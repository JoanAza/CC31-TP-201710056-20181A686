#include <iostream>
#include <functional>
#include <stdlib.h>
#include "CCola.h"

#define AGREGAR 1
#define MOSTRAR 2
#define OBTENER 3
#define SALIR 4

int opcion;
string nombre;
string genero;
string estado;

int edad;
int aislamiento;
int status;

//template<typename T>
CCola* queue = new CCola();

bool Set_status()
{
	status = rand() % (1 - 0 + 1) + 0;

	if (status == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Add_Paciente()
{
	string sta1 = "positivo";
	string sta2 = "negativo";
	cout << endl << " INGRESE LA INFORMACION DEL PACIENTE" << endl << endl;
	cout << " Ingrese el nombre del paciente: ";
	cin >> nombre;
	cout << " Ingrese la edad del paciente: ";
	cin >> edad;
	cout << " Ingrese el genero del paciente: ";
	cin >> genero;

	CPaciente patient = CPaciente(nombre, edad, genero);
	queue->Push(patient);
	if (Set_status())
	{
		patient.setEstado(sta1);
	}
	else
	{
		patient.setEstado(sta2);
	}

	cout << " Paciente agregado correctamente!!!" << endl << endl;
}

void Show_cola()
{
	int cont = 1;
	CPaciente aux = CPaciente(nombre, edad, genero);
	while (!queue->is_empty())
	{
		aux = queue->Front();
		cout << " " << cont << ". " << aux.getNombre() << endl;
		queue->Pop();
		cont++;
	}
}

void Menu()
{
	cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl;
	cout << " *                                                                               *" << endl;
	cout << " *                                    MENU                                       *" << endl;
	cout << " *                                                                               *" << endl;
	cout << " *   1. Agregar nuevo paciente a la cola de espera                               *" << endl;
	cout << " *   2. Mostrar a los pacientes que se encuentran en la cola de espera           *" << endl;
	cout << " *   3. Obtener informacion de los pacientes que dieron positivo para COVID-19   *" << endl;
	cout << " *   4. SALIR                                                                    *" << endl;
	cout << " *                                                                               *" << endl;
	cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl << endl;
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

			Show_cola();

			break;
		}
		Menu();
	}

	system("pause");
	return 0;
}