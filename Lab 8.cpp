#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
 class Shape{
    public:
        static int count;
        Shape(){
          count++;
        }
        static int getCount(){
          return count; 
        }
        void setName(string n){
          this->name = n; 
        }
        string getName(){
          return this->name;
        }
    protected:
        string name;
 };
 int Shape::count = 0;
 class twoD: public Shape{
    protected:
        float *x; 
        float *y;
        float a; 
        float s; 
        float p;
        int points;

    public:
        twoD (float a, int points);
        float get_s();
        float get_p();
        void showdata();
        virtual float area() = 0;
        virtual float perimetr() = 0;
 };
 twoD::twoD (float a, int points) {
    this->a = a;
    this->x = new float [points];
    this->y = new float [points];
 }
 float twoD::get_s(){
   return this->s;
 }
 float twoD::get_p(){
   return this->p;
 }
 void twoD::showdata(){
    cout << setw(10) << name;
    switch(points){
      case 1:{
        cout << setw(10) << "Circle";
        break;
      }
      case 3:{
        cout << setw(10) << "Triangle";
        break;
      }
      case 4:{
        cout << setw(10) << "Square";
        break;
      }
      default:{
        break;
      }
    }
    cout << setw(10) << s;
    cout << setw(10) << p;
    for(int i = 0; i < points; i++){
      cout<< "  (" << x[i] << ", "<< y[i]<< "), ";
    }
    cout << endl;
 }
 class circle: public twoD{
    public: 
       circle (float x1, float y1, float r, string name);
       float area();
       float perimetr();
       void setpoints(float *x, float *y, float x1, float y1);
       void showpoints(float *x, float *y, int points);
 };
 circle:: circle (float x1, float y1, float r, string name):twoD (r, 1){
   this->name=name;
   this->points=1;
   cout<<"Shape name: "<< getName() << endl;
   cout<<"Talbai: "<<this->area()<<endl;
   cout<<"Hureenii urt: "<<this->perimetr()<<endl;
   setpoints(x,y,x1,y1);
   showpoints(x,y,points);
   cout<<endl;
 }
 float circle::area(){
    this->s = 3.14 * this->a * this->a;
    return this->s; 
 } 
 float circle::perimetr(){
   this->p = 2 * 3.14 * this->a;
   return this->p; 
 }
 void circle::setpoints(float *x, float *y, float x1, float y1){
   x[0]=x1;
   y[0]=y1;
 }
 void circle::showpoints(float *x, float *y, int points){
      cout<<"Toirgiin tuv: " << x[0] << ", "<< y[0]<<endl;
 }
 class square: public twoD{
    public:
       square (float a, float x1, float y1, string name);
       float area();
       float perimetr();
       void setpoints(float *x, float *y, float x1, float y1);
       void showpoints(float *x, float *y, int points);
 };
 square::square (float a, float x1, float y1, string name): twoD (a, 4){
   this->name=name;
   this->points=4;
   cout<<"Shape name: "<< getName() << endl;
   cout<<"Talbai: "<<this->area()<<endl;
   cout<<"Hureenii urt: "<<this->perimetr()<<endl;
   setpoints(x,y,x1,y1);
   showpoints(x,y,points);
   cout<<endl;
 }
 float square::area(){
   this->s = this->a * this->a;
   return  this->s; 
 }
 float square::perimetr(){
   this->p = 4* this->a;
   return this->p; 
 }
 void square::setpoints(float *x, float *y, float x1, float y1){
   x[0]=x1;
   y[0]=y1;
   x[1]=x1+a;
   y[1]=y1;
   x[2]=x1;
   y[2]=y1+a;
   x[3]=x1+a;
   y[3]=y1+a;
 }
 void square::showpoints(float *x, float *y, int points){
   for(int i=0;i<points;i++){
      cout<<"Oroi["<<i<<"]: " << x[i] << ", "<< y[i]<<endl;
   }
 }
 class triangle:public twoD{
    public:
       triangle (float a, float x1, float y1, string name);
       float area();
       float perimetr();
       void setpoints(float *x, float *y, float x1, float y1);
       void showpoints(float *x, float *y, int points);
 };
 triangle:: triangle (float a, float x1, float y1, string name) : twoD (a, 3){
   this->name=name;
   this->points=3;
   cout<<"Shape name: "<< getName() << endl;
   cout<<"Talbai: "<<this->area()<<endl;
   cout<<"Hureenii urt: "<<this->perimetr()<<endl;
   setpoints(x,y,x1,y1);
   showpoints(x,y,points);
   cout<<endl;
 }
 float triangle::area(){
   this->s = 0.5 * this->a * this->a * 0.866; 
   return  this->s; 
 }
 float triangle::perimetr(){
   this->p = 3 * this->a;
   return this->p; 
 }
 void triangle::setpoints(float *x, float *y, float x1, float y1){
   x[0]=x1;
   y[0]=y1;
   x[1]=x1-a*0.5;
   y[1]=y1-a*0.866;
   x[2]=x1+a*0.5;
   y[2]=y1-a*0.866;

 }
 void triangle::showpoints(float *x, float *y, int points){
   for(int i=0;i<points;i++){
      cout<<"Oroi["<<i<<"]: " << x[i] << ", "<< y[i]<<endl;
   }
 }
void heading() {
    cout << setw(10) << "ShapeName";
    cout << setw(10) << "ShapeType";
    cout << setw(10) << "Size";
    cout << setw(10) << "Perimeter";
    cout << setw(5) << "  ShapePoints";
    cout << endl;
}

 int main()  {
   circle c1(2, 3, 5, "circle1"), c2(1, 1, 2, "circle2"); 
   square s1(5, 2, 3, "square1"), s2(3, 1, 2, "square2"); 
   triangle t1(5, 1, 1, "triangle1"), t2(2, 0, 0, "triangle2"); 

   twoD *sh[6];
   twoD *temp;
   sh[0] = &c1;
   sh[1] = &c2;
   sh[2] = &s1;
   sh[3] = &s2;
   sh[4] = &t1;
   sh[5] = &t2;

   cout << "Shape infos:"<<endl;
   heading();
   for(int i=0; i<6; i++){
      sh[i]->showdata();
   }
   for (int i = 0; i < 5; i++){
     for (int j = i + 1; j < 6; j++){
        if (sh[i]->get_s() > sh[j]->get_s()){
            temp = sh[j];
            sh[j] = sh[i];
            sh[i] = temp;
         }
      }
   }

   cout << endl << "Talbaigaar erembeleltiin daraa:" <<endl;
   heading();
   for(int i=0; i<6; i++){
      sh[i]->showdata();
   }

   for (int i = 0; i < 5; i++){
     for (int j = i + 1; j < 6; j++){
        if (sh[i]->get_p() > sh[j]->get_p()){
            temp = sh[j];
            sh[j] = sh[i];
            sh[i] = temp;
         }
      }
   }
   cout << endl << "Perimetreer erembeleltiin daraa:" <<endl;
   heading();
   for(int i=0; i<6; i++){
      sh[i]->showdata();
   }

   cout << endl << "Dursiin too: " << Shape::getCount() << endl;
  }   
