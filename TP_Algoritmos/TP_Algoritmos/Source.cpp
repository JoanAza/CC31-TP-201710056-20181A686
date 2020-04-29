#include <iostream>
#include <functional>
#include <stdlib.h>
#include "CCola.h"

#define AGREGAR 1
#define MOSTRAR 2
#define LISTAR 3
#define SALIR 4

int opcion;
int status;
string nombre;
string genero;
string enfermedad;
int edad;

//template<typename T>
CCola* queue = new CCola();

auto Generar_estado = []()
{
	string sta1 = "Positivo";
	string sta2 = "Negativo";
	status = rand() % 10;
	if (status % 2 == 0)
	{
		return sta1;
	}
	else
	{
		return sta2;
	}
};

void Add_Paciente()
{
	cout << endl << " INGRESE LA INFORMACION DEL PACIENTE" << endl << endl;
	cout << " Ingrese el nombre del paciente: ";
	cin >> nombre;
	cout << " Ingrese la edad del paciente: ";
	cin >> edad;
	cout << " Ingrese el genero del paciente: ";
	cin >> genero;
	cout << " Enfermedad pre-existente: ";
	cin >> enfermedad;

	CPaciente patient = CPaciente(nombre, edad, genero, Generar_estado(), enfermedad);
	queue->Push(patient);
	
	cout << " Paciente agregado correctamente!!!" << endl << endl;
}

void Show_pacientes()
{
	int cont = 1;
	CPaciente aux = CPaciente(nombre, edad, genero, Generar_estado(), enfermedad);
	while (!queue->is_empty())
	{
		aux = queue->Front();
		if (aux.getEstado() == "Positivo")
		{
			cout << " Paciente N " << cont << ". " << aux.toString() << endl << endl << endl;
		}
		queue->Pop();
		cont++;
	}
}

void Menu()
{
	cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << " *                                                                   *" << endl;
	cout << " *                                    MENU                           *" << endl;
	cout << " *                                                                   *" << endl;
	cout << " *   1. Agregar nuevo paciente a la cola de espera                   *" << endl;
	cout << " *   2. Mostrar a los pacientes que dieron positivo para COVID-19    *" << endl;
	cout << " *   3. Listar a los pacientes por grupo de riesgo                   *" << endl;
	cout << " *   4. SALIR                                                        *" << endl;
	cout << " *                                                                   *" << endl;
	cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl << endl;
	cout << " Ingrese una opcion: ";
	cin >> opcion;
	system("cls");
}


int main()
{
	Menu();

	while (opcion != 4)
	{
		switch (opcion)
		{
		case AGREGAR:
			char op;
			do
			{
				Add_Paciente();

				cout << " Desea agregar otro paciente ? S para SI : N para NO" << endl;
				cin >> op;
				op = toupper(op);
				system("cls");
			} while (op == 'S');
			break;

		case MOSTRAR:

			Show_pacientes();
			break;
		}
		Menu();
	}

	system("pause");
	return 0;
}