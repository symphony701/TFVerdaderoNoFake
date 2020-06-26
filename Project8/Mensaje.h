#pragma once
#include "Entidad.h"
#include <cstdlib>
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class CMensaje : public CEntidad {
private:
	Int16 direc;
	Int16 mensa;
	Int16 hor;
	Int16 ver;
	Int16 distan;
	bool activador;
	
	
public:
	CMensaje() {
		hor = ver= direc = distan =  0;
		activador = false;
		
	}
	~CMensaje() {}

	void Mosmensaje(){
		mensa = rand() % 5;
		if (mensa == 1) { MessageBox::Show("a"); }
		if (mensa == 2) { MessageBox::Show("b"); }
		if (mensa == 3) { MessageBox::Show("c"); }
		if (mensa == 4) { MessageBox::Show("d"); }
		if (mensa == 5) { MessageBox::Show("e"); }
	
	
	}
	void distancia(int d) {
		distan += 1;
		if (distan >= d) {
			activador = false;
			distan = 0;
		}
	}
	void desativador() {
		activador = false;
		distan = 0;
	}
	bool getactivador() { return activador; }
	void setactivador(bool activador) { this->activador = activador; }
	void CORDENADA(Int16 h, Int16 v) { hor=h; ver = v; }
	void sethor(Int16 h) { hor = h; }
	void setver(Int16 v) { ver = v; }
	void setdirec(Int16 d) { direc = d; }
	Int16 getdirec() { return direc; }
	Int16 gethor() { return hor; }
	Int16 getver() { return ver; }
	Rectangle  getRectangle() {

		return  Rectangle(posx, posy, 17, 15);
	}

};