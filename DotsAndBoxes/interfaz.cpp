#include "interfaz.h"
#include "puntoCompuesto.h"
#include "puntoSimple.h"
#include "excepciones.h"

interfaz::interfaz()
{
	opc = 0;
	this->campoJuegoC = nullptr;
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
	stringstream NombrePartida;
	int id1 = 1;
	int id2 = 2;
	int tresXdos = 0;
	int tresXtres = 0;
	int tresXcinco = 0;
	excepcionEspecifica excepcion;
	excepcionSecundaria execepcionSe;
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
		NombrePartida << nombre1 << " vs " << nombre2;
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
		if (tresXdos == 0 && tresXtres == 0 && tresXcinco == 0)
		{
			throw execepcionSe;
		}
		//---------------------------------------
		imprimirCadena("\n");
		imprimirCadena("Perfecto!!! \n");
		imprimirCadena("< digite enter >");
		cin.get();
		limpiaPantalla();
		//---------------------------------------
		this->campoJuegoC = crearCampoDeJuego(tresXdos, tresXtres, tresXcinco);
		this->campoJuegoC->setColumnas(tresXdos, tresXtres, tresXcinco);
		this->campoJuegoC->setNombre(NombrePartida.str());
		int mayor = mayorDeTresEnteros(2*tresXdos, 3*tresXtres, 5*tresXcinco);
		//------------------------------------------
		this->campoJuegoC->setMayor(mayor);
		this->campoJuegoC->setJugador1(player1);
		this->campoJuegoC->setJugador2(player2);
		mostrarCampo(mayor, this->campoJuegoC);
		//------EMPIEZA TURNO-------------
		turnoDeJuego(player1,player2, mayor, this->campoJuegoC);
	}
	catch (excepcionEspecifica)
	{
	imprimirCadena("Ha digitado un numero mayor a lo permitido");
	}
	catch (excepcionSecundaria)
	{
		imprimirCadena("Si solo digita ceros, entonces no existira campo de juego!");
	}
	
}

void interfaz::jugadorVrsMaquina()
{
	limpiaPantalla();
	string nombre1;
	string nombre2 = "Maqui";
	stringstream NombrePartida;
	int id1 = 1;
	int id2 = 2;
	int tresXdos = 0;
	int tresXtres = 0;
	int tresXcinco = 0;
	excepcionEspecifica excepcion;
	excepcionSecundaria execepcionSe;
	try
	{
		//---------------------------------------
		imprimirCadena("Nombre del Jugador : ");
		nombre1 = leerCadena();
		cout << "Identificador del primer jugador :" << id1;
		imprimirCadena("\n");
		jugador* player1 = new jugador(nombre1, id1);
		//---------------------------------------
		
		cout << "Identificador de la Maquina :" << id2;
		imprimirCadena("\n");
		Maquina* player2 = new Maquina(nombre2,id2);
		//---------------------------------------
		NombrePartida << nombre1 << " vs " << nombre2;
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
		if (tresXdos == 0 && tresXtres == 0 && tresXcinco == 0)
		{
			throw execepcionSe;
		}
		//---------------------------------------
		imprimirCadena("\n");
		imprimirCadena("Perfecto!!! \n");
		imprimirCadena("< digite enter >");
		cin.get();
		imprimirCadena("Digite la estrategia deseada para la maquina: ");
		imprimirCadena("1)Juego aleatorio");
		imprimirCadena("2)Juega  cercano");
		imprimirCadena("3)Juego periférico");
		imprimirCadena("4)Juego central");
		imprimirCadena("5)Juego islas");
		opc = leerSeleccion(5);
		Estrategia* estAleatorio = new juegoAletorio();
		Estrategia* estCentral= new juegoCentral();
		Estrategia* estCercano = new juegoCercano();
		Estrategia* estIslas = new juegoIslas();
		Estrategia* estPeriferico = new juegoPeriferico();
		switch (opc)
		{
		case 1:
			player2->setStrategy(estAleatorio);
			break;
		case 2:
			player2->setStrategy(estCercano);
			break;
		case 3:
			player2->setStrategy(estPeriferico);
			break;
		case 4:
			player2->setStrategy(estCentral);
			break;
		case 5:
			player2->setStrategy(estIslas);
			break;
		}
		limpiaPantalla();
		//---------------------------------------
		this->campoJuegoC = crearCampoDeJuego(tresXdos, tresXtres, tresXcinco);
		this->campoJuegoC->setColumnas(tresXdos, tresXtres, tresXcinco);
		this->campoJuegoC->setNombre(NombrePartida.str());
		int mayor = mayorDeTresEnteros(2 * tresXdos, 3 * tresXtres, 5 * tresXcinco);
		//------------------------------------------
		this->campoJuegoC->setMayor(mayor);
		this->campoJuegoC->setJugador1(player1);
		this->campoJuegoC->setJugador2(player2);

		mostrarCampo(mayor, this->campoJuegoC);
		//------EMPIEZA TURNO-------------
		turnoDeJuegovsMaquina(player1, player2, mayor, this->campoJuegoC);
	}
	catch (excepcionEspecifica)
	{
		imprimirCadena("Ha digitado un numero mayor a lo permitido");
	}
	catch (excepcionSecundaria)
	{
		imprimirCadena("Si solo digita ceros, entonces no existira campo de juego!");
	}
}

