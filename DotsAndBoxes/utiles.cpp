#include "utiles.h"

void imprimirCadena(string cadena) {
	cout << cadena << endl;;
}
string leerCadena() {
	string x;
	cout << "\t";
	getline(cin, x);
	return x;
}

string leerCadenaNoVacia() {
	string x;
	cout << "\t";
	getline(cin, x);
	while (x.empty() || (x[0] == ' ')) {
		cout << "Ingrese algo.." << endl;
		getline(cin, x);
	}
	return x;
}

string leerCadenaNoGetLine() {
	string x;
	cout << "\t";
	cin >> x;
	cin.clear();
	cin.ignore(1024, '\n');
	while (x.empty() || (x[0] == ' ')) {
		cout << "Ingrese algo.." << endl;
		cin >> x;
		cin.clear();
		cin.ignore(1024, '\n');
	}
	return x;
}


int leerEntero() {
	int n;
	while (true) {
		cout << "\t";
		if (cin >> n) {
			cin.clear();
			cin.ignore(1024, '\n');
			return n;
		}
		else {
			cerr << "\t Valor incorrecto.. " << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}

float leerFlotante() {
	float n;
	while (true) {
		cout << "\t";
		if (cin >> n) {
			cin.clear();
			cin.ignore(1024, '\n');
			return n;
		}
		else {
			cerr << "\t Valor incorrecto.. " << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}

char leerCaracter() {
	string line;
	char x;
	while (getline(cin, line) && (line.length() == 0 || line.length() > 1))
		cout << "Ingrese solo un caracter..." << endl;
	x = line[0];

	while ((isalpha(x) == 0)) {
		cout << "Dato invalido" << endl;
		while (getline(cin, line) && (line.length() == 0 || line.length() > 1))
			cout << "Ingrese solo un caracter..." << endl;
		x = line[0];
	}
	return x;
}

int leerSeleccion(int mayor) {
	int entrada = 0;
	while (true) {
		cout << "\t";
		if (cin >> entrada) {

			if (entrada <= mayor && entrada != 0) {
				cin.clear();
				cin.ignore(1024, '\n');
				return entrada;
			}
			else {
				cerr << "\t Valor incorrecto.. digite un numero entre 1 y " << mayor << endl;
				cin.clear();
				cin.ignore(1024, '\n');
			}
		}
		else {
			cerr << "\t Valor incorrecto.. digite un numero entre 1 y " << mayor << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}


int rangoCeroAN(int mayor) {
	int entrada = 0;
	while (true) {
		cout << "\t";
		if (cin >> entrada) {

			if (entrada <= mayor && entrada >= 0) {
				cin.clear();
				cin.ignore(1024, '\n');
				return entrada;
			}
			else {
				cerr << "\t Valor incorrecto.. digite un numero entre 0 y " << mayor << endl;
				cin.clear();
				cin.ignore(1024, '\n');
			}
		}
		else {
			cerr << "\t Valor incorrecto.. digite un numero entre 0 y " << mayor << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
	}
}

int numeroCodigo(string codigo) {
	string numero = "";
	int n = 0;
	int i;
	char caracter = ' ';
	int limite = (codigo.length());
	for (i = 2; i < limite; i++) {
		caracter = codigo[i];
		numero = numero + caracter;
		caracter = ' ';

	}

	n = stoi(numero);
	return n;
}

bool stringSix(string text)
{
	if (text.length() < 6)
	{
		return false;
	}
	return true;
}
bool stringUpperCase(string text)
{
	for (int i = 0; i < text.length(); i++)
	{
		if (isupper(text[i]))
		{
			return true;
		}
	}
	return false;
}
void limpiaPantalla() {
	system("cls");
}
string menuInicio() {
	stringstream s;
	s << endl;
	s << "\t ______________________________________________________________" << endl;
	s << "\t|                    Menu Principal                            |" << endl;
	s << "\t|______________________________________________________________|" << endl;
	s << "\t|[1].Jugar persona vrs persona                                 |" << endl;
	s << "\t|[2].Jugar persona vrs maquina                                 |" << endl;
	s << "\t|[3].Cargar Partida                                            |" << endl;
	s << "\t|[4].Salir                                                     |" << endl;
	s << "\t|______________________________________________________________|" << endl;
	return s.str();
}






int convertirInt(string s) {
	stringstream r(s);
	int v;
	r >> v;
	return v;
}

bool convertirBool(string s)
{
	if (s == "true")
	{
		return true;
	}
	else
	{
		return false;
	}
}

int mayorDeTresEnteros(int n1,int n2,int n3)
{
	if ((n1 >= n2) && (n1 >= n3))
		return n1;
	else if ((n2 >= n1) && (n2 >= n3))
		return  n2;
	else
		return  n3;
}