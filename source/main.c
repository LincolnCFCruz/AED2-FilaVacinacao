#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura para armazenar os dados dos candidatos a vacinação.
typedef struct Pessoa {
  char nome[50];
  int idade;
  char profissao[50];
} Pessoa;

//Estrutura que armazena as informações dos candidatos e o ponteiro que garante a sequência da fila.
typedef struct Celula {
  Pessoa dado;
  struct Celula *prox;
} Celula;

//Estrutura que indica o tamanho, início e o final da fila.
typedef struct Fila {
  Celula *inicio;
  Celula *fim;
  int tam;
} Fila;

//Exibe o nome, idade e profissao daquele presente na fila.
int exibe (Pessoa p) {
  printf("Nome: %s\tIdade: %d\tProfissao: %s\n", p.nome, p.idade, p.profissao);
}

//Alocação dinâmica de memória da célula com os dados.
Celula *novacelula () {
  Celula *aux = (Celula*)malloc(sizeof(Celula));
  aux->prox = NULL;  //Nova célula recebe o ponteiro próximo que aponta para NULL.
  return aux;
}

//Libera espaço na memória para criar a fila.
void novafila (Fila *f) {
  Celula *nova = novacelula();
  f->inicio = nova;
  f->fim = nova;
  f->tam = 0;
}

//Cadastrar uma nova pessoa na fila.
void cadastra (Fila *f, Pessoa dado) {
  Celula *nova = novacelula();  //Outra célula é criada.
  nova->dado = dado;  //Preenchida com informações pessoais.
  //Ponteiro que indica o final da fila aponta para o último usuário cadastrado.
  f->fim->prox = nova;
  f->fim = nova;
  f->tam++;  //Aumenta em 1 o tamanho da fila.
}

//Exibe toda a fila.
void mostrafila (Fila *f) {
  Celula *aux = f->inicio->prox;
  while (aux != NULL) {
    exibe (aux->dado);
    aux = aux->prox;
  }
}

//Menu de opções.
int menu () {
  int resp;
  printf("\n===================================");
  printf("\n| \tVacinação contra COVID-19     |");
  printf("\n===================================");
  printf("\n| 1- Cadastrar uma pessoa na fila.|");
  printf("\n| 2- Exibir uma fila geral.       |");
  printf("\n| 3- Exibir uma fila específica.  |");
  printf("\n| 4- Sair.                        |");
  printf("\n===================================\n");
  scanf("%d", &resp);
  return resp;
}

int main(void) {
  Fila fila;  //Struct Fila que aponta para o início e fim da fila.
  novafila(&fila);  //Libera memória e atualiza os apontadores e início e fim.
  int op = 0;

  do {
    op = menu();  //Menu principal.

    switch(op) {
      //Cadastrar uma nova pessoa na fila.
      case 1: {
        Pessoa p;
        printf("Nome: ");
        scanf("%s", p.nome);  //Inserir nome.
        printf("Idade: ");
        scanf("%d", &p.idade);  //Inserir idade.
        printf("Profissao: ");
        scanf("%s", p.profissao);  //Inserir profissão.
        cadastra(&fila, p);  //Chama a função de cadastro.
      } break;

      //Exibir toda a fila.
      case 2: {
        mostrafila(&fila);
      } break;

      //Exibir uma fila específica.
      case 3: {
        int fase;
        //Menu para as fases.
        printf("\nDeseja ver a fila de qual fase?");
        printf("\n=======================");
        printf("\n| 1- Primeira fase.   |");
        printf("\n| 2- Segunda fase.    |");
        printf("\n| 3- Terceira fase.   |");
        printf("\n| 4- Quarta fase.     |");
        printf("\n=======================\n");
        scanf("%d", &fase);

        if (fase == 1) {
            //Chama a função para exiber a fila da primeira fase de vacinação.
        }
        if (fase == 2) {
            //Função para exibir fase 2.
        }
        if (fase == 3) {
            //Função para exibir fase 3.
        }
        if (fase == 4) {
            //Função para exibir fase 4.
        }

      } break;

    }
  } while(op != 4);

  return 0;
}
