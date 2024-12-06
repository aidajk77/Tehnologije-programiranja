#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
typedef vector<vector<double>> matrica;
matrica MedijanskiFilter(matrica m,int n){
    if(n<0) throw domain_error("neispravan red filtriranja");
    matrica rez(m.size());
    for(int i=0;i<m.size();i++){
        rez.at(i).resize(m.at(i).size());
    }
    vector<double> v;
    double zamjena;
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m.at(i).size();j++){
            for(int y=-n;y<=n;y++){
                for(int x=-n;x<=n;x++){
                    if(i+y>-1 && i+y<m.size() && j+x>-1 && j+x<m.at(i+y).size()){
                        v.push_back(m.at(i+y).at(j+x));

                    }
                }
            }
            for(int k=0;k<v.size();k++){
                for(int u=k+1;u<v.size();u++){
                    if(v.at(k)>v.at(u)){
                        int temp=v.at(k);
                        v.at(k)=v.at(u);
                        v.at(u)=temp;
                    }

                }

            }
            
            if(v.size()%2==1){
                
                zamjena=v.at(v.size()/2);
            }
            else{
                zamjena=(v.at(v.size()/2)+v.at(v.size()/2-1))/2;
            }
            rez.at(i).at(j)=zamjena;
            v.clear();
            
        }
    }

    return rez;

}

int main(){
    cout<<"Unesite broj redova i kolona matrice: Unesite elemente matrice: Unesite red filtriranja:"<<endl;
    int a,b,n;
    double c;
    cin>>a>>b;
    vector<vector<double>> m1(a);
    for(int i=0;i<a;i++){
        m1.at(i).resize(b);
    }

    for(int i=0;i<m1.size();i++){
        for(int j=0;j<m1.at(i).size();j++){
            cin>>c;
            m1.at(i).at(j)=c;
        }
    }
    cin>>n;
    if(n<0){
        cout<<"GRESKA: Neispravan red filtriranja!"<<endl;
        return 0;
    }
    cout<<"Matrica nakon filtriranja:"<<endl;
    auto m=MedijanskiFilter(m1,n);
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m.at(i).size();j++){
            cout<<setw(7)<<setprecision(2)<<fixed<<m.at(i).at(j)<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}