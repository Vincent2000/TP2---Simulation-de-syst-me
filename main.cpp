#include <cstdio>
#include "lancerDe.h"
using namespace std;


/**
 * 
 * 
 */
void marcheAleatoire(int argc, char *argv[])
{
    int n, i;
    char c;
    n = (int)argv[1]-'0';
    c = *argv[2];
    
    //Verification des parametres
    if (argc != 2)
    {
        printf("Mauvaise argumentation");
        return;
    }
    else if (!(n>0)) {
        printf("Nombre de pas pas positif");
        return;
    }
    else if(c != 'C' && c != 'S' && c != 'U')
    {
        printf("Marche aleatoire mal parametre");
        return;
    }

    for(i = 0; i < n; i++)
    {
        /* code */
    }
    
}

int main(int argc, char *argv[])
{
    lancerDe();
    // marcheAleatoire(argc, argv);
    // printf("Hello world !");
    return 0;
}