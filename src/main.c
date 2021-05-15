/*
##       ########     ##                 ########  ########   #######        ## ########  ######  ######## 
##       ##     ##  ####                 ##     ## ##     ## ##     ##       ## ##       ##    ##    ##    
##       ##     ##    ##                 ##     ## ##     ## ##     ##       ## ##       ##          ##    
##       ########     ##      #######    ########  ########  ##     ##       ## ######   ##          ##    
##       ##           ##                 ##        ##   ##   ##     ## ##    ## ##       ##          ##    
##       ##           ##                 ##        ##    ##  ##     ## ##    ## ##       ##    ##    ##    
######## ##         ######               ##        ##     ##  #######   ######  ########  ######     ##    

*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "includes/domain.h"

int main()
{
  setlocale(LC_ALL, "Portuguese");

  while (1)
  {
    MenuPrincipal();
  }

  return 0;
}

void MenuPrincipal()
{
  Banner();
  printf("\nDigite uma das opções para prosseguir:\n");
  printf("1 -> Coordenador <-\n");
  printf("2 -> Aluno <-\n");
  printf("3 -> Sair da aplicação <-\n");
  scanf("%d", &selecao[0]);

  switch (selecao[0])
  {
  case 1:
    MenuDoCoordenador();
    break;
  case 3:
    exit(0);
    break;
  default:
    printf("\nOpção invalida");
  }
}

void MenuDoCoordenador()
{
  int retornoAnterior = 1;

  while (retornoAnterior)
  {
    system("clear");
    Banner();
    printf("\nDigite uma das opções para prosseguir:\n");
    printf("1 -> Cadastrar vagas <-\n");
    printf("2 -> Gerar relatório de aprovados <-\n");
    printf("3 -> Sair da aplicação <-\n");
    scanf("%d", &selecao[1]);

    vagazinha vaginha[5];

    switch (selecao[1])
    {
    case 1:
      CadastroDeVagas(vaginha[0]);
      break;
    case 3:
      retornoAnterior = 0;
      system("clear");
      break;
    default:
      printf("\nOpção invalida");
    }
  }
}

void CadastroDeVagas(vagazinha v)
{
  printf("\nDefina o titulo da vaga: ");
  fgets(v.Titulo, MAX_STRING, stdin);

  printf("\nDefina o quantitativo de vagas: ");
  scanf("%d", &v.Qtde);

  printf("\nInforme o funcionário que será responsável pela seleção: ");
  fgets(v.PessoaResponsavel.Nome, MAX_STRING, stdin);

  printf("\nQual o valor da remuneração: ");
  scanf("%f", &v.Remuneracao);
}

void CadastroDeFuncionarios(funcionario f)
{

  printf("\n\nCadastro de funcionario.");

  printf("\n\nNome: ");
  fgets(f.Nome, MAX_STRING, stdin);

  printf("\n\nCargo: ");
  fgets(f.Cargo, MAX_STRING, stdin);
}

void Banner()
{
  printf("\n***************************\n");
  printf("\nUNIESP - Seleção de Estágio\n");
  printf("\n***************************\n");
}