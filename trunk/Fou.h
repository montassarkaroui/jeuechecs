#ifndef __Fou
#define __Fou

#include "piece.h"
#include "structure.h"

class Fou : public Piece
{

public:

Fou(Position Case, Couleur CouleurPiece);
ull MouvementPossible(ull PieceAdverse, ull PieceAmi);

};

#endif
