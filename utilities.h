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

/* Função que limpa a tela e exibe a mensagem inicial do gerenciador de memória */

void Cabecalho() {
    system("clear"); // Limpa a tela.
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

/* Função que exibe uma mensagem de erro */

void ShowError(char str[TAM_STR + 1], int n) {
    printf("Erro %d: %s\n", n, str);
    exit(n);
}

/* Função que inicializa a memória com partições fixas */

void InicializarMemoria(mem *M) {

    int i;
    int v[5] = {8, 4, 2, 1, 1};

    M->tamanho = TAM_MEM;

    for (i = 0; i < 5; i++) {
        M->bloco[i].tamanho = v[i];
    }

}

/* Função que aguarda o usuário digitar a tecla Enter para prosseguir */

void EsperaEnter() {

    char tecla = 'a';

    printf("Pressione a tecla ");
    printf(ANSI_COLOR_MAGENTA "Enter" ANSI_COLOR_RESET);
    printf(" para continuar...\n");
    scanf("%1c", &tecla);

    while (tecla != '\n') {
        printf("Pressione a tecla ");
        printf(ANSI_COLOR_MAGENTA "Enter" ANSI_COLOR_RESET);
        printf(" para continuar...\n");
        scanf("%*1c%c", &tecla);
    }
}

/* Função que libera a memória alocada para um processo */

void DestroiProcesso(processo * p_processo) {
    free(p_processo);
}

/* Função que fornece tempo ao usuário para que leia uma informação */

void AguardaLeitura(int n) {

    if (op == TRUE) {
        sleep(n);
    }
}

/* Função que imprime dados sobre um processo */

void ImprimeProcesso(processo * p_processo) {

    int i;

    printf("-------------------------------------\n");
    printf(ANSI_COLOR_MAGENTA "Processo %d\n" ANSI_COLOR_RESET, p_processo->numero); /* Número identificador do processo */
    printf("-------------------------------------\n");
    printf(ANSI_COLOR_CYAN "Tamanho" ANSI_COLOR_RESET);
    printf(": %d Mb\n", p_processo->tamanho); /* Tamanho do processo em Mb */
    printf(ANSI_COLOR_CYAN "Quantidade de informação" ANSI_COLOR_RESET);
    printf(": %d\n", p_processo->qtd_info); /* Quantidade de informações do processo */

    for (i = 0; i < p_processo->qtd_info; i++) { /* Vetor de informações do processo */
        printf(ANSI_COLOR_CYAN "Nome da info" ANSI_COLOR_RESET);
        printf(": %s\n", p_processo->infos[i].nome);
        printf(ANSI_COLOR_CYAN "Tempo da info" ANSI_COLOR_RESET);
        printf(": %d s\n", p_processo->infos[i].tempo);

    }
    printf(ANSI_COLOR_CYAN "Tempo total" ANSI_COLOR_RESET);
    printf(": %d s\n", p_processo->tempo_total);
    printf("-------------------------------------\n\n");

    if (op == TRUE) {
        sleep(5);
    }
}

/* Função que imprime dados sobre os blocos de memória */

void ImprimeMemoria(mem *M) {
    int i;

    printf("-----------------------------------------------------------------------------------\n\n");
    printf(ANSI_COLOR_MAGENTA "MAPA DE MEMÓRIA" ANSI_COLOR_RESET ":\n\n");
    printf("-----------------------------------------------------------------------------------\n\n");

    for (i = 0; i < QTD_BLOC; i++) {
        printf("-------------------------------------\n");
        printf("- ");
        printf(ANSI_COLOR_MAGENTA "Bloco %d\n" ANSI_COLOR_RESET, i + 1);
        printf("-------------------------------------\n");
        printf("- ");
        printf(ANSI_COLOR_CYAN "Tamanho" ANSI_COLOR_RESET);
        printf(": %d Mb\n", M->bloco[i].tamanho);
        if (M->bloco[i].p_processo != NULL) {
            ImprimeProcesso(M->bloco[i].p_processo);
        } else if (M->bloco[i].p_processo == NULL) {
            printf("- Bloco vazio.\n");
        }
    }

    printf("-------------------------------------\n\n");

    if (op == TRUE) {
        sleep(5);
    }
}

/* Função que imprime dados sobre uma lista */

void ImprimeLista(LIS_tppLista p_lista) {

    int i, qtd;
    processo * p_processo;

    IrInicioLista(p_lista);

    qtd = LIS_NumeroElementos(p_lista);

    for (i = 0; i < qtd; i++) {
        p_processo = LIS_ObterValor(p_lista);
        ImprimeProcesso(p_processo);
        LIS_AvancarElementoCorrente(p_lista, 1);
    }

    if (op == TRUE) {
        sleep(5);
    }

    IrInicioLista(p_lista);
}

/* Função que contabiliza e decrementa os tempos de execução e de espera dos processos */

void Relogio(mem *M, LIS_tppLista fila_bloqueados, int *tempo_total) {

    int tempo = 0, i, j, k, p; /* Contadores auxiliares */
    processo * p_processo; /* Ponteiro para um processo */

    printf("-----------------------------------------------------------------------------------\n\n");
    printf(ANSI_COLOR_MAGENTA "RELÓGIO" ANSI_COLOR_RESET ":\n\n");
    printf("-----------------------------------------------------------------------------------\n\n");

    /* Vai para o início da fila de bloqueados */
    IrInicioLista(fila_bloqueados);

    while ((tempo < FATIA_TEMPO)) {

        sleep(1);
        tempo++;

        /* Percorre todos os blocos de memória */
        for (j = 0; j < QTD_BLOC; j++) {
            /* Se o bloco de memória está alocado */
            if (M->bloco[j].p_processo != NULL) {
                /* Percorre todos os comandos */
                for (k = 0; k < M->bloco[j].p_processo->qtd_info; k++) {
                    if ((M->bloco[j].p_processo->infos[k].ativo == TRUE) && (M->bloco[j].p_processo->infos[k].tempo > 0) && (strcmp(M->bloco[j].p_processo->infos[k].nome, "exec") == 0)) {
                        M->bloco[j].p_processo->tempo_total--;
                        M->bloco[j].p_processo->infos[k].tempo--;
                        *tempo_total = *tempo_total - 1;
                        printf(ANSI_COLOR_CYAN "Exec" ANSI_COLOR_RESET ": %d s\n", M->bloco[j].p_processo->infos[k].tempo);
                        printf("Tempo total = %d\n", *tempo_total);
                    }
                }
            }
        }

        /* Percorre todos os processos da fila de bloqueados */
        for (i = 0; i < LIS_NumeroElementos(fila_bloqueados); i++) {
            /* Obtém endereço do processo da fila de bloqueados */
            p_processo = LIS_ObterValor(fila_bloqueados);
            /* Percorre todos os comandos */
            for (k = 0; k < p_processo->qtd_info; k++) {
                if ((p_processo->infos[k].tempo > 0) && (strcmp(p_processo->infos[k].nome, "io") == 0)) {
                    p_processo->tempo_total--;
                    p_processo->infos[k].tempo--;
                    *tempo_total = *tempo_total - 1;
                    printf(ANSI_COLOR_CYAN "Io" ANSI_COLOR_RESET ": %d s\n", p_processo->infos[k].tempo);
                    printf("Tempo total = %d\n", *tempo_total);

                    /* Se o tempo de espera do comando acabou */
                    if ((p_processo->infos[k].tempo == 0) && (p_processo->tempo_total == 0)) {
                        LIS_ExcluirElemento(fila_bloqueados);
                    }

                }
            }
            LIS_AvancarElementoCorrente(fila_bloqueados, 1);
        }

        printf("%d s\n", tempo);
    }

    IrInicioLista(fila_bloqueados);

    AguardaLeitura(1);

    printf("\n");
}

/* Função do algoritmo de alocação de memória de ajuste rápido */

void FirstFit(LIS_tppLista fila_prontos, LIS_tppLista fila_bloqueados, mem *M, int qtd_proc, int tempo_total) {

    int i, j, k, qtd_info, c, d, f = FALSE, g; /* Contadores auxiliares */
    int flag; /* Marcadores auxiliares */
    processo * p_processo; /* Ponteiro para um processo */
    processo * p_processo1; /* Ponteiro para um processo */

    /* Imprime dados sobre os blocos de memória */
    ImprimeMemoria(M);

    /* Enquanto o tempo total de todos os processos for diferente de zero */
    while (tempo_total > 0) {

        if ((LIS_NumeroElementos(fila_prontos) > 0)) {
            printf("-----------------------------------------------------------------------------------\n\n");
            printf(ANSI_COLOR_MAGENTA "FILA DE PRONTOS" ANSI_COLOR_RESET ":\n\n");
            printf("-----------------------------------------------------------------------------------\n\n");

            AguardaLeitura(1);

            /* Imprime dados sobre a fila de prontos */
            ImprimeLista(fila_prontos);

            printf("-----------------------------------------------------------------------------------\n\n");
            printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
            printf("-----------------------------------------------------------------------------------\n\n");

            AguardaLeitura(1);

            if ((LIS_NumeroElementos(fila_bloqueados) > 0)) {/* Imprime dados sobre a fila de prontos */
                ImprimeLista(fila_bloqueados);
            } else {
                printf("A fila de bloqueados está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");
            }

            printf("-----------------------------------------------------------------------------------\n\n");
            printf(ANSI_COLOR_MAGENTA "PROCESSO A SER ALOCADO" ANSI_COLOR_RESET ":\n\n");
            printf("-----------------------------------------------------------------------------------\n\n");

            /* Obtém primeiro processo na fila de prontos */
            IrInicioLista(fila_prontos);

            p_processo = LIS_ObterValor(fila_prontos);
            ImprimeProcesso(p_processo);

            printf("É necessário um bloco de memória de %d Mb para comportar o processo %d.\n", p_processo->tamanho, p_processo->numero);

            AguardaLeitura(1);

            /* Procura uma posição de memória para alocar o processo */
            i = 0;

            flag = FALSE;

            while ((flag == FALSE) && (i < QTD_BLOC)) {
                if ((M->bloco[i].tamanho >= p_processo->tamanho) && (M->bloco[i].p_processo == NULL)) {
                    flag = TRUE;
                }
                i++;
            }
            i = i - 1;

            if (flag == FALSE) { // Posição de memória não encontrada, logo o processo é destruído.
                printf("- Posição de memória " ANSI_COLOR_MAGENTA "não" ANSI_COLOR_RESET " encontrada.\n");

                AguardaLeitura(1);

                LIS_ExcluirElemento(fila_prontos);
                IrInicioLista(fila_prontos);
                DestroiProcesso(p_processo);

                /* Subtrai o tempo do processo destruído do tempo total de todos os processos */
                tempo_total = tempo_total - p_processo->tempo_total;

                printf("- Processo " ANSI_COLOR_MAGENTA "destruído" ANSI_COLOR_RESET ".\n\n");

            } else { /* Posição de memória encontrada.
                      * Processo alocado na memória e retirado da lista de prontos. */

                printf("- Posição de memória encontrada no bloco %d.\n", i + 1);

                AguardaLeitura(1);

                M->bloco[i].p_processo = p_processo;

                AguardaLeitura(1);

                printf("- Processo %d " ANSI_COLOR_CYAN "alocado" ANSI_COLOR_RESET ".\n\n", p_processo->numero);
                LIS_ExcluirElemento(fila_prontos);
                IrInicioLista(fila_prontos);

            }

            AguardaLeitura(1);
        }

        /* Imprime dados sobre os blocos de memória */
        ImprimeMemoria(M);

        /* Executa o comando do processo alocado no bloco de memória */
        /* Percorre todos os blocos de memória */
        for (j = 0; j < QTD_BLOC; j++) {
            /* Se o bloco estiver alocado com um processo */
            if (M->bloco[j].p_processo != NULL) {
                /* Percorre todos os comandos do processo */
                qtd_info = M->bloco[j].p_processo->qtd_info;
                for (k = 0; k < qtd_info; k++) {
                    /* Procura comando não finalizado */
                    /* Se for exec */
                    if ((M->bloco[j].p_processo->infos[k].tempo > 0) && (strcmp(M->bloco[j].p_processo->infos[k].nome, "exec") == 0)) {

                        M->bloco[j].p_processo->infos[k].ativo = TRUE;

                        Relogio(M, fila_bloqueados, &tempo_total);

                        M->bloco[j].p_processo->infos[k].ativo = FALSE;

                        /* Imprime dados sobre os blocos de memória */
                        ImprimeMemoria(M);

                        /* Se o comando exec foi finalizado */
                        if (M->bloco[j].p_processo->infos[k].tempo == 0) {
                            /* Se existe um próximo comando no mesmo bloco */
                            if ((strcmp(M->bloco[j].p_processo->infos[k + 1].nome, "io") == 0) || (strcmp(M->bloco[j].p_processo->infos[k + 1].nome, "exec") == 0)) {
                                IrFinalLista(fila_prontos);

                                /* Insere processo na fila de prontos */
                                LIS_InserirElementoApos(fila_prontos, M->bloco[j].p_processo);

                                IrInicioLista(fila_prontos);

                                /* Libera bloco de memória */
                                M->bloco[i].p_processo = NULL;

                                /* Imprime dados sobre os blocos de memória */
                                ImprimeMemoria(M);

                                break;
                            }
                        }/* Se o comando exec não foi finalizado */
                        else if (M->bloco[j].p_processo->infos[k].tempo > 0) {

                            IrFinalLista(fila_prontos);

                            /* Insere processo na fila de prontos */
                            LIS_InserirElementoApos(fila_prontos, M->bloco[j].p_processo);

                            IrInicioLista(fila_prontos);

                            /* Libera bloco de memória */
                            M->bloco[i].p_processo = NULL;

                            /* Imprime dados sobre os blocos de memória */
                            ImprimeMemoria(M);

                            break;

                        }/* Se o comando exec foi finalizado e a fila de bloqueados ainda não */
                        else if ((M->bloco[j].p_processo->infos[k].tempo == 0) && (LIS_NumeroElementos(fila_bloqueados) > 0)) {

                            printf("-----------------------------------------------------------------------------------\n\n");
                            printf(ANSI_COLOR_MAGENTA "FILA DE PRONTOS" ANSI_COLOR_RESET ":\n\n");
                            printf("-----------------------------------------------------------------------------------\n\n");

                            if (LIS_NumeroElementos(fila_prontos) == 0) {
                                printf("A fila de prontos está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");

                            } else {/* Imprime dados sobre a fila de prontos */
                                ImprimeLista(fila_prontos);
                            }

                            printf("-----------------------------------------------------------------------------------\n\n");
                            printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                            printf("-----------------------------------------------------------------------------------\n\n");

                            if (LIS_NumeroElementos(fila_bloqueados) == 0) {
                                printf("A fila de bloqueados está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");

                            } else {/* Imprime dados sobre a fila de bloqueados */
                                ImprimeLista(fila_bloqueados);
                            }

                            while (tempo_total > 0) {
                                Relogio(M, fila_bloqueados, &tempo_total);
                            }

                            LIS_ExcluirElemento(fila_bloqueados);
                        }

                    }/* Se for io */
                    else if ((M->bloco[j].p_processo->infos[k].tempo > 0) && (strcmp(M->bloco[j].p_processo->infos[k].nome, "io") == 0)) {

                        /* Insere processo na fila de bloqueados */
                        LIS_InserirElementoApos(fila_bloqueados, M->bloco[j].p_processo);

                        printf("-----------------------------------------------------------------------------------\n\n");
                        printf(ANSI_COLOR_MAGENTA "FILA DE PRONTOS" ANSI_COLOR_RESET ":\n\n");
                        printf("-----------------------------------------------------------------------------------\n\n");

                        if (LIS_NumeroElementos(fila_prontos) == 0) {
                            printf("A fila de prontos está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");

                        } else {
                            /* Imprime dados sobre a fila de prontos */
                            ImprimeLista(fila_prontos);
                        }

                        printf("-----------------------------------------------------------------------------------\n\n");
                        printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                        printf("-----------------------------------------------------------------------------------\n\n");

                        if (LIS_NumeroElementos(fila_bloqueados) == 0) {
                            printf("A fila de bloqueados está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");

                        } else {/* Imprime dados sobre a fila de bloqueados */
                            ImprimeLista(fila_bloqueados);
                        }

                        /* Se o tempo restante de todos os processos for o tempo do comando io */
                        if (tempo_total == M->bloco[j].p_processo->infos[k].tempo) {
                            f = TRUE;
                        }

                        if ((LIS_NumeroElementos(fila_bloqueados) == 1) && (LIS_NumeroElementos(fila_prontos) == 0)) {

                        }
                        /* Libera bloco de memória */
                        M->bloco[i].p_processo = NULL;

                        /* Imprime dados sobre os blocos de memória */
                        ImprimeMemoria(M);

                        /* Se for a última informação */
                        if ((LIS_NumeroElementos(fila_bloqueados) == 1) && (LIS_NumeroElementos(fila_prontos) == 0)) {

                            if (f == TRUE) {
                                while (tempo_total > 0) {
                                    Relogio(M, fila_bloqueados, &tempo_total);
                                }

                                LIS_ExcluirElemento(fila_bloqueados);
                            } else {

                                Relogio(M, fila_bloqueados, &tempo_total);

                                printf("-----------------------------------------------------------------------------------\n\n");
                                printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                                printf("-----------------------------------------------------------------------------------\n\n");

                                /* Imprime dados sobre a fila de bloqueados */
                                ImprimeLista(fila_bloqueados);

                                /* Obtém endereço do processo da fila de bloqueados */
                                p_processo1 = LIS_ObterValor(fila_bloqueados);

                                /* Vai para o final da fila de prontos */
                                IrFinalLista(fila_prontos);

                                /* Insere processo na fila de prontos */
                                LIS_InserirElementoApos(fila_prontos, p_processo1);

                                IrInicioLista(fila_prontos);

                                LIS_ExcluirElemento(fila_bloqueados);

                                break;
                            }

                        }
                    }
                }
            }
        }

        /* Imprime a fila de prontos após a alocação do processo na memória */
        if (LIS_NumeroElementos(fila_prontos) == 0) {
            printf("-----------------------------------------------------------------------------------\n\n");
            printf(ANSI_COLOR_MAGENTA "FILA DE PRONTOS" ANSI_COLOR_RESET ":\n\n");
            printf("-----------------------------------------------------------------------------------\n\n");
            printf("A fila de prontos está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");

            if (LIS_NumeroElementos(fila_bloqueados) == 0) {
                printf("-----------------------------------------------------------------------------------\n\n");
                printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                printf("-----------------------------------------------------------------------------------\n\n");
                printf("A fila de bloqueados está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");
            } else {
                printf("-----------------------------------------------------------------------------------\n\n");
                printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                printf("-----------------------------------------------------------------------------------\n\n");

                /* Imprime dados sobre a fila de bloqueados */
                ImprimeLista(fila_bloqueados);
            }
        }

        /* Processo finalizado */
        if ((M->bloco[i].p_processo != NULL) && (M->bloco[i].p_processo->tempo_total == 0)) {

            /* Libera bloco de memória */
            M->bloco[i].p_processo = NULL;

            /* Imprime dados sobre os blocos de memória */
            ImprimeMemoria(M);
        }

    } // While

} // FirstFit

#endif	/* UTILITIES_H */