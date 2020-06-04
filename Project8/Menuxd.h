#pragma once
#include "PaginaInicio.h"
namespace Project8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Menuxd
	/// </summary>
	public ref class Menuxd : public System::Windows::Forms::Form
	{
	public:
		Menuxd(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Menuxd()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnStart;
	protected:

	private:
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
			this->btnStart = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnStart
			// 
			this->btnStart->Location = System::Drawing::Point(123, 129);
			this->btnStart->Name = L"btnStart";
			this->btnStart->Size = System::Drawing::Size(141, 49);
			this->btnStart->TabIndex = 0;
			this->btnStart->Text = L"Get Start :v";
			this->btnStart->UseVisualStyleBackColor = true;
			this->btnStart->Click += gcnew System::EventHandler(this, &Menuxd::btnStart_Click);
			// 
			// Menuxd
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(414, 239);
			this->Controls->Add(this->btnStart);
			this->Name = L"Menuxd";
			this->Text = L"Menuxd";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) {
		MyForm^map1 = gcnew MyForm();
		WindowState = FormWindowState::Minimized;
		map1->ShowDialog();
		WindowState = FormWindowState::Normal;
		delete map1;
	}
	};
}
