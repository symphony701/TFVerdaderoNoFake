#pragma once
#include "PaginaInicio.h"
#include <iostream>
#include "Map2.h"

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
			fondo = gcnew Bitmap("imagenmenu.jpeg");
			gr = panel1->CreateGraphics();
		//	gr->DrawImage(fondo, 0, 0);
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

	private: System::Windows::Forms::Button^  btnstart;
	private: System::Windows::Forms::Button^  btnexit;





	protected:

	private:
		Bitmap ^ fondo;
		Graphics^gr;


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
			this->btnstart = (gcnew System::Windows::Forms::Button());
			this->btnexit = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->btnstart);
			this->panel1->Controls->Add(this->btnexit);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(757, 404);
			this->panel1->TabIndex = 1;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Menuxd::panel1_Paint);
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Menuxd::panel1_MouseMove);
			// 
			// btnstart
			// 
			this->btnstart->BackColor = System::Drawing::Color::Black;
			this->btnstart->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnstart->ForeColor = System::Drawing::Color::White;
			this->btnstart->Location = System::Drawing::Point(524, 167);
			this->btnstart->Name = L"btnstart";
			this->btnstart->Size = System::Drawing::Size(141, 83);
			this->btnstart->TabIndex = 0;
			this->btnstart->Text = L" Start";
			this->btnstart->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnstart->UseVisualStyleBackColor = false;
			this->btnstart->Click += gcnew System::EventHandler(this, &Menuxd::btnStart_Click);
			this->btnstart->MouseHover += gcnew System::EventHandler(this, &Menuxd::btnstart_MouseHover);
			// 
			// btnexit
			// 
			this->btnexit->BackColor = System::Drawing::Color::Black;
			this->btnexit->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 36, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnexit->ForeColor = System::Drawing::Color::White;
			this->btnexit->Location = System::Drawing::Point(524, 290);
			this->btnexit->Name = L"btnexit";
			this->btnexit->Size = System::Drawing::Size(141, 83);
			this->btnexit->TabIndex = 1;
			this->btnexit->Text = L" Exit";
			this->btnexit->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnexit->UseVisualStyleBackColor = false;
			this->btnexit->Click += gcnew System::EventHandler(this, &Menuxd::button1_Click);
			this->btnexit->MouseHover += gcnew System::EventHandler(this, &Menuxd::btnexit_MouseHover);
			// 
			// Menuxd
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(769, 430);
			this->Controls->Add(this->panel1);
			this->Name = L"Menuxd";
			this->Text = L"Menuxd";
			this->Load += gcnew System::EventHandler(this, &Menuxd::Menuxd_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnStart_Click(System::Object^  sender, System::EventArgs^  e) {

		MyForm^map1 = gcnew MyForm();
		WindowState = FormWindowState::Minimized;
		map1->ShowDialog();
		WindowState = FormWindowState::Normal;
		delete map1;
		Map2^map2 = gcnew Map2();
		map2->ShowDialog();
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	Close();
}



private: System::Void panel1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

	if (e->X >= 522 && e->X <= 667) {
		if (e->Y >= 165 && e->Y <= 251) {
			btnstart->ForeColor = System::Drawing:: Color::Lime;
		}
		else {
			btnstart->ForeColor = System::Drawing::Color::White;
		}
		if (e->Y >= 288 && e->Y <= 374) {
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
private: System::Void Menuxd_Load(System::Object^  sender, System::EventArgs^  e) {


	
	
}
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	gr->DrawImage(fondo, 0, 0);


}
private: System::Void btnexit_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	btnexit->ForeColor = System::Drawing::Color::Lime;
}
private: System::Void btnstart_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	btnstart->ForeColor = System::Drawing::Color::Lime;

}
};
}
