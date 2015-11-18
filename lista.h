/* TAD Lista */


typedef enum {

         LIS_CondRetOK ,
               /* Concluiu corretamente */

         LIS_CondRetListaVazia ,
               /* A lista nсo contжm elementos */

         LIS_CondRetFimLista ,
               /* Foi atingido o fim de lista */

         LIS_CondRetNaoAchou ,
               /* Nсo encontrou o valor procurado */

         LIS_CondRetFaltouMemoria
               /* Faltou memзria ao tentar criar um elemento de lista */

   } LIS_tpCondRet ;


typedef struct LIS_tagLista * LIS_tppLista ;


LIS_tppLista LIS_CriarLista( void   ( * ExcluirValor ) ( void * pDado ) );

void LIS_DestruirLista( LIS_tppLista pLista ) ;

void LIS_EsvaziarLista( LIS_tppLista pLista ) ;

LIS_tpCondRet LIS_InserirElementoAntes( LIS_tppLista pLista , void * pValor        ) ;

LIS_tpCondRet LIS_InserirElementoApos( LIS_tppLista pLista , void * pValor        );

LIS_tpCondRet LIS_ExcluirElemento( LIS_tppLista pLista ) ;

void * LIS_ObterValor( LIS_tppLista pLista ) ;

void IrInicioLista( LIS_tppLista pLista ) ;

void IrFinalLista( LIS_tppLista pLista ) ;

 LIS_tpCondRet LIS_AvancarElementoCorrente( LIS_tppLista pLista ,  int numElem) ;

LIS_tpCondRet LIS_ProcurarValor( LIS_tppLista pLista , void * pValor) ;
