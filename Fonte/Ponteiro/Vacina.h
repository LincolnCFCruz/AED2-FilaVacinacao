#ifndef VACINA_H
#define VACINA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura para armazenar os dados dos candidatos a vacinação.
typedef struct Pessoa 
{
  char nome[30];
  int idade;
  int comorbidades;
  int profissao;
  int fase;
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

//Imprimir todos os grupos disponíveis para facilitar no uso do programa.
void ImprimirGrupos()
{
	printf("\n");
	printf("  +--------+----------------------------------------------+\n");
	printf("  | Grupos |                Informações                   |\n");
	printf("  +--------+----------------------------------------------+\n");
	printf("  |    0   | Nenhum dos grupos                            |\n");
	printf("  +--------+----------------------------------------------+\n");
	printf("  |    1   | Sistema Único de Assistência Social (SUAS),  |\n");
	printf("  |        | das entidades e organizações de assistência  |\n");
	printf("  |        | social, conselheiros tutelares que prestam   |\n");
	printf("  |        | atendimento ao público                       |\n");
	printf("  +--------+----------------------------------------------+\n");
	printf("  |    2   | Trabalhadores da educação do ensino básico em|\n");
	printf("  |        | exercício nos ambientes escolares            |\n");
	printf("  +--------+----------------------------------------------+\n");
	printf("  |    3   | Coveiros, atendentes e agentes funerários    |\n");
	printf("  +--------+----------------------------------------------+\n");
	printf("  |    4   | Profissionais que trabalham em farmácias     |\n");
	printf("  +--------+----------------------------------------------+\n");
	printf("  |    5   | Oficiais de justiça                          |\n");
	printf("  +--------+----------------------------------------------+\n");
	printf("  |    6   | Taxistas e mototaxistas                      |\n");
	printf("  +--------+----------------------------------------------+\n");
	printf("  |    7   | Profissionais de limpeza pública             |\n");
	printf("  +--------+----------------------------------------------+\n");
	printf("\n");

}

void ImprimirComorbidades()
{
	printf("\n");
	printf("  +----------------+--------------+--------------+--------------+\n");
	printf("  |   Cardiopatia  |   Diabetes   |  Pneumopatia | Doença renal |\n"); 
	printf("  +----------------+--------------+--------------+--------------+\n");
	printf("  | Imunodepressão |   Obesidade  |     Asma     |   Puérperas  |\n");
	printf("  +----------------+--------------+--------------+--------------+\n");
	printf("\n");
}
//Exibe o nome, idade e profissao daquele presente na fila.
void ExibePessoa (Pessoa p) 
{
		printf("\n");
		printf("  +----------------------+-------------------------------+\n");
		printf("  |        Pessoa        |            Informação         |\n");
		printf("  +----------------------+-------------------------------+\n");
		printf("  |         Nome         | %-30s|\n",p.nome);
		printf("  |        Idade         | %-2d anos                       |\n",p.idade);
		printf("  |   Profissão (Grupo)  | Grupo %-1d                       |\n",p.profissao);
		printf("  | Comorbidades (1 | 0) | %-1d                             |\n",p.comorbidades);
		printf("  |         Fase         | %-1d                             |\n",p.fase);
		printf("  +----------------------+-------------------------------+\n");
		printf("\n");
}

//Alocação dinâmica de memória da célula com os dados.
//Nova célula recebe o ponteiro próximo que aponta para NULL.
Celula *NovaCelula () 
{
  Celula *aux = (Celula*)malloc(sizeof(Celula));
  aux->prox = NULL;  
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
void CadastrarPessoa (Fila *f, Pessoa *dado) 
{
  Celula *nova = NovaCelula();  
  nova->dado = *dado;  
  f->fim->prox = nova;
  f->fim = nova;
  f->tam++;  
}

//Imprimir os dados inseridos.
void ImprimePessoa(Pessoa P)
{
	printf("  | %d    | %-2d    | %d                 | %d                  | %-30s|\n",P.fase,P.idade,P.profissao,P.comorbidades,P.nome);
}

//Imprimir no formato de tabela a fila de pessoas.
void ImprimirLista(Fila *F)
{
	printf("  +------+-------+-------------------+--------------------+-------------------------------+\n");
	printf("  | Fase | Idade | Profissão (Grupo) | Comorbidades (1|0) |              Nome             |\n");
	printf("  +------+-------+-------------------+--------------------+-------------------------------+\n");
	
	Celula *tmp = F->inicio->prox;
	while(tmp != NULL)
	{
		ImprimePessoa(tmp->dado);
		tmp = tmp->prox;
	}
	printf("  +------+-------+-------------------+--------------------+-------------------------------+\n");
}

void EncaixarNaFila(Fila *F1,Fila *F2,Fila *F3,Fila *F4,Pessoa *P)
{
	if(P->idade > 75 || P->profissao == 1)
	{
		P->fase = 1;
		CadastrarPessoa(F1,P);
	}
	else if(P->idade >= 60 && P->idade <= 74)
	{
		P->fase = 2;
		CadastrarPessoa(F2,P);
	}
	else if(P->comorbidades == 1)
	{
		P->fase = 3;
		CadastrarPessoa(F3,P);
	}
	else
	{
		P->fase = 4;
		CadastrarPessoa(F4,P);
	}
}

void Reiniciar()
{
	printf("  +-------------------------+\n");
	printf("  | Deseja voltar ao menu ? |\n");  
	printf("  +-------------------------+\n");
	printf("  |    1 - Sim | 0 - Não    |\n");
	printf("  +-------------------------+\n");
	printf("\n");
}

void Fim()
{
	printf("\n");
	printf("  +-----------------+\n");
	printf("  | Fim do programa |\n");
	printf("  +-----------------+\n");
	printf("\n");
}

#endif
