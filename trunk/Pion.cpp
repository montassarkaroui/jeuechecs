#include "Pion.h"
#include "structure.h"
#include <string>

Pion::Pion(Position Case, Couleur CouleurPiece) : Piece()
{
    m_Position = Case;
    m_CouleurPiece = CouleurPiece;
    m_TypePiece = TypeTour;
    m_Valeur = ValeurPion;

    if (CouleurPiece == Blanc)
    {
        m_Symbole = "P";
    }
    else
    {
        m_Symbole = "p";
    }
}


ull Pion::MouvementPossible(ull PieceAdverse, ull PieceAmi)
{
    ull MasqueMouvementPossible = 0;
    ull PositionActuelle = 1;
    ull Un = 1;
    ull UllTemporaire;
    ull PieceTotale = PieceAdverse | PieceAmi;
    PositionActuelle <<= (m_Position.Rangee*8 + m_Position.Colonne);
    switch (m_CouleurPiece)
    {
        case Blanc:
            switch (m_Position.Colonne)
            {
                case 0:
                    if ((PositionActuelle >> 7 & PieceAdverse) != 0) MasqueMouvementPossible |= PositionActuelle >> 7;
                    if ((PositionActuelle >> 8 & PieceTotale) == 0)
                    {
                        MasqueMouvementPossible |= PositionActuelle >> 8;
                        if (m_Position.Rangee == 6 && (PositionActuelle >> 16 & PieceTotale) == 0) MasqueMouvementPossible |= PositionActuelle >> 16;
                    }
                    break;
                case 7:
                    if ((PositionActuelle >> 9 & PieceAdverse) != 0) MasqueMouvementPossible |= PositionActuelle >> 9;
                    if ((PositionActuelle >> 8 & PieceTotale) == 0)
                    {
                        MasqueMouvementPossible |= PositionActuelle >> 8;
                        if (m_Position.Rangee == 6 && (PositionActuelle >> 16 & PieceTotale) == 0) MasqueMouvementPossible |= PositionActuelle >> 16;
                    }
                    break;
                default:
                    UllTemporaire = (PositionActuelle >> 9);
                    if (UllTemporaire & PieceAdverse) MasqueMouvementPossible |= UllTemporaire;
                    UllTemporaire = (PositionActuelle >> 7);
                    if (UllTemporaire & PieceAdverse) MasqueMouvementPossible |= UllTemporaire;
                    UllTemporaire = PositionActuelle >> 8;
                    if ((UllTemporaire & PieceTotale) == 0)
                    {
                        MasqueMouvementPossible |= UllTemporaire;
                        UllTemporaire = PositionActuelle >> 16;
                        if (m_Position.Rangee == 6 && (UllTemporaire & PieceTotale) == 0) MasqueMouvementPossible |= UllTemporaire;
                    }
            }
            break;
        case Noir:
            switch (m_Position.Colonne)
            {
                case 0:
                    if ((PositionActuelle << 9 & PieceAdverse) != 0) MasqueMouvementPossible |= PositionActuelle << 9;
                    if ((PositionActuelle << 8 & PieceTotale) == 0)
                    {
                        MasqueMouvementPossible |= PositionActuelle << 8;
                        if (m_Position.Rangee == 1 && (PositionActuelle << 16 & PieceTotale) == 0) MasqueMouvementPossible |= PositionActuelle << 16;
                    }
                    break;
                case 7:
                    if ((PositionActuelle << 7 & PieceAdverse) != 0) MasqueMouvementPossible |= PositionActuelle << 7;
                    if ((PositionActuelle << 8 & PieceTotale) == 0)
                    {
                        MasqueMouvementPossible |= PositionActuelle << 8;
                        if (m_Position.Rangee == 1 && (PositionActuelle << 16 & PieceTotale) == 0) MasqueMouvementPossible |= PositionActuelle << 16;
                    }
                    break;
                default:
                    UllTemporaire = (PositionActuelle << 9);
                    if (UllTemporaire & PieceAdverse) MasqueMouvementPossible |= UllTemporaire;
                    UllTemporaire = (PositionActuelle << 7);
                    if (UllTemporaire & PieceAdverse) MasqueMouvementPossible |= UllTemporaire;
                    UllTemporaire = PositionActuelle << 8;
                    if ((UllTemporaire & PieceTotale) == 0)
                    {
                        MasqueMouvementPossible |= UllTemporaire;
                        UllTemporaire = PositionActuelle << 16;
                        if (m_Position.Rangee == 1 && (UllTemporaire & PieceTotale) == 0) MasqueMouvementPossible |= UllTemporaire;
                    }
//                    if ((Un << (m_Position.Rangee*8+8 + m_Position.Colonne+1) & PieceAdverse) != 0) MasqueMouvementPossible |= Un << (m_Position.Rangee*8+8 + m_Position.Colonne+1);
//                    if ((Un << (m_Position.Rangee*8+8 + m_Position.Colonne-1) & PieceAdverse) != 0) MasqueMouvementPossible |= Un << (m_Position.Rangee*8+8 + m_Position.Colonne-1);
//                    if ((PositionActuelle << 8 & PieceTotale) == 0)
//                    {
//                        MasqueMouvementPossible |= PositionActuelle << 8;
//                        if (m_Position.Rangee == 1 && (PositionActuelle << 16 & PieceTotale) == 0) MasqueMouvementPossible |= PositionActuelle << 16;
//                    }
            }
    }

    return MasqueMouvementPossible;
}
