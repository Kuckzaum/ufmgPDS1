#include <stdio.h>
#include <math.h>

#define PI 3.14159
#define PESO_A 3
#define PESO_B 4
#define PESO_C 5



float media(float a, float b, float c) {
    return ((a+b+c)/3);
}

float mediaP(float a, float b, float c) {
    return ((PESO_A*a+PESO_B*b+PESO_C*c)/12);
}

float perimetro(float r) {
    return (2 * PI * r);
}

float areaC(float r) {
    return (PI * (r * r));
}

float areaT(float b,float c) {
    return ((b*c)/2);
}

float areaCX(float a, float b, float c) {
    return (2*a+2*b+2*c);
}

float volumeCX(float a, float b, float c) {
    return (a*b*c);
}

float areaCL(float r, float h) {
    return (2*(PI*(r*r))+2*(PI*r*h));
}

float volumeCL(float r, float h) {
    return (PI*(r*r)*h);
}

float hipotenusa(float b, float c) {
    return (sqrt(b*b+c*c));
}

float raizPositiva(float a, float b, float c) {
    if((-1*b+sqrt(b*b-4*a*c))/(2*a)>0){
        return ((-1*b+sqrt(b*b-4*a*c))/(2*a));
    }else{
        return ((-1*b-sqrt(b*b-4*a*c))/(2*a));
    }
}

int main() {
    float a, b, c, r, h;
    printf("Insira A, B, C, R e H: \n");
    scanf("%f%f%f%f%f", &a, &b, &c, &r, &h);
    printf("a) Media: %f\n", media(a,b,c));
    printf("b) Media ponderada: %f\n", mediaP(a,b,c));
    printf("c) Perimetro: %f\n", perimetro(r));
    printf("d) Area do circulo: %f\n", areaC(r));
    printf("e) Area do triangulo: %f\n", areaT(b,c));
    printf("f) Area da caixa: %f\n", areaCX(a,b,c));
    printf("g) Volume da caixa: %f\n", volumeCX(a,b,c));
    printf("h) Area do cilindro: %f\n", areaCL(r,h));
    printf("i) Volume do cilindro: %f\n", volumeCL(r,h));
    printf("j) Hipotenusa: %f\n", hipotenusa(b,c));
    printf("k) Raiz positiva: %f\n", raizPositiva(a,b,c));
    return 0;
}