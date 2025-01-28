#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <cmath>

using namespace std;

function<double(double)> KubnaInterpolacija(vector<pair<double,double>> v){
    sort(v.begin(), v.end(), [](pair<double,double> a, pair<double,double> b){
        return a.first < b.first;
    });
    for(int i=0; i<v.size()-1; i++){
        if(v[i].first == v[i+1].first) throw domain_error("Neispravni cvorovi");
    }
    if(v.size()<4) throw domain_error("Nedovoljan broj cvorova");
    return [v](double x){
        if(x<v.at(0).first || x>v.at(v.size()-1).first) throw range_error("Argument izvan opsega");
        if(x==v.at(v.size()-1).first) return v.at(v.size()-1).second;
        int donji;
        for(int i = 0;i<v.size();i++){
            if(x>=v.at(i).first){
                donji = i;
                break;
            } 
        }
        double suma = 0;
        if(donji==0){
            for(int i=donji;i<donji+4;i++){
                double suma2 = v.at(i).second;
                for(int j=donji;j<donji+4;j++){
                    if(i!=j){
                        double temp = (x-v.at(j).first)/(v.at(i).first-v.at(j).first);
                        suma2 *=temp;
                    }
                    
                }
                suma+=suma2;
            }
        }
        else if(donji==v.size()-2){
            for(int i=donji-2;i<donji+2;i++){
                double suma2 = v.at(i).second;
                for(int j=donji-2;j<donji+2;j++){
                    if(i!=j){
                        double temp = (x-v.at(j).first)/(v.at(i).first-v.at(j).first);
                        suma2 *=temp;
                    }
                    
                }
                suma+=suma2;
            }
        }
        return suma;

    };
        

}


function<double(double)> KubnaInterpolacija (function<double(double)> fun,double xmin, double xmax,double deltax){
    if(deltax<=0 || xmin>xmax) throw domain_error("Nekorektni parametri");
    vector<pair<double,double>> v;
    while(xmin<=xmax){
        v.push_back({xmin,fun(xmin)});
        xmin+=deltax;
    }
    auto rez = KubnaInterpolacija(v);
    return rez;

}


int main(){
    cout<<"Odaberite opciju (1 - unos cvorova, 2 - aproksimacija)"<<endl;
    int izbor{};
    cin>>izbor;
    string c;
    double argument;
    if(izbor==1){
        int broj_cvorova,a,b;
        cout<<"Unesite broj cvorova"<<endl;
        cin>>broj_cvorova;
        vector<pair<double,double>> v;
        cout<<"Unesite brojeve kao parove (x,y)"<<endl;
        for(int i=0;i<broj_cvorova;i++){
            cin>>a;
            cin>>b;
            v.push_back({a,b});
        }
        
        cin.ignore(10000,'\n');
        while(true){
            cout<<"Unesite argument ili \"kraj\" za kraj"<<endl;
            getline(cin,c);
            if(c=="kraj") break;
            argument=stod(c);
            cout<<"f("<<argument<<") ="<<KubnaInterpolacija(v)(argument)<<endl;
        }
    }else{
        cout<<"Unesite krajeve intervala i korak"<<endl;
        double xmin,xmax,korak;
        cin>>xmin>>xmax>>korak;
        cin.ignore(10000,'\n');
        while(true){
            cout<<"Unesite argument ili \"kraj\" za kraj"<<endl;
            getline(cin,c);
            if(c=="kraj") break;
            argument=stod(c);
            auto fun = KubnaInterpolacija([](double x)->double {return (x*x+sin(x)+log(x+1));},xmin,xmax,korak);
            cout<<"f("<<argument<<") = "<<[](double x)->double {return (x*x+sin(x)+log(x+1));}(argument)<<" faprox("<<argument<<") = "<<fun(argument)<<endl;
        }
    }
    
    return 0;
}