#include "Roi.h"
#include "structure.h"
#include <string>
#include <math.h>
#include <iostream>
using namespace std;

Roi::Roi(Position Case, Couleur CouleurPiece) : Piece()
{
    m_Position = Case;
    m_CouleurPiece = CouleurPiece;
    m_TypePiece = TypeRoi;
    m_Valeur = ValeurRoi;

if (CouleurPiece == Blanc)
{
	m_Symbole = "R";
}
else
{
	m_Symbole = "r";
}

}

ull Roi::MouvementPossible(ull PieceAdverse, ull PieceAmi)
{
    ull MasqueMouvementPossible = 0;
    ull PositionActuelle = 1;
    PositionActuelle <<= (m_Position.Rangee*8 + m_Position.Colonne);
    MasqueMouvementPossible = (PositionActuelle << 8) | (PositionActuelle >> 8);
    switch (m_Position.Colonne)
    {
        case 7:
            MasqueMouvementPossible |= (PositionActuelle << 7 | PositionActuelle >> 9 | PositionActuelle >> 1);
            break;
        case 0:
            MasqueMouvementPossible |= (PositionActuelle << 9 | PositionActuelle >> 7 | PositionActuelle << 1);
            break;
        default:
            MasqueMouvementPossible |= (PositionActuelle << 7 | PositionActuelle << 9 | PositionActuelle >> 7 | PositionActuelle >> 9 | PositionActuelle >> 1 | PositionActuelle << 1);
    }
    return MasqueMouvementPossible & ~(MasqueMouvementPossible & PieceAmi);
}
