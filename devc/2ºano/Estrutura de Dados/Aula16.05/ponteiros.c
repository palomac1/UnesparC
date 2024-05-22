/* não inicializado:
x 
y = 0
p aponta para y

inicializado:
x = 0 (valor de *p que é y)
x = 4
y = 1 ((*p)++)
x = 3 (--x)
y = 4 ((*p) += x)*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int x, y, *p;
    y = 0;

    p = &y;
    x = *p;
    x = 4;
    (*p)++;
    --x;
    (*p) += x;

    printf("x=%d y=%d *p=%d", x, y, *p);

    return 0;
}
