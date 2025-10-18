#include <stdio.h>
#ifdef WIN32
#include <windows.h>
#endif

// Função para calcular o máximo divisor comum (MDC) com exibição dos passos
int mdcComPassos(int a, int b) {
  int resto;

  printf("\n-- Calculando MDC entre %d e %d --\n", a, b);
  while (b != 0) {
    resto = a % b;
    printf("Algoritmo de Euclides: %d mod %d = %d\n", a, b, resto);
    a = b;
    b = resto;
  }
  printf("-- Fim do cálculo do MDC. Resultado: %d --\n", a);
  return a;
}

// Função para calcular o inverso modular usando o Algoritmo de Euclides

int inversoModular(int a, int m) {
  int m0 = m, t, q;
  int x0 = 0, x1 = 1;
  int A = a, B = m;

  // Apenas para exibir os passos, conforme sugerido pela estrutura
  mdcComPassos(A, B);

  if (m == 1)
    return 0;

  // Algoritmo de Euclides Estendido
  while (a > 1) {
    q = a / m;
    t = m;
    m = a % m, a = t;
    t = x0;
    x0 = x1 - q * x0;
    x1 = t;
  }

  // Garante que o resultado seja positivo
  if (x1 < 0)
    x1 += m0;

  printf("\nSubstituindo, temos que o inverso de %d em %d é %d.\n\n", A, B, x1);
  return x1;
}

// Função para calcular a potência modular de forma eficiente

long long powMod(int base, int exp, int mod) {
  long long res = 1;
  long long b = base % mod;
  while (exp > 0) {
    // Se o expoente for ímpar, multiplica a base no resultado
    if (exp % 2 != 0)
      res = (res * b) % mod;

    // Eleva a base ao quadrado e reduz o expoente pela metade
    b = (b * b) % mod;
    exp >>= 1; // Equivalente a exp = exp / 2;
  }
  return res;
}

int main() {
#ifdef WIN32
  SetConsoleOutputCP(CP_UTF8);
#endif

  int H, G, Zn, x, n1;

  printf("Insira H: ");
  scanf("%d", &H);
  printf("Insira G: ");
  scanf("%d", &G);
  printf("Insira Zn: ");
  scanf("%d", &Zn);
  printf("Insira x: ");
  scanf("%d", &x);
  printf("Insira n1: ");
  scanf("%d", &n1);

  printf("\n");

  // 1. Calcula o inverso para realizar a "divisão"
  int inverso = inversoModular(G, Zn);

  // 2. Realiza a divisão modular (H / G) como uma multiplicação pelo inverso
  int a = (H * inverso) % Zn;

  printf("Fazendo a multiplicação modular: %d * %d mod %d = %d\n", H, inverso,
         Zn, a);

  // 3. Calcula a exponenciação modular final
  int resultado = powMod(a, x, n1);

  printf("Sendo %d o inverso de %d \n", inverso, G);
  printf("Valor final da congruência: %d\n", resultado);

  return 0;
}
