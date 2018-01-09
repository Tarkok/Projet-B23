#include "utility.h"

void attendre(float temps)
{
    clock_t terminer=clock()+(temps*CLOCKS_PER_SEC); // On calcule le moment où l'attente devra s'arrêter

    while(clock()<terminer);
}
