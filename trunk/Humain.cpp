#include "echiquier.h"
#include "structure.h"
#include "Humain.h"

Coup Humain::TrouverCoupAJouer(Echiquier& Plateau, Couleur CouleurAJoueur)
{
    int i;
    Coup CoupAJouer;
    cin >> i;
    CoupAJouer.Depart.Rangee = (i/1000)*-1+8;
    CoupAJouer.Depart.Colonne = (i-1000*(i/1000))/100-1;
    CoupAJouer.Arrive.Rangee = (i-100*(i/100))/10*-1+8;
    CoupAJouer.Arrive.Colonne = i%10-1;

    return CoupAJouer;
}
