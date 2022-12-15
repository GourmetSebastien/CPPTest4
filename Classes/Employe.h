#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <iostream>
#include <string>
#include "Intervenant.h"

using namespace std;

class Employe: public Intervenant
{
	friend ostream& operator<<(ostream&,const Employe&);

	private:
		string login;
		string* mdp;
		string fonction;
	public:
		Employe();
		Employe(string,string,int,string,string);
		Employe(const Employe&);
		~Employe();

		void setLogin(string);
		void setMotDePasse(string);
		void setFonction(string);

		string getLogin()const;
		string getMotDePasse()const;
		string getFonction()const;

		static const string ADMINISTRATIF;
		static const string VENDEUR;

		Employe& operator=(const Employe&);

		string Tuple() const;
		string ToString() const;
		void Affiche()const;
		void ResetMotDePasse();
};
#endif