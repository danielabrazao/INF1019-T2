/* 
 * =*=*= ARQUIVO DE CABEÇALHO DE DEFINIÇÕES =*=*=
 * Descrição: Arquivo de cabeçalho contendo definições de bibliotecas, macros e tipos.
 * Arquivo: definitions.h criado em 5 de Setembro de 2015, às 12:03.
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

#ifndef DEFINITIONS_H
#define	DEFINITIONS_H

/* BIBLIOTECAS */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <termios.h>
#include <time.h>

/* MACROS */

/* Tamanhos */
#define TAM_STR 100	/* Tamanho da string da mensagem de erro */
#define TAM_VET 100     /* Tamanho do vetor */

/* Erros */
#define ERR_FOPEN       1       /* Erro na abertura de um arquivo */
#define ERR_DUP         2       /* Erro na duplicação de uma entrada ou saída */
#define ERR_DUP2        3       /* Erro na duplicação de uma entrada ou saída */
#define ERR_INPUT	4	/* Entrada inválida */

/* ESTRUTURAS */

/* Estrutura de um processo */
struct estrutura_processo {
    int numero; /* Número identificador do processo */
    int tamanho; /* Tamanho do processo */
    int qtd_info; /* Quantidade de informações do processo */
    time_t inicio_execucao; /* Dia, mês, ano e horário do início da execução do processo. */
    time_t fim_execucao; /* Dia, mês, ano e horário do fim da execução do processo. */
};

/* Vetor de estruturas de processos */
struct estrutura_processo processo[TAM_VET];

/* Estrutura de processo pronto para execução */
struct estrutura_info {
    int numero_processo;    /* Número identificador do processo */
    int tempo_espera;       /* Tempo de espera do processo */
    int tempo_execucao;     /* Tempo de execução do processo */
};

/* Vetor de estruturas de processos prontos para execução */
struct estrutura_info info[TAM_VET];

#endif	/* DEFINITIONS_H */