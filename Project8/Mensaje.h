#pragma once
#include "Entidad.h"
#include <cstdlib>
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class CMensaje : public CEntidad {
private:
	Int16 a;
	Int16 hor;
	Int16 ver;
	bool activador;
	
	
public:
	CMensaje() {
		hor = ver = a = 0;
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
	void CORDENADA(Int16 h, Int16 v) { hor=h; ver = v; }
	void sethor(Int16 h) { hor = h; }
	void setver(Int16 v) { ver = v; }
	Int16 gethor() { return hor; }
	Int16 getver() { return ver; }
};