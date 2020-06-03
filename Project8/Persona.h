#pragma once
#include "Entidad.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class CPersona : public CEntidad {
protected:
	bool virus;
public:
	CPersona(){}
	~CPersona(){}
};