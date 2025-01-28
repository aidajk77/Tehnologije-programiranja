#include <iostream>

using namespace std;

template <typename tip>
    struct Cvor{
        tip element;
        Cvor<tip>* veza;
    };

template <typename TipElemenata>  
    Cvor<TipElemenata> *KreirajPovezanuListu(const TipElemenata &zavrsni){
        Cvor<TipElemenata>* pocetak{};
        Cvor<TipElemenata>* prethodni;
        for(;;){
            TipElemenata t;
            cin>>t;
            if(t==zavrsni) return pocetak;
            Cvor<TipElemenata>* novi = new Cvor<TipElemenata> {t,nullptr};
            if(!pocetak) pocetak = novi;
            else prethodni->veza = novi;
            prethodni = novi;
        }
    }

template <typename TipElemenata> 
    int BrojElemenata(Cvor<TipElemenata> *pocetak){
        int brojac = 0;
        Cvor<TipElemenata>* pomocni=pocetak;
        while(pomocni){
            brojac++;
            pomocni=pomocni->veza;
        }
        return brojac;

    }

template <typename TipElemenata> 
    TipElemenata SumaElemenata(Cvor<TipElemenata> *pocetak){
        TipElemenata suma{};
        Cvor<TipElemenata>* pomocni=pocetak;
        while(pomocni){
            suma+=pomocni->element;
            pomocni=pomocni->veza;
        }
        return suma;
    }

template <typename TipElemenata> 
    int BrojVecihOd(Cvor<TipElemenata> *pocetak, const TipElemenata &prag){
        int brojac=0;
        Cvor<TipElemenata>* pomocni = pocetak;
        while(pomocni){
            if(pomocni->element>prag) brojac++;
            pomocni=pomocni->veza;
        }
        return brojac;

    }

template <typename TipElemenata> 
    void UnistiListu(Cvor<TipElemenata> *pocetak){
        while (pocetak != nullptr) {
        Cvor<TipElemenata> *sljedeci = pocetak->veza; 
        delete pocetak; 
        pocetak = sljedeci;
    }
    }

int main(){

    std::cout << "Unesite slijed brojeva (0 za kraj): "; 
    auto lista = KreirajPovezanuListu<double>(0); 
    std::cout << "U slijedu ima " 
        << BrojVecihOd(lista, SumaElemenata(lista) / BrojElemenata(lista)) 
        << " brojeva vecih od njihove aritmeticke sredine\n"; 
    UnistiListu(lista); 
    return 0; 
}