#ifndef __Elagage
#define __Elagage

#include "echiquier.h"
#include "structure.h"
#include "Joueur.h"

class Elagage: public Joueur
{
    public:

    Elagage();
    Coup TrouverCoupAJouer(Echiquier& Plateau, Couleur CouleurAJouer);
    CoupEval AlgorithmeElagage(Echiquier& Plateau, Couleur CouleurAJouer, int Profondeur, double Alpha, double Beta, int Prise);
};

#endif

