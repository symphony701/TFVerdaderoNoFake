#pragma once
#include "Entidad.h"
namespace Project8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();

			g=panelito->CreateGraphics();
			personaje = gcnew CEntidad();
			//g->DrawImage(personaje->getImagen(), 0, 0, personaje->getRectangle(), GraphicsUnit::Pixel);
			
		
		};

	protected:	
		Graphics^g;
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panelito;
	protected:

	protected:

	protected:

	protected:

	private:
		CEntidad^ personaje;
	
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panelito = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// panelito
			// 
			this->panelito->Location = System::Drawing::Point(1, 1);
			this->panelito->Name = L"panelito";
			this->panelito->Size = System::Drawing::Size(768, 631);
			this->panelito->TabIndex = 0;
			this->panelito->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panelito_Paint);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(769, 631);
			this->Controls->Add(this->panelito);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		//g->DrawRectangle(gcnew Pen(Color::Blue, 4), 0, 0, 20, 20);
		//g->DrawImage(personaje->getImagen(), 0, 0, personaje->getRectangle(),GraphicsUnit::Pixel);
	}
	private: System::Void panelito_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		g->DrawImage(personaje->getImagen(), 0, 0, personaje->getRectangle(), GraphicsUnit::Pixel);
	}
	};
}
