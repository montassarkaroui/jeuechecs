#include "Cavalier.h"
#include "structure.h"
#include "piece.h"
#include <string>
using namespace std;

Cavalier::Cavalier(Position Case, Couleur CouleurPiece) : Piece()
{
m_Position = Case;
m_CouleurPiece = CouleurPiece;
//m_Position = Position;
m_TypePiece = TypeCavalier;
//m_CouleurPiece = CouleurPiece;
//m_Vivante = true;

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
            MasqueMouvementPossible |= PositionActuelle << (2*8+1) | PositionActuelle << (1*8+2) | PositionActuelle >> (2*8-1) | PositionActuelle >> (1*8-2);
            break;
        case 1:
            MasqueMouvementPossible |= PositionActuelle << (2*8+1) | PositionActuelle << (1*8+2) | PositionActuelle << (2*8-1) | PositionActuelle >> (2*8-1) | PositionActuelle >> (1*8-2) | PositionActuelle >> (2*8+1);
            break;
        case 6:
            MasqueMouvementPossible |= PositionActuelle << (1*8-2) | PositionActuelle << (2*8-1) | PositionActuelle << (2*8+1) | PositionActuelle >> (2*8+1) | PositionActuelle >> (1*8+2) | PositionActuelle >> (2*8-1);
            break;
        case 7:
            MasqueMouvementPossible |= PositionActuelle << (1*8-2) | PositionActuelle << (2*8-1) | PositionActuelle >> (2*8+1) | PositionActuelle >> (1*8+2);
            break;
        default:
            MasqueMouvementPossible |= PositionActuelle << (2*8+1) | PositionActuelle << (1*8+2) | PositionActuelle << (2*8-1) | PositionActuelle << (1*8-2) | PositionActuelle >> (2*8+1) | PositionActuelle >> (1*8+2) | PositionActuelle >> (2*8-1) | PositionActuelle >> (1*8-2);
    }
    return MasqueMouvementPossible-(MasqueMouvementPossible & PieceAmi);
}
