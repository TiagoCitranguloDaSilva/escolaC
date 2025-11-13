#include <stdio.h>
#include <stdlib.h>

#define MAX_DISCIPLINAS 50
#define MAX_NOMES 50

struct aluno
{
    int ID;
    char nome[50];
    int dia, mes, ano;
    char curso[100];
    int anoIngresso;
    char telefone[11];
    char endereco[100];
};

struct Disciplina
{
    int id;
    char nome[50];
    char professor[50];
    char semestre[20];
    char curso[50];
};

struct Disciplina disciplinas[MAX_DISCIPLINAS];

struct Nota
{
    int idAluno;
    char nomeAluno[100];
    int idDisciplina;
    char nomeDisciplina[100];
    float media;
};
struct Nota n;

void menuInicial();
void menuAlunos();
void menuDisciplinas();
void menuNotas();

void gerenciarContador(int salvar);
void cadastrarAlunos();
void salvarAluno(struct aluno a);
void salvarAlunoDiminuido(struct aluno a);
void consultarAlunos();
void editarAluno();

void carregar();
void salvar();
void cadastrar();
void listar();
void editar();

char *BuscarNomeAluno(int id);
char *BuscarNomeDisciplina(int id);
void ImprimirListaAlunos();
void ImprimirListaDisciplinas();
void ConsultarNotas();
void CadastrarNotas();
int NotaJaCadastrada(int idAl, int idDisc);
void ExcluirNotas();

int contadorID = 0;

int contador = 0;

// Menu inicial
void menuInicial()
{
    int opcaoMenu;
    system("cls");

    printf("\n=============== MENU INICIAL ===============\n\n");
    printf("          [1] Gerenciar alunos                \n");
    printf("          [2] Gerenciar disciplinas           \n");
    printf("          [3] Gerenciar notas                 \n");
    printf("          [4] Autores                         \n");
    printf("          [5] Sair                            \n\n");
    printf("==============================================\n");
    printf("-Escolha uma opcao: ");
    scanf("%d", &opcaoMenu);

    switch (opcaoMenu)
    {

    case 1:
        system("cls");
        menuAlunos();
        break;

    case 2:
        system("cls");
        menuDisciplinas();
        break;

    case 3:
        system("cls");
        menuNotas();
        break;

    case 4:
        system("cls");
        printf("\n\n-------------- AUTORES --------------\n\n");
        printf("   Camilli dos Santos \n");
        printf("   Gustavo Ferreira dos Santos \n");
        printf("   Jeanderson Silva \n");
        printf("   Luana Gallinari Ranzulla da Silva \n");
        printf("   Matheus de Mello Carvalhaes \n");
        printf("   Otavio Siqueira Goncalves \n");
        printf("   Pedro Henrique Baraldi da Silva \n");
        printf("   Tiago Citrangulo da Silva \n");
        printf("   Victor Wesley Oliveira dos Santos \n\n");
        printf("------------------------------------------");

        printf("\n Pressione ENTER para voltar ao menu inicial ...\n");
        while (getchar() != '\n')
            ;
        getchar();
        menuInicial();
        break;

    case 5:
        exit(0);
        break;

    default:
        printf("\n Opcao invalida, escolha entre uma das opcoes dadas.\n");
        printf(" Pressione ENTER para continuar...\n");
        while (getchar() != '\n')
            ;
        getchar();
        menuInicial();
        break;
    }
}

