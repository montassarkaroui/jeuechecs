#include "piece.h"
#include "structure.h"
#include <string>
using namespace std;


//Constructeur

Piece::Piece()
{
    m_Vivante = true;
}

//Getteurs et Setteurs
Position Piece::GetPosition()
{
    return m_Position;
}

Type Piece::GetType()
{
    return m_TypePiece;
}
string Piece::GetSymbole()
{
    return m_Symbole;
}

Couleur Piece::GetCouleur()
{
    return m_CouleurPiece;
}

bool Piece::GetVivante()
{
    return m_Vivante;
}

int Piece::GetNumero()
{
    return m_Numero;
}

void Piece::SetVivante(bool Valeur)
{
    m_Vivante = Valeur;
}

void Piece::SetPosition(Position PositionPiece)
{
    m_Position = PositionPiece;
}

void Piece::SetNumero(int Numero)
{
    m_Numero = Numero;
}
