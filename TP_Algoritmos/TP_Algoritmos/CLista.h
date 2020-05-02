#ifndef __CLISTA_H__
#define __CLISTA_H__
#include "CPaciente.h"


class CLista
{
	struct Node
	{
		CPaciente elem;
		Node* next;

		Node(CPaciente elem, Node* n = nullptr) : elem(elem), next(n) {}
	};

	Node* ini;
	int len;

public:
	CLista() : len(0), ini(nullptr) {}
	
	~CLista()
	{
		while (ini != nullptr)
		{
			auto aux = ini;
			ini = aux->next;
			delete aux;
		}
	}

	bool is_empty()
	{
		return len == 0;
	}

	void Agregar(CPaciente elem)
	{
		if (++len == 1)
		{
			ini = new Node(elem);
		}
		else
		{
			Node* nuevo = new Node(elem, ini);
			ini = nuevo;
		}
	}

	template <typename T, T NADA>

	T Buscar(CPaciente elem)
	{
		CPaciente help = CPaciente();
		auto aux = ini;
		while (aux != nullptr)
		{
			help = aux->elem;
			if (elem.getApellido() == help.getApellido())
			{
				return aux->elem;
			}
			aux = aux->next;
		}
		return NADA;
	}

	CPaciente Mostrar()
	{
		CPaciente help = CPaciente();
		auto aux = ini;
		help = aux->elem;
		cout << help.Mostrar_Informacion() << endl;
		for (int i = 0; i < len; i++)
		{
			aux = aux->next;
			help = aux->elem;
			cout << help.Mostrar_Informacion() << endl;
			if (aux->next == nullptr)
			{
				break;
			}
		}
		return aux->elem;
	}

	void Guardar()
	{
	
		Node* aux = ini;
		ofstream archivo;

		archivo.open("archivo.txt");
		for(int i = 0; i < len ; ++i)
		{
			archivo << aux->elem.getNombre() << "," << aux->elem.getApellido() << "," << aux->elem.getGenero() << ","
				<< aux->elem.getEdad() << "," << aux->elem.getEnfermedad() << "," << aux->elem.getEstado() << ","
				<< aux->elem.getAislamiento();
			archivo << endl;
			aux = aux->next;
		}
		archivo.close();
	}

	// en prueba

	vector<CPaciente> Cargar(string _nombre)
	{
		ifstream archivo;
		vector<CPaciente> vc1;
		archivo.open(_nombre, ios::in);
		string nombre, apellido, genero, edad, enfermedad,estado, aislamiento;
	
		if (archivo.is_open()) {
			while (!archivo.eof())
			{
				getline(archivo, nombre,',' );
				getline(archivo, apellido,',' );
				getline(archivo, genero,',' );	
				getline(archivo, edad,',' );
				getline(archivo, enfermedad,',' );
				getline(archivo, estado,',' );
				getline(archivo, aislamiento);
				CPaciente paciente = CPaciente(nombre, apellido,stoi(edad), genero, estado, enfermedad);
				vc1.push_back(paciente);			
			}
		}
		else
			cout << "ERROR, FILES NOT FOUND" << endl;
		archivo.close();
		return vc1;
	}


};
#endif