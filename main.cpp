#include <iostream>
#include <math.h>
using namespace std;

class Figure{
protected:
    float rezult;
public:

    virtual void volum() = 0;
};

class Paralelipiped: public Figure{
private:
    int x, y, z;
public:

    void setv(float x, float y, float z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

    void volum() override
    {
        rezult = x * y * z;
        cout << "Volumul paralelipipedului: " << rezult << endl << endl;
    }
};

class Piramida: public Figure{
private:
    int x, y, h;
public:

    void setv(float x, float y, float h){
        this->x = x;
        this->y = y;
        this->h = h;
    }

    void volum() override
    {
        rezult = (x*y*h)/3;
        cout << "Volumul piramidei: " << rezult << endl << endl;
    }
};

class Tetraedru: public Figure{
private:
    int a, h;
public:

    void setv(float a, float h){
        this->a = a;
        this->h = h;
    }

    void volum() override
    {
        float A=(sqrt(3)/4)*pow(a,2);
        rezult = (0.33333333333)*A*h;
        cout << "Volumul tetraedrului: " << rezult << endl << endl;
    }
};

class Sfera: public Figure{
private:
    int r;
public:

    void setv(float r){
        this->r = r;
    }

    void volum() override
    {
        rezult =(4*3.1415*pow(r,3))/3;
        cout << "Volumul sferei: " << rezult << endl << endl;
    }
};

int main()
{
    int op;
    float a, b, c;

    Figure *abstract;

    while(1)
    {
        cout<<" ----------------------"<<endl;
        cout<<" |1. Paralelipiped    |"<<endl;
        cout<<" |2. Piramida         |"<<endl;
        cout<<" |3. Tetraedru        |"<<endl;
        cout<<" |4. Sfera            |"<<endl;
        cout<<" |0. Iesire           |"<<endl;
        cout<<" ----------------------"<<endl;
        cout<<"--> ";
        cin>>op;

      switch(op)
      {
          case 0:
              {
              cout << "Sfarsit de program\n\n";
              exit (0);
              }
              break;
          case 1:
              {
                  cout << "Introdu lungimea - ";
                  cin >> a;
                  cout << "Introdu latimea - ";
                  cin >> b;
                  cout << "Introdu inaltimea - ";
                  cin >> c;
                  Paralelipiped p;
                  p.setv(a, b, c);
                  abstract = &p;
                  abstract->volum();
              }
              break;

          case 2:
              {
                  cout << "Introdu lungimea - ";
                  cin >> a;
                  cout << "Introdu latimea - ";
                  cin >> b;
                  cout << "Introdu inaltimea - ";
                  cin >> c;
                  Piramida p;
                  p.setv(a, b, c);
                  abstract = &p;
                  abstract->volum();
              }
              break;

          case 3:
              {
                  cout << "Introdu lungimea - ";
                  cin >> a;
                  cout << "Introdu inaltimea - ";
                  cin >> c;
                  Tetraedru p;
                  p.setv(a, c);
                  abstract = &p;
                  abstract->volum();
              }
              break;

          case 4:
              {
                  cout << "Introdu raza - ";
                  cin >> a;
                  Sfera p;
                  p.setv(a);
                  abstract = &p;
                  abstract->volum();
              }
              break;
          default:
          {
              cout<<"Optiune gresita!"<<endl;
          }
      }

    }
}
