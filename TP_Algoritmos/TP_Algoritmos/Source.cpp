#include <stdlib.h>
#include "CCola.h"
#include "CLista.h"

#define AGREGAR 1
#define MOSTRAR 2
#define LISTAR 3
#define GUARDAR 4
#define CARGAR 5
#define SALIR 6

int opcion;
int status;
int edad;
string nombre;
string genero;
string enfermedad;
string apellido;
CCola* queue = new CCola();
CLista* mayorRiesgo = new CLista();
CLista* menorRiesgo = new CLista();

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


void Show_mayorriesgo()
{
	cout << "Pacientes en riesgo alto" << endl;
	mayorRiesgo->Mostrar();
}

void Show_menorriesgo()
{
	cout << "Pacientes en riesgo bajo" << endl;
	menorRiesgo->Mostrar();
}

void Add_Paciente()
{
	cout << endl << " INGRESE LA INFORMACION DEL PACIENTE" << endl << endl;
	cout << " Ingrese el NOMBRE del paciente: ";
	cin >> nombre;
	cout << " Ingrese el primer APELLIDO del paciente: ";
	cin >> apellido;
	cout << " Ingrese la EDAD del paciente: ";
	cin >> edad;
	cout << " Ingrese el GENERO del paciente: ";
	cin >> genero;
	cout << " Enfermedad pre-existente ? (SI o NO): ";
	cin >> enfermedad;
	for (int i = 0; i < enfermedad.length(); i++)
	{
		enfermedad[i] = toupper(enfermedad[i]);
	}

	CPaciente patient = CPaciente(nombre, apellido, edad, genero, Generar_estado(), enfermedad);
	queue->Push(patient);
	
	cout << " Paciente agregado correctamente!!!" << endl << endl;
}

void Show_pacientes()
{
	int cont = 1;
	CPaciente aux = CPaciente(nombre, apellido, edad, genero, Generar_estado(), enfermedad);
	while (!queue->is_empty())
	{
		aux = queue->Front();
		if (aux.getEstado() == "Positivo")
		{
			cout << " Paciente N " << cont << ". " << aux.Mostrar_Informacion() << endl << endl << endl;
			if (aux.getEdad() >= 50)
			{
				mayorRiesgo->Agregar(aux);
			}
			else if (aux.getEdad() < 50 && aux.getEnfermedad() == "SI")
			{
				mayorRiesgo->Agregar(aux);
			}
			else
			{
				menorRiesgo->Agregar(aux);
			}
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
	cout << " *   4. Guardar Informacion                                          *" << endl;
	cout << " *   5. Cargar Informacion                                           *" << endl;
	cout << " *   6. SALIR                                                        *" << endl;
	cout << " *                                                                   *" << endl;
	cout << " * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" << endl << endl;
	cout << " Ingrese una opcion: ";
	cin >> opcion;
	system("cls");
}

int main()
{
	Menu();

	while (opcion != 6)
	{
		switch (opcion)
		{
		case AGREGAR:
			char op;
			do
			{
				Add_Paciente();

				cout << " Desea agregar otro paciente ? (S para SI : N para NO)" << endl;
				cin >> op;
				op = toupper(op);
				system("cls");
			} while (op == 'S');
			break;

		case MOSTRAR:

			Show_pacientes();
			break;
		
		case LISTAR:
			int opc;
			cout << "Presione 1 para mostrar al GRUPO DE MAYOR RIESGO o 0 para mostrar al GRUPO DE MENOR RIESGO: ";
			cin >> opc;
			if (opc == 1)
			{	
				if (mayorRiesgo->is_empty())
				{
					cout << "No existen pacientes con riesgo alto";
				}
				else
				{
					Show_mayorriesgo();
				}
			}
			else
			{
				
				if (menorRiesgo->is_empty())
				{
					cout << "No existen pacientes con riesgo bajo";
				}
				else
				{
					Show_menorriesgo();
				}
			}
			break;

		case GUARDAR:
			mayorRiesgo->Guardar();
			menorRiesgo->Guardar();
			break;

		case CARGAR:
			/*string nombre;
			cout << "Nombre del archivo '.cs'  :\n";
			cin >> nombre;
			queue->Cargar(nombre);*/
			break;
		}
		Menu();
	}
	system("pause");
	return 0;
}