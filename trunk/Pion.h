#ifndef __Pion
#define __Pion

#include "piece.h"
#include "structure.h"

class Pion : public Piece
{

public:

Pion(Position Case, Couleur CouleurPiece);
ull MouvementPossible(ull PieceAdverse, ull PieceAmi);

};

#endif
