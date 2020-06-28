#pragma once
#include "Jugador.h"
#include "Arremensajes.h"
#include <iostream>

namespace Project8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Instrucciones
	/// </summary>
	public ref class Instrucciones : public System::Windows::Forms::Form{
		Int16 num;
		Graphics^ g;
		CArreMensajes^ mensajuga;
		CJugador^ jugador;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label11;
			 bool activo;
	public:
		Instrucciones(void)
		{
			InitializeComponent();
			num = 1;
			g = panel1->CreateGraphics();
			mensajuga = gcnew CArreMensajes(1);
			jugador = gcnew CJugador(1);
			activo = false;
			jugador->setPosX(350);
			jugador->setPosY(150);
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Instrucciones()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
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
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Black;
			this->panel1->Controls->Add(this->label12);
			this->panel1->Controls->Add(this->label11);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label10);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(6, 13);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(757, 423);
			this->panel1->TabIndex = 1;
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Instrucciones::panel1_MouseClick);
			this->panel1->MouseHover += gcnew System::EventHandler(this, &Instrucciones::panel1_MouseHover);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Cooper Black", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(433, 13);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(55, 40);
			this->label12->TabIndex = 13;
			this->label12->Text = L"-->";
			this->label12->Click += gcnew System::EventHandler(this, &Instrucciones::label12_Click);
			this->label12->MouseHover += gcnew System::EventHandler(this, &Instrucciones::label12_MouseHover);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Cooper Black", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(284, 13);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(55, 40);
			this->label11->TabIndex = 12;
			this->label11->Text = L"<--";
			this->label11->Click += gcnew System::EventHandler(this, &Instrucciones::label11_Click);
			this->label11->MouseHover += gcnew System::EventHandler(this, &Instrucciones::label11_MouseHover);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(52, 62);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(666, 44);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Eres una persona cansada de los imprudentes";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(52, 106);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(665, 44);
			this->label4->TabIndex = 5;
			this->label4->Text = L"que salen a la calle y acordaste con la policia";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(199, 371);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(393, 44);
			this->label10->TabIndex = 11;
			this->label10->Text = L"rompas el toque de queda";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(74, 327);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(605, 44);
			this->label9->TabIndex = 10;
			this->label9->Text = L"puedas descansar en una habitacion y no";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(52, 283);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(666, 44);
			this->label8->TabIndex = 9;
			this->label8->Text = L"dandote dinero por cada capturado para que";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(11, 239);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(748, 44);
			this->label7->TabIndex = 8;
			this->label7->Text = L"Las autoridades pasaran a su hora correspondiente";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(277, 194);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(244, 44);
			this->label6->TabIndex = 7;
			this->label6->Text = L"infectados o no.";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(64, 150);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(636, 44);
			this->label5->TabIndex = 6;
			this->label5->Text = L"y ambulancia para que identifiques si estan";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(372, 11);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 44);
			this->label2->TabIndex = 1;
			this->label2->Text = L"/4";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Bernard MT Condensed", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(341, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 44);
			this->label1->TabIndex = 0;
			this->label1->Text = L"1";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Instrucciones::timer1_Tick);
			// 
			// Instrucciones
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(769, 440);
			this->Controls->Add(this->panel1);
			this->ForeColor = System::Drawing::Color::White;
			this->Name = L"Instrucciones";
			this->Text = L"Instrucciones";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Instrucciones::Instrucciones_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Instrucciones::Instrucciones_KeyUp);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		/*if (num == 1) {
			button2->Enabled = false;
		}
		else {
			button2->Enabled = true;
		}

		if (num == 4) {
			button1->Enabled = false;
		}
		else {
			button1->Enabled = true;
		}*/
		BufferedGraphicsContext ^bfc = BufferedGraphicsManager::Current;
		BufferedGraphics ^bf = bfc->Allocate(g, this->ClientRectangle);
		if (num == 2) {
			/*jugador->*/
			jugador->Mostrar(bf->Graphics, activo,0);
			mensajuga->MostrarDisparo(bf->Graphics);
		}

		bf->Render(g);
		delete bf, bfc;
	}
