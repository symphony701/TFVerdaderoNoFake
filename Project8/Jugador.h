#pragma once
#include "Entidad.h"
#include <iostream>
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace std;
enum  Direccion
{
	Ninguna,Abajo,Arriba,Izquierda,Derecha
};

ref class CJugador : public CEntidad{
private:
	Int16 vidas;
	bool movArriba, movAbajo, movDerecha, movIzquierda;
	//Direccion ultimaTecla;
public:
	CJugador() {
	//	x = 0;
		//y = 0;
		posx = posy = 200;
		dx=dy = 3;
		imagen = gcnew Bitmap("jugador.png");
		anchoSprite = imagen->Width;
		altoSprite = imagen->Height;
		anchoImagen = anchoSprite / 12;
		altoImagen = altoSprite / 8;
		movArriba = movAbajo = movDerecha = movIzquierda = true;
//		Direccion direccion;
		
	}
	~CJugador(){}

	Void Disparar(){}
	Void Mostrar(Graphics^g,bool act) {
		
		areaVisible = Rectangle(anchoImagen*x, altoImagen*y, anchoImagen, altoImagen);
		
		g->DrawImage(imagen,posx,posy,areaVisible,GraphicsUnit::Pixel);
		if(act==true){ x++; }
		
		if (x == 3) { x = 0; }
	}
	Void Mover(Direccion direccion) {
		 
		switch (direccion)
		{
		case Direccion::Ninguna: 
			break;
		case Direccion::Abajo: 
			if(movAbajo){ posy += dy; }
			y = 0;
			break;
		case Direccion::Arriba:
			if (movArriba) { posy -= dy; }
			
			y = 3;
			break;
		case Direccion::Izquierda:
			if (movIzquierda) { posx -= dx; }
			
			y = 1;
			break;
		case Direccion::Derecha:
			if (movDerecha) { posx += dx; }
		
			y = 2;
			break;
		default:
			break;
		}
		if ((670-anchoImagen) <= posx) {
			posx = 670 - anchoImagen;
		}

		if (posy>=573-altoImagen) {
			movAbajo = false;
		}
		else { movAbajo = true; }

		//Codigo solo para valientes xd
		while(true){
			////Casa aislada

			if (posy  >= 440 && posy <= 445 && posx  <= 250 && posx >= 179  ) {

				movArriba = false; break;
			}
			else { movArriba = true; }


			if (posy >= 374 && posy <= 437 && posx <= 260 && posx >= 257) {

				movIzquierda = false; break;
			}
			else { movIzquierda = true; }
			if (posy >= 365 && posy <= 368 && posx <= 250 && posx >= 179) {

				movAbajo = false; break;
			}
			else { movAbajo = true; }


			if (posy >= 380 && posy <= 431 && posx <= 161 && posx >= 158) {

				movDerecha = false; break;
			}
			else { movDerecha = true; }



		//Valla baja
		if (posy >= 517 && 521 >= posy  &&  posx >= 104 && 632 >= posx) {

			movAbajo = false; break;
		}
		else { movAbajo = true; }
		if (posy >= 329 && 521 >= posy  &&  posx >= 101 && 104 >= posx) {

			movIzquierda = false; break;
		}
		else { movIzquierda = true; }
		if (posy >= 327 && 329 >= posy  &&  posx >= -4 && 103 >= posx) {

			movAbajo = false; break;
		}
		else { movAbajo = true; }

		//Valla derecha
		if (posy >= 143 && 146 >= posy  &&  posx >= 590 && 632 >= posx) {

			movArriba = false; break;
		}
		else { movArriba = true; }
		if (posy >= 47 && 146 >= posy  &&  posx >= 587 && 593 >= posx) {

			movDerecha = false; break;
		}
		else { movDerecha = true; }
		if (posy >= 47 && 49 >= posy  &&  posx >= 420 && 590 >= posx) {
			
			movArriba = false; break;
		}
		else { movArriba = true; }
		//salta las leyes de la programacion
		if (posy >= 47 && 83 >= posy  &&  posx >= 467 && 470 >= posx) {

			movIzquierda = false; break;
		}
		else { movIzquierda = true; }
		//
		if (posy >= 80 && 83 >= posy  &&  posx >= 470 && 563 >= posx) {

			movAbajo = false; break;
		}
		else { movAbajo = true; }


		break;
		}

		cout << posx << "----" << posy << endl;
	}

};