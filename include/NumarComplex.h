#ifndef NUMARCOMPLEX_H
#define NUMARCOMPLEX_H
#include <iostream>
using namespace std;

class NumarComplex
{
    private:
        double re, img;
    public:
        NumarComplex();
        int getReal();
        int getImaginar();
        void setReal(double);
        void setImaginar(double);
        friend NumarComplex operator+(const NumarComplex &, const NumarComplex &);
        friend NumarComplex operator*(const NumarComplex &, const NumarComplex &);
        NumarComplex operator=(const NumarComplex &);
        friend istream &operator>>(istream &, NumarComplex &);
        friend ostream &operator<<(ostream &, NumarComplex &);
        virtual ~NumarComplex();

};

#endif // NUMARCOMPLEX_H
