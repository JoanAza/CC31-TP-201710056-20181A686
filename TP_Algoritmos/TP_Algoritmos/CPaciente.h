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
	string enfermedad;


public:

	CPaciente(string nombre, int edad, string genero, string estado, string enfermedad)
		: nombre(nombre), edad(edad), genero(genero), estado(estado), enfermedad(enfermedad) {}

	string getNombre() { return nombre; }
	int getEdad() { return edad; }
	int getAislamiento() { return aislamiento; }
	string getGenero() { return genero; }
	string getEstado() { return estado; }
	string getEnfermedad() { return enfermedad; }

	int setAislamiento(int _aislamiento) { this->aislamiento = _aislamiento;  return aislamiento; }



	string toString()
	{
		return "\n\n Nombre:                         " + getNombre() +
			   "\n Edad:                           " + to_string(this->edad) +
			   "\n Genero:                         " + getGenero() +
			   "\n Estado:                         " + getEstado() +
			   "\n Enfermedad pre-existente:       " + getEnfermedad() +
			   "\n Tiempo Aislamiento:             " + to_string(this->aislamiento);
	}
};

















#endif
