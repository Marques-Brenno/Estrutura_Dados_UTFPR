# 🏥 RedeFarma — Sistema de Gerenciamento de Carrinho, Produtos e Estoque  
Projeto Final da disciplina **Estruturas de Dados I (ED1)** — UTFPR  

Este repositório contém a implementação do sistema **RedeFarma**, que simula o funcionamento de uma rede de farmácias com múltiplas filiais, um catálogo único de produtos e estoques independentes.  
O objetivo do projeto é aplicar estruturas de dados dinâmicas (listas encadeadas), modularização e manipulação de arquivos para resolver um problema completo e realista.

---

## 📌 Funcionalidades

- 📥 **Carregar dados** de produtos, filiais e estoques a partir de arquivos `.txt`
- 🔍 **Pesquisar produtos** por código ou descrição
- 🛒 **Carrinho de compras**
  - Inserir itens
  - Remover itens
  - Consolidar produtos duplicados
  - Atualizar total automaticamente
- 🏪 **Verificação de atendimento por filial**
  - Filiais 100% aptas
  - Relatório de faltas por filial
- 🔄 **Ajuste Automático do Carrinho**
  - Reduz itens conforme estoque disponível da filial escolhida
  - Remove itens que ficam com quantidade zero
  - Atualiza total após ajuste
- 💳 **Finalização da compra**
  - Escolha da filial
  - Abatimento de estoque
  - Geração de relatórios
- 📄 **Relatórios**
  - Estoque atualizado
  - Diagnóstico por filial
  - Pedido final

---

## 🧱 Estruturas Utilizadas

O sistema utiliza apenas **alocação dinâmica e listas encadeadas**, incluindo:

- `Produto`
- `Filial`
- `ItemEstoque`
- `ItemCarrinho`
- `Carrinho`

Cada módulo possui operações dedicadas para inserir, remover, buscar e atualizar dados.

---

