#pragma once
#include "Vidas.h"
#include "Persona.h"
#include "PaginaInicio.h"
#include <iostream>
#include "Map2.h"
#include "map3.h"
namespace Project8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Dificultad
	/// </summary>
	public ref class Dificultad : public System::Windows::Forms::Form{
	Graphics^ g;
	Cvidas^ cantvidas;
	CPersona^ persona1;
	CPersona^ persona2;
	CPersona^ persona3;
	Int16 valdis;
public:
	Dificultad(void)
	{
		InitializeComponent();
		g = panel1->CreateGraphics();
		cantvidas = gcnew Cvidas(5);
		persona1 = gcnew CPersona();
		persona1->Ubicacion(70, 120);
		persona2 = gcnew CPersona();
		persona2->Ubicacion(280, 120);
		persona3 = gcnew CPersona();
		persona3->Ubicacion(550, 120);
		valdis = 1;

		//
		//TODO: agregar código de constructor aquí
		//
	}

protected:
	/// <summary>
	/// Limpiar los recursos que se estén usando.
	/// </summary>
	~Dificultad()
	{
		if (components)
		{
			delete components;
		}
	}
private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  btn_dificil;
	protected:

	private: System::Windows::Forms::Button^  btn_facil;

private: System::Windows::Forms::NumericUpDown^  nud_ter;


private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::NumericUpDown^  nud_comi;


private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::NumericUpDown^  nud_vidas;
	private: System::Windows::Forms::Button^  btn_condis;



	private: System::Windows::Forms::Button^  btn_sindis;
	private: System::Windows::Forms::Button^  btn_creativo;


private: System::Windows::Forms::Timer^  timer1;
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
		this->nud_ter = (gcnew System::Windows::Forms::NumericUpDown());
		this->label7 = (gcnew System::Windows::Forms::Label());
		this->nud_comi = (gcnew System::Windows::Forms::NumericUpDown());
		this->label6 = (gcnew System::Windows::Forms::Label());
		this->label5 = (gcnew System::Windows::Forms::Label());
		this->label4 = (gcnew System::Windows::Forms::Label());
		this->label3 = (gcnew System::Windows::Forms::Label());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->nud_vidas = (gcnew System::Windows::Forms::NumericUpDown());
		this->btn_condis = (gcnew System::Windows::Forms::Button());
		this->btn_sindis = (gcnew System::Windows::Forms::Button());
		this->btn_creativo = (gcnew System::Windows::Forms::Button());
		this->btn_dificil = (gcnew System::Windows::Forms::Button());
		this->btn_facil = (gcnew System::Windows::Forms::Button());
		this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
		this->panel1->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_ter))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_comi))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_vidas))->BeginInit();
		this->SuspendLayout();
		// 
		// panel1
		// 
		this->panel1->BackColor = System::Drawing::Color::Black;
		this->panel1->Controls->Add(this->nud_ter);
		this->panel1->Controls->Add(this->label7);
		this->panel1->Controls->Add(this->nud_comi);
		this->panel1->Controls->Add(this->label6);
		this->panel1->Controls->Add(this->label5);
		this->panel1->Controls->Add(this->label4);
		this->panel1->Controls->Add(this->label3);
		this->panel1->Controls->Add(this->label2);
		this->panel1->Controls->Add(this->label1);
		this->panel1->Controls->Add(this->nud_vidas);
		this->panel1->Controls->Add(this->btn_condis);
		this->panel1->Controls->Add(this->btn_sindis);
		this->panel1->Controls->Add(this->btn_creativo);
		this->panel1->Controls->Add(this->btn_dificil);
		this->panel1->Controls->Add(this->btn_facil);
		this->panel1->Location = System::Drawing::Point(4, 8);
		this->panel1->Name = L"panel1";
		this->panel1->Size = System::Drawing::Size(757, 404);
		this->panel1->TabIndex = 2;
		// 
		// nud_ter
		// 
		this->nud_ter->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->nud_ter->Location = System::Drawing::Point(642, 41);
		this->nud_ter->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
		this->nud_ter->Name = L"nud_ter";
		this->nud_ter->Size = System::Drawing::Size(41, 32);
		this->nud_ter->TabIndex = 14;
		// 
		// label7
		// 
		this->label7->AutoSize = true;
		this->label7->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label7->ForeColor = System::Drawing::Color::White;
		this->label7->Location = System::Drawing::Point(680, 43);
		this->label7->Name = L"label7";
		this->label7->Size = System::Drawing::Size(42, 28);
		this->label7->TabIndex = 16;
		this->label7->Text = L":00";
		// 
		// nud_comi
		// 
		this->nud_comi->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->nud_comi->Location = System::Drawing::Point(546, 41);
		this->nud_comi->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 24, 0, 0, 0 });
		this->nud_comi->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 18, 0, 0, 0 });
		this->nud_comi->Name = L"nud_comi";
		this->nud_comi->Size = System::Drawing::Size(41, 32);
		this->nud_comi->TabIndex = 13;
		this->nud_comi->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 18, 0, 0, 0 });
		// 
		// label6
		// 
		this->label6->AutoSize = true;
		this->label6->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label6->ForeColor = System::Drawing::Color::White;
		this->label6->Location = System::Drawing::Point(582, 43);
		this->label6->Name = L"label6";
		this->label6->Size = System::Drawing::Size(60, 28);
		this->label6->TabIndex = 15;
		this->label6->Text = L":00 a";
		// 
		// label5
		// 
		this->label5->AutoSize = true;
		this->label5->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label5->ForeColor = System::Drawing::Color::White;
		this->label5->Location = System::Drawing::Point(312, 45);
		this->label5->Name = L"label5";
		this->label5->Size = System::Drawing::Size(132, 28);
		this->label5->TabIndex = 12;
		this->label5->Text = L"20:00 a 6:00";
		// 
		// label4
		// 
		this->label4->AutoSize = true;
		this->label4->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label4->ForeColor = System::Drawing::Color::White;
		this->label4->Location = System::Drawing::Point(67, 45);
		this->label4->Name = L"label4";
		this->label4->Size = System::Drawing::Size(132, 28);
		this->label4->TabIndex = 11;
		this->label4->Text = L"22:00 a 4:00";
		// 
		// label3
		// 
		this->label3->AutoSize = true;
		this->label3->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label3->ForeColor = System::Drawing::Color::White;
		this->label3->Location = System::Drawing::Point(554, 10);
		this->label3->Name = L"label3";
		this->label3->Size = System::Drawing::Size(152, 28);
		this->label3->TabIndex = 10;
		this->label3->Text = L"Hora de queda";
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label2->ForeColor = System::Drawing::Color::White;
		this->label2->Location = System::Drawing::Point(302, 10);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(152, 28);
		this->label2->TabIndex = 9;
		this->label2->Text = L"Hora de queda";
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->label1->ForeColor = System::Drawing::Color::White;
		this->label1->Location = System::Drawing::Point(60, 10);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(152, 28);
		this->label1->TabIndex = 8;
		this->label1->Text = L"Hora de queda";
		// 
		// nud_vidas
		// 
		this->nud_vidas->Location = System::Drawing::Point(573, 263);
		this->nud_vidas->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 8, 0, 0, 0 });
		this->nud_vidas->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
		this->nud_vidas->Name = L"nud_vidas";
		this->nud_vidas->Size = System::Drawing::Size(120, 20);
		this->nud_vidas->TabIndex = 7;
		this->nud_vidas->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		this->nud_vidas->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
		// 
		// btn_condis
		// 
		this->btn_condis->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->btn_condis->ForeColor = System::Drawing::Color::White;
		this->btn_condis->Location = System::Drawing::Point(636, 195);
		this->btn_condis->Name = L"btn_condis";
		this->btn_condis->Size = System::Drawing::Size(91, 32);
		this->btn_condis->TabIndex = 6;
		this->btn_condis->Text = L"con disparo";
		this->btn_condis->UseVisualStyleBackColor = true;
		this->btn_condis->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Dificultad::btn_condis_MouseClick);
		// 
		// btn_sindis
		// 
		this->btn_sindis->BackColor = System::Drawing::Color::Red;
		this->btn_sindis->Enabled = false;
		this->btn_sindis->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->btn_sindis->ForeColor = System::Drawing::Color::White;
		this->btn_sindis->Location = System::Drawing::Point(530, 195);
		this->btn_sindis->Name = L"btn_sindis";
		this->btn_sindis->Size = System::Drawing::Size(91, 32);
		this->btn_sindis->TabIndex = 5;
		this->btn_sindis->Text = L"sin disparo";
		this->btn_sindis->UseVisualStyleBackColor = false;
		this->btn_sindis->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Dificultad::btn_sindis_MouseClick);
		// 
		// btn_creativo
		// 
		this->btn_creativo->BackColor = System::Drawing::Color::Black;
		this->btn_creativo->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->btn_creativo->ForeColor = System::Drawing::Color::White;
		this->btn_creativo->Location = System::Drawing::Point(538, 289);
		this->btn_creativo->Name = L"btn_creativo";
		this->btn_creativo->Size = System::Drawing::Size(187, 83);
		this->btn_creativo->TabIndex = 2;
		this->btn_creativo->Text = L"Creativo";
		this->btn_creativo->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		this->btn_creativo->UseVisualStyleBackColor = false;
		this->btn_creativo->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Dificultad::btn_creativo_MouseClick);
		// 
		// btn_dificil
		// 
		this->btn_dificil->BackColor = System::Drawing::Color::Black;
		this->btn_dificil->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		this->btn_dificil->ForeColor = System::Drawing::Color::White;
		this->btn_dificil->Location = System::Drawing::Point(313, 289);
		this->btn_dificil->Name = L"btn_dificil";
		this->btn_dificil->Size = System::Drawing::Size(141, 83);
		this->btn_dificil->TabIndex = 0;
		this->btn_dificil->Text = L"Dificil";
		this->btn_dificil->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		this->btn_dificil->UseVisualStyleBackColor = false;
		this->btn_dificil->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Dificultad::btn_dificil_MouseClick);
		// 
		// btn_facil
		// 
		this->btn_facil->BackColor = System::Drawing::Color::Black;
		this->btn_facil->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 36, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
			System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
		this->btn_facil->ForeColor = System::Drawing::Color::White;
		this->btn_facil->Location = System::Drawing::Point(68, 289);
		this->btn_facil->Name = L"btn_facil";
		this->btn_facil->Size = System::Drawing::Size(141, 83);
		this->btn_facil->TabIndex = 1;
		this->btn_facil->Text = L"Facil";
		this->btn_facil->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		this->btn_facil->UseVisualStyleBackColor = false;
		this->btn_facil->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Dificultad::btn_facil_MouseClick);
		// 
		// timer1
		// 
		this->timer1->Enabled = true;
		this->timer1->Tick += gcnew System::EventHandler(this, &Dificultad::timer1_Tick);
		// 
		// Dificultad
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::Black;
		this->ClientSize = System::Drawing::Size(769, 430);
		this->Controls->Add(this->panel1);
		this->Name = L"Dificultad";
		this->Text = L"dificultad";
		this->panel1->ResumeLayout(false);
		this->panel1->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_ter))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_comi))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_vidas))->EndInit();
		this->ResumeLayout(false);

	}
