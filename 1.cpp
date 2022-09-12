#include <iostream>
using namespace std;

struct Nod {
	int info;
	Nod* next;
};

void Insert(Nod*& cap, int val)
{
	Nod* p;
	p = new Nod;
	p->info = val;
	p->next = cap;
	cap = p;
}

void CreateList(Nod*& cap)
{
	int n;
	cout << "Introduceti valori - 0 termina"<<endl;
	cin >> n;
	while (n != 0)
	{
		Insert(cap, n);
		cin >> n;
	}
}


int Maxim(Nod*& cap)
{
	Nod* p;
	p = cap;
	int maxim = p->info;
	p = p->next;
	while (p!=0)
	{
		if (p->info > maxim)
		{
			cout << "ceva";
			maxim = p->info;
		}
		p = p->next;
	}
	return maxim;
}

void printare(Nod*& cap)
{	
	cout << "inceput printare";
	Nod* p = cap;
	while(p!=0)
	{
		cout << p->info<<" ";
		p = p->next;
	}
}

void adaugarepeultimapozitie(Nod*& cap,int val)
{
	Nod* p = cap;
	while (p->next != NULL)
	{
		p = p->next;
	}
	Nod* q;
	q = new Nod;
	q->info = val;
	p->next = q;
	q->next = NULL;
}

void stergere(Nod*& cap,int val)
{
	Nod* prev;
	Nod* curent;
	prev = cap;
	curent = cap;
	while (curent->info != val)
	{
		prev = curent;
		curent = curent->next;
	}
	prev->next = curent->next;
	delete curent;
}

//deci pentru sterge avem un nod anterior prev si un nod curent curent, ambele se initializeaza cu cap

int Minim(Nod*& cap)
{
	Nod* p = cap;
	int minim = p->info;
	p = p->next;
	while (p != 0)
	{
		if (p->info < minim)
		{
			minim = p->info;
		}
		p = p->next;
	}
	return minim;
}


int main()
{
	Nod* p = 0;
	CreateList(p);
	cout << p->info;
	printare(p);
	//int maxim=Maxim(p);
	//cout << "maximul este " << maxim << endl;
	//stergere(p, maxim);
	//Insert(p, maxim);

	int minim = Minim(p);
	cout << "minimul este " << minim << endl;
	stergere(p, minim);
	adaugarepeultimapozitie(p, minim);
	printare(p);
	return 0;
}

