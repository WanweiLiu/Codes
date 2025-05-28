#include <iostream>
#include <string>
using namespace std;

class Complex{
  
private:
   double real;
   double image;

public:
  Complex();
  Complex(double,double);
  virtual ~Complex();

public:
  double getReal() const;
  void setReal(double);
  double getImage() const;
  void setImage(double);

public:
  Complex operator+(const Complex &) const;
  Complex operator-(const Complex &) const;
  Complex operator*(const Complex &) const;
  Complex operator/(const Complex &) const;

  Complex operator-() const;
  Complex operator~() const;

  Complex & operator+=(const Complex &);
  Complex & operator-=(const Complex &);
  Complex & operator*=(const Complex &);
  Complex & operator/=(const Complex &);

 public:
  friend ostream & operator<<(ostream &, const Complex &);
  friend istream & operator>>(istream &, Complex &);

 public:
  static Complex str2cmplx(const string &);
};

