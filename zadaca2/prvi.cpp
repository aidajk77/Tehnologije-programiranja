#include<iostream>
namespace {
    enum class Pravci {Sjever, Sjeveroistok, Istok, Jugoistok, Jug, Jugozapad, Zapad, 
Sjeverozapad}; 
enum class KodoviGresaka {PogresnaKomanda, NedostajeParametar, SuvisanParametar, 
NeispravanParametar}; 
enum class Komande {Idi, Rotiraj, Sakrij, Otkrij, PrikaziTeren, Kraj};  
// Ovdje će ići i deklaracije raznih pomoćnih stvari koje će Vam trebati za 
//  potrebe implementacije robota... 
void KreirajTeren(int xmin, int xmax, int ymin, int ymax, int &x, int &o, 
Pravci &orijentacija); 
bool Idi(int &x, int &y, Pravci orijentacija, int korak); 
void Rotiraj(Pravci &orijentacija, int ugao); 
void Sakrij(); 
void Otkrij(); 
void IspisiPoziciju(int x, int y, Pravci orijentacija); 
void PrikaziTeren(); 
void PrijaviGresku(KodoviGresaka kod_greske); 
bool IzvrsiKomandu(Komande komanda, int parametar, int &x, int &y, 
Pravci &orijentacija);  
bool UnosKomande(Komande &komanda, int &parametar, KodoviGresaka &kod_greske);
}