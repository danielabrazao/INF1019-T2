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
    fflush(stdout); // Flush do buffer.
    printf("\tPONTIFÍCIA UNIVERSIDADE CATÓLICA DO RIO DE JANEIRO\n");
    fflush(stdout); // Flush do buffer.
    printf("\tSegundo Trabalho de Sistemas de Computação\n");
    fflush(stdout); // Flush do buffer.
    printf("\tAutores: Daniela Brazão e Thaíssa Falbo\n");
    fflush(stdout); // Flush do buffer.
    printf("\tProfessor: Luiz Fernando Bessa Seibel\n");
    fflush(stdout); // Flush do buffer.
    printf("\tDisciplina: Sistemas de Computação (INF1019)\n\n");
    fflush(stdout); // Flush do buffer.
    printf("-----------------------------------------------------------------------------------\n\n");
    fflush(stdout); // Flush do buffer.
    printf("\tSimulador de Gerenciador de Memória\n");
    fflush(stdout); // Flush do buffer.
    printf("\tCopyright (C) 2015\n\tDaniela Brazão & Thaíssa Falbo\n\n");
    fflush(stdout); // Flush do buffer.printf("-----------------------------------------------------------------------------------\n\n");
    printf("\tEste programa é um software livre; você pode redistribuí-lo e/ou \n");
    fflush(stdout); // Flush do buffer.
    printf("\tmodificá-lo dentro dos termos da Licença Pública Geral GNU como \n");
    fflush(stdout); // Flush do buffer.
    printf("\tpublicada pela Fundação do Software Livre (FSF); na versão 3 da \n");
    fflush(stdout); // Flush do buffer.
    printf("\tLicença.\n\n");
    fflush(stdout); // Flush do buffer.
    printf("\tEste programa é distribuído na esperança de que possa ser útil, \n");
    fflush(stdout); // Flush do buffer.
    printf("\tmas SEM NENHUMA GARANTIA; sem uma garantia implícita de ADEQUAÇÃO \n");
    fflush(stdout); // Flush do buffer.
    printf("\ta qualquer MERCADO ou APLICAÇÃO EM PARTICULAR. Veja a Licença \n");
    fflush(stdout); // Flush do buffer.
    printf("\tPública Geral GNU para maiores detalhes.\n\n");
    fflush(stdout); // Flush do buffer.
    printf("\tVocê deve ter recebido uma cópia da Licença Pública Geral GNU junto \n");
    fflush(stdout); // Flush do buffer.
    printf("\tcom este programa. Se não, veja <http://www.gnu.org/licenses/>.\n\n");
    fflush(stdout); // Flush do buffer.
    printf("-----------------------------------------------------------------------------------\n\n");
    fflush(stdout); // Flush do buffer.
}

/* Função que exibe mensagem de erro */

