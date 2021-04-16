#include "Vacina.h"

//Menu de opções.
int menu () 
{
  int resp;

  printf("\n");
  printf("  +-----------------------------------+\n");
  printf("  |     Vacinação contra COVID-19     |\n");
  printf("  +-----------------------------------+\n");
  printf("  | 0 → Informações sobre o programa. |\n");
  printf("  | 1 → Cadastrar uma pessoa na fila. |\n");
  printf("  | 2 → Exibir a fila geral.          |\n");
  printf("  | 3 → Exibir uma fila específica.   |\n");
  printf("  | 4 → Sair.                         |\n");
  printf("  +-----------------------------------+\n");
  printf("\n");
  scanf("%d", &resp);
  
  return resp;
}

int main(void) 
{
  Fila fila;  //Struct Fila que aponta para o início e fim da fila.
  NovaFila(&fila);  //Libera memória e atualiza os apontadores e início e fim.

  int op = 0;

  do 
  {
    op = menu();  //Menu principal.

    switch(op) 
    {
		
	  case 0:
	  {
			printf("\n");
			printf("+-----------------------------------+\n");
			printf("|   Informações sobre o programa    |\n");
			printf("+-----------------------------------+---------------------------------+\n");
			printf("| O programa 'Vacinação contra COVID-19' tem o objetivo de desenvolver|\n");
			printf("| nossas habilidades em torno do uso de ponteiros e arranjos, na dis- |\n");
			printf("| ciplina de AEDII.                                                   |\n");
			printf("+-----------------------------------+---------------------------------+\n");
			printf("|            Autores                |                                 |\n");
			printf("+-----------------------------------+---------------------------------+\n");
			printf("| - Lincoln Corrêa Figueiredo Cruz                                    |\n");
			printf("| - Pedro Igor Martins dos Reis                                       |\n");
			printf("| - Rafaela Mesquita Gontijo                                          |\n");
			printf("| - Rafael Brandão Nunes                                              |\n");
			printf("+---------------------------------------------------------------------+\n");
			printf("\n"); 
			break;
	  }
      //Cadastrar uma nova pessoa na fila.
      case 1: 
      {
        Pessoa p;
        printf("\n");
		printf("+---------------------------------------+\n");
		printf("|   Cadastrar uma nova pessoa na fila   |\n");
		printf("+---------------------------------------+\n");	
		printf("\n");
		printf("Nome: ");
		scanf("%s", p.nome);  //Inserir nome.
		printf("Idade: ");
        scanf("%d", &p.idade);  //Inserir idade.
        printf("Insira o valor referente a sua profissão de acordo com os grupos abaixo: \n");
        ImprimirGrupos();
        scanf("%d", &p.profissao);  //Inserir profissão.
        CadastrarPessoa(&fila, p);  //Chama a função de cadastro.
        ExibePessoa(p);
      } break;

      //Exibir toda a fila.
      case 2: 
      {
		printf("\n");
		printf("+---------------------------+\n");
		printf("|   Exibir a fila geral     |\n");
		printf("+---------------------------+\n");	
		printf("\n");
        ImprimirLista(&fila);
      } break;

      //Exibir uma fila específica.
      case 3: 
      {
        int fase;
        //Menu para as fases.
        printf("\n");
		printf("+--------------------------------+\n");
		printf("|   Exibir uma fila específica   |\n");
		printf("+--------------------------------+\n");	
		printf("| 1 → Primeira fase              |\n");
		printf("| 2 → Segunda fase               |\n");
		printf("| 3 → Terceira fase              |\n");
		printf("| 4 → Quarta fase                |\n");
		printf("+--------------------------------+\n");	
		printf("\n");
        scanf("%d", &fase);

        /*if (fase == 1) 
        {
            //Chama a função para exiber a fila da primeira fase de vacinação.
        }
        if (fase == 2) 
        {
            //Função para exibir fase 2.
        }
        if (fase == 3) 
        {
            //Função para exibir fase 3.
        }
        if (fase == 4) 
        {
            //Função para exibir fase 4.
        }*/

      } break;

    }
  } while(op != 4);

  return 0;
}
