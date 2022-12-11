#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//estrutura para armezenar as informações do pagamento do mês
typedef struct{
    float salario;
    float comissao;
} mespg;

//estrutura para armezenar as informações de funcionário
typedef struct{
    char nome[100];
    char cargo[50];
    mespg pagamentos[12]; //vetor com 12 posições (12 meses) de pagamentos
} funcionario;

