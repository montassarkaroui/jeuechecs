#include "structure.h"
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

std::string ConversionIntString( int i )
{
    std::ostringstream oss;
    oss << i ;
    return oss.str();
}

void UllVersTableau(ull Ull,  int *Tableau)
{
    ull Un = 1;
    ull Actuelle, Res;
    for(int i=63; i>=0; i--)
    {

        Actuelle = (Un << i);
        Res = (Ull & Actuelle);
        if(Res)
        {
            Ull &= ~Actuelle;
            Tableau[i] = 1;
        }
        else { Tableau[i] = 0; }
    }
//    ull Actuelle, Res;
//    for(int i=63; i>=0; i--)
//    {
//            Actuelle = pow(2,i);
//            Res = Ull/Actuelle;
//            if(Res!=0)
//            {
//                Ull -= Actuelle;
//            }
//            Tableau[i] = Res;
//    }

}

void AffichageUll(unsigned long long int Ull)
{
    int* Tableau = NULL;
    Tableau = (int* )malloc(64*sizeof(int));
    UllVersTableau(Ull, Tableau);
    for(int i=0; i<8; i++)
    {
        cout << "|";
        for(int j=0; j<8; j++)
        {
            cout << Tableau[j+8*i] << "|";
        }
        cout << endl;
    }

    delete Tableau;
}

void ConversionUllCoup(vector<Coup> &ListeCoup, ull Masque, Position PositionDeLaPiece)
{
    ull Un = 1;
    Coup Case;
    for (int i=63; i>=0; i--)
    {
        if ((Un << i) & Masque)
        {
            Case.Depart = PositionDeLaPiece;
            Case.Arrive.Rangee = i/8;
            Case.Arrive.Colonne = i%8;
            Case.Roque = false;
            ListeCoup.push_back(Case);
            Masque &= ~(Un << i);
        }
    }
}

void EcritureFichierUll(ull UllAEcrire, string NomFichier, string Message)
{
    int* Tableau = NULL;
    Tableau = (int* )malloc(64*sizeof(int));
    UllVersTableau(UllAEcrire, Tableau);

    ofstream Fichier(NomFichier.c_str(), ios::out | ios::app);

    Fichier << Message << endl;
    for(int i=0; i<8; i++)
    {
        Fichier << "|";
        for(int j=0; j<8; j++)
        {
            Fichier << Tableau[j+8*i] << "|";
        }
        Fichier << endl;
    }

    Fichier.close();

    delete Tableau;
}
