#ifndef __Joueur
#define __Joueur

#include "echiquier.h"
#include "structure.h"

class Joueur
{
    public:

    Coup TrouverCoupAJouer(Echiquier& Plateau, Couleur CouleurAJouer);
};

#endif
