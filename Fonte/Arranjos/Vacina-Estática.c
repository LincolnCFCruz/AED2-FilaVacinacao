#include "Vacina-Estática.h"

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
	printf("                   +-----------------------------+               \n");
	printf("                   |        Comorbidades         |               \n");
	printf("  +----------------+--------------+--------------+--------------+\n");
	printf("  |   Cardiopatia  |   Diabetes   |  Pneumopatia | Doença renal |\n"); 
	printf("  +----------------+--------------+--------------+--------------+\n");
	printf("  | Imunodepressão |   Obesidade  |     Asma     |   Puérperas  |\n");
	printf("  +----------------+--------------+--------------+--------------+\n");
	printf("\n");
}

void ExibePessoa (Pessoa P) 
{
		printf("\n");
		printf("  +----------------------+-------------------------------+\n");
		printf("  |        Pessoa        |            Informação         |\n");
		printf("  +----------------------+-------------------------------+\n");
		printf("  |         Nome         | %-30s|\n",P.Nome);
		printf("  |        Idade         | %-2d anos                       |\n",P.Idade);
		printf("  |   Profissão (Grupo)  | Grupo %-1d                       |\n",P.Profissao);
		printf("  | Comorbidades (1 | 0) | %-1d                             |\n",P.Comorbidades);
		printf("  |         Fase         | %-1d                             |\n",P.Fase);
		printf("  +----------------------+-------------------------------+\n");
		printf("\n");
}

void NovaFila (Fila *F) 
{
  F->Inicio = 0;
  F->Fim = 0;
  F->Tamanho = 0;
}

void CadastrarPessoa (Fila *F, Pessoa P) 
{
  if(F->Tamanho == MAX){
    printf("Fila cheia!\n");
  }
  else if(F->Tamanho == 0){
    F->fila[0] = P;
    F->Tamanho++;
    F->Fim++;
    printf("\nPessoa cadastrada!\n");
  }
  else{
    int posicao = F->Tamanho-1;
    while(posicao >= 0 && F->fila[posicao].Fase > P.Fase){
      F->fila[posicao+1] = F->fila[posicao];
      posicao--;
    }
    posicao++;
    F->fila[posicao] = P;
    F->Tamanho++;
    F->Fim++;
    printf("\nPessoa cadastrada!\n");
  }  
}

void ImprimePessoa(Pessoa P)
{
	printf("  | %d    | %-2d    | %d                 | %d                  | %-30s|\n",P.Fase,P.Idade,P.Profissao,P.Comorbidades,P.Nome);
}

void ImprimirLista(Fila *F)
{
  if(F->Tamanho==0){
    printf("Erro!A fila esta vazia\n");
  }
  else{
    printf("  +------+-------+-------------------+--------------------+-------------------------------+\n");
    printf("  | Fase | Idade | Profissão (Grupo) | Comorbidades (1|0) |              Nome             |\n");
    printf("  +------+-------+-------------------+--------------------+-------------------------------+\n");
    int i=0;
    while(i < F->Tamanho){
      ImprimePessoa(F->fila[i]);
      i++;
    }
    printf("  +------+-------+-------------------+--------------------+-------------------------------+\n");
  }
}

void Parcial(Fila *F, int Fase)
{
  if(F->Tamanho == 0){
    printf("Erro!A Fila esta vazia\n");
  }
  else{
    printf("  +------+-------+-------------------+--------------------+-------------------------------+\n");
    printf("  | Fase | Idade | Profissão (Grupo) | Comorbidades (1|0) |              Nome             |\n");
    printf("  +------+-------+-------------------+--------------------+-------------------------------+\n");
    int i=0;
    while(i <= F->Tamanho){
      if(F->fila[i].Fase == Fase)
      {
        ImprimePessoa(F->fila[i]);
      }
      i++;
    }
    printf("  +------+-------+-------------------+--------------------+-------------------------------+\n");
  }
}

void DefinirFase(Fila *FilaGeral, Pessoa P)
{
	if(P.Idade > 75 || P.Profissao == 1)
	{
		P.Fase = 1;
		CadastrarPessoa(FilaGeral, P);
		ExibePessoa(P);
	}
	else if(P.Idade >= 60 && P.Idade <= 74)
	{
		P.Fase = 2;
		CadastrarPessoa(FilaGeral, P);
		ExibePessoa(P);
	}
	else if(P.Comorbidades == 1)
	{
		P.Fase = 3;
		CadastrarPessoa(FilaGeral, P);
		ExibePessoa(P);
	}
	else if(P.Idade < 18 || P.Gestante == 1 || P.Alergico == 1)
	{
		ForaFila();
	}
	else
	{
		P.Fase = 4;
		CadastrarPessoa(FilaGeral, P);
		ExibePessoa(P);
	}
}

void ExibirMenu()
{
	printf("\n");
	printf("  +------------------------------------------+\n");
	printf("  |     Fila - Vacinação contra COVID-19     |\n");
	printf("  +------------------------------------------+\n");
	printf("  |    0 → Informações sobre o programa.     |\n");
	printf("  |    1 → Cadastrar uma pessoa na fila.     |\n");
	printf("  |    2 → Exibir a fila geral.              |\n");
	printf("  |    3 → Exibir uma fila específica.       |\n");
	printf("  |    4 → Links úteis.                      |\n");
	printf("  |    5 → Sair.                             |\n");
	printf("  +------------------------------------------+\n");
	printf("\n");
}

void Info()
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
}

void ForaFila()
{
	printf("  +--------------+\n");
	printf("  | Fora da fila |\n");
	printf("  +--------------+---------------+\n");
	printf("  | A vacinação é contraindicada |\n");
	printf("  | para menores de 18 anos,     |\n");
	printf("  | gestantes, ou se teve alguma |\n");
	printf("  | reação alérgica a uma dose    |\n");
	printf("  | anterior a vacina ou a algum |\n");
	printf("  | compontente da mesma.        |\n");
	printf("  +------------------------------+\n");
}

void Links()
{
	printf("  +-------+\n");
	printf("  | Links |\n");
	printf("  +-------+------------+----------------------------------+\n");
	printf("  |      Doenças       | https://saude.abril.com.br/      |\n");
	printf("  |  Grupos de risco   | https://gauchazh.clicrbs.com.br/ |\n");
	printf("  | Painel Coronavírus | https://covid.saude.gov.br/      |\n");
	printf("  |   Saúde / Gov.br   | https://coronavirus.saude.gov.br/|\n");
	printf("  |    Vacinação MG    | https://vacinaminas.mg.gov.br/   |\n");
	printf("  +-------+---------+-------------------------------------+\n");
}

void Erro()
{
	printf("\n");
	printf("  +----------------------------------+\n");
	printf("  | Opção inválida, tente novamente. |\n");  
	printf("  +----------------------------------+\n");
	printf("\n");
}

void Reiniciar()
{
	printf("  +-------------------------+\n");
	printf("  |  Deseja voltar ao menu  |\n");  
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