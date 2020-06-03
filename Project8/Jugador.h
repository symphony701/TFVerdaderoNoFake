#pragma once
#include "Entidad.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class CJugador : public CEntidad{
private:
	Int16 vidas;
public:
	CJugador() {
		x = 0;
		y = 0;
		imagen = gcnew Bitmap("jugador.png");
		anchoSprite = imagen->Width;
		altoSprite = imagen->Height;
		anchoImagen = anchoSprite / 12;
		altoImagen = altoSprite / 8;
		
		areaVisible = Rectangle(anchoImagen*x, altoImagen*y, anchoImagen, altoImagen);
	}
	~CJugador(){}

	Void Disparar(){}

};