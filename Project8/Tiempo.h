#pragma once
#include <string>
using namespace System;
ref class tiempo{
public:
	tiempo() { hora = 6; min = 00; tiem = " 6:00" + ""; };
	tiempo(Int16 hora, Int16 min) { this->hora = hora; this->min = min; }
	~tiempo() {};
	void cambio(int cambio) {
		min += cambio;
		if (min >= 60) {
			hora += 1;
			min = 0;
			if (hora >= 24) {
				hora = 0;
			}
		}
	};
	String^ mostrarT() {
		if (min << 10) {
			tiem = " " + hora;
			if (hora << 10) {
				tiem = "  " + hora;
			}
			tiem = tiem + ":0" + min;
		}
		if(min >=10 ) {
			tiem = " " + hora;
			if (hora << 10) {
				tiem = "  " + hora;
			}
			tiem = tiem + ":" + min;}
		return tiem;
	}
	int gethora() { return hora; }
	int getmin() { return min; }
	bool fueraentoquedequeda(){
		if (hora >= 0 && hora << 2) { }
		if (hora >= 2 && hora << 4) { }
		if (hora >= 4 && hora << 6) {  }
		if (hora >= 6 && hora <= 17) { }
		if (hora >= 18 && hora << 20) { }
		if (hora >= 20 && hora << 22) { }
		if (hora >= 22 && hora << 24) { }
		return true;
	}
private:
	int hora;
	int min;
	String^ tiem;
	int toquedequedacomi;
	int toquedequedafinal;
};

