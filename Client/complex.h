#ifndef TCOMPLEX_H
#define TCOMPLEX_H
#include <iostream>
class TComplex
{

public:
 double re, im;
 TComplex Polar(double mod, double arg);
 double Arg();
 double Abs();
 friend TComplex sqrt(TComplex&);
 TComplex();
 TComplex(double);
 TComplex(double, double);
 TComplex(const TComplex &ob);
 TComplex& operator = (const TComplex);
 TComplex& operator = (const double);
 TComplex& operator += (TComplex a);
 TComplex& operator -= (TComplex a);
 TComplex operator*(TComplex);
 TComplex operator/(TComplex);
 TComplex operator*(double);
 TComplex operator-();
 bool operator ==(double);
 bool operator <(double);
 bool operator >(double);
 friend std::istream& operator >>(std::istream&, TComplex&);
 friend std::ostream& operator <<(std::ostream&, const TComplex&);
};
TComplex operator-(TComplex a, TComplex b);
TComplex operator+(TComplex a, TComplex b);
TComplex operator*(double a, TComplex b);
#endif // TCOMPLEX_H
