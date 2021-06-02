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

int main() {
    setlocale(LC_ALL, "Portuguese");

    while (1)
        MenuPrincipal();
}

void MenuPrincipal() {
    int selecaoMenuPrincial;
    Banner();
    printf("\nDigite uma das opções para prosseguir:\n");
    printf("1 -> Coordenador <-\n");
    printf("2 -> Aluno <-\n");
    printf("3 -> Sair da aplicação <-\n");
    scanf("%d", &selecaoMenuPrincial);

    switch (selecaoMenuPrincial) {
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

void MenuDoCoordenador() {
    int selecaoMenuCoordenador;
    int retornoAnteriorCoordenador = 1;

    while (retornoAnteriorCoordenador) {
        printf("\nDigite uma das opções para prosseguir:\n");
        printf("1 -> Cadastrar vagas <-\n");
        printf("2 -> Cadastro de notas da seleção <-\n");
        printf("3 -> Retornar Menu anterior <-\n");
        scanf("%d", &selecaoMenuCoordenador);

        switch (selecaoMenuCoordenador) {
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

void MenuDoAluno() {

    int selecaoMenuAluno;
    int retornoAnteriorAluno = 1;

    while (retornoAnteriorAluno) {
        printf("\nDigite uma das opções para prosseguir:\n");
        printf("1 -> Listar vagas disponiveis <-\n");
        printf("2 -> Candidatar-se a vaga de estágio <-\n");
        printf("3 -> Verificar resultado final da seleçao <-\n");
        printf("4 -> Importar Resultado para arquivo <-\n");
        printf("5 -> Retornar Menu anterior <-\n");
        scanf("%d", &selecaoMenuAluno);

        switch (selecaoMenuAluno) {
            case 1:
                tratamentoReturno(ListarVagas(), "Não Há vagas!!");
                break;
            case 2:
                CandidatarVagaSelecaoAluno();
                break;
            case 3:
                tratamentoReturno(VerificaResultadoFinal(), "Processo de seleçao nao terminado!!");
                break;
            case 4:
                importarArquivo();
                break;
            case 5:
                retornoAnteriorAluno = 0;
                system("clear");
                break;
            default:
                printf("\nOpção invalida");
        }
    }
}

int CandidatarVagaSelecaoAluno() {
    int numeroDaVaga;
    int controleSaida = 1;
    int verificaSeHaVagas = controleVagas;

    if (verificaSeHaVagas == 0) {
        return 1;
    }

    for (int contador = 0; contador < controleVagas; contador++) {
        printf("\n================= Mural de Vagas ===============================\n");
        printf("\nCandidatar-se para vaga do %d° estágio em: %s\n", contador + 1, vagas[contador].Titulo);
        printf("\nQuantidade de Vagas Disponiveis no %d° estágio: %d",
               contador + 1, vagas[contador].QuantidadeVagas);
        printf("\n================================================================\n");
    }

    while (controleSaida) {
        printf("\nInforme a posição no mural relacionado a vaga em que você deseja se candidatar:");
        scanf("%d", &numeroDaVaga);

        if (numeroDaVaga > controleVagas) {
            printf("\nVaga inexistente!!!\n");
        } else {
            controleSaida = 0;
        }

        numeroDaVaga--;
        if (controleSaida == 0) {
            if (vagas[numeroDaVaga].QuantidadeVagas == 0) {
                printf("\nVagas esgotadas para o estágio selecionado!!!\n");
                return 0;
            }
        }
    }

    flush_in();
    printf("\nInforme seu nome:");
    scanf("%[^\n]", vagas[numeroDaVaga].Candidatos[vagas[numeroDaVaga].QuantidadeAlunosCandidatados].Nome);

    printf("%s", vagas[numeroDaVaga].Candidatos[vagas[numeroDaVaga].QuantidadeAlunosCandidatados].Nome);
    printf("\nInforme seu CRE:");
    scanf("%f", &vagas[numeroDaVaga].Candidatos[vagas[numeroDaVaga].QuantidadeAlunosCandidatados].CRE);

    printf("\nInforme sua matricula:");
    scanf("%d",
          &vagas[numeroDaVaga].Candidatos[vagas[numeroDaVaga].QuantidadeAlunosCandidatados].Matricula);

    controleCadastroAluno++;
    vagas[numeroDaVaga].QuantidadeAlunosCandidatados++;

    return 0;
}

void CadastroDeVagas() {
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

int ListarVagas() {

    if (controleVagas == 0) {
        return 1;
    }

    for (int contador = 0; contador < controleVagas; contador++) {
        printf("\n======================================================================");
        printf("\nTitulo do %dº estágio: %s\n", contador + 1, vagas[contador].Titulo);
        printf("Requisitos do %dº estágio: %s\n", contador + 1, vagas[contador].Requisitos);
        printf("Funcionario responsável pelo %dº estágio: %s\n", contador + 1, vagas[contador].FuncionarioResponsavel);
        printf("Quantidade de vagas disponiveis no %dº estágio: %d\n", contador + 1, vagas[contador].QuantidadeVagas);
        printf("Remuneração do %dº estágio: %0.2f\n", contador + 1, vagas[contador].Remuneracao);
        printf("======================================================================\n");

        if (vagas[contador].Candidatos[0].CRE != 0) {

            for (int canditato = 0; canditato < vagas[contador].QuantidadeAlunosCandidatados; canditato++) {
                printf("%d° Canditado do %dº estágio: %s\n",
                       canditato + 1,
                       contador + 1,
                       vagas[contador].Candidatos[canditato].Nome);
            }
        }
    }

    return 0;
}

int CadastroDeNotasSelecao() {

    if (controleCadastroAluno == 0) {
        return 1;
    }

    int controleCadastroNotas;

    printf("\nDefinição de notas das etapas.\n");

    for (int contador = 0; contador < controleVagas; contador++) {
        printf("\n================= Mural de Vagas ===============================\n");
        printf("\nCandidatar-se para vaga do %d° estágio em: %s\n", contador + 1, vagas[contador].Titulo);
        printf("\nQuantidade de Vagas Disponiveis no %d° estágio: %d",
               contador + 1, vagas[contador].QuantidadeVagas);
        printf("\n================================================================\n");
    }

    printf("\nDefina qual processo deseja cadastrar as notas\n");
    scanf("%d", &controleCadastroNotas);

    for (int primeiraIteracao = 0;
         primeiraIteracao < sizeof(vagas[0].QuantidadeAlunosCandidatados); primeiraIteracao++) {
        printf("%s", vagas[0].Candidatos[primeiraIteracao].Nome);
    }

    for (int primeiraIteracao = 0; primeiraIteracao < controleCadastroNotas; primeiraIteracao++) {
        printf("%d Vaga de estágio: %s\n", primeiraIteracao + 1, vagas[primeiraIteracao].Titulo);

        for (int segundaIteracao = 0;
             segundaIteracao < vagas[primeiraIteracao].QuantidadeAlunosCandidatados; segundaIteracao++) {
            printf("%d° Aluno: %s\n",
                   segundaIteracao + 1,
                   vagas[primeiraIteracao].Candidatos[segundaIteracao].Nome);
            printf("CRE do %d° Aluno: %0.1f\n",
                   segundaIteracao,
                   vagas[primeiraIteracao].Candidatos[segundaIteracao].CRE);

            
            printf("\nDefinir nota da 1º etapa (parte escrita): ");
            scanf("%f", &vagas[primeiraIteracao].Candidatos[segundaIteracao].Notas[0][0]);

            printf("\nDefinir nota da 2º etapa (entrevista): ");
            scanf("%f", &vagas[primeiraIteracao].Candidatos[segundaIteracao].Notas[0][1]);

            printf("\nDefinir nota da 3º etapa (curriculum e CRE): ");
            scanf("%f", &vagas[primeiraIteracao].Candidatos[segundaIteracao].Notas[0][2]);

            vagas[primeiraIteracao].Candidatos[segundaIteracao].MediaGeral =
                    (vagas[primeiraIteracao].Candidatos[segundaIteracao].Notas[0][0] +
                     vagas[primeiraIteracao].Candidatos[segundaIteracao].Notas[0][1] +
                     vagas[primeiraIteracao].Candidatos[segundaIteracao].Notas[0][2]) /
                    3;
        }
    }
    controlenotasCadastradas++;
    return 0;
}

void Banner() {
    printf("\n----------------------------------------------------------");
    printf("\n               UNIESP - Seleção de Estágio                ");
    printf("\n----------------------------------------------------------\n");
}

void tratamentoReturno(int retornoFuncao, char mensagem[100]) {
    if (retornoFuncao == 1) {
        printf("\n%s\n", mensagem);
    } else {
        printf("");
    }
}

void flush_in() {
    int ch;

    while ((ch = fgetc(stdin)) != EOF && ch != '\n') {
    }
}

void importarArquivo() {

    char Str[100];
    int resultado;
    FILE *arq;

    arq = fopen("files/resultados.txt", "wt");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo\n");
    }

    for (int contador = 0; contador < controleVagas; contador++) {

        for (int contadorj = 0; contadorj < controleCadastroAluno; contadorj++) {

            resultado = fputs(vagas[contador].Candidatos[contadorj].Nome, arq);
        }

        if (resultado == EOF) {
            printf("Erro na Gravacao\n");
        }
    }

    fclose(arq);
}

int VerificaResultadoFinal() {
    struct Pessoa varAux;

    if (controlenotasCadastradas == 0) {
        return 1;
    }

    for (int contador = 0; contador < controleVagas; contador++) {
        printf("\n======================================================================");
        printf("\n%dº vaga de estágio: %s\n", contador + 1, vagas[contador].Titulo);
        printf("======================================================================\n");
    }

    printf("\nescolha o estagio que deseja verificar o resultado final: \n");
    scanf("%d", &vagaEscolha);

    for (int i = 0; i < controleCadastroAluno; ++i) {
        for (int j = i + 1; j < controleCadastroAluno; ++j) {
            if (vagas[vagaEscolha - 1].Candidatos[i].MediaGeral < vagas[vagaEscolha - 1].Candidatos[j].MediaGeral) {
                varAux = vagas[vagaEscolha - 1].Candidatos[i];
                vagas[vagaEscolha - 1].Candidatos[i] = vagas[vagaEscolha - 1].Candidatos[j];
                vagas[vagaEscolha - 1].Candidatos[j] = varAux;
            }
        }
    }

    printf("\n               Resultado Final                           ");
    for (int contador = 0; contador < controleCadastroAluno; contador++) {
        printf("\nCandidato: %s, Nota: %0.1f, Aprovado: %s \n",
               vagas[vagaEscolha - 1].Candidatos[contador].Nome,
               vagas[vagaEscolha - 1].Candidatos[contador].MediaGeral,
               vagas[vagaEscolha - 1].QuantidadeVagas > contador ? "Sim" : "Nao");
    }

    return 0;
}
