#include <stdlib.h>
#include <stdio.h>
#include <time.h>

static void tri_bulle(int *tab, int tab_size)
{
    int i;
    int permut;

    do {
        permut = 0;
        for(i=0; i<tab_size-1; i++) {
            if (tab[i] > tab[i+1]) {
                int tmp = tab[i];
                tab[i] = tab[i+1];
                tab[i+1] = tmp;
                permut = 1;
            }
        }
    } while(permut);
}

static void display_tab(int *tab, int tab_size)
{
    int i;

    printf("table = [");
    for(i=0; i<tab_size; i++) {
        printf("%d ", tab[i]);
    }
    printf("]\n");
}

int main(int argc, char *argv[])
{
    int i;
    int *tab;
    int tab_size = (2 == argc) ? atoi(argv[1]) : 20;

    printf("Generate table with %d elements \n", tab_size);
    tab = (int *)malloc(sizeof(int)*tab_size);
    if (NULL == tab) {
        printf("Cannot allocate memory for table \n");
        return 0;
    }

    /* fill table */
    srand(time(NULL));
    for(i=0; i<tab_size; i++) {
        tab[i] = rand()%tab_size;
    }

    /* display table before the ordering */
    display_tab(tab, tab_size);

    tri_bulle(tab, tab_size);

    /* display table after the ordering */
    display_tab(tab, tab_size);


    free(tab);
    return 0;
}
