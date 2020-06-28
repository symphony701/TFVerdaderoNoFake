#pragma once
#include "Entidad.h"
#include "Mensaje.h"
#include <iostream>
#include "Limites.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace std;
enum  Direccion
{
	Ninguna,Abajo,Arriba,Izquierda,Derecha, Espacio
};



ref class CJugador : public CEntidad {
private:
	Int16 aldis;
	bool movArriba, movAbajo, movDerecha, movIzquierda, alquiler;
	Climites^ limites;
public:
	CJugador(Int16 i) {
		aldis = 0;
		if (i == 1) {
			posx = 191;
			posy = 446;

		}
		if (i == 2) {
			posx = 375;
			posy = 570;

		}
		if (i == 3) {
			posx = 400;
			posy = 570;

		}
		dx = dy = 3;
	
		imagen = gcnew Bitmap("jugador.png");
		anchoSprite = imagen->Width;
		altoSprite = imagen->Height;
		anchoImagen = anchoSprite / 12;
		altoImagen = altoSprite / 8;
		movArriba = movAbajo = movDerecha = movIzquierda = true;
		limites = gcnew Climites();
	}
	~CJugador() {
		delete limites, imagen;
	}
	Void Mostrar(Graphics^g, bool act, Int16 i) {

		areaVisible = Rectangle(anchoImagen*x, altoImagen*y, anchoImagen, altoImagen);

		g->DrawImage(imagen, posx, posy, areaVisible, GraphicsUnit::Pixel);
		if (act == true) { x++; }

		if (x == 3) { x = 0; }
		if (alquiler&& i ==1) {
			g->DrawImage(gcnew Bitmap("casaLuri.png"), 188, 418);
			aldis++;
			if (aldis >= 60) {
				aldis = 0;
			}
		}
		if (alquiler&& i == 2) {
			g->DrawImage(gcnew Bitmap("casaSanMiguel.png"), 554, 253);
			aldis++;
			if (aldis >= 60) {
				aldis = 0;
			}
		}
	}
	Int16 cobro(Int16 i) {
		if (alquiler&&i==1) {
			if (aldis == 1) {
				return 10;
			}
		}
		if (alquiler&& i ==2) {
			if (aldis == 1) {
				return 20;
			}
		}
		return 0;
	}
	bool getAlquiler() { return alquiler; }
	Int16 getancho() {return anchoImagen;}
	Int16 getalto() {return altoImagen;}
	Void Mover(Direccion direccion) {

		switch (direccion)
		{
		case Direccion::Ninguna:
			break;
		case Direccion::Abajo:
			if (movAbajo) { posy += dy; }
			movAbajo = limites->mapa1abajo(movAbajo, posx, posy);
			alquiler = limites->colocamapa1(posx, posy);
			y = 0;
			break;
		case Direccion::Arriba:
			if (movArriba) { posy -= dy; }
			movArriba =limites->mapa1arriba( movArriba,  posx,  posy);
			alquiler = limites->colocamapa1(posx, posy);
			y = 3;
			break;
		case Direccion::Izquierda:
			if (movIzquierda) { posx -= dx; }
			movIzquierda = limites->mapa1izquierda(movIzquierda, posx, posy);
			y = 1;
			break;
		case Direccion::Derecha:
			if (movDerecha) { posx += dx; }
			movDerecha = limites->mapa1derecha(movDerecha, posx, posy);
			y = 2;
			break;
		default:
			break;
		}
		if ((670 - anchoImagen) <= posx) {
			posx = 670 - anchoImagen;
		}

		if (posy >= 573 - altoImagen) {
			posy = 573 - altoImagen;
		}
		if (posy <= 0) {
			posy = 0;
		}
		if (0 >= posx) {
			posx = 0;
		}
	}
	Void Mover2(Direccion direccion) {
		switch (direccion)
		{
		case Direccion::Ninguna:
			break;
		case Direccion::Abajo:
			if (movAbajo) { posy += dy; }
			movAbajo = limites->mapa2abajo(movAbajo, posx, posy);
			y = 0;
			break;
		case Direccion::Arriba:
			if (movArriba) { posy -= dy; }
			movArriba = limites->mapa2arriba(movArriba, posx, posy);
			y = 3;
			break;
		case Direccion::Izquierda:
			if (movIzquierda) { posx -= dx; }
			movIzquierda = limites->mapa2izquierda(movIzquierda, posx, posy);
			y = 1;
			break;
		case Direccion::Derecha:
			if (movDerecha) { posx += dx; }
			movDerecha = limites->mapa2derecha(movDerecha, posx, posy);
			y = 2;
			break;
		default:
			break;
		}
			cout << posx << "----" << posy << endl;
	
	
		cout << posx << "----" << posy << endl;

	}

	Void Mover3(Direccion direccion) {
		switch (direccion)
		{
		case Direccion::Ninguna:
			break;
		case Direccion::Abajo:
			if (movAbajo) { posy += dy; }
			movAbajo = limites->mapa3abajo(movAbajo, posx, posy);
			alquiler = limites->colocamapa2(posx, posy);
			y = 0;
			break;
		case Direccion::Arriba:
			if (movArriba) { posy -= dy; }
			movArriba = limites->mapa3arriba(movArriba, posx, posy);
			alquiler = limites->colocamapa2(posx, posy);
			y = 3;
			break;
		case Direccion::Izquierda:
			if (movIzquierda) { posx -= dx; }
			movIzquierda = limites->mapa3izquierda(movIzquierda, posx, posy);
			alquiler = limites->colocamapa2(posx, posy);
			y = 1;
			break;
		case Direccion::Derecha:
			if (movDerecha) { posx += dx; }
			movDerecha = limites->mapa3derecha(movDerecha, posx, posy);
			alquiler = limites->colocamapa2(posx, posy);
			y = 2;
			break;
		default:
			break;
		}
	}

	Void Mover4(Direccion direccion) {
		switch (direccion)
		{
		case Direccion::Ninguna:
			break;
		case Direccion::Abajo:
			if (movAbajo) { posy += dy; }
			movAbajo = limites->mapa4abajo(movAbajo, posx, posy);
			y = 0;
			break;
		case Direccion::Arriba:
			if (movArriba) { posy -= dy; }
			movArriba = limites->mapa4arriba(movArriba, posx, posy);
			y = 3;
			break;
		case Direccion::Izquierda:
			if (movIzquierda) { posx -= dx; }
			movIzquierda = limites->mapa4izquierda(movIzquierda, posx, posy);
			y = 1;
			break;
		case Direccion::Derecha:
			if (movDerecha) { posx += dx; }
			movDerecha = limites->mapa4derecha(movDerecha, posx, posy);
			y = 2;
			break;
		default:
			break;
		}
		cout << posx << "----" << posy << endl;
	}

	Rectangle ^getRectangle() {

		return Rectangle(posx, posy, anchoImagen, altoImagen);
	}

	Void setPosX(Int16 a) { posx = a; }
	Void setPosY(Int16 b) { posy = b; }
	int getPosX() { return posx; }
	int getPosY() { return posy; }
};