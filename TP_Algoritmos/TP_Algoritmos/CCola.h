#ifndef __CCOLA_H__
#define __CCOLA_H__
#include "CPaciente.h"


//template <typename T>
class CCola
{
	struct Node
	{
		CPaciente elem;
		Node* next;

		Node(CPaciente elem, Node* n = nullptr) : elem(elem), next(n) {}
	};

	Node* ini;
	Node* fin;
	int len;

public:
	CCola() : len(0), ini(nullptr), fin(nullptr) {}
	~CCola()
	{
		while (fin != nullptr)
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

	void Push(CPaciente elem)
	{
		if (++len == 1)
		{
			ini = new Node(elem);
			fin = ini;
		}
		else
		{
			fin->next = new Node(elem);
			fin = fin->next;
		}
	}

	bool Pop()
	{
		if (len > 0)
		{
			auto aux = ini;
			ini = aux->next;
			delete aux;
			--len;
			return true;
		}
		return false;
	}

	int Size() { return len; }

	CPaciente Front()
	{
		if (len > 0)
		{
			return ini->elem;
		}
	}

	// en prueba

	//void Cargar(string _nombre)
	//{
	//	ifstream archivo;
	//	
	//	CCola aux2;
	//	archivo.open(_nombre);
	//	string nombre, apellido, genero,estado, enfermedad, edad, aislamiento;
	//
	//	if (archivo.is_open()) {
	//		
	//		getline(archivo,nombre ,',' );
	//		getline(archivo, apellido,',' );
	//		getline(archivo, genero,',' );
	//		getline(archivo, edad,',' );
	//		getline(archivo, enfermedad,',' );
	//		getline(archivo, estado,',' );
	//		// falta 
	//		getline(archivo, aislamiento,',' );
	//		CPaciente* paciente = new CPaciente(nombre,apellido,stoi(edad),genero,estado,enfermedad);
	//	
	//		if (nombre == "")
	//		{
	//	
	//			aux2.Push(*paciente);
	//		}
	//	}
	//	else
	//		cout << "ERROR, FILES NOT FOUND" << endl;


	//}

};

#endif