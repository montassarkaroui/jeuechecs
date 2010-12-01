#include "structure.h"
#include "piece.h"
#include "echiquier.h"
#include "Dame.h"
#include "Roi.h"
#include "Fou.h"
#include "Cavalier.h"
#include "Tour.h"
#include "Pion.h"
#include "math.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;


Echiquier::Echiquier()
{
    Position Case;
    ull Un = 1;

    // Initialisation des pointeurs des pièce à NULL
    for(int i=0; i<32; i++)
    {
        m_ListePiece[i]=NULL;
    }
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            m_Plateau[i][j] = NULL;
        }
    }

    // Declaration des Pieces...
    // ...Blanches...
    Case.Colonne = 4;
    Case.Rangee = 7;
    m_ListePiece[0] = new Roi(Case, Blanc);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[0];
    Case.Colonne = 3;
    Case.Rangee = 7;
    m_ListePiece[1] = new Dame(Case, Blanc);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[1];
    Case.Colonne = 0;
    Case.Rangee = 7;
    m_ListePiece[2] = new Tour(Case, Blanc);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[2];
    Case.Colonne = 7;
    Case.Rangee = 7;
    m_ListePiece[3] = new Tour(Case, Blanc);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[3];
    Case.Colonne = 2;
    Case.Rangee = 7;
    m_ListePiece[4] = new Fou(Case, Blanc);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[4];
    Case.Colonne = 5;
    Case.Rangee = 7;
    m_ListePiece[5] = new Fou(Case, Blanc);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[5];
    Case.Colonne = 1;
    Case.Rangee = 7;
    m_ListePiece[6] = new Cavalier(Case, Blanc);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[6];
    Case.Colonne = 6;
    Case.Rangee = 7;
    m_ListePiece[7] = new Cavalier(Case, Blanc);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[7];
    Case.Colonne = 0;
    Case.Rangee = 6;
    m_ListePiece[8] = new Pion(Case, Blanc);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[8];
    Case.Colonne = 1;
    Case.Rangee = 6;
    m_ListePiece[9] = new Pion(Case, Blanc);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[9];
    Case.Colonne = 2;
    Case.Rangee = 6;
    m_ListePiece[10] = new Pion(Case, Blanc);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[10];
    Case.Colonne = 3;
    Case.Rangee = 6;
    m_ListePiece[11] = new Pion(Case, Blanc);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[11];
    Case.Colonne = 4;
    Case.Rangee = 6;
    m_ListePiece[12] = new Pion(Case, Blanc);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[12];
    Case.Colonne = 5;
    Case.Rangee = 6;
    m_ListePiece[13] = new Pion(Case, Blanc);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[13];
    Case.Colonne = 6;
    Case.Rangee = 6;
    m_ListePiece[14] = new Pion(Case, Blanc);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[14];
    Case.Colonne = 7;
    Case.Rangee = 6;
    m_ListePiece[15] = new Pion(Case, Blanc);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[15];
    // ...et Noires
    Case.Colonne = 4;
    Case.Rangee = 0;
    m_ListePiece[16] = new Roi(Case, Noir);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[16];
    Case.Colonne = 3;
    Case.Rangee = 0;
    m_ListePiece[17] = new Dame(Case, Noir);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[17];
    Case.Colonne = 0;
    Case.Rangee = 0;
    m_ListePiece[18] = new Tour(Case, Noir);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[18];
    Case.Colonne = 7;
    Case.Rangee = 0;
    m_ListePiece[19] = new Tour(Case, Noir);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[19];
    Case.Colonne = 2;
    Case.Rangee = 0;
    m_ListePiece[20] = new Fou(Case, Noir);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[20];
    Case.Colonne = 5;
    Case.Rangee = 0;
    m_ListePiece[21] = new Fou(Case, Noir);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[21];
    Case.Colonne = 1;
    Case.Rangee = 0;
    m_ListePiece[22] = new Cavalier(Case, Noir);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[22];
    Case.Colonne = 6;
    Case.Rangee = 0;
    m_ListePiece[23] = new Cavalier(Case, Noir);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[23];
    Case.Colonne = 0;
    Case.Rangee = 1;
    m_ListePiece[24] = new Pion(Case, Noir);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[24];
    Case.Colonne = 1;
    Case.Rangee = 1;
    m_ListePiece[25] = new Pion(Case, Noir);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[25];
    Case.Colonne = 2;
    Case.Rangee = 1;
    m_ListePiece[26] = new Pion(Case, Noir);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[26];
    Case.Colonne = 3;
    Case.Rangee = 1;
    m_ListePiece[27] = new Pion(Case, Noir);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[27];
    Case.Colonne = 4;
    Case.Rangee = 1;
    m_ListePiece[28] = new Pion(Case, Noir);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[28];
    Case.Colonne = 5;
    Case.Rangee = 1;
    m_ListePiece[29] = new Pion(Case, Noir);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[29];
    Case.Colonne = 6;
    Case.Rangee = 1;
    m_ListePiece[30] = new Pion(Case, Noir);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[30];
    Case.Colonne = 7;
    Case.Rangee = 1;
    m_ListePiece[31] = new Pion(Case, Noir);
    m_Plateau[Case.Rangee][Case.Colonne]=m_ListePiece[31];

    m_CouleurAJouer = Blanc;
    m_EchecBlanc = false;
    m_EchecNoir =  false;
    m_EchecEtMat = false;
    m_Fin = false;

    m_PieceBlanche = 0;
    m_PieceNoire = 0;
    for (int i=0; i<16; i++)
    {
        m_PieceBlanche |= (Un << (i+48));
        m_PieceNoire |= (Un << i);
        m_ListePiece[i]->SetNumero(i);
        m_ListePiece[i+16]->SetNumero(i+16);
    }

    //Pour le roque
    m_NombreDeplacementTourBlancGrandRoque = 0;
    m_NombreDeplacementTourBlancPetitRoque = 0;
    m_NombreDeplacementRoiBlanc = 0;
    m_NombreDeplacementTourNoirGrandRoque = 0;
    m_NombreDeplacementTourNoirPetitRoque = 0;
    m_NombreDeplacementRoiNoir = 0;
    //Fin pour le roque

    TrouverDeplacement(Blanc);
    TrouverDeplacement(Noir);
    TrouverListeCoup();
}

