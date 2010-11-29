#ifndef __Structure
#define __Structure

#define ValeurRoi 0
#define ValeurDame 10
#define ValeurTour 5
#define ValeurFou 3
#define ValeurCavalier 3
#define ValeurPion 1
#define ValeurEchetEtMat 100000000

#define GrandInfini 1000000000

#include <math.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
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
    bool Roque;
    bool GrandRoque;
    bool PetitRoque;
    bool Promotion;
    Type TypePiece;
};

struct CoupEval
{
    Coup CoupAJouer;
    double Evaluation;
};

std::string ConversionIntString(int i);
void UllVersTableau(unsigned long long int Ull, int Tableau[]);
void AffichageUll(unsigned long long int ull);
void ConversionUllCoup(vector<Coup> &ListeCoup, ull Masque, Position PositionDeLaPiece);
void EcritureFichierUll(ull UllAEcrire, string NomFichier, string Message);

#endif
