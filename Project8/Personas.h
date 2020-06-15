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

ref class CPersonas {
	cli::array<CPersona^>^personas;
	
	
	Random r;
	int cantidadEnemigos;
public:
	CPersonas(){
		cantidadEnemigos = (5 + rand() % (11 - 1));
		
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

	Void Atrapado(Point^point) {
	

		for (int i = 0; i < personas->Length; i++)
		{
			if (personas[i]->getPoint()->X == point->X && personas[i]->getPoint()->Y == point->Y) {
				Eliminar(i);
				break;
			}
		}

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