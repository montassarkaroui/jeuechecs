#include "echiquier.h"
#include "structure.h"
#include "NegaMax.h"
#include "Eval.h"
#include <vector>
#include <iostream>
using namespace std;

NegaMax::NegaMax() { m_Niveau = 4; }

Coup NegaMax::TrouverCoupAJouer(Echiquier& Plateau, Couleur CouleurAJouer)
{
    int Profondeur = 0;
    return AlgorithmeNegaMax(Plateau, CouleurAJouer, Profondeur).CoupAJouer;
}
CoupEval NegaMax::AlgorithmeNegaMax(Echiquier& Plateau, Couleur CouleurAJouer, int Profondeur)
{
    CoupEval CoupAJouer;
    CoupEval CoupAJouerTemporaire;
    CoupAJouer.Evaluation = -GrandInfini;
    CoupAJouerTemporaire.Evaluation = -GrandInfini;

    vector<Coup> ListeCoup;
    Plateau.GetListeCoup(ListeCoup);

    if (Profondeur >= m_Niveau || Plateau.GetFin() || ListeCoup.size() == 0) { CoupAJouer.Evaluation = EvaluationPosition(Plateau); }
    else
    {
        for(unsigned int i=0; i<ListeCoup.size(); i++)
        {
            Plateau.Bouger(ListeCoup[i]);
            Plateau.TrouverListeCoup();
            Profondeur += 1;

            if (CouleurAJouer == Noir) { CoupAJouerTemporaire = AlgorithmeNegaMax(Plateau, Blanc, Profondeur); }
            else { CoupAJouerTemporaire = AlgorithmeNegaMax(Plateau, Noir, Profondeur); }
            CoupAJouerTemporaire.Evaluation *= -1;

            Plateau.BougerInverse(ListeCoup[i]);
            Plateau.TrouverListeCoup();
            Profondeur -= 1;

            if (CoupAJouerTemporaire.Evaluation > CoupAJouer.Evaluation)
            {
                CoupAJouer.Evaluation = CoupAJouerTemporaire.Evaluation;
                CoupAJouer.CoupAJouer = ListeCoup[i];
            }
        }
    }

    //if (Profondeur == 0) { cout << "\r";}
    return CoupAJouer;
}

