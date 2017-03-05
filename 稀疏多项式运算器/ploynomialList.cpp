#include "ploynomialList.h"

ploynomialList::ploynomialList(){
	this->linkList = new pNode;
	this->linkList->next = NULL;
}

ploynomialList::ploynomialList(const ploynomialList & L) {
	this->linkList = new pNode;
	pList a = this->linkList;
	pList i = L.linkList;
	while (i->next) {
		i = i->next;
		a->next = new pNode;
		a = a->next;
		a->coef = i->coef;
		a->exp = i->exp;
	}
	a->next = NULL;
}

ploynomialList::ploynomialList(pList L) {
	this->linkList = new pNode;
	pList a = this->linkList;
	while (L->next) {
		L = L->next;
		a->next = new pNode;
		a = a->next;
		a->coef = L->coef;
		a->exp = L->exp;
	}
	a->next = NULL;
}

ploynomialList::ploynomialList(int n) {
	this->linkList = new pNode;
	pList a = this->linkList;
	a->next = new pNode;
	a = a->next;
	a->exp = n;
	a->coef = 1;
	a->next = NULL;
}


ploynomialList::~ploynomialList(){
	pList i = this->linkList;
	pList j = i;
	while (i->next) {
		j = i;
		i = i->next;
		delete j;
	}
	delete i;
	this->linkList = NULL;
}


int ploynomialList::insert(pNode val,bool canCombine){
	pList i = this->linkList;
	pList t = i;
	if (val.coef == 0) return -2;
	if (val.exp < 0) return -3;
	while (i->next) {
		t = i;
		i = i->next;
		if (i->exp == val.exp) {
			if (canCombine) {
				i->coef += val.coef;
				if (abs(i->coef) < 1e-6) {
					t->next = i->next;
					delete i;
				}
				return 0;
			}
			else return -1;
		}
		if (i->exp>val.exp) {
			t->next = new pNode;
			t->next->coef = val.coef;
			t->next->exp = val.exp;
			t->next->next = i;
			return 0;
		}
	}
	i->next = new pNode;
	i->next->coef = val.coef;
	i->next->exp = val.exp;
	i->next->next = NULL;
	return 0;
}

int ploynomialList::remove(int exp) {
	pList t;
	pList i = this->linkList;
	while (i->next) {
		if (i->next->exp == exp) {
			t = i->next;
			i->next = t->next;
			delete t;
			return 0;
		}
		if (i->next->exp > exp)return -1;
	}
}


void ploynomialList::print(){
	pList i = this->linkList;
	i = i->next;
	while (i) {
		using namespace std;
		if ((i->coef!=1)||(i->exp==0)) cout << i->coef;
		if (i->exp > 0)  cout << "x^" << i->exp;
		if (i->next) { 
			if (i->next->coef>0) cout << '+';
		}
		else cout << endl;
		i = i->next;
	}
}


void ploynomialList::clear() {
	pList i = this->linkList;
	if (!i->next) return;
	i = i->next;
	pList j = i;
	while (i->next) {
		j = i;
		i = i->next;
		delete j;
	}
	delete i;
	this->linkList->next = NULL;
}

int ploynomialList::length()
{
	pList i = this->linkList;
	int l = 0;
	if (!i->next) return 0; else i = i->next;
	for (; i; i = i->next)l++;
	return l;
}


int ploynomialList::deg()
{
	pList i = this->linkList;
	if (!i->next) return -2;
	while (i->next) i = i->next;
	if (i->exp > 0) return i->exp;
	else if (abs(i->coef) < 1e-6) return -1;
	else return 0;
}


double ploynomialList::value(double x)
{
	pList i = this->linkList;
	if (!i->next) return 0.0;
	double s;
	i = i->next;
	for (s = 0; i; i = i->next) s += (i->coef)*pow(x, i->exp);
	return s;
}

ploynomialList ploynomialList::gcd(ploynomialList L) {
	ploynomialList T = L % (*this);
	if (L.linkList->next == NULL) return *this;
	if (this->linkList->next == NULL) return L;
	return T.gcd(*this);
}

ploynomialList ploynomialList::lcm(ploynomialList L) {
	return L*(*this)/gcd(L);
}

ploynomialList ploynomialList::nDiff(int n){
	ploynomialList T;
	pList i = this->linkList;
	pList j = T.getLinkList();
	pNode t;
	if (!i->next) return ploynomialList();
	while (i->next) {
		i = i->next;
		if (i->exp > n) {
			t.exp = i->exp - n;
			t.coef = i->coef;
			for (int k = 0; k < n; k++) t.coef *= (i->exp - k);
			T.insert(t);
		}
	}
	return T;
}


ploynomialList ploynomialList::diff(){
	return nDiff(1);
}

