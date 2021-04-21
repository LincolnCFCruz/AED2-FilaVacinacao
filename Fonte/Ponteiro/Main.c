#include "Vacina.h"

//Menu de opções.
int Escolha() 
{
  int resp;

  printf("\n");
  printf("  +------------------------------------------+\n");
  printf("  |     Fila - Vacinação contra COVID-19     |\n");
  printf("  +------------------------------------------+\n");
  printf("  |    0 → Informações sobre o programa.     |\n");
  printf("  |    1 → Cadastrar uma pessoa na fila.     |\n");
  printf("  |    2 → Exibir a fila geral.              |\n");
  printf("  |    3 → Exibir uma fila específica.       |\n");
  printf("  |    4 → Sair.                             |\n");
  printf("  +------------------------------------------+\n");
  printf("\n");
  scanf("%d", &resp);
  
  return resp;
}


void Menu (Fila *FilaGeral, Fila *Fase1, Fila *Fase2, Fila *Fase3, Fila *Fase4)
{
	int Opcao = 0;
	int Voltar = 0;
	Opcao = Escolha();
	
	switch(Opcao) 
    {
	  case 0:
	  {
		printf("\n");
		printf("  +-----------------------------------+\n");
		printf("  |   Informações sobre o programa    |\n");
		printf("  +-----------------------------------+---------------------------------+\n");
		printf("  | O programa 'Vacinação contra COVID-19' tem o objetivo de aprimorar  |\n");
		printf("  | nossas habilidades em torno do uso de ponteiros e arranjos, na dis- |\n");
		printf("  | ciplina de AEDII.                                                   |\n");
		printf("  +-----------------------------------+---------------------------------+\n");
		printf("  |            Autores                |              Github             |\n");
		printf("  +-----------------------------------+---------------------------------+\n");
		printf("  |   Lincoln Corrêa Figueiredo Cruz  |           LincolnCFCruz         |\n");
		printf("  |   Pedro Igor Martins dos Reis     |              ORZAYAZ            |\n");
		printf("  |   Rafaela Mesquita Gontijo        |           rafamesquita          |\n");
		printf("  |   Rafael Brandão Nunes            |          RafaelBrandao13        |\n");
		printf("  +---------------------------------------------------------------------+\n");
		printf("\n"); 
	
		Reiniciar();
		scanf("%d", &Voltar);
		if(Voltar == 1)
		{
			Menu(FilaGeral,Fase1,Fase2,Fase3,Fase4);				
		}
		else
		{
			Fim();
			exit(0);
		}  
	  }
      //Cadastrar uma nova pessoa na fila.
      case 1: 
      {
        Pessoa P;
        printf("\n");
		printf("  +---------------------------------------+\n");
		printf("  |   Cadastrar uma nova pessoa na fila   |\n");
		printf("  +---------------------------------------+\n");	
		printf("\n");
		
		printf("Nome: ");
		scanf("%s", P.nome);  //Inserir nome.
		printf("Idade: ");
        scanf("%d", &P.idade);  //Inserir idade.
        printf("Insira o valor referente a sua profissão de acordo com os grupos abaixo: \n");
        ImprimirGrupos();
        scanf("%d", &P.profissao);  //Inserir profissão.
        printf("Apresenta alguma das comorbidades abaixo? (1 - SIM | 0 - NÃO) \n");
        ImprimirComorbidades();
        scanf("%d", &P.comorbidades);
        EncaixarNaFila(Fase1,Fase2,Fase3,Fase4,&P);
        CadastrarPessoa(FilaGeral, &P);  //Chama a função de cadastro.
        
        ExibePessoa(P);
        
        Reiniciar();
		scanf("%d", &Voltar);
		if(Voltar == 1)
		{
			Menu(FilaGeral,Fase1,Fase2,Fase3,Fase4);		
		}
		else
		{
			Fim();
			exit(0);
		}
       break;
      }
      
      //Exibir toda a fila.
      case 2: 
      {
		 int Voltar = 0;
	
		 printf("\n");
		 printf("  +---------------------------+\n");
		 printf("  |   Exibir a fila geral     |\n");
		 printf("  +---------------------------+\n");	
		 printf("\n");
		 ImprimirLista(FilaGeral);
    
		Reiniciar();
		scanf("%d", &Voltar);
		if(Voltar == 1)
		{
			Menu(FilaGeral,Fase1,Fase2,Fase3,Fase4);	
		}
		else
		{
			Fim();
			exit(0);
		} 
	  }

      //Exibir uma fila específica.
      case 3: 
      {
		int fase;
		int Voltar = 0;
	
		//Menu para as fases.
		printf("\n");
		printf("  +--------------------------------+\n");
		printf("  |   Exibir uma fila específica   |\n");
		printf("  +--------------------------------+\n");	
		printf("  | 1 → Primeira fase              |\n");
		printf("  | 2 → Segunda fase               |\n");
		printf("  | 3 → Terceira fase              |\n");
		printf("  | 4 → Quarta fase                |\n");
		printf("  +--------------------------------+\n");	
		printf("\n");
		scanf("%d", &fase);
      
		if (fase == 1) 
		{
			//Função para exibir fase 1.
			printf("\n");
			printf("  +------------------------------+\n");
			printf("  |    Exibir a primeira fase    |\n");
			printf("  +------------------------------+\n");	
			printf("\n");
			ImprimirLista(Fase1);
		}	
		else if (fase == 2) 
		{
			//Função para exibir fase 2.
			printf("\n");
			printf("  +-----------------------------+\n");
			printf("  |     Exibir a segunda fase   |\n");
			printf("  +-----------------------------+\n");	
			printf("\n");
			ImprimirLista(Fase2);
		}
		else if (fase == 3) 
		{
			//Função para exibir fase 3.
			printf("\n");
			printf("  +------------------------------+\n");
			printf("  |    Exibir a terceira fase    |\n");
			printf("  +------------------------------+\n");	
			printf("\n");
			ImprimirLista(Fase3);
		}	
		else if (fase == 4) 
		{
			//Função para exibir fase 4.
			printf("\n");
			printf("  +----------------------------+\n");
			printf("  |    Exibir a quarta fase    |\n");
			printf("  +----------------------------+\n");	
			printf("\n");
			ImprimirLista(Fase4);
		}
		else
		{
			printf("\n");
			printf("  +----------------------+\n");
			printf("  |    Opção inválida    |\n");
			printf("  +----------------------+\n");	
			printf("\n");
		}	
			
		Reiniciar();
		scanf("%d", &Voltar);
		if(Voltar == 1)
		{
			Menu(FilaGeral,Fase1,Fase2,Fase3,Fase4);			
		}
		else
		{
			Fim();
			exit(0);
		} 
		break;
      } 
      
      case 4:
      {
		  exit(0);
	  }
	  
      default:
      {
			printf("\n");
			printf("  +----------------------------------+\n");
			printf("  | Opção inválida, tente novamente. |\n");  
			printf("  +----------------------------------+\n");
			printf("\n");
				
			printf("  +--------------------------+\n");
			printf("  | Deseja tentar novamente? |\n");  
			printf("  +--------------------------+\n");
			printf("  |     1 - Sim | 0 - Não    |\n");
			printf("  +--------------------------+\n");
			scanf("%d", &Voltar);
			if(Voltar == 1)
			{
				Menu(FilaGeral,Fase1,Fase2,Fase3,Fase4);
			}
			else
			{
				Fim();
				exit(0);
			}
			
			break;
	  }

    }
}

int main(void) 
{
	//Struct Fila que aponta para o início e fim da fila.
	//Libera memória e atualiza os apontadores e início e fim.
	Fila FilaGeral;  
	Fila Fase1;
	Fila Fase2;
	Fila Fase3;
	Fila Fase4;
	NovaFila(&FilaGeral);
	NovaFila(&Fase1);
	NovaFila(&Fase2);
	NovaFila(&Fase3);
	NovaFila(&Fase4);
	
	Menu(&FilaGeral,&Fase1,&Fase2,&Fase3,&Fase4);
  return 0;
}
