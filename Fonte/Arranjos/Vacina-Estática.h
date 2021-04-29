#ifndef VACINA_H
#define VACINA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 2

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

//Estrutura que indica o tamanho, início e o final da fila.
typedef struct Fila 
{
  Pessoa fila[MAX];
  int Inicio, Fim, Tamanho;
} Fila;

void ImprimirGrupos();
void ImprimirComorbidades();
void ExibePessoa (Pessoa P);
void NovaFila (Fila *F);
void CadastrarPessoa (Fila *F, Pessoa dado);
void ImprimePessoa(Pessoa P);
void ImprimirLista(Fila *F);
void Parcial(Fila *F, int Fase);
void DefinirFase(Fila *F,Pessoa P);
void ForaFila();
void ExibirMenu();
void Erro();
void Info();
void Links();
void Reiniciar();
void Fim();

#endif  
