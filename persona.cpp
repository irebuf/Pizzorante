#include "pizzorante.h"

Persona:: Persona(string _nome, string _cognome){
    nome=_nome;
    cognome=_cognome;
}

string Persona::get_nome()const{
    return nome;
}
string Persona::get_cognome()const{
    return cognome;
}

ostream& operator << (ostream& os, const Persona &_persona){
    os<<_persona.nome<<" "<<_persona.cognome<<endl;
    return os;
}
 
void Persona::set_nome(string _nome){
    nome=_nome;
}
void Persona::set_cognome(string _cognome){
    cognome=_cognome;
}

void test_persona(){
    Persona p("Irene","Buffa");
    cout << p;
    cout << "Get nome:"<<p.get_nome()<<endl;
    cout << "Get cognome:"<<p.get_cognome()<<endl;
    p.set_nome("Giovanni");
    cout << p;
    p.set_cognome("Rizzi");
    cout << p;
}
