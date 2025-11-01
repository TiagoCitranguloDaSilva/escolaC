#include <stdio.h>

struct aluno{
    int ID;
    char nome[50];
    int dia, mes, ano;
    char curso[100];
    int anoIngresso;
    char telefone[11];
    char endereco[100];
};
int contadorID = 0;

void consultarAlunos() {
    char letra, nomeArquivo[10];

    for (int i = 0; i < 26; i++) {
        letra = 'A' + i;
        nomeArquivo[0] = letra;
        nomeArquivo[1] = '.';
        nomeArquivo[2] = 't';
        nomeArquivo[3] = 'x';
        nomeArquivo[4] = 't';
        nomeArquivo[5] = '\0';

        FILE *arquivo = fopen(nomeArquivo, "r");
        printf("\nLetra %c:\n", letra);

        if (arquivo == NULL) {
            printf("Nao tem nenhum aluno\n");
            continue;
        }

        char linha[200];
        int temAluno = 0;
        while (fgets(linha, sizeof(linha), arquivo)) {
            printf("%s", linha);
            temAluno = 1;
        }

        if (!temAluno) {
            printf("Nao tem nenhum aluno\n");
        }

        fclose(arquivo);
    }
}

void gerenciarContador(int salvar) {
    if (salvar) {
        FILE *arquivo = fopen("ultimo_id.txt", "w");
        if (arquivo != NULL) {
            fprintf(arquivo, "%d", contadorID);
            fclose(arquivo);
        }
    } else {
        FILE *arquivo = fopen("ultimo_id.txt", "r");
        if (arquivo != NULL) {
            fscanf(arquivo, "%d", &contadorID);
            fclose(arquivo);
        } else{
            contadorID = 0;
        }
    }
}

void cadastrarAlunos(){
    struct aluno a;
    contadorID++;
    a.ID = contadorID;

    printf("=== CADASTRO DE ALUNOS ===\n");

    printf("Nome: ");
    scanf(" %[^\n]", a.nome);
    printf("Data de nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &a.dia, &a.mes, &a.ano);
    printf("Curso: ");
    scanf(" %[^\n]", a.curso);
    printf("Ano de ingressao: ");
    scanf("%d", &a.anoIngresso);
    printf("Telefone: ");
    scanf("%s", a.telefone);
    printf("Endereco: ");
    scanf(" %[^\n]", a.endereco);
    printf("%s recebeu o numero %d\n",a.nome, a.ID);
    salvarAluno(a);
}
void salvarAluno(struct aluno a){
    char letra = a.nome[0];
    if (letra >= 'a' && letra <= 'z'){
        letra = letra - ('a' - 'A');
    }
    
    char nomeArquivo[10];
    nomeArquivo[0] = letra;
    nomeArquivo[1] = '.';
    nomeArquivo[2] = 't';
    nomeArquivo[3] = 'x';
    nomeArquivo[4] = 't';
    nomeArquivo[5] = '\0';

    FILE *arquivoAluno = fopen(nomeArquivo, "a");
    if (arquivoAluno == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }
    fprintf(arquivoAluno, "ID: %d\n", a.ID);
    fprintf(arquivoAluno, "Nome: %s\n", a.nome);
    fprintf(arquivoAluno, "Data de nascimento: %02d/%02d/%04d\n", a.dia, a.mes, a.ano);
    fprintf(arquivoAluno, "Curso: %s\n", a.curso);
    fprintf(arquivoAluno, "Ano de ingresso: %d\n", a.anoIngresso);
    fprintf(arquivoAluno, "Telefone: %s\n", a.telefone);
    fprintf(arquivoAluno, "Endereco: %s\n", a.endereco);
    fprintf(arquivoAluno, "---\n");
    fclose(arquivoAluno);
}
//TODO EDITAR ALUNO
int main(){
    gerenciarContador(0);
    cadastrarAlunos();
    gerenciarContador(1);
    // consultarAlunos();
    return 0;
}