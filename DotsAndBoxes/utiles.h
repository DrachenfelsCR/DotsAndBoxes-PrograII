#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include <wchar.h>
#include <string>
#include <cctype>
#include <algorithm>
#include <locale.h>
using namespace std;

void imprimirCadena(string);
void limpiaPantalla();
int leerEntero();
float leerFlotante();
char leerCaracter();
int leerSeleccion(int);
int rangoCeroAN(int);
int letraCodigo(string);
void limpiaPantalla();
string leerCadena();
string leerCadenaNoVacia();
string leerCadenaNoGetLine();
string menuInicio();
bool stringSix(string);
bool stringUpperCase(string);
int convertirInt(string);
bool convertirBool(string);
int mayorDeTresEnteros(int,int,int);
