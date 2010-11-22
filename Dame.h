#ifndef __Dame
#define __Dame

#include "piece.h"
#include "structure.h"

class Dame : public Piece
{

public:

Dame(Position Case, Couleur CouleurPiece);
ull MouvementPossible(ull PieceAdverse, ull PieceAmi);

};

#endif
