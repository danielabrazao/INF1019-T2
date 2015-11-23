/*
 * -----------------------------------------------------------------
 * ~ PROGRAMA PRINCIPAL DO SIMULADOR DE GERENCIADOR DE MEMÓRIA
 * -----------------------------------------------------------------
 * 
 *  Descrição: Arquivo de código fonte contendo o programa principal.
 *  Arquivo: main.c criado em 5 de Novembro de 2015, às 12:00.
 *  Professor: Luiz Fernando Bessa Seibel
 *  Instituição: Pontifícia Universidade Católica do Rio de Janeiro
 *  Disciplina: Sistemas de Computação (INF1019)
 *  Autoras: 
 * - - - - - - - - - - - - - - - - - - - - - - - - -
 *  -> Daniela Brazão Maksoud
 *  -> Curso: Ciência da Computação
 *  -> Matrícula: 1321873
 * - - - - - - - - - - - - - - - - - - - - - - - - -
 *  -> Thaíssa Falbo
 *  -> Curso: Engenharia da Computação
 *  -> Matrícula: 1421110
 * - - - - - - - - - - - - - - - - - - - - - - - - -
 * 
 *  Este arquivo é parte do programa principal do Simulador de Gerenciador 
 *  de Memória.
 *
 *  O Simulador de Gerenciador de Memória é um software livre; você 
 *  pode redistribuí-lo e/ou modificá-lo dentro dos termos da Licença 
 *  Pública Geral GNU como publicada pela Fundação do Software Livre 
 *  (FSF); na versão 3 da Licença.
 *
 *  Este programa é distribuído na esperança de que possa ser útil, 
 *  mas SEM NENHUMA GARANTIA; sem uma garantia implícita de ADEQUAÇÃO
 *  a qualquer MERCADO ou APLICAÇÃO EM PARTICULAR. Veja a
 *  Licença Pública Geral GNU para maiores detalhes.
 *
 *  Você deve ter recebido uma cópia da Licença Pública Geral GNU junto
 *  com este programa, Se não, veja <http://www.gnu.org/licenses/>.
 * 
 */

/* Pré-processamento */

#include "definitions.h"    /* Arquivo de header com definições (includes e defines) */
#include "utilities.h"      /* Arquivo de header com utilitários (funções auxiliares) */

