#include<iostream>
#include<cmath>
using namespace std;
const double pi=4*atan(1);
int main(){
    double a,b,c;
    cin>>a>>b>>c;
    if(a+b>c && a+c>b && b+c>a){
        double obim=a+b+c;
        double povrsina=sqrt((obim/2)*(obim/2-a)*(obim/2-b)*(obim/2-c));
        double alfa=acos((b*b+c*c-a*a)/(2*b*c))*(180/pi);
        double beta=acos((a*a+c*c-b*b)/(2*a*c))*(180/pi);
        double gama=acos((b*b+a*a-c*c)/(2*b*a))*(180/pi);
        cout<<alfa<<" "<<beta<<" "<<gama<<endl;
        cout<<"obim: "<<obim<<endl;
        cout<<"povrsina: "<<povrsina<<endl;
        if(alfa<=beta && alfa<=gama){
        int stepen=int(alfa);
        double ostatak=alfa-int(alfa);
        double minuta=ostatak*60;
        ostatak=minuta-int(minuta);
        double sekunda=ostatak*60;
        cout<<"min ugao ima "<<stepen<<" stepeni, minuta "<<int(minuta)<<" i sekundi "<<int(sekunda)<<endl;
        }
        if(beta<=alfa && beta<=gama){
        int stepen=int(beta);
        double ostatak=beta-int(beta);
        double minuta=ostatak*60;
        ostatak=minuta-int(minuta);
        double sekunda=ostatak*60;
        cout<<"min ugao ima "<<stepen<<" stepeni, minuta "<<int(minuta)<<" i sekundi "<<int(sekunda)<<endl;
        }
        if(gama<=beta && gama<=alfa){
        int stepen=int(gama);
        double ostatak=gama-int(gama);
        double minuta=ostatak*60;
        ostatak=minuta-int(minuta);
        double sekunda=ostatak*60;
        cout<<"min ugao ima "<<stepen<<" stepeni, minuta "<<int(minuta)<<" i sekundi "<<int(sekunda)<<endl;
        }
    }
    else{
        cout<<"ne postoji trougao"<<endl;
    }

    return 0;
}