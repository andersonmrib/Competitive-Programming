#include <stdio.h>

int main() {

    float a, b, c;
    float aver;

    scanf ("%f %f %f", &a, &b, &c);

    aver = (a*2 + b*3 + c*5)/10;

    printf ("MEDIA = %.1f\n", aver);

    return 0;
}
