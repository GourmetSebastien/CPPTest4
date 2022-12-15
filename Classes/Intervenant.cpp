#include "Intervenant.h"
/*********************************************/
/*********Constructeur et Destructeur*********/
/*********************************************/
Intervenant::Intervenant():Personne()
{
	#ifdef DEBUG
		cout<<"Constructeur par défault de Intervenant"<<endl;
	#endif

	numero=0;
}
Intervenant::Intervenant(string nom,string prenom,int n):Personne(nom,prenom)
{
	#ifdef DEBUG
		cout<<"Constructeur d'initialisation de Intervenant"<<endl;
	#endif

	setNumero(n);
}
Intervenant::Intervenant(const Intervenant &source):Personne(source)
{
	#ifdef DEBUG
		cout<<"Constructeur de copie de Intervenant"<<endl;
	#endif

	setNumero(source.getNumero());
}
Intervenant::~Intervenant()
{
	#ifdef DEBUG
		cout<<"Destructeur d' Intervenant"<<endl;
	#endif
}
/*********************************************/
/***********Getters et Setters****************/
/*********************************************/
void Intervenant::setNumero(int n)
{
	numero=n;
}
int Intervenant::getNumero()const
{
	return numero;
}

/*********************************************/
/***********Methodes publiques****************/
/*********************************************/
// string Intervenant::ToString()const
// {
// 	string tmp="";
// 	return tmp;
// }
// string Intervenant::Tuple()const
// {
// 	string tmp="";
// 	return tmp;
// }
void Intervenant::Affiche()const
{
	Personne::Affiche();
	cout<<"Numéro:"<<getNumero()<<endl;
}
/*********************************************/
/*************Surchage opérateur**************/
/*********************************************/
Intervenant& Intervenant::operator=(const Intervenant &source)
{
	Personne::operator=(source);
	setNumero(source.getNumero());

	return(*this);
}