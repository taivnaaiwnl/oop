#include <iostream>
#include <string.h>
 
using namespace std;
 
class Ajilchin{
    private:
    int Dugaar;
    char Ner[20];
    char AlbanTushaal[10];
    float AjillasanTsag;
 
    public:
    void UtgaOnooh();
    void UtgaAwah();
    void MedeelelDelgetsleh();
    float TsalinBodoh();
    float ZahirlinTsalinBodoh();
    bool TsagNemegduuleh(float h);
};
 
void Ajilchin::UtgaAwah(){
    cout<<"Dugaaraa oruulna uu: ";
    cin>>Dugaar;
    cout<<"Neree oruulna uu: ";
    cin>>Ner;
    cout<<"Alban tushaalaa oruulna uu: ";
    cin>>AlbanTushaal;
    cout<<"Ajillasan tsagaa oruulna uu: ";
    cin>>AjillasanTsag;
}
 
void Ajilchin::UtgaOnooh(){
    cout<<"Utga onooj baina..."<<endl;
    Dugaar= 0;
    strcpy(Ner, "");
    strcpy(AlbanTushaal, "Ajilchin");
    AjillasanTsag = 0;
}

void Ajilchin::MedeelelDelgetsleh(){
    cout<<"Dugaar: "<<Dugaar<<endl;
    cout<<"Ner: "<<Ner<<endl;
    cout<<"Alban Tushaal: "<<AlbanTushaal<<endl;
    cout<<"Ajillasan Tsag: "<<AjillasanTsag<<endl;
    cout<<"Tsalin: "<<TsalinBodoh()<<endl;
}

float Ajilchin::ZahirlinTsalinBodoh(){
    float Tsalin =AjillasanTsag * 500;
    return Tsalin;
}
 
float Ajilchin::TsalinBodoh(){
    float t=0;
    t= AjillasanTsag * 1000;
    if(strcmp(AlbanTushaal, "Zahiral")==0){
        t += ZahirlinTsalinBodoh();
    }
    return t;
}

bool Ajilchin::TsagNemegduuleh(float h){
    cout<<AlbanTushaal<<" "<<Ner<<"-iin ajillasan tsagiig nemegduulj baina..."<<endl;
    if(h>0 && h<=24){
        AjillasanTsag+=h;
        cout<<"Amjilttai!"<<endl;
        return 1;
    }
    else {
        cout<<"Amjiltgui!"<<endl;
        return 0;
    }
}
 
int main(){
Ajilchin a1,Bat;

a1.UtgaOnooh();
a1.MedeelelDelgetsleh();
a1.TsagNemegduuleh(4.0);
a1.MedeelelDelgetsleh();

Bat.UtgaAwah();
Bat.MedeelelDelgetsleh();

return 0;
}

