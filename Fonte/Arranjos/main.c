#include "Vacina-Estática.h"

int Escolha() 
{
  int Resp = 0;
  ExibirMenu();
  scanf("%d", &Resp);
  
  return Resp;
}

void Menu(Fila *FilaGeral)
{
	char Aux;
	int Opcao = 0;
	int Voltar = 0;
	Opcao = Escolha();
	
	switch(Opcao)
	{
		case 0:
		{
			Info();
			Reiniciar();
			scanf("%d", &Voltar);
			if(Voltar == 1)
			{
				Menu(FilaGeral);
			}
			else
			{
				Fim();
				exit(0);
			}
			break;
		}
		
		case 1:
		{
			char Genero;
			Pessoa P;
      if(FilaGeral->Tamanho == MAX)
      {
        printf("  +------------------+\n");
        printf("  | Erro, fila Cheia | \n");
        printf("  +------------------+\n");
        Reiniciar();
			  scanf("%d", &Voltar);
			  if(Voltar == 1)
			  {
				  Menu(FilaGeral);		
			  }
			  else
			  {
				  Fim();
				  exit(0);
			  }
			  break;
      }
			
			printf("\n");
			printf("  +---------------------------------------+\n");
			printf("  |   Cadastrar uma nova pessoa na fila   |\n");
			printf("  +---------------------------------------+\n");	
			printf("\n");
			
			printf("Gênero: (H - Homem | M - Mulher)\n");
			fflush(stdin);
			scanf(" %c", &Genero);
			
			if(Genero == 'H' || Genero == 'h')
			{
				printf("Nome: ");
				scanf("%c",&Aux);
				scanf("%[^\n]",P.Nome);
			
				printf("Idade: ");
				scanf("%d", &P.Idade);
			
				printf("Insira o valor referente a sua profissão de acordo com os grupos abaixo: \n");
				ImprimirGrupos();
				scanf("%d", &P.Profissao);
			
				printf("Apresenta alguma das comorbidades abaixo? (1 - SIM | 0 - NÃO)\n");
				ImprimirComorbidades();
				scanf("%d", &P.Comorbidades);
				
				printf("Apresenta alergia a vacina ou a algum dos componentes da mesma? (1 - SIM | 0 - NÃO)\n");
				scanf("%d", &P.Alergico);
				
				DefinirFase(FilaGeral,P);
			}
			
			else if(Genero == 'M' || Genero == 'm')
			{
				printf("Nome: ");
				scanf("%c",&Aux);
				scanf("%[^\n]",P.Nome);
			
				printf("Idade: ");
				scanf("%d", &P.Idade);
			
				printf("Insira o valor referente a sua profissão de acordo com os grupos abaixo: \n");
				ImprimirGrupos();
				scanf("%d", &P.Profissao);
			
				printf("Apresenta alguma das comorbidades abaixo? (1 - SIM | 0 - NÃO)\n");
				ImprimirComorbidades();
				scanf("%d", &P.Comorbidades);
			
				printf("Você é gestante? (1 - SIM | 0 - NÃO)\n");
				scanf("%d", &P.Gestante);
			
				printf("Apresenta alergia a vacina ou a algum dos componentes da mesma? (1 - SIM | 0 - NÃO)\n");
				scanf("%d", &P.Alergico);
				
				DefinirFase(FilaGeral,P);
			}
			
			else
			{
				Erro();
			}
			
			Reiniciar();
			scanf("%d", &Voltar);
			if(Voltar == 1)
			{
				Menu(FilaGeral);		
			}
			else
			{
				Fim();
				exit(0);
			}
			break;
		}
		
		case 2:
		{
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
				Menu(FilaGeral);		
			}
			else
			{
				Fim();
				exit(0);
			}
			break;
		}
		
		case 3:
		{
			int fase;
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
				Parcial(FilaGeral, fase);
			
			}
				
			else if (fase == 2) 
			{
			//Função para exibir fase 2.
				printf("\n");
				printf("  +-----------------------------+\n");
				printf("  |     Exibir a segunda fase   |\n");
				printf("  +-----------------------------+\n");	
				printf("\n");
				Parcial(FilaGeral, fase);
			}
		
			else if (fase == 3) 
			{
				//Função para exibir fase 3.
				printf("\n");
				printf("  +------------------------------+\n");
				printf("  |    Exibir a terceira fase    |\n");
				printf("  +------------------------------+\n");	
				printf("\n");
				Parcial(FilaGeral, fase);
			}	
		
			else if (fase == 4) 
			{
				//Função para exibir fase 4.
				printf("\n");
				printf("  +----------------------------+\n");
				printf("  |    Exibir a quarta fase    |\n");
				printf("  +----------------------------+\n");	
				printf("\n");
				Parcial(FilaGeral, fase);
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
				Menu(FilaGeral);		
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
			Links();
			Reiniciar();
			scanf("%d", &Voltar);
			if(Voltar == 1)
			{
				Menu(FilaGeral);
			}
			else
			{
				Fim();
				exit(0);
			}
			break;
		}
		
		case 5:
		{
			Fim();
			exit(0);
			break;
		}
		
		default:
		{
			Erro();
			Reiniciar();
			scanf("%d", &Voltar);
			if(Voltar == 1)
			{
				Menu(FilaGeral);
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

int main ()
{
	int Opcao = 0;
	
	Fila FilaGeral;
	NovaFila(&FilaGeral);
	
	Menu(&FilaGeral);
	
	return 0;
}