#include "Employe.h"
/*********************************************/
/*********Constructeur et Destructeur*********/
/*********************************************/
Employe::Employe():Intervenant()
{
	#ifdef DEBUG
		cout<<"Constructeur par défault de employé"<<endl;
	#endif

	setLogin("Pas de login");
	setFonction("Pas de fonction");
	mdp=NULL;
}
Employe::Employe(string nom,string prenom,int numero,string login,string fonction):Intervenant(nom,prenom,numero)
{
	#ifdef DEBUG
		cout<<"Constructeur d'initialisation de employé"<<endl;
	#endif

	setLogin(login);
	setFonction(fonction);
	mdp=NULL;
}
Employe::Employe(const Employe &source):Intervenant(source)
{
	#ifdef DEBUG
		cout<<"Constructeur de copie de employé"<<endl;
	#endif

	setLogin(source.getLogin());
	setFonction(source.getFonction());
	mdp=new string;
	*mdp=source.getMotDePasse();
}
Employe::~Employe()
{
	#ifdef DEBUG
		cout<<"Destructeur de employé"<<endl;
	#endif

	delete mdp;
}
/*********************************************/
/***********Getters et Setters****************/
/*********************************************/
void Employe::setLogin(string l)
{
	login=l;
}
void Employe::setMotDePasse(string m)
{
	ResetMotDePasse();
	if(mdp==NULL)
	{
		mdp=new string(m);
	}
}
void Employe::setFonction(string f)
{
	fonction=f;
}
string Employe::getLogin()const
{
	return login;
}
string Employe::getMotDePasse()const
{
	string a;
	if(mdp!=NULL)
	{
		return *mdp;
	}
	return a;
}
string Employe::getFonction()const
{
	return fonction;
}
/*********************************************/
/***********Methodes publiques****************/
/*********************************************/
void Employe::Affiche()const
{
	Intervenant::Affiche();
	cout<<"Login:"<<getLogin()<<endl<<"Mot de passe:"<<getMotDePasse()<<endl<<"Fonction:"<<getFonction()<<endl;
}
void Employe::ResetMotDePasse()
{
	if(mdp!=NULL)
	{
		delete mdp;
		mdp=NULL;
	}
}

string Employe::ToString()const
{
	string tostring;
	if(fonction.compare("Administratif"))
	{
		tostring="[A"+to_string(getNumero())+"] "+getNom()+" "+getPrenom();
	}
	if(fonction.compare("Vendeur"))
	{
		tostring="[V"+to_string(getNumero())+"] "+getNom()+" "+getPrenom();
	}
	return tostring;
}

string Employe::Tuple() const
{
	string tuple;

	tuple=to_string(getNumero())+";"+getNom()+";"+getPrenom()+";"+getFonction();
	return tuple;
}
/*********************************************/
/***********Sucharge Opérateur****************/
/*********************************************/
Employe& Employe::operator=(const Employe& source)
{
	Intervenant::operator=(source);
	setLogin(source.getLogin());
	setFonction(source.getFonction());
	setMotDePasse(source.getMotDePasse());

	return(*this);
}

ostream& operator<<(ostream& s, const Employe& source)
{
	//source.Affiche();
	s<<"Nom:"<<source.getNom()<<endl<<"Prenom:"<<source.getPrenom()<<endl<<"Numero:"<<source.getNumero()<<endl<<"Login:"<<source.getLogin()<<endl<<"Mot de passe:"<<source.getMotDePasse()<<endl<<"Fonction:"<<source.getFonction()<<endl;
	return s;
}


const string Employe::ADMINISTRATIF = "Administratif";
const string Employe::VENDEUR = "Vendeur";