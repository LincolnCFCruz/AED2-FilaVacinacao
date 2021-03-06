# Trabalho - Fila de Vacinação

![Main](https://raw.githubusercontent.com/LincolnCFCruz/Trabalho-Fila-de-Vacinacao/main/Imagens/Menu.png)

<p align="center">
<img src="https://img.shields.io/github/repo-size/LincolnCFCruz/Trabalho-Fila-de-Vacinacao?label=Tamanho&style=flat-square">
<img src="https://img.shields.io/github/languages/count/LincolnCFCruz/Trabalho-Fila-de-Vacinacao?label=Linguagens&style=flat-square">
<img src="https://img.shields.io/github/issues/LincolnCFCruz/Trabalho-Fila-de-Vacinacao?label=Problemas&style=flat-square">
<img src="https://img.shields.io/github/last-commit/LincolnCFCruz/Trabalho-Fila-de-Vacinacao?label=%C3%9Altimo%20commit&style=flat-square">
</p>


## Links úteis
[Painel Coronavírus](https://covid.saude.gov.br/) | [Saúde / Gov.br](https://coronavirus.saude.gov.br/) | [Vacinação Minas Gerais](https://vacinaminas.mg.gov.br/)

## Objetivo:
 O programa 'Vacinação contra COVID-19' tem o objetivo de aprimorar nossas habilidades em torno do uso de ponteiros e arranjos, na disciplina de AEDII.
## Partipantes:
 - Lincoln Corrêa Figueiredo Cruz | [LincolnCFCruz](https://github.com/LincolnCFCruz)
 - Pedro Igor Martins dos Reis | [ORZAYAZ](https://github.com/ORZAYAZ)
 - Rafaela Mesquita Gontijo | [rafamesquita](https://github.com/rafamesquita)
 - Rafael Brandão Nunes | [RafaelBrandao13](https://github.com/RafaelBrandao13)

## Professor:
 - Kleber Souza | [ProfKleberSouza](https://github.com/ProfKleberSouza)
## Referência:
[Canvas PUC Minas](https://pucminas.instructure.com/courses/53903/assignments/265771)

## Requisitos:
 - Windows → [MinGW](https://sourceforge.net/projects/mingw/)
 - Linux → GCC
 ```
 # Sistemas baseados no Debian
 sudo apt install -y gcc git cmake
 # Sistemas baseados no RHEL
 sudo dnf install -y gcc git cmake
 # Sistemas baseados no Arch Linux
 sudo pacman -S gcc git cmake
 # Void Linux
 sudo xbps-install -S gcc git cmake
 # Solus OS
 sudo eopkg install gcc git cmake
```
## Como executar:
```
git clone https://github.com/LincolnCFCruz/Trabalho-Fila-de-Vacinacao

Para a versão de ponteiros:
cd Trabalho-Fila-de-Vacinacao/Fonte/Ponteiro/
gcc -o Main Vacina.c Main.c
./Main

Para a versão de arranjos:
cd Trabalho-Fila-de-Vacinacao/Fonte/Arranjos/
gcc -o Main Vacina.c Main.c
./Main
```
## Contribuições
```
+---------------------------------+---------------------------------------+
| Pedro Igor Martins dos Reis     | Desenvolveram a versão em Ponteiros   |
+---------------------------------+ de ponteiros do projeto e a aparência |
| Rafaela Mesquita Gontijo        | do programa.                          |
+---------------------------------+---------------------------------------+
| Lincoln Corrêa Figueiredo Cruz  | Desenvolveram a versão em Arranjos    |
+---------------------------------+ do projeto e auxiliaram na parte      |
| Rafael Brandão Nunes            | de prioridade da fila                 |
+---------------------------------+---------------------------------------+
```
## Exemplo de fila:
![Output](https://raw.githubusercontent.com/LincolnCFCruz/Trabalho-Fila-de-Vacinacao/main/Imagens/Lista.png)

