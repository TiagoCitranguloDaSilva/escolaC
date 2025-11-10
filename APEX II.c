#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definições de tamanho
#define MAX_NOMES 50
#define MAX_DISCIPLINAS 50

// Estrutura para a nota
struct Nota {
    int idAluno;
    int idDisciplina;
    float nota1;
    float nota2;
    float media;
};
struct Nota n;

// --- MOCKUP DE FUNÇÕES AUSENTES ---
// Essas funções simulam a busca e impressão de dados de Alunos/Disciplinas
char* BuscarNomeAluno(int id) {
    if (id == 1) return "Ana Silva";
    if (id == 2) return "Bruno Costa";
    return "Nao Encontrado";
}

char* BuscarNomeDisciplina(int id) {
    if (id == 101) return "Programacao C";
    if (id == 102) return "Matematica";
    return "Nao Encontrada";
}

void ImprimirListaAlunos() {
    printf("\n--- Lista de Alunos ---\n");
    printf("ID: 1 - Ana Silva\n");
    printf("ID: 2 - Bruno Costa\n");
    printf("------------------------\n");
}

void ImprimirListaDisciplinas() {
    printf("\n--- Lista de Disciplinas ---\n");
    printf("ID: 101 - Programacao C\n");
    printf("ID: 102 - Matematica\n");
    printf("----------------------------\n");
}
// -----------------------------------

// Função para verificar se a nota já existe (útil para Cadastro e Exclusão)
int NotaJaCadastrada(int idAl, int idDisc, float *n1, float *n2, float *media) {
    FILE *arquivoNotas = fopen("notas.txt", "r");
    if (arquivoNotas == NULL) {
        return 0;
    }

    struct Nota tempNota;
    int existe = 0;

    // Lê 5 valores por linha
    while (fscanf(arquivoNotas, "%d %d %f %f %f", 
                  &tempNota.idAluno, 
                  &tempNota.idDisciplina, 
                  &tempNota.nota1, 
                  &tempNota.nota2, 
                  &tempNota.media) == 5) {

        if (tempNota.idAluno == idAl && tempNota.idDisciplina == idDisc) {
            *n1 = tempNota.nota1;
            *n2 = tempNota.nota2;
            *media = tempNota.media;
            existe = 1;
            break; 
        }
    }
    fclose(arquivoNotas);
    return existe;
}

//========================= 1) Consultar Notas ==============================
void ConsultarNotas() {
    FILE *arquivoNotas = fopen("notas.txt", "r");
    if (arquivoNotas == NULL) {
        printf("Arquivo de notas nao encontrado.\n");
        return;
    }

    printf("\n--- LISTA DE NOTAS ---\n");
    
    while (fscanf(arquivoNotas, "%d %d %f %f %f", 
                  &n.idAluno, 
                  &n.idDisciplina, 
                  &n.nota1, 
                  &n.nota2, 
                  &n.media) == 5) {
        
        char* nomeAluno = BuscarNomeAluno(n.idAluno);
        char* nomeDisciplina = BuscarNomeDisciplina(n.idDisciplina);

        printf("Aluno: %s (ID %d) | Disciplina: %s (ID %d) | N1: %.2f | N2: %.2f | Media: %.2f\n", 
               nomeAluno, n.idAluno, nomeDisciplina, n.idDisciplina, n.nota1, n.nota2, n.media);
    }
    fclose(arquivoNotas);
    printf("\n--- Fim da lista ---\n");
}

//========================= 2) Cadastrar Notas ==============================
void CadastrarNotas() {
    printf("\n--- CADASTRO DE NOTAS ---\n");
    
    int idAlunoSelecionado = -1;
    int idDisciplinaSelecionada = -1;
    float nota1, nota2;

    // 1. Selecao do Aluno
    char letraInicial;
    printf("Digite a letra inicial do aluno desejado: ");
    while (getchar() != '\n'); 
    scanf("%c", &letraInicial);

    ImprimirListaAlunos();

    printf("Selecione o Aluno pelo numero de identificacao (ID): ");
    if (scanf("%d", &idAlunoSelecionado) != 1) {
        printf("Entrada invalida. Cancelando cadastro.\n");
        return;
    }
    n.idAluno = idAlunoSelecionado;
    
    // 2. Selecao da Disciplina
    ImprimirListaDisciplinas();

    printf("Selecione a disciplina pelo numero de identificacao (ID): ");
    if (scanf("%d", &idDisciplinaSelecionada) != 1) {
        printf("Entrada invalida. Cancelando cadastro.\n");
        return;
    }
    n.idDisciplina = idDisciplinaSelecionada;
    
    // 3. Verifica se a nota já existe
    float n1_existente, n2_existente, media_existente;
    if (NotaJaCadastrada(n.idAluno, n.idDisciplina, &n1_existente, &n2_existente, &media_existente)) {
        printf("\nJa existe nota cadastrada para o aluno nesta disciplina.\n");
        printf("Nota cadastrada: N1=%.2f, N2=%.2f, Media=%.2f\n", 
               n1_existente, n2_existente, media_existente);
        return; 
    } 
    
    // 4. Solicita as informações
    printf("Digite a Nota do 1o bimestre (n1): ");
    scanf("%f", &nota1);
    printf("Digite a Nota do 2o bimestre (n2): ");
    scanf("%f", &nota2);
    
    // 5. Armazena no arquivo
    n.nota1 = nota1;
    n.nota2 = nota2;
    n.media = (nota1 + nota2) / 2;

    FILE *arquivoNotas = fopen("notas.txt", "a");
    if (arquivoNotas == NULL) {
        printf("Erro ao abrir o arquivo para cadastro.\n");
        return;
    }
    
    fprintf(arquivoNotas, "%d %d %.2f %.2f %.2f\n", 
            n.idAluno, n.idDisciplina, n.nota1, n.nota2, n.media);

    fclose(arquivoNotas);
    printf("\nNota cadastrada com sucesso. Media final: %.2f\n", n.media);
}

