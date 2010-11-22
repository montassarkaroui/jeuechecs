#ifndef __Echiquier
#define __Echiquier

#include "piece.h"
#include "Roi.h"
#include <vector>

class Echiquier
{

private:

Piece* m_ListePiece[32];
Piece* m_Plateau[8][8];
ull m_PieceBlanche;
ull m_PieceNoire;
ull m_DeplacementBlanc;
ull m_DeplacementNoir;
bool m_EchecBlanc;
bool m_EchecNoir;
Couleur m_CouleurAJouer;
bool m_Fin;
vector<Coup> m_ListeCoup;

public:

//Constructeur & Destructeur
Echiquier();

//Getteurs et Setteurs
bool GetFin();
Couleur GetCouleurAJouer();
vector<Coup> GetListeCoup();

//Méthodes pour le déplacement
void TrouverDeplacement(Couleur CouleurAJouer);
void TrouverListeCoup();
void Bouger(Coup& CoupAJouer);
bool VerificationCoup(Coup CoupAVerifier);
bool BougerTotal(Coup CoupAJouer);
void BougerInverse(Coup CoupAInverser);

//Méthode pour l'affichage
void Affichage();

//Pour le débugage
ull DeplacementPossible(int i);
void AffichageCoup(int i);

};
#endif
