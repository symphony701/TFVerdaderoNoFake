#pragma once
#include "Control2.h"
#include <iostream>
namespace Project8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Resumen de Map2
	/// </summary>
	public ref class Map2 : public System::Windows::Forms::Form
	{
		CControl2^ juego;
		bool Muerte;
	private: System::Windows::Forms::Label^  lbl_dinero;
	private: System::Windows::Forms::Label^  lbl_puntaje;
			 Graphics^g;
	public:
		Map2(Int16 vi, bool dispa, int toqueco, int toquefin, int dinero,int punta,int hora, int min)
		{
			InitializeComponent();
			g = panel1->CreateGraphics();
			juego = gcnew CControl2(vi, dispa,toqueco,toquefin, dinero,punta,lbl_puntaje,lbl_dinero,hora,min);
		}
	private: System::Windows::Forms::Label^  lbl_hora;
	public:
	private: System::Windows::Forms::Timer^  timer1;
	public:

	protected:
		
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Map2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:


	private:
	


	private: System::ComponentModel::IContainer^  components;
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
			this->lbl_puntaje = (gcnew System::Windows::Forms::Label());
			this->lbl_dinero = (gcnew System::Windows::Forms::Label());
			this->lbl_hora = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->lbl_puntaje);
			this->panel1->Controls->Add(this->lbl_dinero);
			this->panel1->Controls->Add(this->lbl_hora);
			this->panel1->Location = System::Drawing::Point(1, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(765, 627);
			this->panel1->TabIndex = 0;
			this->panel1->Click += gcnew System::EventHandler(this, &Map2::panel1_Click);
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Map2::panel1_Paint);
			this->panel1->DoubleClick += gcnew System::EventHandler(this, &Map2::panel1_DoubleClick);
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Map2::panel1_MouseClick);
			// 
			// lbl_puntaje
			// 
			this->lbl_puntaje->BackColor = System::Drawing::Color::Black;
			this->lbl_puntaje->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lbl_puntaje->Font = (gcnew System::Drawing::Font(L"Impact", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_puntaje->ForeColor = System::Drawing::Color::White;
			this->lbl_puntaje->Location = System::Drawing::Point(437, 8);
			this->lbl_puntaje->Name = L"lbl_puntaje";
			this->lbl_puntaje->Size = System::Drawing::Size(61, 35);
			this->lbl_puntaje->TabIndex = 4;
			this->lbl_puntaje->Text = L"0p";
			this->lbl_puntaje->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// lbl_dinero
			// 
			this->lbl_dinero->BackColor = System::Drawing::Color::Black;
			this->lbl_dinero->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lbl_dinero->Font = (gcnew System::Drawing::Font(L"Impact", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_dinero->ForeColor = System::Drawing::Color::White;
			this->lbl_dinero->Location = System::Drawing::Point(557, 8);
			this->lbl_dinero->Name = L"lbl_dinero";
			this->lbl_dinero->Size = System::Drawing::Size(61, 35);
			this->lbl_dinero->TabIndex = 3;
			this->lbl_dinero->Text = L"$100";
			this->lbl_dinero->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbl_hora
			// 
			this->lbl_hora->BackColor = System::Drawing::Color::Black;
			this->lbl_hora->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lbl_hora->Font = (gcnew System::Drawing::Font(L"Impact", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_hora->ForeColor = System::Drawing::Color::White;
			this->lbl_hora->Location = System::Drawing::Point(694, 8);
			this->lbl_hora->Name = L"lbl_hora";
			this->lbl_hora->Size = System::Drawing::Size(61, 35);
			this->lbl_hora->TabIndex = 2;
			this->lbl_hora->Text = L" 6:00";
			this->lbl_hora->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Map2::timer1_Tick);
			// 
			// Map2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(769, 631);
			this->Controls->Add(this->panel1);
			this->Name = L"Map2";
			this->Text = L"Map2";
			this->Load += gcnew System::EventHandler(this, &Map2::Map2_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Map2::Map2_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Map2::Map2_KeyUp);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	
		BufferedGraphicsContext ^bfc = BufferedGraphicsManager::Current;
		BufferedGraphics ^bf = bfc->Allocate(g, this->ClientRectangle);
		/////INICIO DE CODIGO


		Muerte = juego->cadaTick(lbl_puntaje, bf->Graphics, lbl_dinero, lbl_hora);
		///////FIN DE CODIGO
		bf->Render(g);
		delete bf, bfc;
		if (Muerte == true) {
			timer1->Enabled = false;
			Close();
		}
	
	}
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}
	private: System::Void panel1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void panel1_DoubleClick(System::Object^  sender, System::EventArgs^  e) {

	}
private: System::Void Map2_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

	juego->keyDown(e);

}
private: System::Void Map2_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	
	juego->keyUp(e);
}
private: System::Void Map2_Load(System::Object^  sender, System::EventArgs^  e) {
}
		 public:
			 int devolverVidas() { return juego->retornarVidas(); }
			 int devolverDinero() { return juego->retornarDinero(); }
			 int devolverPuntaje() { return juego->returnPuntaje(); }
			 int devolverHora() { return juego->retornarHora(); }
			 int devolverMinutos() { return juego->retornarMinutos(); }
			 int tipoMuerte() { return juego->Tipomuerte(); }
			 bool Dead() { return Muerte; }
private: System::Void panel1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	cout << e->X << "---" << e->Y << endl;
}
};
}
