#ifndef __Cavalier
#define __Cavalier

#include "piece.h"
#include "structure.h"

class Cavalier : public Piece
{

public:

Cavalier(Position Case, Couleur CouleurPiece);
ull MouvementPossible(ull PieceAdverse, ull PieceAmi);

};

#endif
