#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include "Intervenant.h"

using namespace std;

class Client: public Intervenant
{
	friend ostream& operator<<(ostream&,const Client&);

	private:
		string gsm;
	public:
		Client();
		Client(string,string,int,string);
		Client(const Client&);
		~Client();

		void setGsm(string);

		string getGsm()const;

		Client& operator=(const Client&);

		void Affiche()const;
		string Tuple()const;
		string ToString()const;
};

#endif