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

int n, comp = 0;
float mes, dt, soma = 0; //dt = decimo  terceiro

//função que recebe o vetor de funcionários e mostra para cada funcionário o nome dele, o cargo e quanto ele vai deve receber de 13°
void decimo(funcionario *f, int n){

    for(int i=0; i<n; i++){
      comp = strcmp(f[i].cargo,"garçom");
        for(int j=0; j<12; j++){
          
            if(comp==0){ //se o conteúdo de cargo for igual a garçom
                mes = f[i].pagamentos[j].salario + f[i].pagamentos[j].comissao;
                soma = soma + mes;
                dt = soma/12;
            } else {
                soma = soma + f[i].pagamentos[j].salario;
                dt = soma/12; 
            }
        }
    }

  for(int i=0; i<n; i++){
  printf("\nNome: %s\nCargo: %s\n13°: %.2f\n", f[i].nome, f[i].cargo, dt); 
  }
}
