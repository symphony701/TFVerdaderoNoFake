#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
ref class CRecomendaciones {
public:
	CRecomendaciones(){}
	Void darRecomendacion(int i) {
		switch (i)
		{
		case 1:MessageBox::Show("Lávese las manos regularmente con un desinfectante a base de alcohol o con agua y jabón."); break;
		case 2:MessageBox::Show("Las prácticas de desinfección son importantes para reducir el potencial de contaminación por el virus COVID-19 en entornos no sanitarios, como en el hogar, la oficina, las escuelas, los gimnasios, los edificios de acceso público, los centros comunitarios basados en la fe, los mercados, el transporte y los entornos comerciales o restaurantes."); break;
		case 3:MessageBox::Show("Infórmese sobre el COVID-19 a través de fuentes confiables: su agencia de salud pública local o nacional, el sitio web de la OMS o su profesional sanitario local. "); break;
		case 4:MessageBox::Show("¿Sabias que para cuando se programo este juego, en el Perú , llevamos 265 000 casos confirmados? Preocupante"); break;
		case 5:MessageBox::Show("A la actualidad de que nuestros programadores nos dieron funcionalidad llevamos 8586 muertes.Cuida a tus seres queridos para que no sean los siguientes! "); break;
		case 6:MessageBox::Show("Veo que llevas tu mascarilla, muy bien! Nunca salgas sin ella, ademas... creo que te ves mejor asi haha"); break;
		case 7:MessageBox::Show("¿Saliste a hacer las compras? No te quiero ver deambulando por las calles, sino informare a la policia"); break;
		case 8:MessageBox::Show("¿Sabias que la UPC decidió dar clases virtuales todo el 2020 para cuidar a sus alumnos? Admirable no?"); break;
		case 9:MessageBox::Show("Todo esto pasara pronto, tengo fe que Dios nos ayuda y lo seguirá haciendo"); break;
		case 10:MessageBox::Show("Espera, me estas diciendo que solo soy un personaje de un trabajo final de 2 estudiantes de Ingeniería de Software?! Terrible "); break;
		case 11:MessageBox::Show("Nuestros programadores , Johnny Roque y Piero Liberato te desean lo mejor y que puedas superar esta pandemia ;) "); break;
		case 12:MessageBox::Show("Quedate en casa, solo movilizate para lo indispensable y siguie las recomendaciones de los expertos, protejamonos entre todos"); break;
		default:
			break;
		}
	}
};


