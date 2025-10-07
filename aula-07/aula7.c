
#include <stdio.h>

int main()
{
    FILE *arquivo = fopen("dados.txt", "w");// criar arquivo(modelo escrita)
    if(arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }
    
    fprintf(arquivo, "Nome: Maria\nIdade: 25\nCidade: Recife\n");
    fclose(arquivo);
    printf("Arquivo criado e dados gravados com sucesso!\n");
    return 0;
    /*
    #include <stdio.h>

int main()
{
    FILE *arquivo = fopen("dados.txt", "a");// Modo de anexar

    if(arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }
    fprintf(arquivo, "Profissão: Engenheira\n");
    fclose(arquivo);
    printf("Novo dado adicionado ao arquivo!\n");


    FILE *arquivo = fopen("dados.txt", "r");// abre para leitura
    char linha[100];
    
    if(arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }
    
    printf("Conteudo do arquivo:\n");
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }
    
    fclose(arquivo);
    return 0;
}
    
    */
}