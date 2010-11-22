#ifndef __Tour
#define __Tour

#include "piece.h"
#include "structure.h"

class Tour : public Piece
{

public:

Tour(Position Case, Couleur CouleurPiece);
ull MouvementPossible(ull PieceAdverse, ull PieceAmi);

};

#endif
