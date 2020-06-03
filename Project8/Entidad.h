#pragma once
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
ref class CEntidad {
protected:
	Bitmap^imagen;
	Int16 anchoSprite;
	Int16 altoSprite;
	Int16 anchoImagen;
	Int16 altoImagen;
	Int16 x;
	Int16 y;
	Int16 dx;
	Int16 dy;
	Rectangle areaVisible;
public:
	CEntidad() {
		//imagen = gcnew Bitmap("ambulancia.png");
		//anchoSprite = imagen->Width;
		//altoSprite = imagen->Height;
		/*anchoImagen = anchoSprite / 12;
		altoImagen = altoSprite / 8;*/
		//anchoImagen = anchoSprite / 3;
		//altoImagen = altoSprite / 4;
		areaVisible = Rectangle(anchoImagen*x, altoImagen*y, anchoImagen, altoImagen);

	};
	~CEntidad() {};

	Int16 getX() { return x; }
	Int16 getY() { return y; }
	Int16 getDX() { return dx; }
	Int16 getDY() { return dy; }
	Rectangle getRectangle() { return areaVisible;}
	Bitmap ^getImagen() { return imagen; }

	Void Mostrar(){}
	Void Mover(){}



};
