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
	double dis = 0;
	double Ad;
public:
	CBala(double x,double y,double dx,double DestX,double DestY){
		imagen = gcnew Bitmap("tomate.png");
		this->x = x;
		this->y = y;
	/*	this->x = 500;
		this->y = 200;*/
		Ad = y;
		this->dx = dx;
		dis = 0;
		/*this->DestX = 191;
		this->DestY = 446;*/
		double i = (DestY - y) / (DestX - x);
		angulo = atan((DestY - y) / (DestX - x));
		/*if (i <= 0) {
			angulo = angulo + atan(0);
		}*/
		dx = 5;

	}
	~CBala(){}
	Void Mover() {
		dis += dx;
		x += dx;
		y = Ad + dis*tan(angulo);
		if (dis >= 5) {
			dis = 100;
		}
	 }
	Void graficar(Graphics^g) {
		areaVisible = Rectangle((int)x, (int)y, 17, 15);
		g->DrawImage(imagen, (int)x, (int)y);
	//	g->DrawImage(imagen, x, y,GraphicsUnit::Pixel);
	}
};
