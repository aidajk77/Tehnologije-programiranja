#include<iostream>
#include<string>
#include<vector>
using namespace std;



enum class Pravci {Sjever, Istok, Jug, Zapad};
enum class Smjer {Nadesno, Nalijevo};

void Idi(int &x, int &y, Pravci orijentacija, int korak) {
    int dx[]{0, 1, 0, -1}, dy[]{1, 0, -1, 0};
    x += korak * dx[int(orijentacija)]; y += korak * dy[int(orijentacija)];
}


void Rotiraj(Pravci &orijentacija, Smjer na_koju_stranu) {
    if(na_koju_stranu == Smjer::Nadesno) 
    orijentacija = Pravci((int(orijentacija) + 1) % 4);
    else orijentacija = Pravci((int(orijentacija) + 3) % 4);
}

void IspisiPoziciju(int x, int y, Pravci orijentacija) {
    string tekstovi[]{"Sjever", "Istok", "Jug", "Zapad"};
    cout << "Robot se nalazi na poziciji (" << x << ", " << y << ") i gleda na "<< tekstovi[int(orijentacija)] << ".\n";
}

int main(){
    int x = 0, y = 0;
    Pravci orijentacija = Pravci::Sjever;
    Idi(x, y,orijentacija, 5);
    Rotiraj(orijentacija, Smjer::Nalijevo);
    Idi(x, y,orijentacija, 3);
    IspisiPoziciju(x, y, orijentacija);
    return 0;
}