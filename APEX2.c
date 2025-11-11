#include <stdio.h> 
#include <stdlib.h>

#define MAX_NOMES 50

//========================= Estrutura de Notas ==============================
typedef struct {
    int idAluno;
    char nomeAluno[MAX_NOMES];
    int idDisciplina;
    char nomeDisciplina[MAX_NOMES];
    float nota1;
}Nota;
Nota n;



//========================= Consultar Notas ==============================
void ConsultarNotas() {
    FILE *arquivoNotas = fopen("notas.txt", "r");
    if (arquivoNotas == NULL) {
        printf("Erro ao abrir o arquivo de notas.\n");
        return;
    }

    printf("\n--- LISTA DE NOTAS ---\n");

    while (fscanf(arquivoNotas, "%d\n", &n.idAluno) ==1)
        fgets(n.nomeAluno, MAX_NOMES, arquivoNotas);
        n.nomeAluno[strcspn(n.nomeAluno, "\n")] = 0; // Remover nova linha

        fscanf(arquivoNotas, "%d\n", &n.idDisciplina);

        fgets(n.nomeDisciplina, MAX_NOMES, arquivoNotas);
        n.nomeDisciplina[strcspn(n.nomeDisciplina, "\n")] = 0; // Remover nova linha
        
        fscanf(arquivoNotas, "%f\n", &n.nota1);

        printf("%s - %s - media= %f", n.nomeAluno, n.nomeDisciplina, n.nota1);
    {
        fclose(arquivoNotas);
    }
    
}




//========================= abrir arquivo pela letra ==============================
void abrirArquivosPorLetra() {
    char letra;
    char nomeArquivo[20];
    FILE *arquivos;
    char nome[100];
    int id;

    printf("Digite a letra inicial do nome do aluno: ");
    scanf(" %c", &letra);

    sprintf(nomeArquivo, "%c_notas.txt", letra);

    arquivos = fopen(nomeArquivo, "r");
    if (arquivos == NULL) {
        printf("Arquivo nao encontrado para a letra %c.\n", letra);
        return;
    }
    printf("\n--- lista de alunos com letra %c ---\n", letra);

    while (fscanf(arquivo, "%d", &id) == 1) {
        if (fgets(nome, sizeof(nome), arquivo) != NULL) {
            nome[strcspn(nome, "\n")] = 0; // Remover nova linha
            printf("ID: %d, Nome: %s\n", id, nome);
        }
    }
    fclose(arquivos);
    printf("\n--- Fim da lista ---\n");
}    





//========================= Menu de Notas ==============================
int OpcaoMenuNota;
int main() {
    while(OpcaoMenuNota !=4){
        printf("Menu de Notas:\n");
        printf("1 - Inserir Nota\n");
        printf("2 - Calcular Media\n");
        printf("3 - Exibir Notas\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &OpcaoMenuNota);
        
        switch(OpcaoMenuNota){
            case 1:
                // Codigo para inserir nota
                break;
            case 2:
                // Codigo para calcular media
                break;
            case 3:
                void ConsultarNotas();
                break;
            case 4:
                printf("Saindo do menu de notas.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}