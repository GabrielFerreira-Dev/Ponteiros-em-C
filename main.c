#include <stdio.h>
#include <locale.h>

float **alocarMatriz(int N, int M)
{

    float **matriz = (float **)malloc(N * sizeof(float *));
    for (int i = 0; i < N; i++)
    {
        matriz[i] = (float *)malloc(M * sizeof(float));
    }
    return matriz;
}

int main()
{
    int N, M, N_B, M_B;

    printf("Insira o numero de Linhas da matiz A: ");
    scanf("%d", &N);
    printf("Insira o numero de Colunas da matriz A: ");
    scanf("%d", &M);

    float **matrizA = alocarMatriz(N, M);
    printf("Para matriz A: \n");
    popularMatriz(matrizA, N, M);

    printf("Insira o numero de Linhas da matiz B: ");
    scanf("%d", &N_B);
    printf("Insira o numero de Colunas da matriz B: ");
    scanf("%d", &M_B);

    float **matrizB = alocarMatriz(N_B, M_B);
    printf("Para matriz B: \n");
    popularMatriz(matrizB, N_B, M_B);

    int resp;
    printf("Deseja printar as matrizez? 1 ou 0: ");
    scanf("%d", &resp);
    if (resp == 1)
    {
        printf("Matriz A:\n");
        obterMatriz(matrizA, N, M);
        printf("Matriz B:\n");
        obterMatriz(matrizB, N_B, M_B);
        resp = -1;
    }

    printf("Deseja alocar e printar a transposta de A? 1 ou 0: ");
    scanf("%d", &resp);
    if (resp == 1)
    {
        obterTransposta(matrizA, N, M);
        resp = -1;
        printf("\n");
    }

    printf("Deseja somar e printar as matrizes? 1 ou 0: ");
    scanf("%d", &resp);
    if (resp == 1)
    {
        somaMatrizes(matrizA, N, M, matrizB, N_B, M_B);
        resp = -1;
    }

    printf("Deseja multiplicar e printar as matrizes? 1 ou 0: ");
    scanf("%d", &resp);
    if (resp == 1)
    {
        multiplicaMatrizes(matrizA, N, M, matrizB, N_B, M_B);
        resp = -1;
    }

    liberarMemoria(matrizA, N);
    liberarMemoria(matrizB, N_B);

    return 0;
}



void popularMatriz(float **matriz, int N, int M)
{
    float numero;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("Digite o numero %dx%d: ", i + 1, j + 1);
            scanf("%f", &numero);
            matriz[i][j] = numero;
        }
    }
    printf("\n");
}

void liberarMemoria(float **matriz, int N)
{
    for (int i = 0; i < N; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

void obterMatriz(float **matriz, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            printf("[%.2f]", matriz[i][j]);
        }
        printf("\n");
    }
}

void obterTransposta(float **matriz, int N, int M)
{
    float **matrizTransposta;
    matrizTransposta = (float **)malloc(M * sizeof(float *));
    for (int i = 0; i < M; i++)
    {
        matrizTransposta[i] = (float **)malloc(N * sizeof(float));
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrizTransposta[i][j] = matriz[j][i];
        }
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("[%.2f]", matrizTransposta[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < M; i++)
    {
        free(matrizTransposta[i]);
    }
    free(matrizTransposta);
}

void somaMatrizes(float **matriz, int N, int M, float **matriz_2, int N_2, int M_2)
{
    if (N != N_2 || M != M_2)
    {
        printf("Matrizes de diferentes tamanhos, impossível somá-las!\n");
    }
    else
    {
        float **matrizSomada;
        matrizSomada = (float **)malloc(N * sizeof(float *));

        for (int i = 0; i < N; i++)
        {
            matrizSomada[i] = (float *)malloc(M * sizeof(float));
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                matrizSomada[i][j] = matriz[i][j] + matriz_2[i][j];
            }
        }

        obterMatriz(matrizSomada, N, M);

        for (int i = 0; i < N; i++)
        {
            free(matrizSomada[i]);
        }
        free(matrizSomada);
    }
}

void multiplicaMatrizes(float **matriz, int N, int M, float **matriz_2, int N_2, int M_2)
{
    if (M != N_2)
    {
        printf("Não é possível multiplicar as matrizes! Número de colunas da matriz A diferente do número de linhas da matriz B!\n");
    }
    else
    {
        float **matrizMultiplicada;
        matrizMultiplicada = (float **)malloc(N * sizeof(float *));
        for (int i = 0; i < N; i++)
        {
            matrizMultiplicada[i] = (float *)malloc(M_2 * sizeof(float));
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M_2; j++)
            {
                matrizMultiplicada[i][j] = 0;
                for (int k = 0; k < M; k++)
                {
                    matrizMultiplicada[i][j] += matriz[i][k] * matriz_2[k][j];
                }
            }
        }

        obterMatriz(matrizMultiplicada, N, M_2);

        for (int i = 0; i < N; i++)
        {
            free(matrizMultiplicada[i]);
        }
        free(matrizMultiplicada);
    }
}