#include <iostream>
using namespace std;

class excepcion
{
public:
	excepcion();
	virtual ~excepcion() = 0;

private:
	string nombre;
};

excepcion::excepcion()
{
	this->nombre = "excepcion";
}

excepcion::~excepcion()
{
}



//--------------------------------------

class excepcionEspecifica : public excepcion
{
public:
	excepcionEspecifica();
	~excepcionEspecifica();
private:

};

excepcionEspecifica::excepcionEspecifica()
{
}

excepcionEspecifica::~excepcionEspecifica()
{
}

//----------------------------------------------

class excepcionSecundaria : public excepcion
{
public:
	excepcionSecundaria();
	~excepcionSecundaria();

private:

};

excepcionSecundaria::excepcionSecundaria()
{
}

excepcionSecundaria::~excepcionSecundaria()
{
}