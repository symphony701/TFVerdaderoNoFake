#pragma once
#include <iostream>
#include "Entidad.h"
#include "Autoridad.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace std;

ref class CPolicia : public CAutoridad {

	
public:
	CPolicia(int mapa,int nroP) {
		this->mapa = mapa;
		this->nroP = nroP;
		origen = gcnew Point(posx, posy);
		if (mapa == 1)
		{
			puntos = gcnew cli::array<Point^>(15);

		}
		if (mapa == 2)
		{
			puntos = gcnew cli::array<Point^>(18);

		}
		dx = dy = 3;
		imagen = gcnew Bitmap("policias.png");
		anchoSprite = imagen->Width;
		altoSprite = imagen->Height;
		anchoImagen = anchoSprite / 4;
		altoImagen = altoSprite / 4;
		if (mapa==1&&nroP==1) {
			posx = 368;
			posy = -1;
		}
		if (mapa==1&&nroP==2)
		{
			posx = 497;
			posy = 59;
			
		}
		izquierda, derecha, arriba, abajo = false;
		origen->X = posx;
		origen->Y = posy;
		iniciarPuntos();
		cambioDireccion();
	}
	~CPolicia() {}
	


};