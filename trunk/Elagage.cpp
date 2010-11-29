#include "echiquier.h"
#include "structure.h"
#include "Elagage.h"
#include "Eval.h"
#include <vector>
#include <iostream>
using namespace std;

Elagage::Elagage() { m_Niveau = 5; }

Coup Elagage::TrouverCoupAJouer(Echiquier& Plateau, Couleur CouleurAJouer)
{
    int Profondeur = 0;
    return AlgorithmeElagage(Plateau, CouleurAJouer, Profondeur, -GrandInfini, GrandInfini).CoupAJouer;
}
CoupEval Elagage::AlgorithmeElagage(Echiquier& Plateau, Couleur CouleurAJouer, int Profondeur, double Alpha, double Beta)
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

            if (CouleurAJouer == Noir) { CoupAJouerTemporaire = AlgorithmeElagage(Plateau, Blanc, Profondeur, -1*Beta, -1*Alpha); }
            else { CoupAJouerTemporaire = AlgorithmeElagage(Plateau, Noir, Profondeur, -1*Beta, -1*Alpha); }
            CoupAJouerTemporaire.Evaluation *= -1;

            Plateau.BougerInverse(ListeCoup[i]);
            Plateau.TrouverListeCoup();
            Profondeur -= 1;

            if (CoupAJouerTemporaire.Evaluation > CoupAJouer.Evaluation)
            {
                CoupAJouer.Evaluation = CoupAJouerTemporaire.Evaluation;
                CoupAJouer.CoupAJouer = ListeCoup[i];

                //if (Profondeur == 0) { cout << CoupAJouer.Evaluation;}

                if (CoupAJouer.Evaluation > Alpha)
                {
                    Alpha = CoupAJouer.Evaluation;
                    if (Alpha >= Beta) { break; }
                }
            }
        }
    }

    //if (Profondeur == 0) { cout << "\r";}
    return CoupAJouer;
}
