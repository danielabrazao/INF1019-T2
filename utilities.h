/*
 * -------------------------------------------------
 * ~ ARQUIVO DE CABEÇALHO DE UTILITÁRIOS
 * -------------------------------------------------
 *
 *  Descrição: Arquivo de cabeçalho contendo funções auxiliares.
 *  Arquivo: utilities.h criado em 5 de Novembro de 2015, às 12:03.
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

#ifndef UTILITIES_H
#define	UTILITIES_H

#include "definitions.h" /* Arquivo de cabeçalho com definições (includes e defines) */

/* Função que exibe mensagem inicial do gerenciador de memória */

void cabecalho() {
    printf("\n-----------------------------------------------------------------------------------\n\n");
    printf(ANSI_COLOR_CYAN "\tPONTIFÍCIA UNIVERSIDADE CATÓLICA DO RIO DE JANEIRO" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_MAGENTA "\tSegundo Trabalho de Sistemas de Computação" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_CYAN "\tAlunas" ANSI_COLOR_RESET "");
    printf(": Daniela Brazão e Thaíssa Falbo\n");
    printf(ANSI_COLOR_CYAN "\tProfessor" ANSI_COLOR_RESET "");
    printf(": Luiz Fernando Bessa Seibel\n");
    printf(ANSI_COLOR_CYAN "\tDisciplina" ANSI_COLOR_RESET "");
    printf(": Sistemas de Computação (INF1019)\n\n");
    printf("-----------------------------------------------------------------------------------\n\n");
    printf(ANSI_COLOR_MAGENTA "\tSimulador de Gerenciador de Memória" ANSI_COLOR_RESET "\n");
    printf("\tCopyright (C) 2015\n\tDaniela Brazão & Thaíssa Falbo\n\n");
    printf("-----------------------------------------------------------------------------------\n\n");
    printf(ANSI_COLOR_MAGENTA "LICENÇA:" ANSI_COLOR_RESET "\n\n");
    printf("-----------------------------------------------------------------------------------\n\n");
    printf("\tEste programa é um software livre; você pode redistribuí-lo e/ou \n");
    printf("\tmodificá-lo dentro dos termos da Licença Pública Geral GNU como \n");
    printf("\tpublicada pela Fundação do Software Livre (FSF); na versão 3 da \n");
    printf("\tLicença.\n\n");
    printf("\tEste programa é distribuído na esperança de que possa ser útil, \n");
    printf("\tmas SEM NENHUMA GARANTIA; sem uma garantia implícita de ADEQUAÇÃO \n");
    printf("\ta qualquer MERCADO ou APLICAÇÃO EM PARTICULAR. Veja a Licença \n");
    printf("\tPública Geral GNU para maiores detalhes.\n\n");
    printf("\tVocê deve ter recebido uma cópia da Licença Pública Geral GNU junto \n");
    printf("\tcom este programa. Se não, veja <http://www.gnu.org/licenses/>.\n\n");
    printf("-----------------------------------------------------------------------------------\n\n");
}

/* Função que exibe mensagem de erro */

void showError(char str[TAM_STR + 1], int n) {
    printf("Erro %d: %s\n", n, str);
    exit(n);
}

/* Função que inicializa a memória com partições fixas */

void inicializar_memoria(mem *M) {

    int i;
    int v[5] = {8, 4, 2, 1, 1};

    M->tamanho = TAM_MEM;

    for (i = 0; i < 5; i++) {

        M->bloco[i].isAlocado = 0;
        M->bloco[i].tamanho = v[i];
    }

}

/* Função que aguarda o usuário digitar a tecla Enter para prosseguir */

void espera_enter() {

    char tecla = 'a';

    printf("Pressione a tecla ");
    printf(ANSI_COLOR_MAGENTA "Enter" ANSI_COLOR_RESET "");
    printf(" para continuar...\n");
    scanf("%1c", &tecla);

    while (tecla != '\n') {
        printf("Pressione a tecla ");
        printf(ANSI_COLOR_MAGENTA "Enter" ANSI_COLOR_RESET "");
        printf(" para continuar...\n");
        scanf("%*1c%c", &tecla);
    }
}

/* Função que decrementa os tempos dos processos bloqueados */

void *decrementa_io(void *args) {

    estrutura_io *actual_args = args;

    int a, c, dif = 0;

    for (a = 0; a < TAM_VET; a++) {
        if (actual_args->fila_bloq[a].numero > 0) {
            for (c = 0; c < actual_args->fila_bloq[a].qtd_info; c++) {
                if ((strcmp(actual_args->fila_bloq[a].infos[c].nome, "io") == 0) && (actual_args->fila_bloq[a].infos[c].tempo > 0)) {
                    while (actual_args->fila_bloq[a].infos[c].tempo > 0 && dif <= FATIA_TEMPO) {
                        sleep(1);
                        printf("Countdown: %ds\n", actual_args->fila_bloq[a].infos[c].tempo);
                        actual_args->fila_bloq[a].infos[c].tempo--;
                        actual_args->fila_bloq[a].tempo_total--;
                        actual_args->tempo_total--;
                        time(&actual_args->fila_bloq[a].fim_execucao); /* Armazena o tempo de fim da execução do algoritmo */
                        dif = actual_args->fila_bloq[a].fim_execucao - actual_args->fila_bloq[a].inicio_execucao;
                    }
                }
            }
        }
    }

    free(actual_args);
    pthread_exit(NULL);
}

