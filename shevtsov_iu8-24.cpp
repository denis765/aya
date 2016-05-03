#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <iostream>
#include <cmath>

using namespace std;

class Complex         
{
private:
  double deist, mnim;     

public:
  // конструкторы 

  Complex ()
  {
  };

  Complex (double d)   
  {
    deist = d;
    mnim = 0;
  }

  Complex (double d, double m)
  {
    deist = d;
    mnim = m;
  }

  Complex (const Complex &c)  
  {
    deist = c.deist;
    mnim = c.mnim;
  }

  ~Complex ()
  {
  }

  double abs ()        
  {
    return sqrt (deist * deist + mnim * mnim);
  }

  Complex& operator = (Complex &c)   
  {
    deist = c.deist;
    mnim = c.mnim;

    return (*this);
  }

  Complex operator + (const Complex &c)   
  {
    return Complex (deist + c.deist, mnim + c.mnim);
  }

  Complex operator - (const Complex &c)   
  {
    return Complex(deist - c.deist, mnim - c.mnim);
  }

  Complex operator * (const Complex &c)   
  {
    return Complex(deist * c.deist - mnim * c.mnim, deist * c.mnim + mnim * c.deist);
  }

  Complex operator / (const Complex &c)   
  {
    Complex temp;

    double r = c.deist * c.deist + c.mnim * c.mnim;
    temp.re = (deist * c.deist + mnim * c.mnim) / d;
    temp.im = (mnim * c.deist - deist * c.mnim) / d;

    return temp;
  }

  friend ostream & operator<< (ostream &, const Complex &);   
  friend istream & operator>> (istream &, Complex &);         

};

ostream& operator<< (ostream &out, const Complex &c)
{
  out << "(" << c.deist << ", " << c.mnim << ")";
  return out;
}

istream& operator>> (istream &in, Complex &c)
{
  in >> c.deist >> c.mnim;
  return in;
}

int
main ()
{
  Complex a (3, 2);
  Complex b (1, -);

  cout << "a = " << a << "; b =" << b << endl;

  a += b;
 
  cout << "a = " << a << "; b =" << b << endl;

  Complex c = a + b;

  cout << c << endl;
  cout << a + b << endl;
  cout << a * b << endl;

  return 0;
}

