/*
 * -----------------------------------------------------------------
 * ~ PROGRAMA PRINCIPAL DO SIMULADOR DE GERENCIADOR DE MEMÓRIA
 * -----------------------------------------------------------------
 * 
 *  Descrição: Arquivo de código fonte contendo o programa principal.
 *  Arquivo: main.c criado em 5 de Novembro de 2015, às 12:00.
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



/* Pré-processamento */

#include "definitions2.h"    /* Arquivo de header com definições (includes e defines) */
#include "utilities2.h"      /* Arquivo de header com utilitários (funções auxiliares) */

int main(void){

 	
	/* ------------------------------------------------- */
    /* PARTE 1: Declaração de variáveis locais da main   */
    /* ------------------------------------------------- */

    int outputfd; /* Descritor de arquivos abertos = Retorno de open */
    int retorno; /* Valor de retorno de dup */
    int i = 0, j = 0, m = 1, l = 1, n = 1, q; /* Contadores auxiliares */
    int numero_processo; /* Número do processo */
    int tamanho_processo; /* Memória requerida pelo processo */
    int qtd_info_processo; /* Total de entradas que descrevem a execução do processo */
    int id; /* Identificador do algoritmo de alocação escolhido */
    int tempo; /* Tempo de execução ou de espera */
    char s[5]; /* Nome da informação do processo (exec ou io) */
    int qtd_processos = 0; /* Quantidade de processos */
    int tempo_total = 0; /* Tempo total de todos os processos */
	processo * p_processo; /* Ponteiro para processo */


 	/* ------------------------------------------------- */
    /* PARTE 2: Abertura do arquivo de entrada           */
    /* ------------------------------------------------- */

    /* Tratamento de erro para abertura do arquivo 'entrada.txt' */
    if ((outputfd = open("files/entrada.txt", O_RDONLY, 0666)) == -1) {
        showError("Falha na abertura do arquivo 'entrada.txt'.\n", ERR_FOPEN);
    }


    /* ------------------------------------------------- */
    /* PARTE 3: Redirecionamento da entrada padrão       */
    /* ------------------------------------------------- */

    close(0); /* Fechamento da entrada stdin (teclado) */

    /* Tratamento de erro para duplicação de stdin */
    if ((retorno = dup(outputfd)) == -1) {
        /* Duplicação de stdin (menor descritor fechado) */
        showError("Falha na duplicação de stdin.\n", ERR_DUP);
    }


    /* ------------------------------------------------- */
    /* PARTE 4: Leitura do arquivo de entrada            */
    /* ------------------------------------------------- */

    printf("-----------------------------------------------------------------------------------\n\n");
    printf(ANSI_COLOR_MAGENTA "LEITURA DO ARQUIVO DE ENTRADA:" ANSI_COLOR_RESET "\n\n");
    printf("-----------------------------------------------------------------------------------\n\n");
    sleep(2);
    scanf("%d [^\n]", &qtd_processos); /* Lê a quantidade de processos */
    printf("- Número total de processos: %d\n\n", qtd_processos);
    sleep(1);


    


    for (i = 0; i < qtd_processos; i++) {

    	 /* Aloca memória para um processo */
    	p_processo = (processo*) malloc(sizeof (processo));
    	if(p_processo == NULL){
    		exit(1);
    	}

    	/* Preenche processo */
    	p_processo->tempo_total = 0;
        scanf("Processo #%d – %dMb [^\n]", &numero_processo, &tamanho_processo); /* Lê o número identificador do processo e o seu tamanho em Mb */
       	p_processo->numero = numero_processo;
        p_processo->tamanho = tamanho_processo;
        printf("-----------------------------------\n");
        printf("PROCESSO #%d\n", p_processo->numero);
        printf("-----------------------------------\n");
        sleep(2);
        printf("- Número do processo: %d\n", p_processo->numero);
        printf("- Tamanho do processo: %dMb\n", p_processo->tamanho);
        printf("-----------------------------------\n");
        sleep(2);
        scanf("%d [^\n]", &qtd_info_processo); /* Lê a quantidade de informações do processo */
        p_processo->qtd_info = qtd_info_processo;
		
		/* Aloca memória para um vetor de informações do processo */
        p_processo->infos = (info*) malloc(sizeof (info) * qtd_info_processo);

        for (j = 0; j < p_processo->qtd_info; j++) {
            scanf("%s %d [^\n]", s, &tempo); /* Lê o nome da informação (exec ou io) e o tempo de execução ou de espera */
            strcpy(p_processo->infos[j].nome, s);
            p_processo->infos[j].tempo = tempo;
            p_processo->tempo_total = p_processo->tempo_total + tempo;
            tempo_total = tempo_total + tempo; /* Tempo total de todos os processos juntos */
            printf("- Nome da %da informação: %s\n", l, p_processo->infos[j].nome);
            if (strcmp(p_processo->infos[j].nome, "io") == 0) {
                printf("- Tempo de espera %d: %ds\n", n, p_processo->infos[j].tempo);
                printf("-----------------------------------\n");
                sleep(2);
                n++;
                l++;
            } else {
                printf("- Tempo de execução %d: %ds\n", m, p_processo->infos[j].tempo);
                printf("-----------------------------------\n");
                sleep(2);
                m++;
                l++;
            }
        }

        /** INSERIR PROCESSO NA FILA!!! **/
        
        printf("\n");
        l = 1;
        m = 1;
        n = 1;



    }

    scanf("%d [^\n]", &id); /* Lê a opção do algoritmo de alocação que deve ser executado */


}

