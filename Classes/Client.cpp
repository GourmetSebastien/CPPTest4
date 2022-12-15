#include "Client.h"
/*********************************************/
/*********Constructeur et Destructeur*********/
/*********************************************/
Client::Client():Intervenant()
{
	#ifdef DEBUG
		cout<<"Constructeur par défault de Client"<<endl;
	#endif

	setGsm("Pas de gsm");
}
Client::Client(string nom,string prenom,int numero,string gsm):Intervenant(nom,prenom,numero)
{
	#ifdef DEBUG
		cout<<"Constructeur d'initialisation de Client"<<endl;
	#endif

	setGsm(gsm);
}
Client::Client(const Client &source):Intervenant(source)
{
	#ifdef DEBUG
		cout<<"Constructeur de copie de Client"<<endl;
	#endif

	setGsm(source.getGsm());
}
Client::~Client()
{
	#ifdef DEBUG
		cout<<"Destructeur de Client"<<endl;
	#endif
}
/*********************************************/
/***********Getters et Setters****************/
/*********************************************/
void Client::setGsm(string n)
{
	gsm=n;
}
string Client::getGsm()const
{
	return gsm;
}
/*********************************************/
/***********Sucharge Opérateur****************/
/*********************************************/
Client& Client::operator=(const Client &source)
{
	Intervenant::operator=(source);
	setGsm(source.getGsm());
	return (*this);
}
ostream& operator<<(ostream& s,const Client &source)
{
	//source.Affiche();
	s<<"Nom:"<<source.getNom()<<endl<<"Prenom:"<<source.getPrenom()<<endl<<"Numero:"<<source.getNumero()<<endl<<"GSM:"<<source.getGsm()<<endl;
	return s;
}
/*********************************************/
/***********Methodes publiques****************/
/*********************************************/
void Client::Affiche()const
{
	Intervenant::Affiche();
	cout<<"Gsm:"<<getGsm()<<endl;
}
string Client::ToString()const
{
	string tostring;

	tostring="[C"+to_string(getNumero()-40)+"] "+getNom()+" "+getPrenom();
	return tostring;
}

string Client::Tuple() const
{
	string tuple;

	tuple=to_string(getNumero())+";"+getNom()+";"+getPrenom()+";"+getGsm();
	return tuple;
}