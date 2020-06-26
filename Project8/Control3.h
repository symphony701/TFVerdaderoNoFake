#pragma once
#include "Entidad.h"
#include "Jugador.h"
#include "Policia.h"
#include "Ambulancia.h"
#include "mapas.h"
#include "Map2.h"
#include "Tiempo.h"
#include "Personas.h"
#include <iostream>
#include "Arremensajes.h"
#include "Vidas.h"
#include "Recomendaciones.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;
using namespace System::Media;

ref class CControl3 {
private:
	CJugador^ jugador;
	bool activadorRecomendacion;
	CMapas^ mapa;
	bool activo;
	tiempo^ tiem;
	CPersonas ^ personas;
	int dia;
	Int16 punta;
	Int16 dinero;
	Cvidas^ vidajuga;
	CRecomendaciones^recomendaciones;
	int iteradorDeRecomendaciones;
public:
	CControl3(Int16 vi) {
		recomendaciones = gcnew CRecomendaciones();
		iteradorDeRecomendaciones = 1;
		dia = 0;
		dinero = 100;
		tiem = gcnew tiempo();
		jugador = gcnew CJugador();
		vidajuga = gcnew Cvidas(vi);
		punta = 0;
		mapa = gcnew CMapas(2);
		personas = gcnew CPersonas(3);
	}
	~CControl3() {}

	Void cadaTick(Label^  lbl_puntaje, Graphics^g, Label^  lbl_dinero, Label^  lbl_hora) {
		g->DrawImage(mapa->getImagen(), 0, 0, mapa->getRectangle(), GraphicsUnit::Pixel);
		personas->Mostrar(g);
		jugador->Mostrar(g, activo);
		dinero = dinero - jugador->cobro();
		lbl_dinero->Text = "$" + dinero;
		if (personas->Colision(jugador->getRectangle()))
		{
			activadorRecomendacion = true;
		}
		else { activadorRecomendacion = false; }
		vidajuga->Cantivi(g);
		tiem->cambio(1);
		mapa->cambio(tiem->gethora());
		lbl_hora->Text = tiem->mostrarT();
		
	}
	Void keyDown(KeyEventArgs^  e) {
		activo = true;
		if (e->KeyCode == Keys::Up) {
			jugador->Mover4(Direccion::Arriba);
		}
		else if (e->KeyCode == Keys::Down) {
			jugador->Mover4(Direccion::Abajo);
		}
		else if (e->KeyCode == Keys::Left) {
			jugador->Mover4(Direccion::Izquierda);

		}
		else if (e->KeyCode == Keys::Right) {
			jugador->Mover4(Direccion::Derecha);
		}
		else if (e->KeyCode == Keys::W&&activadorRecomendacion) {
			recomendaciones->darRecomendacion(iteradorDeRecomendaciones);
			iteradorDeRecomendaciones++;
		}
	
		cout << jugador->getPosX() << jugador->getPosY() << endl;
	}

	Void keyUp(KeyEventArgs^  e) {
		if (e->KeyCode == Keys::W) {
			activo = false;
		}
		if (e->KeyCode == Keys::Up) {
			activo = false;
		}
		else if (e->KeyCode == Keys::Down) {
			activo = false;
		}
		else if (e->KeyCode == Keys::Left) {
			activo = false;

		}
		else if (e->KeyCode == Keys::Right) {
			activo = false;
		}
	}
	int getContadorRecomendaciones() { return iteradorDeRecomendaciones; }
};
