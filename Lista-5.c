#include <stdio.h>

int res(int a, int b), div(int a, int b), scan(), n, a, b, c, x, k, i;

long int fat(int n) {
    long int result = 1;
    for (i=1; i<=n; i++) result = result * i;
    return result;

    // if(n==0)return(1); 
    // return(n*fat(n-1));
}

int mdc(int a, int b) {
    if(a<b)mdc(b,a);
    int result = a;
    for (int i=b;;i--) if(res(b,i)==0 && res(a,i)==0)return i;
    return result;

    // i=a;
    // do {
    //     // printf("i.%d a.%d b.%d res(a,i).%d res(b,i).%d\n",i,a,b,res(a,i),res(b,i));    
    //     if(res(a,i)==0 && res(b,i)==0) {return i; break;};
    //     i=i--;  
    // }while(1);


    // if(res(a,b)==0) return(b);
    // return(mdc(b,a%b));
}   

int mdc3(int a, int b, int c) {
    return(mdc(mdc(a,b),c));
}

long int fib(int x) {
    long int result=0, lastEl=1;

    for(i=0;i!=x;i++) {
        result = result + lastEl;
        lastEl = result - lastEl;
    }

    return result;

    // while(i!=x) {
    //     printf("i.%d lastEl.%d result.%d x.%d\n", i, lastEl, result,x);
    //     result = result + lastEl;
    //     lastEl = result - lastEl;
    //     i++;
    // } 
    
    // if(x==1 || x==0)return(x);
    // return(fib(x-1)+fib(x-2));
}

const char* primo(int x) {
    for(int i=x-1;i!=0;i--) {
        if(i==1)return("primo");
        if(res(x,i)==0)return("nao primo");
    }
 
    // if(y==1)return("primo");
    // if(res(x,y)==0)return("nao primo");
    // primo(x,y-1);   
}
    
void decrescente(int x) {
    for(i=x-1; i>=1; i--) {
        if(i==1) {printf("1.\n");break;}
        printf("%d, ", i);
    }

    // x=x-1;
    // if(x==1) printf("1.\n"), x=0;
    // if(x==0) return(0);
    // printf("%i,", x);
    // return(decrescente(x));
}

int res(int a, int b) {
    i=a;
    do {
        if(i<b) return(i);
        i=i-b;
    } while(1); 

    // for(i=a;true;i++) if(res(i,a)==0 && res(i,b)==0) return i;

    // for(i=a;i>b;i-b) {
    //     printf("a.%d b.%d i.%d\n", a, b, i);
    //     if(i<b || (i-b)<0) return(i);
    // }

    // if(a==b)return(0);
    // if(div(a,b)==0)return(a);
    // return(res(a-b,b));
}

long int form(int n) {
    int soma = 0;
    for(i=1;i<=n;i++) soma = soma + (i*i);
    return soma;

    // if(n<i)return(0);
    // return((i*i)+form(n,i+1));
}

int mmc(int a, int b) {
    if(a<b)mmc(b,a);
    for(int i=a;;i++) if((res(i,a)==0) && (res(i,b)==0)) return i;
        
    // i=a;
    // do {
    //     printf("%d\n",i);
    //     if((res(i,a)==0) && (res(i,b)==0)) return i;
    //     i=i++;
    // } while(1);

    // int result = a;
    // for (i=1; i<res(a,b); i++) result = result - b;
    // return result;
    
    // if(res(a*i,b)==0)return(a*i);
    // return(mmc(a,b,i+1));
}

int div(int a, int b) {
    int result = 0;
    for(i=a;i-b>=0;i=i-b) result = result + 1;
    return result;
    
    // if(a<b)return(0);
    // return(1 + div(a-b,b));
}

// É uma forma "demorada" e um tanto quanto ineficiente mas foi
// a única coisa que consegui pensar. 
double sqrt(double n) {
    double s;
    for(double i=0;;i=i+0.001){
        s = i*i;
        if((n-s) <=0.001) return i;
    }

    // double i = 1;
    // while(1) {
    //     // printf("i.%lf n.%lf i*i.%lf\n",i,n, i*i);
    //     if(i*i == n-0.001||n + 0.001|| n) return i;
    //     i=i+0.001;
    // }
    

    // if(chute*chute <= n+0.001 && chute*chute >= n-0.001) return(chute);
    // if (chute*chute > n) return(sqrt(n, chute/2));
    // if (chute*chute < n) return(sqrt(n, (9/2)*chute/3));
}

int dig(int n) {
    int result = 0;
    for(int i=n;;i=div(i,10)) {
        result = result + res(i,10);
        if(res(i,10)==i)break;
    }
    return result;

    // i=n;
    // while(1) {
    //     result = result + res(i,10);
    //     i=i/10;
    //     if(i/10 == i) break;
    // }


    // if(o==0)return(o);
    // return(res(o,10)+dig(n,o/10));
}

long int exp(int k, int n) {
    long int result = k;
    for(i=1;i!=n;i++) result = result * k;
    return result;
    // if(n==0)return(1);
    // return(k*exp(k,n-1));
}

void crescente(int x) {
    for(i=1; i<=x; i++) {
        if (i==x) {printf("%d.\n", x); break;}
        printf("%d, ", i);
    }

    // if(y==x) {printf("%i.",x);return(0);}
    // printf("%i, ", y);
    // return(crescente(x,y+1));
}

void main() {
    // scan();
    double nf = (double)n;
    // printf("a) O fatorial de %d eh %ld\n", n, fat(n));
    // printf("2 elevado a n %d\n",exp(2,n));
    // printf("result = %d\n",fat(n)-(exp(2,n)));
    // printf("b) MDC(%d,%d) = %d\n", a, b, mdc(a,b));
    // printf("c) MDC(%d,%d,%d) = %d\n", a, b, c, mdc3(a,b,c));
    // printf("d) Na posicao %d da serie de Fibonacci esta %ld\n", n, fib(n));
    // printf("e) %d eh %s\n", x, primo(x));
    // printf("f) A decrescente de %d eh ", x); decrescente(x);
    // printf("g) O resto de %d/%d eh %d\n", a, b, res(a,b));
    // printf("h) O somatorio de i*i, i(1 a %d) eh %ld\n", n, form(n));
    // printf("i) MMC(%d,%d) = %d\n", a, b, mmc(a,b));    
    // printf("j) %d/%d = %d\n", a, b, div(a,b));
    // printf("l) A raiz quadrada de %.0f eh %.3lf\n", nf, sqrt(nf));
    // printf("m) A soma dos digitos de %d eh %d\n", n, dig(n));
    // printf("n) %d elevado a %d = %ld\n", k, n, exp(k,n));
    // printf("o) A crescente de %d eh ", x); crescente(x);
    printf("foi");
}

int scan() {
    printf("Insira N\n");
    printf("N:");
    scanf("%d", &n);
    // printf("Insira A\n");
    // printf("A:");
    // scanf("%d", &a);
    // printf("Insira B\n");
    // printf("B:");
    // scanf("%d", &b);
    // printf("Insira C\n");
    // printf("C:");
    // scanf("%d", &c);
    // printf("Insira X\n");
    // printf("X:");
    // scanf("%d", &x);
    // printf("Insira K\n");
    // printf("K:");
    // scanf("%d", &k);
    // printf("\n");
    // return(n,a,b,c,x,k);
}
