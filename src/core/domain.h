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

#define MAX_STRING 100

struct Pessoa
{
  char Nome[MAX_STRING];
  char Cargo[MAX_STRING];
};

struct Vaga
{
  char Titulo[MAX_STRING];
  int Qtde;
  struct Pessoa PessoaResponsavel;
  float Remuneracao;
};

int numero[1];
