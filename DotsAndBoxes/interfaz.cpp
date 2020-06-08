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
		jugador* player1 = new jugador(nombre1,id1);
		//---------------------------------------
		imprimirCadena("Nombre del segundo jugador : ");
		nombre2 = leerCadena();
		cout << "Identificador del segundo jugador :" << id2;
		imprimirCadena("\n");
		jugador* player2 = new jugador(nombre2, id2);
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
		cin.get();
		limpiaPantalla();
		//---------------------------------------
		puntoCompuesto* campodeJuego = crearCampoDeJuego(tresXdos, tresXtres, tresXcinco);
		int mayor = mayorDeTresEnteros(2*tresXdos, 3*tresXtres, 5*tresXcinco);
		//------------------------------------------
		mostrarCampo(mayor,campodeJuego);
		//------EMPIEZA TURNO-------------
		turnoDeJuego(player1,player2, mayor, campodeJuego);
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

void interfaz::turnoDeJuego(jugador* p1, jugador* p2, int columnasMax, puntoCompuesto* campoJ)
{
	int turnos = 5;
	int turnoActual = 0;
	excepcionEspecifica excep;
	try
	{
		while (turnos != 0)
		{
			//------------TURNO JUGADOR 1---------------
			turnoJugador(p1, columnasMax, campoJ);
			limpiaPantalla();
			mostrarCampo(columnasMax, campoJ);
			//-----------TURNO JUGADOR 2----------------
			turnoJugador(p2, columnasMax, campoJ);
			limpiaPantalla();
			mostrarCampo(columnasMax, campoJ);
			//------------------------------------------
			turnos--;
		}
	}
	catch (...)
	{
	}
	
}
void interfaz::turnoJugador(jugador* p1,  int columnasMax, puntoCompuesto* campoJ)
{
			cout << "Turno de Jugador " << p1->getNombre() << endl;
			int fila = 0;
			int columna = 0;
			imprimirCadena("Punto de origen, fila: ");
			fila = rangoCeroAN(9);
			imprimirCadena("Punto de origen, columna: ");
			columna = rangoCeroAN(columnasMax);
			puntoSimple* puntoOrigen = campoJ->buscar(fila, columna);
			//------------VERIFICA QUE EL PUNTO DE ORIGEN NO SEA NULO
			while (puntoOrigen == nullptr)
			{
				//----------------------------------------------------
				imprimirCadena("Este punto no esta disponible, trate otra coordenada");
				imprimirCadena("< digite enter >");
				cin.get();
				limpiaPantalla();
				mostrarCampo(columnasMax, campoJ);
				//----------------------------------------------------
				cout << "Turno de Jugador " << p1->getNombre() << endl;
				int fila = 0;
				int columna = 0;
				imprimirCadena("Punto de origen, fila: ");
				fila = rangoCeroAN(9);
				imprimirCadena("Punto de origen, columna: ");
				columna = rangoCeroAN(columnasMax);
				puntoSimple* puntoOrigen = campoJ->buscar(fila, columna);
				//----------------------------------------------------
			}
			//-----FIN DE VERIFICACION DEL PUNTO DE ORIGEN NULO
			imprimirCadena("Punto de destino, fila: ");
			int fila2 = rangoCeroAN(9);
			imprimirCadena("Punto de destino, columna: ");
			int columna2 = rangoCeroAN(columnasMax);
			//-------------------------------------------------------------
			while ((fila2 >= fila + 2) || (fila2 <= fila - 2) || (columna2 >= columna + 2) || (columna2 <= columna - 2))
			{
				imprimirCadena("Este punto no esta disponible, utilice solo puntos adyacentes entre si");
				imprimirCadena("Punto de destino, fila: ");
				int fila2 = rangoCeroAN(9);
				imprimirCadena("Punto de destino, columna: ");
				int columna2 = rangoCeroAN(columnasMax);
			}
			puntoSimple* puntoDestino = campoJ->buscar(fila2, columna2);
			// ------------VERIFICA QUE EL PUNTO DE DESTINO NO SEA NULO
			while ((puntoDestino == nullptr) || ((puntoDestino->getX() == puntoOrigen->getX()) && (puntoDestino->getY() == puntoOrigen->getY())))
			{
				//----------------------------------------------------
				imprimirCadena("Este punto no esta disponible, trate otra coordenada");
				imprimirCadena("< digite enter >");
				cin.get();
				limpiaPantalla();
				mostrarCampo(columnasMax, campoJ);
				//----------------------------------------------------
				cout << "Turno de Jugador " << p1->getNombre() << endl;
				int fila = 0;
				int columna = 0;
				imprimirCadena("Punto de destino, fila: ");
				fila = rangoCeroAN(9);
				imprimirCadena("Punto de destino, columna: ");
				columna = rangoCeroAN(columnasMax);
				puntoSimple* puntoOrigen = campoJ->buscar(fila, columna);
				//----------------------------------------------------
			}
			//-----FIN DE VERIFICACION DEL PUNTO DE DESTINO NULO
			if (fila2 > fila)
			{
				puntoOrigen->setAbajo(true);
				puntoDestino->setArriba(true);
			}
			else if (fila2 < fila)
			{
				puntoOrigen->setArriba(true);
				puntoDestino->setAbajo(true);
			}
			else if (columna2 > columna)
			{
				puntoOrigen->setDerecha(true);
				puntoDestino->setIzquierda(true);
			}
			else if (columna2 < columna)
			{
				puntoOrigen->setIzquierda(true);
				puntoDestino->setDerecha(true);
			}
			imprimirCadena("< digite enter >");
			cin.get();
}

void interfaz::mostrarCampo(int mayor, puntoCompuesto* campodeJuego)
{
	stringstream s;
	s << "\t";
	for (int i = 0; i < mayor; i++)
	{
		s << i << "\t";
	}
	s << endl;
	s << "\t";
	for (int i = 0; i < mayor - 1; i++)
	{
		s << "---------";
	}
	cout << s.str() << endl;
	cout << campodeJuego->toString();
}
