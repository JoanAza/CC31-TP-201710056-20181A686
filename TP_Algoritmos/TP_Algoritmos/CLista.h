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
		Node* aux = ini;
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
		Node* aux = ini;
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
};
#endif