#pragma once
#include "Entidad.h"
ref class Cvidas : public CEntidad {
	Int16 cant;
	Int16 d;
	bool act;
public:
	Cvidas() {
		imagen = gcnew Bitmap("corazon.png");
		posx = 0;
		posy = 0;
		cant = 3;
		d = 0;
		act = false;
	}
	~Cvidas() { delete imagen; }
	Void Cantivi(Graphics^ g) {
		for (int i = 0; i < cant; i++){
			g->DrawImage(imagen, 10+30 * i, 15);
		}
	}
	Void perdervida(bool i) {
		if (i && d == 0) {
			cant = cant - 1;
			if (cant < 0) {
				cant = 0;
			}
			act = true;
		}
		if (act) {
			d++;
		}
		if (d >= 20) {
			d = 0;
			act = false;
		}
	}
	Int16 getcantvida() { return cant; }
};