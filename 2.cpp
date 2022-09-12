#include <iostream>
using namespace std;


struct Nod {
	int info;
	Nod* back;
};

void Push(Nod*& v, int x)
{
	Nod* c;
	if (v == 0)
	{
		v = new Nod;
		v->info = x;
		v->back = 0;
	}
	else
	{
		c = new Nod;
		c->back = v;
		c->info = x;
		v = c;
	}
}

void pop(Nod*& v)
{
	Nod* c;
	if (v == 0)
	{
		cout << "stiva este vida";
	}
	else
	{
		c = v;
		v = v->back;
		delete c;
	}
}
void afisare (Nod* v)
{
	Nod* c;
	c = v;
	cout << endl;
	while (c!=0)
	{
		cout << c->info<<" ";
		c = c->back;
	}
	cout << endl;
}

int main()
{
	int n, a;
	cout << "numarul initial de noduri";
	Nod* varf=0;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a;
		Push(varf,a); 
	}
	cout << endl;
	afisare(varf);
	pop(varf);
	cout << endl << "dupa eliminare" << endl;
	afisare(varf);
	cout << endl;
	return 0;
}