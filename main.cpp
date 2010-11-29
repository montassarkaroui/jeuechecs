#include <iostream>
#include <math.h>
#include "structure.h"
#include "piece.h"
#include "Roi.h"
#include "echiquier.h"
#include "Humain.h"
#include "Aleatoire.h"
#include "Elagage.h"
#include "time.h"
#include <stdlib.h>
using namespace std;

int main ()
{
    Echiquier Test;
    Humain Adrien;
    Aleatoire Maxime;
    Elagage Nicolas;
    srand(time(NULL));

    bool Status;
    Test.Affichage();

    int i = 0;
    while(!Test.GetFin() && i<1000)
    {
        do
        {
            Test.CreationFichierDebugage();
            Status = Test.BougerTotal(Maxime.TrouverCoupAJouer(Test, Test.GetCouleurAJouer()));
        }
        while(!Status);
        if (!Test.GetFin())
        {
            do
            {
                Test.CreationFichierDebugage();
                Status = Test.BougerTotal(Maxime.TrouverCoupAJouer(Test, Test.GetCouleurAJouer()));
            }
            while(!Status);
        }
        i += 1;
    }

//    cout << "C'est la fin" << endl;
//    sleep(5);
    return 0;
}
