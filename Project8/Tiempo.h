#pragma once
#include <string>
using namespace System;
ref class tiempo
{
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
private:
	int hora;
	int min;
	String^ tiem;
};

