#ifndef __Piece
#define __Piece

#include "structure.h"
#include <string>
using namespace std;

class Piece
{

protected:

Position m_Position;
Type m_TypePiece;
Couleur m_CouleurPiece;
bool m_Vivante;
string m_Symbole;
int m_Numero;
double m_Valeur;

public:

//Constructeur
Piece();

//Getteurs et Setteurs
Position GetPosition();
Type GetType();
string GetSymbole();
Couleur GetCouleur();
bool GetVivante();
void SetVivante(bool Valeur);
int GetNumero();
double GetValeur();
void SetPosition(Position PositionPiece);
void SetNumero(int Numero);

//Méthode pour le déplacement
virtual ull MouvementPossible(ull PieceAdverse, ull PieceAmi)=0;

};
#endif
