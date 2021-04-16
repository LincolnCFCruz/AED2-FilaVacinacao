#ifndef VACINA_H
#define VACINA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura para armazenar os dados dos candidatos a vacinação.
typedef struct Pessoa 
{
  char nome[50];
  int idade;
  int profissao;
} Pessoa;

//Estrutura que armazena as informações dos candidatos e o ponteiro que garante a sequência da fila.
typedef struct Celula 
{
  Pessoa dado;
  struct Celula *prox;
} Celula;

//Estrutura que indica o tamanho, início e o final da fila.
typedef struct Fila 
{
  Celula *inicio;
  Celula *fim;
  int tam;
} Fila;

void ImprimirGrupos()
{
	printf("\n");
	printf("+---------+----------------------------------------------+\n");
	printf("| Grupo 1 | Sistema Único de Assistência Social (Suas),  |\n");
	printf("|         | das entidades e organizações de assistência  |\n");
	printf("|         | social, conselheiros tutelares que prestam   |\n");
	printf("|         | atendimento ao público                       |\n");
	printf("+---------+----------------------------------------------+\n");
	printf("| Grupo 2 | Trabalhadores da educação do ensino básico em|\n");
	printf("|         | exercício nos ambientes escolares            |\n");
	printf("+---------+----------------------------------------------+\n");
	printf("| Grupo 3 | Coveiros, atendentes e agentes funerários    |\n");
	printf("+---------+----------------------------------------------+\n");
	printf("| Grupo 4 | Profissionais que trabalham em farmácias     |\n");
	printf("+---------+----------------------------------------------+\n");
	printf("| Grupo 5 | Oficiais de justiça                          |\n");
	printf("+---------+----------------------------------------------+\n");
	printf("| Grupo 6 | Taxistas e mototaxistas                      |\n");
	printf("+---------+----------------------------------------------+\n");
	printf("| Grupo 7 | Profissionais de limpeza pública             |\n");
	printf("+---------+----------------------------------------------+\n");
	printf("\n");

}
//Exibe o nome, idade e profissao daquele presente na fila.
void ExibePessoa (Pessoa p) 
{
		printf("\n");
		printf("+----------------------+------------------------+\n");
		printf("|        Pessoa        |                        |\n");
		printf("+----------------------+------------------------+\n");
		printf("|         Nome         | %s                  |\n",p.nome);
		printf("|        Idade         | %d anos                |\n",p.idade);
		printf("|   Profissão (Grupo)  | Grupo %d                |\n",p.profissao);
		printf("+----------------------+------------------------+\n");
		printf("\n");
}

//Alocação dinâmica de memória da célula com os dados.
Celula *NovaCelula () 
{
  Celula *aux = (Celula*)malloc(sizeof(Celula));
  aux->prox = NULL;  //Nova célula recebe o ponteiro próximo que aponta para NULL.
  return aux;
}

//Libera espaço na memória para criar a fila.
void NovaFila (Fila *f) 
{
  Celula *nova = NovaCelula();
  f->inicio = nova;
  f->fim = nova;
  f->tam = 0;
}

//Cadastrar uma nova pessoa na fila.
void CadastrarPessoa (Fila *f, Pessoa dado) 
{
  Celula *nova = NovaCelula();  //Outra célula é criada.
  nova->dado = dado;  //Preenchida com informações pessoais.
  //Ponteiro que indica o final da fila aponta para o último usuário cadastrado.
  f->fim->prox = nova;
  f->fim = nova;
  f->tam++;  //Aumenta em 1 o tamanho da fila.
}

void ImprimePessoa(Pessoa P)
{
	printf("| %s                |   %d  |        %d          |\n",P.nome,P.idade,P.profissao);
}
void ImprimirLista(Fila *F)
{
	printf("+----------------------+-------+-------------------+\n");
	printf("|         Nome         | Idade | Profissão (Grupo) |\n");
	printf("+----------------------+-------+-------------------+\n");
	
	Celula *tmp = F->inicio->prox;
	while(tmp != NULL)
	{
		ImprimePessoa(tmp->dado);
		tmp = tmp->prox;
	}
	printf("+----------------------+-------+-------------------+\n");
}

#endif
