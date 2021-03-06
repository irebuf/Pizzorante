#include "pizzorante.h"

Prodotto::Prodotto(string _nome, Reparto _reparto, float _costo){
	reparto = _reparto;
	costo = _costo;
	nome = _nome;
	disponibile = true;
}

/*Prodotto::Prodotto (Prodotto& _p){
	set<Ingrediente *>::iterator iter;
	reparto = _p.reparto;
	costo = _p.costo;
	nome = _p.nome;
	disponibile = _p.disponibile;
	for (iter = ingredienti.begin(); iter != ingredienti.end(); iter++){
		_p.ingredienti.insert(*iter);
	}
}*/

void Prodotto::set_ingredienti( Ingrediente* _ingredienti){
	set<Ingrediente *>::iterator iiter;
	set<Allergene>::iterator aiter;
    
	ingredienti.insert(_ingredienti);
    
   /* for(iiter=ingredienti.begin();iiter!=ingredienti.end();++iiter){
        for(aiter=_ingredienti->get_allergeni_begin();aiter!=_ingredienti->get_allergeni_end();++aiter){
            allergeni.insert((*aiter));
        }
    }
    */
    disponibile=true;
    for(iiter=ingredienti.begin();iiter!=ingredienti.end();++iiter)
        if(!(*iiter)->get_disponibile())
        {
            disponibile=false;
            break;
        }
}

void Prodotto::remove_ingrediente (Ingrediente* _ingrediente){
	set<Ingrediente*>::iterator iter;
	iter = ingredienti.find(_ingrediente);
	if (iter != ingredienti.end()){
		ingredienti.erase(iter);
	}
	disponibile=true;
    for(iter=ingredienti.begin();iter!=ingredienti.end();++iter)
        if(!(*iter)->get_disponibile())
        {
            disponibile=false;
            break;
        }
}

bool Prodotto::get_disponibile()const{
	return disponibile;
}

float Prodotto::get_costo()const{
	return costo;
}

void Prodotto::set_costo(float _c){
	costo = _c;
}

bool Prodotto::operator < (const Prodotto& _prodotto)const{
	return (nome < _prodotto.nome);
}

ostream& operator << (ostream& os, const Prodotto& _prodotto){
	set<Ingrediente *>::iterator iiter;
	set<Allergene>::iterator aiter;
	set<Allergene> allergene;
    os<< "- "<<_prodotto.nome<<" -"<<endl;
	os << _prodotto.costo << " Euro "<< endl << "Reparto: ";
	switch(_prodotto.reparto){
		case PIZZERIA: os << "Pizzeria" << endl; break;
		case RISTORANTE: os << "Ristorante" << endl; break;
		case BAR: os << "Bar" << endl; break;
		default: os<< "Errore" << endl;
	}
	if (_prodotto.disponibile == true){
		os << "Disponibile ";
	} else {
		os << "Non disponibile ";
	}
	os << endl;
    
    os<<"- Composto da: -" << endl<<endl;
	for (iiter = _prodotto.ingredienti.begin(); iiter != _prodotto.ingredienti.end(); ++iiter){
		os << *(*iiter);
	}
    os << endl<< "Allergeni Totali: " << endl;
    for (iiter = _prodotto.ingredienti.begin(); iiter != _prodotto.ingredienti.end(); ++iiter){
		for (aiter = (*iiter)->get_allergeni_begin(); aiter != (*iiter)->get_allergeni_end(); ++aiter){
			allergene.insert(*aiter);
		}
	}
	for (aiter = allergene.begin(); aiter != allergene.end(); ++aiter){
		switch(*aiter){
            case 0: os<< "Glutine" <<endl; break;
            case 1: os<< "Crostacei" <<endl; break;
            case 2: os<< "Uova" <<endl; break;
            case 3: os<< "Pesce" <<endl; break;
            case 4: os<< "Arachidi" <<endl; break;
            case 5: os<< "Latte" <<endl; break;
            case 6: os<< "Frutta a Guscio" <<endl; break;
            case 7: os<< "Sedano" <<endl; break;
            case 8: os<< "Senape" <<endl; break;
            case 9: os<< "Semi di Sesamo" <<endl; break;
            case 10: os<< "Anidride Solforosa" <<endl; break;
            case 11: os<< "Lupini" <<endl; break;
            case 12: os<< "Molluschi" <<endl; break;
            default: os<< "Errore" << endl;
        }
	}
	os << endl;
	return os;
}

void test_Prodotto(){
	Prodotto p("Acqua", BAR, 1);
	cout << p << endl;
	Ingrediente i("h2o", 0000, false, false);
	i.add_allergene(GLUTINE);
	i.add_allergene(MOLLUSCHI);
	Ingrediente i2("Bicchiere", 1, true, false);
	i2.add_allergene(MOLLUSCHI);
	p.set_ingredienti(&i);
	cout << p << endl;
	p.set_ingredienti(&i2);
	cout <<  p << endl;
	p.remove_ingrediente (&i);
	cout << p << endl;
	p.set_costo(3);
	cout << p << endl;
	bool disp;
	disp = p.get_disponibile();
	cout << "Disponibile: " << disp << endl;
	float cost;
	cost = p.get_costo();
	cout << "Costo: " << cost << endl;
}
