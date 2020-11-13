#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846


// 1
struct Ponto {
    float x;
    float y;
    
    float distancia(Ponto& p);
    void atribuir(float a,float b);
    void imprime();
};

// 2
float Ponto::distancia(Ponto& p) {
    return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
}

// 3
void Ponto::atribuir(float a,float b) {
    x=a;
    y=b;
}

// ============================================================= //

// 4
struct Triangulo {
    Ponto p1;
    Ponto p2;
    Ponto p3;

    float perimetro();
    float area();
    bool equilatero();
    bool semelhante(Triangulo& t);
    float num(Triangulo& t);
};

// 5
float Triangulo::perimetro() {
    return(p1.distancia(p2)+p2.distancia(p3)+p3.distancia(p1));
}

// 6
float Triangulo::area() {
    int mult = perimetro()/2;
    return(sqrt(mult*(mult-p1.distancia(p2))*(mult-p2.distancia(p3))*(mult-p3.distancia(p1))));
}

// 7
bool Triangulo::equilatero() {
    if(p1.distancia(p2) == p1.distancia(p3) && p3.distancia(p2) == p1.distancia(p2)) return true;
    else return false;
}

// 8
bool Triangulo::semelhante(Triangulo& t) {
    float i = perimetro()/t.perimetro();
    if(i*t.p1.distancia(t.p2) == p1.distancia(p2) && i*(t.p1.distancia(t.p3)) == p1.distancia(p3) && i*t.p3.distancia(t.p2) == p3.distancia(p2))return true;
    else return false;
}

float Triangulo::num(Triangulo& t) {
    return(t.perimetro()/perimetro());
}

// ============================================================= //

// 9
struct Retangulo{
    Ponto p1;
    Ponto p2;
    Ponto p3;
    Ponto p4;

    float perimetro();
    float area();
    bool quadrado();
    bool valido();
};

bool Retangulo::valido() {
    if((p1.x == p4.x && p1.y == p2.y && p2.x == p3.x && p3.y == p4.y)|| (p1.x == p2.x && p1.y == p4.y && p4.x == p3.x && p3.y == p2.y)) return true;
    else {
        printf("Isso nao eh um quadrado\n");
        exit(1);
    }
}

// 10
float Retangulo::perimetro() {
    return(p1.distancia(p2)+p2.distancia(p3)+p3.distancia(p4)+p4.distancia(p1));
}

// 11
float Retangulo::area() {
    return(p1.distancia(p2)*p1.distancia(p4));
}

// 12
bool Retangulo::quadrado() {
    if(p1.distancia(p2) == p2.distancia(p3) && p2.distancia(p3) == p3.distancia(p4) && p3.distancia(p4) == p4.distancia(p1))return true;
    else return false;
}

// 13
struct Circunferencia {
    Ponto center;
    float raio;

    float perimetro();
    float area();
    bool contem(Ponto& p);
    bool contem(Triangulo& t);
    bool contem(Retangulo& r);
    bool pertence(Ponto& p);
    bool circunscrita(Triangulo& t);
    bool circunscrita(Retangulo& r);
};

// 14
float Circunferencia::perimetro() {
    return(2*PI*raio);
}

// 15
float Circunferencia::area() {
    return(PI*(raio*raio));
}

// 16
bool Circunferencia::contem(Ponto& p) {
    if(p.distancia(center)<=raio)return true;
    else false;
}

// 17
bool Circunferencia::contem(Triangulo& t) {
    if(contem(t.p1) && contem(t.p2) && contem(t.p3)) return true;
    else return false;
}

// 18
bool Circunferencia::contem(Retangulo& r){
    if(contem(r.p1) && contem(r.p2) && contem(r.p3) && contem(r.p4)) return true;
    else return false;
}

// 19
bool Circunferencia::pertence(Ponto& p){
    if(p.distancia(center)==raio)return true;
    else return false;
}

