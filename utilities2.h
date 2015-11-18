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

#include "definitions2.h" /* Arquivo de cabeçalho com definições (includes e defines) */

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


#endif	/* UTILITIES_H */