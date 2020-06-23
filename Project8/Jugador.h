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
	Int16 vidas;
	bool movArriba, movAbajo, movDerecha, movIzquierda, alquiler;
	Climites^ limites;
public:
	CJugador() {

		posx = 191;
		posy = 446;
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

	/*Void Disparar(Graphics^g) {
		for (int i = 0; i < 5; i++) {
			if (cantbal[i]->getactivador() == true) {
				if (cantbal[i]->getdirec() == 0) {
					int a = cantbal[i]->getver() + 6;
					cantbal[i]->setver(a);
				}
				if (cantbal[i]->getdirec() == 1) {
					int a = cantbal[i]->gethor() - 6;
					cantbal[i]->sethor(a);

				}
				if (cantbal[i]->getdirec() == 2) {
					int a = cantbal[i]->gethor() + 6;
					cantbal[i]->sethor(a);
				}
				if (cantbal[i]->getdirec() == 3) {
					int a = cantbal[i]->getver() - 6;
					cantbal[i]->setver(a);
				}

				g->DrawImage(mensaje, cantbal[i]->gethor(), cantbal[i]->getver());
				cantbal[i]->distancia();
			}

		}

	}*/
	//Void MostrarDisparo(Int16 x, Int16 y, Int16 d) {
	//	for (int i = 0; i < 5; i++) {
	//		if (cantbal[i]->getactivador() == false) {
	//			cantbal[i]->setactivador(true);
	//			cantbal[i]->CORDENADA(x, y);
	//			cantbal[i]->setdirec(d);
	//			break;
	//		}
	//	}

	//}
	Void Mostrar(Graphics^g, bool act) {

		areaVisible = Rectangle(anchoImagen*x, altoImagen*y, anchoImagen, altoImagen);

		g->DrawImage(imagen, posx, posy, areaVisible, GraphicsUnit::Pixel);
		if (act == true) { x++; }

		if (x == 3) { x = 0; }
		if (alquiler) {
			g->DrawImage(gcnew Bitmap("casaLuri.png"), 188, 418);
		}
	}
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

	//MAPA 2 LURIGANCHO COLISIONES

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
			y = 0;
			break;
		case Direccion::Arriba:
			if (movArriba) { posy -= dy; }
			movArriba = limites->mapa3arriba(movArriba, posx, posy);
			y = 3;
			break;
		case Direccion::Izquierda:
			if (movIzquierda) { posx -= dx; }
			movIzquierda = limites->mapa3izquierda(movIzquierda, posx, posy);
			y = 1;
			break;
		case Direccion::Derecha:
			if (movDerecha) { posx += dx; }
			movDerecha = limites->mapa3derecha(movDerecha, posx, posy);
			y = 2;
			break;
		default:
			break;
		}
	}


	int getPosX() { return posx; }
	int getPosY() { return posy; }
};