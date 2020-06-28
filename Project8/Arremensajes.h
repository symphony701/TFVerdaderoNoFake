#pragma once
#include "Entidad.h"
#include <cstdlib>
#include "Mensaje.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class CArreMensajes : public CEntidad {

	cli::array<CMensaje^>^ cantbal;
	Bitmap^ mensaje;
	Int16 anchoSprite;
	Int16 altoSprite;
	Int16 opc;
	Int16 dis;
public:
	CArreMensajes(Int16 num) {
		opc = num;
		cantbal = gcnew cli::array<CMensaje^>(5);
		for (Int16 i = 0; i < 5; i++) {
			cantbal[i] = gcnew CMensaje();
		}
		dis = 0;
		switch (num){
		case 1:mensaje = gcnew Bitmap("papel.png"); break;
		case 2:mensaje = gcnew Bitmap("tomate.png"); break;
		}
		anchoImagen = mensaje->Width;
		altoImagen = mensaje->Height;
	}
	~CArreMensajes() {}
	Void MostrarDisparo(Graphics^g) {
		if(opc ==1){
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
					cantbal[i]->distancia(18);
				}
			}
		}
		if (opc == 2) {
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
					cantbal[i]->distancia(18);
				}
			}
		}

	}
	Void Disparar(Int16 x, Int16 y, Int16 d,Int16 ancho, Int16 alto) {
		if (opc == 1) {
			for (int i = 0; i < 5; i++) {
				if (cantbal[i]->getactivador() == false) {
					cantbal[i]->setactivador(true);
					if (d == 0) {
						cantbal[i]->CORDENADA(x, y + alto - 10);
					}
					if (d == 1) {
						cantbal[i]->CORDENADA(x - anchoImagen + 6, y + 12);
					}
					if (d == 2) {
						cantbal[i]->CORDENADA(x + ancho - 9, y + 12);
					}
					if (d == 3) {
						cantbal[i]->CORDENADA(x, y - altoImagen + 14);
					}
					cantbal[i]->setdirec(d);
					break;
				}
			}
		}
		if (opc == 2) {
			for (int i = 0; i < 5; i++) {
				dis++;
				if (dis >= 8) { dis = 0; }
				if (cantbal[i]->getactivador() == false&& dis ==1) {
					cantbal[i]->setactivador(true);
					if (d == 0) {
						cantbal[i]->CORDENADA(x, y + alto - 10);
					}
					if (d == 1) {
						cantbal[i]->CORDENADA(x - anchoImagen + 6, y + 12);
					}
					if (d == 2) {
						cantbal[i]->CORDENADA(x + ancho - 9, y + 12);
					}
					if (d == 3) {
						cantbal[i]->CORDENADA(x, y - altoImagen + 14);
					}
					cantbal[i]->setdirec(d);
					break;
				}
			}
		}

	}
	Int16 getposx(Int16 i) { return cantbal[i]->gethor(); }
	Int16 getposy(Int16 i) { return cantbal[i]->getver(); }
	Int16 getancho() { return anchoImagen; }
	Int16 getalto() { return altoImagen; }
	bool getactivador(int i) { return cantbal[i]->getactivador(); }
	void desativador(int i) { return cantbal[i]->desativador(); }
	bool Colision(Rectangle^ juga) {
		bool retornador = false;
	
		for (int i = 0; i < cantbal->Length; i++)
		{
			if (juga->IntersectsWith(cantbal[i]->getRectangle())) {
				
				retornador = true;
				break;
			}
			else { retornador = false; }
		}
		return retornador;
	}
	Void MostrarMensaje() { cantbal[0]->Mosmensaje(); }
};