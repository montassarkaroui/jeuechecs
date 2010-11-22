#ifndef __Aleatoire
#define __Aleatoire

#include "echiquier.h"
#include "structure.h"
#include "Joueur.h"

class Aleatoire : public Joueur
{
    public:

    Coup TrouverCoupAJouer(Echiquier& Plateau, Couleur CouleurAJouer);
};

#endif
