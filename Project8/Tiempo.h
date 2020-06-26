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
		if (toquedequedacomi == 24 && toquedequedafinal == 0) { return false; }
		if (toquedequedacomi == 12 && toquedequedafinal == 12) { return true; }
		if (hora >= toquedequedafinal && hora < toquedequedacomi) { return false; }
		return true;
	}
	void Horasdetoquedequeda(int toqueco, int toquefin) { toquedequedacomi = toqueco; toquedequedafinal = toquefin; }
private:
	int hora;
	int min;
	String^ tiem;
	int toquedequedacomi;
	int toquedequedafinal;
};

