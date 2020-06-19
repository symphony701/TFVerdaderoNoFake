#pragma once
#include "Entidad.h"
#include "Jugador.h"
#include "Policia.h"
#include "Ambulancia.h"
#include "mapas.h"
#include "Map2.h"
#include "Tiempo.h"
#include "Personas.h"
#include <iostream>
#include "Arremensajes.h"
using namespace std;
namespace Project8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;
	using namespace System::Media;
	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		CArreMensajes^ mensajuga;

	public:
		MyForm(void)
		{
			InitializeComponent();

			g = panelito->CreateGraphics();
			tiem = gcnew tiempo();
			jugador = gcnew CJugador();
			poli = gcnew CPolicia();
			ambulancia = gcnew CAmbulancia();
			mapa = gcnew CMapas(1);
			st=gcnew SoundPlayer("soundtrackTono.wav");
			personas = gcnew CPersonas();
			mensajuga = gcnew CArreMensajes(1);
			personas->tamañomen(mensajuga->getancho(), mensajuga->getalto());
			//g->DrawImage(personaje->getImagen(), 0, 0, personaje->getRectangle(), GraphicsUnit::Pixel);


		};
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  lbl_hora;
	public:

	protected:
		Graphics^g;
		/*cli::array<Rectangle^>^ rectangulo;*/
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

		CJugador^ jugador;
		CPolicia^poli;
		CAmbulancia ^ambulancia;
		CMapas^ mapa;
		bool activo;
		SoundPlayer^ st;
		tiempo^ tiem;
		CPersonas ^ personas;
	private: System::ComponentModel::IContainer^  components;

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
			this->panelito = (gcnew System::Windows::Forms::Panel());
			this->lbl_hora = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelito->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelito
			// 
			this->panelito->Controls->Add(this->lbl_hora);
			this->panelito->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->panelito->Location = System::Drawing::Point(1, 1);
			this->panelito->Name = L"panelito";
			this->panelito->Size = System::Drawing::Size(768, 631);
			this->panelito->TabIndex = 0;
			this->panelito->Click += gcnew System::EventHandler(this, &MyForm::panelito_Click);
			this->panelito->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panelito_Paint);
			this->panelito->DoubleClick += gcnew System::EventHandler(this, &MyForm::panelito_DoubleClick);
			this->panelito->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::panelito_MouseClick);
			// 
			// lbl_hora
			// 
			this->lbl_hora->BackColor = System::Drawing::Color::Black;
			this->lbl_hora->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lbl_hora->Font = (gcnew System::Drawing::Font(L"Impact", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_hora->ForeColor = System::Drawing::Color::White;
			this->lbl_hora->Location = System::Drawing::Point(695, 8);
			this->lbl_hora->Name = L"lbl_hora";
			this->lbl_hora->Size = System::Drawing::Size(61, 35);
			this->lbl_hora->TabIndex = 1;
			this->lbl_hora->Text = L" 6:00";
			this->lbl_hora->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
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
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->panelito->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		
	}
	private: System::Void panelito_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		
		
	
	//	st->PlayLooping();
		
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		activo = true;
		if (e->KeyCode == Keys::Up) {
			jugador->Mover(Direccion::Arriba);
		}else if(e->KeyCode == Keys::Down){
			jugador->Mover(Direccion::Abajo);
		}
		else if (e->KeyCode == Keys::Left) {
			jugador->Mover(Direccion::Izquierda);

		}else if(e->KeyCode == Keys::Right){
			jugador->Mover(Direccion::Derecha);
		}
		else if (e->KeyCode == Keys::W) {
			jugador->MostrarDisparo(jugador->getPosX(), jugador->getPosY(), jugador->getY());
			mensajuga->MostrarDisparo(jugador->getPosX(), jugador->getPosY(), jugador->getY());
		}
		
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		for (int i = 0; i < 5; i++){
			if (mensajuga->getactivador(i)) {
				personas->multado(mensajuga->getposx(i), mensajuga->getposy(i));
			}

		}
		
		BufferedGraphicsContext ^bfc = BufferedGraphicsManager::Current;
		BufferedGraphics ^bf = bfc->Allocate(g,this->ClientRectangle);
		/////INICIO DE CODIGO
		bf->Graphics->DrawImage(mapa->getImagen(), 0, 0, mapa->getRectangle(), GraphicsUnit::Pixel);
		/*jugador->Disparar(bf->Graphics);*/
		mensajuga->Disparar(bf->Graphics);
		jugador->Mostrar(bf->Graphics,activo);
		
		
		personas->Mostrar(bf->Graphics);
		personas->Mover();
		poli->Mostrar(bf->Graphics);
		poli->desplazamiento();
		personas->AtrapadoPoli(poli->getRectangle());
		/*personas->multado(jugador->colMensaje(), bf->Graphics);*/



		///////FIN DE CODIGO
		bf->Render(g);
		delete bf, bfc;
		tiem->cambio(1);
		lbl_hora->Text = tiem->mostrarT();
		mapa->cambio(tiem->gethora());
	}
private: System::Void MyForm_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
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
private: System::Void panelito_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
	Map2^map2 = gcnew Map2();
	WindowState = FormWindowState::Minimized;
	map2->ShowDialog();
	
	WindowState = FormWindowState::Normal;
	
	delete map2;
	Close();
}
private: System::Void panelito_Click(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void panelito_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	cout << e->X << "---" << e->Y << endl;
}
};
}
