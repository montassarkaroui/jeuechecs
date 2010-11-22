#ifndef __Humain
#define __Humain

#include "echiquier.h"
#include "structure.h"
#include "Joueur.h"

class Humain : public Joueur
{
    public:

    Coup TrouverCoupAJouer(Echiquier& Plateau, Couleur CouleurAJouer);
};

#endif