/* Função que decrementa os tempos dos processos prontos */

void *decrementa_exec(void *threadid, processo *proc_v, int *tempo_total) {

    int i, k, dif = 0;

    while ((strcmp(proc_v[i].infos[k].nome, "exec") == 0) && proc_v[i].infos[k].tempo > 0 && dif <= FATIA_TEMPO) {
        sleep(1);
        printf("Countdown: %ds\n", proc_v[i].infos[k].tempo);
        proc_v[i].infos[k].tempo--;
        proc_v[i].tempo_total--;
        tempo_total--;
        time(&proc_v[i].fim_execucao); /* Armazena o tempo de fim da execução do algoritmo */
        dif = proc_v[i].fim_execucao - proc_v[i].inicio_execucao;
    }
    sleep(1);
    printf("Countdown: %ds\n", proc_v[i].infos[k].tempo);

    pthread_exit(NULL);
}

/* Função que executa algoritmo de alocação de ajuste rápido */

void first_fit(processo *proc_v, mem *M, int qtd_proc, int tempo_total) {

    int a, c, i, j, k = 0, w, l, d, flag, z, tempo = 0, b;
    unsigned int t = 0;
    time_t dif = 0; /* Diferença entre os tempos final e inicial da execução do algoritmo */
    pthread_t threads[NUM_THREADS]; /* Vetor de threads */

    printf(ANSI_COLOR_MAGENTA "MAPA DE MEMÓRIA" ANSI_COLOR_RESET ":\n\n");
    printf("-----------------------------------------------------------------------------------\n\n");
    sleep(2);

    /* Tempo total de todos os processos dividido pela fatia de tempo */
    if (tempo_total >= FATIA_TEMPO) {
        tempo = qtd_proc;
    }

    printf("Tempo total = %d\n\n", tempo);

    for (z = 0; z < tempo; z++) {
        /* Percorre todos os processos */
        for (i = 0; i < qtd_proc; i++) {
            printf("i = %d\n\n", i);
            flag = 0;

            /* Percorre todas as partições de memória */
            for (j = 0; j < QTD_BLOC; j++) {
                if (M->bloco[j].isAlocado == 0 && M->bloco[j].tamanho >= proc_v[i].tamanho) {

                    flag = 1;
                    M->bloco[j].isAlocado = proc_v[i].numero;

                    printf("-----------------------------------\n");

                    /* Imprime mapa de memória */
                    for (w = 0; w < QTD_BLOC; w++) {
                        printf("- Bloco #%d\n", w + 1);
                        printf("-----------------------------------\n");
                        sleep(2);

                        /* Bloco está alocado para um processo */
                        if (M->bloco[w].isAlocado > 0) {
                            printf("- Número do processo: %d\n", M->bloco[w].isAlocado);

                            for (l = 0; l < qtd_proc; l++) {
                                if (M->bloco[w].isAlocado == proc_v[l].numero) {
                                    printf("- Tamanho do processo: %dMb\n", proc_v[l].tamanho);
                                    printf("- Tempo restante do processo: %ds\n", proc_v[l].tempo_total);
                                }
                            }
                            printf("- Tamanho do bloco de memória: %dMb\n", M->bloco[w].tamanho);
                            printf("-----------------------------------\n");
                            sleep(2);
                        } else {
                            printf("- Bloco de memória");
                            printf(ANSI_COLOR_MAGENTA " vazio" ANSI_COLOR_RESET ".\n");
                            printf("- Tamanho do bloco de memória: %dMb\n", M->bloco[w].tamanho);
                            printf("-----------------------------------\n");
                            sleep(2);
                        }
                    }

                    d = FALSE;

                    /* Percorre as informações sobre o processo */
                    for (k = 0; k < proc_v[i].qtd_info && dif < FATIA_TEMPO; k++) {

                        /* EXEC */
                        if ((strcmp(proc_v[i].infos[k].nome, "exec") == 0) && (proc_v[i].infos[k].tempo > 0) && (proc_v->bloq == FALSE)) {

                            if (d == FALSE) {
                                printf("\n-----------------------------------\n");
                                printf("PROCESSO #%d - RELÓGIO\n", proc_v[i].numero);
                                printf("-----------------------------------\n");
                                sleep(2);
                                printf("Comando: %s\n\n", proc_v[i].infos[k].nome);
                                sleep(2);
                                d = TRUE;
                            }

                            time(&proc_v[i].inicio_execucao); /* Armazena o tempo de início da execução do algoritmo */

                            for (t = 0; t < NUM_THREADS; ++t) {
                                estrutura_io *args = malloc(sizeof *args);
                                args->fila_bloq = fila_bloq;
                                args->tempo_total = &tempo_total;
                                if (pthread_create(&threads[t], NULL, decrementa_io, args)) {
                                    free(args);
                                    //goto error_handler;
                                }
                            }

                            for (t = 0; t < NUM_THREADS; t++)
                                pthread_join(threads[t], NULL);

                            printf("-----------------------------------\n\n");

                            /* Imprime o mapa de memória */
                            for (w = 0; w < QTD_BLOC; w++) {
                                printf("-----------------------------------\n");
                                printf("- Bloco #%d\n", w + 1);
                                printf("-----------------------------------\n");
                                sleep(2);

                                /* Bloco está alocado para um processo */
                                if (M->bloco[w].isAlocado > 0) {
                                    printf("- Número do processo: %d\n", M->bloco[w].isAlocado);
                                    for (l = 0; l < qtd_proc; l++) {
                                        if (M->bloco[w].isAlocado == proc_v[l].numero) {
                                            printf("- Tamanho do processo: %dMb\n", proc_v[l].tamanho);
                                            printf("- Tempo restante do processo: %ds\n", proc_v[l].tempo_total);
                                        }
                                    }
                                    printf("- Tamanho do bloco de memória: %dMb\n", M->bloco[w].tamanho);
                                } else {
                                    printf("- Bloco de memória vazio.\n");
                                    printf("- Tamanho do bloco de memória: %dMb\n", M->bloco[w].tamanho);
                                }
                            }

                            printf("-----------------------------------\n\n");
                            sleep(2);

                            /* Libera bloco de memória caso tenha estourado o tempo máximo de execução de um processo ou todos os processos tenham terminado */
                            if ((dif == 10) || (tempo_total == 0)) {
                                M->bloco[j].isAlocado = 0;
                            }


                            /* Imprime o mapa de memória */
                            for (w = 0; w < QTD_BLOC; w++) {
                                printf("-----------------------------------\n");
                                printf("- Bloco #%d\n", w + 1);
                                printf("-----------------------------------\n");
                                sleep(2);

                                /* Bloco está alocado para um processo */
                                if (M->bloco[w].isAlocado > 0) {
                                    printf("- Número do processo: %d\n", M->bloco[w].isAlocado);
                                    for (l = 0; l < qtd_proc; l++) {
                                        if (M->bloco[w].isAlocado == proc_v[l].numero) {
                                            printf("- Tamanho do processo: %dMb\n", proc_v[l].tamanho);
                                            printf("- Tempo restante do processo: %ds\n", proc_v[l].tempo_total);
                                        }
                                    }
                                    printf("- Tamanho do bloco de memória: %dMb\n", M->bloco[w].tamanho);
                                } else {
                                    printf("- Bloco de memória vazio.\n");
                                    printf("- Tamanho do bloco de memória: %dMb\n", M->bloco[w].tamanho);
                                }
                            }

                            printf("-----------------------------------\n");
                            sleep(2);
                        } else {

                            /* IO */

                            /* Esvazia bloco de memória previamente ocupado e o processo vai para o disco. */

                            M->bloco[j].isAlocado = 0;

                            /* Insere o processo na fila de processsos bloqueados */

                            fila_bloq[i].numero = proc_v[i].numero;
                            fila_bloq[i].tamanho = proc_v[i].tamanho;
                            fila_bloq[i].qtd_info = proc_v[i].qtd_info;
                            fila_bloq[i].inicio_execucao = proc_v[i].inicio_execucao;
                            fila_bloq[i].fim_execucao = proc_v[i].fim_execucao;
                            fila_bloq[i].tempo_total = proc_v[i].tempo_total;

                            strcpy(fila_bloq[i].infos[k].nome, proc_v[i].infos[k].nome);
                            fila_bloq[i].infos[k].tempo = proc_v[i].infos[k].tempo;

                           
                            /* Marca o processo como bloqueado na fila de processos prontos */

                            proc_v[i].bloq = TRUE;

                            printf("Processo #%d entrou em IO.\n", proc_v[i].numero);
                        }
                    }
                    printf("\n");
                }
                dif = 0; /* Reinicializa o valor do contador dif */
            }

            if (flag == 0) {
                printf("Bloco de memória compatível com o tamanho de %dMb do processo de número %d inexiste.\n\n", proc_v[i].tamanho, proc_v[i].numero);
            }
        }
    }

    if (tempo_total % 3 > 0) {
        // repete aquilo mais uma vez
    }
}

#endif	/* UTILITIES_H */