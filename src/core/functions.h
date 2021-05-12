/*
##       ########     ##                 ########  ########   #######        ## ########  ######  ######## 
##       ##     ##  ####                 ##     ## ##     ## ##     ##       ## ##       ##    ##    ##    
##       ##     ##    ##                 ##     ## ##     ## ##     ##       ## ##       ##          ##    
##       ########     ##      #######    ########  ########  ##     ##       ## ######   ##          ##    
##       ##           ##                 ##        ##   ##   ##     ## ##    ## ##       ##          ##    
##       ##           ##                 ##        ##    ##  ##     ## ##    ## ##       ##    ##    ##    
######## ##         ######               ##        ##     ##  #######   ######  ########  ######     ##    

*/

#ifndef FUNCTION_H

#include <stdlib.h>
#include <stdio.h>
#include "domain.h"

void Test();
void CadastroDeFuncionarios(struct Pessoa funcionario);
void menuDoCoordenador();
void CadastroDeVagas(struct Vaga vaga);
void CadastroDeFuncionarios(struct Pessoa funcionario);

void menu()
{

  printf("\n\nDigite o numero 1 para selecionar: ");
  scanf("%d", &menuOption);

  switch (menuOption)
  {
  case 1:
    menuDoCoordenador();
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

    printf("\n\nMENU COORDENADOR");
    printf("\n\nDigite o número para acionar uma ação: ");
    scanf("%d", &menuOption);

    struct Vaga vaginha;

    switch (menuOption)
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
  scanf("%s", &vaga.Titulo);

  printf("\nDefina o quantitativo de vagas: ");
  scanf("%d", &vaga.Qtde);

  printf("\nInforme o funcionário que será responsável pela seleção: ");
  scanf("%s", &vaga.PessoaResponsavel.Nome);

  printf("\nQual o valor da remuneração: ");
  scanf("%f", &vaga.Remuneracao);

  // printf("\nDigite 1 para confirmar a inserção de uma nova vaga \nDigite 2 para cancelar a inserção de uma nova vaga");
  // scanf("%f", &vaga.Remuneracao);
}

// void ListarVagas()
// {
//   for (size_t i = 0; i = < vagas; i++)
//   {
//     printf(" \n O nome da vaga é: %d ", func[i].nome);
//   }
// }

void CadastroDeFuncionarios(struct Pessoa funcionario)
{

  printf("\n\nCadastro de funcionario.");

  printf("\n\nNome: ");
  scanf("%s", &funcionario.Nome);

  printf("\n\nCargo: ");
  scanf("%s", &funcionario.Cargo);
}

void Test()
{
  printf("\nMinha Função TEST\n");
}

// 1 2 3 4 5 for (i = 0; i < 10; i++)
// {
//   strcpy(func[i].nome, "NULL");
//   func[i].idade = 0;
//   func[i].salario = 0.0;
// }

#endif