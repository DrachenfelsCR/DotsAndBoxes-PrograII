#include "interfaz.h"
#include "puntoCompuesto.h"
#include "puntoSimple.h"
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
	string nombre1;
	string nombre2;
	int id1 = 1;
	int id2 = 2;
	int tresXdos = 0;
	int tresXtres = 0;
	int tresXcinco = 0;
	//---------------------------------------
	imprimirCadena("Nombre del primer jugador : ");
	nombre1 = leerCadena();
	cout << "Identificador del primer jugador :" << id1;
	imprimirCadena("\n");
	//---------------------------------------
	imprimirCadena("Nombre del segundo jugador : ");
	nombre1 = leerCadena();
	cout << "Identificador del segundo jugador :" << id2;
	imprimirCadena("\n");
	//---------------------------------------
	imprimirCadena("Digite cuantos campos SeisPuntos (3x2) desea:  ");
	tresXdos = leerEntero();
	imprimirCadena("Digite cuantos campos NuevePuntos  (3x3) desea:  ");
	tresXtres = leerEntero();
	imprimirCadena("Digite cuantos campos QuincePuntos  (3x5) desea:  ");
	tresXcinco = leerEntero();
	//---------------------------------------
	imprimirCadena("\n");
	imprimirCadena("Perfecto!!! \n");
	imprimirCadena("< digite enter >");
	//---------------------------------------
	crearCampoDeJuego(tresXdos, tresXtres, tresXcinco);
}

void interfaz::jugadorVrsMaquina()
{
	limpiaPantalla();
}

void interfaz::cargarPartida()
{
	limpiaPantalla();
}

void interfaz::crearCampoDeJuego(int tresXdos, int tresXtres, int tresXcinco)
{
	
	//--------------------------------------
	int columnas1 = 2 * tresXdos;
	int columnas2 = 3 * tresXtres;
	int columnas3 = 5 * tresXcinco;
	//--------------------------------------
	int filas1 = 3 * tresXdos;
	int filas2 = 3 * tresXtres;
	int filas3 = 3 * tresXcinco;
	//--------------------------------------
	int filasDefinitivas = filas1;
	int columnasDefinitivas = columnas1;
	//--------------------------------------

	//----------------------------------------
	puntoCompuesto* campoJuego = new puntoCompuesto(filas1, columnas1);


}

