#pragma once
#include "AVL.h"
#include "CFila.h"
#include <vector>

class CTabla {
private:
	vector<CFila>* filas;
	int nCol;

public:
	CTabla() {};
	~CTabla() { };
};