#pragma once
#include "Vidas.h"
#include "Persona.h"
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
	public ref class Dificultad : public System::Windows::Forms::Form
	{
		Cvidas^ vidasj;
		CPersona^ perso;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
			 Graphics^ g;
	public:
		Dificultad(void)
		{
			InitializeComponent();
			vidasj = gcnew Cvidas();
			g = panel1->CreateGraphics();
			perso = gcnew CPersona();
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
	private: System::Windows::Forms::Button^  btn_facil;
	private: System::Windows::Forms::Button^  btn_medio;
	private: System::Windows::Forms::Button^  btn_dificil;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	protected:




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
			this->btn_dificil = (gcnew System::Windows::Forms::Button());
			this->btn_facil = (gcnew System::Windows::Forms::Button());
			this->btn_medio = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Black;
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->btn_dificil);
			this->panel1->Controls->Add(this->btn_facil);
			this->panel1->Controls->Add(this->btn_medio);
			this->panel1->ForeColor = System::Drawing::Color::Black;
			this->panel1->Location = System::Drawing::Point(6, 8);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(757, 404);
			this->panel1->TabIndex = 2;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Dificultad::panel1_Paint);
			// 
			// btn_dificil
			// 
			this->btn_dificil->BackColor = System::Drawing::Color::Black;
			this->btn_dificil->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 36, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btn_dificil->ForeColor = System::Drawing::Color::White;
			this->btn_dificil->Location = System::Drawing::Point(524, 234);
			this->btn_dificil->Name = L"btn_dificil";
			this->btn_dificil->Size = System::Drawing::Size(160, 83);
			this->btn_dificil->TabIndex = 2;
			this->btn_dificil->Text = L"Dificil";
			this->btn_dificil->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_dificil->UseVisualStyleBackColor = false;
			this->btn_dificil->Click += gcnew System::EventHandler(this, &Dificultad::btn_dificil_Click);
			// 
			// btn_facil
			// 
			this->btn_facil->BackColor = System::Drawing::Color::Black;
			this->btn_facil->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_facil->ForeColor = System::Drawing::Color::White;
			this->btn_facil->Location = System::Drawing::Point(80, 234);
			this->btn_facil->Name = L"btn_facil";
			this->btn_facil->Size = System::Drawing::Size(160, 83);
			this->btn_facil->TabIndex = 0;
			this->btn_facil->Text = L"Facil  ";
			this->btn_facil->UseVisualStyleBackColor = false;
			this->btn_facil->Click += gcnew System::EventHandler(this, &Dificultad::btn_facil_Click);
			// 
			// btn_medio
			// 
			this->btn_medio->BackColor = System::Drawing::Color::Black;
			this->btn_medio->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 36, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btn_medio->ForeColor = System::Drawing::Color::White;
			this->btn_medio->Location = System::Drawing::Point(314, 234);
			this->btn_medio->Name = L"btn_medio";
			this->btn_medio->Size = System::Drawing::Size(160, 83);
			this->btn_medio->TabIndex = 1;
			this->btn_medio->Text = L"Medio";
			this->btn_medio->UseVisualStyleBackColor = false;
			this->btn_medio->Click += gcnew System::EventHandler(this, &Dificultad::btn_medio_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Dificultad::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(103, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(107, 22);
			this->label1->TabIndex = 3;
			this->label1->Text = L"22:00 a 4:00 ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(335, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(107, 22);
			this->label2->TabIndex = 4;
			this->label2->Text = L"20:00 a 6:00 ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(549, 60);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(107, 22);
			this->label3->TabIndex = 5;
			this->label3->Text = L"20:00 a 6:00 ";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(93, 31);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(128, 22);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Toque de queda";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(324, 31);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(128, 22);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Toque de queda";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(534, 31);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(128, 22);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Toque de queda";
			// 
			// Dificultad
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(769, 430);
			this->Controls->Add(this->panel1);
			this->Name = L"Dificultad";
			this->Text = L"Dificultad";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

	}
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	BufferedGraphicsContext ^bfc = BufferedGraphicsManager::Current;
	BufferedGraphics ^bf = bfc->Allocate(g, this->ClientRectangle);
	bf->Graphics->FillRectangle(Brushes::Black, 0, 0, 757, 404);
	vidasj->cambioppos(90, 200);
	vidasj->setcantvida(5);
	vidasj->Cantivi(bf->Graphics);
	vidasj->cambioppos(350, 200);
	vidasj->setcantvida(3);
	vidasj->Cantivi(bf->Graphics);
	vidasj->cambioppos(570, 200);
	vidasj->setcantvida(3);
	vidasj->Cantivi(bf->Graphics);

	bf->Render(g);
	delete bf, bfc;
}
private: System::Void btn_facil_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void btn_medio_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void btn_dificil_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
