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
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;
using namespace System::Media;

ref class CControl2 {
private:
	CJugador^ jugador;
	CPolicia^poli;
	CAmbulancia ^ambulancia;
	CAmbulancia^ambulancia2;
	CMapas^ mapa;
	bool activo;
	tiempo^ tiem;
	CPersonas ^ personas;
	CPolicia ^poli2;
	int dia;
	bool actPoli;
	bool creada;
	CArreMensajes^ mensajuga;
	CArreMensajes^ tomateenemigos;
	Int16 punta;
	Int16 dinero;
	Cvidas^ vidajuga;
	bool dispaene;
	Int16 tipomuer;
public:
	CControl2(Int16 vi, bool dispaene, int toqueco, int toquefin, int dinero,int punta) {
		this->dispaene = dispaene;
		this->dinero = dinero;
		this->punta = punta;
		dia = 0;
		
		tiem = gcnew tiempo();
		jugador = gcnew CJugador();
		vidajuga = gcnew Cvidas(vi);
		
		tipomuer = 1;
		mapa = gcnew CMapas(3);
		personas = gcnew CPersonas(2);
		mensajuga = gcnew CArreMensajes(1);
		tomateenemigos = gcnew CArreMensajes(2);
		personas->tamañomen(mensajuga->getancho(), mensajuga->getalto());
		tiem->Horasdetoquedequeda(toqueco, toquefin);
		actPoli = true;
		creada = false;
	}
	~CControl2() {}

	bool cadaTick(Label^  lbl_puntaje, Graphics^g, Label^  lbl_dinero, Label^  lbl_hora) {
		for (int i = 0; i < 5; i++) {
			if (mensajuga->getactivador(i)) {
				punta = punta + personas->multado(mensajuga->getposx(i), mensajuga->getposy(i));
				lbl_puntaje->Text = punta + "p";
				if (personas->desacmensa()) {
					mensajuga->desativador(i);
				}
			}

		}
		if (tiem->gethora() == 6 && tiem->getmin() == 00 && actPoli)
		{
			ambulancia = gcnew CAmbulancia(2, 1);
			ambulancia2 = gcnew CAmbulancia(2, 2);
			actPoli = false;
		}
		if (tiem->gethora() == 6 && tiem->getmin() == 00 && !actPoli)
		{
			ambulancia = gcnew CAmbulancia(2, 1);
			ambulancia2 = gcnew CAmbulancia(2, 2);
			delete poli, poli2;
		}
		if (tiem->gethora() == 20 && tiem->getmin() == 00)
		{
			delete ambulancia, ambulancia2;
			poli = gcnew CPolicia(2, 1);
			poli2 = gcnew CPolicia(2, 2);
		}
		g->DrawImage(mapa->getImagen(), 0, 0, mapa->getRectangle(), GraphicsUnit::Pixel);

		mensajuga->MostrarDisparo(g);
		jugador->Mostrar(g, activo);
		dinero = dinero - jugador->cobro();
		lbl_dinero->Text = "$" + dinero;
		personas->Mostrar(g);
		personas->Mover();
		if (tiem->gethora() >= 6 && (tiem->gethora() <= 19 && tiem->getmin() <= 59))
		{
			ambulancia->desplazamiento();
			ambulancia->Mostrar(g);
			ambulancia2->desplazamiento();
			ambulancia2->Mostrar(g);
			personas->AtrapadoAmbu(ambulancia->getRectangle());
			personas->AtrapadoAmbu(ambulancia2->getRectangle());
		}
		if ((tiem->gethora() >= 20 && tiem->gethora() <= 23) || (tiem->gethora() < 6 && tiem->gethora() >= 0)) {

			poli->desplazamiento();
			poli->Mostrar(g);
			poli2->desplazamiento();
			poli2->Mostrar(g);
			personas->AtrapadoPoli(poli->getRectangle());
			personas->AtrapadoPoli(poli2->getRectangle());
		}
		if (dispaene) {
			personas->Cercania(jugador->getRectangle());
			personas->verBala(g);
		}
		vidajuga->perdervida(personas->Colision(jugador->getRectangle()));
		vidajuga->Cantivi(g);
		tiem->cambio(1);
		mapa->cambio(tiem->gethora());
		lbl_hora->Text = tiem->mostrarT();
		if (tiem->fueraentoquedequeda() && jugador->getAlquiler() == false) { tipomuer = 2; }
		if (vidajuga->Muerte()) { tipomuer = 1; }
		return vidajuga->Muerte();
	}
	Void keyDown(KeyEventArgs^  e) {
		activo = true;
		if (e->KeyCode == Keys::Up) {
			jugador->Mover3(Direccion::Arriba);
		}
		else if (e->KeyCode == Keys::Down) {
			jugador->Mover3(Direccion::Abajo);
		}
		else if (e->KeyCode == Keys::Left) {
			jugador->Mover3(Direccion::Izquierda);

		}
		else if (e->KeyCode == Keys::Right) {
			jugador->Mover3(Direccion::Derecha);
		}
		else if (e->KeyCode == Keys::W) {
			mensajuga->Disparar(jugador->getPosX(), jugador->getPosY(), jugador->getY(), jugador->getancho(), jugador->getalto());
		}
		else if (e->KeyCode == Keys::T) {
			personas->Disparad();
			creada = true;
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
	int retornarVidas() { return vidajuga->getcantvida(); }
	int retornarDinero() { return dinero; }
	int returnPuntaje() { return punta; }
	int retornarHora() { return tiem->gethora(); }
	int retornarMinutos() { return tiem->getmin(); }
	int Tipomuerte() { return tipomuer; }
};
