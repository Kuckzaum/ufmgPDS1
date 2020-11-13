#include <stdio.h>
#include <stdbool.h>

int res(int a, int b), div(int a, int b), scan(), n, a, b, c, x, k, i = 1;

long int fat(long int n) {
    if(n==0)return(1); 
    return(n*fat(n-1));
}

int mdc(int a, int b) {
    if(res(a,b)==0) return(b);
    return(mdc(b,a%b));
}   

int mdc3(int a, int b, int c) {
    return(mdc(mdc(a,b),c));
}

long int fib(int x) {
    if(x==1 || x==0)return(x);
    return(fib(x-1)+fib(x-2));
}

bool primo(int x, int y) {
    if(y==1)return true;
    if(res(x,y)==0 && x!=y)return false;
    primo(x,y-1);   
}
    
float decrescente(int x) {
    x=x-1;
    if(x==1) printf("1.\n"), x=0;
    if(x==0) return(0);
    printf("%i,", x);
    return(decrescente(x));
}

int res(int a, int b) {
    if(a==b)return(0);
    if(div(a,b)==0)return(a);
    return(res(a-b,b));
}

long int form(int n, int i) {
    if(n<i)return(0);
    return((i*i)+form(n,i+1));
}

int mmc(int a, int b, int i) {
    if(res(a*i,b)==0)return(a*i);
    return(mmc(a,b,i+1));
}

int div(int a, int b) {
    if(a<b)return(0);
    return(1 + div(a-b,b));
}

float sqrt(float n, float chute) {
    if(chute*chute <= n+0.001 && chute*chute >= n-0.001) return(chute);
    if (chute*chute > n) return(sqrt(n, chute/2));
    if (chute*chute < n) return(sqrt(n, (9/2)*chute/3));
}

int dig(int n, int o) {
    if(o==0)return(o);
    return(res(o,10)+dig(n,o/10));
}

long int exp(int k, int n) {
    if(n==0)return(1);
    return(k*exp(k,n-1));
}

int crescente(int x, int y) {
    if(y==x) {printf("%i.",x);return(0);}
    printf("%i, ", y);
    return(crescente(x,y+1));
}

int main() {
    // scan();
    // float nf=(float)n;
    // printf("a) O fatorial de %d eh %ld\n", n, fat(n));
    // printf("b) MDC(%d,%d)= %d\n", a, b, mdc(a,b));
    // printf("c) MDC(%d,%d,%d)= %d\n", a, b, c, mdc3(a,b,c));
    // printf("d) Na posicao %d da serie de Fibonacci esta %ld\n", n, fib(n));
    int x = 8;
    int y = x-1;
    printf(primo(x,x)?"T":"F");
    // printf("f) A decrescente de %d eh ", x); decrescente(x);
    // printf("g) O resto de %d/%d eh %d\n", a, b, res(a,b));
    // printf("h) O somatorio de i*i, i(1 a %d) eh %ld\n", n, form(n,i));
    // printf("i) MMC(%d,%d)= %d\n", a, b, mmc(a,b,i));    
    // printf("j) %d/%d = %d\n", a, b, div(a,b));
    // printf("l) A raiz quadrada de %.0f eh %.3f\n", nf, sqrt(nf, nf/2));
    // printf("m) A soma dos digitos de %d eh %d\n", n, dig(n, n));
    // printf("n) %d elevado a %d = %ld\n", k, n, exp(k,n));
    // printf("o) A crescente de %d eh ",x); crescente(x,i);
    return 0;
}

int scan() {
    printf("Insira N\n");
    printf("N:");
    scanf("%d", &n);
    printf("Insira A\n");
    printf("A:");
    scanf("%d", &a);
    printf("Insira B\n");
    printf("B:");
    scanf("%d", &b);
    printf("Insira C\n");
    printf("C:");
    scanf("%d", &c);
    printf("Insira X\n");
    printf("X:");
    scanf("%d", &x);
    printf("Insira K\n");
    printf("K:");
    scanf("%d", &k);
    printf("\n");
    return(n,a,b,c,x,k,i);
}

//  Sugestão de um colega de sala;
//  Não dá certo porquê o que acontece é basicamente o segundo número(b) é diminuido 
//  até que ele seja suficiente para dividir a, o problema nesse caso é o fato de que
//  dessa forma não importa o valor de b mas apenas o de a, tendo em vista o teste que fiz
//  com a=58 e b=27, 27 é diminuido até dividir a, e ai se encontra o resultado, porém
//  o resultado falha desse jeito, já que 27 é diminuido e passa primeiro pelo 2, e como 58
//  é divisível por dois, conclui-se equivocadamente que 2 é o MDC enquanto na verdade deveria
//  se 1.

// int mdc(int a, int b) {
//     printf("%i %i\n", a, b);
//     if (a%b == 0) return (b);
//     b = b-1;
//     mdc(a,b);
// }