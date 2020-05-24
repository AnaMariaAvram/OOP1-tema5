#ifndef MATRICECOMPLEXA_H
#define MATRICECOMPLEXA_H
#include "NumarComplex.h"

#include <iostream>



class MatriceComplexa
{
    private:
        int numarLinii;
        int numarColoane;
        NumarComplex **matrice;
    public:
        //Constuctor de initializare
        MatriceComplexa();
        MatriceComplexa(NumarComplex, int, int);
        MatriceComplexa(const MatriceComplexa &);
        //supraincarcarea operatorilor << si >>
        friend istream &operator>>(istream &, MatriceComplexa &);
        friend ostream &operator<<(ostream &, MatriceComplexa &);
        int GetNrLinii();
        int GetNrColoane();
        friend MatriceComplexa operator+(const MatriceComplexa &, const MatriceComplexa &);
        friend MatriceComplexa operator*(const MatriceComplexa &, const MatriceComplexa &);
        MatriceComplexa operator=(const MatriceComplexa &);

        void AfisareMatrice();
        int Numar();
        friend class NumarComplex;
        virtual ~MatriceComplexa();

    protected:

};

#endif // MATRICECOMPLEXA_H
