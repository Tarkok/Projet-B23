#include "utility.h"

void attendre(float temps)
{
    clock_t terminer=clock()+(temps*CLOCKS_PER_SEC); // On calcule le moment o� l'attente devra s'arr�ter

    while(clock()<terminer);
}
