#include "MatriceComplexa.h"
#include <iostream>
#include <cstdlib>
using namespace std;

MatriceComplexa::MatriceComplexa()
{
    numarColoane = 0;
    numarLinii = 0;
    matrice = NULL;
    //ctor
}
int MatriceComplexa::GetNrLinii()
{
    return numarLinii;
}

int MatriceComplexa::GetNrColoane()
{
    return numarColoane;
}

MatriceComplexa::MatriceComplexa(NumarComplex val, int linii, int coloane)
{
    numarLinii = linii;
    numarColoane = coloane;
    matrice = new NumarComplex *[numarLinii];
    for (int i = 0; i < numarLinii; i++)
    {
        matrice[i] = new NumarComplex[numarColoane];
    }
    for (int i = 0; i < numarLinii; i++)
    {
        for (int j = 0 ; j < numarColoane; j++)
        {
            matrice[i][j] = val;
        }
    }

}
MatriceComplexa::MatriceComplexa(const MatriceComplexa &matriceC)
{
    numarLinii = matriceC.numarLinii;
    numarColoane = matriceC.numarColoane;
    matrice = new NumarComplex *[numarLinii];
    for (int i = 0; i < numarLinii; i++)
    {
        matrice[i] = new NumarComplex[numarColoane];
    }
    for (int i = 0; i < numarLinii; i++)
    {
        for (int j = 0 ; j < numarColoane; j++)
        {
            matrice[i][j] = matriceC.matrice[i][j];
        }
    }

}


void MatriceComplexa::AfisareMatrice()
{
    for (int i = 0; i < numarLinii; i++)
    {
        for (int j = 0; j < numarColoane; j++) {
            cout<<matrice[i][j]<< " ";
        }
        cout<<'\n';
    }
}

istream &operator>>(istream &in, MatriceComplexa &matriceC)
{
    in>>matriceC.numarLinii>>matriceC.numarColoane;
    matriceC.matrice = new NumarComplex *[matriceC.numarLinii];
    for (int i = 0; i < matriceC.numarLinii; i++)
    {
        matriceC.matrice[i] = new NumarComplex[matriceC.numarColoane];
    }
    for (int i = 0; i < matriceC.numarLinii; i++)
    {
        for (int j = 0; j < matriceC.numarColoane; j++)
        {
            in>>matriceC.matrice[i][j];
        }
    }
    return in;
}

ostream &operator<<(ostream &out,MatriceComplexa &matriceC)
{

    if(matriceC.numarLinii >0)
    for (int i = 0; i < matriceC.numarLinii; i++)
    {
        for (int j = 0; j < matriceC.numarColoane; j++)
        {
           out<<matriceC.matrice[i][j]<<" ";
        }
        out<<'\n';
    }
    return out;
}

MatriceComplexa operator+(const MatriceComplexa &m1, const MatriceComplexa &m2)
{

    MatriceComplexa temp;
    temp.numarLinii = m1.numarLinii;
    temp.numarColoane = m1.numarColoane;
    temp.matrice = new NumarComplex *[m1.numarLinii];
    for (int i = 0; i < m1.numarLinii; i++)
    {
        temp.matrice[i] = new NumarComplex[m1.numarColoane];
    }
    for (int i = 0; i < m1.numarLinii; i++)
    {
        for (int j = 0; j < m1.numarColoane; j++)
        {
            temp.matrice[i][j] = m1.matrice[i][j] + m2.matrice[i][j];
        }
    }
    return temp;
}

MatriceComplexa operator*(const MatriceComplexa &m1, const MatriceComplexa &m2)
{
    MatriceComplexa temp;
    temp.numarLinii = m1.numarLinii;
    temp.numarColoane = m2.numarColoane;
    temp.matrice = new NumarComplex *[temp.numarLinii];
    for (int i = 0; i < temp.numarLinii; i++)
    {
        temp.matrice[i] = new NumarComplex[temp.numarColoane];
    }
    for (int i = 0; i < m1.numarLinii; i++)
        for (int j = 0; j < m2.numarColoane; j++)
            for (int k = 0; k < m1.numarColoane; k++)
                temp.matrice[i][j] = temp.matrice[i][j] +  m1.matrice[i][k] * m2.matrice[k][j];
    return temp;
}
MatriceComplexa MatriceComplexa::operator=(const MatriceComplexa &m1)
{
    for (int i = 0; i < numarLinii; i++)
    {
        delete [] matrice[i];
    }
    matrice = NULL;
    numarLinii = 0;
    numarColoane = 0;

    this->numarLinii = m1.numarLinii;
    this->numarColoane = m1.numarColoane;
    this->matrice = new NumarComplex *[m1.numarLinii];
    for (int i = 0; i < m1.numarLinii; i++)
    {
        matrice[i] = new NumarComplex[m1.numarColoane];
    }
    for (int i = 0; i < m1.numarLinii; i++)
    {
        for (int j = 0 ; j < m1.numarColoane; j++)
        {
            this->matrice[i][j] = m1.matrice[i][j];
        }
    }

    return *this;

}


MatriceComplexa::~MatriceComplexa()
{
    for (int i = 0; i < numarLinii; i++)
    {
        delete [] matrice[i];
    }
    matrice = NULL;
    numarLinii = 0;
    numarColoane = 0;
}
