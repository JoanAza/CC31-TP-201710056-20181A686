#pragma once
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

	CPaciente(string nombre, int edad, string genero)
		: nombre(nombre), edad(edad), genero(genero) {}

	string getNombre() { return nombre; }
	int getEdad() { return edad; }
	int getAislamiento() { return aislamiento; }
	string getGenero() { return genero; }
	string getEstado() { return estado; }

	void setEstado(string estado) { this->estado = estado; }
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

















#endif
