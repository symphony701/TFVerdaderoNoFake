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
#include <fstream>
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace std;
using namespace System::Media;
using namespace std;

ref class CControl1 {
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
	Int16 punta;
	Int16 dinero;
	Cvidas^ vidajuga;
	bool dispaene;
	Int16 tipomuer;
	bool creadorAmbulancia, creadorPolicia;
public:
	CControl1(Int16 vi, bool dispaene, int toqueco, int toquefin){
		creadorAmbulancia = creadorPolicia = true;
		dia = 0;
		dinero = 100;
		tiem = gcnew tiempo(toquefin,0);
		jugador = gcnew CJugador(1);
		vidajuga = gcnew Cvidas(vi);
		punta = 0;
		mapa = gcnew CMapas(1);
		this->dispaene = dispaene;
		tipomuer = 1;
	
		personas = gcnew CPersonas(1);
		mensajuga = gcnew CArreMensajes(1);
		personas->tama�omen(mensajuga->getancho(), mensajuga->getalto());

		actPoli = true;
		creada = false;
		tiem->Horasdetoquedequeda(toqueco, toquefin);
	}
	~CControl1(){}

	bool cadaTick(Label^  lbl_puntaje,Graphics^g, Label^  lbl_dinero, Label^  lbl_hora) {
		for (int i = 0; i < 5; i++) {
			if (mensajuga->getactivador(i)) {
				punta = punta + personas->multado(mensajuga->getposx(i), mensajuga->getposy(i));
				lbl_puntaje->Text = punta + "p";
				if (personas->desacmensa()) {
					mensajuga->desativador(i);
					mensajuga->MostrarMensaje();
				}
			}

		}


		if (tiem->gethora() >= 6 && tiem->getmin() >= 00 && tiem->gethora() <20 &&actPoli && creadorAmbulancia)
		{
			ambulancia = gcnew CAmbulancia(1, 1);
			ambulancia2 = gcnew CAmbulancia(1, 2);
			creadorAmbulancia = false;
			creadorPolicia = true;

			actPoli = false;
		}
		if (tiem->gethora() >= 6 && tiem->getmin() >= 00 && tiem->gethora() <20 &&!actPoli&&creadorAmbulancia)
		{
			ambulancia = gcnew CAmbulancia(1, 1);
			ambulancia2 = gcnew CAmbulancia(1, 2);
			creadorAmbulancia = false;
			creadorPolicia = true;
			delete poli, poli2;
		}
		if ((tiem->gethora() >= 20 && tiem->getmin() >= 00&&creadorPolicia) || (tiem->gethora() < 6 && tiem->getmin() >= 00&&creadorPolicia) )
		{
			delete ambulancia, ambulancia2;
			poli = gcnew CPolicia(1, 1);
			poli2 = gcnew CPolicia(1, 2);
			creadorAmbulancia = true;
			creadorPolicia = false;
		}
		g->DrawImage(mapa->getImagen(), 0, 0, mapa->getRectangle(), GraphicsUnit::Pixel);

		mensajuga->MostrarDisparo(g);
		jugador->Mostrar(g, activo, 1);
		dinero = dinero - jugador->cobro(1);
		lbl_dinero->Text = "$" + dinero;


		personas->Mostrar(g);
		personas->Mover();
		if (tiem->gethora() >= 6 && (tiem->gethora() <= 19 && tiem->getmin() <= 59))
		{
			ambulancia->desplazamiento();
			ambulancia->Mostrar(g);
			ambulancia2->desplazamiento();
			ambulancia2->Mostrar(g);
			dinero = dinero + personas->AtrapadoAmbu(ambulancia->getRectangle());
			dinero = dinero + personas->AtrapadoAmbu(ambulancia2->getRectangle());
		}
		if ((tiem->gethora() >= 20 && tiem->gethora() <= 23) || (tiem->gethora() < 6 && tiem->gethora() >= 0)) {

			poli->desplazamiento();
			poli->Mostrar(g);
			poli2->desplazamiento();
			poli2->Mostrar(g);
			dinero = dinero + personas->AtrapadoPoli(poli->getRectangle());
			dinero = dinero + personas->AtrapadoPoli(poli2->getRectangle());
		}
		if (dispaene) {
			personas->Cercania(jugador->getRectangle());
			personas->verBala(g);
		}


		vidajuga->perdervida(personas->Colision(jugador->getRectangle()));
		vidajuga->perdervida(personas->Colisiontomate(jugador->getRectangle()));
		vidajuga->Cantivi(g);
		tiem->cambio(1);
		mapa->cambio(tiem->gethora());
		lbl_hora->Text = tiem->mostrarT();

		if (dinero < 0) { tipomuer = 3; return true; }
		if (tiem->fueraentoquedequeda() && jugador->getAlquiler() == false) { tipomuer = 2; return true; }
		if (vidajuga->Muerte()) { tipomuer = 1; }
		return vidajuga->Muerte();

	}

	int getCantidadEnemigos() {
		return personas->getPersonas();
	}
	Void registrarDatos() {
		fstream puntaje("puntaje.txt",ios::out);
		puntaje << to_string(punta) << endl;
	}

	Void keyDown(KeyEventArgs^  e) {
		activo = true;
		if (e->KeyCode == Keys::Up) {
			jugador->Mover(Direccion::Arriba);
		}
		else if (e->KeyCode == Keys::Down) {
			jugador->Mover(Direccion::Abajo);
		}
		else if (e->KeyCode == Keys::Left) {
			jugador->Mover(Direccion::Izquierda);

		}
		else if (e->KeyCode == Keys::Right) {
			jugador->Mover(Direccion::Derecha);
		}
		else if (e->KeyCode == Keys::W) {
			mensajuga->Disparar(jugador->getPosX(), jugador->getPosY(), jugador->getY(), jugador->getancho(), jugador->getalto());
		}
		else if (e->KeyCode == Keys::T) {
			personas->Disparad();
			creada = true;
		}
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
