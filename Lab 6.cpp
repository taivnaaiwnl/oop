#include <iostream>
#include <string>
 using namespace std;
 class Shape {
   public:
   string name;
   public:
   string get_name();
 };
 string Shape::get_name(){
   return this->name;
 }
 class twoD : public Shape{
    protected:
        float *x; 
        float *y;
        float a; 
        float s; 
        float p; 
    public:
        twoD (float a, int points);
        float get_s();
 };
 twoD::twoD (float a, int points) {
    this->a = a;
    this->x = new float [points];
    this->y = new float [points];
 }
 float twoD::get_s(){
   return this->s;
 }
 class circle: public twoD{
    public: 
       circle (float x1, float y1, float r, string name);
       float area();
       float perimetr();
       void setpoints(float *x, float *y, float x1, float y1);
       void showpoints(float *x, float *y, int size);
 };
 circle:: circle (float x1, float y1, float r, string name):twoD ( r, 1){
   this->name=name;
   cout<<"Shape name: "<< get_name() << endl;
   cout<<"Talbai: "<<this->area()<<endl;
   cout<<"Hureenii urt: "<<this->perimetr()<<endl;
   setpoints(x,y,x1,y1);
   showpoints(x,y,1);
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
 void circle::showpoints(float *x, float *y, int size){
   for(int i=0;i<size;i++){
      cout<<"Toirgiin tuv: " << x[i] << ", "<< y[i]<<endl;
   }
 }
 class square: public twoD{
    public:
       square (float a, float x1, float y1, string name);
       float area();
       float perimetr();
       void setpoints(float *x, float *y, float x1, float y1);
       void showpoints(float *x, float *y, int size);
 };
 square::square (float a, float x1, float y1, string name): twoD (a, 4){
   this->name=name;
   cout<<"Shape name: "<< get_name() << endl;
   cout<<"Talbai: "<<this->area()<<endl;
   cout<<"Hureenii urt: "<<this->perimetr()<<endl;
   setpoints(x,y,x1,y1);
   showpoints(x,y,4);
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
 void square::showpoints(float *x, float *y, int size){
   for(int i=0;i<size;i++){
      cout<<"Oroi["<<i<<"]: " << x[i] << ", "<< y[i]<<endl;
   }
 }
 class triangle:public twoD{
    public:
       triangle (float a, float x1, float y1, string name);
       float area();
       float perimetr();
       void setpoints(float *x, float *y, float x1, float y1);
       void showpoints(float *x, float *y, int size);
 };
 triangle:: triangle (float a, float x1, float y1, string name) : twoD ( a, 3){
   this->name=name;
   cout<<"Shape name: "<< get_name() << endl;
   cout<<"Talbai: "<<this->area()<<endl;
   cout<<"Hureenii urt: "<<this->perimetr()<<endl;
   setpoints(x,y,x1,y1);
   showpoints(x,y,3);
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
 void triangle::showpoints(float *x, float *y, int size){
   for(int i=0;i<size;i++){
      cout<<"Oroi["<<i<<"]: " << x[i] << ", "<< y[i]<<endl;
   }
 }
 int main()  {
   circle c1(2, 3, 5, "circle1"), c2(1, 1, 2, "circle2"); 
   square s1(5, 2, 3, "square1"), s2(3, 1, 2, "square2"); 
   triangle t1(5, 1, 1, "triangle1"), t2(2, 0, 0, "triangle2"); 
  }   

