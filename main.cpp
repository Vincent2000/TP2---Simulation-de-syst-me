#include <cstdio>
using namespace std;

int unsigned genererNombre(int modulo = 100000000, int a = 31415821, int c = 1, int unsigned x = 75214)
{
    return (a * x + c) % modulo;
}

void lancerDe(int modulo = 100000000, int a = 31415821, int c = 1, int unsigned x = 75214)
{
    int i;
    int unsigned y;
    int unsigned compteurDe[6];
    int unsigned compteurSomme[12];
    for (i = 0; i < 6; i++)
        compteurDe[i] = 0;

    for (i = 0; i < 12; i++)
        compteurSomme[i] = 0;

    for (i = 0; i < 1000; i++)
    {
        y = genererNombre(modulo, a, c, x);
        x = genererNombre(modulo, a, c, y);
        int m = (int)y * 6 / modulo;
        int n = (int)x * 6 / modulo;
        compteurDe[m]++;
        compteurDe[n]++;
        compteurSomme[n + m]++;
    }

    //Affichage du resultat
    // for (i = 0; i < 6; i++)
    //     printf("%d : %u\n", i, compteurDe[i]);
    for (i = 0; i < 12; i++)
        printf("%d : %u\n", i, compteurSomme[i]);
}

int main(/*int argc, char **argv[]*/)
{

    // for(int i = 0; i < argc; i++)
    // {
    //     printf("%f\n",*argv[i]);
    // }

    // int unsigned tab[3] = {(int unsigned)**argv - '0', (int unsigned)**argv - '0', (int unsigned)**argv - '0'};
    // printf("Iteration # [%c, %c, %c]\n", *argv[1], *argv[2], *argv[3]);
    // printf("Iteration # [%c, %c, %c]\n", *argv[1][0], *argv[2][1], *argv[3][2]);
    // printf("Iteration # [%u, %u, %u]\n", tab[0], tab[1], tab[2]);
    lancerDe();
    printf("Hello, world !");
    return 0;
}