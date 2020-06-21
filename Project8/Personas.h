#pragma once
#include "Persona.h"
#include <cstdlib>
using namespace System;
//using namespace Windows;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;
using namespace System::Media;

ref class CPersonas {
	cli::array<CPersona^>^personas;
	
	SoundPlayer^ alto;
	Random r;
	int cantidadEnemigos;
	Int16 anchomen=31;
	Int16 altomen=25;
public:
	CPersonas(){
		alto= gcnew SoundPlayer("alto.wav");
		cantidadEnemigos = (5 + rand() % (11 - 1));
		cantidadEnemigos = r.Next(5,11);
		personas = gcnew cli::array<CPersona^>(cantidadEnemigos);
		
			
		for (int i = 0; i < cantidadEnemigos; i++)
		{
			personas[i] = gcnew CPersona();


		}

	}
	
	
	Void Mostrar(Graphics^gr) {
		for (int i = 0; i < personas->Length; i++)
		{
			personas[i]->Mostrar(gr);
		}
	}
	Void Mover() {
		for (int i = 0; i < personas->Length; i++)
		{
			personas[i]->desplazamiento();
		}
	}

	/*Void Atrapado(Point^point) {
	

		for (int i = 0; i < personas->Length; i++)
		{
			if (personas[i]->getPoint()->X == point->X && personas[i]->getPoint()->Y == point->Y) {
				Eliminar(i);
				break;
			}
		}

	}*/
	void AtrapadoPoli(Rectangle^ poli) {
		for (int i = 0; i < personas->Length; i++)
		{
			if (poli->IntersectsWith(personas[i]->getRectangle())&&personas[i]->getMulta()&&!personas[i]->getVirus() ) {
				alto->Play();
				Eliminar(i);
				break;
			}
		}
	}

	void AtrapadoAmbu(Rectangle ^poli) {
		for (int i = 0; i < personas->Length; i++)
		{
			if (poli->IntersectsWith(personas[i]->getRectangle()) && personas[i]->getMulta() && personas[i]->getVirus()) {
			//	alto->Play();
				Eliminar(i);
				break;
			}
		}
	}

	/*Void multado(cli::array<Rectangle^>^sd,) {
		for (int i = 0; i < personas->Length; i++)
		{
			
			if (sd[i].IntersectsWith(personas[i]->getRectangle)) {
				Eliminar(i);
				
				break;
			}
		}
	}*/
	Void multado(Int16 posx ,Int16 posy) {
		for (int i = 0; i < personas->Length; i++) {
			Rectangle^ intermensa = gcnew Rectangle(posx, posy, anchomen, altomen);
			if ( intermensa->IntersectsWith(personas[i]->getRectangle())) {
				personas[i]->cambioImagen();
				personas[i]->multar();
				break;
			}
		}
	}
	Void tamañomen(Int16 ancho, Int16 alto) {
		anchomen = ancho;
		altomen = alto;
	}
	Void Eliminar(int pos) {
		cli::array<CPersona^>^fantasmas;
		fantasmas = gcnew cli::array<CPersona^>(personas->Length-1);
		int cont = 0;
		for (int i = 0; i < personas->Length; i++)
		{
			if (i!=pos) {
				fantasmas[cont] = personas[i];
				cont++;
				
			}
		}

		delete personas;
		personas = fantasmas;
		delete fantasmas;

	}



	
};