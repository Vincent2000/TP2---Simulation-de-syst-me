#include <cstdio>
#include <stdio.h>
#include <math.h>
#include <vector>
#include "lancerDe.h"
#include "personnage.h"
#include "carte.h"
using namespace std;


//Si vous voulez changez le nombre de pas, commenter/decommenter les lignes 26-27, 39-40, 64-65 


#define NOMBRE_PAS 50
// #define NOMBRE_PAS 510
#define CONFIGURATION 'S'

//Partie 3
void marcheAleatoire(int n, char configuration)
{
    //ecriture dans le fichier resultat.txt
    FILE * fp;
    int i;
    /* open the file for writing*/
    fp = fopen ("./resultat.txt","w");
 
 
    //Le personnage est place au centre de la carte
    Personnage moi = Personnage(10, 10);
    // Personnage moi = Personnage(550, 550);
    int k, direction;

    printf("%d %c\n", n, configuration);

    long unsigned modulo = pow(2, 16);
    int a = 16807;
    int c = 7;
    long unsigned x = 0;

    Position nouvellePosition;
    carte carte;
    carte.tab_=vector<vector<int>> (20, vector<int> (20, 0));
    // carte.tab_=vector<vector<int>> (1100, vector<int> (1100, 0));

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

        fprintf (fp, "%d\t%d\n",nouvellePosition.i_, nouvellePosition.j_);

        if (k%51==0) {
            moi.historique_.clear();
            moi = Personnage(10, 10);
            // moi = Personnage(550, 550);
            fprintf (fp, "\n\n");
        }
        
        moi.move(nouvellePosition);
        carte.tab_[moi.position_.i_][moi.position_.j_] = k+1;
    }
    printf("\n\n");
    moi.afficherHistorique();
    carte.afficherCarte();

    /* close the text file*/  
    fclose (fp);
}