void interfaz::cargarPartida()
{
	limpiaPantalla();
	excepcionEspecifica falloVacio;
	string nombreJ1;
	string nombreJ2;
	int mayor;
	//------
	int columna1;
	int columna2;
	int columna3;
	int* ptrColumna1 = &columna1;
	int* ptrColumna2 = &columna2;
	int* ptrColumna3 = &columna3;
	//------
	string* ptrNombreJ1=  &nombreJ1;
	string* ptrNombreJ2 = &nombreJ2;
	int* ptrMayor = &mayor;
	int contador = 0;
	try
	{
		string* nombrePartidas = new string[20];
		for (int i = 0; i < 20; i++)
		{
			nombrePartidas[i] = "";
		}
		analizador analiza;
		int seleccion = 0;
		analiza.recuperarNombrePartidas("PartidasJugadas.txt", nombrePartidas, ptrNombreJ1, ptrNombreJ2, ptrMayor, ptrColumna1, ptrColumna2, ptrColumna3);
		for (int i = 0; i < 20; i++)
		{
			if (nombrePartidas[i] != "")
			{
				cout << i + 1 << ". " << nombrePartidas[i] << endl;
				contador++;
			}	
			else 
			{
				break;
			}
		}
		if (contador == 0)
		{
			throw falloVacio;
		}
		imprimirCadena("Escriba el numero de partida que quiere cargar");
		seleccion = leerSeleccion(contador);
		stringstream partidaCargar;
		partidaCargar << "archivos/"<<nombrePartidas[seleccion - 1] << ".txt";
		//-------------------------------------------------------------

		//-------------------------------------------
		this->campoJuegoC = new puntoCompuesto(9, 14);
		jugador* jugadorN1 = new jugador(nombreJ1,1);
		jugador* jugadorN2 = new jugador(nombreJ2, 2);
		this->campoJuegoC->setJugador1(jugadorN1);
		this->campoJuegoC->setJugador2(jugadorN2);
		this->campoJuegoC->setColumnas(columna1, columna2, columna3);
		analiza.recuperarCampoJuego(this->campoJuegoC, partidaCargar.str(), jugadorN1, jugadorN2);
		//--------------------------------------------------------------------
		this->campoJuegoC->setFilasM();
		mostrarCampo(mayor, this->campoJuegoC);
		turnoDeJuego(jugadorN1, jugadorN2, mayor, this->campoJuegoC);
	}
	catch (excepcionEspecifica)
	{
		imprimirCadena("No hay partidas guardadas");
	}
}

