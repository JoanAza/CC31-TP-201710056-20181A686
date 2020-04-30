#pragma once
#ifndef __CPACIENTE_H__
#define __CPACIENTE_H__

#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>


using namespace std;

class CPaciente
{
	string nombre;
	string p_apellido;
	int edad;
	string genero;
	string estado;
	int aislamiento;
	string enfermedad;


public:
	CPaciente(){}
	CPaciente(string nombre, string p_apellido, int edad, string genero, string estado, string enfermedad)
		: nombre(nombre), p_apellido(p_apellido), edad(edad), genero(genero), estado(estado), enfermedad(enfermedad) {}

	string getNombre() { return nombre; }
	string getApellido() { return p_apellido; }
	int getEdad() { return edad; }
	int getAislamiento() { return aislamiento; }
	string getGenero() { return genero; }
	string getEstado() { return estado; }
	string getEnfermedad() { return enfermedad; }

	int setAislamiento(int _aislamiento) { this->aislamiento = _aislamiento;  return aislamiento; }



	string Mostrar_Informacion()
	{
		return "\n\n Nombre:                         " + getNombre() +
			   "\n Apellido:                       " + getApellido() +
			   "\n Edad:                           " + to_string(this->edad) +
			   "\n Genero:                         " + getGenero() +
			   "\n Estado:                         " + getEstado() +
			   "\n Enfermedad pre-existente:       " + getEnfermedad() +
			   "\n Tiempo Aislamiento:             " + to_string(this->aislamiento);
	}
};

















#endif
