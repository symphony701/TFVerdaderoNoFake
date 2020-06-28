#pragma once

namespace Project8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Pantallafinal
	/// </summary>
	public ref class Pantallafinal : public System::Windows::Forms::Form
	{
		bool Dead;
		Int16 tipodead;
	private: System::Windows::Forms::Label^  label4;
			 Int16 puntaje;
	public:
		Pantallafinal(bool muerte, Int16 Tipo, Int16 punta, Int16 dinero ){
			Dead = muerte;
			tipodead = Tipo;
			puntaje = punta + dinero;
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Pantallafinal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;


	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 24, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Lime;
			this->label1->Location = System::Drawing::Point(89, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 38);
			this->label1->TabIndex = 0;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 24, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Lime;
			this->label2->Location = System::Drawing::Point(31, 113);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(111, 38);
			this->label2->TabIndex = 1;
			this->label2->Text = L"puntaje";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 24, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Lime;
			this->label3->Location = System::Drawing::Point(265, 113);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 38);
			this->label3->TabIndex = 2;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Pantallafinal::timer1_Tick);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 24, System::Drawing::FontStyle::Italic));
			this->label4->Location = System::Drawing::Point(89, 63);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 38);
			this->label4->TabIndex = 3;
			// 
			// Pantallafinal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(393, 188);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::Color::Transparent;
			this->Name = L"Pantallafinal";
			this->Text = L"Pantallafinal";
			this->TransparencyKey = System::Drawing::Color::Transparent;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (Dead == true) {
			if (tipodead == 1) {
				label1->Text ="Perdiste";
				this->label1->ForeColor = System::Drawing::Color::Red;
			}
			if (tipodead == 2) {
				label1->Text = "No te quedes fuera ";
				this->label1->ForeColor = System::Drawing::Color::Red;
				label4->Text = "del toque de queda";
				this->label4->ForeColor = System::Drawing::Color::Red;
			}
			if (tipodead == 3) {
				label1->Text = "No te puedes quedarte";
				this->label1->ForeColor = System::Drawing::Color::Red;
				label4->Text = "con deudas";
				this->label4->ForeColor = System::Drawing::Color::Red;
			}
		}
		if (Dead == false) {
			label1->Text = "Gracias por jugar!!";
			this->label1->ForeColor = System::Drawing::Color::White;
		}
		label3->Text = puntaje + "";
	}
};
}
