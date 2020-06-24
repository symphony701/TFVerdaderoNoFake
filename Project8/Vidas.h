#pragma once
#include "Entidad.h"
ref class Cvidas : public CEntidad {
	Int16 cant;
	Int16 d;
	bool act;
public:
	Cvidas() {
		imagen = gcnew Bitmap("corazon.png");
		posx = 10;
		posy = 15;
		cant = 3;
		d = 0;
		act = false;
	}
	~Cvidas() { delete imagen; }
	Void Cantivi(Graphics^ g) {
		for (int i = 0; i < cant; i++){
			g->DrawImage(imagen, posx+30 * i, posy);
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
	Void setcantvida(Int16 cantv) { cant = cantv; }
	Void cambioppos(Int16 x, Int16 y) { posx = x; posy = y; }
};