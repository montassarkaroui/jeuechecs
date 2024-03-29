#include "Cavalier.h"
#include "structure.h"
#include "piece.h"
#include <string>
using namespace std;

Cavalier::Cavalier(Position Case, Couleur CouleurPiece) : Piece()
{
m_Position = Case;
m_CouleurPiece = CouleurPiece;
m_TypePiece = TypeCavalier;
m_Valeur = ValeurCavalier;


if (CouleurPiece == Blanc)
{
	m_Symbole = "C";
}
else
{
	m_Symbole = "c";
}

}

ull Cavalier::MouvementPossible(ull PieceAdverse, ull PieceAmi)
{
    ull MasqueMouvementPossible = 0;
    ull PositionActuelle = 1;
    PositionActuelle <<= (m_Position.Rangee*8 + m_Position.Colonne);
    switch (m_Position.Colonne)
    {
        case 0:
            //MasqueMouvementPossible |= PositionActuelle << (2*8+1) | PositionActuelle << (1*8+2) | PositionActuelle >> (2*8-1) | PositionActuelle >> (1*8-2);
            MasqueMouvementPossible |= PositionActuelle << (17) | PositionActuelle << (10) | PositionActuelle >> (15) | PositionActuelle >> (6);
            break;
        case 1:
            //MasqueMouvementPossible |= PositionActuelle << (2*8+1) | PositionActuelle << (1*8+2) | PositionActuelle << (2*8-1) | PositionActuelle >> (2*8-1) | PositionActuelle >> (1*8-2) | PositionActuelle >> (2*8+1);
            MasqueMouvementPossible |= PositionActuelle << (17) | PositionActuelle << (10) | PositionActuelle << (15) | PositionActuelle >> (15) | PositionActuelle >> (6) | PositionActuelle >> (17);
            break;
        case 6:
            //MasqueMouvementPossible |= PositionActuelle << (1*8-2) | PositionActuelle << (2*8-1) | PositionActuelle << (2*8+1) | PositionActuelle >> (2*8+1) | PositionActuelle >> (1*8+2) | PositionActuelle >> (2*8-1);
            MasqueMouvementPossible |= PositionActuelle << (6) | PositionActuelle << (15) | PositionActuelle << (17) | PositionActuelle >> (17) | PositionActuelle >> (10) | PositionActuelle >> (15);
            break;
        case 7:
            //MasqueMouvementPossible |= PositionActuelle << (1*8-2) | PositionActuelle << (2*8-1) | PositionActuelle >> (2*8+1) | PositionActuelle >> (1*8+2);
            MasqueMouvementPossible |= PositionActuelle << (6) | PositionActuelle << (15) | PositionActuelle >> (17) | PositionActuelle >> (10);
            break;
        default:
            //MasqueMouvementPossible |= PositionActuelle << (2*8+1) | PositionActuelle << (1*8+2) | PositionActuelle << (2*8-1) | PositionActuelle << (1*8-2) | PositionActuelle >> (2*8+1) | PositionActuelle >> (1*8+2) | PositionActuelle >> (2*8-1) | PositionActuelle >> (1*8-2);
            MasqueMouvementPossible |= PositionActuelle << (17) | PositionActuelle << (10) | PositionActuelle << (15) | PositionActuelle << (6) | PositionActuelle >> (17) | PositionActuelle >> (10) | PositionActuelle >> (15) | PositionActuelle >> (6);
    }
    return MasqueMouvementPossible & ~(MasqueMouvementPossible & PieceAmi);
}
