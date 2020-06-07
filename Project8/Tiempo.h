#pragma once
#include <string>
using namespace System;
ref class tiempo
{
public:
	tiempo() { hora = 17; min = 45; tiem = "6:00" + ""; };
	~tiempo() {};
	void cambio(Int16 cambio) {
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
			tiem = hora + ":0" + min;
		}
		if(min >=10 ) {tiem = hora + ":" + min;}
		return tiem;
	}
	Int16 gethora() { return hora; }
private:
	Int16 hora;
	Int16 min;
	String^ tiem;
};

