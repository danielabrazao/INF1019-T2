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

        M->bloco[i].p_processo = NULL;
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


void DestroiProcesso(processo * pProcesso){
    free(pProcesso);
}


void ImprimeProcesso(processo * p_processo){
    
    int i;

    printf("-------- Imprimindo Processo --------\n");
    printf("Numero: %d\n", p_processo->numero);                   /* Número identificador do processo */
    printf("Tamanho: %d\n", p_processo->tamanho);                 /* Tamanho do processo em Mb */
    printf("Quantidade de informação: %d\n", p_processo->qtd_info);        /* Quantidade de informações do processo */
    
    for(i=0;i<p_processo->qtd_info;i++){                            /* Vetor de informações do processo */
        printf("Nome da info:: %s\n", p_processo->infos[i].nome);
        printf("Tempo da info: %d\n", p_processo->infos[i].tempo);

    }                
    printf("Tempo total: %d\n", p_processo->tempo_total); 

}

void ImprimeMemoria(mem *M){
    int i;
    printf("---- Imprimindo Memória -----\n");
    for(i=0;i<QTD_BLOC;i++){
        printf("------------------\n");
        printf("Posicao: %d\n", i);
        printf("Tamanho bloco: %d\n", M->bloco[i].tamanho);
        if(M->bloco[i].p_processo != NULL){
            printf("Processo alocado: %d\n", M->bloco[i].p_processo->numero);
            printf("Tamanho do processo alocado: %d\n", M->bloco[i].p_processo->tamanho);
        }else{
            printf("Vazio\n");
        }
    }

}


void first_fit(LIS_tppLista lista_prontos, mem *M, int qtd_proc, int tempo_total) {
    int tempo=0,flag,i;
    processo * p_processo;


    printf(ANSI_COLOR_MAGENTA "MAPA DE MEMÓRIA" ANSI_COLOR_RESET ":\n\n");
    printf("-----------------------------------------------------------------------------------\n\n");
    

    ImprimeMemoria(M);


    /* Tempo total de todos os processos dividido pela fatia de tempo */
    if (tempo_total >= FATIA_TEMPO) {
        tempo = qtd_proc;
    }

    printf("Tempo total = %d\n\n", tempo);


    IrInicioLista(lista_prontos);
    /* Pega o primeiro processo */

    p_processo = LIS_ObterValor(lista_prontos);

    ImprimeProcesso(p_processo);

    printf("Preciso de %d de memoria para este processo...\n", p_processo->tamanho);

    // Procurando posicao de memoria
    i=0;
    flag = FALSE;
    while((flag == FALSE) && (i<QTD_BLOC)){
        if(M->bloco[i].tamanho >= p_processo->tamanho){
            flag = TRUE;
        }
        i++;
    }
    i-=1;

    if(flag==FALSE){  // Nao encontrei posicao de memoria, devo destruir o processo
        printf("Nao encontrei posicao de memoria, devo destruir o processo\n");
        LIS_ExcluirElemento(lista_prontos);
        DestroiProcesso(p_processo);
    }else{  // Encontrei posicao de memoria, aloco o processo na memoria e retiro da lista de prontos.
        printf("Encontrei posicao de memoria, vou alocar o processo\n");
        M->bloco[i].p_processo = p_processo;
        LIS_ExcluirElemento(lista_prontos);
    }


    ImprimeMemoria(M);





}


#endif	/* UTILITIES_H */