puntoCompuesto* interfaz::crearCampoDeJuego(int tresXdos, int tresXtres, int tresXcinco)
{
	//--------------------------------------
	int columnas1 = 2 * tresXdos;
	int columnas2 = 3 * tresXtres;
	int columnas3 = 5 * tresXcinco;
	//--------------------------------------
	int filas1 = 3;
	int filas2 = 6;
	int filas3 = 9;
	//--------------------------------------
	puntoCompuesto* campoJuego = new puntoCompuesto(9, 14);
	campoJuego->setColumnas(tresXdos,tresXtres,tresXcinco);
	//////////////////////////////////////////////////////////////////////
	if (tresXdos == 0)
	{
		for (int i2 = 0; i2 < 3; i2++)
		{
			for (int j2 = columnas2; j2 < 14; j2++)
			{
				(campoJuego->getArreglo())[i2][j2] = nullptr;
			}

		}
		for (int i3 = 3; i3 < 6; i3++)
		{
			for (int j3 = columnas3; j3 < 14; j3++)
			{
				(campoJuego->getArreglo())[i3][j3] = nullptr;
			}
		}
		for (int i = 6; i < 9; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				(campoJuego->getArreglo())[i][j] = nullptr;
			}
		}
	}
	else if (tresXtres == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = columnas1; j < 14; j++)
			{
				(campoJuego->getArreglo())[i][j] = nullptr;
			}
		}
		for (int i3 = 3; i3 < 6; i3++)
		{
			for (int j3 = columnas3; j3 < 14; j3++)
			{
				(campoJuego->getArreglo())[i3][j3] = nullptr;
			}

		}
		for (int ii = 6; ii < 9; ii++)
		{
			for (int jj = 0; jj < 14; jj++)
			{
				(campoJuego->getArreglo())[ii][jj] = nullptr;
			}
		}
	}
	else if (tresXcinco == 0)
	{
		for (int i = 0; i < 3; i++)
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
			for (int j3 = 0; j3 < 14; j3++)
			{
				(campoJuego->getArreglo())[i3][j3] = nullptr;
			}
		}
	}
	//////////////////////////////////////////////////////////////////////
	else if (tresXdos == 0 && tresXtres == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = columnas3; j < 14; j++)
			{
				(campoJuego->getArreglo())[i][j] = nullptr;
			}
		}
		for (int i = 3; i < 9; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				(campoJuego->getArreglo())[i][j] = nullptr;
			}
		}
	}
	else if (tresXdos == 0 && tresXcinco == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = columnas2; j < 14; j++)
			{
				(campoJuego->getArreglo())[i][j] = nullptr;
			}
		}
		for (int i = 3; i < 9; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				(campoJuego->getArreglo())[i][j] = nullptr;
			}
		}
	}
	else if (tresXtres == 0 && tresXcinco == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = columnas1; j < 14; j++)
			{
				(campoJuego->getArreglo())[i][j] = nullptr;
			}
		}
		for (int i = 3; i < 9; i++)
		{
			for (int j = 0; j < 14; j++)
			{
				(campoJuego->getArreglo())[i][j] = nullptr;
			}
		}
	}
	else
	{
		for (int i = 0; i < 3; i++)
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
		

	}

	campoJuego->setFilasM();
	return campoJuego;
}

