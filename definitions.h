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

/* Tamanhos fixos */

#define TAM_STR     100     /* Tamanho da string máxima */
#define TAM_VET     100     /* Tamanho do vetor máximo */
#define TAM_MEM     16      /* Tamanho da memória em Mb */
#define FATIA_TEMPO 10      /* Time slice dos processos */


/* Erros tratados */

#define ERR_FOPEN   1   /* Erro na abertura de um arquivo */
#define ERR_DUP     2   /* Erro na duplicação de uma entrada ou saída com dup */
#define ERR_DUP2    3   /* Erro na duplicação de uma entrada ou saída com dup2 */
#define ERR_INPUT   4   /* Arquivo de entrada inválido */

/* ESTRUTURAS */

/* Estrutura de uma informação sobre um processo */

struct estrutura_info {
	char nome[5];   /* Nome da informação (exec ou io) */
	int tempo;      /* Tempo de execução para exec ou de espera para io */
};

/* Estrutura de um processo */

struct estrutura_processo {
    int numero;                    /* Número identificador do processo */
    int tamanho;                   /* Tamanho do processo em Mb */
    int qtd_info;                  /* Quantidade de informações do processo */
    time_t inicio_execucao;        /* Horário do início da execução do processo em segundos */
    time_t fim_execucao;           /* Horário do fim da execução do processo em segundos */
    struct estrutura_info *info;   /* Vetor de informações do processo */
};

/* Vetor de estruturas de processos */

struct estrutura_processo processo[TAM_VET];

/* Estrutura de um bloco (partição fixa) de memória */

struct estrutura_bloco_memoria {
	int tamanho;    /* Tamanho do bloco de memória em Mb */
	int isAlocado;  /* Equivale:
                         * - a NULL, caso o bloco de memória não esteja alocado.
                         * - ao número identificador do processo alocado no bloco de memória.
                         */
};

typedef struct estrutura_bloco_memoria bloco_mem;

/* Estrutura da memória */

struct estrutura_memoria {

	int tamanho;            /* Tamanho da memória em Mb */
	bloco_mem bloco[5];     /* Vetor de partições da memória */
	
};

typedef struct estrutura_memoria mem;

#endif	/* DEFINITIONS_H */