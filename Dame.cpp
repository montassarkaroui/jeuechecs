#include "Dame.h"
#include "structure.h"
#include <string>

Dame::Dame(Position Case, Couleur CouleurPiece) : Piece()
{
m_Position = Case;
m_CouleurPiece = CouleurPiece;
m_TypePiece = TypeDame;
m_Valeur = ValeurDame;


if (CouleurPiece == Blanc)
{
	m_Symbole = "D";
}
else
{
	m_Symbole = "d";
}

}

ull Dame::MouvementPossible(ull PieceAdverse, ull PieceAmi)
{
    ull MasqueMouvementPossible = 0;
    ull PositionActuelle = 1;
    ull PositionAnalyse;
    ull Un = 1;
    int NombreDeCas;
    PositionActuelle <<= (m_Position.Rangee*8 + m_Position.Colonne);

    PositionAnalyse = PositionActuelle;
    NombreDeCas = min(7-m_Position.Rangee, 7-m_Position.Colonne);
    for(int i=0; i<NombreDeCas; i++)
    {
        PositionAnalyse <<= 9;
        if ((PositionAnalyse & PieceAmi) != 0) break;
        MasqueMouvementPossible |= PositionAnalyse;
        if ((PositionAnalyse & PieceAdverse) != 0) break;
    }
    PositionAnalyse = PositionActuelle;
    NombreDeCas = min(7-m_Position.Rangee, m_Position.Colonne);
    for(int i=NombreDeCas; i>0; i--)
    {
        PositionAnalyse <<= 7;
        if ((PositionAnalyse & PieceAmi) != 0) break;
        MasqueMouvementPossible |= PositionAnalyse;
        if ((PositionAnalyse & PieceAdverse) != 0) break;
    }
    PositionAnalyse = PositionActuelle;
    NombreDeCas = min(m_Position.Rangee, 7-m_Position.Colonne);
    for(int i=0; i<NombreDeCas; i++)
    {
        PositionAnalyse >>= 7;
        if ((PositionAnalyse & PieceAmi) != 0) break;
        MasqueMouvementPossible |= PositionAnalyse;
        if ((PositionAnalyse & PieceAdverse) != 0) break;
    }
    PositionAnalyse = PositionActuelle;
    NombreDeCas = min(m_Position.Rangee, m_Position.Colonne);
    for(int i=NombreDeCas; i>0; i--)
    {
        PositionAnalyse >>=9;
        if ((PositionAnalyse & PieceAmi) != 0) break;
        MasqueMouvementPossible |= PositionAnalyse;
        if ((PositionAnalyse & PieceAdverse) != 0) break;
    }

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

//    // Le Fou
//
//    for(int i=m_Position.Rangee+1; i<8; i++)
//    {
//        int j=m_Position.Colonne+i-m_Position.Rangee;
//        PositionAnalyse = Un << (i*8+j);
//        if ((PositionAnalyse & PieceAmi) != 0) break;
//        if (j<8)
//        {
//            MasqueMouvementPossible |= PositionAnalyse;
//        }
//        if ((PositionAnalyse & PieceAdverse) != 0) break;
//    }
//    for(int i=m_Position.Rangee+1; i<8; i++)
//    {
//        int j=m_Position.Colonne-i+m_Position.Rangee;
//        PositionAnalyse = Un << (i*8+j);
//        if ((PositionAnalyse & PieceAmi) != 0) break;
//        if (j>=0)
//        {
//            MasqueMouvementPossible |= PositionAnalyse;
//        }
//        if ((PositionAnalyse & PieceAdverse) != 0) break;
//    }
//    for(int i=m_Position.Rangee-1; i>=0; i--)
//    {
//        int j=m_Position.Colonne+i-m_Position.Rangee;
//        PositionAnalyse = Un << (i*8+j);
//        if ((PositionAnalyse & PieceAmi) != 0) break;
//        if (j>=0)
//        {
//            MasqueMouvementPossible |= PositionAnalyse;
//        }
//        if ((PositionAnalyse & PieceAdverse) != 0) break;
//    }
//    for(int i=m_Position.Rangee-1; i>=0; i--)
//    {
//        int j=m_Position.Colonne-i+m_Position.Rangee;
//        PositionAnalyse = Un << (i*8+j);
//        if ((PositionAnalyse & PieceAmi) != 0) break;
//        if (j<8)
//        {
//            MasqueMouvementPossible |= PositionAnalyse;
//        }
//        if ((PositionAnalyse & PieceAdverse) != 0) break;
//    }
//
//    // La Tour
//
//    for(int i=m_Position.Rangee+1; i<8; i++)
//    {
//        PositionAnalyse = Un << (i*8+m_Position.Colonne);
//        if ((PositionAnalyse & PieceAmi) != 0) break;
//        MasqueMouvementPossible |= PositionAnalyse;
//        if ((PositionAnalyse & PieceAdverse) != 0) break;
//    }
//    for(int i=m_Position.Rangee-1; i>=0; i--)
//    {
//        PositionAnalyse = Un << (i*8+m_Position.Colonne);
//        if ((PositionAnalyse & PieceAmi) != 0) break;
//        MasqueMouvementPossible |= PositionAnalyse;
//        if ((PositionAnalyse & PieceAdverse) != 0) break;
//    }
//    for(int j=m_Position.Colonne+1; j<8; j++)
//    {
//        PositionAnalyse = Un << (m_Position.Rangee*8+j);
//        if ((PositionAnalyse & PieceAmi) != 0) break;
//        MasqueMouvementPossible |= PositionAnalyse;
//        if ((PositionAnalyse & PieceAdverse) != 0) break;
//    }
//    for(int j=m_Position.Colonne-1; j>=0; j--)
//    {
//        PositionAnalyse = Un << (m_Position.Rangee*8+j);
//        if ((PositionAnalyse & PieceAmi) != 0) break;
//        MasqueMouvementPossible |= PositionAnalyse;
//        if ((PositionAnalyse & PieceAdverse) != 0) break;
//    }
    return MasqueMouvementPossible;
}
