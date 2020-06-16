#pragma once
#include "Entidad.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class CPolicia : public CEntidad {
private:
	bool direcc;
	bool arriba;
	bool abajo;
	bool derecha;
	bool izquierda;
	Point^origen;
public:
	CPolicia() {
		origen = gcnew Point(posx, posy);
		dx = dy = 1;
		imagen = gcnew Bitmap("policias.png");
		anchoSprite = imagen->Width;
		altoSprite = imagen->Height;
		anchoImagen = anchoSprite / 4;
		altoImagen = altoSprite / 8;
		posx = 368;
		posy = 176;
		arriba = abajo = derecha = izquierda = true;
		origen->X = posx;
		origen->Y = posy;
	}
	~CPolicia() {}
	Void Mostrar(Graphics^g) {
		areaVisible = Rectangle(anchoImagen*x, altoImagen*y, anchoImagen, altoImagen);
		g->DrawImage(imagen, posx, posy, areaVisible, GraphicsUnit::Pixel);
		if (x == 3) { x = 0; }
		x++;
	}
	Void Mover() {
		/*if (posx == 0) { direcc = true; y = 2; origen->X = posx;
		origen->Y = posy;
		}
		if (posx == 300) { direcc = false; y = 1; origen->X = posx;
		origen->Y = posy;
		}
		if (direcc) { posx = posx + dx; origen->X = posx;
		origen->Y = posy;
		}
		if (direcc==false) { posx = posx - dx;; origen->X = posx;
		origen->Y = posy;
		}*/
		posx = posx - dx;
		origen->X=posx;
		origen->Y = posy;
		
	}
	
	Point ^ getPoint() {
		return origen;
	}
	Rectangle ^getRectangle() {
		return Rectangle(posx, posy, posx+anchoImagen, posy+altoImagen);
	}


};