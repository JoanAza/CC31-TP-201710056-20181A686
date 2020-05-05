//#include <stdlib.h>
#include <conio.h>
#include "CCola.h"
#include "CLista.h"

#define AGREGAR 1
#define MOSTRAR 2
#define LISTAR 3
#define GUARDAR 4
#define CARGAR 5
#define SALIR 6

int opcionMenu;
int status;
int edad;
string nombre;
string genero;
string enfermedad;
string apellido;
string estado;
string archivo1 = "Mayor_Riesgo.txt";
string archivo2 = "Menor_Riesgo.txt";
string eliminarApellido;
CCola<CPaciente>* queue = new CCola<CPaciente>();
CLista<CPaciente>* mayorRiesgo = new CLista<CPaciente>();
CLista<CPaciente>* menorRiesgo = new CLista<CPaciente>();



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
	mayorRiesgo->Mostrar<void>();
}

void Show_menorriesgo()
{
	cout << "Pacientes en riesgo bajo" << endl;
	menorRiesgo->Mostrar<void>();
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
	queue->Push<void>(patient);
	
	cout << " Paciente agregado correctamente!!!" << endl << endl;
}

void Show_pacientes()
{
	int cont = 1;
	CPaciente aux = CPaciente(nombre, apellido, edad, genero, Generar_estado(), enfermedad);
	while (!queue->is_empty())
	{
		aux = queue->Front<CPaciente>();
		if (aux.getEstado() == "Positivo")
		{
			cout << " Paciente N " << cont << ". " << aux.Mostrar_Informacion() << endl << endl << endl;
			if (aux.getEdad() >= 60)
			{
				mayorRiesgo->Agregar<void>(aux);
			}
			else if (aux.getEdad() < 60 && aux.getEnfermedad() == "SI")
			{
				mayorRiesgo->Agregar<void>(aux);
			}
			else
			{
				menorRiesgo->Agregar<void>(aux);
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
	cin >> opcionMenu;
	system("cls");
}

int main()
{
	Menu();

	while (opcionMenu != 6)
	{
		switch (opcionMenu)
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
			cout << "\n Presione una tecla para volver al menu principal...";
			_getch();
			system("cls");
			break;
		
		case LISTAR:
			int opc;
			char opcionEliminar;
			cout << " Presione 1 para mostrar al GRUPO DE MAYOR RIESGO o 0 para mostrar al GRUPO DE MENOR RIESGO: ";
			cin >> opc;
			if (opc == 1)
			{	
				if (mayorRiesgo->is_empty())
				{
					cout << " No existen pacientes con riesgo alto" << endl << endl;
					cout << "\n Presione una tecla para volver al menu principal...";
					_getch();
				}
				else
				{
					Show_mayorriesgo();
					cout << "\n Desea eliminar a un paciente de la lista ? (S para SI : N para NO): ";
					cin >> opcionEliminar;
					opcionEliminar = toupper(opcionEliminar);
					if (opcionEliminar == 'S')
					{
						cout << " Ingrese el apellido del paciente que desea eliminar de la lista: ";
						cin >> eliminarApellido;
						mayorRiesgo->Eliminar<bool>(eliminarApellido);
						cout << " Paciente removido correctamente!!!";
					}
					cout << "\n Presione una tecla para volver al menu principal...";
					_getch();
				}
			}
			else
			{
				
				if (menorRiesgo->is_empty())
				{
					cout << " No existen pacientes con riesgo bajo" << endl << endl;
					cout << "\n Presione una tecla para volver al menu principal...";
					_getch();
				}
				else
				{
					Show_menorriesgo();
					cout << "\n Desea eliminar a un paciente de la lista ? (S para SI : N para NO): ";
					cin >> opcionEliminar;
					opcionEliminar = toupper(opcionEliminar);
					if (opcionEliminar == 'S')
					{
						cout << " Ingrese el apellido del paciente que desea eliminar de la lista: ";
						cin >> eliminarApellido;
						menorRiesgo->Eliminar<bool>(eliminarApellido);
						cout << " Paciente removido correctamente!!!";
					}
					cout << "\n Presione una tecla para volver al menu principal...";
					_getch();
				}
			}
			system("cls");
			break;

		case GUARDAR:

			menorRiesgo->Guardar<void>(archivo2);
			mayorRiesgo->Guardar<void>(archivo1);
			cout << " Se guardo la lista de pacientes en un archivo correctamente!!!" << endl << endl;
			cout << "\n Presione una tecla para volver al menu principal...";
			_getch();
			system("cls");
			break;

		case CARGAR:
			int opcion;
			int n;
			string nombreArchivo;
			CPaciente aux = CPaciente(nombre, apellido, edad, genero, estado, enfermedad);
			CLista<CPaciente>* aux1 = new CLista<CPaciente>();

			cout << " 1. Abrir archivo de los pacientes de MENOR RIESGO\n";
			cout << " 2. Abrir archivo de los pacientes de MAYOR RIESGO\n";
			cout << "Ingrese una opcion: ";
			cin >> opcion;

			cout << "N* de pacientes en el archivo: ";
			cin >> n;
			//queue->Push(nuevaLista->Cargar(nombre));

			if (opcion == 1)
			{
				nombreArchivo = "Menor_Riesgo.txt";
				for (int i = 0; i < n; i++)
				{
					aux1->Agregar<void>(menorRiesgo->Cargar(nombreArchivo)[i]);
				}
			}
			else
			{
				nombreArchivo = "Mayor_Riesgo.txt";
				for (int i = 0; i < n; i++)
				{
					aux1->Agregar<void>(mayorRiesgo->Cargar(nombreArchivo)[i]);
				}
			}
			aux1->Mostrar<void>();
			cout << "\n\n Presione una tecla para volver al menu principal...";
			_getch();
			system("cls");
			break;
		}
	Menu();
	}
	system("pause");
	return 0;
}