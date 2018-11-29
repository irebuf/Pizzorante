#include "pizzorante.h"

Delivery::Delivery(int _q, string _n, Prodotto* _p, 
		unsigned int _anno, unsigned int _mese, unsigned int _giorno, unsigned int _ora, unsigned int _minuto, unsigned int _secondi,
		Responsabile *resp, string _via, string _citta, int _numero, int _cap,  string _nome, string _cognome, string _num_tel) : 
		data_consegna(_anno, _mese, _giorno, _ora, _minuto, _secondi),
		responsabile (resp), Ordine(_q, _n, _p), 
		consegna(_via, _citta, _numero, _cap, _nome, _cognome, _num_tel){
			set<RigaOrdine>::iterator iter;
			sub_totale = 0;
			for(iter = get_begin_prodotti(); iter != get_end_prodotti(); iter++){
				sub_totale = sub_totale + (*iter).get_sub_totale();
			}
}

Data Delivery::get_data_consegna() const{
	return data_consegna;
}

Responsabile* Delivery::get_responsabile() const{
	return responsabile;
}

void Delivery::set_responsabile(Responsabile* _resp){
	responsabile = _resp;
}

void Delivery::set_data(unsigned int _anno, unsigned int _mese, unsigned int _giorno, unsigned int _ora, unsigned int _minuto, unsigned int _secondi){
	data_consegna = Data(_anno, _mese, _giorno, _ora, _minuto, _secondi);
}

float Delivery::aggiorna_sub_totale() {
	set<RigaOrdine>::iterator iter;
	sub_totale = 0;
	for(iter = get_begin_prodotti(); iter != get_end_prodotti(); iter++){
		sub_totale = sub_totale + (*iter).get_sub_totale();
	}
	return sub_totale;
}

void Delivery::add_prodotti_delivery(RigaOrdine _prodotto){
	add_prodotti(_prodotto);
	sub_totale = aggiorna_sub_totale();
}

float Delivery::get_sub_totale() const{
	return sub_totale;
}

ostream& operator << (ostream& os, const Delivery& d){
	os <<"Ordine " << d.get_id_ordine() << endl;
	set<RigaOrdine>::iterator iter;
	for (iter = d.get_begin_prodotti(); iter != d.get_end_prodotti(); iter++){
		os << *(iter) << endl;
	}
	os << "Del" << d.get_data() << endl;
	os <<"Operatore: " << *(d.responsabile) << endl;
	os << "Totale: Euro " << d.sub_totale << endl;
	os <<"Consegna prevista: " << d.get_data_consegna() << endl;
    return os;
}

void test_delivery(){
	
}