//Getteurs et Setteurs

bool Echiquier::GetFin() { return m_Fin; }

bool Echiquier::GetEchecEtMat() { return m_EchecEtMat; }

Couleur Echiquier::GetCouleurAJouer() { return m_CouleurAJouer; }

vector<Coup> Echiquier::GetListeCoup() { return m_ListeCoup; }

void Echiquier::GetListeCoup(vector<Coup>& ListeCoup)
{
    ListeCoup.clear();
    for(unsigned int i=0; i<m_ListeCoup.size(); i++)
    {
        ListeCoup.push_back(m_ListeCoup[i]);
    }
}

Piece* Echiquier::GetListePiece(int i, int j) { return m_Plateau[i][j]; }

//Méthodes pour le déplacement

void Echiquier::TrouverDeplacement(Couleur CouleurAJouer)
{
    if (CouleurAJouer == Blanc)
    {
        m_DeplacementBlanc = 0;
        for(int i=0; i<16; i++)
        {
            if (m_ListePiece[i]->GetVivante()) { m_DeplacementPiece[i] = m_ListePiece[i]->MouvementPossible(m_PieceNoire, m_PieceBlanche); }
            else { m_DeplacementPiece[i] = 0; }
            m_DeplacementBlanc |= m_DeplacementPiece[i];
        }
    }
    else
    {
        m_DeplacementNoir = 0;
        for(int i=16; i<32; i++)
        {
            if (m_ListePiece[i]->GetVivante()) { m_DeplacementPiece[i] = m_ListePiece[i]->MouvementPossible(m_PieceBlanche, m_PieceNoire); }
            else { m_DeplacementPiece[i] = 0; }
            m_DeplacementNoir |= m_DeplacementPiece[i];
        }
    }
}

