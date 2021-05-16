/*

##       ########     ##                 ########  ########   #######        ## ########  ######  ######## 
##       ##     ##  ####                 ##     ## ##     ## ##     ##       ## ##       ##    ##    ##    
##       ##     ##    ##                 ##     ## ##     ## ##     ##       ## ##       ##          ##    
##       ########     ##      #######    ########  ########  ##     ##       ## ######   ##          ##    
##       ##           ##                 ##        ##   ##   ##     ## ##    ## ##       ##          ##    
##       ##           ##                 ##        ##    ##  ##     ## ##    ## ##       ##    ##    ##    
######## ##         ######               ##        ##     ##  #######   ######  ########  ######     ##    

*/

/**
 * by: Kaique M. D. Lima and Mateus P. Jorge  
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
  int selecaoMenuPrincial;
  Banner();
  printf("\nDigite uma das opções para prosseguir:\n");
  printf("1 -> Coordenador <-\n");
  printf("2 -> Aluno <-\n");
  printf("3 -> Sair da aplicação <-\n");
  scanf("%d", &selecaoMenuPrincial);

  printf("SELECAO DOIDA%dDOIDA", selecaoMenuPrincial);

  switch (selecaoMenuPrincial)
  {
  case 1:
    MenuDoCoordenador();
    break;
  case 2:
    MenuDoAluno();
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
  int selecaoMenuCoordenador;
  int retornoAnteriorCoordenador = 1;

  while (retornoAnteriorCoordenador)
  {
    printf("\nDigite uma das opções para prosseguir:\n");
    printf("1 -> Cadastrar vagas <-\n");
    printf("2 -> Cadastro de notas da seleção <-\n");
    printf("3 -> Retornar Menu anterior <-\n");
    scanf("%d", &selecaoMenuCoordenador);

    switch (selecaoMenuCoordenador)
    {
    case 1:
      CadastroDeVagas();
      break;
    case 2:
      tratamentoReturno(CadastroDeNotasSelecao(), "Não há alunos cadastrados!!");
      break;
    case 3:
      retornoAnteriorCoordenador = 0;
      system("clear");
      break;
    default:
      printf("\nOpção invalida");
    }
  }
}

void MenuDoAluno()
{

  int selecaoMenuAluno;
  int retornoAnteriorAluno = 1;

  while (retornoAnteriorAluno)
  {
    printf("Digite uma das opções para prosseguir:\n");
    printf("1 -> Listar vagas disponiveis <-\n");
    printf("2 -> Candidatar-se a vaga de estágio <-\n");
    printf("3 -> Retornar Menu anterior <-\n");
    scanf("%d", &selecaoMenuAluno);

    switch (selecaoMenuAluno)
    {
    case 1:
      tratamentoReturno(ListarVagas(), "Não Há vagas!!");
      break;
    case 2:
      CandidatarVagaSelecaoAluno();
      break;
    case 3:
      retornoAnteriorAluno = 0;
      system("clear");
      break;
    default:
      printf("\nOpção invalida");
    }
  }
}

int CandidatarVagaSelecaoAluno()
{
  int numeroDaVaga;
  int controleSaida = 1;
  int verificaSeHaVagas = controleVagas;

  for (int contador = 0; contador < controleVagas; contador++)
  {
    printf("Vaga %d: %s\n", contador + 1, vagas[contador].Titulo);
  }

  if (verificaSeHaVagas == 0)
  {
    return 1;
  }

  while (controleSaida)
  {
    printf("\nInforme o número da vaga que você deseja se candidatar:");
    scanf("%d", &numeroDaVaga);

    if (numeroDaVaga > sizeof(vagas))
    {
      printf("Vaga inexistente!!!");
    }
    else
    {
      controleSaida = 0;
    }
  }

  printf("\nInforme seu nome:");
  scanf("%s", &vagas[numeroDaVaga].Candidatos[controleCadastroAluno].Nome);

  printf("\nInforme seu CRE:");
  scanf("%f", &vagas[numeroDaVaga].Candidatos[controleCadastroAluno].CRE);

  printf("\nInforme sua matricula:");
  scanf("%d", &vagas[numeroDaVaga].Candidatos[controleCadastroAluno].Matricula);

  controleCadastroAluno++;

  return 0;
}

void CadastroDeVagas()
{
  printf("\nDefina o titulo da vaga:");
  scanf("%s", &vagas[controleVagas].Titulo);

  printf("\nDefina os requisitos da vaga:");
  scanf("%s", &vagas[controleVagas].Requisitos);

  printf("\nDefina o quantitativo de vagas:");
  scanf("%d", &vagas[controleVagas].Qtde);

  printf("\nInforme o funcionário que será responsável pela seleção:");
  scanf("%s", &vagas[controleVagas].funcionarioResponsavel);

  printf("\nQual o valor da remuneração:");
  scanf("%f", &vagas[controleVagas].Remuneracao);

  controleVagas++;
}

int ListarVagas()
{
  printf("controle %d", controleVagas);

  for (int contador = 0; contador < controleVagas; contador++)
  {
    printf("\nTitulo da Vaga %d: %s\n", contador + 1, vagas[contador].Titulo);
    printf("Requisitos da Vaga %d: %s\n", contador + 1, vagas[contador].Requisitos);
    printf("Funcionario responsável pela vaga %d: %s\n", contador + 1, vagas[contador].funcionarioResponsavel);
    printf("Número de vagas %d: %d\n", contador + 1, vagas[contador].Qtde);
    printf("Remuneração da vaga %d: %0.2f\n", contador + 1, vagas[contador].Remuneracao);
  }

  if (controleVagas == 0)
  {
    return 1;
  }

  return 0;
}

int CadastroDeNotasSelecao()
{
  int primeiraIteracao = 0;
  int segundaIteracao = 0;

  for (primeiraIteracao; primeiraIteracao < controleVagas; primeiraIteracao++)
  {
    for (segundaIteracao; segundaIteracao < primeiraIteracao; segundaIteracao++)
    {
      printf("Alunos %d: %s\n", primeiraIteracao + 1, vagas[primeiraIteracao].Candidatos[segundaIteracao].Nome);
    }
  }

  if (controleCadastroAluno == 0)
  {
    return 1;
  }

  return 0;
}

void Banner()
{
  printf("\n----------------------------------------------------------");
  printf("\n               UNIESP - Seleção de Estágio                ");
  printf("\n----------------------------------------------------------\n");
}

void tratamentoReturno(int retornoFuncao, char mensagem[100])
{
  (retornoFuncao == 1)
      ? printf("\n%s\n", mensagem)
      : "";
}