// Gerenciar alunos
void menuAlunos()
{
    int opcaoA;
    system("cls");

    printf("\n============= GERENCIAR ALUNOS =============\n\n");
    printf("        [1] Consultar alunos                  \n");
    printf("        [2] Cadastrar aluno                   \n");
    printf("        [3] Editar aluno                      \n");
    printf("        [4] Voltar para o menu inicial        \n\n");
    printf("==============================================\n");
    printf("-Escolha uma opcao: ");
    scanf("%d", &opcaoA);

    switch (opcaoA)
    {

    case 1:
        system("cls");
        consultarAlunos();
        printf("Pressione ENTER para continuar...\n");
        while (getchar() != '\n')
            ;
        getchar();
        menuAlunos();
        break;

    case 2:
        system("cls");
        cadastrarAlunos();
        printf("Pressione ENTER para continuar...\n");
        while (getchar() != '\n')
            ;
        getchar();
        menuAlunos();
        break;

    case 3:
        system("cls");
        editarAluno();
        printf("Pressione ENTER para continuar...\n");
        while (getchar() != '\n')
            ;
        getchar();
        menuAlunos();
        break;

    case 4:
        system("cls");
        menuInicial();
        break;

    default:
        printf("\n Opcao invalida, escolha entre uma das opcoes dadas.\n");
        printf(" Pressione ENTER para continuar...\n");
        while (getchar() != '\n')
            ;
        getchar();
        menuAlunos();
        break;
    }
}

// Gerenciar disciplinas
void menuDisciplinas()
{
    int opcaoD;
    system("cls");

    printf("\n============== MENU DISCIPLINAS ============\n\n");
    printf("         [1] Consultar disciplinas            \n");
    printf("         [2] Cadastrar disciplina             \n");
    printf("         [3] Editar disciplina                \n");
    printf("         [4] Voltar para o menu inicial       \n\n");
    printf("==============================================\n");
    printf("-Escolha uma opcao: ");
    scanf("%d", &opcaoD);

    switch (opcaoD)
    {

    case 1:
        system("cls");
        listar();
        printf("Pressione ENTER para continuar...\n");
        while (getchar() != '\n')
            ;
        getchar();
        menuDisciplinas();
        break;

    case 2:
        system("cls");
        cadastrar();
        printf("Pressione ENTER para continuar...\n");
        while (getchar() != '\n')
            ;
        getchar();
        menuDisciplinas();
        break;

    case 3:
        system("cls");
        editar();
        printf("Pressione ENTER para continuar...\n");
        while (getchar() != '\n')
            ;
        getchar();
        menuDisciplinas();
        break;

    case 4:
        system("cls");
        menuInicial();
        menuDisciplinas();
        break;

    default:
        printf("\n Opcao invalida, escolha entre uma das opcoes dadas.\n");
        printf(" Pressione ENTER para continuar...\n");
        while (getchar() != '\n')
            ;
        getchar();
        menuDisciplinas();
        break;
    }
}

// Gerenciar notas
void menuNotas()
{
    int opcaoN;
    system("cls");

    printf("\n============== GERENCIAR NOTAS =============\n\n");
    printf("         [1] Consultar notas                  \n");
    printf("         [2] Cadastrar notas                  \n");
    printf("         [3] Excluir nota                     \n");
    printf("         [4] Voltar para o menu inicial       \n\n");
    printf("==============================================\n");
    printf("-Escolha uma opcao: ");
    scanf("%d", &opcaoN);

    switch (opcaoN)
    {

    case 1:
        system("cls");
        ConsultarNotas();
        printf("Pressione ENTER para continuar...\n");
        while (getchar() != '\n')
            ;
        getchar();
        menuNotas();
        break;

    case 2:
        system("cls");
        CadastrarNotas();
        printf("Pressione ENTER para continuar...\n");
        while (getchar() != '\n')
            ;
        getchar();
        menuNotas();
        break;

    case 3:
        system("cls");
        ExcluirNotas();
        printf("Pressione ENTER para continuar...\n");
        while (getchar() != '\n')
            ;
        getchar();
        menuNotas();
        break;

    case 4:
        system("cls");
        menuInicial();
        break;

    default:
        printf("\n Opcao invalida, escolha entre uma das opcoes dadas.\n");
        printf(" Pressione ENTER para continuar...\n");
        while (getchar() != '\n')
            ;
        getchar();
        menuNotas();
        break;
    }
}

