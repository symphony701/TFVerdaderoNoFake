#pragma once
#include <cmath>
#include <iostream>
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
		this->x = 500;
		this->y = 200;
		this->dx = dx;
		this->DestX = 191;
		this->DestY = 446;
		angulo = atan((DestY - y) / (DestX - x));
		dx = 5;

	}
	~CBala(){}
	Void Mover() {
		x += dx;
		y = x*tan(angulo);
	 }
	Void graficar(Graphics^g) {
		areaVisible = Rectangle((int)x, (int)y, 17, 15);
		g->DrawImage(imagen, (int)x, (int)y);
	//	g->DrawImage(imagen, x, y,GraphicsUnit::Pixel);
	}
};
