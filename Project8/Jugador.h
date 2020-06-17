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
	bool movArriba, movAbajo, movDerecha, movIzquierda;
	Bitmap^ mensaje;
	cli::array<CMensaje^>^ cantbal;
	Climites^ limites;
public:
	CJugador() {

		posx = 191;
		posy = 446;
		dx = dy = 3;
		cantbal = gcnew cli::array<CMensaje^>(5);
		for (Int16 i = 0; i < 5; i++) {
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
		limites = gcnew Climites();
	}
	~CJugador() {
		delete limites, cantbal, imagen, mensaje;
	}

	Void Disparar(Graphics^g) {
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

	}
	Void MostrarDisparo(Int16 x, Int16 y, Int16 d) {
		for (int i = 0; i < 5; i++) {
			if (cantbal[i]->getactivador() == false) {
				cantbal[i]->setactivador(true);
				cantbal[i]->CORDENADA(x, y);
				cantbal[i]->setdirec(d);
				break;
			}
		}

	}
	Void Mostrar(Graphics^g, bool act) {

		areaVisible = Rectangle(anchoImagen*x, altoImagen*y, anchoImagen, altoImagen);

		g->DrawImage(imagen, posx, posy, areaVisible, GraphicsUnit::Pixel);
		if (act == true) { x++; }

		if (x == 3) { x = 0; }
	}

	cli::array<Rectangle>^colMensaje() {
		cli::array<Rectangle>^ rectangulos;
		rectangulos = gcnew cli::array<Rectangle>(5);
		for (int i = 0; i < cantbal->Length; i++)
		{
			rectangulos[i] = cantbal[i]->getRectangle();
		}


		return rectangulos;

	}





	Void Mover(Direccion direccion) {

		switch (direccion)
		{
		case Direccion::Ninguna:
			break;
		case Direccion::Abajo:
			if (movAbajo) { posy += dy; }
			movAbajo = limites->mapa1abajo(movAbajo, posx, posy);
			y = 0;
			break;
		case Direccion::Arriba:
			if (movArriba) { posy -= dy; }
			movArriba =limites->mapa1arriba( movArriba,  posx,  posy);
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

		//if (posy >= 573 - altoImagen) {
		//	movAbajo = false;
		//}
		//else { movAbajo = true; }
		
		////Codigo solo para valientes xd
		//while (true) {
		//	////Casa aislada
		//	if (posy >= 440 && posy <= 445 && posx <= 250 && posx >= 179) {
		//		movArriba = false; break;
		//	}
		//	else { movArriba = true; }
		//	if (posy >= 374 && posy <= 437 && posx <= 260 && posx >= 257) {
		//		movIzquierda = false; break;
		//	}
		//	else { movIzquierda = true; }
		//	if (posy >= 365 && posy <= 368 && posx <= 250 && posx >= 179) {
		//		movAbajo = false; break;
		//	}
		//	else { movAbajo = true; }
		//	if (posy >= 380 && posy <= 431 && posx <= 161 && posx >= 158) {
		//		movDerecha = false; break;
		//	}
		//	else { movDerecha = true; }
		//	//Valla baja
		//	if (posy >= 517 && 521 >= posy  &&  posx >= 104 && 632 >= posx) {
		//		movAbajo = false; break;
		//	}
		//	else { movAbajo = true; }
		//	if (posy >= 329 && 521 >= posy  &&  posx >= 101 && 104 >= posx) {
		//		movIzquierda = false; break;
		//	}
		//	else { movIzquierda = true; }
		//	if (posy >= 327 && 329 >= posy  &&  posx >= -4 && 103 >= posx) {
		//		movAbajo = false; break;
		//	}
		//	else { movAbajo = true; }
		//	//Valla derecha
		//	if (posy >= 143 && 146 >= posy  &&  posx >= 590 && 632 >= posx) {
		//		movArriba = false; break;
		//	}
		//	else { movArriba = true; }
		//	if (posy >= 47 && 146 >= posy  &&  posx >= 587 && 593 >= posx) {
		//		movDerecha = false; break;
		//	}
		//	else { movDerecha = true; }
		//	if (posy >= 47 && 49 >= posy  &&  posx >= 420 && 590 >= posx) {
		//		movArriba = false; break;
		//	}
		//	else { movArriba = true; }
		//	//salta las leyes de la programacion
		//	if (posy >= 47 && 83 >= posy  &&  posx >= 467 && 470 >= posx) {
		//		movIzquierda = false; break;
		//	}
		//	else { movIzquierda = true; }
		//	//
		//	if (posy >= 80 && 83 >= posy  &&  posx >= 470 && 563 >= posx) {
		//		movAbajo = false; break;
		//	}
		//	else { movAbajo = true; }
		//	if (posy >= 83 && 320 >= posy  &&  posx >= 560 && 563 >= posx) {
		//		movIzquierda = false; break;
		//	}
		//	else { movIzquierda = true; }
		//	//
		//	if (posy >= 317 && 320 >= posy  &&  posx >= 299 && 563 >= posx) {
		//		movArriba = false; break;
		//	}
		//	else { movArriba = true; }
		//	if (posy >= 260 && 320 >= posy  &&  posx >= 296 && 299 >= posx) {
		//		movDerecha = false; break;
		//	}
		//	if (posy >= 260 && 320 >= posy  &&  posx >= 296 && 299 >= posx) {
		//		movDerecha = false; break;
		//	}
		//	else { movDerecha = true; }
		//	if (posy >= 257 && 260 >= posy  &&  posx >= 149 && 299 >= posx) {
		//		movArriba = false; break;
		//	}
		//	else { movArriba = true; }
		//	if (posy >= 188 && 260 >= posy  &&  posx >= 146 && 149 >= posx) {
	//		movDerecha = false; break;
		//	}
		//	else { movDerecha = true; }
		//	if (posy >= 185 && 188 >= posy  &&  posx >= 149 && 524 >= posx) {
		//		movAbajo = false; break;
		//	}
		//	else { movAbajo = true; }
		//	if (posy >= 158 && 194 >= posy  &&  posx >= 521 && 524 >= posx) {
		//		movDerecha = false; break;
		//	}
		//	else { movDerecha = true; }
		//	if (posy >= 155 && 158 >= posy  &&  posx >= 389 && 524 >= posx) {
		//		movArriba = false; break;
		//	}
		//	else { movArriba = true; }
		//	if (posy >= 155 && 158 >= posy  &&  posx >= 125 && 356 >= posx) {
		//		movArriba = false; break;
		//	}
		//	else { movArriba = true; }
		//	if (posy >= 158 && 293 >= posy  &&  posx >= 125 && 127 >= posx) {
		//		movIzquierda = false; break;
		//	}
		//	else { movIzquierda = true; }
		//	if (posy >= 10 && 158 >= posy  &&  posx >= 386 && 389 >= posx) {
		//		movDerecha = false; break;
		//	}
		//	else { movDerecha = true; }
		//	if (posy >= 10 && 158 >= posy  &&  posx >= 356 && 359 >= posx) {
		//		movIzquierda = false; break;
		//	}
		//	else { movIzquierda = true; }
		//	if (posy >= 290 && 293 >= posy  &&  posx >= -13 && 125 >= posx) {
		//		movArriba = false; break;
		//	}
		//	else { movArriba = true; }
		//	if (posy >= 365 && 443 >= posy  &&  posx >= 287 && 290 >= posx) {
		//		movDerecha = false; break;
		//	}
		//	else { movDerecha = true; }
		//	if (posy >= 440 && 443 >= posy  &&  posx >= 290 && 584 >= posx) {
		//		movArriba = false; break;
		//	}
		//	else { movArriba = true; }
		//	if (posy >= 365 && 443 >= posy  &&  posx >= 584 && 587 >= posx) {
		//		movIzquierda = false; break;
		//	}
		//	else { movIzquierda = true; }
		//	if (posy >= 362 && 365 >= posy  &&  posx >= 290 && 584 >= posx) {
		//		movAbajo = false; break;
		//	}
		//	else { movAbajo = true; }
		//	break;
		//}
		//cout << posx << "----" << posy << endl;
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
	
		//while (true) {
		//	/*	if (posy >= 551 && 554 >= posy  &&  posx >= 134 && 638 >= posx) {
		//			movArriba = false; break;
		//		}
		//		else { movArriba = true; }*/
		//	if (posy >= 293 && 554 >= posy  &&  posx >= 635 && 638 >= posx) {
		//		movDerecha = false; break;
		//	}
		//	else { movDerecha = true; }
		//	if (posy >= 293 && 296 >= posy  &&  posx >= 608 && 638 >= posx) {
		//		movArriba = false; break;
		//	}
		//	else { movArriba = true; }
		//	if (posy >= 293 && 512 >= posy  &&  posx >= 608 && 611 >= posx) {
		//		movIzquierda = false; break;
		//	}
		//	else { movIzquierda = true; }
		//	if (posy >= 512 && 515 >= posy  &&  posx >= 236 && 608 >= posx) {
		//		movArriba = false; break;
		//	}
		//	else { movArriba = true; }
		//	if (posy >= 494 && 512 >= posy  &&  posx >= 233 && 236 >= posx) {
		//		movDerecha = false; break;
		//	}
		//	else { movDerecha = true; }
		//	//no madido xd 
		/*	if (posy >= 491 && 494 >= posy  &&  posx >= 236 && 582 >= posx) {
				movAbajo = false; break;
			}
			else { movAbajo = true; }*/
		//	if (posy >= 438 && 494 >= posy  &&  posx >= 434 && 437 >= posx) {
		//		movDerecha = false; break;
		//	}
		//	else { movDerecha = true; }
		//	if (posy >= 458 && 461 >= posy  &&  posx >= 236 && 582 >= posx) {
		//		movArriba = false; break;
		//	}
		//	else { movArriba = true; }
		//	if (posx >= 233 && 236 >= posx && posy >= 356 && 458 >= posy) {
		//		movDerecha = false; break;
		//	}
		//	else { movDerecha = true; }
			//if (posx >= 236 && 401 >= posx && posy >= 353 && 356 >= posy) {
			//	movAbajo = false; break;
			//}
			//else { movAbajo = true; }
		//	if (posx >= 398 && 401 >= posx && posy >= 320 && 356 >= posy) {
		//		movDerecha = false; break;
		//	}
		//	else { movDerecha = true; }
		//	if (posx >= 236 && 401 >= posx && posy >= 320 && 323 >= posy) {
		//		movArriba = false; break;
		//	}
		//	else { movArriba = true; }
		//	if (posx >= 233 && 236 >= posx && posy >= 224 && 320 >= posy) {
		//		movDerecha = false; break;
		//	}
		//	else { movDerecha = true; }
			//if (posx >= 236 && 338 >= posx && posy >= 221 && 224 >= posy) {
			//	movAbajo = false; break;
			//}
			//else { movAbajo = true; }
		//	if (posx >= 335 && 338 >= posx && posy >= 188 && 224 >= posy) {
		//		movDerecha = false; break;
		//	}
		//	else { movDerecha = true; }
		//	if (posx >= 236 && 338 >= posx && posy >= 188 && 191 >= posy) {
		//		movArriba = false; break;
		//	}
		//	else { movArriba = true; }
		//	if (posx >= 233 && 236 >= posx && posy >= 134 && 188 >= posy) {
		//		movDerecha = false; break;
		//	}
		//	else { movDerecha = true; }
		//	if (posx >= 212 && 236 >= posx && posy >= 134 && 137 >= posy) {
		//		movArriba = false; break;
		//	}
		//	else { movArriba = true; }
		//	if (posx >= 212 && 215 >= posx && posy >= 134 && 188 >= posy) {
		//		movIzquierda = false; break;
		//	}
		//	else { movIzquierda = true; }
		//	if (posx >= 8 && 212 >= posx && posy >= 188 && 191 >= posy) {
		//		movArriba = false; break;
		//	}
		//	else { movArriba = true; }
		//	if (posx >= 8 && 11 >= posx && posy >= 188 && 224 >= posy) {
		//		movIzquierda = false; break;
		//	}
		//	else { movIzquierda = true; }
		//	if (posx >= 8 && 212 >= posx && posy >= 221 && 224 >= posy) {
		//		movAbajo = false; break;
		//	}
		//	else { movAbajo = true; }
		//	if (posx >= 212 && 215 >= posx && posy >= 224 && 320 >= posy) {
		//		movIzquierda = false; break;
		//	}
		//	else { movIzquierda = true; }
		//	if (posx >= 8 && 212 >= posx && posy >= 320 && 323 >= posy) {
		//		movArriba = false; break;
		//	}
		//	else { movArriba = true; }
		//	if (posx >= 8 && 11 >= posx && posy >= 320 && 356 >= posy) {
		//		movIzquierda = false; break;
		//	}
		//	else { movIzquierda = true; }
		//	if (posx >= 8 && 212 >= posx && posy >= 353 && 356 >= posy) {
		//		movAbajo = false; break;
		//	}
		//	else { movAbajo = true; }
		//	if (posx >= 212 && 215 >= posx && posy >= 356 && 458 >= posy) {
		//		movIzquierda = false; break;
		//	}
		//	else { movIzquierda = true; }
		//	if (posx >= 128 && 212 >= posx && posy >= 458 && 461 >= posy) {
		//		movArriba = false; break;
		//	}
		//	else { movArriba = true; }
		//	//confuncion mental, si sale error revisar aqui
		//	if (posx >= 128 && 131 >= posx && posy >= 458 && 494 >= posy) {
		//		movIzquierda = false; break;
		//	}
		//	else { movIzquierda = true; }
		//	if (posx >= 128 && 212 >= posx && posy >= 491 && 494 >= posy) {
		//		movAbajo = false; break;
		//	}
		//	else { movAbajo = true; }
		//	if (posx >= 212 && 215 >= posx && posy >= 494 && 512 >= posy) {
		//		movIzquierda = false; break;
		//	}
		//	else { movIzquierda = true; }
		//	if (posx >= 134 && 212 >= posx && posy >= 512 && 515 >= posy) {
		//		movArriba = false; break;
		//	}
		//	else { movArriba = true; }
		//	if (posx >= 134 && 137 >= posx && posy >= 512 && 554 >= posy) {
		//		movIzquierda = false; break;
		//	}
		//	else { movIzquierda = true; }
		//	/*if (posx >= 134 && 638 >= posx && posy >= 551 && 554 >= posy) {
		//		movAbajo = false; break;
		//	}
		//	else { movAbajo = true; }*/
		//	if (Formula(134, 638, 551, 554)) { movAbajo = false; break; }
		//	break;
		//}
		//cout << posx << "----" << posy << endl;

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
	
		/*while (true)
		{
			if (Formula(389, 392, 518, 578)) { movDerecha = false; break; }
			if (Formula(392, 620, 515, 518)) { movAbajo = false; break; }
			if (Formula(617, 620, 485, 518)) { movDerecha = false; break; }
			if (Formula(344, 620, 485, 488)) { movArriba = false; break; }
			if (Formula(341, 344, 434, 485)) { movDerecha = false; break; }
			if (Formula(344, 656, 431, 434)) { movAbajo = false; break; }
			if (Formula(653, 656, 239, 434)) { movDerecha = false; break; }
			if (Formula(629, 656, 239, 242)) { movArriba = false; break; }
			if (Formula(629, 632, 239, 287)) { movIzquierda = false; break; }
			if (Formula(506, 629, 287, 290)) { movArriba = false; break; }
			if (Formula(503, 506, 239, 287)) { movDerecha = false; break; }
			if (Formula(482, 506, 239, 242)) { movArriba = false; break; }
			if (Formula(482, 485, 239, 287)) { movIzquierda = false; break; }
			if (Formula(344, 482, 287, 290)) { movArriba = false; break; }
			if (Formula(341, 344, 89, 287)) { movDerecha = false; break; }
			if (Formula(344, 488, 87, 89)) { movAbajo = false; break; }
			if (Formula(485, 488, 59, 89)) { movDerecha = false; break; }
			if (Formula(488, 629, 57, 59)) { movAbajo = false; break; }
			if (Formula(629, 632, 59, 143)) { movIzquierda = false; break; }
			if (Formula(629, 657, 140, 143)) { movAbajo = false; break; }
			if (Formula(654, 657, 41, 143)) { movDerecha = false; break; }
			if (Formula(467, 657, 41, 44)) { movArriba = false; break; }
			if (Formula(467, 470, 41, 62)) { movIzquierda = false; break; }
			if (Formula(410, 470, 62, 65)) { movArriba = false; break; }
			if (Formula(320, 368, 62, 65)) { movArriba = false; break; }
			if (Formula(320, 323, 62, 239)) { movIzquierda = false; break; }
			if (Formula(203, 320, 239, 242)) { movArriba = false; break; }
			if (Formula(203, 206, 239, 275)) { movIzquierda = false; break; }
			if (Formula(203, 320, 273, 275)) { movAbajo = false; break; }
			if (Formula(320, 323, 275, 485)) { movIzquierda = false; break; }
			if (Formula(224, 320, 485, 488)) { movArriba = false; break; }
			if (Formula(224, 227, 485, 518)) { movIzquierda = false; break; }
			if (Formula(224, 350, 515, 518)) { movAbajo = false; break; }
			if (Formula(350, 353, 518, 578)) { movIzquierda = false; break; }
			if (Formula(368, 371, -16, 62)) { movIzquierda = false; break; }
			if (Formula(407, 410, -16, 62)) { movDerecha = false; break; }
			if (Formula(341, 344, 320, 395)) { movDerecha = false; break; }
			if (Formula(344, 482, 317, 320)) { movAbajo = false; break; }
			if (Formula(482, 485, 320, 395)) { movIzquierda = false; break; }
			if (Formula(344, 482, 395, 398)) { movArriba = false; break; }
			if (Formula(503, 506, 320, 395)) { movDerecha = false; break; }
			if (Formula(506, 629, 395, 398)) { movArriba = false; break; }
			if (Formula(629, 632, 320, 395)) { movIzquierda = false; break; }
			if (Formula(506, 629, 319, 320)) { movAbajo = false; break; }


			movAbajo = movDerecha = movArriba = movIzquierda = true;
			break;
		}
		cout << posx << "----" << posy << endl;*/
	}



	// Funcion formula general colisiones con el entorno
	/*bool Formula(Int16 xmin, Int16 xmax, Int16 ymin, Int16 ymax) {
		bool valzz;
		if (posx >= xmin && xmax >= posx && posy >= ymin && ymax >= posy) {
			valzz = true;
		}
		else { valzz = false; }return valzz;
	}*/

};