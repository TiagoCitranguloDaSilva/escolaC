#include <stdio.h> 

#define MAX_NOMES 50
typedef struct {
    int iaAluno;
    char nomeAluno[MAX_NOMES];
    int idDisciplina;
    char nomeDisciplina[MAX_NOMES];
    float nota1;
}Nota;
Nota n;

void ConsultarNotas() {// Implementacao da funcao ConsultarNotas
    FILE *arquivo = fopen("notas.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de notas.\n");
        return;
    }

    printf("\n--- LISTA DE NOTAS ---\n");

    while (fscanf(arquivo, "%d\n", &n.idAluno) ==1)
        fgets(n.nomeAluno, MAX_NOMES, arquivo);
        n.nomeAluno[strcspn(n.nomeAluno, "\n")] = 0; // Remover nova linha

        fscanf(arquivo, "%d\n", &n.idDisciplina);

        fgets(n.nomeDisciplina, MAX_NOMES, arquivo);
        n.nomeDisciplina[strcspn(n.nomeDisciplina, "\n")] = 0; // Remover nova linha
        
        fscanf(arquivo, "%f\n", &n.nota1);

        printf("%s - %s - media= %f", n.nomeAluno, n.nomeDisciplina, n.nota1);
    {
        fclose(arquivo);
    }
    
}

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