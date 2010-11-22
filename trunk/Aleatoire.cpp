#include "echiquier.h"
#include "structure.h"
#include "Aleatoire.h"
#include <vector>
#include <stdlib.h>
//#include "time.h"

Coup Aleatoire::TrouverCoupAJouer(Echiquier& Plateau, Couleur CouleurAJoueur)
{
    vector<Coup> ListeCoup;
    ListeCoup = Plateau.GetListeCoup();
    int CoupAleatoire;
    CoupAleatoire = int((rand()/(double) (RAND_MAX)) * ListeCoup.size());
    return ListeCoup[CoupAleatoire];
}