void Echiquier::TrouverListeCoup()
{
    vector<Coup> ListeCoupFinal;
    ListeCoupFinal.clear();
    m_ListeCoup.clear();
    if (m_CouleurAJouer == Blanc)
    {
        ConversionUllCoup(m_ListeCoup, m_DeplacementPiece[0] & ~(m_DeplacementPiece[0] & m_DeplacementNoir), m_ListePiece[0]->GetPosition());
        //Pour le roque
        VerifierRoque();
        //Fin pour le roque
        for(int i=1; i<16; i++)
        {
            if (m_ListePiece[i]->GetVivante()) ConversionUllCoup(m_ListeCoup, m_DeplacementPiece[i], m_ListePiece[i]->GetPosition());
        }
        for(unsigned int i=0; i<m_ListeCoup.size(); i++)
        {
            Bouger(m_ListeCoup[i]);
            if (!m_EchecBlanc)
            {
                ListeCoupFinal.push_back(m_ListeCoup[i]);
            }
            BougerInverse(m_ListeCoup[i]);
        }
    }
    else
    {
        ConversionUllCoup(m_ListeCoup, m_DeplacementPiece[16] & ~(m_DeplacementPiece[16] & m_DeplacementBlanc), m_ListePiece[16]->GetPosition());
        //Pour le roque
        VerifierRoque();
        //Fin Pour le Roque
        for(int i=17; i<32; i++)
        {
            if (m_ListePiece[i]->GetVivante()) ConversionUllCoup(m_ListeCoup, m_DeplacementPiece[i], m_ListePiece[i]->GetPosition());
        }
        for(unsigned int i=0; i<m_ListeCoup.size(); i++)
        {
            Bouger(m_ListeCoup[i]);
            if (!m_EchecNoir)
            {
                ListeCoupFinal.push_back(m_ListeCoup[i]);
            }
            BougerInverse(m_ListeCoup[i]);
        }
    }
    m_ListeCoup.clear();
    for (unsigned int i=0; i<ListeCoupFinal.size(); i++)
    {
        m_ListeCoup.push_back(ListeCoupFinal[i]);
    }
    ListeCoupFinal.clear();
    if (m_ListeCoup.size() == 0)
    {
        m_Fin = true;
        if (m_EchecNoir || m_EchecBlanc) { m_EchecEtMat = true; }
    }
}

