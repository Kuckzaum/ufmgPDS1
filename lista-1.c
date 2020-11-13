// Funções log(),sin(),cos(),sqrt() são funções da biblioteca math.h
#include <stdio.h>
#include <math.h>

//  1 
void Q1() {
    printf("Questao 1:\n"); 
    printf("a) 3+4 = %d\n", 3+4);
    printf("b) 7/4 = %d\n", 7/4);
    printf("c) 3^2 = %d\n", 3*3);
    printf("d) (5*3)*(2*1) = %d\n", (5*3)*(2*1));
    printf("e) 2*5-2 = %d\n", 2*5-2);
    printf("f) 2+2*5  = %d\n", 2+2*5);
    printf("g) (2+5)*3 = %d\n", (2+5)*3);
    printf("h) sin(3.141502) = %f\n", sin(3.141502));
    printf("i) sqrt(5) = %f\n", sqrt(5));
    printf("j) 1+2+3 = %d\n", 1+2+3);
    printf("k) 1*2*3 = %d\n", 1*2*3);
    printf("l) (1+2+3)/3.0 = %1.0f\n", (1+2+3)/3.0);
    printf("m) (2+4)*(3-1) = %d\n", (2+4)*(3-1));
    printf("n) (9/3)+(3*2) = %d\n", (9/3)+(3*2));
    printf("o) sin(4.5)+cos(3.7) = %f\n", sin(4.5)+cos(3.7));
    printf("p) log(2.3)-log(3.1) = %f\n", log(2.3)-log(3.1));
    printf("q) log (7)*(log(7)*log(7)-cos(log(7))) = %f\n", log(7)+(log(7)*log(7)-cos(log(7))));
    printf("r) (10.3+8.4)/50.3-(10.3+8.4) = %f\n", (10.3+8.4)/50.3-(10.3+8.4));
    printf("s) (cos(0.8)+sin(0.8))*(cos(0.8)-sin(0.8)) = %f\n\n", (cos(0.8)+sin(0.8))*(cos(0.8)-sin(0.8)));
}

// 2
void Q2() {
    float a, b, c, d;
    printf("Questao 2: \n");
    printf("Digite A, B, C e D Respectivamente: \n");
    scanf("%f%f%f%f", &a, &b, &c, &d);
    printf("A = %1.3f\n", a);
    printf("B = %1.3f\n", b );
    printf("C = %1.3f\n", c );
    printf("D = %1.3f\n\n", d );
    printf("a) A + B = %1.3f\n", a+b);
    printf("b) A/C = %1.3f\n", a/c);
    printf("c) A^2 = %1.3f\n", a*a);
    printf("d) B*C = %1.3f\n", b*c);
    printf("e) A*B-C = %1.3f\n", a*b-c);
    printf("f) A+B*C = %1.3f\n", a+b*c);
    printf("g) (A+B)*C = %1.3f\n", (a+b)*c);
    printf("h) sin(A) = %1.3f\n", sin(a));
    printf("i) sqrt(B) = %1.3f\n", sqrt(b));
    printf("j) A+B+C = %1.3f\n", a+b+c);
    printf("k) A*B*C = %1.3f\n", a*b*c);
    printf("l) (A+B+C)/D = %1.3f\n", (a+b+c)/d);
    printf("m) (A+B)*(A-D) = %1.3f\n", (a+b)*(a-d));
    printf("n) (B/C)+(A*D) = %1.3f\n", (b/c)+(a*d));
    printf("o) sin(B)+cos(C) = %1.3f\n", sin(b)+cos(c));
    printf("p) log(A)-log(C) = %1.3f\n", log(a)-log(c));
    printf("q) log(A)+(log(B)*log(D)-cos(log(C))) = %1.3f\n", log(a)+(log(b)*log(d)-cos(log(c))));
    printf("r) (B+A)/C-(D+A) = %1.3f\n", (b+a)/c-(d+a));
    printf("s) (cos(D)+sin(C))*(cos(B)-sin(A)) = %1.3f\n\n", (cos(d)+sin(c))*(cos(b)-sin(a)));
}

// 3
void Q3() {
    float a, b, c;
    printf("Questao 3: \n");
    printf("Digite A, B e C Respectivamente: \n");
    scanf("%f%f%f", &a, &b, &c);
    printf("A = %1.3f\n", a);
    printf("B = %1.3f\n", b );
    printf("C = %1.3f\n\n", c );
    printf("a) A media entre A,B e C eh: %1.3f\n", (a+b+c)/3);
    printf("b) A media ponderada entre A,B e C eh: %1.3f\n", (3*a+4*b+5*c)/12);
    printf("c) O perimetro de raio A eh: %1.3f\n", 2*3.14*a);
    printf("d) A area do circulo de A eh: %1.3f\n", 3.14*a*a);
    printf("e) A area do triangulo de base B e altura C eh: %1.3f\n", (b*c)/2);
    printf("f) A hipotenusa do triangulo retangulo de lados B, C e ? eh: %1.3f\n", sqrt(b*b+c*c));
    printf("g) As raizes possiveis da equacao sao: %1.3f %1.3f\n", (-1*b+sqrt(b*b-4*a*c))/(2*a),(-1*b-sqrt(b*b-4*a*c))/(2*a));
}

int main() {
    Q1();
    Q2();
    Q3();
    return 0;
}
