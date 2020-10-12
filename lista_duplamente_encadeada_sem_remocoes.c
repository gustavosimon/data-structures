#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Pessoa {
  char nome[20];
  int cod;
  struct Pessoa * anterior;
  struct Pessoa * proximo;
};
typedef struct Pessoa Pessoa;
struct descritor_lista {
  Pessoa * inicio;
  Pessoa * fim;
  int tamanho;
};
typedef struct descritor_lista TipoDescritorLista;

/* Criação de uma lista vazia */
void cria_lista(TipoDescritorLista * descritor_lista) {
  descritor_lista -> inicio = NULL;
  descritor_lista -> fim = NULL;
}
void lePessoa(struct Pessoa * aux) {
  printf("Nome: ");
  scanf("%[^\n]", aux->nome);
  fflush(stdin);
  printf("Codigo: ");
  scanf("%d", &aux->cod);
  fflush(stdin);
}
/* Inserindo no final da lista */
void insere_lista_fim(TipoDescritorLista * descritor_lista) {
  Pessoa * novo = (Pessoa * ) malloc(sizeof(Pessoa));
  lePessoa(novo);
  if (!descritor_lista -> inicio) {
    novo -> proximo = NULL;
    novo -> anterior = NULL;
    descritor_lista -> inicio = novo;
  } else {
    novo -> proximo = NULL;
    novo -> anterior = descritor_lista -> fim;
    descritor_lista -> fim -> proximo = novo;
  }
  descritor_lista -> fim = novo;
}
int verifica_lista_vazia(TipoDescritorLista * descritor_lista) {
  return (descritor_lista -> inicio == NULL);
}

/* Imprime os nodos da lista */
void imprime_lista(TipoDescritorLista * descritor_lista) {
  if (verifica_lista_vazia(descritor_lista)) printf("Lista vazia");
  else {
    Pessoa * p;
    for (p = descritor_lista -> inicio; p != NULL; p = p -> proximo) 
      printf("%s\t%d\t", p -> nome, p -> cod);
  }
}

void remover(TipoDescritorLista * lista, int numNodos) {
    while(numNodos != 0) {
		Pessoa* paux = lista->fim;      
	    paux->anterior->proximo = NULL;
		lista->fim = paux->anterior;
	    lista->tamanho--;
	    free(paux);
	    numNodos--;
	}
}

int main() {
  TipoDescritorLista * descritor_lista;
  descritor_lista = (TipoDescritorLista * ) malloc(sizeof(TipoDescritorLista));
  cria_lista(descritor_lista);
  insere_lista_fim(descritor_lista);
  insere_lista_fim(descritor_lista);
  insere_lista_fim(descritor_lista);
  insere_lista_fim(descritor_lista);

  imprime_lista(descritor_lista);

  remover(descritor_lista, 2);

  printf("\n");
  imprime_lista(descritor_lista);
  return 0;
}
