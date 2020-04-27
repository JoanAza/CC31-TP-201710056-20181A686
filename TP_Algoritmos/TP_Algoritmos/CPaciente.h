#ifndef __CPACIENTE_H__
#define __CPACIENTE_H__

#include <iostream>
#include <functional>
#include <vector>
#include <string>

using namespace std;




class CPaciente
{
	string nombre;
	int edad;
	string genero;
	string estado;
	int aislamiento;


public:

	CPaciente(string nombre, int edad, string genero, string estado, int aislamiento)
		: nombre(nombre), edad(edad), genero(genero), estado(estado), aislamiento(aislamiento) {}

	string getNombre() { return this->nombre; }
	int getEdad() { return this->edad; }
	int getAislamiento() { return this->aislamiento; }
	string getGenero() { return this->genero; }
	string getEstado() { return this->estado; }


	int setAislamiento(int _aislamiento) { this->aislamiento = _aislamiento;  return aislamiento; }



	string toString()
	{
		return this->nombre +
			"\n Edad:				" + to_string(this->edad) +
			"\n Genero:				" + getGenero() +
			"\n Estado:				" + getEstado() +
			"\n Tiempo Aislamiento: " + to_string(this->aislamiento);

	}

};


















#endif // !__CPACIENTE_H__
