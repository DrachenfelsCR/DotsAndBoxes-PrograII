#include "interfaz.h"
#include "puntoCompuesto.h"
#include "puntoSimple.h"
#include "excepciones.h"

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
	excepcionEspecifica excepcion;
	try
	{
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
		imprimirCadena("Digite cuantos campos SeisPuntos (3x2) desea(maximo 7!):  ");
		tresXdos = leerEntero();
		if (tresXdos > 7)
		{
			throw excepcion;
		}
		imprimirCadena("Digite cuantos campos NuevePuntos (3x3) desea(maximo 4!):  ");
		tresXtres = leerEntero();
		if (tresXtres > 4)
		{
			throw excepcion;
		}
		imprimirCadena("Digite cuantos campos QuincePuntos  (3x5) desea(maximo 2!):  ");
		tresXcinco = leerEntero();
		if (tresXcinco > 2)
		{
			throw excepcion;
		}
		//---------------------------------------
		imprimirCadena("\n");
		imprimirCadena("Perfecto!!! \n");
		imprimirCadena("< digite enter >");
		//---------------------------------------
		puntoCompuesto* campodeJuego = crearCampoDeJuego(tresXdos, tresXtres, tresXcinco);
		//------------------------------------------
		cout << campodeJuego->toString();
	}
	catch (...)
	{
	imprimirCadena("Ha digitado un numero mayor a lo permitido");
	}
	
}

void interfaz::jugadorVrsMaquina()
{
	limpiaPantalla();
}

void interfaz::cargarPartida()
{
	limpiaPantalla();
}

puntoCompuesto* interfaz::crearCampoDeJuego(int tresXdos, int tresXtres, int tresXcinco)
{
	//--------------------------------------
	int columnas1 = 2 * tresXdos;
	int columnas2 = 3 * tresXtres;
	int columnas3 = 5 * tresXcinco;
	//--------------------------------------
	int filas1 = tresXdos;
	int filas2 = tresXtres;
	int filas3 = tresXcinco;
	//--------------------------------------
	int filasDefinitivas = filas1;
	int columnasDefinitivas = columnas1;
	//---------------------------------------
	puntoCompuesto* campoJuego = new puntoCompuesto(9, 14);

	for (int i = 0; i < filas1; i++)
	{
		for (int j = columnas1; j < 14; j++)
		{
			(campoJuego->getArreglo())[i][j] = nullptr;
		}
	}
	for (int i2 = 3; i2 < 6; i2++)
	{
		for (int j2 = columnas2; j2 < 14; j2++)
		{
			(campoJuego->getArreglo())[i2][j2] = nullptr;
		}

	}
	for (int i3 = 6; i3 < 9; i3++)
	{
		for (int j3 = columnas3; j3 < 14; j3++)
		{
			(campoJuego->getArreglo())[i3][j3] = nullptr;
		}

	}
	return campoJuego;
}