void Echiquier::Bouger(Coup& CoupAJouer)
{
    ull Un = 1;
    //Pour le Roque
    if (CoupAJouer.Roque)
    {
        BougerRoque(CoupAJouer);
    }
    else
    {
        //Fin Pour le roque
        if (m_Plateau[CoupAJouer.Arrive.Rangee][CoupAJouer.Arrive.Colonne] != NULL)
        {
            if (m_Plateau[CoupAJouer.Arrive.Rangee][CoupAJouer.Arrive.Colonne]->GetCouleur() == Blanc)
            {
                m_PieceBlanche &= ~(Un << (CoupAJouer.Arrive.Rangee*8+CoupAJouer.Arrive.Colonne));
            }
            else
            {
                m_PieceNoire &= ~(Un << (CoupAJouer.Arrive.Rangee*8+CoupAJouer.Arrive.Colonne));
            }
            CoupAJouer.BoolPiecePrise = true;
            CoupAJouer.PiecePrise = m_Plateau[CoupAJouer.Arrive.Rangee][CoupAJouer.Arrive.Colonne]->GetNumero();
            m_Plateau[CoupAJouer.Arrive.Rangee][CoupAJouer.Arrive.Colonne]->SetVivante(false);
        }
        else
        {
            CoupAJouer.BoolPiecePrise = false;
        }
        //Pour le Roque
        switch (m_Plateau[CoupAJouer.Depart.Rangee][CoupAJouer.Depart.Colonne]->GetNumero())
        {
            case 0:
                m_NombreDeplacementRoiBlanc += 1;
                break;
            case 2:
                m_NombreDeplacementTourBlancGrandRoque += 1;
                break;
            case 3:
                m_NombreDeplacementTourBlancPetitRoque += 1;
                break;
            case 16:
                m_NombreDeplacementRoiNoir += 1;
                break;
            case 18:
                m_NombreDeplacementTourNoirGrandRoque += 1;
                break;
            case 19:
                m_NombreDeplacementTourNoirGrandRoque += 1;
        }
        //Fin pour le roque
        m_Plateau[CoupAJouer.Arrive.Rangee][CoupAJouer.Arrive.Colonne] = m_Plateau[CoupAJouer.Depart.Rangee][CoupAJouer.Depart.Colonne];
        m_Plateau[CoupAJouer.Arrive.Rangee][CoupAJouer.Arrive.Colonne]->SetPosition(CoupAJouer.Arrive);
        m_Plateau[CoupAJouer.Depart.Rangee][CoupAJouer.Depart.Colonne] = NULL;
        if (m_Plateau[CoupAJouer.Arrive.Rangee][CoupAJouer.Arrive.Colonne]->GetCouleur() == Blanc)
        {
            m_PieceBlanche &= ~(Un << (CoupAJouer.Depart.Rangee*8+CoupAJouer.Depart.Colonne));
            m_PieceBlanche |= (Un << (CoupAJouer.Arrive.Rangee*8+CoupAJouer.Arrive.Colonne));
            m_CouleurAJouer = Noir;
        }
        else
        {
            m_PieceNoire &= ~(Un << (CoupAJouer.Depart.Rangee*8+CoupAJouer.Depart.Colonne));
            m_PieceNoire |= (Un << (CoupAJouer.Arrive.Rangee*8+CoupAJouer.Arrive.Colonne));
            m_CouleurAJouer = Blanc;
        }
    }
    TrouverDeplacement(Blanc);
    TrouverDeplacement(Noir);
    m_EchecBlanc = (((Un << (m_ListePiece[0]->GetPosition().Rangee*8+m_ListePiece[0]->GetPosition().Colonne)) & m_DeplacementNoir) != 0);
    m_EchecNoir = (((Un << (m_ListePiece[16]->GetPosition().Rangee*8+m_ListePiece[16]->GetPosition().Colonne)) & m_DeplacementBlanc) != 0);
}

bool Echiquier::VerificationCoup(Coup& CoupAVerifier)
{
    bool AppartientALaListe = false;
    for(unsigned int i=0; i<m_ListeCoup.size(); i++)
    {
        if (CoupAVerifier.Depart.Rangee == m_ListeCoup[i].Depart.Rangee && CoupAVerifier.Depart.Colonne == m_ListeCoup[i].Depart.Colonne && CoupAVerifier.Arrive.Rangee == m_ListeCoup[i].Arrive.Rangee && CoupAVerifier.Arrive.Colonne == m_ListeCoup[i].Arrive.Colonne)
        {
            AppartientALaListe = true;
            CoupAVerifier = m_ListeCoup[i];
        }
    }
    return AppartientALaListe;
}

bool Echiquier::BougerTotal(Coup CoupAJouer)
{
    if (!VerificationCoup(CoupAJouer))
    {
        cout << "CoupInvalide" << endl;
        return false;
    }
    else
    {
        Bouger(CoupAJouer);
        Affichage();
        TrouverListeCoup();
        return true;
    }
}

