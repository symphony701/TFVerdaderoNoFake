#pragma once
#include "Entidad.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class CPersona : public CEntidad {
protected:
	bool virus, perseguir;
	Int16 posx, posy, altoImagen, anchoImagen,altoSprite,anchoSprite;
	Bitmap^imagen;
public:
	CPersona(){}
	~CPersona(){}
};