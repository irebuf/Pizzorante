#ifndef __PIZZORANTE_H__
#define __PIZZORANTE_H__

#include <iostream>
#include <string>
#include <set>
using namespace std;

typedef enum Allergene{
	GLUTINE,
	CROSTACEI,
	UOVA,
	PESCE,
	ARACHIDI,
	LATTE,
	FRUTTA_A_GUSCIO,
	SEDANO,
	SENAPE,
	SEMI_DI_SESAMO,
	ANIDRIDE_SOLFOROSA,
	LUPINI,
	MOLLUSCHI
}Allergene;

class Ingrediente {
	private:
		string nome;
		int id_ingrediente;
		bool disponibile;
		bool surgelato;
		set<Allergene> nodeAllergeni;
	public:
		Ingrediente(string _nome, int _id_ingrediente, bool _disponibile, bool surgelato, set<Allergene> _nodeAllergeni);
		
};


#endif

