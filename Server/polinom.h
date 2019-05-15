#ifndef TPOLINOM_H
#define TPOLINOM_H
#include "number.h"
#include <iostream>
using namespace std;
class TPolinom
{
public:
 number a,b,c;
 TPolinom();
 TPolinom(number, number, number);
 number value(number);
 int roots(number*);
 friend ostream& operator << (ostream&, TPolinom&);
};
#endif // TPOLINOM_H
