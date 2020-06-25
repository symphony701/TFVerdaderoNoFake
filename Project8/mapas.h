#pragma once
#include "Entidad.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;



ref class CMapas : public CEntidad {
private:
	Int16 num;

public:
	CMapas(int nroMap) {
		x = 0;
		y = 0;
		switch (nroMap)
		{
		case 1:imagen = gcnew Bitmap("paisaje1.jpg"); num = 1; break;
		case 2:imagen = gcnew Bitmap("paisajeSM4.jpg"); num = 2; break;
		case 3:imagen = gcnew Bitmap("paisajeSM1.jpg"); num = 3; break;
		default:
			break;
		}
		
		anchoSprite = imagen->Width;
		altoSprite = imagen->Height;
		anchoImagen = anchoSprite;
		altoImagen = altoSprite;

		areaVisible = Rectangle(0, 0, anchoImagen, altoImagen);
	}
	~CMapas() {}
	void cambio(Int16 tiem){
		if (num == 1) { cambioSJL1(tiem); }
		if (num == 3) { cambioSJL2(tiem); }
		if (num == 2) { cambioSM(tiem); }
	}
	void cambioSJL1(Int16 tiem) {
		if (tiem >= 0 && tiem << 2) { imagen = gcnew Bitmap("paisaje1(+noche).jpg"); }
		if (tiem >= 2 && tiem << 4) { imagen = gcnew Bitmap("paisaje1(noche).jpg"); }
		if (tiem >= 4 && tiem << 6) { imagen = gcnew Bitmap("paisaje1(-noche).jpg"); }
		if (tiem >= 6 && tiem <= 17) { imagen = gcnew Bitmap("paisaje1.jpg"); }
		if (tiem >= 18 && tiem << 20) { imagen = gcnew Bitmap("paisaje1(-noche).jpg"); }
		if (tiem >= 20 && tiem << 22) { imagen = gcnew Bitmap("paisaje1(noche).jpg"); }
		if (tiem >= 22 && tiem << 24) { imagen = gcnew Bitmap("paisaje1(+noche).jpg"); }
	}
	void cambioSJL2(Int16 tiem) {
		
		if (tiem >= 0 && tiem << 2) { imagen = gcnew Bitmap("paisajeSM1(+noche).jpg"); }
		if (tiem >= 2 && tiem << 4) { imagen = gcnew Bitmap("paisajeSM1(noche).jpg"); }
		if (tiem >= 4 && tiem << 6) { imagen = gcnew Bitmap("paisajeSM1(-noche).jpg"); }
		if (tiem >= 6 && tiem << 18) { imagen = gcnew Bitmap("paisajeSM1.jpg"); }
		if (tiem >= 18 && tiem << 20) { imagen = gcnew Bitmap("paisajeSM1(-noche).jpg"); }
		if (tiem >= 20 && tiem << 22) { imagen = gcnew Bitmap("paisajeSM1(noche).jpg"); }
		if (tiem >= 22 && tiem << 24) { imagen = gcnew Bitmap("paisajeSM1(+noche).jpg"); }

	}
	void cambioSM(Int16 tiem) {

		if (tiem >= 0 && tiem << 2) { imagen = gcnew Bitmap("paisajeSM4(+noche).jpg"); }
		if (tiem >= 2 && tiem << 4) { imagen = gcnew Bitmap("paisajeSM4(noche).jpg"); }
		if (tiem >= 4 && tiem << 6) { imagen = gcnew Bitmap("paisajeSM4(-noche).jpg"); }
		if (tiem >= 6 && tiem << 18) { imagen = gcnew Bitmap("paisajeSM4.jpg"); }
		if (tiem >= 18 && tiem << 20) { imagen = gcnew Bitmap("paisajeSM4(-noche).jpg"); }
		if (tiem >= 20 && tiem << 22) { imagen = gcnew Bitmap("paisajeSM4(noche).jpg"); }
		if (tiem >= 22 && tiem << 24) { imagen = gcnew Bitmap("paisajeSM4(+noche).jpg"); }

	}
	Void Disparar() {}


};