private: System::Void Instrucciones_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	activo = true;
	if (e->KeyCode == Keys::Up) {
		jugador->Mover3(Direccion::Arriba);
	}
	else if (e->KeyCode == Keys::Down) {
		jugador->Mover3(Direccion::Abajo);
	}
	else if (e->KeyCode == Keys::Left) {
		jugador->Mover3(Direccion::Izquierda);

	}
	else if (e->KeyCode == Keys::Right) {
		jugador->Mover3(Direccion::Derecha);
	}
	else if (e->KeyCode == Keys::W) {
		/*jugador->MostrarDisparo(jugador->getPosX(), jugador->getPosY(), jugador->getY());*/
		mensajuga->Disparar(jugador->getPosX(), jugador->getPosY(), jugador->getY(), jugador->getancho(), jugador->getalto());
	}
}
private: System::Void Instrucciones_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::W) {
		activo = false;
	}
	if (e->KeyCode == Keys::Up) {
		activo = false;
	}
	else if (e->KeyCode == Keys::Down) {
		activo = false;
	}
	else if (e->KeyCode == Keys::Left) {
		activo = false;

	}
	else if (e->KeyCode == Keys::Right) {
		activo = false;
	}
}
private: System::Void label12_Click(System::Object^  sender, System::EventArgs^  e) {
	num++;
	label1->Text = num + "";
	label11->ForeColor = System::Drawing::Color::White;
	label12->ForeColor = System::Drawing::Color::White;
	if (num == 1) {
		label3->ForeColor = System::Drawing::Color::White;
		label4->ForeColor = System::Drawing::Color::White;
		label5->ForeColor = System::Drawing::Color::White;
		label5->Location = System::Drawing::Point(64, 150);
		label6->ForeColor = System::Drawing::Color::White;
		label6->Location = System::Drawing::Point(277, 194);
		label7->ForeColor = System::Drawing::Color::White;
		label7->Location = System::Drawing::Point(11, 239);
		label8->ForeColor = System::Drawing::Color::White;
		label8->Location = System::Drawing::Point(52, 283);
		label9->ForeColor = System::Drawing::Color::White;
		label9->Location = System::Drawing::Point(74, 327);
		label10->ForeColor = System::Drawing::Color::White;
		label10->Location = System::Drawing::Point(199, 371);
		label3->Text = "Eres una persona cansada de los imprudentes";
		label3->Location = System::Drawing::Point(52, 62);
		label4->Text = "que salen a la calle y acordaste con la policia";
		label4->Location = System::Drawing::Point(52, 106);
	}
	else {
		/*label3->ForeColor = System::Drawing::Color::Black;
		label4->ForeColor = System::Drawing::Color::Black;*/
		/*label5->ForeColor = System::Drawing::Color::White;
		label5->Location = System::Drawing::Point(52, 506);*/
		/*label6->ForeColor = System::Drawing::Color::Black;
		label6->Location = System::Drawing::Point(52, 506);*/
		label7->ForeColor = System::Drawing::Color::Black;
		label7->Location = System::Drawing::Point(52, 506);
		label8->ForeColor = System::Drawing::Color::Black;
		label8->Location = System::Drawing::Point(52, 506);
		label9->ForeColor = System::Drawing::Color::Black;
		label9->Location = System::Drawing::Point(52, 506);
		label10->ForeColor = System::Drawing::Color::Black;
		label10->Location = System::Drawing::Point(52, 506);
	}
	if (num == 2) {
		label3->Text = "Usas las flechas direccionales para moverte";
		label3->Location = System::Drawing::Point(62, 62);
		label4->Text = "Y la W para disparar";
		label4->Location = System::Drawing::Point(245, 106);
		label5->Text = "Solo posees 5 disparos";
		label5->Location = System::Drawing::Point(240, 283);
		label6->Text = "Y cada mapa tiene restricciones, tener cuidado";
		label6->Location = System::Drawing::Point(45, 327);

	}
}
private: System::Void label11_Click(System::Object^  sender, System::EventArgs^  e) {
	num--;
	label1->Text = num + "";
	label12->ForeColor = System::Drawing::Color::White;
	label11->ForeColor = System::Drawing::Color::White;
	if (num == 1) {
		label3->ForeColor = System::Drawing::Color::White;
		label4->ForeColor = System::Drawing::Color::White;
		label5->ForeColor = System::Drawing::Color::White;
		label5->Location = System::Drawing::Point(64, 150);
		label6->ForeColor = System::Drawing::Color::White;
		label6->Location = System::Drawing::Point(277, 194);
		label7->ForeColor = System::Drawing::Color::White;
		label7->Location = System::Drawing::Point(11, 239);
		label8->ForeColor = System::Drawing::Color::White;
		label8->Location = System::Drawing::Point(52, 283);
		label9->ForeColor = System::Drawing::Color::White;
		label9->Location = System::Drawing::Point(74, 327);
		label10->ForeColor = System::Drawing::Color::White;
		label10->Location = System::Drawing::Point(199, 371);
		label3->Text = "Eres una persona cansada de los imprudentes";
		label3->Location = System::Drawing::Point(52, 62);
		label4->Text = "que salen a la calle y acordaste con la policia";
		label4->Location = System::Drawing::Point(52, 106);
	}
	else {
		/*label3->ForeColor = System::Drawing::Color::Black;
		/*label4->ForeColor = System::Drawing::Color::Black;
		label5->ForeColor = System::Drawing::Color::White;
		label5->Location = System::Drawing::Point(52, 506);
		label6->ForeColor = System::Drawing::Color::Black;
		label6->Location = System::Drawing::Point(52, 506);*/
		label7->ForeColor = System::Drawing::Color::Black;
		label7->Location = System::Drawing::Point(52, 506);
		label8->ForeColor = System::Drawing::Color::Black;
		label8->Location = System::Drawing::Point(52, 506);
		label9->ForeColor = System::Drawing::Color::Black;
		label9->Location = System::Drawing::Point(52, 506);
		label10->ForeColor = System::Drawing::Color::Black;
		label10->Location = System::Drawing::Point(52, 506);
	}
	if (num == 2) {
		label3->Text = "Usas las flechas direccionales para moverte";
		label3->Location = System::Drawing::Point(62, 62);
		label4->Text = "Y la W para disparar";
		label4->Location = System::Drawing::Point(245, 106);
		label5->Text = "Solo posees 5 disparos";
		label5->Location = System::Drawing::Point(245, 283);
		label6->Text = "Y cada mapa tiene restricciones, tener cuidado";
		label6->Location = System::Drawing::Point(62, 327);
	}
}
private: System::Void label12_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	label12->ForeColor = System::Drawing::Color::Lime;

}
private: System::Void label11_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	label11->ForeColor = System::Drawing::Color::Lime;
}
private: System::Void panel1_MouseHover(System::Object^  sender, System::EventArgs^  e) {
	label12->ForeColor = System::Drawing::Color::White;
	label11->ForeColor = System::Drawing::Color::White;
}
private: System::Void panel1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	cout << e->X << "---" << e->Y << endl;
}
};
}
