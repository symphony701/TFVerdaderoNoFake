#pragma once
#include "Entidad.h"
#include <cstdlib>
#include "Mensaje.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class CArreMensajes : public CEntidad {
private:
	cli::array<CMensaje^>^ cantbal;
	Bitmap^ mensaje;
	Int16 anchoSprite;
	Int16 altoSprite;
public:
	CArreMensajes(Int16 num) {

		cantbal = gcnew cli::array<CMensaje^>(5);
		for (Int16 i = 0; i < 5; i++) {
			cantbal[i] = gcnew CMensaje();
		}
		switch (num){
		case 1:mensaje = gcnew Bitmap("papel.png"); break;
		case 2:mensaje = gcnew Bitmap("papel.png"); break;
		}
		anchoImagen = mensaje->Width;
		altoImagen = mensaje->Height;
	}
	~CArreMensajes() {}
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
	Int16 getposx(Int16 i) { return cantbal[i]->gethor(); }
	Int16 getposy(Int16 i) { return cantbal[i]->getver(); }
	Int16 getancho() { return anchoImagen; }
	Int16 getalto() { return altoImagen; }
	bool getactivador(Int16 i) { return cantbal[i]->getactivador(); }
};