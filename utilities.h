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

/* Função que exibe mensagem de erro */

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

/* Função que imprime dados sobre o processo */

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
        } else {
            printf("- Bloco vazio.\n");
        }
    }

    printf("-------------------------------------\n\n");
}

/* Função que imprime dados sobre a lista */

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

    IrInicioLista(p_lista);
}

/* Função do algoritmo de ajuste rápido */

void FirstFit(LIS_tppLista fila_prontos, mem *M, int qtd_proc, int tempo_total) {

    int flag, i;
    processo * p_processo;

    ImprimeMemoria(M);

    while (LIS_NumeroElementos(fila_prontos) > 0) {

        printf("-----------------------------------------------------------------------------------\n\n");
        printf(ANSI_COLOR_MAGENTA "FILA DE PRONTOS" ANSI_COLOR_RESET ":\n\n");
        printf("-----------------------------------------------------------------------------------\n\n");


        if (op == TRUE) {
            sleep(1);
        }

        ImprimeLista(fila_prontos);

        printf("-----------------------------------------------------------------------------------\n\n");
        printf(ANSI_COLOR_MAGENTA "PROCESSO A SER ALOCADO" ANSI_COLOR_RESET ":\n\n");
        printf("-----------------------------------------------------------------------------------\n\n");


        /* Obtém primeiro processo na fila de prontos */
        IrInicioLista(fila_prontos);
        p_processo = LIS_ObterValor(fila_prontos);
        ImprimeProcesso(p_processo);
        printf("É necessário um bloco de memória de %d Mb para comportar o processo %d.\n", p_processo->tamanho, p_processo->numero);

        // *** Procurando posicao de memoria para alocar o processo
        i = 0;

        flag = FALSE;

        while ((flag == FALSE) && (i < QTD_BLOC)) {
            if ((M->bloco[i].tamanho >= p_processo->tamanho) && (M->bloco[i].p_processo == NULL)) {
                flag = TRUE;
            }
            i++;
        }
        i = i - 1;

        if (flag == FALSE) { // Nao encontrei posicao de memoria, devo destruir o processo
            printf("- Posição de memória não encontrada.\n");
            LIS_ExcluirElemento(fila_prontos);
            DestroiProcesso(p_processo);
            printf("- Processo destruído.\n");
        } else { // Encontrei posicao de memoria, aloco o processo na memoria e retiro da lista de prontos.
            printf("- Posição de memória encontrada.\n");
            M->bloco[i].p_processo = p_processo;
            printf("- Processo %d alocado.\n\n", p_processo->numero);
            LIS_ExcluirElemento(fila_prontos);
            IrInicioLista(fila_prontos);
        }

        ImprimeMemoria(M);

        /* Imprime a fila de prontos após a alocação */
        if (LIS_NumeroElementos(fila_prontos) == 0) {
            printf("A fila de prontos está ");
            printf(ANSI_COLOR_MAGENTA "vazia" ANSI_COLOR_RESET);
            printf(".\n\n");
        } else {
            ImprimeLista(fila_prontos);
        }

        /* 
        Executar processo a partir daqui!!! 
        Criar função que reduz o tempo de todos os processos em exec e em IO
        
         */



    }//while


}//fist_fit
#endif	/* UTILITIES_H */