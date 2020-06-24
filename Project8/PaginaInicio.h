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
#include "Vidas.h"
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
		CArreMensajes^ tomateenemigos;
		Int16 punta;
		Int16 dinero;
	private: System::Windows::Forms::Label^  lbl_puntaje;
	private: System::Windows::Forms::Label^  lbl_dinero;
			 Cvidas^ vidajuga;

	public:
		MyForm(void)
		{
			InitializeComponent();
			dia = 0;
			dinero = 100;
			g = panelito->CreateGraphics();
			tiem = gcnew tiempo();
			jugador = gcnew CJugador();
			
			vidajuga = gcnew Cvidas();
			punta = 0;
			mapa = gcnew CMapas(1);
			st=gcnew SoundPlayer("soundtrackTono.wav");
			personas = gcnew CPersonas(1);
			mensajuga = gcnew CArreMensajes(1);
			tomateenemigos = gcnew CArreMensajes(2);
			personas->tamañomen(mensajuga->getancho(), mensajuga->getalto());
			
			actPoli = true;
			creada = false;
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
		CAmbulancia^ambulancia2;
		CMapas^ mapa;
		bool activo;
		SoundPlayer^ st;
		tiempo^ tiem;
		CPersonas ^ personas;
		CPolicia ^poli2;
		int dia;
		bool actPoli;
		bool creada;
		
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
			this->lbl_dinero = (gcnew System::Windows::Forms::Label());
			this->lbl_puntaje = (gcnew System::Windows::Forms::Label());
			this->panelito->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelito
			// 
			this->panelito->Controls->Add(this->lbl_puntaje);
			this->panelito->Controls->Add(this->lbl_dinero);
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
			// lbl_dinero
			// 
			this->lbl_dinero->BackColor = System::Drawing::Color::Black;
			this->lbl_dinero->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lbl_dinero->Font = (gcnew System::Drawing::Font(L"Impact", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_dinero->ForeColor = System::Drawing::Color::White;
			this->lbl_dinero->Location = System::Drawing::Point(622, 8);
			this->lbl_dinero->Name = L"lbl_dinero";
			this->lbl_dinero->Size = System::Drawing::Size(61, 35);
			this->lbl_dinero->TabIndex = 2;
			this->lbl_dinero->Text = L"$100";
			this->lbl_dinero->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lbl_puntaje
			// 
			this->lbl_puntaje->BackColor = System::Drawing::Color::Black;
			this->lbl_puntaje->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lbl_puntaje->Font = (gcnew System::Drawing::Font(L"Impact", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_puntaje->ForeColor = System::Drawing::Color::White;
			this->lbl_puntaje->Location = System::Drawing::Point(162, 8);
			this->lbl_puntaje->Name = L"lbl_puntaje";
			this->lbl_puntaje->Size = System::Drawing::Size(61, 35);
			this->lbl_puntaje->TabIndex = 3;
			this->lbl_puntaje->Text = L"0p";
			this->lbl_puntaje->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
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
		
		
	//amen
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
			/*jugador->MostrarDisparo(jugador->getPosX(), jugador->getPosY(), jugador->getY());*/
			mensajuga->Disparar(jugador->getPosX(), jugador->getPosY(), jugador->getY(), jugador->getancho(), jugador->getalto());
		}
		else if (e->KeyCode==Keys::T) {
			personas->Disparad(jugador->getPosX(),jugador->getPosY());
			creada = true;
		}
		
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		for (int i = 0; i < 5; i++){
			if (mensajuga->getactivador(i)) {
				punta = punta + personas->multado(mensajuga->getposx(i), mensajuga->getposy(i));
				lbl_puntaje->Text = punta + "p";
				if (personas->desacmensa()/*&& personas->sincambio()*/) {
					mensajuga->desativador(i);
				}
			}

		}
		/*personas->Cercania(jugador->getPosX, jugador->getPosY, jugador->getancho, jugador->getalto);*/
		BufferedGraphicsContext ^bfc = BufferedGraphicsManager::Current;
		BufferedGraphics ^bf = bfc->Allocate(g,this->ClientRectangle);
		/////INICIO DE CODIGO
		
		
		if (tiem->gethora() == 6 && tiem->getmin() == 00 && actPoli)
		{
			ambulancia = gcnew CAmbulancia(1, 1);
			ambulancia2 = gcnew CAmbulancia(1,2);
			
			actPoli = false;
		}
		if (tiem->gethora() == 6 && tiem->getmin() == 00&&!actPoli)
		{
			ambulancia = gcnew CAmbulancia(1, 1);
			ambulancia2 = gcnew CAmbulancia(1,2);
			delete poli,poli2;
		}
		if (tiem->gethora()==20 && tiem->getmin() == 00)
		{
			delete ambulancia, ambulancia2;
			poli = gcnew CPolicia(1, 1);
			poli2 = gcnew CPolicia(1, 2);
		}

		bf->Graphics->DrawImage(mapa->getImagen(), 0, 0, mapa->getRectangle(), GraphicsUnit::Pixel);
		
		mensajuga->MostrarDisparo(bf->Graphics);
		jugador->Mostrar(bf->Graphics,activo);
		dinero = dinero - jugador->cobro();
		lbl_dinero->Text = "$" + dinero;
		
		
		personas->Mostrar(bf->Graphics);
		personas->Mover();
		if (tiem->gethora()>=6&&tiem->gethora()<=20)
		{
		ambulancia->desplazamiento();
		ambulancia->Mostrar(bf->Graphics);
		ambulancia2->desplazamiento();
		ambulancia2->Mostrar(bf->Graphics);
		personas->AtrapadoAmbu(ambulancia->getRectangle());
		personas->AtrapadoAmbu(ambulancia2->getRectangle());
		}
		if((tiem->gethora() >= 20 && tiem->gethora() <= 23) || (tiem->gethora() < 6&& tiem->gethora()>=0)){
		
		poli->desplazamiento();
		poli->Mostrar(bf->Graphics);
		poli2->desplazamiento();
		poli2->Mostrar(bf->Graphics);
		personas->AtrapadoPoli(poli->getRectangle());
		personas->AtrapadoPoli(poli2->getRectangle());
		}

		if (creada) {
			personas->Trayectoria();
			personas->verBala(bf->Graphics);
		}


		vidajuga->perdervida (personas->Colision(jugador->getRectangle()));
		vidajuga->Cantivi(bf->Graphics);
		
		/*personas->multado(jugador->colMensaje(), bf->Graphics);*/



		///////FIN DE CODIGO
		bf->Render(g);
		delete bf, bfc;
		tiem->cambio(1);
		mapa->cambio(tiem->gethora());
		lbl_hora->Text = tiem->mostrarT();
		
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
	
	Close();
	
	WindowState = FormWindowState::Normal;
	
	delete map2;
}
private: System::Void panelito_Click(System::Object^  sender, System::EventArgs^  e) {
	
}
private: System::Void panelito_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	cout << e->X << "---" << e->Y << endl;
}
};
}
