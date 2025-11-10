#include <stdio.h>

#define MAX_DISCIPLINAS 50 

struct Disciplina { 
    int id;
    char nome[50];
    char professor[50];
    char semestre[20];
    char curso[50];
};

struct Disciplina disciplinas[MAX_DISCIPLINAS];
int contador = 0;

void carregar() {
    FILE *arquivo = fopen("disciplinas.txt", "r");
    if (arquivo == NULL) {
        return;
    }
    contador = 0;
    while (fscanf(arquivo, "%d;%49[^;];%49[^;];%19[^;];%49[^\n]\n",
                  &disciplinas[contador].id,
                  disciplinas[contador].nome,
                  disciplinas[contador].professor,
                  disciplinas[contador].semestre,
                  disciplinas[contador].curso) == 5) {
        contador++;
    }
    fclose(arquivo);
}

void salvar() {
    FILE *arquivo = fopen("disciplinas.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao salvar arquivo.\n");
        return;
    }
    for (int i = 0; i < contador; i++) {
        fprintf(arquivo, "%d;%s;%s;%s;%s\n",
                disciplinas[i].id,
                disciplinas[i].nome,
                disciplinas[i].professor,
                disciplinas[i].semestre,
                disciplinas[i].curso);
    }
    fclose(arquivo);
}

void cadastrar() {
    if (contador >= MAX_DISCIPLINAS) {
        printf("Limite atingido.\n");
        return;
    }
    disciplinas[contador].id = contador + 1;
    printf("Nome: ");
    scanf(" %[^\n]", disciplinas[contador].nome);
    printf("Professor: ");
    scanf(" %[^\n]", disciplinas[contador].professor);
    printf("Semestre: ");
    scanf(" %[^\n]", disciplinas[contador].semestre);
    printf("Curso: ");
    scanf(" %[^\n]", disciplinas[contador].curso);
    contador++;
    salvar();
    printf("Disciplina cadastrada!\n");
}

void listar() {
    if (contador == 0) {
        printf("Nenhuma disciplina cadastrada.\n");
        return;
    }
    printf("\n--- Disciplinas cadastradas ---\n");
    for (int i = 0; i < contador; i++) {
        printf("%d - %s | Prof: %s | %s | %s\n",
               disciplinas[i].id,
               disciplinas[i].nome,
               disciplinas[i].professor,
               disciplinas[i].semestre,
               disciplinas[i].curso);
    }
}
 
int main() {
    int opcao;
    carregar();

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Listar disciplinas\n");
        printf("2 - Cadastrar disciplina\n");
        printf("3 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1)
            listar();
        else if (opcao == 2)
            cadastrar();
        else if (opcao != 3)
            printf("Opção inválida.\n");

    } while (opcao != 3);

    printf("Programa encerrado.\n");
    return 0;
}