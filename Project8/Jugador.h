#pragma once
#include "Entidad.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
enum  Direccion
{
	Ninguna,Abajo,Arriba,Izquierda,Derecha
};

ref class CJugador : public CEntidad{
private:
	Int16 vidas;
	Direccion ultimaTecla;
public:
	CJugador() {
	//	x = 0;
		//y = 0;
		posx = posy = 0;
		dx=dy = 3;
		imagen = gcnew Bitmap("jugador.png");
		anchoSprite = imagen->Width;
		altoSprite = imagen->Height;
		anchoImagen = anchoSprite / 12;
		altoImagen = altoSprite / 8;
		Direccion direccion;
		
	}
	~CJugador(){}

	Void Disparar(){}
	Void Mostrar(Graphics^g,bool act) {
		
		areaVisible = Rectangle(anchoImagen*x, altoImagen*y, anchoImagen, altoImagen);
	//	g->Clear(Color::White);
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