#pragma once
#include <iostream>
#include "Control3.h"
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
		CControl3^ juego;

	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  lbl_puntaje;
	private: System::Windows::Forms::Label^  lbl_dinero;
			 Graphics^g;
	public:
		map3(Int16 vi, bool dispaene,int dinero,int punta)
		{
			InitializeComponent();
			g = panel1->CreateGraphics();
			juego = gcnew CControl3(vi,dispaene,dinero,punta);
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
			this->lbl_dinero = (gcnew System::Windows::Forms::Label());
			this->lbl_puntaje = (gcnew System::Windows::Forms::Label());
			this->lbl_hora = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->lbl_dinero);
			this->panel1->Controls->Add(this->lbl_puntaje);
			this->panel1->Controls->Add(this->lbl_hora);
			this->panel1->Location = System::Drawing::Point(1, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(765, 627);
			this->panel1->TabIndex = 1;
			// 
			// lbl_dinero
			// 
			this->lbl_dinero->BackColor = System::Drawing::Color::Black;
			this->lbl_dinero->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lbl_dinero->Font = (gcnew System::Drawing::Font(L"Impact", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_dinero->ForeColor = System::Drawing::Color::White;
			this->lbl_dinero->Location = System::Drawing::Point(542, 7);
			this->lbl_dinero->Name = L"lbl_dinero";
			this->lbl_dinero->Size = System::Drawing::Size(61, 35);
			this->lbl_dinero->TabIndex = 6;
			this->lbl_dinero->Text = L"$100";
			this->lbl_dinero->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbl_puntaje
			// 
			this->lbl_puntaje->BackColor = System::Drawing::Color::Black;
			this->lbl_puntaje->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lbl_puntaje->Font = (gcnew System::Drawing::Font(L"Impact", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_puntaje->ForeColor = System::Drawing::Color::White;
			this->lbl_puntaje->Location = System::Drawing::Point(335, 7);
			this->lbl_puntaje->Name = L"lbl_puntaje";
			this->lbl_puntaje->Size = System::Drawing::Size(61, 35);
			this->lbl_puntaje->TabIndex = 5;
			this->lbl_puntaje->Text = L"0p";
			this->lbl_puntaje->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
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
			this->Load += gcnew System::EventHandler(this, &map3::map3_Load);
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
		juego->cadaTick(lbl_puntaje, bf->Graphics, lbl_dinero, lbl_hora);
		///////FIN DE CODIGO
		bf->Render(g);
		if (juego->getContadorRecomendaciones()>12)
		{
			Close();
		}
		delete bf, bfc;
	}
private: System::Void map3_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	juego->keyDown(e);
}
private: System::Void map3_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	juego->keyUp(e);
}
private: System::Void map3_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}
