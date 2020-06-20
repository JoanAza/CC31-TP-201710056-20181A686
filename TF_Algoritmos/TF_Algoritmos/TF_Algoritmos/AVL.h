#ifndef __AVL_H__
#define __AVL_H__
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;

template <typename T, typename R = T, T NONE = 0> // 
class AVLTree
{
	struct  Node
	{
		T elem;
		Node* left;
		Node* right;
		int h;
		Node(T elem) : elem(elem), left(nullptr), right(nullptr), h(0) {}
		static int height(Node* n) { return n == nullptr ? -1 : n->h; } // if abreviado  

		void updateH() {
			h = std::max(Node::height(left), Node::height(right)) + 1;
		}

	};
	Node* root;
	int		len;

	function<R(T)>key;

	void destroy(Node* n) {
		if (n != nullptr)
		{
			destroy(n->l);
			destroy(n->r);
			delete n;
		}
	}
	void rotAB(Node*& n)
	{
		Node* aux = n->l;
		n->l = aux->r;
		n->updateH();
		aux->r = n;
		n = aux;
		n->updateH();
	}
	void rotBA(Node*& n)
	{
		Node* aux = n->r;
		n->r = aux->l;
		n->updateH();
		aux->l = n;
		n = aux;
		n->updateH();
	}
	void balance(Node*& n) {
		int delta = Node::height(n->l) - Node::height(n->r);
		if (delta < -1) {
			if (Node::height(n->r->l) > Node::height(n->r->r))
			{
				rotAB(n->r);
			}
			rotBA(n);
		}
		else if (delta > 1) {

			if (Node::height(n->l->r) > Node::height(n->l->l))
			{
				rotBA(n->l);
			}
			rotAB(n);
		}
	}
	void add(Node*& n, T e) {
		if (n == nullptr) {
			n = new Node(e);
			return;
		}
		else if (key(e) < key(n->e)) {
			add(n->l, e);
		}
		else {
			add(n->r, e);
		}
		balance(n);
		n->updateH();
	}
	void InOrder(Node* node, function<void(T)> in_order) {
		if (node != nullptr) {
			InOrder(node->l, in_order);
			in_order(node->e);
			InOrder(node->r, in_order);
		}
	}
	// NUEVO
	T find(Node* node, R val) {
		if (node == nullptr) { 
			return NONE;
		}else if (val = key(node->elem)) {
			return node->elem;
		}else if (val < key(node->elem)) {
			return find(node->left);
		}else {
			return find(node->right);
		}

	}
	T greatertham(Node* node, R val){
		if (node == nullptr) {
			return NONE;
		}else if (val < key(node->elem)) {
			return nodo->elem;
		}
		return greatertham(node->right, val);
	
	}
	T smallertham(Node* node, R val) {
		if (node == nullptr) {
			return NONE;
		}
		else if (val > key(node->elem)) {
			return nodo->elem;
		}
		return smallertham(node->left, val);

	}

public:
	AVLTree(function<R(T)>key = [](T a) {return a; }) :root(nullptr), len(0), key(key) {}
	~AVLTree() { destroy(root); }
	int Length() { return len; }
	int Height() { return Node::height(root); }
	void Add(T e) {
		add(root, e);
		++len;
	}
	void InOrder(function<void(T)> in_order) {
		InOrder(root, in_order);
	}

	// NUEVO
	T Find(R val) { return find(root, val); }
	T greaterTham(R val) { return greatertham(root, val); }
	T smallerTham(R val) { return smallertham(root, val); }
};












#endif // !__AVL_H__
