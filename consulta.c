#include  "consulta.h"

void ler_consultas(char *nome_diretorio, VetorStr *docs, TST *palavras_tst, TST *stopwords_tst, Graph *grafo){

  double *pagerank = calcula_pagerank(grafo);
  
  char consulta[100];

  FILE *searches = abre_arquivo(nome_diretorio, "searches.txt");
  
  while(fscanf(searches, "%[^\n]\n", consulta) != EOF){
    
    padronizar_string(consulta);

    printf("search:%s\n",consulta);
    
    DocList *resultado = fazer_consulta(consulta, palavras_tst, stopwords_tst);
    
    if(resultado != NULL && get_tamanho_doclist(resultado) != 0){
      ordena_doclist(resultado, pagerank);
    }

    printf("pages:");

    if(resultado != NULL && get_tamanho_doclist(resultado) != 0) print_com_nomes(resultado, docs);
    
    printf("\n");
    printf("pr:");
    
    if(resultado!= NULL && get_tamanho_doclist(resultado) != 0) print_com_pr(resultado, pagerank);
    
    printf("\n");
    
    if (resultado != NULL) free_doclist(resultado);
  }

  printf("\n");

  free(pagerank);
  fclose(searches);
}

DocList* fazer_consulta(char* consulta, TST *palavras_tst, TST *stopwords_tst){
  
  DocList* resultadoAtual = NULL;

  char* palavra = strtok(consulta, " \n\t");

  while (palavra != NULL) {
        
    if (TST_search(stopwords_tst, palavra) != NULL) {
              palavra = strtok(NULL, " \n\t"); 
              continue; 
          }
          break; 
      }
  
  if (palavra == NULL) return NULL;

  DocList* original1 = TST_search(palavras_tst, palavra);
  
  if (original1 == NULL || get_tamanho_doclist(original1) == 0) return NULL;

  resultadoAtual = clona_doclist(original1); 

  while ((palavra = strtok(NULL, " \n\t")) != NULL) {
         
    if (resultadoAtual == NULL || get_tamanho_doclist(resultadoAtual) == 0) {
           break;
      }

    if (TST_search(stopwords_tst, palavra) != NULL) {
              continue;
          }

          
    DocList* original2 = TST_search(palavras_tst, palavra);

    if (original2 == NULL || get_tamanho_doclist(resultadoAtual) == 0) {
        free_doclist(resultadoAtual);
        return NULL; 
    }

    DocList* intersecao = encontra_intersecao(resultadoAtual, original2);

    free_doclist(resultadoAtual);

    resultadoAtual = intersecao;
  }

 return resultadoAtual; 
}
