#pragma once
#include "Entidad.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class CPolicia : public CEntidad {
public:
	CPolicia() {
		x = 0;
		y = 0;
		imagen = gcnew Bitmap("policias.png");
		anchoSprite = imagen->Width;
		altoSprite = imagen->Height;
		anchoImagen = anchoSprite / 4;
		altoImagen = altoSprite / 8;

		areaVisible = Rectangle(anchoImagen*x, altoImagen*y, anchoImagen, altoImagen);
	}
	~CPolicia() {}
};