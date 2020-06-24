#pragma once
#include <cmath>
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace std;
ref class CBala {
	double x;
	double y;
	double dx;
	double DestX;
	double DestY;
	double angulo;
	int alto;
	int ancho;
	Bitmap^imagen;
	Rectangle areaVisible;
public:
	CBala(double x,double y,double dx,double DestX,double DestY){
		imagen = gcnew Bitmap("tomate.png");
		this->x = x;
		this->y = y;
		this->dx = dx;
		this->DestX = DestX;
		this->DestY = DestY;
		angulo = atan((DestY - y) / (DestX - x));

	}
	~CBala(){}
	Void Mover() {
		x += dx;
		y = x*tan(angulo);
	 }
	Void graficar(Graphics^g) {
		areaVisible = Rectangle(x, y, 17, 15);
		g->DrawImage(imagen, x, y,areaVisible, GraphicsUnit::Pixel);
	}
};
