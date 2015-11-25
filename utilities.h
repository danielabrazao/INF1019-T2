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
    fflush(stdin);
    printf(ANSI_COLOR_MAGENTA "Processo %d\n" ANSI_COLOR_RESET, p_processo->numero); /* Número identificador do processo */
    fflush(stdin);
    printf("-------------------------------------\n");
    fflush(stdin);
    printf(ANSI_COLOR_CYAN "Tamanho" ANSI_COLOR_RESET);
    fflush(stdin);
    printf(": %d Mb\n", p_processo->tamanho); /* Tamanho do processo em Mb */
    fflush(stdin);
    printf(ANSI_COLOR_CYAN "Quantidade de informação" ANSI_COLOR_RESET);
    fflush(stdin);
    printf(": %d\n", p_processo->qtd_info); /* Quantidade de informações do processo */
    fflush(stdin);

    for (i = 0; i < p_processo->qtd_info; i++) { /* Vetor de informações do processo */
        printf(ANSI_COLOR_CYAN "Nome da info" ANSI_COLOR_RESET);
        fflush(stdin);
        printf(": %s\n", p_processo->infos[i].nome);
        fflush(stdin);
        printf(ANSI_COLOR_CYAN "Tempo da info" ANSI_COLOR_RESET);
        fflush(stdin);
        printf(": %d s\n", p_processo->infos[i].tempo);
        fflush(stdin);

    }

    printf(ANSI_COLOR_CYAN "Tempo total" ANSI_COLOR_RESET);
    fflush(stdin);
    printf(": %d s\n", p_processo->tempo_total);
    fflush(stdin);
    printf("-------------------------------------\n\n");
    fflush(stdin);

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

