#pragma once
#include "Entidad.h"
#include <cstdlib>
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class CMensaje : public CEntidad {
private:
	Int16 a;
	Int16 X;
	Int16 Y;
	bool activador;
	
	
public:
	CMensaje() {
		X = Y = a = 0;
		activador = false;
		
	}
	~CMensaje() {}

	Void Mosmensaje(){
		a = rand() % 5;
		if (a == 1) { MessageBox::Show("a"); }
		if (a == 2) { MessageBox::Show("b"); }
		if (a == 3) { MessageBox::Show("c"); }
		if (a == 4) { MessageBox::Show("d"); }
		if (a == 5) { MessageBox::Show("e"); }
	
	
	}
	bool getactivador() { return activador; }
	void setactivador(bool activador) { this->activador = activador; }
	void CORDENADA(Int16 X, Int16 Y) { this->X = X; this->Y = Y; }
	void setx(Int16 X) { this->X = X; }
	Int16 getx() { return X; }
	Int16 gety() { return Y; }
};