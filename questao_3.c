/*  Dado um vetor que guarda o valor de faturamento diário de uma distribuidora de todos os dias de um ano, faça um programa, na linguagem que desejar, que calcule e retorne:

- O menor valor de faturamento ocorrido em um dia do ano;
- O maior valor de faturamento ocorrido em um dia do ano;
- Número de dias no ano em que o valor de faturamento diário foi superior à média anual.

a) Considerar o vetor já carregado com as informações de valor de faturamento.

b) Podem existir dias sem faturamento, como nos finais de semana e feriados. Estes dias devem ser ignorados no cálculo da média.

c) Utilize o algoritmo mais veloz que puder definir.*/

#include <stdio.h>

float calculaMenor(int n, float vet[])
{
    float menor = vet[0];
    for (int i = 1; i < n; i++)
    {
        if (vet[i] < menor && vet[i] != 0)
        {
            menor = vet[i];
        }
    }
    return menor;
}

float calculaMaior(int n, float vet[])
{
    float maior = 0;
    for (int i = 0; i < n; i++)
    {
        if (vet[i] > maior)
        {
            maior = vet[i];
        }
    }
    return maior;
}

int calculaDias(int n, float vet[])
{
    float media = 0, somatorio = 0;
    int dias = 0, diasValidos = 0;
    for (int i = 0; i < n; i++)
    {
        if (vet[i] != 0)
        {
            somatorio += vet[i];
            diasValidos++;
        }
    }

    media = somatorio / diasValidos;

    for (int i = 0; i < n; i++)
    {
        if (vet[i] > media)
        {
            dias++;
        }
    }

    return dias;
}

int main()
{
    // insira os valores para teste na variavel vetor
    float vetor[] = {221.50, 180.00, 0.0, 350.75, 410.30, 0.0, 298.40, 500.00, 120.90, 0.0, 275.60, 330.20, 410.30, 90.00, 600.00};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Menor valor de faturamento: %.2f\n", calculaMenor(tamanho, vetor));
    printf("Maior valor de faturamento: %.2f\n", calculaMaior(tamanho, vetor));
    printf("Dias em que o valor do faturamento foi superior a média: %d\n", calculaDias(tamanho, vetor));
}