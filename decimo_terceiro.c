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

int main(){

    printf("\nDigíte a quantidade de funcionários: ");
    scanf("%d", &n);

    funcionario *f;
    f = malloc (n*sizeof(funcionario));

    //verofocação de memória suficiente disponível
    if(f==NULL){
        printf("\nERRRO NA ALOCAÇÃO DE MEMÓRIA");
        exit(1);
    }

    //preenchimento das estruturas
    for(int i=0; i<n; i++){
        printf("\nNome: ");
        scanf("%s", f[i].nome);
        printf("\nCargo: ");
        scanf("%s", f[i].cargo);
        for(int j=0; j<12; j++){
            printf("\nSalário do %d° mês: ", j+1);
            scanf("%f", &f[i].pagamentos[j].salario);
            printf("\nComissão do %d mês: ", j+1);
            scanf("%f", &f[i].pagamentos[j].comissao);
        }
    }

    decimo(f, n); //chamada da função

    free(f); //liberando o espaço da alocação de memória

   return 0; 
}