#include "Fou.h"
#include "structure.h"
#include <string>

Fou::Fou(Position Case, Couleur CouleurPiece): Piece()
{
m_Position = Case;
m_CouleurPiece = CouleurPiece;
m_TypePiece = TypeFou;
m_Valeur = ValeurFou;

if (CouleurPiece == Blanc)
{
	m_Symbole = "F";
}
else
{
	m_Symbole = "f";
}

}

ull Fou::MouvementPossible(ull PieceAdverse, ull PieceAmi)
{
    ull MasqueMouvementPossible = 0;
    ull PositionActuelle = 1;
    ull PositionAnalyse;
    ull Un = 1;
    PositionActuelle <<= (m_Position.Rangee*8 + m_Position.Colonne);
    for(int i=m_Position.Rangee+1; i<8; i++)
    {
        int j=m_Position.Colonne+i-m_Position.Rangee;
        PositionAnalyse = Un << (i*8+j);
        if ((PositionAnalyse & PieceAmi) != 0) break;
        if (j<8)
        {
            MasqueMouvementPossible |= PositionAnalyse;
        }
        if ((PositionAnalyse & PieceAdverse) != 0) break;
    }
    for(int i=m_Position.Rangee+1; i<8; i++)
    {
        int j=m_Position.Colonne-i+m_Position.Rangee;
        PositionAnalyse = Un << (i*8+j);
        if ((PositionAnalyse & PieceAmi) != 0) break;
        if (j>=0)
        {
            MasqueMouvementPossible |= PositionAnalyse;
        }
        if ((PositionAnalyse & PieceAdverse) != 0) break;
    }
    for(int i=m_Position.Rangee-1; i>=0; i--)
    {
        int j=m_Position.Colonne+i-m_Position.Rangee;
        PositionAnalyse = Un << (i*8+j);
        if ((PositionAnalyse & PieceAmi) != 0) break;
        if (j>=0)
        {
            MasqueMouvementPossible |= PositionAnalyse;
        }
        if ((PositionAnalyse & PieceAdverse) != 0) break;
    }
    for(int i=m_Position.Rangee-1; i>=0; i--)
    {
        int j=m_Position.Colonne-i+m_Position.Rangee;
        PositionAnalyse = Un << (i*8+j);
        if ((PositionAnalyse & PieceAmi) != 0) break;
        if (j<8)
        {
            MasqueMouvementPossible |= PositionAnalyse;
        }
        if ((PositionAnalyse & PieceAdverse) != 0) break;
    }
    return MasqueMouvementPossible;
}
