/*
##       ########     ##                 ########  ########   #######        ## ########  ######  ######## 
##       ##     ##  ####                 ##     ## ##     ## ##     ##       ## ##       ##    ##    ##    
##       ##     ##    ##                 ##     ## ##     ## ##     ##       ## ##       ##          ##    
##       ########     ##      #######    ########  ########  ##     ##       ## ######   ##          ##    
##       ##           ##                 ##        ##   ##   ##     ## ##    ## ##       ##          ##    
##       ##           ##                 ##        ##    ##  ##     ## ##    ## ##       ##    ##    ##    
######## ##         ######               ##        ##     ##  #######   ######  ########  ######     ##    

*/

#include <stdlib.h>
#include <stdio.h>
#include "domain.h"

void Banner();
void CadastroDeFuncionarios(struct Pessoa funcionario);
void menuDoCoordenador();
void CadastroDeVagas(struct Vaga vaga);
void CadastroDeFuncionarios(struct Pessoa funcionario);

void menu()
{

  Banner();

  printf("\nDigite uma das opções para prosseguir:\n");
  printf("1 -> Coordenador <-\n");
  printf("2 -> Aluno <-\n");
  printf("3 -> Sair da aplicação <-\n");
  scanf("%d", &numero[0]);

  switch (numero[0])
  {
  case 1:
    menuDoCoordenador();
    break;
  case 3:
    exit(0);
    break;
  default:
    printf("\nOpção invalida");
  }
}

void menuDoCoordenador()
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
    scanf("%d", &numero[1]);

    struct Vaga vaginha;

    switch (numero[1])
    {
    case 1:
      CadastroDeVagas(vaginha);
    case 2:
      retornoAnterior = 0;
      system("clear");
      //ListarVagas();
      break;
    default:
      printf("\nOpção invalida");
    }
  }
}

void CadastroDeVagas(struct Vaga vaga)
{
  printf("\nDefina o titulo da vaga: ");
  fgets(vaga.Titulo, MAX_STRING, stdin);

  printf("\nDefina o quantitativo de vagas: ");
  scanf("%d", &vaga.Qtde);

  printf("\nInforme o funcionário que será responsável pela seleção: ");
  fgets(vaga.PessoaResponsavel.Nome, MAX_STRING, stdin);

  printf("\nQual o valor da remuneração: ");
  scanf("%f", &vaga.Remuneracao);

  // printf("\nDigite 1 para confirmar a inserção de uma nova vaga \nDigite 2 para cancelar a inserção de uma nova vaga");
  // scanf("%f", &vaga.Remuneracao);
}

void CadastroDeFuncionarios(struct Pessoa funcionario)
{

  printf("\n\nCadastro de funcionario.");

  printf("\n\nNome: ");
  fgets(funcionario.Nome, MAX_STRING, stdin);

  printf("\n\nCargo: ");
  fgets(funcionario.Cargo, MAX_STRING, stdin);
}

void Banner()
{
  printf("\n***************************\n");
  printf("\nUNIESP - Seleção de Estágio\n");
  printf("\n***************************\n");
}