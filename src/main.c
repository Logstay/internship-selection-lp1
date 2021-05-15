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

  while (retornoAnterior)
  {
    Banner();
    printf("\nDigite uma das opções para prosseguir:\n");
    printf("1 -> Cadastrar vagas <-\n");
    printf("2 -> Gerar relatório de aprovados <-\n");
    printf("3 -> Mostrar vagas de estágio <-\n");
    printf("4 -> Sair da aplicação <-\n");
    scanf("%d", &selecao[1]);

    switch (selecao[1])
    {
    case 1:
      CadastroDeVagas();
      break;
    case 2:
      // Relatorio
      break;
    case 3:
      ListarVagas();
      break;
    case 4:
      retornoAnterior = 0;
      system("clear");
      break;
    default:
      printf("\nOpção invalida");
    }
  }
}

void CadastroDeVagas()
{
  printf("\nDefina o titulo da vaga:");
  scanf(" %s", &vaginha[controleVagas].Titulo);

  printf("\nDefina o quantitativo de vagas:");
  scanf(" %d", &vaginha[controleVagas].Qtde);

  printf("\nInforme o funcionário que será responsável pela seleção:");
  scanf(" %s", &vaginha[controleVagas].PessoaResponsavel.Nome);

  printf("\nQual o valor da remuneração:");
  scanf(" %f", &vaginha[controleVagas].Remuneracao);

  controleVagas++;
}

void ListarVagas()
{
  for (int contador = 0; contador < controleVagas; contador++)
  {
    printf("Titulo da Vaga %d: %s\n", contador + 1, vaginha[contador].Titulo);
    printf("Número de vagas %d: %d\n", contador + 1, vaginha[contador].Qtde);
    printf("Funcionario responsável pela vaga %d: %s\n", contador + 1, vaginha[contador].PessoaResponsavel.Nome);
    printf("Remuneração da vaga %d: %0.2f\n", contador + 1, vaginha[contador].Remuneracao);
  }
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