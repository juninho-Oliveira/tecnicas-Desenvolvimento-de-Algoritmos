#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ARQUIVO "produtos.txt"
#define CSV "produtos.csv"
#define MAX 100

// Estrutura para armazenar os dados do produto
typedef struct {
    int id;
    char nome[50];
    char categoria[30];
    float preco;
    int quantidade;
    char fornecedor[50];
} Produto;

// Funções auxiliares
int carregarProdutos(Produto lista[]);
void salvarProdutos(Produto lista[], int n);
int gerarID();
int existeProduto(Produto lista[], int n, const char *nome);
void criarProduto();
void listarProdutos();
void buscarPorNome();
void buscarPorCategoria();
void alterarProduto();
void excluirProduto();
void ordenarPorNomeAZ();
void ordenarPorNomeZA();
void ordenarPorPrecoMenorMaior();
void ordenarPorPrecoMaiorMenor();
void exportarCSV();
void exibirTabela(Produto lista[], int n);
void toLowerStr(char *str);

// Função principal
int main() {
    int opcao;
    do {
        printf("\n===== CADASTRO DE PRODUTOS =====\n");
        printf("1. Inserir produto\n");
        printf("2. Listar produtos\n");
        printf("3. Buscar por nome\n");
        printf("4. Buscar por categoria\n");
        printf("5. Alterar produto\n");
        printf("6. Excluir produto\n");
        printf("7. Ordenar por nome (A–Z)\n");
        printf("8. Ordenar por nome (Z–A)\n");
        printf("9. Ordenar por preço (menor–maior)\n");
        printf("10. Ordenar por preço (maior–menor)\n");
        printf("11. Exportar para CSV\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer

        switch (opcao) {
            case 1: criarProduto(); break;
            case 2: listarProdutos(); break;
            case 3: buscarPorNome(); break;
            case 4: buscarPorCategoria(); break;
            case 5: alterarProduto(); break;
            case 6: excluirProduto(); break;
            case 7: ordenarPorNomeAZ(); break;
            case 8: ordenarPorNomeZA(); break;
            case 9: ordenarPorPrecoMenorMaior(); break;
            case 10: ordenarPorPrecoMaiorMenor(); break;
            case 11: exportarCSV(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}

/* ------------------ FUNÇÕES AUXILIARES ------------------ */

// Converte string para minúsculas (para comparação case-insensitive)
void toLowerStr(char *str) {
    for (int i = 0; str[i]; i++)
        str[i] = tolower(str[i]);
}

// Carrega produtos do arquivo para o vetor
int carregarProdutos(Produto lista[]) {
    FILE *f = fopen(ARQUIVO, "r");
    if (!f) return 0;
    int i = 0;
    while (fscanf(f, "%d;%49[^;];%29[^;];%f;%d;%49[^\n]\n",
                  &lista[i].id, lista[i].nome, lista[i].categoria,
                  &lista[i].preco, &lista[i].quantidade, lista[i].fornecedor) == 6)
        i++;
    fclose(f);
    return i;
}

// Salva o vetor de produtos no arquivo
void salvarProdutos(Produto lista[], int n) {
    FILE *f = fopen(ARQUIVO, "w");
    if (!f) {
        printf("Erro ao salvar arquivo!\n");
        return;
    }
    for (int i = 0; i < n; i++)
        fprintf(f, "%d;%s;%s;%.2f;%d;%s\n",
                lista[i].id, lista[i].nome, lista[i].categoria,
                lista[i].preco, lista[i].quantidade, lista[i].fornecedor);
    fclose(f);
}

// Gera ID automático baseado no maior ID existente
int gerarID() {
    Produto lista[MAX];
    int n = carregarProdutos(lista);
    int maxID = 0;
    for (int i = 0; i < n; i++)
        if (lista[i].id > maxID) maxID = lista[i].id;
    return maxID + 1;
}

// Verifica duplicata (nome igual)
int existeProduto(Produto lista[], int n, const char *nome) {
    char nomeBusca[50], nomeLista[50];
    strcpy(nomeBusca, nome);
    toLowerStr(nomeBusca);
    for (int i = 0; i < n; i++) {
        strcpy(nomeLista, lista[i].nome);
        toLowerStr(nomeLista);
        if (strcmp(nomeLista, nomeBusca) == 0)
            return 1;
    }
    return 0;
}

/* ------------------ FUNÇÕES PRINCIPAIS ------------------ */

void criarProduto() {
    Produto lista[MAX];
    int n = carregarProdutos(lista);
    Produto p;

    p.id = gerarID();

    printf("Nome do produto: ");
    fgets(p.nome, 50, stdin); p.nome[strcspn(p.nome, "\n")] = 0;
    if (existeProduto(lista, n, p.nome)) {
        printf("Produto já cadastrado!\n");
        return;
    }

    printf("Categoria: ");
    fgets(p.categoria, 30, stdin); p.categoria[strcspn(p.categoria, "\n")] = 0;
    printf("Preço (R$): ");
    scanf("%f", &p.preco);
    printf("Quantidade: ");
    scanf("%d", &p.quantidade);
    getchar();
    printf("Fornecedor: ");
    fgets(p.fornecedor, 50, stdin); p.fornecedor[strcspn(p.fornecedor, "\n")] = 0;

    lista[n++] = p;
    salvarProdutos(lista, n);
    printf("Produto cadastrado com sucesso! (ID %d)\n", p.id);
}

void listarProdutos() {
    Produto lista[MAX];
    int n = carregarProdutos(lista);
    if (n == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    exibirTabela(lista, n);
}

void buscarPorNome() {
    Produto lista[MAX];
    int n = carregarProdutos(lista);
    char nome[50], nomeLista[50], nomeBusca[50];
    printf("Digite o nome do produto: ");
    fgets(nome, 50, stdin); nome[strcspn(nome, "\n")] = 0;
    strcpy(nomeBusca, nome); toLowerStr(nomeBusca);
    int encontrado = 0;

    for (int i = 0; i < n; i++) {
        strcpy(nomeLista, lista[i].nome);
        toLowerStr(nomeLista);
        if (strstr(nomeLista, nomeBusca)) {
            if (!encontrado) printf("\nResultado da busca:\n");
            printf("[%d] %s - R$ %.2f\n", lista[i].id, lista[i].nome, lista[i].preco);
            encontrado = 1;
        }
    }
    if (!encontrado) printf("Produto não encontrado.\n");
}

void buscarPorCategoria() {
    Produto lista[MAX];
    int n = carregarProdutos(lista);
    char categoria[30], catLista[30], catBusca[30];
    printf("Digite a categoria: ");
    fgets(categoria, 30, stdin); categoria[strcspn(categoria, "\n")] = 0;
    strcpy(catBusca, categoria); toLowerStr(catBusca);
    int encontrado = 0;

    for (int i = 0; i < n; i++) {
        strcpy(catLista, lista[i].categoria);
        toLowerStr(catLista);
        if (strcmp(catLista, catBusca) == 0) {
            if (!encontrado) printf("\nResultado da busca:\n");
            printf("[%d] %s - R$ %.2f\n", lista[i].id, lista[i].nome, lista[i].preco);
            encontrado = 1;
        }
    }
    if (!encontrado) printf("Categoria não encontrada.\n");
}

// Cria arquivo temporário para atualizar registro
void alterarProduto() {
    Produto lista[MAX];
    int n = carregarProdutos(lista);
    int id, encontrado = 0;
    printf("Digite o ID do produto a alterar: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < n; i++) {
        if (lista[i].id == id) {
            printf("Novo nome (%s): ", lista[i].nome);
            fgets(lista[i].nome, 50, stdin); lista[i].nome[strcspn(lista[i].nome, "\n")] = 0;
            printf("Nova categoria (%s): ", lista[i].categoria);
            fgets(lista[i].categoria, 30, stdin); lista[i].categoria[strcspn(lista[i].categoria, "\n")] = 0;
            printf("Novo preço (%.2f): ", lista[i].preco);
            scanf("%f", &lista[i].preco);
            printf("Nova quantidade (%d): ", lista[i].quantidade);
            scanf("%d", &lista[i].quantidade);
            getchar();
            printf("Novo fornecedor (%s): ", lista[i].fornecedor);
            fgets(lista[i].fornecedor, 50, stdin); lista[i].fornecedor[strcspn(lista[i].fornecedor, "\n")] = 0;
            encontrado = 1;
            break;
        }
    }

    if (encontrado) {
        salvarProdutos(lista, n);
        printf("Produto atualizado!\n");
    } else {
        printf("Produto não encontrado.\n");
    }
}

void excluirProduto() {
    Produto lista[MAX];
    int n = carregarProdutos(lista);
    int id, pos = -1;
    printf("Digite o ID do produto a excluir: ");
    scanf("%d", &id);

    for (int i = 0; i < n; i++)
        if (lista[i].id == id) pos = i;

    if (pos == -1) {
        printf("Produto não encontrado.\n");
        return;
    }

    for (int i = pos; i < n - 1; i++)
        lista[i] = lista[i + 1];
    n--;

    salvarProdutos(lista, n);
    printf("Produto excluído com sucesso!\n");
}

/* ------------------ ORDENAÇÕES ------------------ */

// Bubble Sort por nome (A-Z)
void ordenarPorNomeAZ() {
    Produto lista[MAX];
    int n = carregarProdutos(lista);
    Produto temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (strcasecmp(lista[j].nome, lista[j + 1].nome) > 0) {
                temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
    exibirTabela(lista, n);
}

// Z-A
void ordenarPorNomeZA() {
    Produto lista[MAX];
    int n = carregarProdutos(lista);
    Produto temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (strcasecmp(lista[j].nome, lista[j + 1].nome) < 0) {
                temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
    exibirTabela(lista, n);
}

// Preço (menor -> maior)
void ordenarPorPrecoMenorMaior() {
    Produto lista[MAX];
    int n = carregarProdutos(lista);
    Produto temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (lista[j].preco > lista[j + 1].preco) {
                temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
    exibirTabela(lista, n);
}

// Preço (maior -> menor)
void ordenarPorPrecoMaiorMenor() {
    Produto lista[MAX];
    int n = carregarProdutos(lista);
    Produto temp;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (lista[j].preco < lista[j + 1].preco) {
                temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
    exibirTabela(lista, n);
}

// Exporta os dados para CSV
void exportarCSV() {
    Produto lista[MAX];
    int n = carregarProdutos(lista);
    FILE *f = fopen(CSV, "w");
    if (!f) {
        printf("Erro ao criar CSV!\n");
        return;
    }
    fprintf(f, "ID,Produto,Categoria,Preco,Quantidade,Fornecedor\n");
    for (int i = 0; i < n; i++)
        fprintf(f, "%d,%s,%s,%.2f,%d,%s\n",
                lista[i].id, lista[i].nome, lista[i].categoria,
                lista[i].preco, lista[i].quantidade, lista[i].fornecedor);
    fclose(f);
    printf("Arquivo CSV exportado com sucesso!\n");
}

// Exibe a tabela formatada
void exibirTabela(Produto lista[], int n) {
    printf("-------------------------------------------------------------------------------\n");
    printf("| ID | %-20s | %-12s | %-8s | %-10s | %-15s |\n",
           "Produto", "Categoria", "Preço", "Qtd", "Fornecedor");
    printf("-------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
        printf("| %-2d | %-20s | %-12s | %8.2f | %-10d | %-15s |\n",
               lista[i].id, lista[i].nome, lista[i].categoria,
               lista[i].preco, lista[i].quantidade, lista[i].fornecedor);
    printf("-------------------------------------------------------------------------------\n");
}