void showError(char str[TAM_STR + 1], int n) {
    printf("Erro %d: %s\n", n, str);
    fflush(stdout); // Flush do buffer.
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

/* Função que executa algoritmo de alocação de ajuste rápido */

void first_fit(processo *proc_v, mem *M, int qtd_proc) {

    int i, j, k = 0, w, l, p = qtd_proc;
    time_t dif = 0; /* Diferença entre os tempos final e inicial da execução do algoritmo */

    printf("-----------------------------------------------------------------------------------\n\n");
    fflush(stdout); // Flush do buffer.
    printf("MAPA DE MEMÓRIA:\n\n");
    fflush(stdout); // Flush do buffer.
    printf("-----------------------------------------------------------------------------------\n\n");
    fflush(stdout); // Flush do buffer.

    /* Percorre os processos */
    for (i = 0; i < qtd_proc; i++) {

        /* Percorre as partições de memória */
        for (j = 0; j < QTD_BLOC; j++) {
            if (M->bloco[j].isAlocado == 0 && M->bloco[j].tamanho >= proc_v[i].tamanho) {

                M->bloco[j].isAlocado = proc_v[i].numero;

                printf("-----------------------------------\n");
                fflush(stdout); // Flush do buffer.
                /* Percorre todos os blocos de memória */
                for (w = 0; w < QTD_BLOC; w++) {
                    printf("- Bloco #%d\n", w + 1);
                    fflush(stdout); // Flush do buffer.
                    printf("-----------------------------------\n");
                    fflush(stdout); // Flush do buffer.
                    if (M->bloco[w].isAlocado > 0) {
                        printf("- Número do processo: %d\n", M->bloco[w].isAlocado);
                        fflush(stdout); // Flush do buffer.
                        for (l = 0; l < qtd_proc; l++) {
                            if (M->bloco[w].isAlocado == proc_v[l].numero) {
                                printf("- Tamanho do processo: %dMb\n", proc_v[l].tamanho);
                                printf("- Tempo restante do processo: %ds\n", proc_v[l].tempo_total);
                                fflush(stdout); // Flush do buffer.
                            }
                        }
                        printf("- Tamanho do bloco de memória: %dMb\n", M->bloco[w].tamanho);
                        fflush(stdout); // Flush do buffer.
                        printf("-----------------------------------\n");
                        fflush(stdout); // Flush do buffer.
                    } else {
                        printf("- Bloco de memória vazio.\n");
                        fflush(stdout); // Flush do buffer.
                        printf("- Tamanho do bloco de memória: %dMb\n", M->bloco[w].tamanho);
                        fflush(stdout); // Flush do buffer.
                        printf("-----------------------------------\n");
                        fflush(stdout); // Flush do buffer.
                    }
                }

                time(&proc_v[i].inicio_execucao); /* Armazena o tempo de início de execução do algoritmo */
                printf("\n-----------------------------------\n");
                fflush(stdout); // Flush do buffer.
                printf("PROCESSO #%d - RELÓGIO\n", proc_v[i].numero);
                fflush(stdout); // Flush do buffer.
                printf("-----------------------------------\n");
                fflush(stdout); // Flush do buffer.

                /* Percorre as informações sobre o processo */
                for (k = 0; k < proc_v[i].qtd_info && dif < FATIA_TEMPO; k++) {

                    /* EXEC */
                    if (strcmp(proc_v[i].infos->nome, "exec") == 0 && dif < 10) {
                        while (proc_v[i].infos[k].tempo > 0 && dif < FATIA_TEMPO) {
                            sleep(1);
                            printf("Countdown: %ds\n", proc_v[i].infos[k].tempo);
                            fflush(stdout); // Flush do buffer.
                            proc_v[i].infos[k].tempo--;
                            proc_v[i].tempo_total--;
                            time(&proc_v[i].fim_execucao);
                            dif = proc_v[i].fim_execucao - proc_v[i].inicio_execucao;
                        }
                        printf("Countdown: %ds\n", proc_v[i].infos[k].tempo);
                        printf("-----------------------------------\n\n");

                        /* Percorre todos os blocos de memória */
                        for (w = 0; w < QTD_BLOC; w++) {
                            printf("-----------------------------------\n");
                            fflush(stdout); // Flush do buffer.
                            printf("- Bloco #%d\n", w + 1);
                            fflush(stdout); // Flush do buffer.
                            printf("-----------------------------------\n");
                            fflush(stdout); // Flush do buffer.
                            if (M->bloco[w].isAlocado > 0) {
                                printf("- Número do processo: %d\n", M->bloco[w].isAlocado);
                                fflush(stdout); // Flush do buffer.
                                for (l = 0; l < qtd_proc; l++) {
                                    if (M->bloco[w].isAlocado == proc_v[l].numero) {
                                        printf("- Tamanho do processo: %dMb\n", proc_v[l].tamanho);
                                        printf("- Tempo restante do processo: %ds\n", proc_v[l].tempo_total);
                                        fflush(stdout); // Flush do buffer.
                                    }
                                }
                                printf("- Tamanho do bloco de memória: %dMb\n", M->bloco[w].tamanho);
                                fflush(stdout); // Flush do buffer.
                            } else {
                                printf("- Bloco de memória vazio.\n");
                                fflush(stdout); // Flush do buffer.
                                printf("- Tamanho do bloco de memória: %dMb\n", M->bloco[w].tamanho);
                                fflush(stdout); // Flush do buffer.
                            }
                        }

                        printf("-----------------------------------\n");
                        fflush(stdout); // Flush do buffer.
                        printf("\n-----------------------------------\n");
                        fflush(stdout); // Flush do buffer.

                        /* Libera bloco de memória caso tenha estourado o tempo máximo de execução de um processo */
                        if (dif == 10) {
                            M->bloco[j].isAlocado = 0;
                        }

                        /* Percorre todos os blocos de memória */
                        for (w = 0; w < QTD_BLOC; w++) {
                            printf("- Bloco #%d\n", w + 1);
                            fflush(stdout); // Flush do buffer.
                            printf("-----------------------------------\n");
                            fflush(stdout); // Flush do buffer.
                            if (M->bloco[w].isAlocado > 0) {
                                printf("- Número do processo: %d\n", M->bloco[w].isAlocado);
                                fflush(stdout); // Flush do buffer.
                                for (l = 0; l < qtd_proc; l++) {
                                    if (M->bloco[w].isAlocado == proc_v[l].numero) {
                                        printf("- Tamanho do processo: %dMb\n", proc_v[l].tamanho);
                                        printf("- Tempo restante do processo: %ds\n", proc_v[l].tempo_total);
                                        fflush(stdout); // Flush do buffer.
                                    }
                                }
                                printf("- Tamanho do bloco de memória: %dMb\n", M->bloco[w].tamanho);
                                fflush(stdout); // Flush do buffer.
                                printf("-----------------------------------\n");
                                fflush(stdout); // Flush do buffer.
                            } else {
                                printf("- Bloco de memória vazio.\n");
                                fflush(stdout); // Flush do buffer.
                                printf("- Tamanho do bloco de memória: %dMb\n", M->bloco[w].tamanho);
                                fflush(stdout); // Flush do buffer.
                                printf("-----------------------------------\n");
                                fflush(stdout); // Flush do buffer.
                            }
                        }
                    } else {

                        /* IO 
                         * Esvazia o bloco de memória ocupado;
                         * Decrementa o tempo do IO.
                         */

                        M->bloco[j].isAlocado = 0;
                        while (proc_v[i].infos[k].tempo > 0) {
                            sleep(1);
                            proc_v[i].infos[k].tempo--;
                            proc_v[i].tempo_total--;
                            time(&proc_v[i].fim_execucao);
                            dif = proc_v[i].fim_execucao - proc_v[i].inicio_execucao;
                        }
                    }
                }
                printf("\n");
                fflush(stdout); // Flush do buffer.
            }
            dif = 0;
        }
    }

}
#endif	/* UTILITIES_H */