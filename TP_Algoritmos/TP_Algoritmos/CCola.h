#pragma once
#include <iostream>
using namespace std;


template<typename T>
class Cola
{
	struct Node
	{
		T elem;
		Node* next;

		Node(T elem) : elem(elem), next(nullptr) {}
	};

	Node* ini;
	Node* fin;
	int len;

public:
	Cola() : len(0), ini(nullptr), fin(fin) {}
	~Cola() {	}

	void Push(T elem) {
		Node* nuevoNode = new Node(elem);
		nuevoNode->next = nullptr;
		if (Is_Empty()) {
			ini = nuevoNode;
			fin = nuevoNode;
		}
		else {
			fin->next = nuevoNode;
			fin = nuevoNode;
		}
	}
	void Pop()
	{
		if (Is_Empty()) {
			return;
		}
		else {
			Node* borrar = ini;
			if (ini == fin) {
				ini = nullptr;
				fin = nullptr;
			}
			else
			{
				ini = ini->next;
				delete borrar;
			}
		}
	}
	bool Is_Empty(Node* ini)
	{
		return (ini == NULL) ? true : false;

	}

};
