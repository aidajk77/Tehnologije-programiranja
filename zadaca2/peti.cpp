#include<iostream>
#include<type_traits>
#include<vector>
#include<deque>

using namespace std;

template < typename kontejner1, typename kontejner2>
auto KreirajTablicuMnozenja (kontejner1 k1, kontejner2 k2) -> remove_reference_t<decltype(*k1.begin()* *k2.begin())>**{
    if(k1.end()-k1.begin() != k2.end()-k2.begin()){
        throw range_error("Kontejneri nisu iste duzine");
    }
    using Tip = remove_reference_t<decltype(*k1.begin() * *k2.begin())>;
    try{
        int broj_elemenata=0;
        int velicina=k2.end()-k2.begin();
        auto start=k2.begin();
        while(start!=k2.end()){
            broj_elemenata=broj_elemenata+k2.end()-start;
            start++;
        }
        auto m=new Tip*[velicina];
        int pozicija=1;
        try{
            m[0]=new Tip[broj_elemenata];
            for(int i=1;i<velicina;i++){
                m[i]=m[i-1]+pozicija;
                pozicija++;
            }
            bool je_li_komutativno=false;
            auto p1=k1.begin();
            auto p2=k2.begin();
            for(int i=0;i<k2.end()-k2.begin();i++){
                for(int j=0;j<i+1;j++){
                    if(((*p1)* (*p2))==((*p2)* (*p1))){
                        m[i][j]=(*p1)* (*p2);
                        p2++;
                        je_li_komutativno=true;

                    }else{
                        je_li_komutativno=false;
                        break;
                    }
                }
                if(!je_li_komutativno){
                    delete[] m;
                    throw logic_error("Nije ispunjena komutativnost");
                }
                p1++;
                p2=k2.begin();
            }
        }
        catch(bad_alloc &e){
            delete[] m;
            throw range_error("Neuspjela alokacija");
        }    
        return m;
    }catch(bad_alloc &e){
        throw range_error("Neuspjela alokacija");
    }

}

int main(){
    cout<<"Duzina sekvenci: "<<endl;
    int a,b;
    cin>>a;
    vector<double> v;
    cout<<"elementi prve sekvence"<<endl;
    for(int i=0;i<a;i++){
        cin>>b;
        v.push_back(b);
    }
    deque<double> d;
    cout<<"elementi druge sekvence"<<endl;
    for(int i=0;i<a+1;i++){
        cin>>b;
        d.push_back(b);
    }
    auto m=KreirajTablicuMnozenja(v,d);
    for(int i=0;i<a;i++){
        for(int j=0;j<i+1;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }

    
    return 0; 
}