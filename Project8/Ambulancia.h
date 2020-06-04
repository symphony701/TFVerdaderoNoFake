#pragma once
#include "Entidad.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class CAmbulancia : public CEntidad {
public:
	CAmbulancia() {
		/*x = 0;
		y = 0;*/
		posx = 390;
		posy = 295;
		dx = dy = 6;
		imagen = gcnew Bitmap("ambulancia.png");
		anchoSprite = imagen->Width;
		altoSprite = imagen->Height;
		anchoImagen = anchoSprite / 3;
		altoImagen = altoSprite / 4;

		areaVisible = Rectangle(anchoImagen*x, altoImagen*y, anchoImagen, altoImagen);
	}
	~CAmbulancia() {}
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
		case Direccion::Abajo: posy += dy;
			y = 0;
			break;
		case Direccion::Arriba:posy -= dy;
			y = 3;
			break;
		case Direccion::Izquierda:posx -= dx;
			y = 1;
			break;
		case Direccion::Derecha:posx += dx;
			y = 2;
			break;
		default:
			break;
		}
	}
};