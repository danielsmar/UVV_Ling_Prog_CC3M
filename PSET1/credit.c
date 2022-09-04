#include <stdio.h>

int main(void)
{
    long long numero_cartao, cartao_atual, div = 10;
    int soma_1 = 0, soma_2 = 0, soma_total = 0, contador = 0;

    do
    {
        printf("Informe os dígitos do seu cartao de credito:\n");
        scanf("%lld", &numero_cartao);

    } while (numero_cartao <= 0);

    // 1
    cartao_atual = numero_cartao;
    while (cartao_atual > 0)
    {
        int ultimo_digito = cartao_atual % 10;
        soma_1 = soma_1 + ultimo_digito;
        cartao_atual = cartao_atual / 100;
    }

    // 2
    cartao_atual = numero_cartao / 10;
    while (cartao_atual > 0)
    {
        int ultimo_digito = cartao_atual % 10;
        int mult = ultimo_digito * 2;
        soma_2 = soma_2 + (mult % 10) + (mult / 10);
        cartao_atual = cartao_atual / 100;
    }

    // 3
    soma_total = soma_1 + soma_2;

    cartao_atual = numero_cartao;
    while (cartao_atual != 0)
    {
        cartao_atual = cartao_atual / 10;
        contador++;
    }

    for (int i = 0; i < contador - 2; i++)
    {
        div = div * 10;
    }

    int primeiro_numero = numero_cartao / div;
    int dois_primeiros_numeros = numero_cartao / (div / 10);

    if (soma_total % 10 == 0)
    {
        if (primeiro_numero == 4 && (contador == 13 || contador == 16))
        {
            printf(" \nBANDEIRA VISA\n");
        }

        else if ((dois_primeiros_numeros == 34 || dois_primeiros_numeros == 37) && contador == 15)
        {
            printf("\nBANDEIRA AMEX \n");
        }

        else if ((dois_primeiros_numeros > 50 && dois_primeiros_numeros < 56) && contador == 16)
        {
            printf("\nBANDEIRA MASTERCARD \n");
        }

        else
        {
            printf("\nCARTAO INVALIDO\n");
        }
    }

    else
    {
        printf("\nCARTAO INVALIDO\n");
    }
}