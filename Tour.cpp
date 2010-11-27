#include "Tour.h"
#include "structure.h"
#include <string>

Tour::Tour(Position Case, Couleur CouleurPiece): Piece()
{
m_Position = Case;
m_CouleurPiece = CouleurPiece;
m_TypePiece = TypeFou;
m_Valeur = ValeurTour;

if (CouleurPiece == Blanc)
{
	m_Symbole = "T";
}
else
{
	m_Symbole = "t";
}

}

ull Tour::MouvementPossible(ull PieceAdverse, ull PieceAmi)
{
    ull MasqueMouvementPossible = 0;
    ull PositionActuelle = 1;
    ull PositionAnalyse;
    ull Un = 1;
    PositionActuelle <<= (m_Position.Rangee*8 + m_Position.Colonne);
    for(int i=m_Position.Rangee+1; i<8; i++)
    {
        PositionAnalyse = Un << (i*8+m_Position.Colonne);
        if ((PositionAnalyse & PieceAmi) != 0) break;
        MasqueMouvementPossible |= PositionAnalyse;
        if ((PositionAnalyse & PieceAdverse) != 0) break;
    }
    for(int i=m_Position.Rangee-1; i>=0; i--)
    {
        PositionAnalyse = Un << (i*8+m_Position.Colonne);
        if ((PositionAnalyse & PieceAmi) != 0) break;
        MasqueMouvementPossible |= PositionAnalyse;
        if ((PositionAnalyse & PieceAdverse) != 0) break;
    }
    for(int j=m_Position.Colonne+1; j<8; j++)
    {
        PositionAnalyse = Un << (m_Position.Rangee*8+j);
        if ((PositionAnalyse & PieceAmi) != 0) break;
        MasqueMouvementPossible |= PositionAnalyse;
        if ((PositionAnalyse & PieceAdverse) != 0) break;
    }
    for(int j=m_Position.Colonne-1; j>=0; j--)
    {
        PositionAnalyse = Un << (m_Position.Rangee*8+j);
        if ((PositionAnalyse & PieceAmi) != 0) break;
        MasqueMouvementPossible |= PositionAnalyse;
        if ((PositionAnalyse & PieceAdverse) != 0) break;
    }

    return MasqueMouvementPossible;
}

