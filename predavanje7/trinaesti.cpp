#include <iostream>
#include <list>
#include <queue>
#include <iterator>


using namespace std;

void RotirajKoloneMatrice(list<list<double>>& m){
    queue<bool> red;
    int size = (*m.begin()).size();
    for(auto it1 = m.begin();it1!=m.end();it1++){
        for(auto it2 = (*it1).begin();it2!=(*it1).end();it2++){
            swap(*(*it1).begin(),*it2);
        }
    }
}

queue<bool> RotirajRedoveMatrice(list<list<double>>& m){
    queue<bool> red;
    int size = (*m.begin()).size();
    for(auto it1 = m.begin();it1!=m.end();it1++){
        if((*it1).size()!=size) throw domain_error("Parametar nema formu matrice");
        double product=1;
        for(auto it2 = (*it1).begin();it2!=(*it1).end();it2++){
            product*=*it2;
        }
        if(product>0) red.push(true);
        else red.push(false);
    }   
    for(auto it1 = next(m.begin());it1!=m.end();it1++){
        swap(*m.begin(),*it1);


    }

    return red;

}

int main(){
    int a,b;
    double c;
    cout<<"unesite dimenzije"<<endl;
    cin>>a>>b;
    list<list<double>> m(a);
    cout<<"unesite elemente"<<endl;
    for(auto it=m.begin();it!=m.end();it++){
        for(int i=0;i<b;i++){
            cin>>c;
            (*it).insert((*it).end(),c);
        }
    }
    //auto red = RotirajMatrice(m);
    RotirajKoloneMatrice(m);
    for(auto it = m.begin();it!=m.end();it++){
        for(auto it2 = (*it).begin();it2!=(*it).end();it2++){
            cout<<*it2<<" ";
        }
        cout<<endl;
    }

    /*while(!red.empty()){
        cout<<red.front()<<" ";
        red.pop();
    }*/


    return 0;
}