#pragma endregion
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	Int16 a = Int16(nud_vidas->Value);
	BufferedGraphicsContext ^bfc = BufferedGraphicsManager::Current;
	BufferedGraphics ^bf = bfc->Allocate(g, this->ClientRectangle);
	bf->Graphics->FillRectangle(Brushes::Black, 0, 0, 757, 404);

	cantvidas->setcantvida(5);
	cantvidas->cambioppos(70, 240);
	cantvidas->Cantivi(bf->Graphics);

	persona1->Mostrar(bf->Graphics);
	persona1->desplazamiento();
	if (160 <= persona1->getPosX()) {
		persona1->Ubicacion(70, 120);
		persona1->CambioPersona();
	}


	cantvidas->setcantvida(3);
	cantvidas->cambioppos(340, 240);
	cantvidas->Cantivi(bf->Graphics);
	
	persona2->Mostrar(bf->Graphics);
	persona2->desplazamiento();
	if (350 <= persona2->getPosX()) {
		persona2->Ubicacion(280, 120);
		persona2->CambioPersona();
	}
	persona2->Diasparar();
	persona2->verBala(bf->Graphics);


	cantvidas->setcantvida(a);
	cantvidas->cambioppos(635 - a * 15, 240);
	cantvidas->Cantivi(bf->Graphics);
	
	if (valdis == 1) {
		persona3->Mostrar(bf->Graphics);
		persona3->desplazamiento();
		if (640 <= persona3->getPosX()) {
			persona3->Ubicacion(550, 120);
			persona3->CambioPersona();
		}
	}
	if (valdis == 2) {
		persona3->Mostrar(bf->Graphics);
		persona3->desplazamiento();
		if (600 <= persona3->getPosX()) {
			persona3->Ubicacion(530, 120);
			persona3->CambioPersona();
		}
		persona3->Diasparar();
		persona3->verBala(bf->Graphics);
	}
	bf->Render(g);
	delete bf, bfc;
}

