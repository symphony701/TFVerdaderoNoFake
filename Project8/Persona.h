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

public:
	CPersona(){
		puntos = gcnew cli::array<Point^>(15);
		posicion = gcnew Point(0,0);
		iniciarPuntos(1);
		dx = dy = 3;
		posx=origen->X;
		posy = origen->Y;
		imagen = gcnew Bitmap("jugador.png");
		anchoImagen = imagen->Width;
		altoImagen = imagen->Height;
		anchoSprite = anchoImagen /12 ;
		altoSprite = altoImagen / 8;
		filas = 1;
		cols = 0;
		cambioDireccion();
	}
	~CPersona(){}
	Void Mostrar(Graphics^gr) {
		areaVisible = Rectangle(anchoSprite*filas, altoSprite*cols, anchoSprite, altoSprite);
		gr->DrawImage(imagen, posx, posy, areaVisible, GraphicsUnit::Pixel);
		
	}
	Void desplazamiento() {
		movimiento();
		filas++;
		if (filas > 2) { filas = 0; }
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
		// recordatorio para las 9
	//vas a colocar 2 if para poder activar lado horizontal o lado vertical
		//tendras que activar el panel para que dibues unos mas para poder verlos
		//y para poder ver como se activa y desactiva cuando escogen una opcion
		//esto sera retirado una vez que tengamos bien los limites; 
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
			decision(random(3, 3));/*	cout << punt->X << "--" << punt->Y;*/
		}
			if (punt->X == puntos[5]->X&&punt->Y == puntos[5]->Y) {
			 
			do {  vacio = random(1, 4); } while (vacio==3);
			decision(vacio);	/*cout << punt->X << "--" << punt->Y;*/
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
		/*cout << "-" << arriba << derecha << abajo << izquierda<<endl;*/

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