int main(void) {

    /* ------------------------------------------------- */
    /* PARTE 1: Declaração de variáveis locais da main   */
    /* ------------------------------------------------- */

    int outputfd; /* Descritor de arquivos abertos = Retorno de open */
    int retorno; /* Valor de retorno de dup */
    int i = 0, j = 0, m = 1, l = 1, n = 1; /* Contadores auxiliares */
    int numero_processo; /* Número do processo */
    int tamanho_processo; /* Memória requerida pelo processo */
    int qtd_info_processo; /* Total de entradas que descrevem a execução do processo */
    int id; /* Identificador do algoritmo de alocação escolhido */
    int tempo; /* Tempo de execução ou de espera */
    char s[5]; /* Nome da informação do processo (exec ou io) */
    int qtd_processos = 0; /* Quantidade de processos */
    int tempo_total = 0; /* Tempo total de todos os processos */
    processo * p_processo; /* Ponteiro para processo */
    mem *M; /* Memória */

    /* Declaração da fila de processos prontos */
    
    LIS_tppLista fila_prontos;

    fila_prontos = LIS_CriarLista(DestroiProcesso);
    
    /* Declaração da fila de processos bloqueados */
    
    LIS_tppLista fila_bloqueados;

    fila_bloqueados = LIS_CriarLista(DestroiProcesso);

    /* ------------------------------------------------- */
    /* PARTE 2: Exibição do cabeçalho                    */
    /* ------------------------------------------------- */

    Cabecalho();
    EsperaEnter();

    /* ------------------------------------------------- */
    /* PARTE 3: Abertura do arquivo de entrada           */
    /* ------------------------------------------------- */

    /* Tratamento de erro para abertura do arquivo 'entrada.txt' */
    if ((outputfd = open("files/entrada.txt", O_RDONLY, 0666)) == -1) {
        ShowError("Falha na abertura do arquivo 'entrada.txt'.\n", ERR_FOPEN);
    }

    /* ------------------------------------------------- */
    /* PARTE 4: Redirecionamento da entrada padrão       */
    /* ------------------------------------------------- */

    close(0); /* Fechamento da entrada stdin (teclado) */

    /* Tratamento de erro para duplicação de stdin */
    if ((retorno = dup(outputfd)) == -1) {
        /* Duplicação de stdin (menor descritor fechado) */
        ShowError("Falha na duplicação de stdin.\n", ERR_DUP);
    }

    /* ------------------------------------------------- */
    /* PARTE 5: Leitura do arquivo de entrada            */
    /* ------------------------------------------------- */

    printf("-----------------------------------------------------------------------------------\n\n");
    printf(ANSI_COLOR_MAGENTA "LEITURA DO ARQUIVO DE ENTRADA:" ANSI_COLOR_RESET "\n\n");
    printf("-----------------------------------------------------------------------------------\n\n");
    
    AguardaLeitura(2);
    
    scanf("%d [^\n]", &qtd_processos); /* Lê a quantidade de processos */
    printf("- " ANSI_COLOR_CYAN "Número total de processos" ANSI_COLOR_RESET ": %d\n\n", qtd_processos);
    
    AguardaLeitura(5);

    /* Percorre todos os processos */
    for (i = 0; i < qtd_processos; i++) {

        /* Aloca memória para o processo */
        p_processo = (processo*) malloc(sizeof (processo));

        /* Tratamento de erro para alocação de memória */
        if (p_processo == NULL) {
            ShowError("Falha ao alocar memória para um processo.\n", ERR_MALLOC);
        }

        /* Preenche dados do processo */
        p_processo->tempo_total = 0; // Inicializa o tempo total de cada processo como zero.

        scanf("Processo #%d – %dMb [^\n]", &numero_processo, &tamanho_processo); /* Lê o número identificador do processo e o seu tamanho em Mb */
        p_processo->numero = numero_processo;
        p_processo->tamanho = tamanho_processo;

        /* Imprime dados sobre o processo */
        printf("-----------------------------------\n");
        printf(ANSI_COLOR_MAGENTA "PROCESSO #%d\n" ANSI_COLOR_RESET, p_processo->numero);
        printf("-----------------------------------\n");
        printf("- " ANSI_COLOR_CYAN "Número do processo" ANSI_COLOR_RESET ": %d\n", p_processo->numero);
        printf("- " ANSI_COLOR_CYAN "Tamanho do processo" ANSI_COLOR_RESET ": %dMb\n", p_processo->tamanho);
        printf("-----------------------------------\n");

        scanf("%d [^\n]", &qtd_info_processo); /* Lê a quantidade de informações do processo */
        p_processo->qtd_info = qtd_info_processo;

        /* Aloca memória para um vetor de informações do processo */
        p_processo->infos = (info*) malloc(sizeof (info) * qtd_info_processo);

        /* Tratamento de erro para alocação de memória */
        if (p_processo->infos == NULL) {
            ShowError("Falha ao alocar memória para o vetor de informações do processo.\n", ERR_MALLOC);
        }

        /* Percorre todas as informações do processo */
        for (j = 0; j < p_processo->qtd_info; j++) {
            scanf("%s %d [^\n]", s, &tempo); /* Lê o nome da informação (exec ou io) e o tempo de execução ou de espera */
            strcpy(p_processo->infos[j].nome, s);
            p_processo->infos[j].tempo = tempo;
            p_processo->tempo_total = p_processo->tempo_total + tempo;
            p_processo->infos[j].ativo = FALSE;
            tempo_total = tempo_total + tempo; /* Tempo total de todos os processos juntos */

            /* Imprime dados sobre a informação do processo */
            printf("- " ANSI_COLOR_CYAN "Nome da %da informação" ANSI_COLOR_RESET ": %s\n", l, p_processo->infos[j].nome);
            if (strcmp(p_processo->infos[j].nome, "io") == 0) {
                printf("- " ANSI_COLOR_CYAN "Tempo de espera %d" ANSI_COLOR_RESET ": %ds\n", n, p_processo->infos[j].tempo);
                printf("-----------------------------------\n");
                n++;
                l++;
            } else {
                printf("- " ANSI_COLOR_CYAN "Tempo de execução %d" ANSI_COLOR_RESET ": %ds\n", m, p_processo->infos[j].tempo);
                printf("-----------------------------------\n");
                m++;
                l++;
            }
        }

        AguardaLeitura(10);

        printf(ANSI_COLOR_CYAN "\nControle antes" ANSI_COLOR_RESET ": ");
        if (LIS_NumeroElementos(fila_prontos) == 0) {
            printf("Nenhum elemento na fila de prontos.\n");
        } else if (LIS_NumeroElementos(fila_prontos) == 1) {
            printf("1 elemento na fila de prontos.\n");
        } else {
            printf("%d elementos na fila de prontos.\n", LIS_NumeroElementos(fila_prontos));
        }

        AguardaLeitura(1);

        /* Insere processo na fila de prontos */
        LIS_InserirElementoApos(fila_prontos, p_processo);

        printf(ANSI_COLOR_CYAN "\nControle depois" ANSI_COLOR_RESET ": ");
        if (LIS_NumeroElementos(fila_prontos) == 1) {
            printf("1 elemento na fila de prontos.\n\n");
        } else {
            printf("%d elementos na fila de prontos.\n\n", LIS_NumeroElementos(fila_prontos));
        }

        AguardaLeitura(5);

        /* Reinicializa os contadores das informações do processo */
        l = 1;
        m = 1;
        n = 1;

    }

    /* Lê a opção do algoritmo de alocação que deve ser executado */
    scanf("%d [^\n]", &id);

    /* ------------------------------------------------- */
    /* PARTE 6: Inicialização da memória                 */
    /* ------------------------------------------------- */

    /* Aloca memória para uma estrutura de memória */
    M = (mem*) malloc(sizeof (mem));

    /* Tratamento de erro para alocação de memória */
    if (M == NULL) {
        ShowError("Falha ao alocar memória para a estrutura de memória do simulador.\n", ERR_MALLOC);
    }

    /* Inicializa memória com partições fixas */
    InicializarMemoria(M);

    /* ------------------------------------------------- */
    /* PARTE 7: Execução do algoritmo de alocação        */
    /* ------------------------------------------------- */

    if (LIS_NumeroElementos(fila_prontos) == 1) {
        printf(ANSI_COLOR_CYAN "Tempo total do processo" ANSI_COLOR_RESET ": %d s\n\n", tempo_total);
    } else {
        printf(ANSI_COLOR_CYAN "Tempo total dos processos" ANSI_COLOR_RESET ": %d s\n\n", tempo_total);
    }

    switch (id) {
        /* First Fit */
        case 1:
            printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n");
            printf(ANSI_COLOR_CYAN "F I R S T  F I T" ANSI_COLOR_RESET "\n\n");
            printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n\n");
            
            AguardaLeitura(2);
            
            FirstFit(fila_prontos, fila_bloqueados, M, qtd_processos, tempo_total);
            break;

        /* Next Fit */
        case 2:
            printf("-----------------------------------------------------------------------------------\n\n");
            printf(ANSI_COLOR_CYAN "N E X T  F I T" ANSI_COLOR_RESET "\n\n");
            printf("-----------------------------------------------------------------------------------\n\n");
            
            AguardaLeitura(2);
            
            //NextFit(fila_prontos, fila_bloqueados, M, qtd_processos, tempo_total);
            break;

        /* Worst Fit */
        case 3:
            printf("-----------------------------------------------------------------------------------\n\n");
            printf(ANSI_COLOR_CYAN "W O R S T  F I T" ANSI_COLOR_RESET "\n\n");
            printf("-----------------------------------------------------------------------------------\n\n");
            
            AguardaLeitura(2);
            
            //worstFit(fila_prontos, fila_bloqueados, M, qtd_processos, tempo_total);
            break;


        /* Best Fit */
        case 4:
            printf("-----------------------------------------------------------------------------------\n\n");
            printf(ANSI_COLOR_CYAN "B E S T  F I T" ANSI_COLOR_RESET "\n\n");
            printf("-----------------------------------------------------------------------------------\n\n");
            
            AguardaLeitura(2);
            
            //BestFit(fila_prontos, fila_bloqueados, M, qtd_processos, tempo_total);
            break;
    }

}

