
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
        printf("d = %d\n", d);
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

        while ((flag == FALSE) && (i < QTD_BLOC)) {
            if ((M->bloco[i].tamanho >= p_processo->tamanho) && (M->bloco[i].p_processo == NULL)) {
                flag = TRUE;
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

                        printf("entrou no exec\n");
                        fflush(stdin);
                        printf("k = %d\n", k);
                        fflush(stdin);
                        printf("j = %d\n", j);
                        fflush(stdin);

                        M->bloco[j].p_processo->infos[k].ativo = TRUE;

                        Relogio(M, fila_bloqueados, fila_prontos, &tempo_total);

                        M->bloco[j].p_processo->infos[k].ativo = FALSE;

                        /* Imprime dados sobre os blocos de memória */
                        ImprimeMemoria(M);

                        /* Processo finalizado */
                        if (M->bloco[j].p_processo->tempo_total == 0) {

                            printf("milagre\n");
                            fflush(stdin);

                            /* Libera bloco de memória */
                            M->bloco[j].p_processo = NULL;

                            /* Imprime dados sobre os blocos de memória */
                            ImprimeMemoria(M);
                        }

                        break;

                        //goto ALOCA;

                    }/* Se for io não ativo */
                    else if ((M->bloco[j].p_processo->infos[k].ativo == FALSE) && (M->bloco[j].p_processo->infos[k].tempo > 0) && (strcmp(M->bloco[j].p_processo->infos[k].nome, "io") == 0)) {

                        printf("entrou no io\n");
                        fflush(stdin);
                        printf("k = %d\n", k);
                        fflush(stdin);
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

                        printf("k = %d\n", k);
                        fflush(stdin);

                        break;
                    } else if ((M->bloco[j].p_processo->infos[k].tempo > 0) && (M->bloco[j].p_processo->infos[k].ativo == TRUE) && (strcmp(M->bloco[j].p_processo->infos[k].nome, "io") == 0)) {
                        printf("oi\n");
                        fflush(stdin);

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

                        printf("processo %d\n", M->bloco[j].p_processo->numero);
                        fflush(stdin);

                        /* Percorre todos os blocos de memória */
                        for (g = 0; g < QTD_BLOC; g++) {/* Processo finalizado */
                            if (M->bloco[g].p_processo != NULL) {
                                if (M->bloco[g].p_processo->tempo_total == 0) {

                                    printf("milagre\n");
                                    fflush(stdin);

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

}
