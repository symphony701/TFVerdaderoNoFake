#pragma once
#include "Entidad.h"
#include "Mensaje.h"
#include <iostream>
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace std;
enum  Direccion
{
	Ninguna,Abajo,Arriba,Izquierda,Derecha, Espacio
};



ref class CJugador : public CEntidad{
private:
	Int16 vidas;
	bool movArriba, movAbajo, movDerecha, movIzquierda;
	Bitmap^ mensaje;
	cli::array<CMensaje^>^ cantbal;
public:
	CJugador() {
	
		posx = 191;
		posy = 446;
		dx=dy = 3;
		cantbal = gcnew cli::array<CMensaje^>(5);
		for (Int16 i = 0; i < 5; i++){
			cantbal[i] = gcnew CMensaje();
		}
		imagen = gcnew Bitmap("jugador.png");
		mensaje = gcnew Bitmap("papel.png");
		anchoSprite = imagen->Width;
		altoSprite = imagen->Height;
		anchoImagen = anchoSprite / 12;
		altoImagen = altoSprite / 8;
		movArriba = movAbajo = movDerecha = movIzquierda = true;
//		Direccion direccion;
		
	}
	~CJugador(){}

	Void Disparar(Graphics^g) {
		for (int i = 0; i < 5; i++) {
			if (cantbal[i]->getactivador() == true) {
				int a = cantbal[i]->gethor() + 1;
				cantbal[i]->sethor(a);
				g->DrawImage(mensaje, cantbal[i]->gethor(), cantbal[i]->getver());
				
			}

		}

	}
	Void MostrarDisparo(Int16 x, Int16 y){
		for (int i = 0; i < 5; i++){
			if (cantbal[i]->getactivador() == false) {
				cantbal[i]->setactivador(true);
				cantbal[i]->CORDENADA(x, y);
					break;
			}
		}
	
	}
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
		

		cout << posx << "----" << posy << endl;
	}

	//MAPA 2 LURIGANCHO COLISIONES

	Void Mover2(Direccion direccion) {
		switch (direccion)
		{
		case Direccion::Ninguna:
			break;
		case Direccion::Abajo:
			if (movAbajo) { posy += dy; }
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

		while (true) {

		/*	if (posy >= 551 && 554 >= posy  &&  posx >= 134 && 638 >= posx) {

				movArriba = false; break;
			}

			else { movArriba = true; }*/

			if (posy >= 293 && 554 >= posy  &&  posx >= 635 && 638 >= posx) {

				movDerecha = false; break;
			}

			else { movDerecha = true; }

			if (posy >= 293 && 296 >= posy  &&  posx >= 608 && 638 >= posx) {

				movArriba = false; break;
			}

			else { movArriba = true; }

			if (posy >= 293 && 512 >= posy  &&  posx >= 608 && 611 >= posx) {

				movIzquierda = false; break;
			}

			else { movIzquierda = true; }

			if (posy >= 512 && 515 >= posy  &&  posx >= 236 && 608 >= posx) {

				movArriba = false; break;
			}

			else { movArriba = true; }

			if (posy >= 494 && 512 >= posy  &&  posx >= 233 && 236 >= posx) {

				movDerecha = false; break;
			}

			else { movDerecha = true; }
			//no madido xd 
			if (posy >= 491 && 494 >= posy  &&  posx >= 236 && 582 >= posx) {

				movAbajo = false; break;
			}

			else { movAbajo = true; }

			if (posy >= 438 && 494 >= posy  &&  posx >= 434 && 437 >= posx) {

				movDerecha = false; break;
			}

			else { movDerecha = true; }

			if (posy >= 458 && 461 >= posy  &&  posx >= 236 && 582 >= posx) {

				movArriba = false; break;
			}

			else { movArriba = true; }

			if (posx >= 233 && 236 >= posx && posy >= 356 && 458 >= posy) {

				movDerecha = false; break;
			}

			else { movDerecha = true; }

			if (posx >= 236 && 401 >= posx && posy >= 353 && 356 >= posy) {

				movAbajo = false; break;
			}

			else { movAbajo = true; }

			if (posx >= 398 && 401 >= posx && posy >= 320 && 356 >= posy) {

				movDerecha = false; break;
			}

			else { movDerecha = true; }

			if (posx >= 236 && 401 >= posx && posy >= 320 && 323 >= posy) {

				movArriba = false; break;
			}

			else { movArriba = true; }

			if (posx >= 233 && 236 >= posx && posy >= 224 && 320 >= posy) {

				movDerecha = false; break;
			}

			else { movDerecha = true; }

			if (posx >= 236 && 338 >= posx && posy >= 221 && 224 >= posy) {

				movAbajo = false; break;
			}

			else { movAbajo = true; }

			if (posx >= 335 && 338 >= posx && posy >= 188 && 224 >= posy) {

				movDerecha = false; break;
			}

			else { movDerecha = true; }

			if (posx >= 236 && 338 >= posx && posy >= 188 && 191 >= posy) {

				movArriba = false; break;
			}

			else { movArriba = true; }

			if (posx >= 233 && 236 >= posx && posy >= 134 && 188 >= posy) {

				movDerecha = false; break;
			}

			else { movDerecha = true; }

			if (posx >= 212 && 236 >= posx && posy >= 134 && 137 >= posy) {

				movArriba = false; break;
			}

			else { movArriba = true; }

			if (posx >= 212 && 215 >= posx && posy >= 134 && 188 >= posy) {

				movIzquierda = false; break;
			}

			else { movIzquierda = true; }

			if (posx >= 8 && 212 >= posx && posy >= 188 && 191 >= posy) {

				movArriba = false; break;
			}

			else { movArriba = true; }

			if (posx >= 8 && 11 >= posx && posy >= 188 && 224 >= posy) {

				movIzquierda = false; break;
			}

			else { movIzquierda = true; }

			if (posx >= 8 && 212 >= posx && posy >= 221 && 224 >= posy) {

				movAbajo = false; break;
			}

			else { movAbajo = true; }

			if (posx >= 212 && 215 >= posx && posy >= 224 && 320 >= posy) {

				movIzquierda = false; break;
			}

			else { movIzquierda = true; }

			if (posx >= 8 && 212 >= posx && posy >= 320 && 323 >= posy) {

				movArriba = false; break;
			}

			else { movArriba = true; }

			if (posx >= 8 && 11 >= posx && posy >= 320 && 356 >= posy) {

				movIzquierda = false; break;
			}

			else { movIzquierda = true; }

			if (posx >= 8 && 212 >= posx && posy >= 353 && 356 >= posy) {

				movAbajo = false; break;
			}

			else { movAbajo = true; }

			if (posx >= 212 && 215 >= posx && posy >= 356 && 458 >= posy) {

				movIzquierda = false; break;
			}

			else { movIzquierda = true; }

			if (posx >= 128 && 212 >= posx && posy >= 458 && 461 >= posy) {

				movArriba = false; break;
			}

			else { movArriba = true; }

			//confuncion mental, si sale error revisar aqui

			if (posx >= 128 && 131 >= posx && posy >= 458 && 494 >= posy) {

				movIzquierda = false; break;
			}

			else { movIzquierda = true; }

			if (posx >= 128 && 212 >= posx && posy >= 491 && 494 >= posy) {

				movAbajo = false; break;
			}

			else { movAbajo = true; }

			if (posx >= 212 && 215 >= posx && posy >= 494 && 512 >= posy) {

				movIzquierda = false; break;
			}

			else { movIzquierda = true; }

			if (posx >= 134 && 212 >= posx && posy >= 512 && 515 >= posy) {

				movArriba = false; break;
			}

			else { movArriba = true; }

			if (posx >= 134 && 137 >= posx && posy >= 512 && 554 >= posy) {

				movIzquierda = false; break;
			}

			else { movIzquierda = true; }

			/*if (posx >= 134 && 638 >= posx && posy >= 551 && 554 >= posy) {

				movAbajo = false; break;
			}

			else { movAbajo = true; }*/
			if (Formula(134, 638, 551, 554)) { movAbajo = false; break; }
			

			break;
		}

		cout << posx << "----" << posy << endl;

	}

	Void Mover3(Direccion direccion) {
		switch (direccion)
		{
		case Direccion::Ninguna:
			break;
		case Direccion::Abajo:
			if (movAbajo) { posy += dy; }
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

		while (true)
		{
			if (Formula(389, 392, 518, 578)) { movDerecha = false; break; }
			if (Formula(392, 620, 515, 518)) { movAbajo = false; break; }
			break;
		}
		cout << posx << "----" << posy << endl;
	}



	// Funcion formula general colisiones con el entorno
	bool Formula(Int16 xmin, Int16 xmax,Int16 ymin,Int16 ymax) {
		bool valzz;
		if (posx >= xmin && xmax >= posx && posy >= ymin && ymax >= posy) {
			valzz= true;
		}
		else { valzz = false; }return valzz;
	}
};