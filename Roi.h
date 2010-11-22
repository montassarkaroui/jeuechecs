#ifndef __Roi
#define __Roi

#include "piece.h"
#include "structure.h"

class Roi : public Piece
{
    private:

    int m_NombreDeplacementTourGrandRoque;
    int m_NombreDeplacementTourPetitRoque;
    int m_NombreDeplacementRoi;
    bool m_Echec;

    public:

    Roi(Position Case, Couleur CouleurPiece);
    ull MouvementPossible(ull PieceAdverse, ull PieceAmi);

};

#endif
