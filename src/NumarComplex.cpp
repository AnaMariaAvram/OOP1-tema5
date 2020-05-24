#include "NumarComplex.h"
#include <cstdlib>
NumarComplex::NumarComplex()
{
    re = 0;
    img = 0;
    //ct
}

int NumarComplex::getReal()
{
    return re;
}

int NumarComplex::getImaginar()
{
    return img;
}

void NumarComplex::setReal(double r)
{
    re = r;
}

void NumarComplex::setImaginar(double i)
{
    img = i;
}

NumarComplex operator+(const NumarComplex &ob1, const NumarComplex &ob2)
{
    NumarComplex temp;

    temp.img = ob1.img +  ob2.img;
    temp.re = ob1.re + ob2.re;

    return temp;
}

NumarComplex operator*(const NumarComplex &ob1, const NumarComplex &ob2)
{
    NumarComplex temp;

    temp.img = ob1.img * ob2.re + ob1.re * ob2.img;
    temp.re = ob1.re * ob2.re - ob1.img * ob2.img;

    return temp;
}

NumarComplex NumarComplex::operator=(const NumarComplex &nr)
{
    re = img =0;
    this->re = nr.re;
    this->img = nr.img;
    return (*this);
}

istream &operator>>(istream &in, NumarComplex &nr)
{
    in>>nr.img>>nr.re;
    return in;
}

ostream &operator<<(ostream &out, NumarComplex &nr)
{
    out<<nr.img<<"i+"<<nr.re;
    return out;
}
NumarComplex::~NumarComplex()
{
    re = 0;
    img = 0;
    //dtor
}
