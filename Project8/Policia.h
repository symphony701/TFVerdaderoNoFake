#pragma once
#include "Entidad.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class CPolicia : public CEntidad {
private:
	bool direcc;
public:
	CPolicia() {
		dx = dy = 4;
		imagen = gcnew Bitmap("policias.png");
		anchoSprite = imagen->Width;
		altoSprite = imagen->Height;
		anchoImagen = anchoSprite / 4;
		altoImagen = altoSprite / 8;
		posx = 0;
		posy = 200;

		
	}
	~CPolicia() {}
	Void Mostrar(Graphics^g) {
		areaVisible = Rectangle(anchoImagen*x, altoImagen*y, anchoImagen, altoImagen);
		g->DrawImage(imagen, posx, posy, areaVisible, GraphicsUnit::Pixel);
		if (x == 3) { x = 0; }
		x++;
	}
	Void Mover() {
		if (posx == 0) { direcc = true; y = 2; }
		if (posx == 300) { direcc = false; y = 1; }
		if (direcc) { posx = posx + dx; }
		if (direcc==false) { posx = posx - dx;; }

	}
};