void Echiquier::BougerInverse(Coup CoupAInverser)
{
    ull Un = 1;
    if (CoupAInverser.Roque)
    {
        BougerRoqueInverse(CoupAInverser);
    }
    else
    {
        m_Plateau[CoupAInverser.Depart.Rangee][CoupAInverser.Depart.Colonne] = m_Plateau[CoupAInverser.Arrive.Rangee][CoupAInverser.Arrive.Colonne];
        if (CoupAInverser.BoolPiecePrise)
        {
            m_Plateau[CoupAInverser.Arrive.Rangee][CoupAInverser.Arrive.Colonne] = m_ListePiece[CoupAInverser.PiecePrise];
            m_Plateau[CoupAInverser.Arrive.Rangee][CoupAInverser.Arrive.Colonne]->SetVivante(true);
            if (m_CouleurAJouer == Blanc) m_PieceBlanche |= (Un << (CoupAInverser.Arrive.Rangee*8+CoupAInverser.Arrive.Colonne));
            else m_PieceNoire |= (Un << (CoupAInverser.Arrive.Rangee*8+CoupAInverser.Arrive.Colonne));
        }
        else
        {
            m_Plateau[CoupAInverser.Arrive.Rangee][CoupAInverser.Arrive.Colonne] = NULL;
        }
        //Pour le Roque
        switch (m_Plateau[CoupAInverser.Depart.Rangee][CoupAInverser.Depart.Colonne]->GetNumero())
        {
            case 0:
                m_NombreDeplacementRoiBlanc -= 1;
                break;
            case 2:
                m_NombreDeplacementTourBlancGrandRoque -= 1;
                break;
            case 3:
                m_NombreDeplacementTourBlancPetitRoque -= 1;
                break;
            case 16:
                m_NombreDeplacementRoiNoir -= 1;
                break;
            case 18:
                m_NombreDeplacementTourNoirGrandRoque -= 1;
                break;
            case 19:
                m_NombreDeplacementTourNoirGrandRoque -= 1;
        }
        //Fin pour le roque
        m_Plateau[CoupAInverser.Depart.Rangee][CoupAInverser.Depart.Colonne]->SetPosition(CoupAInverser.Depart);
        if (m_CouleurAJouer == Blanc)
        {
            m_CouleurAJouer = Noir;
            m_PieceNoire &= ~(Un << (CoupAInverser.Arrive.Rangee*8+CoupAInverser.Arrive.Colonne));
            m_PieceNoire |= (Un << (CoupAInverser.Depart.Rangee*8+CoupAInverser.Depart.Colonne));
        }
        else
        {
            m_CouleurAJouer = Blanc;
            m_PieceBlanche &= ~(Un << (CoupAInverser.Arrive.Rangee*8+CoupAInverser.Arrive.Colonne));
            m_PieceBlanche |= (Un << (CoupAInverser.Depart.Rangee*8+CoupAInverser.Depart.Colonne));
        }
    }
    TrouverDeplacement(Blanc);
    TrouverDeplacement(Noir);
    m_EchecBlanc = (((Un << (m_ListePiece[0]->GetPosition().Rangee*8+m_ListePiece[0]->GetPosition().Colonne)) & m_DeplacementNoir) != 0);
    m_EchecNoir = (((Un << (m_ListePiece[16]->GetPosition().Rangee*8+m_ListePiece[16]->GetPosition().Colonne)) & m_DeplacementBlanc) != 0);
    m_Fin = false;
    m_EchecEtMat = false;
}

//Méthodes pour le Roque

