#include <cstdio>
#include <math.h>
#define NOMBRE_LANCE 5000000
/**
 * @return Génère un nombre entre 0 et modulo
 */
int unsigned genererNombre(long unsigned modulo, int a, int c, long unsigned x)
{
    return (a * x + c) % modulo;
}
/**
 * Lance deux dés, fait la somme et test le khi deux 
 */
void lancerDe(long unsigned modulo, int a, int c, long unsigned x)
{
    int i, N, q;
    int n, m;
    float temp;
    double khi = 0;
    long unsigned y;
    // int unsigned compteurDe[6];
    int unsigned compteurSomme[11];
    // for (i = 0; i < 6; i++)
    //     compteurDe[i] = 0;

    for (i = 0; i < 12; i++)
        compteurSomme[i] = 0;

    for (i = 0; i < NOMBRE_LANCE; i++)
    {
        y = genererNombre(modulo, a, c, x);
        x = genererNombre(modulo, a, c, y);
        m = (y * 6) / modulo;
        n = (x * 6) / modulo;
        // printf("y : %u -> %d  |  x : %u -> %d\n", y, m, x, n);

        // compteurDe[m]++;
        // compteurDe[n]++;
        compteurSomme[n + m]++;
    }

    compteurSomme[1] += compteurSomme[0];
    compteurSomme[9] += compteurSomme[10];

    //Affichage du resultat
    // for (i = 0; i < 6; i++)
    //     printf("%d : %u\n", i, compteurDe[i]);
    // for (i = 0; i < 11; i++)
    //     printf("%d : %u | %f\n", i + 2, compteurSomme[i], ((float)compteurSomme[i] * 2) / NOMBRE_LANCE);

    //Test du Khi-deux
    for (i = 1; i < 10; i++)
    {
        if (i == 1 || i == 9)
            N = NOMBRE_LANCE * 3 / 36;
        else if (i + 1 < 7)
            N = NOMBRE_LANCE * (i + 1) / 36;
        else
            N = NOMBRE_LANCE * (12 - (i + 1)) / 36;
        q = compteurSomme[i] - N;
        temp = pow(q, 2) / N;
        printf("%d : %d\t - %d\t%f\n", i + 2, N, compteurSomme[i], temp);
        khi += temp;
    }
    printf("khi-deux = %f\nTest khi-deux ", khi);
    if (khi < 15.51)
        printf("reussi !\n");
    else
        printf("echoue !\n");
}
