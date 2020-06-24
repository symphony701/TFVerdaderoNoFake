#pragma once
#include <iostream>
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace std;
ref class Climites{
public:
	Climites(){}
	~Climites(){}
	bool colocamapa1(Int16 posx, Int16 posy) {
		bool i = false;
		if (Formula(179, 250, 385, 425, posx, posy)) {i = true;}
		return i;
	}
	bool mapa1arriba(bool movArriba, Int16 posx, Int16 posy) {
		while (true) {
			if(Formula(179, 250, 385, 388, posx, posy)) { movArriba = false; break; }
			if (Formula(195, 250, 440,445, posx, posy)) { movArriba = false; break; }
			if (Formula(590, 632, 143, 146, posx, posy)) { movArriba = false; break; }
			if (Formula(420, 590, 47, 49, posx, posy)) { movArriba = false; break; }
			if (Formula(299, 563, 317, 320, posx, posy)) { movArriba = false; break; }
			if (Formula(149, 299, 257, 260, posx, posy)) { movArriba = false; break; }
			if (Formula(389, 524, 155, 158, posx, posy)) { movArriba = false; break; }
			if (Formula(125, 356, 155, 158, posx, posy)) { movArriba = false; break; }
			if (Formula(-13, 125, 290, 293, posx, posy)) { movArriba = false; break; }
			if (Formula(290, 584, 440, 443, posx, posy)) { movArriba = false; break; }
			movArriba = true;
			break;
		}
		cout << posx << "----" << posy << endl;
		return (movArriba);



	}
	bool mapa1abajo(bool movAbajo, Int16 posx, Int16 posy) {
		while (true) {
			if (Formula(179, 250, 365, 368, posx, posy)) { movAbajo = false; break; }
			if (Formula(195, 250, 420, 425, posx, posy)) { movAbajo = false; break; }
			if (Formula(104, 632, 517, 521, posx, posy)) { movAbajo = false; break; }
			if (Formula(-4, 103, 327, 329, posx, posy)) { movAbajo = false; break; }
			if (Formula(470, 563, 80, 83, posx, posy)) { movAbajo = false; break; }
			if (Formula(149, 524, 185, 188, posx, posy)) { movAbajo = false; break; }
			if (Formula(290, 584, 362, 365, posx, posy)) { movAbajo = false; break; }
			movAbajo = true;
			break;
		}
		cout << posx << "----" << posy << endl;

		return (movAbajo);
		
	}
	bool mapa1derecha(bool movDerecha, Int16 posx, Int16 posy) {
		while (true) {
			if (Formula(158, 161, 380, 431, posx, posy)) { movDerecha = false; break; }
			if (Formula(236, 240, 374, 437, posx, posy)) { movDerecha = false; break; }
			if (Formula(587, 593, 47, 146, posx, posy)) { movDerecha = false; break; }
			if (Formula(296, 299, 260, 320, posx, posy)) { movDerecha = false; break; }
			if (Formula(146, 149, 188, 260, posx, posy)) { movDerecha = false; break; }
			if (Formula(521, 524, 158, 194, posx, posy)) { movDerecha = false; break; }
			if (Formula(386, 389, 10, 158, posx, posy)) { movDerecha = false; break; }
			if (Formula(287, 290, 365, 443, posx, posy)) { movDerecha = false; break; }
			movDerecha = true;

			break;
		}
		cout << posx << "----" << posy << endl;
		return (movDerecha);
		
	}
	bool mapa1izquierda(bool movIzquierda, Int16 posx, Int16 posy) {
		while (true) {
			if (Formula(257, 260, 374, 437, posx, posy)) { movIzquierda = false; break; }
			if (Formula(178, 181, 380, 431, posx, posy)) { movIzquierda = false; break; }
			if (Formula(101, 104, 329, 521, posx, posy)) { movIzquierda = false; break; }
			if (Formula(467, 470, 47, 83, posx, posy)) { movIzquierda = false; break; }
			if (Formula(560, 563, 83, 320, posx, posy)) { movIzquierda = false; break; }
			if (Formula(125, 127, 158, 293, posx, posy)) { movIzquierda = false; break; }
			if (Formula(356, 359, 10, 158, posx, posy)) { movIzquierda = false; break; }
			if (Formula(584, 587, 365, 443, posx, posy)) { movIzquierda = false; break; }
			movIzquierda = true;
			break;
		}

		cout << posx << "----" << posy << endl;
		return(movIzquierda);
	}
	//mapa 2
	bool mapa2arriba(bool movArriba,Int16 posx, Int16 posy){
		while (true) {
			if (Formula(608, 638, 293, 296, posx, posy)) { movArriba = false; break; }
			if (Formula(236, 608, 512, 515, posx, posy)) { movArriba = false; break; }
			if (Formula(236, 582, 458, 461, posx, posy)) { movArriba = false; break; }
			if (Formula(236, 401, 320, 323, posx, posy)) { movArriba = false; break; }
			if (Formula(236, 338, 188, 191, posx, posy)) { movArriba = false; break; }
			if (Formula(236, 582, 458, 461, posx, posy)) { movArriba = false; break; }
			if (Formula(212, 236, 134, 137, posx, posy)) { movArriba = false; break; }
			if (Formula(236, 582, 458, 461, posx, posy)) { movArriba = false; break; }
			if (Formula(8, 212, 188, 191, posx, posy)) { movArriba = false; break; }
			if (Formula(8, 212, 320, 323, posx, posy)) { movArriba = false; break; }
			if (Formula(128, 212, 458, 461, posx, posy)) { movArriba = false; break; }
			if (Formula(134, 212, 512, 515, posx, posy)) { movArriba = false; break; }
			movArriba = true;
			break;
		}
		return(movArriba);

	}
	bool mapa2abajo(bool movAbajo, Int16 posx, Int16 posy) {
		while (true) {
			if (Formula(491, 494, 236, 582, posx, posy)) { movAbajo = false; break; }
			if (Formula(236, 401, 353, 356, posx, posy)) { movAbajo = false; break; }
			if (Formula(236, 338, 221, 224, posx, posy)) { movAbajo = false; break; }
			if (Formula(398, 401, 320, 356, posx, posy)) { movAbajo = false; break; }
			if (Formula(8, 212, 221, 224, posx, posy)) { movAbajo = false; break; }
			if (Formula(8, 212, 353, 356, posx, posy)) { movAbajo = false; break; }
			if (Formula(128, 212, 491, 494, posx, posy)) { movAbajo = false; break; }
			if (Formula(134, 638, 551, 554, posx, posy)) { movAbajo = false; break; }
			movAbajo = true;
				break;
			}
			return(movAbajo);

			cout << posx << "----" << posy << endl;

		}
	bool mapa2derecha( bool movDerecha, Int16 posx, Int16 posy) {
		while (true) {

			if (Formula(635, 638, 293, 554, posx, posy)) { movDerecha = false; break; }
			if (Formula(233, 236, 494, 512, posx, posy)) { movDerecha = false; break; }
			if (Formula(434, 437, 438, 494, posx, posy)) { movDerecha = false; break; }
			if (Formula(233, 236, 356, 458, posx, posy)) { movDerecha = false; break; }
			if (Formula(398, 401, 320, 356, posx, posy)) { movDerecha = false; break; }
			if (Formula(233, 236, 224, 320, posx, posy)) { movDerecha = false; break; }
			if (Formula(335, 338, 188, 224, posx, posy)) { movDerecha = false; break; }
			if (Formula(233, 236, 134, 188, posx, posy)) { movDerecha = false; break; }
		
			movDerecha = true;
			break;
		}
		return(movDerecha);
		cout << posx << "----" << posy << endl;

	}
	bool mapa2izquierda(bool movIzquierda, Int16 posx, Int16 posy) {
		while (true) {
		

			if (Formula(608, 611, 293, 512, posx, posy)) { movIzquierda = false; break; }
			if (Formula(212, 215, 134, 188, posx, posy)) { movIzquierda = false; break; }
			if (Formula(8, 11, 188, 224, posx, posy)) { movIzquierda = false; break; }
			if (Formula(212, 215, 224, 320, posx, posy)) { movIzquierda = false; break; }
			if (Formula(8, 11, 320, 356, posx, posy)) { movIzquierda = false; break; }
			if (Formula(212, 215, 356, 458, posx, posy)) { movIzquierda = false; break; }
			if (Formula(128, 131, 458, 494, posx, posy)) { movIzquierda = false; break; }
			if (Formula(212, 215, 134, 188, posx, posy)) { movIzquierda = false; break; }
			if (Formula(212, 215, 494, 512, posx, posy)) { movIzquierda = false; break; }
			if (Formula(134, 137, 512, 554, posx, posy)) { movIzquierda = false; break; }
			movIzquierda = true;
			break;
		}
		return(movIzquierda);
		cout << posx << "----" << posy << endl;

	}
	
	bool mapa3arriba(bool movArriba,Int16 posx, Int16 posy){
	while (true)
	{
		if (Formula(344, 620, 485, 488, posx, posy)) { movArriba = false; break; }
		if (Formula(629, 656, 239, 242, posx, posy)) { movArriba = false; break; }
		if (Formula(506, 629, 287, 290, posx, posy)) { movArriba = false; break; }
		if (Formula(482, 506, 239, 242, posx, posy)) { movArriba = false; break; }
		if (Formula(344, 482, 287, 290, posx, posy)) { movArriba = false; break; }
		if (Formula(467, 657, 41, 44, posx, posy)) { movArriba = false; break; }
		if (Formula(410, 470, 62, 65, posx, posy)) { movArriba = false; break; }
		if (Formula(320, 368, 62, 65, posx, posy)) { movArriba = false; break; }
		if (Formula(203, 320, 239, 242, posx, posy)) { movArriba = false; break; }
		if (Formula(224, 320, 485, 488, posx, posy)) { movArriba = false; break; }
		if (Formula(344, 482, 395, 398, posx, posy)) { movArriba = false; break; }
		if (Formula(506, 629, 395, 398, posx, posy)) { movArriba = false; break; }
		movArriba = true;
		break;
	}
	return(movArriba);
	cout << posx << "----" << posy << endl;
}
	bool mapa3abajo(bool movAbajo, Int16 posx, Int16 posy) {
		while (true)
		{
			if (Formula(392, 620, 515, 518, posx, posy)) { movAbajo = false; break; }
			if (Formula(344, 656, 431, 434, posx, posy)) { movAbajo = false; break; }
			if (Formula(344, 488, 87, 89, posx, posy)) { movAbajo = false; break; }
			if (Formula(488, 629, 57, 59, posx, posy)) { movAbajo = false; break; }
			if (Formula(629, 657, 140, 143, posx, posy)) { movAbajo = false; break; }
			if (Formula(203, 320, 273, 275, posx, posy)) { movAbajo = false; break; }
			if (Formula(224, 350, 515, 518, posx, posy)) { movAbajo = false; break; }
			if (Formula(344, 482, 317, 320, posx, posy)) { movAbajo = false; break; }
			if (Formula(506, 629, 319, 320, posx, posy)) { movAbajo = false; break; }
			movAbajo = true;
			break;
		}
		return(movAbajo);
		cout << posx << "----" << posy << endl;
	}
	bool mapa3derecha(bool movDerecha, Int16 posx, Int16 posy) {
		while (true)
		{
			if (Formula(389, 392, 518, 578, posx, posy)) { movDerecha = false; break; }
			if (Formula(617, 620, 485, 518, posx, posy)) { movDerecha = false; break; }
			if (Formula(341, 344, 434, 485, posx, posy)) { movDerecha = false; break; }
			if (Formula(653, 656, 239, 434, posx, posy)) { movDerecha = false; break; }
			if (Formula(503, 506, 239, 287, posx, posy)) { movDerecha = false; break; }
			if (Formula(341, 344, 89, 287, posx, posy)) { movDerecha = false; break; }
			if (Formula(485, 488, 59, 89, posx, posy)) { movDerecha = false; break; }
			if (Formula(654, 657, 41, 143, posx, posy)) { movDerecha = false; break; }
			if (Formula(407, 410, -16, 62, posx, posy)) { movDerecha = false; break; }
			if (Formula(341, 344, 320, 395, posx, posy)) { movDerecha = false; break; }
			if (Formula(503, 506, 320, 395, posx, posy)) { movDerecha = false; break; }
			movDerecha =  true;
			break;
		}
		return(movDerecha);
		cout << posx << "----" << posy << endl;
	}
	bool mapa3izquierda(bool movIzquierda, Int16 posx, Int16 posy) {
		while (true)
		{
			if (Formula(629, 632, 239, 287, posx, posy)) { movIzquierda = false; break; }
			if (Formula(482, 485, 239, 287, posx, posy)) { movIzquierda = false; break; }
			if (Formula(629, 632, 59, 143, posx, posy)) { movIzquierda = false; break; }
			if (Formula(467, 470, 41, 62, posx, posy)) { movIzquierda = false; break; }
			if (Formula(320, 323, 62, 239, posx, posy)) { movIzquierda = false; break; }
			if (Formula(203, 206, 239, 275, posx, posy)) { movIzquierda = false; break; }
			if (Formula(320, 323, 275, 485, posx, posy)) { movIzquierda = false; break; }
			if (Formula(224, 227, 485, 518, posx, posy)) { movIzquierda = false; break; }
			if (Formula(350, 353, 518, 578, posx, posy)) { movIzquierda = false; break; }
			if (Formula(368, 371, -16, 62, posx, posy)) { movIzquierda = false; break; }
			if (Formula(482, 485, 320, 395, posx, posy)) { movIzquierda = false; break; }
			if (Formula(629, 632, 320, 395, posx, posy)) { movIzquierda = false; break; }



			movIzquierda = true;
			break;
		}
		return(movIzquierda);
		cout << posx << "----" << posy << endl;
	}
	//mapa4
	bool mapa4arriba(bool movArriba, Int16 posx, Int16 posy) {
		while (true) {
			if (Formula(98, 272, 482, 485, posx, posy)) { movArriba = false; break; }
			if (Formula(293, 650, 488, 491, posx, posy)) { movArriba = false; break; }
			if (Formula(116, 614, 368, 371, posx, posy)) { movArriba = false; break; }
			if (Formula(98, 269, 206, 209, posx, posy)) { movArriba = false; break; }
			if (Formula(458, 647, 206, 209, posx, posy)) { movArriba = false; break; }
			if (Formula(71, 680, 89, 92, posx, posy)) { movArriba = false; break; }
			movArriba = true;
			break;
		}
		return(movArriba);

	}
	bool mapa4abajo(bool movAbajo, Int16 posx, Int16 posy) {
		while (true) {
			if (Formula(71, 680, 509, 512, posx, posy)) { movAbajo = false; break; }
			if (Formula(98, 272, 395, 398, posx, posy)) { movAbajo = false; break; }
			if (Formula(293, 650, 395, 398, posx, posy)) { movAbajo = false; break; }
			if (Formula(113, 269, 239, 242, posx, posy)) { movAbajo = false; break; }
			if (Formula(458, 614, 239, 242, posx, posy)) { movAbajo = false; break; }
			if (Formula(98, 278, 116, 119, posx, posy)) { movAbajo = false; break; }
			if (Formula(449, 605, 116, 119, posx, posy)) { movAbajo = false; break; }
			if (Formula(278, 449, 107, 110, posx, posy)) { movAbajo = false; break; }
			movAbajo = true;
			break;
		}
		return(movAbajo);

		cout << posx << "----" << posy << endl;

	}
	bool mapa4derecha(bool movDerecha, Int16 posx, Int16 posy) {
		while (true) {

			if (Formula(673, 680, 89, 512, posx, posy)) { movDerecha = false; break; }
			if (Formula(275, 278, 110, 119, posx, posy)) { movDerecha = false; break; }
			if (Formula(95, 98, 119, 206, posx, posy)) { movDerecha = false; break; }
			if (Formula(110, 113, 242, 368, posx, posy)) { movDerecha = false; break; }
			if (Formula(95, 98, 398, 482, posx, posy)) { movDerecha = false; break; }
			if (Formula(290, 293, 398, 488, posx, posy)) { movDerecha = false; break; }
			if (Formula(266, 269, 188, 224, posx, posy)) { movDerecha = false; break; }
			movDerecha = true;
			break;
		}
		return(movDerecha);
		cout << posx << "----" << posy << endl;

	}
	bool mapa4izquierda(bool movIzquierda, Int16 posx, Int16 posy) {
		while (true) {


			if (Formula(71, 73, 89, 512, posx, posy)) { movIzquierda = false; break; }
			if (Formula(647, 650, 119, 206, posx, posy)) { movIzquierda = false; break; }
			if (Formula(449, 452, 98, 119, posx, posy)) { movIzquierda = false; break; }
			if (Formula(458, 461, 206, 242, posx, posy)) { movIzquierda = false; break; }
			if (Formula(272, 275, 398, 482, posx, posy)) { movIzquierda = false; break; }
			if (Formula(650, 653, 398, 488, posx, posy)) { movIzquierda = false; break; }
			if (Formula(614, 617, 242, 368, posx, posy)) { movIzquierda = false; break; }
			movIzquierda = true;
			break;
		}
		return(movIzquierda);
		cout << posx << "----" << posy << endl;

	}
	bool Formula(Int16 xmin, Int16 xmax, Int16 ymin, Int16 ymax,Int16 posx, Int16 posy) {
		bool valzz;
		if (posx >= xmin && xmax >= posx && posy >= ymin && ymax >= posy) {
			valzz = true;
		}
		else { valzz = false; }return valzz;
	}
};
