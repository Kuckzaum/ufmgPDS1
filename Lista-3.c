#include <stdio.h>
#include <math.h>

int max(int a, int b, int c) {
    if(a>b && a>c) return a;
    else if(b>c) return b;
    else return c;
}

int min(int a, int b, int c) {
    if(a<b && a<c) return a;
    else if(b<c) return b;
    else return c;
}

const char* par(int x) {
    if (x % 2 == 0) return ("par");
    return ("impar");
}

// Essa foi a forma mais precisa que encontrei de cobrir todas as possibilidades de combinações x,y,z.
const char* dentro(float x, float y, float z) {
    if(x<z && x>y || x>z && x<y || x==y && y<z || x==z && z>y || x==y && y==z) return ("dentro");
    else return ("fora");
}

const char* fora(float x, float y, float z) {
    if(!(x<z && x>y || x>z && x<y || x==y && y<z || x==z && z>y || x==y && y==z)) return ("fora");
    else return ("dentro");
}
// ---------------------------------------------------------------- //

const char* bissexto(int year) {
    if((year % 400 == 0)||(year % 4 == 0 && year % 100 != 0)) return ("bissexto"); 
    else return ("normal");
}

int main() {
    int a,b,c;
    printf("1. Escreva a,b e c respectivamente:\n");
    scanf("%d%d%d", &a, &b, &c);
    printf("a) Max(%d,%d,%d) = %d\n", a, b, c, max(a,b,c));
    printf("b) Min(%d,%d,%d) = %d\n\n", a, b, c, min(a,b,c));

    int x,y,z;
    printf("2. Escreva x,y e z respectivamente:\n");
    scanf("%d%d%d", &x, &y, &z);
    printf("a) %d eh %s.\n", x, par(x));
    printf("b) %d esta %s do intervalo(%d,%d).\n", x, dentro(x,y,z), y, z);
    printf("c) %d esta %s do intervalo(%d,%d).\n\n", x, fora(x,y,z), y, z);

    int year;
    printf("3. Insira um ano:\n");
    scanf("%d", &year);
    printf("%d eh um ano %s.\n",year, bissexto(year));
    
   return 0;
}