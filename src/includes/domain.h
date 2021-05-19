/*
##       ########     ##                 ########  ########   #######        ## ########  ######  ######## 
##       ##     ##  ####                 ##     ## ##     ## ##     ##       ## ##       ##    ##    ##    
##       ##     ##    ##                 ##     ## ##     ## ##     ##       ## ##       ##          ##    
##       ########     ##      #######    ########  ########  ##     ##       ## ######   ##          ##    
##       ##           ##                 ##        ##   ##   ##     ## ##    ## ##       ##          ##    
##       ##           ##                 ##        ##    ##  ##     ## ##    ## ##       ##    ##    ##    
######## ##         ######               ##        ##     ##  #######   ######  ########  ######     ##    

*/

#ifndef DOMAIN_H
#define DOMAIN_H

#define MAX_STRING 100
#define MAX_LENGTH 100

struct Pessoa
{
  char Nome[MAX_STRING];
  float CRE;
  int Matricula;
  int Notas[1][3];
};

struct Vaga
{
  char Titulo[MAX_STRING];
  char Requisitos[MAX_STRING];
  char FuncionarioResponsavel[MAX_STRING];
  int QuantidadeVagas;
  float Remuneracao;
  struct Pessoa Candidatos[MAX_STRING];
};

void MenuPrincipal();
void Banner();
int CadastroDeNotasSelecao();
void MenuDoCoordenador();
void CadastroDeVagas();
int ListarVagas();
int CandidatarVagaSelecaoAluno();
void tratamentoReturno(int retornoFuncao, char mensagem[100]);
void MenuDoAluno();

struct Vaga vagas[MAX_LENGTH];

int controleVagas = 0;
int controleCadastroAluno = 0;

#endif