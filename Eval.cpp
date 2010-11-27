#include "Eval.h"
#include "structure.h"
#include "echiquier.h"
#include "piece.h"

double EvaluationPosition(Echiquier Plateau)
{
    double Evaluation;
    if (Plateau.GetEchecEtMat())
    {
        if (Plateau.GetCouleurAJouer() == Blanc) { return ValeurEchetEtMat; }
        else { return -ValeurEchetEtMat; }
    }
    if (Plateau.GetFin()) { return 0; }
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if (Plateau.GetListePiece(i, j) != NULL)
            {
                if (Plateau.GetListePiece(i, j)->GetCouleur() == Blanc) { Evaluation += Plateau.GetListePiece(i, j)->GetValeur(); }
                else { Evaluation -= Plateau.GetListePiece(i, j)->GetValeur(); }
            }
        }
    }
    return Evaluation;
}
