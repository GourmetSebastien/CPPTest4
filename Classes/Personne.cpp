#include "Personne.h"
/*********************************************/
/*********Constructeur et Destructeur*********/
/*********************************************/
Personne::Personne()
{
	#ifdef DEBUG
		cout<<"Constructeur par défault de Personne"<<endl;
	#endif

	setNom("Personne sans nom");
	setPrenom("Personne sans prenom");
}
Personne::Personne(string n,string p)
{
	#ifdef DEBUG
		cout<<"Constructeur d'initialisation de Personne"<<endl;
	#endif

	setNom(n);
	setPrenom(p);
}
Personne::Personne(const Personne &source)
{
	#ifdef DEBUG
		cout<<"Constructeur de copie de Personne"<<endl;
	#endif

	setNom(source.getNom());
	setPrenom(source.getPrenom());
}
Personne::~Personne()
{
	#ifdef DEBUG
		cout<<"Destructeur de copie de Personne"<<endl;
	#endif
}
/*********************************************/
/***********Getters et Setters****************/
/*********************************************/
void Personne::setNom(string n)
{
	nom=n;
}
void Personne::setPrenom(string p)
{
	prenom=p;
}
string Personne::getNom()const
{
	return nom;
}
string Personne::getPrenom()const
{
	return prenom;
}
/*********************************************/
/*************Surchage opérateur**************/
/*********************************************/
Personne& Personne::operator=(const Personne &source)
{
	setNom(source.getNom());
	setPrenom(source.getPrenom());
	
	return (*this);
}
ostream& operator<<(ostream& s,const Personne &source)
{
	s<<"Nom:"<<source.getNom()<<endl<<"Prenom:"<<source.getPrenom()<<endl;

	return s;
}
istream& operator>>(istream& s,Personne &source)
{
	string nom;
	string prenom;

	cout<<endl<<"Nom:";
	s>>nom;
	cout<<endl<<"Prenom:";
	s>>prenom;

	source.setNom(nom);
	source.setPrenom(prenom);

	return s;
}
/*********************************************/
/*************Méthode publique****************/
/*********************************************/
void Personne::Affiche()const
{
	cout<<"Nom:"<<getNom()<<endl<<"Prenom:"<<getPrenom()<<endl;
}