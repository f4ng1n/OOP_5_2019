#include "polinom.h"
#include <cmath>
#include <math.h>
#include "number.h"
#define EPSILON 0.00001

TPolinom::TPolinom(number x, number y, number z)
{
a = x;
b = y;
c = z;
}
TPolinom::TPolinom()
{
}
number TPolinom::value(number x)
{
    return (a*x*x+b*x+c);
}

int TPolinom::roots(number *x)
{
    number d = b*b-4*a*c;

    if ((d > 0) || (d < 0))
        {
            x[0] = (-b + sqrt(d))/(2*a);
            x[1] = (-b - sqrt(d))/(2*a);
            return 2;
        }
        if (d == 0)
        {
            x[0] = -b/(2*a);
            return 1;
        }
        return 0;
  }

ostream& operator << (ostream& os, TPolinom& p)
{
     //bool hasc =fabs(p.c) >= EPSILON;

    if ((p.a > 0) || (p.a < 0))
    {
            os<< p.a<<"x^2";
            if (p.b > 0)
            {
                os << "+" << p.b <<"x";
                if (p.c == 0)
                    os << "";
                if (p.c > 0)
                    os<<"+"<< p.c<<"";
                else
                    os << p.c << "";
            }
            if (p.b < 0)
            {
                os << p.b << "x";
                if (p.c == 0)
                    os << "";
                if (p.c > 0)
                    os<<"+"<< p.c<<"";
                else
                    os << p.c << "";
            }
            if (p.b == 0)
            {
                if (p.c == 0)
                    os << "";
                if (p.c > 0)
                    os<<"+"<< p.c<<"";
                else
                    os << p.c << "";
            }
    }
    if (p.a == 0)
    {
        if ((p.b > 0) || (p.b < 0))
        {
            os << p.b << "x";
            if (p.c == 0)
                os << "";
            if (p.c > 0)
                os<<"+"<< p.c<<"";
            else
                os << p.c << "";
        }
        if (p.b == 0)
        {
            if (p.c == 0)
                os << "";
            if (p.c > 0)
                os<<"+"<< p.c<<"";
            else
                os << p.c << "";
        }

    }
return os;
}
