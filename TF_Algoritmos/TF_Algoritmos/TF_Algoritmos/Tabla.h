#pragma once
#include "AVL.h"
#include "CFila.h"
#include "CColumna.h"

class CTabla {
private:
	vector<CFila>* filas;
	vector<CColumna>* columna;
	int nCol;

public:
	CTabla() {};
	~CTabla() { };
};