#ifndef __Roi
#define __Roi

#include "piece.h"
#include "structure.h"

class Roi : public Piece
{
    public:

    //Constructeur
    Roi(Position Case, Couleur CouleurPiece);

    //Getteur et Setteur
    int GetNombreDeplacementTourGrandRoque();
    int GetNombreDeplacementTourPetitRoque();
    int GetNombreDeplacementRoi();
    void SetNombreDeplacementTourGrandRoque(unsigned int Nombre);
    void SetNombreDeplacementTourPetitRoque(unsigned int Nombre);
    void SetNombreDeplacementTourRoi(unsigned int Nombre);
    ull MouvementPossible(ull PieceAdverse, ull PieceAmi);

};

#endif
