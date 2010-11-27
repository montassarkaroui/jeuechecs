#ifndef __Joueur
#define __Joueur

#include "echiquier.h"
#include "structure.h"

class Joueur
{
    protected:

    int m_Niveau;

    public:

    Coup TrouverCoupAJouer(Echiquier& Plateau, Couleur CouleurAJouer);
};

#endif
