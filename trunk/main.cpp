#include <iostream>
#include <math.h>
#include "structure.h"
#include "piece.h"
#include "Roi.h"
#include "echiquier.h"
#include "Humain.h"
#include "Aleatoire.h"
#include "time.h"
#include <stdlib.h>
using namespace std;

int main ()
{
    Echiquier Test;
    Humain Adrien;
    Aleatoire Maxime;
    srand(time(NULL));

    bool Status;

    Test.Affichage();
    while(!Test.GetFin())
    {
        do
        {
            Status = Test.BougerTotal(Adrien.TrouverCoupAJouer(Test, Test.GetCouleurAJouer()));
        }
        while(!Status);
        if (!Test.GetFin())
        {
            do
            {
                Status = Test.BougerTotal(Maxime.TrouverCoupAJouer(Test, Test.GetCouleurAJouer()));
            }
            while(!Status);
        }
    }

    cout << "C'est la fin" << endl;
    sleep(5);
    return 0;
}
