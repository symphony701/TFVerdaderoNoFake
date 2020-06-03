#pragma once
#include "Entidad.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class CAmbulancia : public CEntidad {
public:
	CAmbulancia() {
		x = 0;
		y = 0;
		imagen = gcnew Bitmap("ambulancia.png");
		anchoSprite = imagen->Width;
		altoSprite = imagen->Height;
		anchoImagen = anchoSprite / 3;
		altoImagen = altoSprite / 4;

		areaVisible = Rectangle(anchoImagen*x, altoImagen*y, anchoImagen, altoImagen);
	}
	~CAmbulancia() {}
};