#include <stdio.h>

// Questão 2
float media_matriz(int n, float mat[][100]) {
    float total=0;
    for(int i=0;i<n;i++) {
         for(int j=0;j<n;j++) {
             total += mat[i][j];
        }   
    }
    return(total/(n*n));
}

// Questão 3
void identidade(int n, float A[][100]) {
    for(int i=0;i<n;i++) {
         for(int j=0;j<n;j++) {
            if(i==j)A[i][j]=1;
            else A[i][j]=0;
        }   
    }
}

// Questão 4 
void transposta(int n, float A[][100], float T[][100]) {
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            T[i][j]=A[j][i];
        }
    }
}

// Questao 5
int simetrica(int n, float A[][100]) {
    float Atransp[100][100];
    int value;

    // Uma matriz é simétrica se ela e sua tranposta são iguais,
    // Nesse caso eu fiz a transposta pra posteiormente compará=la
    // com a normal.
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            Atransp[i][j]=A[j][i];
        }
    }

    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(Atransp[i][j]==A[i][j] && value != 0) value = 1;
            else value = 0;
        }
    }
    return value;
}

// Questao 6
void soma_matriz(int n, float A[][100],float B[][100],float S[][100]) {
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            S[i][j] = A[i][j]+B[i][j];
        }
    }
}

// Questao 7
void mult_matriz(int n, float A[][100],float B[][100],float P[][100]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                P[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

int main() {
    // Questão 1
    float matriz[100][100];
    int linha, coluna;

    FILE* f = fopen("matriz.txt","r");
    if(f == NULL) {
        printf("Error, make sure 'matriz.txt' is in the program directory.");
        return 1;
    }

    fscanf(f,"%d %d", &linha, &coluna);
    for(int i=0;i<linha;i++){
        for(int j=0;j<coluna;j++){
            fscanf(f,"%f", &matriz[i][j]);
        }
    }
    fclose(f);

    // Matrizes e n assumem os valores para efeito de teste. 
    float A[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%.0f", A[i][j]);
        }
        printf("\n");
    }
    float B[100][100]={{1,2,3},{4,5,6},{7,8,9}}; 
    int n = 3;

    // 2
    float mat[100][100]={{1,2,3},{4,5,6},{7,8,9}};
    printf("A media dos elementos da matriz 'mat' eh %f\n",media_matriz(n, mat));

    // 3
    identidade(n,A);

    // 4
    float T[100][100];
    transposta(n,A,T);

    // 5
    printf("A matriz A eh ");
    printf(simetrica(n,A) ? "simetrica\n":"assimetrica\n");

    // 6
    float S[100][100]; 
    soma_matriz(n,A,B,S);

    // 7
    float P[100][100];
    mult_matriz(n,A,B,P);

    return 0;
}




// Teste 
/*

int main() {
    int x, y;
    printf("Insira os valores de x e y para criacao de uma matriz X x Y:\n");
    scanf("%d%d",&x,&y);
    int teste[x][y];
    int teste2[y][x];
    printf("Matris %d x %d criada\n",x,y);
    for(int i=0;i<x;i++){
        for(int s=0;s<y;s++){
            scanf("%d",&teste[i][s]);
        }
    }
    printf("Valores atribuidos, a matriz resultado foi:\n");
    for(int j=0;j<x;j++){
        for(int k=0;k<y;k++){
            printf("%d ", teste[j][k]);
        }
        printf("\n");
    }
    printf("\n");

    // printf("%d\n", teste[0][12]);
    // Teste
    // Linha depois colunam bem mais eficiente.
    int vendas[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    for(int j=0;j<3;j++){
        for(int k=0;k<3;k++){
            printf("%d ", vendas[j][k]);
        }
        printf("\n");
    }
    printf("\n");

    // Coluna depois linha, bem menos eficiente.
    for(int j=0;j<3;j++){
        for(int k=0;k<3;k++){
            printf("%d ", vendas[k][j]);
        }
        printf("\n");
    }
    return 0;
}

// int raiz[4][4] = {{1,3,2,7},{2,3,1,2},{6,4,2,3},{5,8,9,3}};
// for(int i=0;i<4;i++) {
//     for(int s=0;s<4;s++){
//         printf("%d ", raiz[i][s]);
//     }
//     printf("\n");
// }

*/