void interfaz::turnoDeJuego(jugador* p1, jugador* p2, int columnasMax, puntoCompuesto* campoJ)
{
	int turnos = 0;
	excepcionEspecifica excep;
	try
	{
		int maxPlays = campoJ->jugadasMaximas();
		while (maxPlays != turnos)
		{
			//------------TURNO JUGADOR 1---------------
			turnoJugador(p1, columnasMax, campoJ);
			limpiaPantalla();
			mostrarCampo(columnasMax, campoJ);
			turnos++;
			if (campoJ->jugadasMaximas() == turnos)
			{
				break;
			}
			//-----------TURNO JUGADOR----------------
			turnoJugador(p2, columnasMax, campoJ);
			limpiaPantalla();
			mostrarCampo(columnasMax, campoJ);
			turnos++;
			//------------------------------------------
		}
		//---------------------------------------
		campoJ->guardarNombre("PartidasJugadas.txt");
		stringstream r;
		r << "archivos/" << campoJ->getNombre() <<".txt";
		campoJ->guardar(r.str());
	}
	catch (...)
	{
	}
	
}
void interfaz::turnoDeJuegovsMaquina(jugador* p, Maquina* m,int columnasMax,puntoCompuesto* campoJ)
{
	int turnos = 0;
	excepcionEspecifica excep;
	try
	{
		int maxPlays = campoJ->jugadasMaximas();

		while (maxPlays != turnos)
		{
			//------------TURNO JUGADOR 1---------------
			turnoJugador(p, columnasMax, campoJ);
			limpiaPantalla();
			mostrarCampo(columnasMax, campoJ);
			turnos++;
			if (campoJ->jugadasMaximas() == turnos)
			{
				break;
			}
			//-----------TURNO MAQUINA----------------
			m->getStrategy()->jugar(campoJ,m);
			puntoSimple* pOrigen = m->getStrategy()->getPuntoOrigen();
			puntoSimple* pDestino = m->getStrategy()->getPuntoDestino();
			verificaPunto(pOrigen, campoJ->getFilasM(), campoJ->getcolumna1() * 2 , campoJ->getcolumna2() * 3, campoJ->getcolumna3() * 5);
			verificaPunto(pDestino, campoJ->getFilasM(), campoJ->getcolumna1() * 2, campoJ->getcolumna2() * 3, campoJ->getcolumna3() * 5);
			limpiaPantalla();
			mostrarCampo(columnasMax, campoJ);
			turnos++;
			//------------------------------------------
		}
		//---------------------------------------
		campoJ->guardarNombre("PartidasJugadas.txt");
		stringstream r;
		r << "archivos/" << campoJ->getNombre() << ".txt";
		campoJ->guardar(r.str());
	}
	catch (...)
	{
	}
}
void interfaz::turnoJugador(jugador* p,  int columnasMax, puntoCompuesto* campoJ)
{
	puntoSimple* puntoOrigen = nullptr;
	puntoSimple* puntoDestino = nullptr;
	bool movimientoIlegal = false;
			cout << "Turno de Jugador " << p->getNombre() << endl;
			int fila = 0;
			int columna = 0;
			imprimirCadena("Punto de origen, fila: ");
			fila = rangoCeroAN(9);
			imprimirCadena("Punto de origen, columna: ");
			columna = rangoCeroAN(columnasMax);
			puntoOrigen = campoJ->buscar(fila, columna);
			if (puntoOrigen->getConquistado())
			{
				puntoOrigen = nullptr;
			}
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
				cout << "Turno de Jugador " << p->getNombre() << endl;
				int fila = 0;
				int columna = 0;
				imprimirCadena("Punto de origen, fila: ");
				fila = rangoCeroAN(9);
				imprimirCadena("Punto de origen, columna: ");
				columna = rangoCeroAN(columnasMax);
				puntoSimple* puntoOrigen = campoJ->buscar(fila, columna);
				//----------------------------------------------------
				if (puntoOrigen->getConquistado())
				{
					puntoOrigen = nullptr;
				}
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
				fila2 = rangoCeroAN(9);
				imprimirCadena("Punto de destino, columna: ");
				columna2 = rangoCeroAN(columnasMax);
			}
			puntoDestino = campoJ->buscar(fila2, columna2);
			campoJ->setUltimafil(fila2);
			campoJ->setUltimaCol(columna2);
			//---------------------------------------------
			if (fila2 > fila)
			{
				if ((puntoOrigen->checkAbajo() && puntoDestino->checkArriba()) || (puntoOrigen->getConquistado() == true || puntoDestino->getConquistado() == true))
				{
					movimientoIlegal = true;
				}
				else
					movimientoIlegal = false;

			}
			else if (fila2 < fila)
			{
				if ((puntoOrigen->checkArriba() && puntoDestino->checkAbajo()) || (puntoOrigen->getConquistado() == true || puntoDestino->getConquistado() == true))
				{
					movimientoIlegal = true;
				}
				else
					movimientoIlegal = false;
			}
			else if (columna2 > columna)
			{
				if ((puntoOrigen->checkDerecha() && puntoDestino->checkIzq()) || (puntoOrigen->getConquistado() == true || puntoDestino->getConquistado() == true))
				{
					movimientoIlegal = true;
				}
				else
					movimientoIlegal = false;
			}
			else if (columna2 < columna)
			{
				if ((puntoOrigen->checkIzq() && puntoDestino->checkDerecha()) || (puntoOrigen->getConquistado() == true || puntoDestino->getConquistado() == true))
				{
					movimientoIlegal = true;
				}
				else
					movimientoIlegal = false;
			}
			// ------------VERIFICA QUE EL PUNTO DE DESTINO NO SEA NULO
			while ((puntoDestino == nullptr) || movimientoIlegal == true ||((puntoDestino->getX() == puntoOrigen->getX()) && (puntoDestino->getY() == puntoOrigen->getY())))
			{
				//----------------------------------------------------
				imprimirCadena("Este punto no esta disponible, trate otra coordenada");
				imprimirCadena("< digite enter >");
				cin.get();
				limpiaPantalla();
				mostrarCampo(columnasMax, campoJ);
				//----------------------------------------------------
				cout << "Turno de Jugador " << p->getNombre() << endl;
				//int fila2 = 0;
				//int columna2 = 0;
				imprimirCadena("Punto de destino, fila: ");
				fila2 = rangoCeroAN(9);
				imprimirCadena("Punto de destino, columna: ");
				columna2 = rangoCeroAN(columnasMax);
				puntoDestino = campoJ->buscar(fila2, columna2);
				//----------------------------------------------------
				if (fila2 > fila)
				{
					if ((puntoOrigen->checkAbajo() && puntoDestino->checkArriba()) || (puntoOrigen->getConquistado() == true || puntoDestino->getConquistado() == true))
					{
						movimientoIlegal = true;
					}
					else
						movimientoIlegal = false;

				}
				else if (fila2 < fila)
				{
					if ((puntoOrigen->checkArriba() && puntoDestino->checkAbajo()) || (puntoOrigen->getConquistado() == true || puntoDestino->getConquistado() == true))
					{
						movimientoIlegal = true;
					}
					else
						movimientoIlegal = false;
				}
				else if (columna2 > columna)
				{
					if ((puntoOrigen->checkDerecha() && puntoDestino->checkIzq()) || (puntoOrigen->getConquistado() == true || puntoDestino->getConquistado() == true))
					{
						movimientoIlegal = true;
					}
					else
						movimientoIlegal = false;
				}
				else if (columna2 < columna)
				{
					if ((puntoOrigen->checkIzq() && puntoDestino->checkDerecha()) || (puntoOrigen->getConquistado() == true || puntoDestino->getConquistado() == true))
					{
						movimientoIlegal = true;
					}
					else
						movimientoIlegal = false;
				}
			}
			//---------------------------
			puntoOrigen->setJugador(p);
			puntoDestino->setJugador(p);
			//-----FIN DE VERIFICACION DEL PUNTO DE DESTINO NULO
			if (fila2 > fila)
			{
				puntoOrigen->setAbajo(true);
				puntoDestino->setArriba(true);
				campoJ->movimientoAbajo(fila2, columna2, p);
				
			}
			else if (fila2 < fila)
			{
				puntoOrigen->setArriba(true);
				puntoDestino->setAbajo(true);
				campoJ->movimientoArriba(fila2, columna2, p);
			}
			else if (columna2 > columna)
			{
				puntoOrigen->setDerecha(true);
				puntoDestino->setIzquierda(true);
				campoJ->movimientoDerecha(fila2, columna2, p);

			}
			else if (columna2 < columna)
			{
				puntoOrigen->setIzquierda(true);
				puntoDestino->setDerecha(true);
				campoJ->movimientoIzquierda(fila2, columna2, p);
			}
			verificaPunto(puntoOrigen, campoJ->getFilasM(), campoJ->getcolumna1() * 2, campoJ->getcolumna2() * 3, campoJ->getcolumna3() * 5);
			verificaPunto(puntoDestino, campoJ->getFilasM(), campoJ->getcolumna1() * 2, campoJ->getcolumna2() * 3, campoJ->getcolumna3() * 5);
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

