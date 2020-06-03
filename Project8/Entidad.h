#pragma once
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
ref class CEntidad {
private:
	Bitmap^imagen;
	Int16 anchoSprite;
	Int16 altoSprite;
	Int16 anchoImagen;
	Int16 altoImagen;
	Int16 x=0;
	Int16 y=0;
	Int16 dx;
	Int16 dy;
	Rectangle areaVisible;
public:
	CEntidad() {
		imagen = gcnew Bitmap("ambulancia.png");
		anchoSprite = imagen->Width;
		altoSprite = imagen->Height;
		/*anchoImagen = anchoSprite / 12;
		altoImagen = altoSprite / 8;*/
		anchoImagen = anchoSprite / 3;
		altoImagen = altoSprite / 4;
		areaVisible = Rectangle(anchoImagen*x, altoImagen*y, anchoImagen, altoImagen);

	};
	~CEntidad() {};

	Rectangle getRectangle() { return areaVisible;}
	Int16 getX() { return x; }
	Int16 getY() { return y; }
	Bitmap ^getImagen() { return imagen; }



};
