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
  float Notas[0][2];
  float MediaGeral;
};

struct Vaga
{
  char Titulo[MAX_STRING];
  char Requisitos[MAX_STRING];
  char FuncionarioResponsavel[MAX_STRING];
  int QuantidadeVagas;
  float Remuneracao;
  struct Pessoa Candidatos[10];
  int QuantidadeAlunosCandidatados;
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
int VerificaResultadoFinal();

struct Vaga vagas[MAX_LENGTH];

int controleVagas;
int controleCadastroAluno;
int controlenotasCadastradas;
int vagaEscolha;

#endif