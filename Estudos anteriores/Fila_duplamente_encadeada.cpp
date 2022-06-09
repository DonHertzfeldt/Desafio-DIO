#include <stdio.h>
#include <stdlib.h>

//Fila duplamente encadeada com ordem decrescente de prioridade de 1 a 3 e 3 dados, nome, identificacao e a prioridade.
typedef struct listano Fila;
struct listano
{
  int prioridade;
  char nome[15];
  int identificacao;
  Fila* ant;
  Fila* prox;
};

Fila* inicio;
Fila* fim;

void imprimelista(void)
{
    Fila* pont;
    pont=inicio;
    pont=pont->prox;
    if(pont!=fim)
    {  
      while(pont!=fim)
      {
          printf("%s", pont->nome);
          printf(" ");
          printf("%d", pont->identificacao);
          printf(" ");
          pont=pont->prox;
      }
      printf("\n");
    }
    else
    {
      printf("A fila está vazia.\n");
    }
}

Fila* busca (int posicao)
{
    Fila* pont;
    pont = inicio;
    while(pont->prioridade>(posicao-1))
    {
      pont=pont->prox;
    }
    return pont;
}
   


void entranafila (int prioridade , char *nome, int identificacao)
{
   
    Fila* novo;
    Fila* aux;
    Fila* proximo;
    Fila* anterior;
    int i;
    novo = (Fila*) malloc (sizeof(Fila));
    for(i=0 ; i<15 ; i++)
      {
        novo->nome[i]=nome[i];
      }
    novo->prioridade=prioridade;
    novo->identificacao=identificacao;
    aux = busca (prioridade);
    anterior = aux->ant;
    proximo = aux->prox;
    novo->prox = aux;
    novo->ant = aux->ant;
    anterior->prox = novo;
    aux->ant = novo;
}

void saidafila (void)
{
  Fila* aux;
  Fila*proximo;
  Fila*anterior;
  aux=inicio;
  aux=aux->prox;
  if(aux==fim)
  {
    printf("A fila está vazia.\n");
  }
  else
  {
    printf("O próximo da fila é: ");
    printf("%s" , aux->nome);
    printf(" ");
    printf("%d", aux->identificacao);
    printf("\n");
    anterior=aux->ant;
    proximo=aux->prox;
    anterior->prox = proximo;
    proximo->ant=anterior;
    free(aux);
  }
}
   
   
int main()
{
    int identificacao,prioridade,operacao=1;
    Fila* n1;
    Fila* n2;
    char nome[15];
    n1 = (Fila*)malloc(sizeof(Fila));
    n2 = (Fila*)malloc(sizeof(Fila));
    n1->prioridade = 4;
    n1->prox=n2;
    n1->ant=n2;
    n2->prioridade = 0;
    n2->prox=n1;
    n2->ant=n1;
    inicio=n1;
    fim=n2;
    while(operacao!=0)
    {
        printf("Digite 1 para inserir , 2 para remover , 3 para imprimir e 0 para sair. \n");
        scanf("%d", &operacao);
        if(operacao==1)
        {
            printf("Digite a Prioridade de 1 a 3, o nome e a identificação do paciente: \n");
            scanf("%d", &prioridade);
            scanf("%s", nome);
            scanf("%d", &identificacao);
            entranafila(prioridade, nome, identificacao);
        }
        else if(operacao==2)
        {
            saidafila();
        }
        else if(operacao==3)
        {
            imprimelista();
        }
    }      
}