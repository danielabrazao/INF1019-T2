/* 
 * =*=*= ARQUIVO DE CABEÇALHO DE UTILITÁRIOS =*=*=
 * Descrição: Arquivo de cabeçalho contendo funções auxiliares.
 * Arquivo: utilities.h criado em 5 de Novembro de 2015, às 12:03.
 * Autoras: 
 * ----------------------------------
 * -> Daniela Brazão Maksoud
 * -> Curso: Ciência da Computação
 * -> Matrícula: 1321873
 * ----------------------------------
 * -> Thaíssa Falbo
 * -> Curso: Engenharia da Computação
 * -> Matrícula: 1421110
 * ----------------------------------
 * Professor: Luiz Fernando Bessa Seibel
 * Instituição: Pontifícia Universidade Católica do Rio de Janeiro
 * Disciplina: Sistemas de Computação (INF1019)
 */

#ifndef UTILITIES_H
#define	UTILITIES_H

#include "definitions.h" /* Arquivo de cabeçalho com definições (includes e defines) */

/* Função que exibe mensagem inicial do interpretador */
void cabecalho() {
    printf("\n--------------------------------------------------------------------\n\n");
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
    printf("--------------------------------------------------------------------\n\n");
}

/* Função que exibe mensagem de erro */
void showError(char str[TAM_STR + 1], int n) {
    printf("Erro %d: %s\n", n, str);
    fflush(stdout); // Flush do buffer.
    exit(n);
}

#endif	/* UTILITIES_H */