//========================= 3) Excluir Notas - Implementacao conforme imagem ==============================
void ExcluirNotas() {
    printf("\n--- EXCLUSAO DE NOTAS ---\n");
    
    int idAlunoSelecionado = -1;
    int idDisciplinaSelecionada = -1;
    
    // 1. Selecao do Aluno
    char letraInicial;
    printf("Digite a letra inicial do aluno desejado: ");
    while (getchar() != '\n'); 
    scanf("%c", &letraInicial);

    ImprimirListaAlunos();

    printf("Selecione o Aluno pelo numero de identificacao (ID): ");
    if (scanf("%d", &idAlunoSelecionado) != 1) {
        printf("Entrada invalida. Cancelando exclusao.\n");
        return;
    }
    
    // 2. Selecao da Disciplina
    ImprimirListaDisciplinas();

    printf("Selecione a disciplina pelo numero de identificacao (ID): ");
    if (scanf("%d", &idDisciplinaSelecionada) != 1) {
        printf("Entrada invalida. Cancelando exclusao.\n");
        return;
    }

    // 3. Verifica se a nota existe
    float n1_existente, n2_existente, media_existente;
    if (!NotaJaCadastrada(idAlunoSelecionado, idDisciplinaSelecionada, &n1_existente, &n2_existente, &media_existente)) {
        // Se não houver nota cadastrada: informa
        printf("\nNao existia nota cadastrada para excluir para o Aluno ID %d na Disciplina ID %d.\n", 
               idAlunoSelecionado, idDisciplinaSelecionada);
        return; 
    }
    
    // 4. Se houver nota cadastrada: Remove do arquivo
    
    FILE *arquivoOriginal = fopen("notas.txt", "r");
    FILE *arquivoTemporario = fopen("temp_notas.txt", "w");
    
    if (arquivoOriginal == NULL || arquivoTemporario == NULL) {
        printf("Erro ao manipular o arquivo de notas. Exclusao falhou.\n");
        if (arquivoOriginal) fclose(arquivoOriginal);
        if (arquivoTemporario) fclose(arquivoTemporario);
        return;
    }

    struct Nota tempNota;
    int removido = 0;
    
    while (fscanf(arquivoOriginal, "%d %d %f %f %f", 
                  &tempNota.idAluno, 
                  &tempNota.idDisciplina, 
                  &tempNota.nota1, 
                  &tempNota.nota2, 
                  &tempNota.media) == 5) {

        // Se o registro for DIFERENTE do que queremos excluir, ele é copiado para o arquivo temporário
        if (!(tempNota.idAluno == idAlunoSelecionado && tempNota.idDisciplina == idDisciplinaSelecionada)) {
            fprintf(arquivoTemporario, "%d %d %.2f %.2f %.2f\n", 
                    tempNota.idAluno, tempNota.idDisciplina, tempNota.nota1, tempNota.nota2, tempNota.media);
        } else {
            // Este é o registro que está sendo removido
            removido = 1;
        }
    }
    
    fclose(arquivoOriginal);
    fclose(arquivoTemporario);

    // Renomeia o arquivo temporário para substituir o original
    if (removido) {
        remove("notas.txt"); // Remove o arquivo original
        rename("temp_notas.txt", "notas.txt"); // Renomeia o temporário
        
        printf("\n Nota do Aluno ID %d na Disciplina ID %d removida com sucesso.\n", 
               idAlunoSelecionado, idDisciplinaSelecionada);
    } else {
        // Isso só ocorreria se o arquivo fosse alterado entre as verificações,
        // mas é bom ter uma verificação final.
        remove("temp_notas.txt"); // Remove o temporário
        printf("\nNao foi possivel remover a nota (erro de arquivo).\n");
    }
}

//========================= Menu de Notas ==============================
int OpcaoMenuNota = 0;
int main() {
    while(OpcaoMenuNota != 4){
        printf("\n==================================\n");
        printf("--- Menu Gerenciar Notas ---\n");
        printf("1 - Consultar notas\n");
        printf("2 - Cadastrar notas\n");
        printf("3 - Excluir nota\n");
        printf("4 - Voltar para o menu inicial (Sair)\n");
        printf("==================================\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &OpcaoMenuNota) != 1) {
            printf("Entrada invalida. Saindo do programa.\n");
            while (getchar() != '\n'); 
            OpcaoMenuNota = 4;
            continue;
        }

        switch(OpcaoMenuNota){
            case 1:
                ConsultarNotas();
                break;
            case 2:
                CadastrarNotas();
                break;
            case 3:
                ExcluirNotas();
                break;
            case 4:
                printf("Voltando para o menu inicial. Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    }

    return 0;
}