void Echiquier::VerifierRoque()
{
    ull Un = 1;
    Coup CoupRoque;
    if (m_CouleurAJouer == Blanc)
    {
        if (m_NombreDeplacementRoiBlanc == 0 && !m_EchecBlanc)
        {
            if (m_NombreDeplacementTourBlancPetitRoque == 0 && m_Plateau[7][5] == NULL && m_Plateau[7][6] == NULL && ((m_DeplacementNoir & (Un << (7*8+5))) == 0))
            {
                CoupRoque.Depart.Rangee = 7;
                CoupRoque.Depart.Colonne = 4;
                CoupRoque.Arrive.Rangee = 7;
                CoupRoque.Arrive.Colonne = 6;
                CoupRoque.Roque = true;
                CoupRoque.PetitRoque = true;
                CoupRoque.GrandRoque = false;
                m_ListeCoup.push_back(CoupRoque);
            }
            if (m_NombreDeplacementTourBlancGrandRoque == 0 && m_Plateau[7][3] == NULL && m_Plateau[7][2] == NULL && m_Plateau[7][1] == NULL && ((m_DeplacementNoir & (Un << (7*8+3))) == 0))
            {
                CoupRoque.Depart.Rangee = 7;
                CoupRoque.Depart.Colonne = 4;
                CoupRoque.Arrive.Rangee = 7;
                CoupRoque.Arrive.Colonne = 2;
                CoupRoque.Roque = true;
                CoupRoque.PetitRoque = false;
                CoupRoque.GrandRoque = true;
                m_ListeCoup.push_back(CoupRoque);
            }
        }
    }
    else
    {
        if (m_NombreDeplacementRoiNoir == 0 && !m_EchecNoir)
        {
            if (m_NombreDeplacementTourNoirPetitRoque == 0 && m_Plateau[0][5] == NULL && m_Plateau[0][6] == NULL && ((m_DeplacementBlanc & (Un << (0*8+5))) == 0))
            {
                CoupRoque.Depart.Rangee = 0;
                CoupRoque.Depart.Colonne = 4;
                CoupRoque.Arrive.Rangee = 0;
                CoupRoque.Arrive.Colonne = 6;
                CoupRoque.Roque = true;
                CoupRoque.PetitRoque = true;
                CoupRoque.GrandRoque = false;
                m_ListeCoup.push_back(CoupRoque);
            }
            if (m_NombreDeplacementTourNoirGrandRoque == 0 && m_Plateau[0][3] == NULL && m_Plateau[0][2] == NULL && m_Plateau[0][1] == NULL && ((m_DeplacementBlanc & (Un << (0*8+3))) == 0))
            {
                CoupRoque.Depart.Rangee = 0;
                CoupRoque.Depart.Colonne = 4;
                CoupRoque.Arrive.Rangee = 0;
                CoupRoque.Arrive.Colonne = 2;
                CoupRoque.Roque = true;
                CoupRoque.PetitRoque = false;
                CoupRoque.GrandRoque = true;
                m_ListeCoup.push_back(CoupRoque);
            }
        }
    }
}

void Echiquier::BougerRoque(Coup CoupRoque)
{
    ull Un = 1;
    Position TourRoque;
    if (m_CouleurAJouer == Blanc)
    {
        if (CoupRoque.PetitRoque)
        {
            m_CouleurAJouer = Noir;
            m_PieceBlanche &= ~((Un << (7*8+4)) | (Un << (7*8+7)));
            m_PieceBlanche |= ((Un << (7*8+6)) | (Un << (7*8+5)));
            m_Plateau[7][6] = m_Plateau[7][4];
            m_Plateau[7][5] = m_Plateau[7][7];
            m_Plateau[7][4] = NULL;
            m_Plateau[7][7] = NULL;
            m_Plateau[7][6]->SetPosition(CoupRoque.Arrive);
            TourRoque.Rangee = 7;
            TourRoque.Colonne = 5;
            m_Plateau[7][5]->SetPosition(TourRoque);
            m_NombreDeplacementRoiBlanc += 1;
            m_NombreDeplacementTourBlancPetitRoque += 1;
        }
        else
        {
            m_CouleurAJouer = Noir;
            m_PieceBlanche &= ~((Un << (7*8+4)) | (Un << (7*8+0)));
            m_PieceBlanche |= ((Un << (7*8+2)) | (Un << (7*8+3)));
            m_Plateau[7][2] = m_Plateau[7][4];
            m_Plateau[7][3] = m_Plateau[7][0];
            m_Plateau[7][4] = NULL;
            m_Plateau[7][0] = NULL;
            m_Plateau[7][2]->SetPosition(CoupRoque.Arrive);
            TourRoque.Rangee = 7;
            TourRoque.Colonne = 3;
            m_Plateau[7][3]->SetPosition(TourRoque);
            m_NombreDeplacementRoiBlanc += 1;
            m_NombreDeplacementTourBlancGrandRoque += 1;
        }
    }
    else
    {
        if (CoupRoque.PetitRoque)
        {
            m_CouleurAJouer = Blanc;
            m_PieceNoire &= ~((Un << (0*8+4)) | (Un << (0*8+7)));
            m_PieceNoire |= ((Un << (0*8+6)) | (Un << (0*8+5)));
            m_Plateau[0][6] = m_Plateau[0][4];
            m_Plateau[0][5] = m_Plateau[0][7];
            m_Plateau[0][4] = NULL;
            m_Plateau[0][7] = NULL;
            m_Plateau[0][6]->SetPosition(CoupRoque.Arrive);
            TourRoque.Rangee = 0;
            TourRoque.Colonne = 5;
            m_Plateau[0][5]->SetPosition(TourRoque);
            m_NombreDeplacementRoiNoir += 1;
            m_NombreDeplacementTourNoirPetitRoque += 1;
        }
        else
        {
            m_CouleurAJouer = Blanc;
            m_PieceNoire &= ~((Un << (0*8+4)) | (Un << (0*8+0)));
            m_PieceNoire |= ((Un << (0*8+2)) | (Un << (0*8+3)));
            m_Plateau[0][2] = m_Plateau[0][4];
            m_Plateau[0][3] = m_Plateau[0][0];
            m_Plateau[0][4] = NULL;
            m_Plateau[0][0] = NULL;
            m_Plateau[0][2]->SetPosition(CoupRoque.Arrive);
            TourRoque.Rangee = 0;
            TourRoque.Colonne = 3;
            m_Plateau[0][3]->SetPosition(TourRoque);
            m_NombreDeplacementRoiNoir += 1;
            m_NombreDeplacementTourNoirGrandRoque += 1;
        }
    }
}

