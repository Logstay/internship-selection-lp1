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

typedef struct Pessoa
{
  char Nome[MAX_STRING];
  char Cargo[MAX_STRING];
} funcionario;

struct Candidato
{
  char Nome[MAX_STRING];
  float Pnota;
  float Snota;
  float Tnota;
  float Qnota;
};

struct Vaga
{
  char Titulo[MAX_STRING];
  int Qtde;
  funcionario PessoaResponsavel;
  float Remuneracao;
  struct Candidato Candidatos[];
};

void MenuPrincipal();
void Banner();
void CadastroDeFuncionarios(funcionario f);
void MenuDoCoordenador();
void CadastroDeVagas();
void ListarVagas();

struct Vaga vaginha[100];

int selecao[1];
int controleVagas = 0;
int retornoAnterior = 1;

#endif