#include "complex.h"
#include "number.h"
#include <math.h>
#define _USE_MATH_DEFINES
double TComplex::Arg()
{
 return atan2(im,re);
}
double TComplex::Abs()
{
 return sqrt(re*re+im*im);
}
TComplex TComplex::Polar(double mod,double arg)
{
 return TComplex(mod*cos(arg),mod*sin(arg));
}
TComplex sqrt(TComplex&f)
{
 TComplex res[2];
 double angle=f.Arg();
 double mod=f.Abs();
 mod=pow(mod,1.0/2);
 for(int k=0;k<2;k++){
 res[k]=f.Polar(mod,(angle+2*k*M_PI)/2);
 }
 return res[0];
}
TComplex::TComplex(double a)
{
 re=a;
 im=0.0;
}
TComplex::TComplex()
{
 re = 0.0;
 im = 0.0;
}
TComplex::TComplex(double r,double i)
{
 re = r;
 im = i;
}
TComplex::TComplex(const TComplex &ob)
{
 re = ob.re;
 im = ob.im;
}
TComplex& TComplex::operator =( const TComplex com)
{
 re = com.re;
 im = com.im;
 return *this;
}
TComplex& TComplex::operator =( const double com)
{
 re = com;
 im = 0.0;
 return *this;
}
TComplex& TComplex::operator+=(TComplex a){
 re+=a.re;
 im+=a.im;
 return *this;
}
TComplex& TComplex::operator-=(TComplex a){
 re-=a.re;
 im-=a.im;
 return *this;
}
std::ostream& operator << (std::ostream& out, const TComplex& com)
{
 if(com.im < 0)
 out <<"("<< com.re << "+i(" << com.im << ")"<<")";
 else
 out <<"("<<com.re << "+i"<< com.im<<")";
 return out;
}
std::istream& operator >> (std::istream& in, TComplex& com)
{
 // std::cout << "Enter the real part of the complex number - ";
 in >> com.re;
 // std::cout << "Enter the imaginary part of the complex number - ";
 in >> com.im;
 return in;
}
bool TComplex::operator==(double b){
 if(re==b)
 return 1;
 else
 return 0;
}
bool TComplex::operator<(double b){
 if(re<b)
 return 1;
 else
 return 0;
}
bool TComplex::operator>(double b){
 if(re>b)
 return 1;
 else
 return 0;
}
TComplex operator+(TComplex a,TComplex b)
{
 return a+=b;
}
TComplex operator-(TComplex a,TComplex b)
{
 return a-=b;
}
TComplex TComplex::operator*(TComplex b)
{
 double i,j;
 TComplex temp=*this;
 i=temp.re*b.re-temp.im*b.im;
 j=temp.re*b.im +b.re*temp.im;
 temp.re=i;
 temp.im=j;
 return temp;
}
TComplex TComplex::operator*(double a)
{
 TComplex temp=*this;
 return temp*TComplex(a);
}
TComplex operator*(double a,TComplex b)
{
 return b*a;
}
TComplex TComplex::operator-(){
 return TComplex(-re,-im);
}
TComplex TComplex::operator/(TComplex b){
 double r = (re*b.re+im*b.im)/(b.re*b.re+b.im*b.im);
 double i = (-re*b.im+im*b.re)/(b.re*b.re+b.im*b.im);
 return TComplex(r,i);
}
