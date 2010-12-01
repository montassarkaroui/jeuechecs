#ifndef __NegaMax
#define __NegaMax

#include "echiquier.h"
#include "structure.h"
#include "Joueur.h"

class NegaMax: public Joueur
{
    public:

    NegaMax();
    Coup TrouverCoupAJouer(Echiquier& Plateau, Couleur CouleurAJouer);
    CoupEval AlgorithmeNegaMax(Echiquier& Plateau, Couleur CouleurAJouer, int Profondeur);
};

#endif
