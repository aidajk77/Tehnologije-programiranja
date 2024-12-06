#include <iostream>

using namespace std;


struct Vrijeme{
    int sati;
    int minute;
    int sekunde;
};

void TestirajVrijeme(Vrijeme v){
    if(v.sati < 0 || v.sati > 0 || v.minute < 0 || v.minute > 60 || v.sekunde < 0 || v.sekunde > 60){
        throw domain_error("Neispravno vrijeme");
    }
}

void IspisiVrijeme(Vrijeme v){

    TestirajVrijeme(v);

    if(v.sati<10) cout << "0" <<v.sati<<":";
    else cout << v.sati <<":";

    if(v.minute<10) cout << "0" <<v.minute<<":";
    else cout << v.minute <<":";

    if(v.sekunde<10) cout << "0" <<v.sekunde<<":";
    else cout << v.sekunde <<":";
}

Vrijeme ZbirVremena(Vrijeme v1, Vrijeme v2){
    try{
    TestirajVrijeme(v1);
    TestirajVrijeme(v2);
    }catch(domain_error &e){
        throw e;
    }

    Vrijeme v3 = {0,0,0};

    if(v1.sekunde + v2.sekunde > 60){
        v3.minute++;
        v3.sekunde=v1.sekunde + v2.sekunde - 60;
    } 
    else v3.sekunde = v1.sekunde + v2.sekunde;

    if(v1.minute + v2.minute > 60){
        v3.sati++;
        v3.minute=v1.minute + v2.minute - 60;
    } 
    else v3.minute = v1.minute + v2.minute;

    if(v1.sati + v2.sati > 23) v3.sati=v3.sati+v1.sati + v2.sati - 24;
    else v3.sati =v3.sati + v1.sati + v2.sati;
    
}



int main(){
    try { 
    Vrijeme v1, v2; 
    std::cout << "Unesite prvo vrijeme (h m s): "; 
    std::cin >> v1.sati >> v1.minute >> v1.sekunde; 
    TestirajVrijeme(v1); 
    std::cout << "Unesite drugo vrijeme (h m s): "; 
    std::cin >> v2.sati >> v2.minute >> v2.sekunde; 
    TestirajVrijeme(v2); 
    std::cout << "Prvo vrijeme: "; 
    IspisiVrijeme(v1); 
    std::cout << std::endl << "Drugo vrijeme: "; 
    IspisiVrijeme(v2); 
    std::cout << std::endl << "Zbir vremena: "; 
    IspisiVrijeme(ZbirVremena(v1, v2)); 
    std::cout << std::endl; 
  } 
  catch(std::domain_error e) { 
    std::cout << e.what() << std::endl; 
  } 
  return 0;
}