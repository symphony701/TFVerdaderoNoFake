#pragma once
#include <iostream>
#include "Entidad.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace std;

ref class CAutoridad : public CEntidad {
protected:
	bool direcc;
	bool arriba;
	bool abajo;
	bool derecha;
	bool izquierda;
	Point^origen;
	cli::array<Point^>^puntos;
	bool doble = true;
	bool ir = true;
	int mapa;
	int nroP;
	bool triple = true;

public:
	CAutoridad(int mapa, int nroP) {
		this->mapa = mapa;
		this->nroP = nroP;
		origen = gcnew Point(posx, posy);
		if (mapa == 1)
		{
			puntos = gcnew cli::array<Point^>(15);

		}
		if (mapa == 2)
		{
			puntos = gcnew cli::array<Point^>(18);

		}
		
	}
	CAutoridad(){}
	~CAutoridad() {}
	Void Mostrar(Graphics^g) {
		areaVisible = Rectangle(anchoImagen*x, altoImagen*y, anchoImagen, altoImagen);
		g->DrawImage(imagen, posx, posy, areaVisible, GraphicsUnit::Pixel);
	}
	Void Mover() {
	}
	Void desplazamiento() {
		x++;
		if (x > 2) { x = 0; }
		cambioDireccion();
		movimiento();
	}
	Void cambioDireccion() {
		/*1:arriba
		2 : derech
		3 : abajo
		4 : izquie*/
		/*bool doble=true;*/

		if (mapa == 1 && nroP == 1) {
			if (ir) {
				if (funcion(4)) {
					decision(3);
					doble = true;
				}
				if (funcion(5) && doble) {
					decision(2);
					doble = false;
				}
				if (funcion(10)) {
					decision(4);
				}

				if (funcion(1)) {
					decision(3);
					doble = true;
				}
				if (funcion(14) && doble) {
					decision(4);

				}
				if (funcion(0)) {
					decision(2);
					doble = false;
				}
				if (funcion(14) && !doble) {
					decision(3);
				}
				if (funcion(3)) {
					decision(2);
				
					doble = true;
				}
				if (funcion(13)) {
					decision(2);
					ir = false;
				
				}
			}
			if (!ir)
			{
				if (funcion(13)) {
					decision(4);
				}
				if (funcion(3)) {
					decision(1);
				}
				if (funcion(14) && doble) {
					decision(4);
				}
				if (funcion(0)) {
					decision(2);
					doble = false;
				}
				if (funcion(14) && !doble) {
					decision(1);
				}
				if (funcion(1)) {
					decision(2);
					doble = true;
				}
				if (funcion(5) && doble) {
					decision(2);
				}
				if (funcion(10)) {
					decision(4);
					doble = false;
				}
				if (funcion(5) && !doble) {
					decision(1);
					ir = true;
				}
			
			}

		}


		if (mapa == 1 && nroP == 2)
		{
			if (true) {
				if (funcion(9)) {
					decision(2);
					doble = true;
					triple = true;
				}
				if (funcion(11) && doble) {
					decision(3);
				}
				if (funcion(11) && doble) {
					decision(3);
				}
				if (funcion(11) && doble) {
					decision(3);
				}
				if (funcion(12) && doble) {
					decision(4);
				}
				if (funcion(7) && doble) {
					decision(1);
				}
				if (funcion(6) && doble) {
					decision(4);
				}
				if (funcion(2) && doble) {
					decision(2);
					doble = false;
				}
				if (funcion(6) && !doble) {
					decision(3);
				}
				if (funcion(8)) {
					triple = false;
					decision(1);
				}
				if (funcion(7) && !doble&&triple) {
					decision(3);

				}
				if (funcion(7) && !doble && !triple) {
					decision(2);
				}
				if (funcion(12) && !doble) {
					decision(1);
				}
				if (funcion(11) && !doble) {
					decision(4);
				}if (funcion(9) && !doble) {
					decision(2);
					doble = true;
					triple = true;
				}
			}
		}

		if (mapa == 2 && nroP == 1) {
			if (true) {
				if (funcion(17) && doble) {
					decision(1);
					doble = true;
					triple = true;
				}
				if (funcion(16) && doble) {
					decision(4);
				}
				if (funcion(15) && doble) {
					decision(3);
				}
				if (funcion(14) && doble) {
					decision(4);
				}
				if (funcion(13) && doble) {
					decision(3);
				}
				if (funcion(9) && triple&&doble) {
					decision(4);
				}
				if (funcion(12)) {
					decision(2);
					triple = false;
				}
				if (funcion(9) && doble && !triple) {
					decision(3);
				}
				if (funcion(6) && doble) {
					triple = true;
					decision(2);
				}
				if (funcion(8) && doble) {
					decision(4);
					doble = false;
				}
				if (funcion(6) && !doble) {
					decision(1);
					triple = true;
				}
				if (funcion(9) && !doble&&triple) {
					decision(1);
				}
				if (funcion(9) && !doble && !triple) {
					decision(4);
				}
				if (funcion(13) && !doble) {
					decision(2);
				}
				if (funcion(14) && !doble) {
					decision(1);
				}
				if (funcion(15) && !doble) {
					decision(2);
				}
				if (funcion(16) && !doble) {
					decision(3);
				}
				if (funcion(17) && !doble) {
					decision(1);
					doble = true;
					triple = true;
				}
			}
		}

		if (mapa == 2 && nroP == 2) {

		}



	}

	Void cambioDireccion2() {
		/*1:arriba
		2 : derech
		3 : abajo
		4 : izquie*/
		/*bool doble=true;*/

	}

	bool funcion(int xd) {
		Point^punt = gcnew Point(posx, posy);
		bool val;
		if (punt->X == puntos[xd]->X&&punt->Y == puntos[xd]->Y) {
			val = true;
		}
		else { val = false; }
		return val;
	}



	Void iniciarPuntos() {
		if (mapa == 1) {
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
			puntos[14] = gcnew Point(140, 308);

		}
		if (mapa == 2) {
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
			
		}

	}

	Point ^ getPoint() {
		return origen;
	}
	Rectangle ^getRectangle() {

		return Rectangle(posx, posy, 29, 45);
	}

	Void movimiento() {
		if (arriba)
		{
			posy = posy - dy;
		}
		if (abajo) { posy = posy + dy; }
		if (derecha) { posx = posx + dx; }
		if (izquierda) { posx = posx - dx; }
		

	}

	Void decision(int cambio) {
		switch (cambio)
		{
		case 1:arriba = true; derecha = izquierda = abajo = false; y = 3; break;
		case 2:derecha = true; arriba = izquierda = abajo = false; y = 2; break;
		case 3:abajo = true; derecha = izquierda = arriba = false; y = 0; break;
		case 4:izquierda = true; derecha = arriba = abajo = false; y = 1; break;
		default:
			break;
		}


	}


};










