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
  int Notas[0][2];
};

struct Vaga
{
  char Titulo[MAX_STRING];
  char Requisitos[MAX_STRING];
  char FuncionarioResponsavel[MAX_STRING];
  int QuantidadeVagas;
  float Remuneracao;
  struct Pessoa Candidatos[MAX_STRING];
  int QuantidadeAlunosCadidatados;
};

void MenuPrincipal();
void Banner();
void CadastroDeVagas();
void MenuDoCoordenador();
void tratamentoReturno(int retornoFuncao, char mensagem[100]);
void MenuDoAluno();
void flush_in();
int CadastroDeNotasSelecao();
int ListarVagas();
int CandidatarVagaSelecaoAluno();
void importarArquivo();

struct Vaga vagas[MAX_LENGTH];

int controleVagas = 0;
int controleCadastroAluno = 0;

#endif