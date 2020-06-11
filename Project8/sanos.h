#pragma once
#include "Persona.h"
ref class Csanos :public CPersona{
	Csanos() {
	}
	~Csanos() {}
	Void Mostrar() {
		imagen = gcnew Bitmap("enemigos(sanos).png");
		perseguir = true;
	}




};