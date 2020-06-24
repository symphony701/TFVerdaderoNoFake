#pragma once
#include "Entidad.h"
#include "Jugador.h"
#include "Policia.h"
#include "Ambulancia.h"
#include "mapas.h"
#include "Tiempo.h"
#include "Personas.h"
#include <iostream>
#include "Arremensajes.h"
namespace Project8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	/// <summary>
	/// Resumen de map3
	/// </summary>
	public ref class map3 : public System::Windows::Forms::Form
	{
	private:
		CJugador^ jugador;
		CPolicia^poli;
		CAmbulancia ^ambulancia;
		CAmbulancia^ambulancia2;
		CMapas^ mapa;
		bool activo;
		SoundPlayer^ st;
		tiempo^ tiem;
		CPersonas ^ personas;
		CPolicia ^poli2;
		int dia;
		bool actPoli;


	private: System::Windows::Forms::Timer^  timer1;
			 Graphics^g;
	public:
		map3(void)
		{
			InitializeComponent();
			g = panel1->CreateGraphics();
			mapa = gcnew CMapas(2);
			jugador = gcnew CJugador();
			dia = 0;
			g = panel1->CreateGraphics();
			tiem = gcnew tiempo();
			jugador = gcnew CJugador();
			st = gcnew SoundPlayer("soundtrackTono.wav");
			personas = gcnew CPersonas(2);
			poli = gcnew CPolicia(2,1);
			poli2 = gcnew CPolicia(2,2);
			ambulancia = gcnew CAmbulancia(2,1);
			ambulancia2 = gcnew CAmbulancia(2, 2);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~map3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:
	private: System::Windows::Forms::Label^  lbl_hora;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->lbl_hora = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->lbl_hora);
			this->panel1->Location = System::Drawing::Point(2, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(765, 627);
			this->panel1->TabIndex = 1;
			// 
			// lbl_hora
			// 
			this->lbl_hora->BackColor = System::Drawing::Color::Black;
			this->lbl_hora->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lbl_hora->Font = (gcnew System::Drawing::Font(L"Impact", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_hora->ForeColor = System::Drawing::Color::White;
			this->lbl_hora->Location = System::Drawing::Point(694, 7);
			this->lbl_hora->Name = L"lbl_hora";
			this->lbl_hora->Size = System::Drawing::Size(61, 35);
			this->lbl_hora->TabIndex = 2;
			this->lbl_hora->Text = L" 6:00";
			this->lbl_hora->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &map3::timer1_Tick);
			// 
			// map3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(769, 631);
			this->Controls->Add(this->panel1);
			this->Name = L"map3";
			this->Text = L"map3";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &map3::map3_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &map3::map3_KeyUp);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		BufferedGraphicsContext ^bfc = BufferedGraphicsManager::Current;
		BufferedGraphics ^bf = bfc->Allocate(g, this->ClientRectangle);
		/////INICIO DE CODIGO


		//if (tiem->gethora() == 6 && tiem->getmin() == 00 && actPoli)
		//{
		//	ambulancia = gcnew CAmbulancia(1, 1);
		//	ambulancia2 = gcnew CAmbulancia(1, 2);

		//	actPoli = false;
		//}
		//if (tiem->gethora() == 6 && tiem->getmin() == 00 && !actPoli)
		//{
		//	ambulancia = gcnew CAmbulancia(2, 1);
		//	delete poli, poli2;
		//}
		//if (tiem->gethora() == 20 && tiem->getmin() == 00)
		//{
		//	delete ambulancia;
		//	poli = gcnew CPolicia(2, 1);
		//	poli2 = gcnew CPolicia(1, 2);
		//}
		bf->Graphics->DrawImage(mapa->getImagen(), 0, 0, mapa->getRectangle(), GraphicsUnit::Pixel);
		jugador->Mostrar(bf->Graphics, activo);


		personas->Mostrar(bf->Graphics);
		personas->Mover();
		//if (tiem->gethora() >= 6 && tiem->gethora() <= 20)
		//{
			ambulancia->Mostrar(bf->Graphics);
			ambulancia->desplazamiento();
			personas->AtrapadoAmbu(ambulancia->getRectangle());

		//}
		//if ((tiem->gethora() >= 20 && tiem->gethora() <= 23) || (tiem->gethora() < 6 && tiem->gethora() >= 0)) {

		poli->Mostrar(bf->Graphics);
		poli->desplazamiento();
		poli2->Mostrar(bf->Graphics);
		poli2->desplazamiento();
		personas->AtrapadoPoli(poli->getRectangle());
		personas->AtrapadoPoli(poli2->getRectangle());
		//}
		///////FIN DE CODIGO
		bf->Render(g);
		delete bf, bfc;
		tiem->cambio(1);
		mapa->cambio(tiem->gethora());
	}
private: System::Void map3_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	activo = true;
	if (e->KeyCode == Keys::Up) {
		jugador->Mover4(Direccion::Arriba);
	}
	else if (e->KeyCode == Keys::Down) {
		jugador->Mover4(Direccion::Abajo);
	}
	else if (e->KeyCode == Keys::Left) {
		jugador->Mover4(Direccion::Izquierda);

	}
	else if (e->KeyCode == Keys::Right) {
		jugador->Mover4(Direccion::Derecha);
	}

}
private: System::Void map3_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::Up) {
		activo = false;
	}
	else if (e->KeyCode == Keys::Down) {
		activo = false;
	}
	else if (e->KeyCode == Keys::Left) {
		activo = false;

	}
	else if (e->KeyCode == Keys::Right) {
		activo = false;
	}
	else if (e->KeyCode == Keys::W) {

		//mensajuga->Disparar(jugador->getPosX(), jugador->getPosY(), jugador->getY(), jugador->getancho(), jugador->getalto());
	}
}
};
}
