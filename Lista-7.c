#include <stdio.h>

float q1(float *arr1) {
    printf("Questao 1\n\n");
    FILE* f = fopen("exercicio1.txt","r");
    if(f==NULL) {
        printf("Nao consegui achar o arquivo, favor verificar se o arquivo 'exercicio1.txt' esta no diretorio.");
        return 1;
    }
    for(int i=0;!feof(f);i++) fscanf(f, "%f",&arr1[i]);
    fclose(f);
    printf("Os valores presentes em 'exercicio1.txt' foram armazenados no vetor 'arr1'.\n\n");
}

float q2(float *v, int n) {
    int total = 0;
    for(int i=0;i<n;i++)total = total + v[i];
    return ((float)total/n);
}

float q3(float* v, int n) {
    float s,result = 0;
    for(int i=0;i!=n;i++) {
        s = ((v[i]-q2(v,n))*(v[i]-q2(v,n)));
        result = result + s;
    }
    return result/(n-1);
}

float q4(float *v, int n) {
    float biggest = 0;
    for(int i=0;i!=n;i++){
        if(v[i]>biggest)biggest = v[i];
    }
    return biggest;
}

float q5(float *v, int n) {
    float lowest = v[0];
    for(int i=0;i!=n;i++){
        if(v[i]<lowest)lowest = v[i];
    }
    return lowest;
}

float q6(float *v,float *u,int n) {
    float s,result = 0;
    for(int i=0;i!=n;i++) {
        s = v[i]*u[i];
        result = result + s;
    }
    return result;
}

int main() {
    int n,t;
    float arr1[1000],v[1000],u[1000];
    q1(arr1);
    printf("Questao 2\nInsira n: ");
    scanf("%d",&n);
    t=n;
    // Gerei os vetores v e w a partir de n apenas para efeito de testes
    // Sendo um formado em ordem crescente e outro de forma descrescente.
    for(int i=0;i<=n;i++) v[i]=i+1;
    for(int i=0;i<=n;i++,t--) u[i]=t;

    printf("A media dos primeiros %d numeros de v eh %.3f\n\n",n, q2(v,n));
    printf("Questao 3\nA variancia do vetor v eh %.3f\n\n",q3(v,n));
    printf("Questao 4\nO maior numero no vetor v eh %.3f\n\n",q4(v,n));
    printf("Questao 5\nO menor numero no vetor v eh %.3f\n\n",q5(v,n));
    printf("Questao 6\nO menor numero no vetor v eh %.3f\n\n",q6(v,u,n));
    return 0;
}
   
    // while (!feof(f)) {
    //     i++;
    //     fscanf(f, "%d",&arr1[i]);
    // }
    // float notas[55];
    // for(int i=0;i<55;i++){
    //     printf("Digite a nota de aluno %d\n",i);
    //     scanf("%f",&notas[i]);
    // }

    // for(int i=0;i<55;i++) {
    //     printf("%f\n",notas[i]);
    // }    
