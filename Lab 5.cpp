#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;
 
class Ajilchin{
    private:
    int dugaar;
    char* ner;
    char* job;
    float workhour;
 
    public:
    Ajilchin(){
        dugaar = 0;
        ner = new char[1];
        strcpy(ner, "");
        job = new char[9];
        strcpy(job, "Ajilchin");
        workhour = 0;
    }
    Ajilchin(int id, char* name, char* position, float time){
        dugaar = id;
        ner = new char[strlen(name)+1];
        strcpy(ner, name);
        job = new char[strlen(position)+1];
        strcpy(job, position);
        workhour = time;
    }
    Ajilchin(Ajilchin &a){
        dugaar = a.getdugaar();
        delete ner;
        ner = new char[strlen(a.getName())+1];
        strcpy(ner, a.getName());
        delete job;
        job = new char[strlen(a.getRank())+1];
        strcpy(job, a.getRank());
        workhour = a.getTime();
    }
    ~Ajilchin(){
        cout<<"Objectiig ustgasan"<<endl;
    }
    void setdugaar(int a);
    void setName(char *a);
    void setRank(char *a);
    void setTime(float a);
    int getdugaar();
    char* getName();
    char* getRank();
    float getTime();

    void setData();
    void inputData();
    void showData();

    float TsalinBodoh();
    bool TsagNemegduuleh(float h);
    void copy(Ajilchin &a);
    private:
    float ZahirlinTsalinBodoh();
};

void Ajilchin::setdugaar(int a){
    dugaar = a;
}
void Ajilchin::setName(char *a){
    delete ner;
    ner = new char[strlen(a)+1];
    strcpy(ner, a);
}
void Ajilchin::setRank(char *a){
    delete job;
    job = new char[strlen(a)+1];
    strcpy(job, a);
}
void Ajilchin::setTime(float a){
    workhour = a;
}
int Ajilchin::getdugaar(){
    return dugaar;
}
char* Ajilchin::getName(){
    return ner;
}
char* Ajilchin::getRank(){
    return job;
}
float Ajilchin::getTime(){
    return workhour;
}
void Ajilchin::inputData(){
    cout<<"dugaaraa oruulna uu: ";
    cin>>dugaar;
    cout<<"neree oruulna uu: ";
    cin>>ner;
    cout<<"Alban tushaalaa oruulna uu: ";
    cin>>job;
    cout<<"Ajillasan tsagaa oruulna uu: ";
    cin>>workhour;
}

void Ajilchin::showData(){
    cout << endl;
    cout << setw(6) << dugaar;
    cout << setw(20) << ner;
    cout << setw(15) << job;
    cout << setw(6) << workhour;
    cout << setw(10) << TsalinBodoh();

}

float Ajilchin::ZahirlinTsalinBodoh(){
    float Tsalin = workhour * 500;
    return Tsalin;
}
 
float Ajilchin::TsalinBodoh(){
    float t=0;
    t= workhour * 1000;
    if(strcmp(job, "Zahiral")==0){
        t += ZahirlinTsalinBodoh();
    }
    return t;
}

bool Ajilchin::TsagNemegduuleh(float h){
    cout<<job<<" "<<ner<<"-iin ajillasan tsagiig nemegduulj baina..."<<endl;
    if(h>0 && h<=24){
        workhour+=h;
        cout<<"Amjilttai!"<<endl;
        return 1;
    }
    else {
        cout<<"Amjiltgui!"<<endl;
        return 0;
    }
}

void Ajilchin::copy(Ajilchin &a){
    dugaar = a.getdugaar();
    delete ner;
    ner = new char[strlen(a.getName())+1];
    strcpy(ner, a.getName());
    delete job;
    job = new char[strlen(a.getRank())+1];
    strcpy(job, a.getRank());
    workhour = a.getTime();
}

void heading() {
    cout << endl;
    cout << setw(6) << "Dugaar";
    cout << setw(20) << "Ner";
    cout << setw(15) << "Alban Tushaal";
    cout << setw(6) << "Tsag";
    cout << setw(10) << "Tsalin";
}

int main(){
    int n, i, j;
    bool k=0;
    cin >> n;
    Ajilchin emp[n],swp;
    cout<<"1 dugaar ajiltnii medeelliig oruulna uu"<<endl;
    emp[0].inputData();

    for(i = 1; i < n; i++){
        cout << i + 1 << " dugaar ajiltnii medeelliig oruulna uu:" << endl;
        emp[i].inputData();
        for(j = 0; j < i; j++){
            k=0;
            if(emp[i].getdugaar()==emp[j].getdugaar()) {
                cout << "ID dugaar davhtsaj baina, ID dugaariig dahin oruulna uu: ";
                int newid;
                cin >> newid;
                emp[i].setdugaar(newid);
                k=1;
                }
            if(k==1){
                j=-1; 
            }
        }
    }
    heading();
    for(i = 0; i < n; i++){
        emp[i].showData();
        cout<<endl;
    }

    for(i = 0; i < n-1 ;i++){
        for(j = i; j < n; j++){
            if(strcmp(emp[i].getName(),emp[j].getName())>0){
                swp.copy(emp[i]);
                emp[i].copy(emp[j]);
                emp[j].copy(swp);
            }
        }
    }
    cout<<"Nereer eremblesen ni";
    heading();
    for(i = 0; i < n; i++){
        emp[i].showData();
        cout<<endl;
    }


    return 0;
}