ploynomialList ploynomialList::integral(){
	ploynomialList T;
	pList i = this->linkList;
	pList j = T.getLinkList();
	pNode t;
	if (!i->next) return ploynomialList();
	while (i->next) {
		i = i->next;
		t.exp = i->exp +1;
		t.coef = i->coef/i->exp;
		T.insert(t);
	}
	return T;
}


double ploynomialList::definiteIntegral(double l, double r){
	ploynomialList T = this->integral();
	return T.value(r)-T.value(l);
}

ploynomialList ploynomialList::operator+(ploynomialList & L) {
	ploynomialList T;
	pList i = this->linkList->next;
	pList j = L.getLinkList()->next;
	pList k = T.linkList;
	while (i&&j) {
		if (i->exp > j->exp) {
			k->next = new pNode;
			k = k->next;
			k->coef = j->coef;
			k->exp = j->exp;
			j = j->next;
		}
		else if (i->exp < j->exp) {
			k->next = new pNode;
			k = k->next;
			k->coef = i->coef;
			k->exp = i->exp;
			i = i->next;
		}
		else if (i->exp == j->exp) {
			if (abs(i->coef + j->coef) > 1e-6) {
				k->next = new pNode;
				k = k->next;
				k->coef = i->coef + j->coef;
				k->exp = i->exp;
			}
			i = i->next;
			j = j->next;
		}
	}
	while (j) {
		k->next = new pNode;
		k = k->next;
		k->coef = j->coef;
		k->exp = j->exp;
		j = j->next;
	}
	while (i) {
		k->next = new pNode;
		k = k->next;
		k->coef = i->coef;
		k->exp = i->exp;
		i = i->next;
	}
	k->next = NULL;
	return T;
}

ploynomialList ploynomialList::operator-(ploynomialList & L) {
	return *this + L*(-1.0);
}

ploynomialList ploynomialList::operator*(ploynomialList & L) {
	pList i = this->linkList;
	pList j = L.getLinkList();
	ploynomialList T;
	pNode t;
	while (i->next) {
		i = i->next;
		while (j->next) {
			j = j->next;
			t.coef = i->coef*j->coef;
			t.exp = i->exp + j->exp;
			T.insert(t, true);
		}
		j = L.getLinkList();
	}
	return T;
}

ploynomialList ploynomialList::operator/(ploynomialList & L) {
	ploynomialList T;
	ploynomialList P(this->linkList);
	if (L.linkList->next == NULL) return T;
	if (this->deg() < L.deg()) {
		return T;
	}
	pList i = P.getLinkList();
	pList j = L.getLinkList();
	double maxi, maxj; int degi, degj;
	while (P.deg() >= L.deg()) {
		i = P.getLinkList(); j = L.getLinkList();
		while (i->next) i = i->next;
		maxi = i->coef; degi = i->exp;
		while (j->next) j = j->next;
		maxj = j->coef; degj = j->exp;
		double c = maxi / maxj;
		T = T + c*ploynomialList(degi - degj);
		P = P - c*L*ploynomialList(degi - degj);
	}
	return T;
}

ploynomialList ploynomialList::operator%(ploynomialList & L) {
	return *this - L*(*this / L);
}

ploynomialList & ploynomialList::operator=(const ploynomialList & L) {
	this->clear();
	pList a = this->linkList;
	pList i = L.linkList;
	while (i->next) {
		i = i->next;
		a->next = new pNode;
		a = a->next;
		a->coef = i->coef;
		a->exp = i->exp;
	}
	a->next = NULL;
	return *this;
}

bool ploynomialList::operator==(ploynomialList & L) {
	if (L.length() != this->length()) return false;
	pList i=this->linkList,j=L.getLinkList();
	while (i->next&&j->next) {
		i = i->next;
		j = j->next;
		if ((i->exp != j->exp) || (i->coef != j->coef)) return false;
	}
	return true;
}

ploynomialList operator*(ploynomialList & L, double c) {
	ploynomialList T;
	if (c == 0) {
		return T;
	}
	pNode t;
	pList i = L.getLinkList();
	pList j = T.getLinkList();
	while (i->next) {
		i = i->next;
		j->next = new pNode;
		j = j->next;
		j->coef = c*i->coef;
		j->exp = i->exp;
	}
	j->next = NULL;
	return T;
}

ploynomialList operator*(double c, ploynomialList & L) {
	return L*c;
}

ploynomialList operator/(ploynomialList & L, double c) {
	if (c == 0) return ploynomialList();
	return L*(1/c);
}

ploynomialList operator/(double c, ploynomialList & L) {
	return L/c;
}

pList ploynomialList::getLinkList() {
	return this->linkList;
}


void ploynomialList::setLinkList(pList L) {
	this->linkList = L;
}


int ploynomialList::setNode(pNode val) {
	pList i = this->linkList;
	if (val.coef == 0) return -1;
	while (i->next) {
		i = i->next;
		if (i->exp == val.exp) {
			i->coef = val.coef;
			return 0;
		}
		if (i->exp > val.exp) return -1;
	}
}