void Echiquier::BougerRoqueInverse(Coup CoupRoqueAInverser)
{
    ull Un = 1;
    Position TourRoque;
    if (m_CouleurAJouer == Noir)
    {
        if (CoupRoqueAInverser.PetitRoque)
        {
            m_CouleurAJouer = Blanc;
            m_PieceBlanche |= ((Un << (7*8+4)) | (Un << (7*8+7)));
            m_PieceBlanche &= ~((Un << (7*8+6)) | (Un << (7*8+5)));
            m_Plateau[7][4] = m_Plateau[7][6];
            m_Plateau[7][7] = m_Plateau[7][5];
            m_Plateau[7][6] = NULL;
            m_Plateau[7][5] = NULL;
            m_Plateau[7][4]->SetPosition(CoupRoqueAInverser.Depart);
            TourRoque.Rangee = 7;
            TourRoque.Colonne = 7;
            m_Plateau[7][7]->SetPosition(TourRoque);
            m_NombreDeplacementRoiBlanc -= 1;
            m_NombreDeplacementTourBlancPetitRoque -= 1;
        }
        else
        {
            m_CouleurAJouer = Blanc;
            m_PieceBlanche |= ((Un << (7*8+4)) | (Un << (7*8+0)));
            m_PieceBlanche &= ~((Un << (7*8+2)) | (Un << (7*8+3)));
            m_Plateau[7][4] = m_Plateau[7][2];
            m_Plateau[7][0] = m_Plateau[7][3];
            m_Plateau[7][2] = NULL;
            m_Plateau[7][3] = NULL;
            m_Plateau[7][4]->SetPosition(CoupRoqueAInverser.Depart);
            TourRoque.Rangee = 7;
            TourRoque.Colonne = 0;
            m_Plateau[7][0]->SetPosition(TourRoque);
            m_NombreDeplacementRoiBlanc -= 1;
            m_NombreDeplacementTourBlancGrandRoque -= 1;
        }
    }
    else
    {
        if (CoupRoqueAInverser.PetitRoque)
        {
            m_CouleurAJouer = Noir;
            m_PieceNoire |= ((Un << (0*8+4)) | (Un << (0*8+7)));
            m_PieceNoire &= ~((Un << (0*8+6)) | (Un << (0*8+5)));
            m_Plateau[0][4] = m_Plateau[0][6];
            m_Plateau[0][7] = m_Plateau[0][5];
            m_Plateau[0][6] = NULL;
            m_Plateau[0][5] = NULL;
            m_Plateau[0][4]->SetPosition(CoupRoqueAInverser.Depart);
            TourRoque.Rangee = 0;
            TourRoque.Colonne = 7;
            m_Plateau[0][7]->SetPosition(TourRoque);
            m_NombreDeplacementRoiNoir -= 1;
            m_NombreDeplacementTourNoirPetitRoque -= 1;
        }
        else
        {
            m_CouleurAJouer = Noir;
            m_PieceNoire |= ((Un << (0*8+4)) | (Un << (0*8+0)));
            m_PieceNoire &= ~((Un << (0*8+2)) | (Un << (0*8+3)));
            m_Plateau[0][4] = m_Plateau[0][2];
            m_Plateau[0][0] = m_Plateau[0][3];
            m_Plateau[0][2] = NULL;
            m_Plateau[0][3] = NULL;
            m_Plateau[0][4]->SetPosition(CoupRoqueAInverser.Depart);
            TourRoque.Rangee = 0;
            TourRoque.Colonne = 0;
            m_Plateau[0][0]->SetPosition(TourRoque);
            m_NombreDeplacementRoiNoir -= 1;
            m_NombreDeplacementTourNoirGrandRoque -= 1;
        }
    }
}

