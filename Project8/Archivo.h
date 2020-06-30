#pragma once
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;
ref class CArchivo {
private:
	int eneEle,toDePun,dinRes;

public:
	CArchivo() {
		ifstream file("some.txt");
		int a, pts, din;
		file >> a >> pts >> din;
		this->eneEle = a;
		this->toDePun = pts;
		this->dinRes = din;
	};
	~CArchivo() {}
	void Escribir(int enemigosEliminados,int totalDePuntaje,int dineroRestante) {
		ofstream file("some.txt");
		file << enemigosEliminados<<" "<<totalDePuntaje<<" "<<dineroRestante<<endl;
		file.close();
	}
	void Abrir() {
		ifstream file("some.txt");

	}
	bool Comparar(int totalDePuntaje) {
		bool val;
		if (totalDePuntaje>toDePun)
		{
			val = true;
		}
		else
		{
			val = false;
		}
		return val;
	}
	int getEneEle() { return eneEle; }
	int getToDePun() { return toDePun; }
	int getDinRes() { return dinRes; }
};