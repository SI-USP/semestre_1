# Gestão de processos (parte 2)

## Etapas de um ciclo de vida de um processo

### Modelagem

Etapa de esquematização de um processo, usualmente expressa em **notação gráfica**[^1].

**Pré-modelagem:** Etapa de coleção dos requisitos do processo.

**Pós-modelagem:** Etapa de validação e simulação do modelo criado.

### Implementação

Criação de um "**executável**" do processo baseado no modelo deste. No contexto de SIs, buscando-se automatizar nalgum nível este processo. Isso, seja com o uso de scripts ou mesmo a criação de um novo programa com o uso de linguagens de programação.

**Pré-implementação:** fase de definição das linguagens de programação, ambientes de desenvolvimento, e SIs a serem usados e integrados.

**Pós-implementação:** fase de realização de testes no processo implementado (caixa branca, caixa preta, etc.).

### Execução e monitoramento

Etapa de uso de uma ou mais instâncias de **servidor de aplicação** para realização do processo.

### Otimização

Em geral, as aplicações que executam processos produzem **logs de execução** os quais podem ser usados quando busca-se otimizar o processo. À partir desses é possível aferir e corrigir:

- Falhas de segurança ou disponibilidade;

- Reduções de desempenho.

Ou mesmo, objetivar reiniciar o ciclo de vida do processo.

[^1]: Como o **BPMN** (Bussiness Process Model and Notation).
