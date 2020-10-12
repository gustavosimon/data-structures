#include <stdio.h>
void somaprod(int a, int b, int s, int p) {
       s = a + b;
       p = a * b;
}

int main(void) {
       int s, p;
       somaprod(3,5,s,p);
       printf("Soma = %d Produto = %d\n", s, p);
       return 0;
}

/*void sum(int a, int b, int *s, int *p) {
  *s = a + b;
  *p = a * b;
}
int main(void) {
  int s, p;
  sum(3,5, &s, &p);
  printf("A Soma eh = %d \nO Produto eh = %d\n", s, p);
  return 0;
}*/



