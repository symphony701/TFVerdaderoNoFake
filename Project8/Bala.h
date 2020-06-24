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
	double angulo;
	int alto;
	int ancho;
	Bitmap^imagen;
	int direc;
	int dis = 0;

	bool act;
public:
	CBala(){
		imagen = gcnew Bitmap("tomate.png");
		this->x = 500;
		this->y = 200;

		act = false;
		this->dx = dx;
		dis = 0;
		
		dx = 5;

	}
	~CBala(){}
	Void modificar(double x, double y, int direc) {
		this->x = x;
		this->y = y;
		this->direc = direc;
		act = true;
	}
	Void direccion() {
		switch (direc){
		case 3: y-=dx; break;
		case 2:x+=dx; break;
		case 0:y+=dx; break;
		case 1: x-=dx; break;
		default:break;
		}
	}
	Void Mover() {
		
		/*x += dx;
		y = Ad + dis*tan(angulo);*/
		if (act) {
			direccion();
		}
		if (dis >= 7) {
			act = false;
			dis =0;
		}
		dis++;
	 }
	Void graficar(Graphics^g) {
		if (act) { g->DrawImage(imagen, (int)x, (int)y); }
		
	//	g->DrawImage(imagen, x, y,GraphicsUnit::Pixel);
	}
	bool getactivador() { return act; }
};