void interfaz::verificaPunto(puntoSimple* punto, int filasMax, int cols1, int cols2, int cols3)
{	
	//verifica cual columna esta vacia
	int columna1 = (columna1Maxima(cols1, cols2, cols3)) - 1; 
	int columna2 = (columna2Maxima(cols1, cols2, cols3)) - 1;
	int column3 = (columna3Maxima(cols1, cols2, cols3)) - 1;
	int puntoInferiorDerecho = column3;
	int puntSupDerecho = columna1;
	//----------------------------------
	// verifica si es esquina superior izquierda
	if ((punto->getY() == 0) && (punto->getX() == 0))
	{
		if (punto->checkAbajo() == true && punto->checkDerecha() == true)
		{
			punto->setConquistado(true);
		}
	}
	// verifica si es esquina superior derecha
	else if ((punto->getY() == 0) && (punto->getX() == puntSupDerecho))
	{
		if (punto->checkAbajo() == true && punto->checkIzq() == true)
		{
			punto->setConquistado(true);
		}

	}
	// verifica si es esquina inferior izquierda
	else if ((punto->getY() == filasMax) && (punto->getX() == 0))
	{
		if (punto->checkArriba() == true && punto->checkDerecha() == true)
		{
			punto->setConquistado(true);
		}
	}
	// verifica si es esquina inferior derecha
	else if ((punto->getY() == filasMax) && (punto->getX() == puntoInferiorDerecho))
	{
		if (punto->checkArriba() == true && punto->checkIzq() == true)
		{
			punto->setConquistado(true);
		}
	}
	// verifica si esta en la fila 0 pero no en las esquinas
	else if ((punto->getY() == 0) && (punto->getX() > 0 && punto->getX() < puntSupDerecho))
	{
		if (punto->checkDerecha() == true && punto->checkIzq() == true && punto->checkAbajo())
		{
			punto->setConquistado(true);
		}
	}
	// verifica si esta en fila final pero no en la esquinas
	else if ((punto->getY() == 0) && (punto->getX() > 0 && punto->getX() < puntSupDerecho))
	{
		if (punto->checkDerecha() == true && punto->checkIzq() == true && punto->checkAbajo())
		{
			punto->setConquistado(true);
		}
	}
	//verifica si esta en el borde izquierdo excepto la fila 0 y fila final
	else if ((punto->getX() == 0) && ((punto->getY() != 0 && punto->getY() != filasMax)))
	{
		if (punto->checkDerecha() == true && punto->checkArriba() == true && punto->checkAbajo() == true)
		{
			punto->setConquistado(true);
		}
	}
	//verifica si esta en el borde derecho filas 0 a 3
	else if ((punto->getY() >= 0 && punto->getY() < 3) && (punto->getX() == columna1))
	{
		if (punto->checkIzq() == true && punto->checkArriba() == true && punto->checkAbajo() == true)
		{
			punto->setConquistado(true);
		}
	}
	// verifica si esta en el borde derecho filas 3 a 6
	else if ((punto->getY() >= 3 && punto->getY() < 6) && (punto->getX() == columna2))
	{
		if (columna1 < columna2)
		{
			if (punto->checkIzq() == true && punto->checkAbajo() == true)
			{
				punto->setConquistado(true);
			}
		}
		else if (punto->checkIzq() == true && punto->checkArriba() == true && punto->checkAbajo() == true)
		{
			punto->setConquistado(true);
		}
	}
	// verifica si esta en el borde derecho filas 6 a 9 menos la 9
	else if ((punto->getY() >= 6 && punto->getY() < 9) && (punto->getX() == column3))
	{
		if (columna2 < column3 && punto->getY() == 6)
		{
			if (punto->checkIzq() == true && punto->checkAbajo() == true)
			{
				punto->setConquistado(true);
			}
		}
		else if (punto->checkIzq() == true && punto->checkArriba() == true && punto->checkAbajo() == true)
		{
			punto->setConquistado(true);
		}
	}
	else
	{
		if (punto->checkIzq() == true && punto->checkArriba() == true && punto->checkAbajo() == true && punto->checkDerecha() == true)
		{
			punto->setConquistado(true);
		}
	}
}

int interfaz::columna1Maxima(int col1, int col2, int col3)
{
	if (col1 == 0)
	{
		if (col2 == 0)
		{
			return col3;
		}
		return col2;
	}
	else
	{
		return col1;
	}
}

int interfaz::columna2Maxima(int col1, int col2, int col3)
{
	if (col2 == 0)
	{
		if (col1 == 0)
		{
			return col3;
		}
		return col1;
	}
	else
	{
		return col2;
	}
}

int interfaz::columna3Maxima(int col1, int col2, int col3)
{
	if (col3 == 0)
	{
		if (col2 == 0)
		{
			return col1;
		}
		return col2;
	}
	else
	{
		return col3;
	}
}
