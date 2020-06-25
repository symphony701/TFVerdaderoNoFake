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
	/// Resumen de dificultad
	/// </summary>
	public ref class dificultad : public System::Windows::Forms::Form{
		Graphics^ g;
		Cvidas^ cantvidas;
		CPersona^ persona;
	public:
		dificultad(void)
		{
			InitializeComponent();
			g = panel1->CreateGraphics();
			cantvidas = gcnew Cvidas();
			persona = gcnew CPersona();

			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~dificultad()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:
	private: System::Windows::Forms::Button^  btnstart;
	private: System::Windows::Forms::Button^  btnexit;
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


	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
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
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btnstart = (gcnew System::Windows::Forms::Button());
			this->btnexit = (gcnew System::Windows::Forms::Button());
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
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->btnstart);
			this->panel1->Controls->Add(this->btnexit);
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
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(643, 202);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 6;
			this->button3->Text = L"con disparo";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(542, 202);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"sin disparo";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Black;
			this->button1->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(538, 289);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(187, 83);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Creativo";
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->UseVisualStyleBackColor = false;
			// 
			// btnstart
			// 
			this->btnstart->BackColor = System::Drawing::Color::Black;
			this->btnstart->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnstart->ForeColor = System::Drawing::Color::White;
			this->btnstart->Location = System::Drawing::Point(313, 289);
			this->btnstart->Name = L"btnstart";
			this->btnstart->Size = System::Drawing::Size(141, 83);
			this->btnstart->TabIndex = 0;
			this->btnstart->Text = L"Dificil";
			this->btnstart->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnstart->UseVisualStyleBackColor = false;
			// 
			// btnexit
			// 
			this->btnexit->BackColor = System::Drawing::Color::Black;
			this->btnexit->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 36, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnexit->ForeColor = System::Drawing::Color::White;
			this->btnexit->Location = System::Drawing::Point(68, 289);
			this->btnexit->Name = L"btnexit";
			this->btnexit->Size = System::Drawing::Size(141, 83);
			this->btnexit->TabIndex = 1;
			this->btnexit->Text = L"Facil";
			this->btnexit->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnexit->UseVisualStyleBackColor = false;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &dificultad::timer1_Tick);
			// 
			// dificultad
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(769, 430);
			this->Controls->Add(this->panel1);
			this->Name = L"dificultad";
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




		cantvidas->setcantvida(3);
		cantvidas->cambioppos(340, 240);
		cantvidas->Cantivi(bf->Graphics);



		cantvidas->setcantvida(a);
		cantvidas->cambioppos(635-a*15, 240);
		cantvidas->Cantivi(bf->Graphics);




		bf->Render(g);
		delete bf, bfc;
	}
};
}
