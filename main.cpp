#include <iostream>
#include "NumarComplex.h"
#include "MatriceComplexa.h"
#include <fstream>
using namespace std;
ifstream f("tema.in");
int main()
{

    ///initializarea unei matrice cu un nr complex

    NumarComplex val;
    int lin,col;
    cout<<"Introducem nr de linii si nr de coloane: ";
    cin>>lin>>col;
    cout<<"Si valoarea pe care o va lua matricea:";
    cin>>val;
    MatriceComplexa matrice(val,lin,col); ///aici se initializeaza matricea cu nr complex
    cout<<matrice<<endl;

    ///constructor de copiere

    MatriceComplexa  ob5;
    cout<<"Se introduce numarul de linii si de coloane matrice urmat de matrice: ";
    cin>>ob5; ///supraincarc operatorul >>
    MatriceComplexa ob4(ob5); ///aici se apeleaza constructorul de copiere
    cout<<ob4<<endl; ///supraincarc operatorul <<
    ///Matricea obtinuta prin supraincarcarea lui << />> este in ob4



    ///adunarea matricelor

    MatriceComplexa  ob6, ob7;
    cout<<"Se introduce numarul de linii si de coloane al primei matrice urmat de prima matrice: ";
    cin>>ob6;
    cout<<"Se introduce numarul de linii si de coloane al celei de-a doua matrice urmat de a doua matrice: ";
    cin>>ob7;
    if(ob6.GetNrLinii()==ob7.GetNrLinii() and ob6.GetNrColoane()==ob7.GetNrColoane())
    {
        MatriceComplexa ob8 = ob6 + ob7; ///aici se aduna matricele
        cout<<"Suma matricelor este:"<<'\n';
        cout<<ob8<<'\n';
    }
    else
        cout<<"NU SE POT ADUNA."<< endl;

    ///inmultirea matricelor
    MatriceComplexa  ob9, ob10;
    cout<<"Se introduce numarul de linii si de coloane al primei matrice urmat de prima matrice: ";
    cin>>ob9;
    cout<<"Se introduce numarul de linii si de coloane al celei de-a doua matrice urmat de a doua matrice: ";
    cin>>ob10;
    if(ob10.GetNrLinii()==ob9.GetNrColoane())
    {
        MatriceComplexa ob11 = ob9*ob10; ///aici se inmultesc matricele
        cout<<"Inmultirea matricelor este:"<<'\n';
        cout<<ob11;
    }
    else
        cout<<"NU SE POT INMULTI."<< endl;

    return 0;

}
