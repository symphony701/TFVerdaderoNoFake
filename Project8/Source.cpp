#include "PaginaInicio.h"
#include "Menuxd.h"
#include "Instrucciones.h"
#include "Dificultad.h"
#include <cstdlib>
#include <time.h>
using namespace Project8;
int main() {
	srand(time(NULL));
	Application::Run(gcnew Menuxd());
	return 0;
}
