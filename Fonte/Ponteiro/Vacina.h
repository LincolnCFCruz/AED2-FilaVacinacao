#ifndef VACINA_H
#define VACINA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura para armazenar os dados dos candidatos a vacinação.
typedef struct Pessoa 
{
  char Nome[30];
  int Idade;
  int Comorbidades;
  int Profissao;
  int Fase;
  int Gestante;
  int Alergico;
  int Exclusao;
} Pessoa;

//Estrutura que armazena as informações dos candidatos e o ponteiro que garante a sequência da fila.
typedef struct Celula 
{
  Pessoa Dado;
  struct Celula *Proximo;
} Celula;

//Estrutura que indica o tamanho, início e o final da fila.
typedef struct Fila 
{
  Celula *Inicio;
  Celula *Fim;
  int Tamanho;
} Fila;

void ImprimirGrupos();
void ImprimirComorbidades();
void ExibePessoa (Pessoa *P);
Celula *NovaCelula ();
void NovaFila (Fila *F);
void CadastrarPessoa (Fila *F, Pessoa *dado);
void ImprimePessoa(Pessoa P);
void ImprimirLista(Fila *F);
void Parcial(Fila *F, int Fase);
void DefinirFase(Fila *F,Pessoa *P);
void ForaFila();
void ExibirMenu();
void Erro();
void Info();
void Links();
void Reiniciar();
void Fim();

#endif
