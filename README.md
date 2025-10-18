# 💥 Projeto: RSA & Números — MD2 na Veia

**Disciplina:** Matemática Discreta II (MD2)  
**Curso:** Engenharia de Software — UnB (FGA)  
**Professor:** Cristiane Loesch de Souza Costa · **Turma:** T01  
**Entrega:** **18/10/2025** às 12:00  

---

## 👥 Time

| Nome | Matrícula |
|:--|:--|
| Pedro Henrique Pereira Santos | 232038442 |
| Lucas de Paula Leal | 232004480 |

---

## 🚀 Missão: O que fizemos

Criamos uma suíte de utilitários em **C** para brincar sério com teoria dos números. Sem pegar atalhos: todo o RSA, fatorações, MMC, funções divisor → implementados do zero. O objetivo? Fazer você entender cada linha de código — ver o algoritmo respirar.  

Também incluímos logs estilo “pane de missão” no terminal, pra deixar visível o que tá rolando. 

---

## 🛠 Ferramentas (o arsenal)

| Codinome | Função principal |
|--|--|
| **Q01 — CryptoAgent: Mission RSA** (1,0 pt) | Gera chaves RSA, fatora com Rho de Pollard, criptografa/decripta, e valida que tudo voltou igual ao original. |
| **Q02 — TemporalKey Sync: Chrono-Protocol** (0,5 pt) | Busca o primeiro momento em que vários ciclos assíncronos se alinham (MMC) num horizonte de 50 anos. |
| **Q03 — Divisor Analyzer: Numeric Efficiency Probe** (0,5 pt) | Fatora N, calcula número de divisores τ(N) e soma σ(N), mede uma “Razão de Eficiência” da estrutura do número. |
| **Q04 — Code Analysis: Modular Arithmetic Core** (bônus 0,5 pt) | Completa funções faltantes, analisa execução modular, assegura que todo cálculo modular esteja redondinho. |

---

## ⚙️ Como compilar e rodar

Todos usam GCC + `-lm` (biblioteca matemática).  

```bash
# Q01 — RSA
gcc q1.c -o rsa_agent -lm
./rsa_agent

# Q02 — TemporalKey Sync
gcc q2.c -o key_sync -lm
./key_sync

# Q03 — Divisor Analyzer
gcc q3.c -o divisor_analyzer -lm
./divisor_analyzer

# Q04 — Code Analysis
gcc q4.c -o q4_analysis
./q4_analysis
```
---
## Questão 4 (Verdadeiro ou Falso)
### V, F, V, V, F, V, V
