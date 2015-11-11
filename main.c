/*
 * *=*= PROGRAMA PRINCIPAL DO SIMULADOR DE SISTEMA COM GERENTE DE MEMÓRIA =*=*=
 *Arquivo : prog_ff.c criado em 5 de Novembro de 2015, às 12 : 00.
 * Autoras :
 * ----------------------------------
 * -> Daniela Brazão Maksoud
 * -> Curso : Ciência da Computação
 * -> Matrícula : 1321873
 * ----------------------------------
 * -> Thaíssa Falbo
 * -> Curso : Engenharia da Computação
 * -> Matrícula : 1421110
 * ----------------------------------
 * Professor : Luiz Fernando Bessa Seibel
 * Instituição : Pontifícia Universidade Católica do Rio de Janeiro
 * Disciplina : Sistemas de Computação(INF1019)
 */

/* Pré-processamento */

#include "definitions.h"    /* Arquivo de header com definições (includes e defines) */
#include "utilities.h"      /* Arquivo de header com utilitários (funções auxiliares) */

/* Função principal */

int main(void) {

    /* ------------------------------------------------- */
    /* PARTE 1: Declaração de variáveis locais da main   */
    /* ------------------------------------------------- */

    int fd[2]; /* Descritores de arquivos dos pipes.
                * fd[0] = Leitura
                * fd[1] = Escrita */
    int outputfd; /* Descritor de arquivos abertos = Retorno de open */
    int retorno; /* Valor de retorno de dup */
    int retorno2; /* Valor de retorno de dup2 */
    int i = 0, j = 0, w = 0, l = 0, m; /* Contadores auxiliares */
    int numero_processo; /* Número do processo */
    int tamanho_processo; /* Memória requerida pelo processo */
    int qtd_info_processo; /* Total de entradas que descrevem a execução do processo */
    int tempo_execucao; /* Tempo de execução do processo */
    int tempo_espera; /* Tempo de operação de entrada e saída 1 do processo */
    char id; /* Identificador para leitura do arquivo de entrada */
    int qtd_processos_; /* Quantidade de processos */

    /* ------------------------------------------------- */
    /* PARTE 2: Abertura do arquivo de entrada           */
    /* ------------------------------------------------- */

    /* Tratamento de erro para abertura do arquivo 'entrada.txt' */
    if ((outputfd = open("files/entrada.txt", O_RDONLY, 0666)) == -1) {
        showError("Falha na abertura do arquivo 'entrada.txt'.\n", ERR_FOPEN);
        fflush(stdout); // Flush do buffer.
    }

    /* ------------------------------------------------- */
    /* PARTE 3: Redirecionamento da entrada padrão       */
    /* ------------------------------------------------- */

    close(0); /* Fechamento da entrada stdin (teclado). */

    /* Tratamento de erro para duplicação de stdin */
    if ((retorno = dup(outputfd)) == -1) {
        /* Duplicação de stdin (menor descritor fechado) */
        showError("Falha na duplicação de stdin.\n", ERR_DUP);
        fflush(stdout); // Flush do buffer.
    }

    /* ------------------------------------------------- */
    /* PARTE 4: Abertura do arquivo de saída             */
    /* ------------------------------------------------- */

    /* Tratamento de erro para abertura do arquivo 'saida_lp.txt' */
    if ((outputfd = open("files/saida_ff.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1) {
        showError("Falha na abertura do arquivo 'saida.txt'.\n", ERR_FOPEN);
        fflush(stdout); // Flush do buffer.
    }

    /* ------------------------------------------------- */
    /* PARTE 5: Redirecionamento da saída padrão         */
    /* ------------------------------------------------- */

    close(1); /* Fechamento da saída stdout (monitor). */

    /* Tratamento de erro para duplicação de stdout */
    if ((retorno2 = dup2(outputfd, 1)) == -1) {
        /* Duplicação de stdout. */
        showError("Falha na duplicação de stdout.\n", ERR_DUP2);
        fflush(stdout); // Flush do buffer.
    }

    /* ------------------------------------------------- */
    /* PARTE 6: Exibição da mensagem inicial             */
    /* ------------------------------------------------- */

    cabecalho();

    /* ------------------------------------------------- */
    /* PARTE 7: Leitura do arquivo de entrada            */
    /* ------------------------------------------------- */

    scanf("%d [^\n]", &qtd_processos_); /* Lê a quantidade de processos */
    printf("Quantidade de processos: %d\n\n", qtd_processos_);
    fflush(stdout); // Flush do buffer.

    for (i = 0; i < qtd_processos_; i++) {
        scanf("Processo #%d – %dMb [^\n]", &numero_processo, &tamanho_processo);
        processo[i].numero = numero_processo;
        processo[i].tamanho = tamanho_processo;
        printf("Número do processo: #%d\n", processo[i].numero);
        printf("Tamanho do processo: %dMb\n", processo[i].tamanho);
        scanf("%d [^\n]", &qtd_info_processo);
        processo[i].qtd_info = qtd_info_processo;
        for (j = 0; j < processo[i].qtd_info; j++) {
            scanf("%1c", &id);
            switch (id) {
                case 'e':
                    scanf("xec %d [^\n]", &tempo_execucao);
                    info[i + 3 * w].numero_processo = numero_processo;
                    info[i + 3 * w].tempo_execucao = tempo_execucao;
                    printf("Tempo de execução %d: %ds\n", l + 1, info[i + 3 * w].tempo_execucao);
                    l++;
                    break;

                case'i':
                    scanf("o %d [^\n]", &tempo_espera);
                    info[i + 3 * w].numero_processo = numero_processo;
                    info[i + 3 * w].tempo_espera = tempo_espera;
                    printf("Tempo de espera %d: %ds\n", m + 1, info[i + 3 * w].tempo_espera);
                    m++;
                    break;

                default:
                    showError("Entrada inválida.", ERR_INPUT);
            }
        }
        printf("\n\n");
        l = 0;
        m = 0;
    }

    return 0; /* Sucesso */
}


