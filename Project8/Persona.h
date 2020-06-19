#pragma once
#include "Entidad.h"
#include <iostream>
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

public:
	CPersona(){
		puntos = gcnew cli::array<Point^>(15);
		posicion = gcnew Point(0,0);
		iniciarPuntos(1);
		dx = dy = 3;
		posx=origen->X;
		posy = origen->Y;
		imagen = gcnew Bitmap("enemigos(base1).png");
		anchoImagen = imagen->Width;
		altoImagen = imagen->Height;
		anchoSprite = anchoImagen /12 ;
		altoSprite = altoImagen / 4;
		multa = false;
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

	}

	Void cambioDireccion() {
		Point^punt = gcnew Point(posx, posy);
		
		int vacio;
		if (punt->X==puntos[0]->X&&punt->Y== puntos[0]->Y) {
			decision(random(2,2));	
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
			 
			do {  vacio = random(1, 4); } while (vacio==3);
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
			 
			do { vacio = random(1, 4); } while (vacio == 3||vacio==2);
			decision(vacio);	
		}
			if (punt->X == puntos[13]->X&&punt->Y == puntos[13]->Y) {
			decision(random(4, 4));	
		}
			if (punt->X == puntos[14]->X&&punt->Y == puntos[14]->Y) {
			 
			do { vacio = random(1, 4); } while ( vacio == 2);
			decision(vacio);
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
};