//Méthode pour l'affichage

void Echiquier::Affichage()
{
    system("clear");

    cout << endl;
    for(int i=0; i<8; i++)
    {
        cout << i*-1+8 << " ";
        for(int j=0; j<8; j++)
        {
            cout << " ";
            if (m_Plateau[i][j] != NULL)
            {
                cout << m_Plateau[i][j]->GetSymbole();
            }
            else
            {
                cout << ".";
            }

        }
        cout <<  " " << endl;
    }
    cout << endl;
    cout << "   1 2 3 4 5 6 7 8" << endl;
}

//Pour le débugage

ull Echiquier::DeplacementPossible(int i)
{
    switch (m_ListePiece[i]->GetCouleur())
    {
        case Blanc:
            return m_ListePiece[i]->MouvementPossible(m_PieceNoire, m_PieceBlanche);
            break;
        case Noir:
            return m_ListePiece[i]->MouvementPossible(m_PieceBlanche, m_PieceNoire);
    }
}

void Echiquier::AffichageCoup(int i)
{
    cout << m_ListeCoup[i].Depart.Rangee << endl;
    cout << m_ListeCoup[i].Depart.Colonne << endl;
    cout << m_ListeCoup[i].Arrive.Rangee << endl;
    cout << m_ListeCoup[i].Arrive.Colonne << endl;
}

void Echiquier::CreationFichierDebugage()
{
    string NomFichierBlanc = "DebugBlanc";
    string NomFichierNoir = "DebugNoir";
    string Numero;
    ull DeplacementRoi;

    if (m_CouleurAJouer == Blanc)
    {
        ofstream FichierBlanc(NomFichierBlanc.c_str(), ios::out | ios::trunc);
        FichierBlanc.close();

        EcritureFichierUll(m_PieceBlanche, NomFichierBlanc, "PieceBlanche");
        EcritureFichierUll(m_PieceNoire, NomFichierBlanc, "PieceNoire");
        EcritureFichierUll(m_DeplacementBlanc, NomFichierBlanc, "DeplacementBlanc");
        EcritureFichierUll(m_DeplacementNoir, NomFichierBlanc, "DeplacementNoir");

        for(int i=0; i<32; i++)
        {
            EcritureFichierUll(m_DeplacementPiece[i], NomFichierBlanc, ConversionIntString(i));
        }
    }
    else
    {
        ofstream FichierNoir(NomFichierNoir.c_str(), ios::out | ios::trunc);
        FichierNoir.close();

        EcritureFichierUll(m_PieceBlanche, NomFichierNoir, "PieceBlanche");
        EcritureFichierUll(m_PieceNoire, NomFichierNoir, "PieceNoire");
        EcritureFichierUll(m_DeplacementBlanc, NomFichierNoir, "DeplacementBlanc");
        EcritureFichierUll(m_DeplacementNoir, NomFichierNoir, "DeplacementNoir");

        for(int i=0; i<32; i++)
        {
            EcritureFichierUll(m_DeplacementPiece[i], NomFichierNoir, ConversionIntString(i));
        }
    }

}