// 20
bool Circunferencia::circunscrita(Triangulo& t) {
    if(t.p1.distancia(center) == raio && t.p1.distancia(center) == raio && t.p3.distancia(center) == raio)return true;
    else return false;
}

// 21
bool Circunferencia::circunscrita(Retangulo& r) {
    if(r.p1.distancia(center) == raio && r.p1.distancia(center) == raio && r.p3.distancia(center) == raio && r.p4.distancia(center) == raio)return true;
    else return false;
}

int main() {
    printf("\nParte 1 - Pontos\n\n");
    Ponto p1;
    Ponto p2;
    float a,b;
    p1.atribuir(0,0);
    printf("Insira os valores de X e Y para o calculo da distancia a partir do ponto(0,0):\n");
    scanf("%f%f",&a,&b);
    p2.atribuir(a,b);
    printf("A distancia entre pontos p1(0,0) e p2(%.0f,%.0f) eh %f\n",a,b,p1.distancia(p2));

    printf("\nParte 2 - Triangulos\n\n");
    Triangulo t;
    Triangulo t1;
    t.p1.atribuir(0,4);
    t.p2.atribuir(3,0);
    t.p3.atribuir(0,0);
    // t1 criado para efeito de teste e comparação na função semelhança
    t1.p1.atribuir(0,2);
    t1.p2.atribuir(1.5,0);
    t1.p3.atribuir(0,0);
    printf("O perimetro do triangulo T eh %f\n",t.perimetro());
    printf("A area do triangulo T eh %f\n", t.area());
    printf(t.equilatero()?"O triangulo T eh equilátero.\n":"O triangulo T nao eh equilatero.\n");
    t.semelhante(t1)?printf("O triangulo 't1' eh semelhante a t e eh exatamente %.2f x t.\n",t.num(t1)):printf("O triangulo 't1' nao eh semelhante a t.\n");


    printf("\nParte 3 - Retangulos\n\n");
    Retangulo r;
    r.p1.atribuir(0,0);
    r.p2.atribuir(1,0);
    r.p3.atribuir(1,1);
    r.p4.atribuir(0,1);
    // Essa função checa se o retangulo em questão é um retangulo no sentido horizonteal
    r.valido();
    printf("O perimetro do retangulo eh %f\n",r.perimetro());
    printf("A area do retangulo R eh %f\n",r.area());
    printf(r.quadrado()?"O retangulo R eh tambem um quadrado\n":"O retangulo R nao eh um quadrado\n");

    printf("\nParte 4 - Circunferencia\n\n");
    Circunferencia c;
    printf("Insira o raio: ");
    scanf("%f",&c.raio);
    Ponto pt;
    float pa,pb;
    printf("Insira (x,y) para usarmos esse ponto como teste:\n");
    scanf("%f %f",&pa,&pb);
    pt.atribuir(pa,pb);
    // Para efeito de teste o centrio da circunferência é atribuido ao ponto (0,0)
    c.center.atribuir(0,0);
    printf("O perimetro da circunferencia C eh %f\n",c.perimetro());
    printf("A area da circunferencia C eh %f\n",c.area());
    printf(c.contem(pt)?"O ponto esta contido na circunferencia.\n":"O ponto nao esta contido na circunferencia.\n");
    printf(c.contem(t)?"O triangulo esta contido na circunferencia.\n":"O triangulo nao esta contido na circunferencia.\n");
    printf(c.contem(r)?"O retangulo esta contido na circunferencia.\n":"O retangulo nao esta contido na circunferencia.\n");
    printf(c.pertence(pt)?"O ponto p esta contido na reta tracada pelo raio.\n":"O ponto p nao esta contido na reta tracada pelo raio.\n");
    printf(c.circunscrita(t)?"A circunferencia eh circunscrita ao triangulo t.\n":"A circunferencia nao eh circunscrita ao triangulo t.\n");
    printf(c.circunscrita(r)?"A circunferencia eh circunscrita ao retangulo r.\n":"A circunferencia nao eh circunscrita ao retangulo r.\n");

    return 0;
}