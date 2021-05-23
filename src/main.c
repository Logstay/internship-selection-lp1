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
    MenuPrincipal();
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
    printf("\nDigite uma das opções para prosseguir:\n");
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
    case 4:
      importarArquivo();
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

  if (verificaSeHaVagas == 0)
  {
    return 1;
  }

  for (int contador = 0; contador < controleVagas; contador++)
  {
    printf("Candidatar-se para vaga do %d estágio em: %s\n", contador + 1, vagas[contador].Titulo);
  }

  while (controleSaida)
  {
    printf("\nInforme o número da vaga que você deseja se candidatar:");
    scanf("%d", &numeroDaVaga);

    if (numeroDaVaga > controleVagas)
    {
      printf("\nVaga inexistente!!!\n");
    }
    else
    {
      controleSaida = 0;
    }

    numeroDaVaga--;
    if (controleSaida == 0)
    {
      printf("quantidade %d", vagas[numeroDaVaga].QuantidadeVagas);
      if (vagas[numeroDaVaga].QuantidadeVagas == 0)
      {
        printf("\nQuantidade de vagas esgotadas!!!\n");
        return 0;
      }
    }
  }

  flush_in();
  printf("\nInforme seu nome:");
  scanf("%[^\n]", vagas[numeroDaVaga].Candidatos[vagas[numeroDaVaga].QuantidadeAlunosCadidatados].Nome);

  printf("\nInforme seu CRE:");
  scanf("%f", &vagas[numeroDaVaga].Candidatos[vagas[numeroDaVaga].QuantidadeAlunosCadidatados].CRE);

  printf("\nInforme sua matricula:");
  scanf("%d", &vagas[numeroDaVaga].Candidatos[vagas[numeroDaVaga].QuantidadeAlunosCadidatados].Matricula);

  vagas[numeroDaVaga].QuantidadeVagas--;

  controleCadastroAluno++;
  vagas[numeroDaVaga].QuantidadeAlunosCadidatados++;

  return 0;
}

void CadastroDeVagas()
{
  flush_in();
  printf("\nDefina o titulo da vaga: ");
  scanf("%[^\n]", vagas[controleVagas].Titulo);

  flush_in();
  printf("\nDefina os requisitos da vaga:");
  scanf("%[^\n]", vagas[controleVagas].Requisitos);

  printf("\nDefina o quantitativo de vagas:");
  scanf("%d", &vagas[controleVagas].QuantidadeVagas);

  flush_in();
  printf("\nInforme o funcionário que será responsável pela seleção:");
  scanf("%[^\n]", vagas[controleVagas].FuncionarioResponsavel);

  printf("\nQual o valor da remuneração:");
  scanf("%f", &vagas[controleVagas].Remuneracao);

  controleVagas++;
}

int ListarVagas()
{

  if (controleVagas == 0)
  {
    return 1;
  }

  for (int contador = 0; contador < controleVagas; contador++)
  {
    printf("\n======================================================================");
    printf("\nTitulo do %dº estágio: %s\n", contador + 1, vagas[contador].Titulo);
    printf("Requisitos do %dº estágio: %s\n", contador + 1, vagas[contador].Requisitos);
    printf("Funcionario responsável pelo %dº estágio: %s\n", contador + 1, vagas[contador].FuncionarioResponsavel);
    printf("Quantidade de vagas disponiveis no %dº estágio: %d\n", contador + 1, vagas[contador].QuantidadeVagas);
    printf("Remuneração do %dº estágio: %0.2f\n", contador + 1, vagas[contador].Remuneracao);
    printf("======================================================================\n");

    if (vagas[contador].Candidatos[0].CRE != 0)
    {

      for (int j = 0; j < vagas[contador].QuantidadeAlunosCadidatados; j++)
      {
        printf("Canditados do %dº estágio: %s\n", contador + 1, vagas[contador].Candidatos[j].Nome);
      }
    }
  }

  return 0;
}

int CadastroDeNotasSelecao()
{

  if (controleCadastroAluno == 0)
  {
    return 1;
  }

  printf("\nDefinição de notas das etapas.\n");
  for (int primeiraIteracao = 0; primeiraIteracao < controleVagas; primeiraIteracao++)
  {
    printf("Vaga de estágio: %s\n", primeiraIteracao + 1, vagas[primeiraIteracao].Titulo);

    for (int segundaIteracao = 0; segundaIteracao < controleCadastroAluno; segundaIteracao++)
    {
      printf("Aluno: %s\n", primeiraIteracao + 1, vagas[primeiraIteracao].Candidatos[segundaIteracao].Nome);
      printf("CRE do Aluno: %s\n", primeiraIteracao + 1, vagas[primeiraIteracao].Candidatos[segundaIteracao].CRE);

      printf("\nDefinir nota da 1º etapa: ");
      scanf("%d", &vagas[primeiraIteracao].Candidatos[segundaIteracao].Notas[0][0]);

      printf("\nDefinir nota da 2º etapa: ");
      scanf("%d", &vagas[primeiraIteracao].Candidatos[segundaIteracao].Notas[0][1]);

      printf("\nDefinir nota da 3º etapa: ");
      scanf("%d", &vagas[primeiraIteracao].Candidatos[segundaIteracao].Notas[0][2]);
    }
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
  if (retornoFuncao == 1)
  {
    printf("\n%s\n", mensagem);
  }
  else
  {
    printf("");
  }
}

void flush_in()
{
  int ch;

  while ((ch = fgetc(stdin)) != EOF && ch != '\n')
  {
  }
}

void importarArquivo()
{
  int controleIteracao = 1;

  char Str[100];
  int resultado;
  FILE *arq;

  while (controleIteracao)
  {

    arq = fopen("files/arquivo.txt", "wt");

    if (arq == NULL)
    { //verifica se ocorreu erro
      printf("Erro ao abrir o arquivo\n");
    }
    else
    {

      controleIteracao = 0;
    }

    strcpy(Str, ">>>TRABALHAR<<<<");
    resultado = fputs(Str, arq);

    if (resultado == EOF)
    { //verifica se ocorreu erro
      printf("Erro na Gravacao\n");
    }
  }

  fclose(arq);
}