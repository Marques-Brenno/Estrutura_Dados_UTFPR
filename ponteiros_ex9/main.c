#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y){
    int z = *x;
    *x = *y;
    *y = z;

    printf("\n x = %i, y = %i", *x, *y);
}

int main()
{
    int x = 6, y = 12;

    printf("\n x = %i, y = %i", x, y);
    swap(&x, &y);

    return 0;
}
