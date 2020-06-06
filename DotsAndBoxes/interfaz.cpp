#include "interfaz.h"
interfaz::interfaz()
{
	opc = 0;
}

interfaz::~interfaz()
{
}

void interfaz::menuPrincipal()
{
	limpiaPantalla();
	opc = 0;
	int cont = 1;
	do
	{
		
		imprimirCadena(menuInicio());
		opc=leerSeleccion(4);
		switch (opc)
		{
		case 1:
			jugadorVrsPersona();
			imprimirCadena("<Enter>");
			cin.get();
			break;
		case 2:
			jugadorVrsMaquina();
			imprimirCadena("<Enter>");
			cin.get();
			break;
		case 3:
			cargarPartida();
			imprimirCadena("<Enter>");
			cin.get();
			break;
		case 4:
			exit(0);
			break;
		}
		imprimirCadena("\t [Digite 1 para seguir en el juego] o [2 para salir]: ");
		cont = leerSeleccion(2);
		limpiaPantalla();
		if (cont == 2) {
			menuPrincipal();
		}
	} while (cont == 1);
}

void interfaz::jugadorVrsPersona()
{
	limpiaPantalla();
}

void interfaz::jugadorVrsMaquina()

{
	limpiaPantalla();
}

void interfaz::cargarPartida()
{
	limpiaPantalla();
}
