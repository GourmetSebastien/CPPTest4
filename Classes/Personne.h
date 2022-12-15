#ifndef PERSONNE_H
#define PERSONNE_H

#include <iostream>
#include <string>

using namespace std;

class Personne
{
	friend ostream& operator<<(ostream& s,const Personne&);
	friend istream& operator>>(istream& s,Personne&);

	protected:
		string nom;
		string prenom;
	public:
		Personne();
		Personne(string,string);
		Personne(const Personne&);
		~Personne();

		void setNom(string);
		void setPrenom(string);

		string getNom()const;
		string getPrenom()const;

		Personne& operator=(const Personne&);
		void Affiche()const;
};

#endif 