#ifndef INTERVENANT_H
#define INTERVENANT_H

#include <iostream>
#include <string>
#include "Personne.h"

using namespace std;

class Intervenant: public Personne
{
	protected:
		int numero;
	public:
		Intervenant();
		Intervenant(string,string,int);
		Intervenant(const Intervenant&);
		virtual ~Intervenant();

		void setNumero(int);

		int getNumero()const;

		Intervenant& operator=(const Intervenant&);

		virtual string ToString()const=0;
		virtual string Tuple()const=0;
		void Affiche()const;
};

#endif