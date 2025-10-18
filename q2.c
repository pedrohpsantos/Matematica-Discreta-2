/**
 * @description
 * Este programa resolve o problema de "Chaves Periódicas" ao calcular
 * o Mínimo Múltiplo Comum (MMC) de um conjunto de ciclos de tempo.
 * Ele determina o primeiro ano em que todos os ciclos se alinham,
 * respeitando um limite máximo de 50 anos.
 *
 * A interface simula um terminal de um sistema de sincronização temporal.
 */

#include <stdio.h>
#include <stdlib.h>

// Definição de tipo para consistência
typedef long long ll;

//                  PROTÓTIPOS DAS FUNÇÕES PRINCIPAIS

ll mdc(ll a, ll b);
ll mmc(ll a, ll b);
void limpar_buffer();
void run_synchronization_protocol();

//              FUNÇÃO PRINCIPAL: INICIALIZADOR DO SISTEMA

int main() {

  printf("TEMPORAL KEY SYNCHRONIZER v1.0\n");
  printf("[SYSTEM] Inicializando protocolo de alinhamento cíclico...\n");

  // Executa o módulo principal
  run_synchronization_protocol();

  printf("\n[SYSTEM] Protocolo concluído. Encerrando operações.\n\n");
  return 0;
}

//         MÓDULO DE EXECUÇÃO: PROTOCOLO DE SINCRONIZAÇÃO
/**
 * @brief Executa a lógica para encontrar o primeiro ano de sincronização (MMC).
 * @details Coleta os dados de entrada, calcula o MMC sequencialmente e verifica
 * se o resultado está dentro do limite operacional de 50 anos.
 */
void run_synchronization_protocol() {
  int N;
  const int LIMITE_MAXIMO_ANO = 50;
  ll ciclos[10];

  printf("\nMÓDULO: ALINHAMENTO DE CHAVES PERIÓDICAS\n");
  printf("[INFO] Objetivo: Encontrar o primeiro ano de sincronização (MMC) "
         "para N chaves.\n");
  printf("[INFO] Restrição Operacional: O ano de alinhamento não deve exceder "
         "%d.\n",
         LIMITE_MAXIMO_ANO);

  // 1. Leitura e Validação do Número de Chaves (N)
  do {
    printf("\n[INPUT] Insira o número de chaves temporais N (1 a 10): ");
    if (scanf("%d", &N) != 1 || N < 1 || N > 10) {
      printf("[ERROR] Parâmetro N inválido. O valor deve estar entre 1 e 10. "
             "Tente novamente.\n");
      limpar_buffer();
    } else {
      break;
    }
  } while (1);
  limpar_buffer();

  // 2. Leitura e Validação dos Ciclos (C_i)
  printf("[INPUT] Insira os %d períodos de ciclo C (2 a 20), separados por "
         "espaço: ",
         N);
  int entrada_valida = 1;
  for (int i = 0; i < N; i++) {
    if (scanf("%lld", &ciclos[i]) != 1 || ciclos[i] < 2 || ciclos[i] > 20) {
      printf("\n[ERROR] Período de ciclo C[%d] inválido. O valor deve estar "
             "entre 2 e 20.\n",
             i + 1);
      entrada_valida = 0;
      break;
    }
  }
  limpar_buffer();

  if (!entrada_valida) {
    printf("\n[CONCLUSION] Impossibilidade: Dados de entrada corrompidos. "
           "Missão abortada.\n");
    return;
  }

  // 3. Cálculo do Ponto de Sincronização (MMC Sequencial)
  ll ano_sincronizado = 1;
  if (N > 0) {
    ano_sincronizado = ciclos[0];
  }

  printf("\n[LOG] Iniciando cálculo de sincronização...\n");
  printf("  -> Ponto de Sincronia Inicial (baseado em C1): %lld\n",
         ano_sincronizado);

  for (int i = 1; i < N; i++) {
    ll mmc_anterior = ano_sincronizado;
    ano_sincronizado = mmc(ano_sincronizado, ciclos[i]);

    printf("  -> [Passo %d] Calculando MMC(%lld, %lld) -> Novo Ponto de "
           "Sincronia: %lld\n",
           i, mmc_anterior, ciclos[i], ano_sincronizado);

    // Otimização: se o MMC já ultrapassou o limite, não há necessidade de
    // continuar
    if (ano_sincronizado > LIMITE_MAXIMO_ANO) {
      printf("[WARNING] Ponto de sincronia excedeu o limite operacional de %d "
             "anos.\n",
             LIMITE_MAXIMO_ANO);
      break;
    }
  }

  // 4. Relatório Final
  printf("RELATÓRIO DE SINCRONIZAÇÃO\n");

  if (ano_sincronizado > 0 && ano_sincronizado <= LIMITE_MAXIMO_ANO) {
    printf("[STATUS]   SUCESSO\n");
    printf("[MESSAGE]  Alinhamento temporal possível.\n");
    printf("[RESULT]   Primeiro Ano Sincronizado: %-4lld \n", ano_sincronizado);
  } else {
    printf("[STATUS]   IMPOSSIBILIDADE\n");
    printf("[MESSAGE]  Alinhamento excede limite de %d anos.\n",
           LIMITE_MAXIMO_ANO);
    printf("[CALCULADO] Ponto de Sincronia: %-10lld\n", ano_sincronizado);
  }
}

//                FUNÇÕES DE ARITMÉTICA E UTILITÁRIOS

/**
 * @brief Limpa o buffer de entrada (stdin) para evitar leituras incorretas.
 */
void limpar_buffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}

/**
 * @brief Calcula o Máximo Divisor Comum (MDC) de dois números.
 * @note  Versão sem prints para ser usada internamente pelo MMC.
 */
ll mdc(ll a, ll b) {
  a = llabs(a);
  b = llabs(b);
  while (b != 0) {
    ll resto = a % b;
    a = b;
    b = resto;
  }
  return a;
}

/**
 * @brief Calcula o Mínimo Múltiplo Comum (MMC) de dois números.
 * @details Usa a fórmula MMC(a, b) = (|a * b|) / MDC(a, b).
 * A implementação evita overflow multiplicando após a divisão.
 */
ll mmc(ll a, ll b) {
  if (a == 0 || b == 0)
    return 0;
  // Evita overflow calculando (a / mdc) * b ao invés de (a * b) / mdc
  return llabs((a / mdc(a, b)) * b);
}
