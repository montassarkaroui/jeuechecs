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

Couleur m_CouleurAJouer;

vector<Coup> m_ListeCoup;
ull* m_Deplacement[32];

bool m_EchecBlanc;
bool m_EchecNoir;
bool m_EchecEtMat;
bool m_Fin;
//Attribut pour le roque
    int m_NombreDeplacementTourBlancGrandRoque;
    int m_NombreDeplacementTourBlancPetitRoque;
    int m_NombreDeplacementRoiBlanc;
    int m_NombreDeplacementTourNoirGrandRoque;
    int m_NombreDeplacementTourNoirPetitRoque;
    int m_NombreDeplacementRoiNoir;

public:

//Constructeur & Destructeur
Echiquier();

//Getteurs et Setteurs
bool GetFin();
bool GetEchecEtMat();
Couleur GetCouleurAJouer();
vector<Coup> GetListeCoup();
void GetListeCoup(vector<Coup>& ListeCoup);
Piece* GetListePiece(int i, int j);

//Méthodes pour le déplacement
void TrouverDeplacement(Couleur CouleurAJouer);
void TrouverListeCoup();
void Bouger(Coup& CoupAJouer);
bool VerificationCoup(Coup& CoupAVerifier);
bool BougerTotal(Coup CoupAJouer);
void BougerInverse(Coup CoupAInverser);

//Méthodes pour le Roque;
void VerifierRoque();
void BougerRoque(Coup CoupRoque);
void BougerRoqueInverse(Coup CoupRoqueAInverser);

//Méthode pour l'affichage
void Affichage();

//Pour le débugage
ull DeplacementPossible(int i);
void AffichageCoup(int i);
void CreationFichierDebugage();

};
#endif
