#pragma once
#include "Entidad.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;



ref class CMapas : public CEntidad {
private:
	Int16 vidas;
public:
	CMapas(int nroMap) {
		x = 0;
		y = 0;
		switch (nroMap)
		{
		case 1:imagen = gcnew Bitmap("paisaje1.jpg"); break;
		case 2:imagen = gcnew Bitmap("paisajeSM4.jpg"); break;
		default:
			break;
		}
	//	imagen = gcnew Bitmap("paisaje1.jpg");
		anchoSprite = imagen->Width;
		altoSprite = imagen->Height;
		anchoImagen = anchoSprite;
		altoImagen = altoSprite;

		areaVisible = Rectangle(0, 0, anchoImagen, altoImagen);
	}
	~CMapas() {}

	Void Disparar() {}

};