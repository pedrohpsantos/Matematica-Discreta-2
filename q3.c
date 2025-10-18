/**
 * @description
 * Este programa calcula a "Razão de Eficiência" de um número inteiro N,
 * definida como a divisão da soma de seus divisores (Sigma) pelo
 * número de seus divisores (Tau).
 *
 * A interface simula um terminal de um sistema de análise matemática.
 */

#include <math.h>
#include <stdio.h>

// Definição de tipo para consistência
typedef long long ll;

//                  PROTÓTIPOS DAS FUNÇÕES PRINCIPAIS

ll power(int base, int exp);
void run_divisor_analysis();

//              FUNÇÃO PRINCIPAL: INICIALIZADOR DO SISTEMA

int main() {

  printf("DIVISOR EFFICIENCY ANALYZER v1.0\n");

  printf("[SYSTEM] Inicializando módulo de análise numérica...\n");

  // Executa o módulo principal
  run_divisor_analysis();

  printf("\n[SYSTEM] Análise concluída. Encerrando operações.\n");

  return 0;
}

//         MÓDULO DE EXECUÇÃO: ANÁLISE DE EFICIÊNCIA

/**
 * @brief Executa a lógica para calcular Tau(N), Sigma(N) e sua razão.
 * @details Coleta N, realiza a fatoração em primos e aplica as fórmulas
 * da teoria dos números para encontrar o resultado.
 */
void run_divisor_analysis() {
  int n;

  printf("\nMÓDULO: CÁLCULO DA RAZÃO DE EFICIÊNCIA\n");
  printf("[INFO] Objetivo: Calcular Sigma(N) / Tau(N) para um inteiro N.\n");

  // 1. Leitura e Validação da Entrada
  printf("\n[INPUT] Insira o número N para análise (1 a 100000): ");
  if (scanf("%d", &n) != 1 || n < 1 || n > 100000) {
    printf("[ERROR] Entrada inválida. O valor de N deve estar no intervalo [1, "
           "100000].\n");
    return;
  }

  // Caso especial N=1
  if (n == 1) {
    printf("[ANALYSIS] N = 1 é um caso base.\n");
    printf("[RESULT] Tau(1) = 1, Sigma(1) = 1.\n");

    printf("RELATÓRIO DE EFICIÊNCIA\n");

    printf("[TARGET]   N = 1\n");
    printf("[RATIO]    Sigma(N) / Tau(N) = 1.00\n");

    return;
  }

  // 2. Fatoração em Primos (Trial Division)
  int temp_n = n;
  ll tau_n = 1;
  ll sigma_n = 1;

  printf("\n[ANALYSIS] Iniciando fatoração de N = %d...\n", n);
  // Fator p=2
  if (temp_n % 2 == 0) {
    int count = 0;
    while (temp_n % 2 == 0) {
      temp_n /= 2;
      count++;
    }
    printf("  -> Fator primo encontrado: 2 ^ %d\n", count);
    tau_n *= (count + 1);
    sigma_n *= (power(2, count + 1) - 1) / (2 - 1);
  }

  // Fatores ímpares a partir de 3
  for (int i = 3; i * i <= temp_n; i += 2) {
    if (temp_n % i == 0) {
      int count = 0;
      while (temp_n % i == 0) {
        temp_n /= i;
        count++;
      }
      printf("  -> Fator primo encontrado: %d ^ %d\n", i, count);
      tau_n *= (count + 1);
      sigma_n *= (power(i, count + 1) - 1) / (i - 1);
    }
  }

  // Se sobrou um fator primo > sqrt(n)
  if (temp_n > 1) {
    printf("  -> Fator primo encontrado: %d ^ 1\n", temp_n);
    tau_n *= 2;                  // (1 + 1)
    sigma_n *= (ll)(temp_n + 1); // (p^2 - 1) / (p - 1) = p + 1
  }

  // 3. Cálculo das Funções e da Razão
  printf("\n[CALCULATION] Funções de Teoria dos Números:\n");
  printf("  -> Tau(N)   = Número de divisores   = %lld\n", tau_n);
  printf("  -> Sigma(N) = Soma dos divisores    = %lld\n", sigma_n);

  double razao = (tau_n != 0) ? (double)sigma_n / tau_n : 0.0;

  // 4. Relatório Final

  printf("RELATÓRIO DE EFICIÊNCIA\n");

  printf("[TARGET]   N = %d\n", n);
  printf("[RATIO]    Sigma(N) / Tau(N) = %-7.2f //\n", fabs(razao));
}

//                     FUNÇÕES DE UTILITÁRIOS

/**
 * @brief Calcula a potência de um número (base^exp).
 * @param base O número base.
 * @param exp O expoente.
 * @return O resultado de base elevado a exp, como long long.
 */
ll power(int base, int exp) {
  ll res = 1;
  for (int i = 0; i < exp; ++i) {
    res *= base;
  }
  return res;
}
