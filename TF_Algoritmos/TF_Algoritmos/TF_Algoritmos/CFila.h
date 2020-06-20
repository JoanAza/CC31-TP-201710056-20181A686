#ifndef __CFILA_H__
#define __CFILA_H__

class CFila
{
private:
	int idx;
public:
	CFila(int idx) : idx(idx){}
	~CFila(){}
	int getIdx() { return idx; }
	void setIdx(int _idx) { this->idx = _idx; }

};



#endif // !__CFILA_H__
