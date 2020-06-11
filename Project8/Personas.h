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
		for (int i = 0; i < cantidadEnemigos; i++)
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

	
};