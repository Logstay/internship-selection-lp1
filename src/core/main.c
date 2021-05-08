#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "domain.h"
#include "functions.h"

int main()
{
  setlocale(LC_ALL, "Portuguese");

  printf("Digite 1 para iniciar: ");
  scanf("%f", &numero[0]);

  while (1)
  {

    menu();

    printf("\nDigite qualque tecla para continuar.\n");
    fflush(stdin);
    getchar();
  }

  return 0;
}
