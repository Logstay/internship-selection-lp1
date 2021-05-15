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

typedef struct Vaga
{
  char Titulo[MAX_STRING];
  int Qtde;
  funcionario PessoaResponsavel;
  float Remuneracao;
} vagazinha;

void MenuPrincipal();
void Banner();
void CadastroDeFuncionarios(funcionario f);
void MenuDoCoordenador();
void CadastroDeVagas(vagazinha v);

int selecao[1];

#endif