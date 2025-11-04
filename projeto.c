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
void salvarAlunoDiminuido(struct aluno a){
    char letra = a.nome[0];
    if(letra >= 'a' && letra <= 'z'){
        letra = letra - ('a' - 'A');
    }

    char nomeArquivo[10];
    nomeArquivo[0] = letra;
    nomeArquivo[1] = 'D';
    nomeArquivo[2] = '.';
    nomeArquivo[3] = 't';
    nomeArquivo[4] = 'x';
    nomeArquivo[5] = 't';
    nomeArquivo[6] = '\0';

    FILE *arquivoAluno = fopen(nomeArquivo, "a");
    if (arquivoAluno == NULL){
        printf("Aluno nao encontrado");
        return;
    }
    fprintf(arquivoAluno, "ID: %d\n", a.ID);
    fprintf(arquivoAluno, "Nome: %s\n", a.nome);
    fclose(arquivoAluno);
}
void consultarAlunos() {
    char letra, nomeArquivo[10];
    int i;
    

    for (i = 0; i < 26; i++) {
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
    salvarAlunoDiminuido(a);
}

    //TODO EDITAR ALUNO
    
void editarAluno() {
    char letra;
    printf("Digite a letra inicial do aluno: ");
    scanf(" %c", &letra);

    
    if (letra >= 'a' && letra <= 'z') {
        letra = letra - ('a' - 'A');
    }

    
    char nomeArquivo[10];
    nomeArquivo[0] = letra;
    nomeArquivo[1] = 'D';
    nomeArquivo[2] = '.';
    nomeArquivo[3] = 't';
    nomeArquivo[4] = 'x';
    nomeArquivo[5] = 't';
    nomeArquivo[6] = '\0';

    FILE *arquivoAluno = fopen(nomeArquivo, "r");
    if (arquivoAluno == NULL) {
        printf("Nenhum aluno encontrado com a letra %c.\n", letra);
        return;
    }

    printf("\n=== Lista de alunos com a letra %c ===\n", letra);
    char linha[200];
    while (fgets(linha, sizeof(linha), arquivoAluno)) {
        printf("%s", linha);
    }
    fclose(arquivoAluno);

    int idBuscado;
    printf("\nDigite o ID do aluno que deseja editar: ");
    scanf("%d", &idBuscado);

    char nomeArquivoCompleto[10];
    nomeArquivoCompleto[0] = letra;
    nomeArquivoCompleto[1] = '.';
    nomeArquivoCompleto[2] = 't';
    nomeArquivoCompleto[3] = 'x';
    nomeArquivoCompleto[4] = 't';
    nomeArquivoCompleto[5] = '\0';

    FILE *origem = fopen(nomeArquivoCompleto, "r");
    if (origem == NULL) {
        printf("Erro ao abrir o arquivo completo.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(origem);
        return;
    }

    int idAtual, achou = 0;
    int dentro = 0;
    struct aluno a;
    char buffer[200];

    while (fgets(buffer, sizeof(buffer), origem)) {
        if (sscanf(buffer, "ID: %d", &idAtual) == 1) {
            dentro = (idAtual == idBuscado);
            if (dentro) {
                achou = 1;
                a.ID = idBuscado;

                fgets(buffer, sizeof(buffer), origem);
                sscanf(buffer, "Nome: %[^\n]", a.nome);
                fgets(buffer, sizeof(buffer), origem);
                sscanf(buffer, "Data de nascimento: %d/%d/%d", &a.dia, &a.mes, &a.ano);
                fgets(buffer, sizeof(buffer), origem);
                sscanf(buffer, "Curso: %[^\n]", a.curso);
                fgets(buffer, sizeof(buffer), origem);
                sscanf(buffer, "Ano de ingresso: %d", &a.anoIngresso);
                fgets(buffer, sizeof(buffer), origem);
                sscanf(buffer, "Telefone: %[^\n]", a.telefone);
                fgets(buffer, sizeof(buffer), origem);
                sscanf(buffer, "Endereco: %[^\n]", a.endereco);

                int opcao;
                printf("\nO que deseja alterar?\n");
                printf("1) Data de nascimento\n");
                printf("2) Curso\n");
                printf("3) Ano de ingresso\n");
                printf("4) Telefone\n");
                printf("5) Endereco\n");
                printf("Opcao: ");
                scanf("%d", &opcao);

                switch (opcao) {
                    case 1:
                        printf("Nova data (dd mm aaaa): ");
                        scanf("%d %d %d", &a.dia, &a.mes, &a.ano);
                        break;
                    case 2:
                        printf("Novo curso: ");
                        scanf(" %[^\n]", a.curso);
                        break;
                    case 3:
                        printf("Novo ano de ingresso: ");
                        scanf("%d", &a.anoIngresso);
                        break;
                    case 4:
                        printf("Novo telefone: ");
                        scanf("%s", a.telefone);
                        break;
                    case 5:
                        printf("Novo endereco: ");
                        scanf(" %[^\n]", a.endereco);
                        break;
                    default:
                        printf("Opcao invalida.\n");
                        break;
                }

                fprintf(temp, "ID: %d\n", a.ID);
                fprintf(temp, "Nome: %s\n", a.nome);
                fprintf(temp, "Data de nascimento: %02d/%02d/%04d\n", a.dia, a.mes, a.ano);
                fprintf(temp, "Curso: %s\n", a.curso);
                fprintf(temp, "Ano de ingresso: %d\n", a.anoIngresso);
                fprintf(temp, "Telefone: %s\n", a.telefone);
                fprintf(temp, "Endereco: %s\n", a.endereco);
                fprintf(temp, "---\n");

                while (fgets(buffer, sizeof(buffer), origem)) {
                    if (buffer[0] == '-') break;
                }
                continue;
            }
        }
        fprintf(temp, "%s", buffer);
    }

    fclose(origem);
    fclose(temp);

    if (!achou) {
        printf("Aluno com ID %d não encontrado.\n", idBuscado);
        remove("temp.txt");
        return;
    }

    remove(nomeArquivoCompleto);
    rename("temp.txt", nomeArquivoCompleto);

    printf("\nAluno atualizado com sucesso!\n");
}

void selecionarAluno(){
    int idBuscado;
    printf("Digite o ID do aluno que deseja selecionar: ");
    scanf("%d", &idBuscado);

    char nomeArquivo[10];
    char linha [200];
    int i;
    int encontrado = 0;

    for (i = 0; i < 26; i++){
        char letra = 'A' + i;
        nomeArquivo[0] = letra;
        nomeArquivo[1] = '.';
        nomeArquivo[2] = 't';
        nomeArquivo[3] = 'x';
        nomeArquivo[4] = 't';
        nomeArquivo[5] = '\0';

        FILE *arquivoAluno = fopen(nomeArquivo, "r");
        if (arquivoAluno == NULL){
            continue;
        }

        while (fgets(linha, sizeof(linha), arquivoAluno)){
            int idLido;
            if (sscanf(linha, "ID: %d", &idLido) == 1){
                if (idLido == idBuscado){
                    encontrado = 1;
                    printf("Aluno encontrado:\n");
                    printf("%s", linha);
                    while (fgets(linha, sizeof(linha), arquivoAluno) && linha[0] != '-'){
                        printf("%s", linha);
                    }
                    break;
                }
            }
        }
        fclose(arquivoAluno);
        if (encontrado){
            break;
        }
        if (!encontrado){
            printf("Aluno com ID %d nao encontrado.\n", idBuscado);
        }
    }
}

int main(){
    gerenciarContador(0);
    cadastrarAlunos();
    gerenciarContador(1);
   consultarAlunos();
   editarAluno();
}    