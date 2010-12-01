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
    int NombreDeCas;
    PositionActuelle <<= (m_Position.Rangee*8 + m_Position.Colonne);
    PositionAnalyse = PositionActuelle;
    NombreDeCas = 7-m_Position.Rangee;
    for(int i=0; i<NombreDeCas; i++)
    {
        PositionAnalyse <<= 8;
        if ((PositionAnalyse & PieceAmi) != 0) break;
        MasqueMouvementPossible |= PositionAnalyse;
        if ((PositionAnalyse & PieceAdverse) != 0) break;
    }
    PositionAnalyse = PositionActuelle;
    NombreDeCas = m_Position.Rangee;
    for(int i=NombreDeCas; i>0; i--)
    {
        PositionAnalyse >>= 8;
        if ((PositionAnalyse & PieceAmi) != 0) break;
        MasqueMouvementPossible |= PositionAnalyse;
        if ((PositionAnalyse & PieceAdverse) != 0) break;
    }
    PositionAnalyse = PositionActuelle;
    NombreDeCas = 7-m_Position.Colonne;
    for(int i=0; i<NombreDeCas; i++)
    {
        PositionAnalyse <<= 1;
        if ((PositionAnalyse & PieceAmi) != 0) break;
        MasqueMouvementPossible |= PositionAnalyse;
        if ((PositionAnalyse & PieceAdverse) != 0) break;
    }
    PositionAnalyse = PositionActuelle;
    NombreDeCas = m_Position.Colonne;
    for(int i=NombreDeCas; i>0; i--)
    {
        PositionAnalyse >>=1;
        if ((PositionAnalyse & PieceAmi) != 0) break;
        MasqueMouvementPossible |= PositionAnalyse;
        if ((PositionAnalyse & PieceAdverse) != 0) break;
    }

    return MasqueMouvementPossible;
}

