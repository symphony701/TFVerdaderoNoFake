#pragma once
#include "PaginaInicio.h"
#include <iostream>

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
	private: System::Windows::Forms::Panel^  panel1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnstart;
	private: System::Windows::Forms::Button^  btnexit;





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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnstart = (gcnew System::Windows::Forms::Button());
			this->btnexit = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Black;
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->btnstart);
			this->panel1->Controls->Add(this->btnexit);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(390, 215);
			this->panel1->TabIndex = 1;
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Menuxd::panel1_MouseMove);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Heroes Assemble Gradient Italic", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Lime;
			this->label1->Location = System::Drawing::Point(61, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(276, 62);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Quarantine Game";
			// 
			// btnstart
			// 
			this->btnstart->BackColor = System::Drawing::Color::Black;
			this->btnstart->Font = (gcnew System::Drawing::Font(L"Heroes Assemble Expanded", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnstart->ForeColor = System::Drawing::Color::White;
			this->btnstart->Location = System::Drawing::Point(123, 112);
			this->btnstart->Name = L"btnstart";
			this->btnstart->Size = System::Drawing::Size(141, 40);
			this->btnstart->TabIndex = 0;
			this->btnstart->Text = L"Get Start :v";
			this->btnstart->UseVisualStyleBackColor = false;
			this->btnstart->Click += gcnew System::EventHandler(this, &Menuxd::btnStart_Click);
			this->btnstart->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Menuxd::btnstart_MouseMove);
			// 
			// btnexit
			// 
			this->btnexit->BackColor = System::Drawing::Color::Black;
			this->btnexit->Font = (gcnew System::Drawing::Font(L"Heroes Assemble Expanded", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnexit->ForeColor = System::Drawing::Color::White;
			this->btnexit->Location = System::Drawing::Point(123, 158);
			this->btnexit->Name = L"btnexit";
			this->btnexit->Size = System::Drawing::Size(141, 40);
			this->btnexit->TabIndex = 1;
			this->btnexit->Text = L"Exit";
			this->btnexit->UseVisualStyleBackColor = false;
			this->btnexit->Click += gcnew System::EventHandler(this, &Menuxd::button1_Click);
			// 
			// Menuxd
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(414, 239);
			this->Controls->Add(this->panel1);
			this->Name = L"Menuxd";
			this->Text = L"Menuxd";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
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
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	Close();
}

private: System::Void btnstart_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (e->X <= 123 && e->X >= 264) {
		if (e->Y== 112 && e->Y >= 152){
			btnstart->ForeColor = Color::Lime;
		}
		if (e->Y == 158 && e->Y == 198){
			btnexit->ForeColor = Color::Lime;
		}
}
}

private: System::Void panel1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

	if (e->X >= 122 && e->X <= 265) {
		if (e->Y >= 111 && e->Y <= 153) {
			btnstart->ForeColor = System::Drawing:: Color::Lime;
		}
		else {
			btnstart->ForeColor = System::Drawing::Color::White;
		}
		if (e->Y >= 157 && e->Y <= 199) {
			btnexit->ForeColor = System::Drawing::Color::Lime;
		}
		else {
			btnexit->ForeColor = System::Drawing::Color::White;
		}
	}
	else {
		btnstart->ForeColor = System::Drawing::Color::White;
		btnexit->ForeColor = System::Drawing::Color::White;
	}
}
};
}
