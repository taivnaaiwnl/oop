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
    Ajilchin(){
        Dugaar = 0;
        strcpy(Ner, "");
        strcpy(AlbanTushaal, "Ajilchin");
        AjillasanTsag = 0;
    }
    Ajilchin(int id, char* name, char* position, float time){
        Dugaar = id;
        strcpy(Ner, name);
        strcpy(AlbanTushaal, position);
        AjillasanTsag = time;
    }
    ~Ajilchin(){
        cout<<"Objectiig ustgasan"<<endl;
    }
    void setDugaar(int a);
    void setName(char *a);
    void setRank(char *a);
    void setTime(float a);
    int getDugaar();
    char* getName();
    char* getRank();
    float getTime();
    void inputData();
    void showData();
    float TsalinBodoh();
    bool TsagNemegduuleh(float h);
    
    private:
    float ZahirlinTsalinBodoh();
};

void Ajilchin::setDugaar(int a){
    Dugaar = a;
}
void Ajilchin::setName(char *a){
    strcpy(Ner, a);
}
void Ajilchin::setRank(char *a){
    strcpy(AlbanTushaal, a);
}
void Ajilchin::setTime(float a){
    AjillasanTsag = a;
}
int Ajilchin::getDugaar(){
    return Dugaar;
}
char* Ajilchin::getName(){
    return Ner;
}
char* Ajilchin::getRank(){
    return AlbanTushaal;
}
float Ajilchin::getTime(){
    return AjillasanTsag;
}
void Ajilchin::inputData(){
    cout<<"Dugaaraa oruulna uu: ";
    cin>>Dugaar;
    cout<<"Neree oruulna uu: ";
    cin>>Ner;
    cout<<"Alban tushaalaa oruulna uu: ";
    cin>>AlbanTushaal;
    cout<<"Ajillasan tsagaa oruulna uu: ";
    cin>>AjillasanTsag;
}

void Ajilchin::showData(){
    cout<<"Dugaar: "<<Dugaar<<endl;
    cout<<"Ner: "<<Ner<<endl;
    cout<<"Alban Tushaal: "<<AlbanTushaal<<endl;
    cout<<"Ajillasan Tsag: "<<AjillasanTsag<<endl;
    cout<<"Tsalin: "<<TsalinBodoh()<<endl;
}

float Ajilchin::ZahirlinTsalinBodoh(){
    float Tsalin = AjillasanTsag * 500;
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
    int n, i, j;
    cin >> n;
    double salary[n],sswp;
    Ajilchin emp[n],swp;
    for(i = 0; i < n; i++){
        cout << i << " dugaar ajiltnii medeelliig oruulna uu:" << endl;
        emp[i].inputData();
        salary[i]=emp[i].TsalinBodoh();
        cout << "Tsalin: "<<salary[i]<<endl;
    }
    for(i = 0; i < n-1; i++){
        for(j = i + 1; j < n ; j++){
            if(salary[i] < salary[j]){
                swp.setDugaar(emp[i].getDugaar());
                swp.setName(emp[i].getName());
                swp.setRank(emp[i].getRank());
                swp.setTime(emp[i].getTime());
                sswp=salary[i];
                emp[i].setDugaar(emp[j].getDugaar());
                emp[i].setName(emp[j].getName());
                emp[i].setRank(emp[j].getRank());
                emp[i].setTime(emp[j].getTime());
                salary[i]=salary[j];
                emp[j].setDugaar(swp.getDugaar());
                emp[j].setName(swp.getName());
                emp[j].setRank(swp.getRank());
                emp[j].setTime(swp.getTime());
                salary[j]=sswp;
            }
        }
    }
    for(i = 0; i < n; i++){
        emp[i].showData();
        cout<<endl;
    }
    Ajilchin e1, e2;
    e2.inputData();
    Ajilchin e3(976, "Bold", "Zahiral", 8);
    e1.showData();
    e2.showData();
    e3.showData();
    return 0;
}

