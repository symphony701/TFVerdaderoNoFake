#pragma once
#include "mapas.h"
#include "Jugador.h"
namespace Project8 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Map2
	/// </summary>
	public ref class Map2 : public System::Windows::Forms::Form
	{
	public:
		Map2(void)
		{
			InitializeComponent();
			g = panel1->CreateGraphics();
			mapa = gcnew CMapas(2);
			jugador = gcnew CJugador();
			//
			//TODO: agregar código de constructor aquí
			//
		}
	private: System::Windows::Forms::Timer^  timer1;
	public:

	protected:
		
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Map2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;

	private:
		Graphics^g;
		CMapas^ mapa;
		CJugador^jugador;
		bool activo;
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(765, 627);
			this->panel1->TabIndex = 0;
			this->panel1->Click += gcnew System::EventHandler(this, &Map2::panel1_Click);
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Map2::panel1_Paint);
			this->panel1->DoubleClick += gcnew System::EventHandler(this, &Map2::panel1_DoubleClick);
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(8, 8);
			this->flowLayoutPanel1->TabIndex = 1;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &Map2::timer1_Tick);
			// 
			// Map2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(769, 631);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->panel1);
			this->Name = L"Map2";
			this->Text = L"Map2";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Map2::Map2_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Map2::Map2_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		BufferedGraphicsContext ^bfc = BufferedGraphicsManager::Current;
		BufferedGraphics ^bf = bfc->Allocate(g, this->ClientRectangle);
		/////INICIO DE CODIGO
		bf->Graphics->DrawImage(mapa->getImagen(), 0, 0, mapa->getRectangle(), GraphicsUnit::Pixel);
		jugador->Mostrar(bf->Graphics, activo);

		///////FIN DE CODIGO
		bf->Render(g);
		delete bf, bfc;
	}
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	}
	private: System::Void panel1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void panel1_DoubleClick(System::Object^  sender, System::EventArgs^  e) {

	}
private: System::Void Map2_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	activo = true;
	if (e->KeyCode == Keys::Up) {
		jugador->Mover2(Direccion::Arriba);
	}
	else if (e->KeyCode == Keys::Down) {
		jugador->Mover2(Direccion::Abajo);
	}
	else if (e->KeyCode == Keys::Left) {
		jugador->Mover2(Direccion::Izquierda);

	}
	else if (e->KeyCode == Keys::Right) {
		jugador->Mover2(Direccion::Derecha);
	}
}
private: System::Void Map2_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
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
};
}
