### Primeiro trabalho prático de algoritmos e estrutura de dados 2. 

# Simulador de Servidor de E-mails

## Objetivo
Implementar um simulador de servidor de e-mails com gerenciamento de contas e entrega de mensagens, focando no funcionamento correto do sistema.

## Funcionalidades
- **Cadastro de Usuários**: Criação de caixas de entrada para novos usuários.
- **Remoção de Usuários**: Exclusão de usuários e suas mensagens.
- **Entrega de E-mails**: Armazenamento de e-mails nas caixas de entrada com prioridade.
- **Consulta de E-mails**: Acesso à próxima mensagem prioritária na caixa de entrada do usuário.

## Requisitos Técnicos
- Uso de estruturas de dados como fila, pilha, e lista encadeada.
- Implementação eficiente com alocação dinâmica de memória.
- Armazenamento de mensagens com prioridade.
- Implementação de pelo menos dois Tipos Abstratos de Dados (TADs): para o e-mail e para a caixa de entrada.

## Entrada e Saída
- Entrada: Arquivo de texto com operações.
- Saída: Linha de saída padrão para cada operação.

## Operações
- **CADASTRA ID**: Cria caixa de entrada para usuário.
- **REMOVE ID**: Remove usuário e suas mensagens.
- **ENTREGA ID PRI MSG FIM**: Armazena mensagem na caixa de entrada do usuário.
- **CONSULTA ID**: Retorna a próxima mensagem prioritária.
