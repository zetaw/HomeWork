#pragma once
#ifndef PLOYNOMIALLIST_H
#define PLOYNOMIALLIST_H
#include <iostream>
#include <ostream>
#include <istream>
#include <cmath>

typedef struct ploynomialNode {
	unsigned int exp;
	double coef;
	struct ploynomialNode *next;
}pNode,*pList;


class ploynomialList
{
public:
	ploynomialList();
	ploynomialList(const ploynomialList &L);
	ploynomialList(pList L);
	ploynomialList(int n);
	~ploynomialList();
private:
	pList linkList;
public:
	pList getLinkList();
	void setLinkList(pList L);
	int insert(pNode val,bool canCombine=false);
	int remove(int exp);
	void print();
	void clear();
	int length();
	int deg();
	double value(double x);
	ploynomialList gcd(ploynomialList L);
	ploynomialList lcm(ploynomialList L);
	ploynomialList nDiff(int n=1);
	ploynomialList diff();
	ploynomialList integral();
	double definiteIntegral(double l, double r);
	ploynomialList operator+(ploynomialList &L);
	ploynomialList operator-(ploynomialList &L);
	ploynomialList operator*(ploynomialList &L);
	ploynomialList operator/(ploynomialList &L);
	ploynomialList operator%(ploynomialList &L);
	ploynomialList & operator=(const ploynomialList &L);
	bool operator==(ploynomialList &L);
	friend ploynomialList operator*(ploynomialList &L, double c);
	friend ploynomialList operator*(double c, ploynomialList &L);
	friend ploynomialList operator/(ploynomialList &L, double c);
	friend ploynomialList operator/(double c,ploynomialList &L);
	friend inline std::ostream &operator << (std::ostream& out, ploynomialList &L) {
		pList i = L.getLinkList();
		while (i->next) {
			i = i->next;
			out << i->coef;
			if (i->exp > 0)  out << "x^" << i->exp;
			if (i->next) out << '+'; else out << std::endl;
		}
		return out;
	}
	friend inline std::istream &operator >> (std::istream& in, ploynomialList &L) {
		pNode T;
		int e, c, msg;
		for (;;) {
			in >> e;
			if (e == -1) return in;
			in >> c;
			T.coef = c;
			T.exp = e;
			if (e < 0) {
				std::cerr << "指数为负数！\n"; continue;
			}
			msg = L.insert(T);
			if (msg == -2) std::cerr << "系数为0！\n";
			if (msg == -1) std::cerr << "重复输入！\n";
		}
	}
	int setNode(pNode val);
};

#endif // !PLOYNOMIALLIST_H
