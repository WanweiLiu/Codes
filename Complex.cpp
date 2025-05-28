#include "Complex.h"
#include <string>
#include <iostream>
using namespace std;

Complex::Complex(){
  image = real = 0;
}

Complex::Complex(double r, double i){
  real = r;
  image = i;
}

Complex::~Complex(){
}

double Complex::getReal() const{
  return real;
}

void Complex::setReal(double r){
  this->real = r;
}

double Complex::getImage() const{
  return this->image;
}

void Complex::setImage(double i){
  image = i;
}

Complex  Complex::operator+(const Complex &c) const{
  return Complex(this->getReal()+c.getReal(),
  this->getImage()+c.getImage());
}

Complex  Complex::operator-(const Complex &c) const{
  return Complex(this->getReal()-c.getReal(),
  this->getImage()-c.getImage());
}

Complex Complex::operator*(const Complex &c) const{
  return Complex(this->getReal()*c.getReal() - this->getImage()*c.getImage(),
		 this->getReal()*c.getImage() + this->getImage()*c.getReal());
}

Complex Complex::operator/(const Complex &c) const{
  double mod = c.getReal()*c.getReal()+c.getImage()*c.getImage();
  return Complex((this->getReal()*c.getReal()+this->getImage()*c.getImage())/mod,
		 (this->getImage()*c.getReal()-this->getReal()*c.getImage())/mod);
}


Complex Complex::operator-() const{
  return Complex(-real,-image);
}

Complex Complex::operator~() const{
  return Complex(getReal(),-getImage());
}

Complex & Complex::operator+=(const Complex& c){
  real += c.getReal();
  image += c.getImage();
  return *this;
}

Complex & Complex::operator-=(const Complex& c){
  real -= c.getReal();
  image -= c.getImage();
  return *this;
}

Complex & Complex::operator*=(const Complex& c){
  double r = real*c.real - image*c.image;
  double i = real*c.image + image*c.real;
  real = r;
  image = i;
  return *this;
}

Complex& Complex::operator/=(const Complex& c){
  double mod = c.real*c.real + c.image*c.image;
  double r = (real*c.real + image*c.image) / mod;
  double i = (image*c.real - real*c.image) /mod;
  real = r;
  image = i;
  return *this;
}

#include <cstdlib>

/**
 * find(char* c): find the position of the first occurrence of some substring c
 * atof(char* c): convert c to float value
 * substr(m,n): extract the substring composed by the n characters starting from the m-th character
 * length(): get the length of the string
 * c_str(): convert the string to char* type
 */
Complex Complex::str2cmplx(const string & s){
  Complex c(0,0);
  int n = s.find("+i*");
  if(n!=-1){ // both real and image parts exist
    c.setReal(atof(s.substr(0,n).c_str()));
    c.setImage(atof(s.substr(n+3,s.length()-n-3).c_str()));
  }
  else
    if(s.find("i*")==0){ // pure imaginary
      c.setImage(atof(s.substr(2,s.length()-2).c_str()));
    }
    else {
      c.setReal(atof(s.c_str()));
    }
  return c;
}

ostream & operator<< (ostream & os, const Complex & c){
  os<<c.getReal()<<"+i*"<<c.getImage();
  return os;
}

istream & operator>>(istream & is, Complex & c){
  string s;
  is>>s;
  c = Complex::str2cmplx(s);
  return is;
}

