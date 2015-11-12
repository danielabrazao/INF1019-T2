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

#include "definitions.h"    /* Arquivo de header com definições (includes e defines) */
#include "utilities.h"      /* Arquivo de header com utilitários (funções auxiliares) */

/* Função principal */

int main(void) {

    /* ------------------------------------------------- */
    /* PARTE 1: Declaração de variáveis locais da main   */
    /* ------------------------------------------------- */

    int outputfd; /* Descritor de arquivos abertos = Retorno de open */
    int retorno; /* Valor de retorno de dup */
    int retorno2; /* Valor de retorno de dup2 */
    int i = 0, j = 0, m = 1, l = 1, n = 1; /* Contadores auxiliares */
    int numero_processo; /* Número do processo */
    int tamanho_processo; /* Memória requerida pelo processo */
    int qtd_info_processo; /* Total de entradas que descrevem a execução do processo */
    char id; /* Identificador do algoritmo de alocação escolhido */
    int qtd_processos_; /* Quantidade de processos */
    processo *proc_v; /* Vetor de processos */
    int tempo; /* Tempo de execução ou de espera */
    char s[5]; /* Nome da informação do processo */

    /* ------------------------------------------------- */
    /* PARTE 2: Abertura do arquivo de entrada           */
    /* ------------------------------------------------- */

    /* Tratamento de erro para abertura do arquivo 'entrada.txt' */
    if ((outputfd = open("files/entrada.txt", O_RDONLY, 0666)) == -1) {
        showError("Falha na abertura do arquivo 'entrada.txt'.\n", ERR_FOPEN);
        fflush(stdout); // Flush do buffer.
    }

    /* ------------------------------------------------- */
    /* PARTE 3: Redirecionamento da entrada padrão       */
    /* ------------------------------------------------- */

    close(0); /* Fechamento da entrada stdin (teclado). */

    /* Tratamento de erro para duplicação de stdin */
    if ((retorno = dup(outputfd)) == -1) {
        /* Duplicação de stdin (menor descritor fechado) */
        showError("Falha na duplicação de stdin.\n", ERR_DUP);
        fflush(stdout); // Flush do buffer.
    }

    /* ------------------------------------------------- */
    /* PARTE 4: Abertura do arquivo de saída             */
    /* ------------------------------------------------- */

    /* Tratamento de erro para abertura do arquivo 'saida_lp.txt' */
    if ((outputfd = open("files/saida.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1) {
        showError("Falha na abertura do arquivo 'saida.txt'.\n", ERR_FOPEN);
        fflush(stdout); // Flush do buffer.
    }

    /* ------------------------------------------------- */
    /* PARTE 5: Redirecionamento da saída padrão         */
    /* ------------------------------------------------- */

    close(1); /* Fechamento da saída stdout (monitor). */

    /* Tratamento de erro para duplicação de stdout */
    if ((retorno2 = dup2(outputfd, 1)) == -1) {
        /* Duplicação de stdout. */
        showError("Falha na duplicação de stdout.\n", ERR_DUP2);
        fflush(stdout); // Flush do buffer.
    }

    /* ------------------------------------------------- */
    /* PARTE 6: Exibição da mensagem inicial             */
    /* ------------------------------------------------- */

    cabecalho();

    /* ------------------------------------------------- */
    /* PARTE 7: Leitura do arquivo de entrada            */
    /* ------------------------------------------------- */

    printf("LEITURA DO ARQUIVO DE ENTRADA:\n\n");
    printf("-----------------------------------------------------------------------------------\n\n");
    scanf("%d [^\n]", &qtd_processos_); /* Lê a quantidade de processos */
    printf("- Número total de processos: %d\n\n", qtd_processos_);
    fflush(stdout); // Flush do buffer.

    /* Aloca memória para um vetor de processos */
    proc_v = (processo*) malloc(qtd_processos_ * sizeof (processo));

    for (i = 0; i < qtd_processos_; i++) {
        scanf("Processo #%d – %dMb [^\n]", &numero_processo, &tamanho_processo); /* Lê o número identificador do processo e o seu tamanho em Mb */
        proc_v[i].numero = numero_processo;
        proc_v[i].tamanho = tamanho_processo;
        printf("--------------------------------\n");
        printf("PROCESSO #%d\n", proc_v[i].numero);
        printf("--------------------------------\n");
        printf("- Número do processo: %d\n", proc_v[i].numero);
        printf("- Tamanho do processo: %dMb\n", proc_v[i].tamanho);
        scanf("%d [^\n]", &qtd_info_processo);
        proc_v[i].qtd_info = qtd_info_processo;

        /* Aloca memória para um vetor de informações do processo */
        proc_v[i].infos = (info*) malloc(sizeof (info) * qtd_info_processo);
        
        printf("--------------------------------\n");
        
        for (j = 0; j < proc_v[i].qtd_info; j++) {
            scanf("%s %d [^\n]", s, &tempo);
            strcpy(proc_v[i].infos[j].nome, s);
            proc_v[i].infos[j].tempo = tempo;
            printf("- Nome da %da informação: %s\n", l, proc_v[i].infos[j].nome);
            if (strcmp(proc_v[i].infos[j].nome, "io") == 0) {
                printf("- Tempo de espera %d: %ds\n", n, proc_v[i].infos[j].tempo);
                printf("--------------------------------\n");
                n++;
                l++;
            } else {
                printf("- Tempo de execução %d: %ds\n", m, proc_v[i].infos[j].tempo);
                printf("--------------------------------\n");
                m++;
                l++;
            }
        }
        printf("\n");
        l = 1;
        m = 1;
        n = 1;
    }
    
    switch(id)
    {
        
    }

    return 0; /* Sucesso */
}


