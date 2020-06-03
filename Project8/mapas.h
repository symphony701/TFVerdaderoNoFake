#pragma once
#include "Entidad.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;



ref class CMapas : public CEntidad {
private:
	Int16 vidas;
public:
	CMapas() {
		x = 0;
		y = 0;
		imagen = gcnew Bitmap("paisaje1.jpg");
		anchoSprite = imagen->Width;
		altoSprite = imagen->Height;
		anchoImagen = anchoSprite;
		altoImagen = altoSprite;

		areaVisible = Rectangle(0, 0, anchoImagen, altoImagen);
	}
	~CMapas() {}

	Void Disparar() {}

};