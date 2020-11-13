// Para a execução desse arquivo são necessários outros 2 arquivos no mesmo diretório, são eles:
// - naturais.txt
// - reais.txt
// Sem os mesmos é impossível que o programa funcione

#include <stdio.h>

int num;

int primo(int x) {
    int i = x - 1;
    for(i;;i--) {
        if(x==1 || i==1)return (1);
        if(x%i==0)return(0);
    }
}

// Questão 1
void q1() {
    int i = 0, s = 0, n;
    printf("Questao 1\n\n");
    printf("Insira n para a questao 1:\n");
    scanf("%d",&n);
    FILE* p=fopen("Q1-primos.txt","w+t");
    FILE* f=fopen("Q1-naturais.txt","w+t");
    fscanf(f, "%d\n", &num);

    // Para controlar quantos números primos foram escritos é criada uma variável de controle
    // 'i' que a cada vez que é adicionado um número ao arquivo primos.txt i é incrementado,
    // dessa forma quando i chegar a quantidade de n isso significara que os n números pedidos
    // estão lá, parando assim while loop. Ao mesmo tempo está sendo gerado pela função createN
    // vai criando os números naturais que serão usados para a formação do arquivo de primos.
    while(i!=n) {
        s++;
        createN(s);
        if(primo(num)) {fprintf(p,"%d\n", num);i++;}
        fscanf(f, "%d\n", &num);
    }
    fclose(p);
    fclose(f);
    printf("Os %d primeiros numeros primos estao no arquivo Q1-primos.txt\n\n", n);
}

// Aqui são gerados os números naturais de forma crescente para o cálculo da questão 1.
void createN(int s) {
    if(s==1) {
        FILE* f=fopen("Q1-naturais.txt","w+t");
        fprintf(f,"%d\n", s);
        fclose(f);
    } else { 
        FILE* f=fopen("Q1-naturais.txt","a");
        fprintf(f,"%d\n", s);
        fclose(f);
    }
}

// Questão 2
void q2() {
    printf("Questao 2\n\n");
    FILE *f=fopen("naturais.txt","r");
    if(f==NULL) {
        printf("Nao consegui abrir o arquivo naturais.txt, eh preciso que voce adicione um arquivo de nome 'naturais.txt' com\nnumeros inteiros no padrao, 1 por linha, ao diretorio do programa para que o mesmo prossiga execucao.\nAo realizar o procedimento solicitado por favor re-execute o programa.\n");
        return(1);
    }
    FILE *p=fopen("Q2-primos.txt","w+t");

    do {
        fscanf(f,"%d",&num);
        if (primo(num)) fprintf(p,"%d - Primo\n", num);
        else fprintf(p,"%d - Não primo\n", num);
    } while (!feof(f));
    fclose(f);
    fclose(p);
    printf("O arquivo com os respectivos numeros e suas propriedades, isto eh, primo ou nao primo, estao no arquivo Q2-primos.txt.\n\n");
}

// Questão 3
void q3() {
    printf("Questao 3\n\n");
    FILE *f=fopen("naturais.txt","r");
    if(f==NULL) {
        printf("Nao consegui abrir o arquivo naturais.txt, eh preciso que voce adicione um arquivo de nome 'naturais.txt' com\nnumeros inteiros no padrao, 1 por linha, ao diretorio do programa para que o mesmo prossiga execucao.\nAo realizar o procedimento solicitado por favor re-execute o programa.\n");
        return(1);
    }
    FILE *p=fopen("primos.txt","w+t");
    FILE *o=fopen("outros.txt","w+t");

    do {
        fscanf(f,"%d",&num);
        if (primo(num)) fprintf(p,"%d\n", num);
        else if(feof(f))return 1;
        else fprintf(o,"%d\n", num);
    } while (!feof(f));
    fclose(f);
    fclose(p);
    fclose(o);
    printf("Os numeros primos presentes no intervalo do arquivo que voce colocou no diretorio se encontram no arquivo 'primos.txt'\nenquanto os outros numeros nao primos se encontram no arquivo 'outros.txt'.\n\n");
}

// Questão 4
void q4() {
    printf("Questao 4\n\n");
    FILE*f=fopen("reais.txt","r");
    if(f==NULL) {
        printf("Nao consegui abrir o arquivo reais.txt, eh preciso que voce adicione um arquivo de nome 'reais.txt' com numeros\nreais ex: 1.123456... , no padrao, 1 por linha, ao diretorio do programa para que o mesmo prossiga execucao.\nAo realizar o procedimento solicitado por favor re-execute o programa.\n");
        return(1);
    }
    int s = 1;
    do {
        fscanf(f,"%f",&num);
        resultQ4(num, s);    
        s++;
    } while (!feof(f));
    fclose(f);
    printf("O arquivo com os resultados da aplicacao da funcao f(x)=x^2-5x+1 sobre os numeros em 'reais.txt' estao no arquivo\n'Q4-resultado.txt'.\n\n");
}

void resultQ4(float x, int s) {
    if(s==1) {
        FILE*p=fopen("Q4-resultado.txt","w+t"); 
        fprintf(p,"f(x) = x²-5x+1:\n");
        fprintf(p,"f(%.2f) = %f\n", x,(x*x)-(5*x)+1);
        fclose(p);
    } else {
        FILE*p=fopen("Q4-resultado.txt","a"); 
        fprintf(p,"f(%.2f) = %f\n", x,(x*x)-(5*x)+1);
        fclose(p);
    }
}

// Questão 5
void q5() {
    printf("Questao 5\n\n");
    FILE*f=fopen("reais.txt","r");
    if(f==NULL) {
        printf("Nao consegui abrir o arquivo reais.txt, eh preciso que voce adicione um arquivo de nome 'reais.txt' com numeros\nreais ex: 1.123456... , no padrao, 1 por linha, ao diretorio do programa para que o mesmo prossiga execucao.\nAo realizar o procedimento solicitado por favor re-execute o programa.\n");
        return(1);
    }
    int s = 1,a,b,c,d;
    printf("Insira a,b, c e d respectivamente para calculo da funcao:\n");
    scanf("%d%d%d%d",&a,&b,&c,&d);
    do {
        fscanf(f,"%f",&num);
        resultQ5(num, s,a,b,c,d);    
        s++;
    } while (!feof(f));
    fclose(f);
    printf("O arquivo com os resultados da aplicacao da funcao f(x)=a(x^2)+b(x^2)+cx+d sobre os numeros em 'reais.txt' estao no\narquivo 'Q5-resultado.txt'.\n");
}

void resultQ5(float x, int s, int a, int b, int c, int d) {
    if(s==1) {
        FILE*p=fopen("Q5-resultado.txt","w+t"); 
        fprintf(p,"f(x) = ax² + bx² cx + d:\n");
        fprintf(p,"Sendo\nA = %d\nB = %d\nC = %d\nD = %d\n\n",a,b,c,d);
        fprintf(p,"f(%.2f) = %f\n", x,(a*(x*x))+(b*(x*x))+(c*x)+d);
        fclose(p);
    } else {
        FILE*p=fopen("Q5-resultado.txt","a"); 
        fprintf(p,"f(%.2f) = %f\n", x,(a*(x*x))+(b*(x*x))+(c*x)+d);
        fclose(p);
    }
}


int main() {
    q1();
    q2();
    q3();
    q4();
    q5();
    return 0;
}