#include <cstdio>
#include <math.h>
#include <vector>
#include "lancerDe.h"
#include "personnage.h"
#include "carte.h"
using namespace std;

#define TAILLE_CARTE 20
#define NOMBRE_PAS 10
#define CONFIGURATION 'U'

/**
 * 
 * 
 */
void marcheAleatoire(int n, char configuration)
{
    Personnage moi = Personnage(5, 5);
    int k, direction;

    printf("%d %c\n", n, configuration);

    long unsigned modulo = pow(2, 16);
    int a = 16807;
    int c = 7;
    long unsigned x = 0;

    Position nouvellePosition;
    carte carte;
    // carte = carte();
    carte.tab_=vector<vector<int>> (20, vector<int> (20, 0));

    for (k = 0; k < n; k++)
    {
        do
        {
            x = genererNombre(modulo, a, c, x);
            direction = x * 4 / modulo;
            nouvellePosition = moi.position_;
            if (direction == 0)
                nouvellePosition.j_++;
            else if (direction == 1)
                nouvellePosition.i_++;
            else if (direction == 2)
                nouvellePosition.j_--;
            else
                nouvellePosition.i_--;

        } while (!moi.estAutorise(nouvellePosition, configuration, carte.tab_.size()));
        moi.move(nouvellePosition);
        printf("[%u; %u]\n", nouvellePosition.i_, nouvellePosition.j_);
        carte.tab_[moi.position_.i_][moi.position_.j_] = k+1;
    }
    printf("\n\n");
    moi.afficherHistorique();
    carte.afficherCarte();
}
