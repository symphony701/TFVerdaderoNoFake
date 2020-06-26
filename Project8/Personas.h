#pragma once
#include "Persona.h"
#include <cstdlib>
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;
using namespace System::Media;

ref class CPersonas {
	cli::array<CPersona^>^personas;
	Random r;
	int cantidadEnemigos;
	Int16 anchomen=31;
	Int16 altomen=25;
	bool desac;
public:
	CPersonas(int nroMapa){
		cantidadEnemigos = r.Next(5,11);
		if (nroMapa==3)
		{
			cantidadEnemigos = 12;
		}
		personas = gcnew cli::array<CPersona^>(cantidadEnemigos);
		if (nroMapa==1||nroMapa==2)
		{
			for (int i = 0; i < cantidadEnemigos; i++)
			{
				desac = true;
				personas[i] = gcnew CPersona(nroMapa);
			}
		}
		if (nroMapa==3)
		{
			for (int i = 0; i < cantidadEnemigos; i++)
			{
				desac = true;
				personas[i] = gcnew CPersona(nroMapa);
				personas[i]->onlyMap3(i);
			}
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
	void AtrapadoPoli(Rectangle^ poli) {
		for (int i = 0; i < personas->Length; i++)
		{
			if (poli->IntersectsWith(personas[i]->getRectangle())&&personas[i]->getMulta()&&!personas[i]->getVirus() ) {
				Eliminar(i);
				break;
			}
		}
	}
	Void Cercania(Rectangle ^juga) {
		
		for (int i = 0; i < personas->Length; i++) {
			for (int a = 0; a < 5; a++) {

					Rectangle cercaniaariba = Rectangle(personas[i]->getPosX(), (personas[i]->getPosY()- (altomen * 5)), anchomen, altomen*5);
					Rectangle cercaniaabajo = Rectangle(personas[i]->getPosX(), personas[i]->getPosY(), anchomen, altomen*5);
					Rectangle cercaniaderecha =Rectangle(personas[i]->getPosX(), personas[i]->getPosY(), anchomen*5, altomen);
					Rectangle cercaniaizquierda =Rectangle(personas[i]->getPosX()-(anchomen * 5), personas[i]->getPosY(), anchomen*5, altomen);
					switch (personas[i]->direccion()) {
					case 3: if (juga->IntersectsWith(cercaniaariba)){
						personas[i]->Diasparar();
					};break;
					case 2:if (juga->IntersectsWith(cercaniaderecha)){
						personas[i]->Diasparar();
					}; break;
					case 0:if (juga->IntersectsWith(cercaniaabajo)){
						personas[i]->Diasparar();
					}; break;
					case 1:if (juga->IntersectsWith(cercaniaizquierda)){
						personas[i]->Diasparar();
					}; break;
					default:break;
				}
			}
		}
	}
	Void Disparad() {
		for (int i = 0; i < personas->Length; i++) {
			personas[i]->Diasparar();
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
				Eliminar(i);
				break;
			}
		}
	}
	Int16 multado(Int16 posx ,Int16 posy) {
		Rectangle^ intermensa = gcnew Rectangle(posx, posy, anchomen, altomen);
		for (int i = 0; i < personas->Length; i++) {
			desac = true;
			if ( intermensa->IntersectsWith(personas[i]->getRectangle()) && personas[i]->getestadoba()) {
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
		Rectangle^ juga2 = gcnew Rectangle(juga->X + 7, juga->Y + 11, juga->Width - 14, juga->Height - 22);
		for (int i = 0; i < personas->Length; i++){
			if (juga2->IntersectsWith(personas[i]->getRectangle()) ) {
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
	int getPersonas() { return personas->Length; }
};