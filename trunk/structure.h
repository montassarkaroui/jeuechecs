#ifndef __Structure
#define __Structure

#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

typedef unsigned long long int ull;
typedef unsigned short int usi;

enum Type
{
TypeRoi, TypeDame, TypeTour, TypeFou, TypeCavalier, TypePion, TypeNull
};

enum Couleur
{
Blanc, Noir
};

struct Position
{
    usi Colonne;
    usi Rangee;
};

struct Coup
{
    Position Depart;
    Position Arrive;
    int PiecePrise;
    bool BoolPiecePrise;
};

void UllVersTableau(unsigned long long int Ull, int Tableau[]);
void AffichageUll(unsigned long long int ull);
void ConversionUllCoup(vector<Coup> &ListeCoup, ull Masque, Position PositionDeLaPiece);


#endif