private: System::Void btn_sindis_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btn_sindis->Enabled = false;
	btn_condis->Enabled = true;
	btn_sindis->BackColor = System::Drawing::Color::Red;
	btn_condis->BackColor = System::Drawing::Color::Black;
	valdis = 1;
}
private: System::Void btn_condis_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	btn_sindis->Enabled = true;
	btn_condis->Enabled = false;
	btn_condis->BackColor = System::Drawing::Color::Red;
	btn_sindis->BackColor = System::Drawing::Color::Black;
	valdis = 2;
}

private: System::Void btn_facil_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	MyForm^map1 = gcnew MyForm(5);
	WindowState = FormWindowState::Minimized;
	map1->ShowDialog();
	WindowState = FormWindowState::Normal;
	delete map1;
	Map2^map2 = gcnew Map2(5);
	WindowState = FormWindowState::Minimized;
	map2->ShowDialog();
	WindowState = FormWindowState::Normal;
	delete map2;
	map3^Map3 = gcnew map3(5);
	WindowState = FormWindowState::Minimized;
	Map3->ShowDialog();
	WindowState = FormWindowState::Normal;
	delete Map3;
	MessageBox::Show("Gracias por jugar!!");
}
private: System::Void btn_dificil_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
}
private: System::Void btn_creativo_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
}
};
}