void Relogio(mem *M, LIS_tppLista fila_bloqueados, LIS_tppLista fila_prontos, int *tempo_total) {

    int tempo = 0, i, j, k, q = 0; /* Contadores auxiliares */
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

        IrInicioLista(fila_bloqueados);

        q = LIS_NumeroElementos(fila_bloqueados);

        /* Percorre todos os processos da fila de bloqueados */
        for (i = 0; i < q; i++) {
DECREMENTA:
            /* Obtém endereço do processo da fila de bloqueados */
            p_processo = LIS_ObterValor(fila_bloqueados);

            /* Percorre todos os comandos */
            for (k = 0; k < p_processo->qtd_info; k++) {
                if ((p_processo->infos[k].ativo == TRUE) && (p_processo->infos[k].tempo > 0) && (strcmp(p_processo->infos[k].nome, "io") == 0)) {
                    p_processo->tempo_total--;
                    p_processo->infos[k].tempo--;
                    *tempo_total = *tempo_total - 1;
                    printf(ANSI_COLOR_CYAN "Io" ANSI_COLOR_RESET ": %d s\n", p_processo->infos[k].tempo);
                    fflush(stdin);
                    printf("Tempo total = %d\n", *tempo_total);
                    fflush(stdin);

                    /* Se o tempo de espera do comando acabou e o processo também */
                    if (p_processo->infos[k].tempo == 0) {
                        p_processo->infos[k].ativo = FALSE;
                        LIS_ExcluirElemento(fila_bloqueados);
                    }/* Se o tempo de espera do comando acabou mas não o tempo total do processo */
                    else if ((p_processo->infos[k].tempo == 0) && (p_processo->tempo_total > 0)) {

                        LIS_ExcluirElemento(fila_bloqueados);

                        IrInicioLista(fila_bloqueados);
                        
                        if (LIS_NumeroElementos(fila_bloqueados) > 0) {
                            goto DECREMENTA;
                        } else {
                            break;
                        }
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

void Relogio2(mem *M, LIS_tppLista fila_bloqueados, LIS_tppLista fila_prontos, int *tempo_total) {

    int tempo = 0, i, j, k, q, d = FALSE; /* Contadores auxiliares */
    processo * p_processo; /* Ponteiro para um processo */

    printf("-----------------------------------------------------------------------------------\n\n");
    fflush(stdin);
    printf(ANSI_COLOR_MAGENTA "RELÓGIO" ANSI_COLOR_RESET ":\n\n");
    fflush(stdin);
    printf("-----------------------------------------------------------------------------------\n\n");
    fflush(stdin);

    /* Vai para o início da fila de bloqueados */
    IrInicioLista(fila_bloqueados);

    while ((tempo < FATIA_TEMPO)) {

        sleep(1);
        tempo++;

        IrInicioLista(fila_bloqueados);

        q = LIS_NumeroElementos(fila_bloqueados);

        /* Percorre todos os processos da fila de bloqueados */
        for (i = 0; i < q; i++) {
DECREMENTA:
            /* Obtém endereço do processo da fila de bloqueados */
            p_processo = LIS_ObterValor(fila_bloqueados);
            /* Percorre todos os comandos */
            for (k = 0; k < p_processo->qtd_info; k++) {
                if ((p_processo->infos[k].ativo == TRUE) && (p_processo->infos[k].tempo > 0) && (strcmp(p_processo->infos[k].nome, "io") == 0)) {
                    p_processo->tempo_total--;
                    p_processo->infos[k].tempo--;
                    *tempo_total = *tempo_total - 1;
                    printf(ANSI_COLOR_CYAN "Io" ANSI_COLOR_RESET ": %d s\n", p_processo->infos[k].tempo);
                    fflush(stdin);
                    printf("Tempo total = %d\n", *tempo_total);
                    fflush(stdin);

                    /* Se o tempo de espera do comando acabou */
                    if (p_processo->infos[k].tempo == 0) {
                        p_processo->infos[k].ativo = FALSE;
                        LIS_ExcluirElemento(fila_bloqueados);
                        d = TRUE;
                    }
                }
            }

            LIS_AvancarElementoCorrente(fila_bloqueados, 1);

        }

        printf("%d s\n", tempo);
    }

    IrInicioLista(fila_bloqueados);

    q = LIS_NumeroElementos(fila_bloqueados);

    /* Percorre todos os processos da fila de bloqueados */
    for (i = 0; i < q; i++) {
        /* Obtém endereço do processo da fila de bloqueados */
        p_processo = LIS_ObterValor(fila_bloqueados);
        /* Percorre todos os comandos */
        for (k = 0; k < p_processo->qtd_info; k++) {
            if ((p_processo->infos[k].ativo == TRUE) && (strcmp(p_processo->infos[k].nome, "io") == 0) && (p_processo->tempo_total == 0)) {
                p_processo->infos[k].ativo = FALSE;
                LIS_ExcluirElemento(fila_bloqueados);
            } 
            
            if (d == TRUE) {
                p_processo->infos[k].ativo = FALSE;
                LIS_ExcluirElemento(fila_bloqueados);
            }

            LIS_AvancarElementoCorrente(fila_bloqueados, 1);
        }
    }

    IrInicioLista(fila_bloqueados);

    q = LIS_NumeroElementos(fila_bloqueados);

    /* Percorre todos os processos da fila de bloqueados */
    for (i = 0; i < q; i++) {
        /* Obtém endereço do processo da fila de bloqueados */
        p_processo = LIS_ObterValor(fila_bloqueados);

        for (k = 0; k < p_processo->qtd_info; k++) {
            if ((p_processo->infos[k].ativo == TRUE) && (strcmp(p_processo->infos[k].nome, "io") == 0) && (p_processo->infos[k].tempo == 0)) {
                LIS_ExcluirElemento(fila_bloqueados);
                break;
            }
        }

        LIS_AvancarElementoCorrente(fila_bloqueados, 1);
    }

    IrInicioLista(fila_bloqueados);

    AguardaLeitura(1);

    printf("\n");
    fflush(stdin);
}

/* Função do algoritmo de alocação de memória de ajuste rápido */

void FirstFit(LIS_tppLista fila_prontos, LIS_tppLista fila_bloqueados, mem *M, int qtd_proc, int tempo_total) {

    int i, j, k, qtd_info, c, d, f = FALSE, g, l, q; /* Contadores auxiliares */
    int flag; /* Marcadores auxiliares */
    processo * p_processo; /* Ponteiro para um processo */

    /* Imprime dados sobre os blocos de memória */
    ImprimeMemoria(M);

    /* Obtém primeiro processo na fila de prontos */
    IrInicioLista(fila_prontos);

    l = LIS_NumeroElementos(fila_prontos);
ALOCA:
    for (d = 0; d < l; d++) {
        fflush(stdin);
        printf("-----------------------------------------------------------------------------------\n\n");
        fflush(stdin);
        printf(ANSI_COLOR_MAGENTA "FILA DE PRONTOS" ANSI_COLOR_RESET ":\n\n");
        fflush(stdin);
        printf("-----------------------------------------------------------------------------------\n\n");
        fflush(stdin);

        AguardaLeitura(1);

        /* Imprime dados sobre a fila de prontos */
        ImprimeLista(fila_prontos);

        printf("-----------------------------------------------------------------------------------\n\n");
        fflush(stdin);
        printf(ANSI_COLOR_MAGENTA "PROCESSO A SER ALOCADO" ANSI_COLOR_RESET ":\n\n");
        fflush(stdin);
        printf("-----------------------------------------------------------------------------------\n\n");

        p_processo = LIS_ObterValor(fila_prontos);
        ImprimeProcesso(p_processo);

        printf("É necessário um bloco de memória de %d Mb para comportar o processo %d.\n", p_processo->tamanho, p_processo->numero);
        fflush(stdin);

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

        if (flag == FALSE) {

            c = FALSE;

            /* Percorre todos os blocos de memória */
            for (j = 0; j < QTD_BLOC; j++) {
                /* Se o processo que não pôde ser alocado cabe em algum dos blocos de memória */
                if (M->bloco[j].tamanho >= p_processo->tamanho) {
                    c = TRUE;
                }
            }

            if (c == FALSE) {

                /* Posição de memória não encontrada, pois o processo não coube em nenhum bloco de memória.
                 * Logo, o processo deverá ser destruído. */

                printf("- Posição de memória " ANSI_COLOR_MAGENTA "não" ANSI_COLOR_RESET " encontrada.\n");
                fflush(stdin);

                AguardaLeitura(1);

                /* Exclui processo da fila de prontos */
                LIS_ExcluirElemento(fila_prontos);

                IrInicioLista(fila_prontos);

                /* Exclui informações do processo */
                DestroiProcesso(p_processo);

                /* Subtrai o tempo do processo destruído do tempo total de todos os processos */
                tempo_total = tempo_total - p_processo->tempo_total;

                printf("- Processo " ANSI_COLOR_MAGENTA "destruído" ANSI_COLOR_RESET ".\n\n");
                fflush(stdin);
            } else {
                printf("- Posição de memória " ANSI_COLOR_MAGENTA "não" ANSI_COLOR_RESET " encontrada.\n");
                fflush(stdin);
                printf("- Processo " ANSI_COLOR_MAGENTA "mantido" ANSI_COLOR_RESET " na fila de prontos.\n\n");
                fflush(stdin);

                p_processo = LIS_ObterValor(fila_prontos);

                /* Exclui processo da fila de prontos */
                LIS_ExcluirElemento(fila_prontos);

                LIS_InserirElementoApos(fila_prontos, p_processo);

                IrInicioLista(fila_prontos);
            }

        } else {

            /* Posição de memória encontrada.
             * Processo alocado na memória e retirado da lista de prontos. */

            printf("- Posição de memória encontrada no bloco %d.\n", i + 1);
            fflush(stdin);

            AguardaLeitura(1);

            /* Processo é alocado na memória */
            M->bloco[i].p_processo = p_processo;

            AguardaLeitura(1);

            printf("- Processo %d " ANSI_COLOR_CYAN "alocado" ANSI_COLOR_RESET ".\n\n", p_processo->numero);
            fflush(stdin);

            /* Exclui processo da fila de prontos */
            LIS_ExcluirElemento(fila_prontos);

            IrInicioLista(fila_prontos);

        }

        AguardaLeitura(1);

        printf("-----------------------------------------------------------------------------------\n\n");
        fflush(stdin);
        printf(ANSI_COLOR_MAGENTA "FILA DE PRONTOS" ANSI_COLOR_RESET ":\n\n");
        fflush(stdin);
        printf("-----------------------------------------------------------------------------------\n\n");
        fflush(stdin);
        AguardaLeitura(1);

        /* Imprime dados sobre a fila de prontos */
        ImprimeLista(fila_prontos);

        /* Imprime dados sobre os blocos de memória */
        ImprimeMemoria(M);

    }

    l = LIS_NumeroElementos(fila_prontos);

    /* Enquanto o tempo total de todos os processos for diferente de zero */
    while (tempo_total > 0) {

PERCORRE:
        /* Executa o comando do processo alocado no bloco de memória */
        /* Percorre todos os blocos de memória */
        for (j = 0; j < QTD_BLOC; j++) {
            /* Se o bloco estiver alocado com um processo */
            if (M->bloco[j].p_processo != NULL) {
                for (k = 0; k < M->bloco[j].p_processo->qtd_info; k++) {
                    /* Procura comando não finalizado */
                    /* Se for exec */
                    if ((M->bloco[j].p_processo->infos[k].tempo > 0) && (strcmp(M->bloco[j].p_processo->infos[k].nome, "exec") == 0)) {

                        printf("-----------------------------------------------------------------------------------\n\n");
                        fflush(stdin);
                        printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                        fflush(stdin);
                        printf("-----------------------------------------------------------------------------------\n\n");
                        fflush(stdin);

                        if (LIS_NumeroElementos(fila_bloqueados) == 0) {
                            printf("A fila de bloqueados está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");

                        } else {
                            /* Imprime dados sobre a fila de prontos */
                            ImprimeLista(fila_bloqueados);
                        }

                        M->bloco[j].p_processo->infos[k].ativo = TRUE;

                        Relogio(M, fila_bloqueados, fila_prontos, &tempo_total);

                        M->bloco[j].p_processo->infos[k].ativo = FALSE;

                        /* Imprime dados sobre os blocos de memória */
                        ImprimeMemoria(M);

                        /* Processo finalizado */
                        if (M->bloco[j].p_processo->tempo_total == 0) {

                            /* Libera bloco de memória */
                            M->bloco[j].p_processo = NULL;

                            /* Imprime dados sobre os blocos de memória */
                            ImprimeMemoria(M);
                        }

                        break;

                        //goto ALOCA;

                    }/* Se for io não ativo */
                    else if ((M->bloco[j].p_processo->infos[k].ativo == FALSE) && (M->bloco[j].p_processo->infos[k].tempo > 0) && (strcmp(M->bloco[j].p_processo->infos[k].nome, "io") == 0)) {
                        
                        /* Insere processo na fila de bloqueados */
                        LIS_InserirElementoApos(fila_bloqueados, M->bloco[j].p_processo);

                        M->bloco[j].p_processo->infos[k].ativo = TRUE;

                        printf("-----------------------------------------------------------------------------------\n\n");
                        fflush(stdin);
                        printf(ANSI_COLOR_MAGENTA "FILA DE PRONTOS" ANSI_COLOR_RESET ":\n\n");
                        fflush(stdin);
                        printf("-----------------------------------------------------------------------------------\n\n");
                        fflush(stdin);

                        if (LIS_NumeroElementos(fila_prontos) == 0) {
                            printf("A fila de prontos está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");

                        } else {
                            /* Imprime dados sobre a fila de prontos */
                            ImprimeLista(fila_prontos);
                        }

                        printf("-----------------------------------------------------------------------------------\n\n");
                        fflush(stdin);
                        printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                        fflush(stdin);
                        printf("-----------------------------------------------------------------------------------\n\n");
                        fflush(stdin);

                        if (LIS_NumeroElementos(fila_bloqueados) == 0) {
                            printf("A fila de bloqueados está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");
                            fflush(stdin);

                        } else {

                            /* Imprime dados sobre a fila de bloqueados */
                            ImprimeLista(fila_bloqueados);
                        }

                        /* Imprime dados sobre os blocos de memória */
                        ImprimeMemoria(M);

                        break;
                    } else if ((M->bloco[j].p_processo->infos[k].tempo > 0) && (M->bloco[j].p_processo->infos[k].ativo == TRUE) && (strcmp(M->bloco[j].p_processo->infos[k].nome, "io") == 0)) {
                        
                        Relogio2(M, fila_bloqueados, fila_prontos, &tempo_total);

                        if (LIS_NumeroElementos(fila_bloqueados) == 0) {
                            printf("-----------------------------------------------------------------------------------\n\n");
                            fflush(stdin);
                            printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                            fflush(stdin);
                            printf("-----------------------------------------------------------------------------------\n\n");
                            fflush(stdin);
                            printf("A fila de bloqueados está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");
                        } else {
                            printf("-----------------------------------------------------------------------------------\n\n");
                            fflush(stdin);
                            printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                            fflush(stdin);
                            printf("-----------------------------------------------------------------------------------\n\n");

                            /* Imprime dados sobre a fila de bloqueados */
                            ImprimeLista(fila_bloqueados);
                        }

                        /* Percorre todos os blocos de memória */
                        for (g = 0; g < QTD_BLOC; g++) {
                            
                            /* Processo finalizado */
                            if (M->bloco[g].p_processo != NULL) {
                                if (M->bloco[g].p_processo->tempo_total == 0) {

                                    /* Libera bloco de memória */
                                    M->bloco[g].p_processo = NULL;

                                    /* Imprime dados sobre os blocos de memória */
                                    ImprimeMemoria(M);
                                }
                            }
                        }

                        break;
                    }
                }
            }
        }

        q = FALSE;

        /* Percorre todos os blocos de memória */
        for (j = 0; j < QTD_BLOC; j++) {
            /* Se o bloco de memória está alocado */
            if (M->bloco[j].p_processo != NULL) {
                q = TRUE;
            }
        }

        /* Se a memória está vazia */
        if (q == FALSE) {
            goto ALOCA;
        }

        /* Imprime a fila de prontos após a alocação do processo na memória */
        if (LIS_NumeroElementos(fila_prontos) == 0) {
            printf("-----------------------------------------------------------------------------------\n\n");
            fflush(stdin);
            printf(ANSI_COLOR_MAGENTA "FILA DE PRONTOS" ANSI_COLOR_RESET ":\n\n");
            fflush(stdin);
            printf("-----------------------------------------------------------------------------------\n\n");
            fflush(stdin);
            printf("A fila de prontos está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");
            fflush(stdin);

            if (LIS_NumeroElementos(fila_bloqueados) == 0) {
                printf("-----------------------------------------------------------------------------------\n\n");
                fflush(stdin);
                printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                fflush(stdin);
                printf("-----------------------------------------------------------------------------------\n\n");
                fflush(stdin);
                printf("A fila de bloqueados está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");
            } else {
                printf("-----------------------------------------------------------------------------------\n\n");
                fflush(stdin);
                printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                fflush(stdin);
                printf("-----------------------------------------------------------------------------------\n\n");

                /* Imprime dados sobre a fila de bloqueados */
                ImprimeLista(fila_bloqueados);
            }
        }

    } // While

} // FirstFit

/* Função do algoritmo de alocação de memória de próximo ajuste */

void NextFit(LIS_tppLista fila_prontos, LIS_tppLista fila_bloqueados, mem *M, int qtd_proc, int tempo_total) {

   int i, j, k, qtd_info, c, d, f = FALSE, g, l, q, ultima_posicao = 0; /* Contadores auxiliares */
    int flag; /* Marcadores auxiliares */
    processo * p_processo; /* Ponteiro para um processo */

    /* Imprime dados sobre os blocos de memória */
    ImprimeMemoria(M);

    /* Obtém primeiro processo na fila de prontos */
    IrInicioLista(fila_prontos);

    l = LIS_NumeroElementos(fila_prontos);
    
ALOCA:
    for (d = 0; d < l; d++) {
        fflush(stdin);
        printf("-----------------------------------------------------------------------------------\n\n");
        fflush(stdin);
        printf(ANSI_COLOR_MAGENTA "FILA DE PRONTOS" ANSI_COLOR_RESET ":\n\n");
        fflush(stdin);
        printf("-----------------------------------------------------------------------------------\n\n");
        fflush(stdin);

        AguardaLeitura(1);

        /* Imprime dados sobre a fila de prontos */
        ImprimeLista(fila_prontos);

        printf("-----------------------------------------------------------------------------------\n\n");
        fflush(stdin);
        printf(ANSI_COLOR_MAGENTA "PROCESSO A SER ALOCADO" ANSI_COLOR_RESET ":\n\n");
        fflush(stdin);
        printf("-----------------------------------------------------------------------------------\n\n");

        p_processo = LIS_ObterValor(fila_prontos);
        ImprimeProcesso(p_processo);

        printf("É necessário um bloco de memória de %d Mb para comportar o processo %d.\n", p_processo->tamanho, p_processo->numero);
        fflush(stdin);

        AguardaLeitura(1);

        /* Procura uma posição de memória para alocar o processo */
        i = ultima_posicao;

        flag = FALSE;

        while ((flag == FALSE) && (i < QTD_BLOC)) {
            if ((M->bloco[i].tamanho >= p_processo->tamanho) && (M->bloco[i].p_processo == NULL)) {
                flag = TRUE;
            }
            i++;
        }
        ultima_posicao = i;
        i = i - 1;
        
        if (flag == FALSE) {

            /* Percorre todos os blocos de memória */
            for (f = 0; f < QTD_BLOC; f++) {
                /* Se o processo que não pôde ser alocado cabe em algum dos blocos de memória */
                if ((M->bloco[f].tamanho >= p_processo->tamanho) && (M->bloco[f].p_processo == NULL)) {
                    flag = TRUE;
                    break;
                }
            }

            if (flag == TRUE) {
                i = f;
            }
        }

        if (flag == FALSE) {

            c = FALSE;

            /* Percorre todos os blocos de memória */
            for (j = 0; j < QTD_BLOC; j++) {
                /* Se o processo que não pôde ser alocado cabe em algum dos blocos de memória */
                if (M->bloco[j].tamanho >= p_processo->tamanho) {
                    c = TRUE;
                }
            }

            if (c == FALSE) {

                /* Posição de memória não encontrada, pois o processo não coube em nenhum bloco de memória.
                 * Logo, o processo deverá ser destruído. */

                printf("- Posição de memória " ANSI_COLOR_MAGENTA "não" ANSI_COLOR_RESET " encontrada.\n");
                fflush(stdin);

                AguardaLeitura(1);

                /* Exclui processo da fila de prontos */
                LIS_ExcluirElemento(fila_prontos);

                IrInicioLista(fila_prontos);

                /* Exclui informações do processo */
                DestroiProcesso(p_processo);

                /* Subtrai o tempo do processo destruído do tempo total de todos os processos */
                tempo_total = tempo_total - p_processo->tempo_total;

                printf("- Processo " ANSI_COLOR_MAGENTA "destruído" ANSI_COLOR_RESET ".\n\n");
                fflush(stdin);
            } else {
                printf("- Posição de memória " ANSI_COLOR_MAGENTA "não" ANSI_COLOR_RESET " encontrada.\n");
                fflush(stdin);
                printf("- Processo " ANSI_COLOR_MAGENTA "mantido" ANSI_COLOR_RESET " na fila de prontos.\n\n");
                fflush(stdin);

                p_processo = LIS_ObterValor(fila_prontos);

                /* Exclui processo da fila de prontos */
                LIS_ExcluirElemento(fila_prontos);

                LIS_InserirElementoApos(fila_prontos, p_processo);

                IrInicioLista(fila_prontos);
            }

        } else {

            /* Posição de memória encontrada.
             * Processo alocado na memória e retirado da lista de prontos. */

            printf("- Posição de memória encontrada no bloco %d.\n", i + 1);
            fflush(stdin);

            AguardaLeitura(1);

            /* Processo é alocado na memória */
            M->bloco[i].p_processo = p_processo;

            AguardaLeitura(1);

            printf("- Processo %d " ANSI_COLOR_CYAN "alocado" ANSI_COLOR_RESET ".\n\n", p_processo->numero);
            fflush(stdin);

            /* Exclui processo da fila de prontos */
            LIS_ExcluirElemento(fila_prontos);

            IrInicioLista(fila_prontos);

        }

        AguardaLeitura(1);

        printf("-----------------------------------------------------------------------------------\n\n");
        fflush(stdin);
        printf(ANSI_COLOR_MAGENTA "FILA DE PRONTOS" ANSI_COLOR_RESET ":\n\n");
        fflush(stdin);
        printf("-----------------------------------------------------------------------------------\n\n");
        fflush(stdin);
        AguardaLeitura(1);

        /* Imprime dados sobre a fila de prontos */
        ImprimeLista(fila_prontos);

        /* Imprime dados sobre os blocos de memória */
        ImprimeMemoria(M);

    }

    l = LIS_NumeroElementos(fila_prontos);

    /* Enquanto o tempo total de todos os processos for diferente de zero */
    while (tempo_total > 0) {

PERCORRE:
        /* Executa o comando do processo alocado no bloco de memória */
        /* Percorre todos os blocos de memória */
        for (j = 0; j < QTD_BLOC; j++) {
            /* Se o bloco estiver alocado com um processo */
            if (M->bloco[j].p_processo != NULL) {
                for (k = 0; k < M->bloco[j].p_processo->qtd_info; k++) {
                    /* Procura comando não finalizado */
                    /* Se for exec */
                    if ((M->bloco[j].p_processo->infos[k].tempo > 0) && (strcmp(M->bloco[j].p_processo->infos[k].nome, "exec") == 0)) {

                        printf("-----------------------------------------------------------------------------------\n\n");
                        fflush(stdin);
                        printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                        fflush(stdin);
                        printf("-----------------------------------------------------------------------------------\n\n");
                        fflush(stdin);

                        if (LIS_NumeroElementos(fila_bloqueados) == 0) {
                            printf("A fila de bloqueados está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");

                        } else {
                            /* Imprime dados sobre a fila de prontos */
                            ImprimeLista(fila_bloqueados);
                        }

                        M->bloco[j].p_processo->infos[k].ativo = TRUE;

                        Relogio(M, fila_bloqueados, fila_prontos, &tempo_total);

                        M->bloco[j].p_processo->infos[k].ativo = FALSE;

                        /* Imprime dados sobre os blocos de memória */
                        ImprimeMemoria(M);

                        /* Processo finalizado */
                        if (M->bloco[j].p_processo->tempo_total == 0) {

                            /* Libera bloco de memória */
                            M->bloco[j].p_processo = NULL;

                            /* Imprime dados sobre os blocos de memória */
                            ImprimeMemoria(M);
                        }

                        break;

                        //goto ALOCA;

                    }/* Se for io não ativo */
                    else if ((M->bloco[j].p_processo->infos[k].ativo == FALSE) && (M->bloco[j].p_processo->infos[k].tempo > 0) && (strcmp(M->bloco[j].p_processo->infos[k].nome, "io") == 0)) {
                        
                        /* Insere processo na fila de bloqueados */
                        LIS_InserirElementoApos(fila_bloqueados, M->bloco[j].p_processo);

                        M->bloco[j].p_processo->infos[k].ativo = TRUE;

                        printf("-----------------------------------------------------------------------------------\n\n");
                        fflush(stdin);
                        printf(ANSI_COLOR_MAGENTA "FILA DE PRONTOS" ANSI_COLOR_RESET ":\n\n");
                        fflush(stdin);
                        printf("-----------------------------------------------------------------------------------\n\n");
                        fflush(stdin);

                        if (LIS_NumeroElementos(fila_prontos) == 0) {
                            printf("A fila de prontos está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");

                        } else {
                            /* Imprime dados sobre a fila de prontos */
                            ImprimeLista(fila_prontos);
                        }

                        printf("-----------------------------------------------------------------------------------\n\n");
                        fflush(stdin);
                        printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                        fflush(stdin);
                        printf("-----------------------------------------------------------------------------------\n\n");
                        fflush(stdin);

                        if (LIS_NumeroElementos(fila_bloqueados) == 0) {
                            printf("A fila de bloqueados está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");
                            fflush(stdin);

                        } else {

                            /* Imprime dados sobre a fila de bloqueados */
                            ImprimeLista(fila_bloqueados);
                        }

                        /* Imprime dados sobre os blocos de memória */
                        ImprimeMemoria(M);

                        break;
                    } else if ((M->bloco[j].p_processo->infos[k].tempo > 0) && (M->bloco[j].p_processo->infos[k].ativo == TRUE) && (strcmp(M->bloco[j].p_processo->infos[k].nome, "io") == 0)) {
                        
                        Relogio2(M, fila_bloqueados, fila_prontos, &tempo_total);

                        if (LIS_NumeroElementos(fila_bloqueados) == 0) {
                            printf("-----------------------------------------------------------------------------------\n\n");
                            fflush(stdin);
                            printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                            fflush(stdin);
                            printf("-----------------------------------------------------------------------------------\n\n");
                            fflush(stdin);
                            printf("A fila de bloqueados está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");
                        } else {
                            printf("-----------------------------------------------------------------------------------\n\n");
                            fflush(stdin);
                            printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                            fflush(stdin);
                            printf("-----------------------------------------------------------------------------------\n\n");

                            /* Imprime dados sobre a fila de bloqueados */
                            ImprimeLista(fila_bloqueados);
                        }

                        /* Percorre todos os blocos de memória */
                        for (g = 0; g < QTD_BLOC; g++) {
                            
                            /* Processo finalizado */
                            if (M->bloco[g].p_processo != NULL) {
                                if (M->bloco[g].p_processo->tempo_total == 0) {

                                    /* Libera bloco de memória */
                                    M->bloco[g].p_processo = NULL;

                                    /* Imprime dados sobre os blocos de memória */
                                    ImprimeMemoria(M);
                                }
                            }
                        }

                        break;
                    }
                }
            }
        }

        q = FALSE;

        /* Percorre todos os blocos de memória */
        for (j = 0; j < QTD_BLOC; j++) {
            /* Se o bloco de memória está alocado */
            if (M->bloco[j].p_processo != NULL) {
                q = TRUE;
            }
        }

        /* Se a memória está vazia */
        if (q == FALSE) {
            goto ALOCA;
        }

        /* Imprime a fila de prontos após a alocação do processo na memória */
        if (LIS_NumeroElementos(fila_prontos) == 0) {
            printf("-----------------------------------------------------------------------------------\n\n");
            fflush(stdin);
            printf(ANSI_COLOR_MAGENTA "FILA DE PRONTOS" ANSI_COLOR_RESET ":\n\n");
            fflush(stdin);
            printf("-----------------------------------------------------------------------------------\n\n");
            fflush(stdin);
            printf("A fila de prontos está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");
            fflush(stdin);

            if (LIS_NumeroElementos(fila_bloqueados) == 0) {
                printf("-----------------------------------------------------------------------------------\n\n");
                fflush(stdin);
                printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                fflush(stdin);
                printf("-----------------------------------------------------------------------------------\n\n");
                fflush(stdin);
                printf("A fila de bloqueados está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");
            } else {
                printf("-----------------------------------------------------------------------------------\n\n");
                fflush(stdin);
                printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                fflush(stdin);
                printf("-----------------------------------------------------------------------------------\n\n");

                /* Imprime dados sobre a fila de bloqueados */
                ImprimeLista(fila_bloqueados);
            }
        }

    } // While

} // NextFit

/* Função do algoritmo de alocação de memória de pior ajuste */

void WorstFit(LIS_tppLista fila_prontos, LIS_tppLista fila_bloqueados, mem *M, int qtd_proc, int tempo_total) {


    int i, j, k, qtd_info, c, d, f = FALSE, g, l, q, ultima_posicao = 0; /* Contadores auxiliares */
    int flag, dif, worst, dif_compara; /* Marcadores auxiliares */
    processo * p_processo; /* Ponteiro para um processo */

    /* Imprime dados sobre os blocos de memória */
    ImprimeMemoria(M);

    /* Obtém primeiro processo na fila de prontos */
    IrInicioLista(fila_prontos);

    l = LIS_NumeroElementos(fila_prontos);
ALOCA:
    for (d = 0; d < l; d++) {
        fflush(stdin);
        printf("-----------------------------------------------------------------------------------\n\n");
        fflush(stdin);
        printf(ANSI_COLOR_MAGENTA "FILA DE PRONTOS" ANSI_COLOR_RESET ":\n\n");
        fflush(stdin);
        printf("-----------------------------------------------------------------------------------\n\n");
        fflush(stdin);

        AguardaLeitura(1);

        /* Imprime dados sobre a fila de prontos */
        ImprimeLista(fila_prontos);

        printf("-----------------------------------------------------------------------------------\n\n");
        fflush(stdin);
        printf(ANSI_COLOR_MAGENTA "PROCESSO A SER ALOCADO" ANSI_COLOR_RESET ":\n\n");
        fflush(stdin);
        printf("-----------------------------------------------------------------------------------\n\n");

        p_processo = LIS_ObterValor(fila_prontos);
        ImprimeProcesso(p_processo);

        printf("É necessário um bloco de memória de %d Mb para comportar o processo %d.\n", p_processo->tamanho, p_processo->numero);
        fflush(stdin);

        AguardaLeitura(1);

        /* Procura uma posição de memória para alocar o processo */
        i = 0;
        dif = 0;

        flag = FALSE;

        while (i < QTD_BLOC) {
            if ((M->bloco[i].tamanho >= p_processo->tamanho) && (M->bloco[i].p_processo == NULL)) {
                dif_compara = M->bloco[i].tamanho - p_processo->tamanho;
                if (dif_compara >= dif) {
                    dif = dif_compara;
                    worst = i;
                    flag = TRUE;
                }
            }
            i++;
        }
        i = worst;

        if (flag == FALSE) {

            c = FALSE;

            /* Percorre todos os blocos de memória */
            for (j = 0; j < QTD_BLOC; j++) {
                /* Se o processo que não pôde ser alocado cabe em algum dos blocos de memória */
                if (M->bloco[j].tamanho >= p_processo->tamanho) {
                    c = TRUE;
                }
            }

            if (c == FALSE) {

                /* Posição de memória não encontrada, pois o processo não coube em nenhum bloco de memória.
                 * Logo, o processo deverá ser destruído. */

                printf("- Posição de memória " ANSI_COLOR_MAGENTA "não" ANSI_COLOR_RESET " encontrada.\n");
                fflush(stdin);

                AguardaLeitura(1);

                /* Exclui processo da fila de prontos */
                LIS_ExcluirElemento(fila_prontos);

                IrInicioLista(fila_prontos);

                /* Exclui informações do processo */
                DestroiProcesso(p_processo);

                /* Subtrai o tempo do processo destruído do tempo total de todos os processos */
                tempo_total = tempo_total - p_processo->tempo_total;

                printf("- Processo " ANSI_COLOR_MAGENTA "destruído" ANSI_COLOR_RESET ".\n\n");
                fflush(stdin);
            } else {
                printf("- Posição de memória " ANSI_COLOR_MAGENTA "não" ANSI_COLOR_RESET " encontrada.\n");
                fflush(stdin);
                printf("- Processo " ANSI_COLOR_MAGENTA "mantido" ANSI_COLOR_RESET " na fila de prontos.\n\n");
                fflush(stdin);

                p_processo = LIS_ObterValor(fila_prontos);

                /* Exclui processo da fila de prontos */
                LIS_ExcluirElemento(fila_prontos);

                LIS_InserirElementoApos(fila_prontos, p_processo);

                IrInicioLista(fila_prontos);
            }

        } else {

            /* Posição de memória encontrada.
             * Processo alocado na memória e retirado da lista de prontos. */

            printf("- Posição de memória encontrada no bloco %d.\n", i + 1);
            fflush(stdin);

            AguardaLeitura(1);

            /* Processo é alocado na memória */
            M->bloco[i].p_processo = p_processo;

            AguardaLeitura(1);

            printf("- Processo %d " ANSI_COLOR_CYAN "alocado" ANSI_COLOR_RESET ".\n\n", p_processo->numero);
            fflush(stdin);

            /* Exclui processo da fila de prontos */
            LIS_ExcluirElemento(fila_prontos);

            IrInicioLista(fila_prontos);

        }

        AguardaLeitura(1);

        printf("-----------------------------------------------------------------------------------\n\n");
        fflush(stdin);
        printf(ANSI_COLOR_MAGENTA "FILA DE PRONTOS" ANSI_COLOR_RESET ":\n\n");
        fflush(stdin);
        printf("-----------------------------------------------------------------------------------\n\n");
        fflush(stdin);
        AguardaLeitura(1);

        /* Imprime dados sobre a fila de prontos */
        ImprimeLista(fila_prontos);

        /* Imprime dados sobre os blocos de memória */
        ImprimeMemoria(M);

    }

    l = LIS_NumeroElementos(fila_prontos);

    /* Enquanto o tempo total de todos os processos for diferente de zero */
    while (tempo_total > 0) {

PERCORRE:
        /* Executa o comando do processo alocado no bloco de memória */
        /* Percorre todos os blocos de memória */
        for (j = 0; j < QTD_BLOC; j++) {
            /* Se o bloco estiver alocado com um processo */
            if (M->bloco[j].p_processo != NULL) {
                for (k = 0; k < M->bloco[j].p_processo->qtd_info; k++) {
                    /* Procura comando não finalizado */
                    /* Se for exec */
                    if ((M->bloco[j].p_processo->infos[k].tempo > 0) && (strcmp(M->bloco[j].p_processo->infos[k].nome, "exec") == 0)) {

                        M->bloco[j].p_processo->infos[k].ativo = TRUE;

                        Relogio(M, fila_bloqueados, fila_prontos, &tempo_total);

                        M->bloco[j].p_processo->infos[k].ativo = FALSE;

                        /* Imprime dados sobre os blocos de memória */
                        ImprimeMemoria(M);

                        /* Processo finalizado */
                        if (M->bloco[j].p_processo->tempo_total == 0) {

                            /* Libera bloco de memória */
                            M->bloco[j].p_processo = NULL;

                            /* Imprime dados sobre os blocos de memória */
                            ImprimeMemoria(M);
                        }

                        break;

                        //goto ALOCA;

                    }/* Se for io não ativo */
                    else if ((M->bloco[j].p_processo->infos[k].ativo == FALSE) && (M->bloco[j].p_processo->infos[k].tempo > 0) && (strcmp(M->bloco[j].p_processo->infos[k].nome, "io") == 0)) {

                        /* Insere processo na fila de bloqueados */
                        LIS_InserirElementoApos(fila_bloqueados, M->bloco[j].p_processo);

                        M->bloco[j].p_processo->infos[k].ativo = TRUE;

                        printf("-----------------------------------------------------------------------------------\n\n");
                        fflush(stdin);
                        printf(ANSI_COLOR_MAGENTA "FILA DE PRONTOS" ANSI_COLOR_RESET ":\n\n");
                        fflush(stdin);
                        printf("-----------------------------------------------------------------------------------\n\n");
                        fflush(stdin);

                        if (LIS_NumeroElementos(fila_prontos) == 0) {
                            printf("A fila de prontos está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");

                        } else {
                            /* Imprime dados sobre a fila de prontos */
                            ImprimeLista(fila_prontos);
                        }

                        printf("-----------------------------------------------------------------------------------\n\n");
                        fflush(stdin);
                        printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                        fflush(stdin);
                        printf("-----------------------------------------------------------------------------------\n\n");
                        fflush(stdin);

                        if (LIS_NumeroElementos(fila_bloqueados) == 0) {
                            printf("A fila de bloqueados está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");
                            fflush(stdin);

                        } else {

                            /* Imprime dados sobre a fila de bloqueados */
                            ImprimeLista(fila_bloqueados);
                        }

                        /* Imprime dados sobre os blocos de memória */
                        ImprimeMemoria(M);

                        break;
                    } else if ((M->bloco[j].p_processo->infos[k].tempo > 0) && (M->bloco[j].p_processo->infos[k].ativo == TRUE) && (strcmp(M->bloco[j].p_processo->infos[k].nome, "io") == 0)) {

                        Relogio2(M, fila_bloqueados, fila_prontos, &tempo_total);

                        if (LIS_NumeroElementos(fila_bloqueados) == 0) {
                            printf("-----------------------------------------------------------------------------------\n\n");
                            fflush(stdin);
                            printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                            fflush(stdin);
                            printf("-----------------------------------------------------------------------------------\n\n");
                            fflush(stdin);
                            printf("A fila de bloqueados está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");
                        } else {
                            printf("-----------------------------------------------------------------------------------\n\n");
                            fflush(stdin);
                            printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                            fflush(stdin);
                            printf("-----------------------------------------------------------------------------------\n\n");

                            /* Imprime dados sobre a fila de bloqueados */
                            ImprimeLista(fila_bloqueados);
                        }

                        /* Percorre todos os blocos de memória */
                        for (g = 0; g < QTD_BLOC; g++) {/* Processo finalizado */
                            if (M->bloco[g].p_processo != NULL) {
                                if (M->bloco[g].p_processo->tempo_total == 0) {

                                    /* Libera bloco de memória */
                                    M->bloco[g].p_processo = NULL;

                                    /* Imprime dados sobre os blocos de memória */
                                    ImprimeMemoria(M);
                                }
                            }
                        }

                        break;
                    }
                }
            }
        }

        q = FALSE;

        /* Percorre todos os blocos de memória */
        for (j = 0; j < QTD_BLOC; j++) {
            /* Se o bloco de memória está alocado */
            if (M->bloco[j].p_processo != NULL) {
                q = TRUE;
            }
        }

        /* Se a memória está vazia */
        if (q == FALSE) {
            goto ALOCA;
        }

        /* Imprime a fila de prontos após a alocação do processo na memória */
        if (LIS_NumeroElementos(fila_prontos) == 0) {
            printf("-----------------------------------------------------------------------------------\n\n");
            fflush(stdin);
            printf(ANSI_COLOR_MAGENTA "FILA DE PRONTOS" ANSI_COLOR_RESET ":\n\n");
            fflush(stdin);
            printf("-----------------------------------------------------------------------------------\n\n");
            fflush(stdin);
            printf("A fila de prontos está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");
            fflush(stdin);

            if (LIS_NumeroElementos(fila_bloqueados) == 0) {
                printf("-----------------------------------------------------------------------------------\n\n");
                fflush(stdin);
                printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                fflush(stdin);
                printf("-----------------------------------------------------------------------------------\n\n");
                fflush(stdin);
                printf("A fila de bloqueados está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");
            } else {
                printf("-----------------------------------------------------------------------------------\n\n");
                fflush(stdin);
                printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                fflush(stdin);
                printf("-----------------------------------------------------------------------------------\n\n");

                /* Imprime dados sobre a fila de bloqueados */
                ImprimeLista(fila_bloqueados);
            }
        }

    } // While

} // WorstFit

/* Função do algoritmo de alocação de memória de melhor ajuste */

void BestFit(LIS_tppLista fila_prontos, LIS_tppLista fila_bloqueados, mem *M, int qtd_proc, int tempo_total) {


    int i, j, k, qtd_info, c, d, f = FALSE, g, l, q, ultima_posicao = 0; /* Contadores auxiliares */
    int flag, dif, best, dif_compara; /* Marcadores auxiliares */
    processo * p_processo; /* Ponteiro para um processo */

    /* Imprime dados sobre os blocos de memória */
    ImprimeMemoria(M);

    /* Obtém primeiro processo na fila de prontos */
    IrInicioLista(fila_prontos);

    l = LIS_NumeroElementos(fila_prontos);
ALOCA:
    for (d = 0; d < l; d++) {
        fflush(stdin);
        printf("-----------------------------------------------------------------------------------\n\n");
        fflush(stdin);
        printf(ANSI_COLOR_MAGENTA "FILA DE PRONTOS" ANSI_COLOR_RESET ":\n\n");
        fflush(stdin);
        printf("-----------------------------------------------------------------------------------\n\n");
        fflush(stdin);

        AguardaLeitura(1);

        /* Imprime dados sobre a fila de prontos */
        ImprimeLista(fila_prontos);

        printf("-----------------------------------------------------------------------------------\n\n");
        fflush(stdin);
        printf(ANSI_COLOR_MAGENTA "PROCESSO A SER ALOCADO" ANSI_COLOR_RESET ":\n\n");
        fflush(stdin);
        printf("-----------------------------------------------------------------------------------\n\n");

        p_processo = LIS_ObterValor(fila_prontos);
        ImprimeProcesso(p_processo);

        printf("É necessário um bloco de memória de %d Mb para comportar o processo %d.\n", p_processo->tamanho, p_processo->numero);
        fflush(stdin);

        AguardaLeitura(1);

        /* Procura uma posição de memória para alocar o processo */
        i = 0;
        dif = 1000;

        flag = FALSE;

        while (i < QTD_BLOC) {
            if ((M->bloco[i].tamanho >= p_processo->tamanho) && (M->bloco[i].p_processo == NULL)) {
                dif_compara = M->bloco[i].tamanho - p_processo->tamanho;
                if (dif_compara <= dif) {
                    dif = dif_compara;
                    best = i;
                    flag = TRUE;
                }
            }
            i++;
        }
        i = best;

        if (flag == FALSE) {

            c = FALSE;

            /* Percorre todos os blocos de memória */
            for (j = 0; j < QTD_BLOC; j++) {
                /* Se o processo que não pôde ser alocado cabe em algum dos blocos de memória */
                if (M->bloco[j].tamanho >= p_processo->tamanho) {
                    c = TRUE;
                }
            }

            if (c == FALSE) {

                /* Posição de memória não encontrada, pois o processo não coube em nenhum bloco de memória.
                 * Logo, o processo deverá ser destruído. */

                printf("- Posição de memória " ANSI_COLOR_MAGENTA "não" ANSI_COLOR_RESET " encontrada.\n");
                fflush(stdin);

                AguardaLeitura(1);

                /* Exclui processo da fila de prontos */
                LIS_ExcluirElemento(fila_prontos);

                IrInicioLista(fila_prontos);

                /* Exclui informações do processo */
                DestroiProcesso(p_processo);

                /* Subtrai o tempo do processo destruído do tempo total de todos os processos */
                tempo_total = tempo_total - p_processo->tempo_total;

                printf("- Processo " ANSI_COLOR_MAGENTA "destruído" ANSI_COLOR_RESET ".\n\n");
                fflush(stdin);
            } else {
                printf("- Posição de memória " ANSI_COLOR_MAGENTA "não" ANSI_COLOR_RESET " encontrada.\n");
                fflush(stdin);
                printf("- Processo " ANSI_COLOR_MAGENTA "mantido" ANSI_COLOR_RESET " na fila de prontos.\n\n");
                fflush(stdin);

                p_processo = LIS_ObterValor(fila_prontos);

                /* Exclui processo da fila de prontos */
                LIS_ExcluirElemento(fila_prontos);

                LIS_InserirElementoApos(fila_prontos, p_processo);

                IrInicioLista(fila_prontos);
            }

        } else {

            /* Posição de memória encontrada.
             * Processo alocado na memória e retirado da lista de prontos. */

            printf("- Posição de memória encontrada no bloco %d.\n", i + 1);
            fflush(stdin);

            AguardaLeitura(1);

            /* Processo é alocado na memória */
            M->bloco[i].p_processo = p_processo;

            AguardaLeitura(1);

            printf("- Processo %d " ANSI_COLOR_CYAN "alocado" ANSI_COLOR_RESET ".\n\n", p_processo->numero);
            fflush(stdin);

            /* Exclui processo da fila de prontos */
            LIS_ExcluirElemento(fila_prontos);

            IrInicioLista(fila_prontos);

        }

        AguardaLeitura(1);

        printf("-----------------------------------------------------------------------------------\n\n");
        fflush(stdin);
        printf(ANSI_COLOR_MAGENTA "FILA DE PRONTOS" ANSI_COLOR_RESET ":\n\n");
        fflush(stdin);
        printf("-----------------------------------------------------------------------------------\n\n");
        fflush(stdin);
        AguardaLeitura(1);

        /* Imprime dados sobre a fila de prontos */
        ImprimeLista(fila_prontos);

        /* Imprime dados sobre os blocos de memória */
        ImprimeMemoria(M);

    }

    l = LIS_NumeroElementos(fila_prontos);

    /* Enquanto o tempo total de todos os processos for diferente de zero */
    while (tempo_total > 0) {

PERCORRE:
        /* Executa o comando do processo alocado no bloco de memória */
        /* Percorre todos os blocos de memória */
        for (j = 0; j < QTD_BLOC; j++) {
            /* Se o bloco estiver alocado com um processo */
            if (M->bloco[j].p_processo != NULL) {
                for (k = 0; k < M->bloco[j].p_processo->qtd_info; k++) {
                    /* Procura comando não finalizado */
                    /* Se for exec */
                    if ((M->bloco[j].p_processo->infos[k].tempo > 0) && (strcmp(M->bloco[j].p_processo->infos[k].nome, "exec") == 0)) {

                        M->bloco[j].p_processo->infos[k].ativo = TRUE;

                        Relogio(M, fila_bloqueados, fila_prontos, &tempo_total);

                        M->bloco[j].p_processo->infos[k].ativo = FALSE;

                        /* Imprime dados sobre os blocos de memória */
                        ImprimeMemoria(M);

                        /* Processo finalizado */
                        if (M->bloco[j].p_processo->tempo_total == 0) {

                            /* Libera bloco de memória */
                            M->bloco[j].p_processo = NULL;

                            /* Imprime dados sobre os blocos de memória */
                            ImprimeMemoria(M);
                        }

                        break;

                        //goto ALOCA;

                    }/* Se for io não ativo */
                    else if ((M->bloco[j].p_processo->infos[k].ativo == FALSE) && (M->bloco[j].p_processo->infos[k].tempo > 0) && (strcmp(M->bloco[j].p_processo->infos[k].nome, "io") == 0)) {

                        /* Insere processo na fila de bloqueados */
                        LIS_InserirElementoApos(fila_bloqueados, M->bloco[j].p_processo);

                        M->bloco[j].p_processo->infos[k].ativo = TRUE;

                        printf("-----------------------------------------------------------------------------------\n\n");
                        fflush(stdin);
                        printf(ANSI_COLOR_MAGENTA "FILA DE PRONTOS" ANSI_COLOR_RESET ":\n\n");
                        fflush(stdin);
                        printf("-----------------------------------------------------------------------------------\n\n");
                        fflush(stdin);

                        if (LIS_NumeroElementos(fila_prontos) == 0) {
                            printf("A fila de prontos está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");

                        } else {
                            /* Imprime dados sobre a fila de prontos */
                            ImprimeLista(fila_prontos);
                        }

                        printf("-----------------------------------------------------------------------------------\n\n");
                        fflush(stdin);
                        printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                        fflush(stdin);
                        printf("-----------------------------------------------------------------------------------\n\n");
                        fflush(stdin);

                        if (LIS_NumeroElementos(fila_bloqueados) == 0) {
                            printf("A fila de bloqueados está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");
                            fflush(stdin);

                        } else {

                            /* Imprime dados sobre a fila de bloqueados */
                            ImprimeLista(fila_bloqueados);
                        }

                        /* Imprime dados sobre os blocos de memória */
                        ImprimeMemoria(M);

                        break;
                    } else if ((M->bloco[j].p_processo->infos[k].tempo > 0) && (M->bloco[j].p_processo->infos[k].ativo == TRUE) && (strcmp(M->bloco[j].p_processo->infos[k].nome, "io") == 0)) {

                        Relogio2(M, fila_bloqueados, fila_prontos, &tempo_total);

                        if (LIS_NumeroElementos(fila_bloqueados) == 0) {
                            printf("-----------------------------------------------------------------------------------\n\n");
                            fflush(stdin);
                            printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                            fflush(stdin);
                            printf("-----------------------------------------------------------------------------------\n\n");
                            fflush(stdin);
                            printf("A fila de bloqueados está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");
                        } else {
                            printf("-----------------------------------------------------------------------------------\n\n");
                            fflush(stdin);
                            printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                            fflush(stdin);
                            printf("-----------------------------------------------------------------------------------\n\n");

                            /* Imprime dados sobre a fila de bloqueados */
                            ImprimeLista(fila_bloqueados);
                        }

                        /* Percorre todos os blocos de memória */
                        for (g = 0; g < QTD_BLOC; g++) {/* Processo finalizado */
                            if (M->bloco[g].p_processo != NULL) {
                                if (M->bloco[g].p_processo->tempo_total == 0) {

                                    /* Libera bloco de memória */
                                    M->bloco[g].p_processo = NULL;

                                    /* Imprime dados sobre os blocos de memória */
                                    ImprimeMemoria(M);
                                }
                            }
                        }

                        break;
                    }
                }
            }
        }

        q = FALSE;

        /* Percorre todos os blocos de memória */
        for (j = 0; j < QTD_BLOC; j++) {
            /* Se o bloco de memória está alocado */
            if (M->bloco[j].p_processo != NULL) {
                q = TRUE;
            }
        }

        /* Se a memória está vazia */
        if (q == FALSE) {
            goto ALOCA;
        }

        /* Imprime a fila de prontos após a alocação do processo na memória */
        if (LIS_NumeroElementos(fila_prontos) == 0) {
            printf("-----------------------------------------------------------------------------------\n\n");
            fflush(stdin);
            printf(ANSI_COLOR_MAGENTA "FILA DE PRONTOS" ANSI_COLOR_RESET ":\n\n");
            fflush(stdin);
            printf("-----------------------------------------------------------------------------------\n\n");
            fflush(stdin);
            printf("A fila de prontos está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");
            fflush(stdin);

            if (LIS_NumeroElementos(fila_bloqueados) == 0) {
                printf("-----------------------------------------------------------------------------------\n\n");
                fflush(stdin);
                printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                fflush(stdin);
                printf("-----------------------------------------------------------------------------------\n\n");
                fflush(stdin);
                printf("A fila de bloqueados está " ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET ".\n\n");
            } else {
                printf("-----------------------------------------------------------------------------------\n\n");
                fflush(stdin);
                printf(ANSI_COLOR_MAGENTA "FILA DE BLOQUEADOS" ANSI_COLOR_RESET ":\n\n");
                fflush(stdin);
                printf("-----------------------------------------------------------------------------------\n\n");

                /* Imprime dados sobre a fila de bloqueados */
                ImprimeLista(fila_bloqueados);
            }
        }

    } // While

} // BestFit

#endif	/* UTILITIES_H */