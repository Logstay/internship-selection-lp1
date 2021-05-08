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

void menu()
{

  printf("\n\nDigite o numero 1 para selecionar: ");
  scanf("%d", &menuOption);

  switch (menuOption)
  {
  case 1:
    Test();
    break;
  default:
    printf("\nOpção invalida");
  }
}

void Test()
{
  printf("\nMinha Função TEST\n");
}

#endif