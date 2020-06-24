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
	bool desac;
public:
	CPersonas(int nroMapa){
		alto= gcnew SoundPlayer("alto.wav");
		
		cantidadEnemigos = r.Next(5,11);
		personas = gcnew cli::array<CPersona^>(cantidadEnemigos);
			
		for (int i = 0; i < cantidadEnemigos; i++)
		{

			desac = true;

			personas[i] = gcnew CPersona(nroMapa);


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

	Void Disparad(int jx,int jy) {
		for (int i = 0; i < personas->Length; i++) {
			personas[i]->Diasparar(jx,jy);
		}
	}
	Void Trayectoria() {
		for (int i = 0; i < personas->Length; i++) {
			personas[i]->Mover();
		}
	}
	Void verBala(Graphics^g) {
		for (int i = 0; i < personas->Length; i++) {
			personas[i]->verBala(g);
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
	Int16 multado(Int16 posx ,Int16 posy) {
		Rectangle^ intermensa = gcnew Rectangle(posx, posy, anchomen, altomen);
		for (int i = 0; i < personas->Length; i++) {
			desac = true;
			if ( intermensa->IntersectsWith(personas[i]->getRectangle()) && !personas[i]->getestadoba()) {
				personas[i]->cambioImagen();
				personas[i]->estadocambiado();
				desac = personas[i]->getestadoba();
				personas[i]->multar();
				return 10;
				break;
			}
		}
		return 0;
	}
	bool desacmensa() {
		return !(desac);
	}
	bool Colision(Rectangle ^juga) {
		for (int i = 0; i < personas->Length; i++)
		{
			if (juga->IntersectsWith(personas[i]->getRectangle()) ) {
				return true;
				break;
			}
		}
		return false;
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
	Void Cercania(Int16 posx, Int16 posy, Int16 ancho, Int16 alto2) {
		/*for (int i = 0; i < personas->Length; i++){
			if (personas[i]->getPosX -50 >= posx + ancho && personas[i]->getPosX+ personas[i]->getancho + 50<= posx && personas[i]->getPosY - 50 >= posx + alto2 && personas[i]->getPosY + personas[i]->getalto +50<= posy) {

			}*/
		/*	
		}*/
	}


	
};