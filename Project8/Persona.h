#pragma once
#include "Entidad.h"
#include <iostream>
#include "Bala.h"
#include "Arremensajes.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace std;

ref class CPersona : public CEntidad {
protected:
	bool virus, perseguir;
	int posx, posy, altoImagen, anchoImagen,altoSprite,anchoSprite,cols,filas,dx,dy;
	cli::array<Point^>^puntos;
	Point^origen;
	Point ^posicion;
	bool izquierda, derecha, arriba, abajo;
	Random r;
	int personaje;
	bool multa;
	bool estadoba;
	int nroMapa;
	CBala^ bala;
	CArreMensajes^ tomate;

public:
	CPersona(int nroMapa){

		this->nroMapa = nroMapa;
		if (nroMapa==1)
		{
			puntos = gcnew cli::array<Point^>(15);

		}
		if (nroMapa==2)
		{
		puntos = gcnew cli::array<Point^>(18);
		}
		if (nroMapa == 3) {
			puntos = gcnew cli::array<Point^>(12);
		}
		posicion = gcnew Point(0,0);
		iniciarPuntos(nroMapa);
		dx = dy = 3;
		if (nroMapa==2||nroMapa==1) {
		posx=origen->X;
		posy = origen->Y;
		}
		imagen = gcnew Bitmap("enemigos(base1).png");
		bala = gcnew CBala();
		tomate = gcnew CArreMensajes(2);
		anchoImagen = imagen->Width;
		altoImagen = imagen->Height;
		anchoSprite = anchoImagen /12 ;
		altoSprite = altoImagen / 4;
		multa = false;
		estadoba = true;
		int contagiado = r.Next(1, 7);
		if (contagiado%2==0) {
			virus = true;
		}
		else { virus = false; }
		switch (r.Next(1,5))
		{
		case 1:filas = 1; cols = 0; personaje = 1; break;
		case 2:filas = 4; cols = 0; personaje = 2; break;
		case 3:filas = 7; cols = 0; personaje = 3; break;
		case 4:filas = 10; cols = 0; personaje = 4; break;
		default:
			break;
		}
		cambioDireccion();
	}
	~CPersona(){}
	Void Diasparar() {
		tomate->Disparar(posx, posy, cols, anchoSprite, altoSprite);
	}
	Int16 direccion() { return cols; }
	bool Dispactiva(Int16 i) {  return tomate->getactivador(i); }
	Void Trayectar() {
		bala->Mover();
	}
	Void verBala(Graphics^g) {
		tomate->MostrarDisparo(g);
	}
	Void multar() {
		multa = true;
	}
	bool getVirus() { return virus; }
	bool getMulta() { return multa; }
	Void cambioImagen() {
		if (virus) {
			imagen = gcnew Bitmap("enemigos(infectados).png");
		}else{ imagen = gcnew Bitmap("enemigos(sanos).png"); }
	}
	Void estadocambiado() { estadoba = false; }
	bool getestadoba() { return estadoba; }
	Void Mostrar(Graphics^gr) {
		areaVisible = Rectangle(anchoSprite*filas, altoSprite*cols, anchoSprite, altoSprite);
		gr->DrawImage(imagen, posx, posy, areaVisible, GraphicsUnit::Pixel);
		
	}
	Void desplazamiento() {
		movimiento();
		filas++;
		
		switch (personaje)
		{
		case 1:if (filas > 2) { filas = 0; }; break;
		case 2:if (filas > 5) { filas = 3; }break;
		case 3:if (filas > 8) { filas = 6; }break;
		case 4:if (filas > 11) { filas = 9; } break;
		default:
			break;
		}
		cambioDireccion();
	}


	Void iniciarPuntos(int map) {
		if (map == 1) {
			puntos[0] = gcnew Point(11, 308);
			puntos[1] = gcnew Point(140, 176);
			puntos[2] = gcnew Point(140, 275);
			puntos[3] = gcnew Point(140, 458);
			puntos[4] = gcnew Point(368, -1);
			puntos[5] = gcnew Point(368, 176);
			puntos[6] = gcnew Point(287, 275);
			puntos[7] = gcnew Point(287, 341);
			puntos[8] = gcnew Point(287, 458);
			puntos[9] = gcnew Point(497, 59);
			puntos[10] = gcnew Point(509, 176);
			puntos[11] = gcnew Point(572, 59);
			puntos[12] = gcnew Point(572, 341);
			puntos[13] = gcnew Point(587, 458);
			puntos[14] = gcnew Point(140,308);
			int puntito = 0 + rand() % (13 - 1);
			origen = gcnew Point(0,0);
			origen = puntos[puntito];
		}
		if (map == 2) {
			puntos[0] = gcnew Point(230, 506);
			puntos[1] = gcnew Point(335, 506);
			puntos[2] = gcnew Point(617, 506);
			puntos[3] = gcnew Point(335, 422);
			puntos[4] = gcnew Point(494, 422);
			puntos[5] = gcnew Point(641, 422);
			puntos[6] = gcnew Point(335, 308);
			puntos[7] = gcnew Point(494, 308);
			puntos[8] = gcnew Point(641, 308);
			puntos[9] = gcnew Point(335, 257);
			puntos[10] = gcnew Point(494, 248);
			puntos[11] = gcnew Point(641, 248);
			puntos[12] = gcnew Point(215, 257);
			puntos[13] = gcnew Point(335, 80);
			puntos[14] = gcnew Point(479, 80);
			puntos[15] = gcnew Point(479, 50);
			puntos[16] = gcnew Point(647, 50);
			puntos[17] = gcnew Point(647, 128);
			int puntito = random(0,17);
			origen = gcnew Point(0, 0);
			origen = puntos[puntito];
		}
		if (map == 3) {
			puntos[0] = gcnew Point(578, 92);
			puntos[1] = gcnew Point(365, 371);
			puntos[2] = gcnew Point(305, 371);
			puntos[3] = gcnew Point(239, 371);
			puntos[4] = gcnew Point(194, 371);
			puntos[5] = gcnew Point(146, 371);
			puntos[6] = gcnew Point(415, 371);
			puntos[7] = gcnew Point(481, 371);
			puntos[8] = gcnew Point(526, 371);
			puntos[9] = gcnew Point(574, 371);
			puntos[10] = gcnew Point(218, 485);
			puntos[11] = gcnew Point(527, 491);
		}
	}
	Void onlyMap3(int i) {
		posx = puntos[i]->X;
		posy = puntos[i]->Y;
	}
	Void cambioDireccion() {
		Point^punt = gcnew Point(posx, posy);
		
		int vacio;
		if (nroMapa==1)
		{
			if (punt->X == puntos[0]->X&&punt->Y == puntos[0]->Y) {
				decision(random(2, 2));
			}
			if (punt->X == puntos[1]->X&&punt->Y == puntos[1]->Y) {
				decision(random(2, 3));
			}
			if (punt->X == puntos[2]->X&&punt->Y == puntos[2]->Y) {
				decision(random(1, 3));
			}
			if (punt->X == puntos[3]->X&&punt->Y == puntos[3]->Y) {
				decision(random(1, 2));
			}
			if (punt->X == puntos[4]->X&&punt->Y == puntos[4]->Y) {
				decision(random(3, 3));
			}
			if (punt->X == puntos[5]->X&&punt->Y == puntos[5]->Y) {

				do { vacio = random(1, 4); } while (vacio == 3);
				decision(vacio);
			}
			if (punt->X == puntos[6]->X&&punt->Y == puntos[6]->Y) {
				decision(random(3, 4));
			}
			if (punt->X == puntos[7]->X&&punt->Y == puntos[7]->Y) {
				decision(random(1, 3));
			}
			if (punt->X == puntos[8]->X&&punt->Y == puntos[8]->Y) {

				do { vacio = random(1, 4); } while (vacio == 3);
				decision(vacio);
			}
			if (punt->X == puntos[9]->X&&punt->Y == puntos[9]->Y) {
				decision(random(2, 2));
			}
			if (punt->X == puntos[10]->X&&punt->Y == puntos[10]->Y) {
				decision(random(4, 4));
			}
			if (punt->X == puntos[11]->X&&punt->Y == puntos[11]->Y) {
				decision(random(3, 4));
			}
			if (punt->X == puntos[12]->X&&punt->Y == puntos[12]->Y) {

				do { vacio = random(1, 4); } while (vacio == 3 || vacio == 2);
				decision(vacio);
			}
			if (punt->X == puntos[13]->X&&punt->Y == puntos[13]->Y) {
				decision(random(4, 4));
			}
			if (punt->X == puntos[14]->X&&punt->Y == puntos[14]->Y) {

				do { vacio = random(1, 4); } while (vacio == 2);
				decision(vacio);
			}
		}


		if (nroMapa==2)
		{
			/*1:arriba
			2 : derech
			3 : abajo
			4 : izquie*/
			
			if(funcion(0)){
				decision(2);
			}
			if (funcion(1)) {
				do { vacio = random(1, 4); } while (vacio == 3);
				decision(vacio);
			}
			if (funcion(2)) {
				decision(4);
			}
			if (funcion(3)) {
				decision(random(1,2));
			}
			if (funcion(4)) {
				do { vacio = random(1, 4); } while (vacio == 3);
				decision(vacio);
			}
			if (funcion(5)) {
				do { vacio = random(1, 4); } while (vacio == 2||vacio==3);
				decision(vacio);
			}
			if (funcion(6)) {
				decision(random(1, 3));
			}
			if (funcion(7)) {
				decision(random(1, 4));
			}
			if (funcion(8)) {
				do { vacio = random(1, 4); } while (vacio == 2);
				decision(vacio);
			}
			if (funcion(9)) {
				do { vacio = random(1, 4); } while (vacio == 2 );
				decision(vacio);
			}
			if (funcion(10)) {
				decision(3);
			}
			if (funcion(11)) {
				decision(3);
			}
			if (funcion(12)) {
				decision(2);
			}
			if (funcion(13)) {
				decision(random(2, 3));
			}
			if (funcion(14)) {
				do { vacio = random(1, 4); } while (vacio == 2||vacio==3);
				decision(vacio);
			}
			if (funcion(15)) {
				decision(random(2, 3));
			}
			if (funcion(16)) {
				decision(random(3, 4));
			}
			if (funcion(17)) {
				decision(1);
			}
		}
	}

	Void decision(int cambio) {
		switch (cambio)
		{
		case 1:arriba=true;derecha=izquierda=abajo=false; cols = 3; break;
		case 2:derecha = true; arriba = izquierda = abajo = false; cols = 2; break;
		case 3:abajo = true; derecha = izquierda = arriba = false; cols = 0; break;
		case 4:izquierda = true; derecha = arriba = abajo = false; cols = 1; break;
		default:
			break;
		}
	}
	Void movimiento() {
		if (arriba)
		{
			posy = posy - dy;
		}
		 if (abajo) { posy = posy + dy; }
		 if (derecha) { posx = posx + dx; }
		 if (izquierda) { posx = posx - dx; }
		 posicion->X = posx;
		 posicion->Y = posy;
	}
	int random(int min,int max) {
		int numero=	min + rand() % (max + 1 - min);
		return numero;
	}

	Point^ getPoint() {
		return posicion;
	}
	Rectangle  getRectangle() {
		Rectangle rectangulito = Rectangle(posx, posy,33,49);
		return rectangulito;
	}
	Int16 getancho() { return anchoSprite; }
	Int16 getalto() { return altoSprite; }
	bool funcion(int xd) {
		Point^punt = gcnew Point(posx, posy);
		bool val;
		if (punt->X == puntos[xd]->X&&punt->Y == puntos[xd]->Y) {
			val = true;
		}
		else { val = false; }
		return val;
	}
	int getPosX() { return this->posx; }
	int getPosY() { return this->posy; }
};