void gerenciarContador(int salvar)
{
    if (salvar)
    {
        FILE *arquivo = fopen("ultimo_id.txt", "w");
        if (arquivo != NULL)
        {
            fprintf(arquivo, "%d", contadorID);
            fclose(arquivo);
        }
    }
    else
    {
        FILE *arquivo = fopen("ultimo_id.txt", "r");
        if (arquivo != NULL)
        {
            fscanf(arquivo, "%d", &contadorID);
            fclose(arquivo);
        }
        else
        {
            contadorID = 0;
        }
    }
}

void cadastrarAlunos()
{
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
    printf("%s recebeu o numero %d\n", a.nome, a.ID);
    salvarAluno(a);
    salvarAlunoDiminuido(a);
}

void salvarAluno(struct aluno a)
{
    char letra = a.nome[0];
    if (letra >= 'a' && letra <= 'z')
    {
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
    if (arquivoAluno == NULL)
    {
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

void salvarAlunoDiminuido(struct aluno a)
{
    char letra = a.nome[0];
    if (letra >= 'a' && letra <= 'z')
    {
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
    if (arquivoAluno == NULL)
    {
        printf("Aluno nao encontrado");
        return;
    }
    fprintf(arquivoAluno, "ID: %d\n", a.ID);
    fprintf(arquivoAluno, "Nome: %s\n", a.nome);
    fclose(arquivoAluno);
}

void consultarAlunos()
{
    char letra, nomeArquivo[10];
    int i;

    for (i = 0; i < 26; i++)
    {
        letra = 'A' + i;
        nomeArquivo[0] = letra;
        nomeArquivo[1] = '.';
        nomeArquivo[2] = 't';
        nomeArquivo[3] = 'x';
        nomeArquivo[4] = 't';
        nomeArquivo[5] = '\0';

        FILE *arquivo = fopen(nomeArquivo, "r");
        printf("\nLetra %c:\n", letra);

        if (arquivo == NULL)
        {
            printf("Nao tem nenhum aluno\n");
            continue;
        }

        char linha[200];
        int temAluno = 0;
        while (fgets(linha, sizeof(linha), arquivo))
        {
            printf("%s", linha);
            temAluno = 1;
        }

        if (!temAluno)
        {
            printf("Nao tem nenhum aluno\n");
        }

        fclose(arquivo);
    }
}

void editarAluno()
{
    char letra;
    printf("Digite a letra inicial do aluno: ");
    scanf(" %c", &letra);

    if (letra >= 'a' && letra <= 'z')
    {
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
    if (arquivoAluno == NULL)
    {
        printf("Nenhum aluno encontrado com a letra %c.\n", letra);
        return;
    }

    printf("\n=== Lista de alunos com a letra %c ===\n", letra);
    char linha[200];
    while (fgets(linha, sizeof(linha), arquivoAluno))
    {
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
    if (origem == NULL)
    {
        printf("Erro ao abrir o arquivo completo.\n");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL)
    {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(origem);
        return;
    }

    int idAtual, achou = 0;
    int dentro = 0;
    struct aluno a;
    char buffer[200];

    while (fgets(buffer, sizeof(buffer), origem))
    {
        if (sscanf(buffer, "ID: %d", &idAtual) == 1)
        {
            dentro = (idAtual == idBuscado);
            if (dentro)
            {
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

                switch (opcao)
                {
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

                while (fgets(buffer, sizeof(buffer), origem))
                {
                    if (buffer[0] == '-')
                        break;
                }
                continue;
            }
        }
        fprintf(temp, "%s", buffer);
    }

    fclose(origem);
    fclose(temp);

    if (!achou)
    {
        printf("Aluno com ID %d não encontrado.\n", idBuscado);
        remove("temp.txt");
        return;
    }

    remove(nomeArquivoCompleto);
    rename("temp.txt", nomeArquivoCompleto);

    printf("\nAluno atualizado com sucesso!\n");
}

void carregar()
{
    FILE *arquivo = fopen("disciplinas.txt", "r");
    if (arquivo == NULL)
    {
        return;
    }
    contador = 0;
    while (fscanf(arquivo, "ID: %d; NOME: %[^;]; PROFESSOR: %[^;]; SEMESTRE: %[^;]; CURSO: %[^\n]\n",
                  &disciplinas[contador].id,
                  disciplinas[contador].nome,
                  disciplinas[contador].professor,
                  disciplinas[contador].semestre,
                  disciplinas[contador].curso) == 5)
    {
        contador++;
    }
    fclose(arquivo);
}

void salvar()
{
    FILE *arquivo = fopen("disciplinas.txt", "w");
    if (arquivo == NULL)
    {
        printf("Erro ao salvar arquivo.\n");
        return;
    }
    for (int i = 0; i < contador; i++)
    {
        fprintf(arquivo, "ID: %d; NOME: %s; PROFESSOR: %s; SEMESTRE: %s; CURSO: %s\n",
                disciplinas[i].id,
                disciplinas[i].nome,
                disciplinas[i].professor,
                disciplinas[i].semestre,
                disciplinas[i].curso);
    }
    fclose(arquivo);
}

void cadastrar()
{
    if (contador >= MAX_DISCIPLINAS)
    {
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

void listar()
{
    carregar();
    if (contador == 0)
    {
        printf("Nenhuma disciplina cadastrada.\n");
        return;
    }
    printf("\n--- Disciplinas cadastradas ---\n");
    for (int i = 0; i < contador; i++)
    {
        printf("%d - %s | Prof: %s | %s | %s\n",
               disciplinas[i].id,
               disciplinas[i].nome,
               disciplinas[i].professor,
               disciplinas[i].semestre,
               disciplinas[i].curso);
    }
}

void editar()
{
    carregar();
    if (contador == 0)
    {
        printf("Nenhuma disciplina cadastrada\n");
        return;
    }
    printf("Disciplinas:\n");
    for (int i = 0; i < contador; i++)
    {
        printf("ID: %d,Nome: %s\n", disciplinas[i].id, disciplinas[i].nome);
    }
    int identificador;
    printf("\nDigite o ID da disciplina para editar:");
    scanf("%d", &identificador);

    int indice = -1;
    for (int i = 0; i < contador; i++)
    {
        if (disciplinas[i].id == identificador)
        {
            indice = i;
            break;
        }
    }
    if (indice == -1)
    {
        printf("Disciplina não encontrada\n");
        return;
    }
    printf("O que deseja alterar?\n");
    printf("1)professor:\n");
    printf("2)Semestre:\n");
    printf("3)Curso:\n");
    int opcao;
    scanf("%d", &opcao);
    getchar();
    if (opcao == 1)
    {
        printf("Novo professor:");
        scanf(" %99[^\n]", disciplinas[indice].professor);
    }
    else if (opcao == 2)
    {
        printf("Novo semestre:");
        scanf(" %49[^\n]", disciplinas[indice].semestre);
    }
    else if (opcao == 3)
    {
        printf("Novo Curso:");
        scanf(" %99[^\n]", disciplinas[indice].curso);
    }
    else
    {
        printf("Opcao invalida!\n");
        return;
    }
    printf("%s", disciplinas[indice].professor);
    salvar();
    printf("disciplina editada com sucesso. TMJ!\n");
}

char *BuscarNomeAluno(int id)
{
    if (id == 1)
        return "Ana Silva";
    if (id == 2)
        return "Bruno Costa";
    return "Nao Encontrado";
}

char *BuscarNomeDisciplina(int id)
{
    if (id == 101)
        return "Programacao C";
    if (id == 102)
        return "Matematica";
    return "Nao Encontrada";
}

void ImprimirListaDisciplinas()
{
    printf("\n--- Lista de Disciplinas ---\n");
    printf("ID: 101 - Programacao C\n");
    printf("ID: 102 - Matematica\n");
    printf("----------------------------\n");
}

void ImprimirListaAlunos()
{
    printf("\n--- Lista de Alunos ---\n");
    printf("ID: 1 - Ana Silva\n");
    printf("ID: 2 - Bruno Costa\n");
    printf("------------------------\n");
}

void ConsultarNotas()
{
    FILE *arquivoNotas = fopen("notas.txt", "r");
    if (arquivoNotas == NULL)
    {
        FILE *f = fopen("notas.txt", "w+");
        fclose(f);
        arquivoNotas = fopen("notas.txt", "r");
    }

    printf("\n--- LISTA DE NOTAS ---\n");

    while (fscanf(arquivoNotas,
                  "ID_ALUNO: %d; NOME_ALUNO: %[^;]; ID_DISCIPLINA: %d; NOME_DISCIPLINA: %[^;]; MEDIA: %f\n",
                  &n.idAluno,
                  n.nomeAluno,
                  &n.idDisciplina,
                  n.nomeDisciplina,
                  &n.media) == 5)
    {

        printf("Aluno: %s (ID %d) | Disciplina: %s (ID %d) |  Media: %.2f\n",
               n.nomeAluno, n.idAluno, n.nomeDisciplina, n.idDisciplina, n.media);
    }
    fclose(arquivoNotas);
    printf("\n--- Fim da lista ---\n");
}

void CadastrarNotas()
{
    printf("\n--- CADASTRO DE NOTAS ---\n");

    int idAlunoSelecionado = -1;
    int idDisciplinaSelecionada = -1;
    float nota1, nota2;

    // 1. Selecao do Aluno
    char letraInicial;
    printf("Digite a letra inicial do aluno desejado: ");
    while (getchar() != '\n')
        ;
    scanf("%c", &letraInicial);

    if (letraInicial >= 'a' && letraInicial <= 'z')
    {
        letraInicial = letraInicial - ('a' - 'A');
    }

    char nomeArquivo[10];
    nomeArquivo[0] = letraInicial;
    nomeArquivo[1] = 'D';
    nomeArquivo[2] = '.';
    nomeArquivo[3] = 't';
    nomeArquivo[4] = 'x';
    nomeArquivo[5] = 't';
    nomeArquivo[6] = '\0';

    FILE *arquivoAluno = fopen(nomeArquivo, "r");
    if (arquivoAluno == NULL)
    {
        printf("Nenhum aluno encontrado com a letra %c.\n", letraInicial);
        return;
    }

    printf("\n=== Lista de alunos com a letra %c ===\n", letraInicial);
    char linha[200];

    while (fgets(linha, sizeof(linha), arquivoAluno))
    {
        printf("%s", linha);
    }
    fclose(arquivoAluno);

    printf("Selecione o Aluno pelo numero de identificacao (ID): ");
    if (scanf("%d", &idAlunoSelecionado) != 1)
    {
        printf("Entrada invalida. Cancelando cadastro.\n");
        return;
    }
    n.idAluno = idAlunoSelecionado;

    char nomeArquivoCompleto[10];
    nomeArquivoCompleto[0] = letraInicial;
    nomeArquivoCompleto[1] = 'D';
    nomeArquivoCompleto[2] = '.';
    nomeArquivoCompleto[3] = 't';
    nomeArquivoCompleto[4] = 'x';
    nomeArquivoCompleto[5] = 't';
    nomeArquivoCompleto[6] = '\0';

    FILE *origem = fopen(nomeArquivoCompleto, "r");
    if (origem == NULL)
    {
        printf("Erro ao abrir o arquivo completo.\n");
        return;
    }

    int idAtual, achou = 0;
    int dentro = 0;
    char buffer[200];

    while (fgets(buffer, sizeof(buffer), origem))
    {
        if (sscanf(buffer, "ID: %d", &idAtual) == 1)
        {
            dentro = (idAtual == idAlunoSelecionado);
            if (dentro)
            {
                achou = 1;

                fgets(buffer, sizeof(buffer), origem);
                sscanf(buffer, "Nome: %[^\n]", n.nomeAluno);

                while (fgets(buffer, sizeof(buffer), origem))
                {
                    if (buffer[0] == '-')
                        break;
                }
                continue;
            }
        }
    }

    fclose(origem);

    if (!achou)
    {
        printf("Aluno com ID %d não encontrado.\n", idAlunoSelecionado);
        return;
    }

    // remove(nomeArquivoCompleto);

    // 2. Selecao da Disciplina
    listar();

    printf("Selecione a disciplina pelo numero de identificacao (ID): ");
    if (scanf("%d", &idDisciplinaSelecionada) != 1)
    {
        printf("Entrada invalida. Cancelando cadastro.\n");
        return;
    }
    n.idDisciplina = idDisciplinaSelecionada;

    FILE *origemDisc = fopen("disciplinas.txt", "r");
    if (origemDisc == NULL)
    {
        printf("Erro ao abrir o arquivo completo.\n");
        return;
    }

    achou = 0;
    dentro = 0;
    // struct aluno a;
    char bufferDisc[200];

    while (fgets(bufferDisc, sizeof(bufferDisc), origemDisc))
    {
        struct Disciplina disc;

        if (sscanf(bufferDisc,
                   "ID: %d; NOME: %[^;]; PROFESSOR: %[^;]; SEMESTRE: %[^;]; CURSO: %[^\n]",
                   &disc.id,
                   n.nomeDisciplina,
                   disc.professor,
                   disc.semestre,
                   disc.curso) == 5)
        {

            if (disc.id == idDisciplinaSelecionada)
            {
                achou = 1;
                printf("NOME DA DISC: %s\n", n.nomeDisciplina);
                break;
            }
        }
    }

    fclose(origemDisc);

    if (!achou)
    {
        printf("ID %d não encontrado.\n", idDisciplinaSelecionada);
        return;
    }

    // remove(nomeArquivoCompleto);

    // 3. Verifica se a nota j� existe

    if (NotaJaCadastrada(n.idAluno, n.idDisciplina))
    {
        printf("\nJa existe nota cadastrada para o aluno nesta disciplina.\n");
        printf("Nota cadastrada: N1=%.2f, N2=%.2f, Media=%.2f\n",
               nota1, nota2, n.media);
        return;
    }

    // 4. Solicita as informa��es
    printf("Digite a Nota do 1o bimestre (n1): ");
    scanf("%f", &nota1);
    printf("Digite a Nota do 2o bimestre (n2): ");
    scanf("%f", &nota2);

    n.media = (nota1 + nota2) / 2;
    FILE *arquivoNotas = fopen("notas.txt", "a");
    if (arquivoNotas == NULL)
    {
        printf("Erro ao abrir o arquivo para cadastro.\n");
        return;
    }

    fprintf(arquivoNotas, "ID_ALUNO: %d; NOME_ALUNO: %s; ID_DISCIPLINA: %d; NOME_DISCIPLINA: %s; MEDIA: %.2f\n",
            n.idAluno, n.nomeAluno, n.idDisciplina, n.nomeDisciplina, n.media);

    fclose(arquivoNotas);
    printf("\nNota cadastrada com sucesso. Media final: %.2f\n", n.media);
}

int NotaJaCadastrada(int idAl, int idDisc)
{
    FILE *arquivoNotas = fopen("notas.txt", "r");
    if (arquivoNotas == NULL)
    {
        return 0;
    }

    struct Nota tempNota;
    int existe = 0;

    // L� 5 valores por linha
    while (fscanf(arquivoNotas, "ID_ALUNO: %d; NOME_ALUNO: %[^;]; ID_DISCIPLINA: %d; NOME_DISCIPLINA: %[^;]; MEDIA: %f\n",
                  &tempNota.idAluno,
                  &tempNota.nomeAluno,
                  &tempNota.idDisciplina,
                  &tempNota.nomeDisciplina,
                  &tempNota.media) == 5)
    {

        if (tempNota.idAluno == idAl && tempNota.idDisciplina == idDisc)
        {
            // *n1 = tempNota.nota1;
            // *n2 = tempNota.nota2;
            // *media = tempNota.media;
            existe = 1;
            break;
        }
    }
    fclose(arquivoNotas);
    return existe;
}

void ExcluirNotas()
{
    printf("\n--- EXCLUSAO DE NOTAS ---\n");

    // 1. Selecao do Aluno
    int idAlunoSelecionado = -1;
    int idDisciplinaSelecionada = -1;
    float nota1, nota2;

    // 1. Selecao do Aluno
    char letraInicial;
    printf("Digite a letra inicial do aluno desejado: ");
    while (getchar() != '\n')
        ;
    scanf("%c", &letraInicial);

    if (letraInicial >= 'a' && letraInicial <= 'z')
    {
        letraInicial = letraInicial - ('a' - 'A');
    }

    char nomeArquivo[10];
    nomeArquivo[0] = letraInicial;
    nomeArquivo[1] = 'D';
    nomeArquivo[2] = '.';
    nomeArquivo[3] = 't';
    nomeArquivo[4] = 'x';
    nomeArquivo[5] = 't';
    nomeArquivo[6] = '\0';

    FILE *arquivoAluno = fopen(nomeArquivo, "r");
    if (arquivoAluno == NULL)
    {
        printf("Nenhum aluno encontrado com a letra %c.\n", letraInicial);
        return;
    }

    printf("\n=== Lista de alunos com a letra %c ===\n", letraInicial);
    char linha[200];

    while (fgets(linha, sizeof(linha), arquivoAluno))
    {
        printf("%s", linha);
    }
    fclose(arquivoAluno);

    printf("Selecione o Aluno pelo numero de identificacao (ID): ");
    if (scanf("%d", &idAlunoSelecionado) != 1)
    {
        printf("Entrada invalida. Cancelando cadastro.\n");
        return;
    }
    n.idAluno = idAlunoSelecionado;

    char nomeArquivoCompleto[10];
    nomeArquivoCompleto[0] = letraInicial;
    nomeArquivoCompleto[1] = 'D';
    nomeArquivoCompleto[2] = '.';
    nomeArquivoCompleto[3] = 't';
    nomeArquivoCompleto[4] = 'x';
    nomeArquivoCompleto[5] = 't';
    nomeArquivoCompleto[6] = '\0';

    FILE *origem = fopen(nomeArquivoCompleto, "r");
    if (origem == NULL)
    {
        printf("Erro ao abrir o arquivo completo.\n");
        return;
    }

    int idAtual, achou = 0;
    int dentro = 0;
    char buffer[200];

    while (fgets(buffer, sizeof(buffer), origem))
    {
        if (sscanf(buffer, "ID: %d", &idAtual) == 1)
        {
            dentro = (idAtual == idAlunoSelecionado);
            if (dentro)
            {
                achou = 1;

                fgets(buffer, sizeof(buffer), origem);
                sscanf(buffer, "Nome: %[^\n]", n.nomeAluno);

                while (fgets(buffer, sizeof(buffer), origem))
                {
                    if (buffer[0] == '-')
                        break;
                }
                continue;
            }
        }
    }

    fclose(origem);

    if (!achou)
    {
        printf("Aluno com ID %d não encontrado.\n", idAlunoSelecionado);
        return;
    }

    // 2. Selecao da Disciplina
    listar();

    printf("Selecione a disciplina pelo numero de identificacao (ID): ");
    if (scanf("%d", &idDisciplinaSelecionada) != 1)
    {
        printf("Entrada invalida. Cancelando cadastro.\n");
        return;
    }
    n.idDisciplina = idDisciplinaSelecionada;

    FILE *origemDisc = fopen("disciplinas.txt", "r");
    if (origemDisc == NULL)
    {
        printf("Erro ao abrir o arquivo completo.\n");
        return;
    }

    achou = 0;
    dentro = 0;
    // struct aluno a;
    char bufferDisc[200];

    while (fgets(bufferDisc, sizeof(bufferDisc), origemDisc))
    {
        struct Disciplina disc;

        if (sscanf(bufferDisc,
                   "ID: %d; NOME: %[^;]; PROFESSOR: %[^;]; SEMESTRE: %[^;]; CURSO: %[^\n]",
                   &disc.id,
                   n.nomeDisciplina,
                   disc.professor,
                   disc.semestre,
                   disc.curso) == 5)
        {

            if (disc.id == idDisciplinaSelecionada)
            {
                achou = 1;
                printf("NOME DA DISC: %s\n", n.nomeDisciplina);
                break;
            }
        }
    }

    fclose(origemDisc);

    if (!achou)
    {
        printf("ID %d não encontrado.\n", idDisciplinaSelecionada);
        return;
    }

    // 3. Verifica se a nota j� existe
    n.media = (nota1 + nota2) / 2;
    if (!NotaJaCadastrada(n.idAluno, n.idDisciplina))
    {
        printf("\nNao existia nota cadastrada para excluir para o Aluno ID %d na Disciplina ID %d.\n",
               idAlunoSelecionado, idDisciplinaSelecionada);
        return;
    }

    // 4. Se houver nota cadastrada: Remove do arquivo

    FILE *arquivoOriginal = fopen("notas.txt", "r");
    FILE *arquivoTemporario = fopen("temp_notas.txt", "w");

    if (arquivoOriginal == NULL || arquivoTemporario == NULL)
    {
        printf("Erro ao manipular o arquivo de notas. Exclusao falhou.\n");
        if (arquivoOriginal)
            fclose(arquivoOriginal);
        if (arquivoTemporario)
            fclose(arquivoTemporario);
        return;
    }

    struct Nota tempNota;
    int removido = 0;

    while (fscanf(arquivoOriginal, "ID_ALUNO: %d; NOME_ALUNO: %[^;]; ID_DISCIPLINA: %d; NOME_DISCIPLINA: %[^;]; MEDIA: %f\n",
                  &tempNota.idAluno,
                  tempNota.nomeAluno,
                  &tempNota.idDisciplina,
                  tempNota.nomeDisciplina,
                  &tempNota.media) == 5)
    {

        // Se o registro for DIFERENTE do que queremos excluir, ele � copiado para o arquivo tempor�rio
        if (!(tempNota.idAluno == idAlunoSelecionado && tempNota.idDisciplina == idDisciplinaSelecionada))
        {
            fprintf(arquivoTemporario, "ID_ALUNO: %d; NOME_ALUNO: %s; ID_DISCIPLINA: %d; NOME_DISCIPLINA: %s; MEDIA: %.2f\n",
                    tempNota.idAluno, tempNota.nomeAluno, tempNota.idDisciplina, tempNota.nomeDisciplina, tempNota.media);
        }
        else
        {
            // Este � o registro que est� sendo removido
            removido = 1;
        }
    }

    fclose(arquivoOriginal);
    fclose(arquivoTemporario);

    // Renomeia o arquivo tempor�rio para substituir o original
    if (removido)
    {
        remove("notas.txt");                   // Remove o arquivo original
        rename("temp_notas.txt", "notas.txt"); // Renomeia o tempor�rio

        printf("\n Nota do Aluno ID %d na Disciplina ID %d removida com sucesso.\n",
               idAlunoSelecionado, idDisciplinaSelecionada);
    }
    else
    {
        // Isso s� ocorreria se o arquivo fosse alterado entre as verifica��es,
        // mas � bom ter uma verifica��o final.
        remove("temp_notas.txt"); // Remove o tempor�rio
        printf("\nNao foi possivel remover a nota (erro de arquivo).\n");
    }
}

int main()
{
    gerenciarContador(0);
    carregar();
    menuInicial();
    return 0;
}
