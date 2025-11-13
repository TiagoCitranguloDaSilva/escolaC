#include <stdio.h>
#include <stdlib.h>

#define MAX_DISCIPLINAS 50
#define MAX_NOMES 50

// Criação/Iniciação dos structs e variáveis necessárias

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

void gerenciarContador();
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

void ConsultarNotas();
void CadastrarNotas();
int NotaJaCadastrada(int idAl, int idDisc);
void ExcluirNotas();

int contadorID = 0;

int contador = 0;

// Função que irá mostrar o menu inicial
void menuInicial()
{
    int opcaoMenu;
    system("cls");

    // Mostra o menu
    printf("\n=============== MENU INICIAL ===============\n\n");
    printf("          [1] Gerenciar alunos                \n");
    printf("          [2] Gerenciar disciplinas           \n");
    printf("          [3] Gerenciar notas                 \n");
    printf("          [4] Autores                         \n");
    printf("          [5] Sair                            \n\n");
    printf("==============================================\n");
    printf("-Escolha uma opcao: ");
    scanf("%d", &opcaoMenu);

    // Conforme a opção escolhida, faz uma ação
    switch (opcaoMenu)
    {

    // Mostra o menu de aluno
    case 1:
        system("cls");
        menuAlunos();
        break;

    // Mostra o menu de disciplinas
    case 2:
        system("cls");
        menuDisciplinas();
        break;

    // Mostra o menu de notas
    case 3:
        system("cls");
        menuNotas();
        break;

    // Mostra os autores
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

    // Encerra o programa
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

// Função que irá mostrar o menu de alunos
void menuAlunos()
{
    int opcaoA;
    system("cls");

    // Mostra o menu de alunos
    printf("\n============= GERENCIAR ALUNOS =============\n\n");
    printf("        [1] Consultar alunos                  \n");
    printf("        [2] Cadastrar aluno                   \n");
    printf("        [3] Editar aluno                      \n");
    printf("        [4] Voltar para o menu inicial        \n\n");
    printf("==============================================\n");
    printf("-Escolha uma opcao: ");
    scanf("%d", &opcaoA);

    // Conforme a opção escolhida, faz uma ação
    switch (opcaoA)
    {

    // Consulta os alunos cadastrados
    case 1:
        system("cls");
        consultarAlunos();
        printf("Pressione ENTER para continuar...\n");
        while (getchar() != '\n')
            ;
        getchar();
        menuAlunos();
        break;

    // Cadastra novos alunos
    case 2:
        system("cls");
        cadastrarAlunos();
        printf("Pressione ENTER para continuar...\n");
        while (getchar() != '\n')
            ;
        getchar();
        menuAlunos();
        break;

    // Edita um aluno já existente
    case 3:
        system("cls");
        editarAluno();
        printf("Pressione ENTER para continuar...\n");
        while (getchar() != '\n')
            ;
        getchar();
        menuAlunos();
        break;

    // Volta ao menu inicial
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

// Função que irá mostrar o menu de disciplinas
void menuDisciplinas()
{
    int opcaoD;
    system("cls");

    // Mostra o menu de disciplinas
    printf("\n============== MENU DISCIPLINAS ============\n\n");
    printf("         [1] Consultar disciplinas            \n");
    printf("         [2] Cadastrar disciplina             \n");
    printf("         [3] Editar disciplina                \n");
    printf("         [4] Voltar para o menu inicial       \n\n");
    printf("==============================================\n");
    printf("-Escolha uma opcao: ");
    scanf("%d", &opcaoD);

    // Conforme a opção escolhida, faz uma ação
    switch (opcaoD)
    {

    // Lista as disciplinas existentes
    case 1:
        system("cls");
        listar();
        printf("Pressione ENTER para continuar...\n");
        while (getchar() != '\n')
            ;
        getchar();
        menuDisciplinas();
        break;

    // Cadastra novas disciplinas
    case 2:
        system("cls");
        cadastrar();
        printf("Pressione ENTER para continuar...\n");
        while (getchar() != '\n')
            ;
        getchar();
        menuDisciplinas();
        break;

    // Edita uma disciplinas já existente
    case 3:
        system("cls");
        editar();
        printf("Pressione ENTER para continuar...\n");
        while (getchar() != '\n')
            ;
        getchar();
        menuDisciplinas();
        break;

    // Retorna ao menu inicial
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
        menuDisciplinas();
        break;
    }
}

// Função que irá mostrar o menu de notas
void menuNotas()
{
    int opcaoN;
    system("cls");

    // Mostra o menu de notas
    printf("\n============== GERENCIAR NOTAS =============\n\n");
    printf("         [1] Consultar notas                  \n");
    printf("         [2] Cadastrar notas                  \n");
    printf("         [3] Excluir nota                     \n");
    printf("         [4] Voltar para o menu inicial       \n\n");
    printf("==============================================\n");
    printf("-Escolha uma opcao: ");
    scanf("%d", &opcaoN);

    // Conforme a opção escolhida, faz uma ação
    switch (opcaoN)
    {

    // Mostra as notas existentes
    case 1:
        system("cls");
        ConsultarNotas();
        printf("Pressione ENTER para continuar...\n");
        while (getchar() != '\n')
            ;
        getchar();
        menuNotas();
        break;

    // Cadastra uma nova nota
    case 2:
        system("cls");
        CadastrarNotas();
        printf("Pressione ENTER para continuar...\n");
        while (getchar() != '\n')
            ;
        getchar();
        menuNotas();
        break;

    // Exclui uma nota existente
    case 3:
        system("cls");
        ExcluirNotas();
        printf("Pressione ENTER para continuar...\n");
        while (getchar() != '\n')
            ;
        getchar();
        menuNotas();
        break;

    // Volta ao menu inicial
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

// Ao rodar o projeto, essa função verá qual é o maior id de aluno já existente
void gerenciarContador()
{

    // Se existir um arquivo chamado "ultimo_id.txt", irá pegar o valor dentro dele e dirá que esse [e o último id já utilizado
    FILE *arquivo = fopen("ultimo_id.txt", "r");
    if (arquivo != NULL)
    {
        // Guarda o último id já utilizado no contadorID
        fscanf(arquivo, "%d", &contadorID);
        fclose(arquivo);
    }
    // Se o arquivo não existir, cria ele e começa o contador de id do 0
    else
    {
        arquivo = fopen("ultimo_id.txt", "w");
        fprintf(arquivo, "0");
        fclose(arquivo);
        contadorID = 0;
    }
}

// Função para cadastrar um novo aluno
void cadastrarAlunos()
{
    // Cria um aluno com base no struct
    struct aluno a;

    // Adiciona +1 ao contador de id
    contadorID++;

    // Atribui o id ao aluno
    a.ID = contadorID;

    // Pede as informações pro cadastro e as salva no aluno
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

    // Manda salvar o aluno
    salvarAluno(a);

    // Manda salvar uma versão "diminuida" do aluno que será útil para o cadastro de notas ou editar alunos
    salvarAlunoDiminuido(a);
}

// Função que salva um aluno com base nos valores recebidos como parâmetro
void salvarAluno(struct aluno a)
{

    // Pega a primeira letro do nome do aluno
    char letra = a.nome[0];

    // Garante sempre que a letra seja maiuscula
    if (letra >= 'a' && letra <= 'z')
    {
        // Faz uma subtração com base nos valores ASCII para pegar a versão maiúscula de uma letra minúscula
        letra = letra - ('a' - 'A');
    }

    // Cria o nome do arquivo com base na primeira letra do nome do aluno
    char nomeArquivo[6];
    nomeArquivo[0] = letra;
    nomeArquivo[1] = '.';
    nomeArquivo[2] = 't';
    nomeArquivo[3] = 'x';
    nomeArquivo[4] = 't';
    nomeArquivo[5] = '\0';

    // Abre o arquivo com a primeira letra do nome do aluno (Ele cria um novo arquivo caso não exista)
    FILE *arquivoAluno = fopen(nomeArquivo, "a");
    if (arquivoAluno == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Guarda as informações no arquivo
    fprintf(arquivoAluno, "ID: %d\n", a.ID);
    fprintf(arquivoAluno, "Nome: %s\n", a.nome);
    fprintf(arquivoAluno, "Data de nascimento: %02d/%02d/%04d\n", a.dia, a.mes, a.ano);
    fprintf(arquivoAluno, "Curso: %s\n", a.curso);
    fprintf(arquivoAluno, "Ano de ingresso: %d\n", a.anoIngresso);
    fprintf(arquivoAluno, "Telefone: %s\n", a.telefone);
    fprintf(arquivoAluno, "Endereco: %s\n", a.endereco);
    fprintf(arquivoAluno, "---\n");

    // Fecha o arquivo
    fclose(arquivoAluno);
}

// Salva uma versão menor do aluno com base no aluno passado por parâmetro para ser utilizado ao cadastrar notas ou editar alunos
void salvarAlunoDiminuido(struct aluno a)
{
    // Pega a primeira letro do nome do aluno
    char letra = a.nome[0];

    // Garante sempre que a letra seja maiuscula
    if (letra >= 'a' && letra <= 'z')
    {
        // Faz uma subtração com base nos valores ASCII para pegar a versão maiúscula de uma letra minúscula
        letra = letra - ('a' - 'A');
    }

    // Cria o nome do arquivo com base na primeira letra do nome do aluno
    char nomeArquivo[7];
    nomeArquivo[0] = letra;
    nomeArquivo[1] = 'D'; // D -> diminuido
    nomeArquivo[2] = '.';
    nomeArquivo[3] = 't';
    nomeArquivo[4] = 'x';
    nomeArquivo[5] = 't';
    nomeArquivo[6] = '\0';

    // Abre o arquivo com a primeira letra do nome do aluno (Ele cria um novo arquivo caso não exista)
    FILE *arquivoAluno = fopen(nomeArquivo, "a");
    if (arquivoAluno == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Salva o nome e o id do aluno no arquivo
    fprintf(arquivoAluno, "ID: %d\n", a.ID);
    fprintf(arquivoAluno, "Nome: %s\n", a.nome);

    // Fecha o arquivo
    fclose(arquivoAluno);
}

// Mostra os alunos existentes
void consultarAlunos()
{
    char letra, nomeArquivo[6];
    int i;

    // Um for que roda por todas as letras do alfabeto
    for (i = 0; i < 26; i++)
    {
        // Pegando a proxima letra usando os valores da tabela ASCII
        letra = 'A' + i;

        // Cria o nome do arquivo
        nomeArquivo[0] = letra;
        nomeArquivo[1] = '.';
        nomeArquivo[2] = 't';
        nomeArquivo[3] = 'x';
        nomeArquivo[4] = 't';
        nomeArquivo[5] = '\0';

        // Abre o arquivo da letra atual
        FILE *arquivo = fopen(nomeArquivo, "r");

        printf("\nLetra %c:\n", letra);

        // Caso o arquivo não exista
        if (arquivo == NULL)
        {
            // Mostra uma mensagem dizendo que está vazio
            printf("Nao tem nenhum aluno\n");

            // Ignora o resto do código e vai pra próxima volta do for
            continue;
        }

        char linha[200];
        int temAluno = 0;

        // Roda por cada linha do arquivo
        while (fgets(linha, sizeof(linha), arquivo))
        {

            // Mostra a linha
            printf("%s", linha);

            // Fala que existe alunos com essa letra
            temAluno = 1;
        }

        // Caso não exista alunos com essa letra
        if (!temAluno)
        {
            // Fala que não tem nenhum aluno
            printf("Nao tem nenhum aluno\n");
        }

        // Fecha o arquivo
        fclose(arquivo);
    }
}

// Edita o aluno
void editarAluno()
{
    char letra;

    // Pede a primeira letra do aluno que será editado
    printf("Digite a letra inicial do aluno: ");
    scanf(" %c", &letra);

    // Garante sempre que a letra seja maiuscula
    if (letra >= 'a' && letra <= 'z')
    {
        // Faz uma subtração com base nos valores ASCII para pegar a versão maiúscula de uma letra minúscula
        letra = letra - ('a' - 'A');
    }

    // Cria o nome do arquivo diminuido
    char nomeArquivo[7];
    nomeArquivo[0] = letra;
    nomeArquivo[1] = 'D';
    nomeArquivo[2] = '.';
    nomeArquivo[3] = 't';
    nomeArquivo[4] = 'x';
    nomeArquivo[5] = 't';
    nomeArquivo[6] = '\0';

    // Abre o arquivo daquela letra
    FILE *arquivoAluno = fopen(nomeArquivo, "r");

    // Verifica se o arquivo existe
    if (arquivoAluno == NULL)
    {
        // Fala que não há alunos com essa letra
        printf("Nenhum aluno encontrado com a letra %c.\n", letra);
        return;
    }

    // Mostra a lista de alunos
    printf("\n=== Lista de alunos com a letra %c ===\n", letra);
    char linha[200];

    // Roda por cada linha do arquivo da letra do aluno
    while (fgets(linha, sizeof(linha), arquivoAluno))
    {
        // Mostra a linha
        printf("%s", linha);
    }

    // Fecha o arquivo
    fclose(arquivoAluno);

    // Pede o id do aluno a ser editado
    int idBuscado;
    printf("\nDigite o ID do aluno que deseja editar: ");
    scanf("%d", &idBuscado);

    // Cria o nome do arquivo
    char nomeArquivoCompleto[6];
    nomeArquivoCompleto[0] = letra;
    nomeArquivoCompleto[1] = '.';
    nomeArquivoCompleto[2] = 't';
    nomeArquivoCompleto[3] = 'x';
    nomeArquivoCompleto[4] = 't';
    nomeArquivoCompleto[5] = '\0';

    // Abre o arquivo
    FILE *origem = fopen(nomeArquivoCompleto, "r");

    // Se o arquivo não existir
    if (origem == NULL)
    {
        // Mostra uma mensagem de erro
        printf("Erro ao abrir o arquivo completo.\n");
        return;
    }

    // Cria um arquivo temporario
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

    // Roda por cada linha do arquivo da letra do aluno
    while (fgets(buffer, sizeof(buffer), origem))
    {

        // Se a linha contém um id (Ou seja, é um aluno)
        if (sscanf(buffer, "ID: %d", &idAtual) == 1)
        {

            // Se o id do aluno atual for igual ao id do aluno a ser editado
            dentro = (idAtual == idBuscado);
            if (dentro)
            {

                // Diz que achou o aluno
                achou = 1;

                // Guarda o id no struct aluno
                a.ID = idBuscado;

                // Mostra as informações desse aluno
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
                // Pergunta qual dado do aluno será editado
                printf("\nO que deseja alterar?\n");
                printf("1) Data de nascimento\n");
                printf("2) Curso\n");
                printf("3) Ano de ingresso\n");
                printf("4) Telefone\n");
                printf("5) Endereco\n");
                printf("Opcao: ");
                scanf("%d", &opcao);

                // Com base na escolha, irá editar uma parte diferente do aluno
                switch (opcao)
                {
                // Data de nascimento
                case 1:
                    printf("Nova data (dd mm aaaa): ");
                    scanf("%d %d %d", &a.dia, &a.mes, &a.ano);
                    break;
                // Curso
                case 2:
                    printf("Novo curso: ");
                    scanf(" %[^\n]", a.curso);
                    break;
                // Ano de ingresso
                case 3:
                    printf("Novo ano de ingresso: ");
                    scanf("%d", &a.anoIngresso);
                    break;
                // Telefone
                case 4:
                    printf("Novo telefone: ");
                    scanf("%s", a.telefone);
                    break;
                // Endereço
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

                // Roda até achar a linha divisória de alunos: '-'
                while (fgets(buffer, sizeof(buffer), origem))
                {
                    if (buffer[0] == '-')
                        break;
                }

                // Manda o while ignorar o resto do código e já ir verificar o próximo aluno
                continue;
            }
        }

        // Caso não seja o id buscado, salva o aluno sendo verificado no arquivo temporário
        fprintf(temp, "%s", buffer);
    }

    // Fecha os arquivos da letra do aluno e o arquivo temporário
    fclose(origem);
    fclose(temp);

    // Caso não tenha encontrado o aluno, mostra uma mensagem de erro
    if (!achou)
    {
        printf("Aluno com ID %d não encontrado.\n", idBuscado);
        remove("temp.txt");
        return;
    }

    // Apaga o arquivo da letra do aluno
    remove(nomeArquivoCompleto);

    // Renomeia o arquivo temporario pra ter o nome do arquivo da letra do aluno
    rename("temp.txt", nomeArquivoCompleto);

    printf("\nAluno atualizado com sucesso!\n");
}

// Importa as informações que estão no disciplinas.txt
void carregar()
{

    // Abre o "disciplinas.txt"
    FILE *arquivo = fopen("disciplinas.txt", "r");

    // Se o arquivo não existir
    if (arquivo == NULL)
    {
        return;
    }

    // Contador de quantas disciplinas existem
    contador = 0;

    // Pega as disciplinas que estão no arquivo e as salva na array disciplinas e ve se todas as informações das disciplinas estão no txt
    while (fscanf(arquivo, "ID: %d; NOME: %[^;]; PROFESSOR: %[^;]; SEMESTRE: %[^;]; CURSO: %[^\n]\n",
                  &disciplinas[contador].id,
                  disciplinas[contador].nome,
                  disciplinas[contador].professor,
                  disciplinas[contador].semestre,
                  disciplinas[contador].curso) == 5)
    {
        // Adiciona mais um ao contador
        contador++;
    }

    // Fecha o arquivo
    fclose(arquivo);
}

// Cadastra uma nova disciplina
void cadastrar()
{
    // Importa as informações que estão no disciplinas.txt
    carregar();

    // Se já tiver atinjindo o número máximo de disciplinas cadastradas
    if (contador >= MAX_DISCIPLINAS)
    {
        printf("Limite atingido.\n");
        return;
    }

    // Atribui um id para a nova disciplina
    disciplinas[contador].id = contador + 1;

    // Pede as informações de cadastro
    printf("Nome: ");
    scanf(" %[^\n]", disciplinas[contador].nome);
    printf("Professor: ");
    scanf(" %[^\n]", disciplinas[contador].professor);
    printf("Semestre: ");
    scanf(" %[^\n]", disciplinas[contador].semestre);
    printf("Curso: ");
    scanf(" %[^\n]", disciplinas[contador].curso);

    // Adiciona +1 ao contador
    contador++;

    // Salva a nova disciplina
    salvar();

    printf("Disciplina cadastrada!\n");
}

// Salva a nova disciplina
void salvar()
{
    // Abre o arquivo de disciplinas
    FILE *arquivo = fopen("disciplinas.txt", "w");

    // Se ouver algum erro
    if (arquivo == NULL)
    {
        printf("Erro ao salvar arquivo.\n");
        return;
    }

    // Roda pela quantidade de disciplinas existentes
    for (int i = 0; i < contador; i++)
    {
        // Escreve no arquivo a disciplina atual do for
        fprintf(arquivo, "ID: %d; NOME: %s; PROFESSOR: %s; SEMESTRE: %s; CURSO: %s\n",
                disciplinas[i].id,
                disciplinas[i].nome,
                disciplinas[i].professor,
                disciplinas[i].semestre,
                disciplinas[i].curso);
    }

    // Fecha o arquivo
    fclose(arquivo);
}

// Lista as disciplinas existentes
void listar()
{

    // Importa as informações que estão no disciplinas.txt
    carregar();

    // Se não houver disciplinas
    if (contador == 0)
    {
        printf("Nenhuma disciplina cadastrada.\n");
        return;
    }

    printf("\n--- Disciplinas cadastradas ---\n");

    // Roda pela quantidade de discplinas existentes
    for (int i = 0; i < contador; i++)
    {
        // Mostra as informações da disciplina atual do for
        printf("%d - %s | Prof: %s | %s | %s\n",
               disciplinas[i].id,
               disciplinas[i].nome,
               disciplinas[i].professor,
               disciplinas[i].semestre,
               disciplinas[i].curso);
    }
}

// Edita uma disciplina
void editar()
{
    // Importa as informações que estão no disciplinas.txt
    carregar();

    // Se não houver disciplinas
    if (contador == 0)
    {
        printf("Nenhuma disciplina cadastrada\n");
        return;
    }

    printf("Disciplinas:\n");

    // Roda pela quantidade de disciplinas existentes
    for (int i = 0; i < contador; i++)
    {
        printf("ID: %d,Nome: %s\n", disciplinas[i].id, disciplinas[i].nome);
    }

    int identificador;

    // Pede o id da disciplina a ser editada
    printf("\nDigite o ID da disciplina para editar:");
    scanf("%d", &identificador);

    int indice = -1;

    // Roda pela quantidade de disciplinas existentes
    for (int i = 0; i < contador; i++)
    {
        // Se o id da disciplina atual for igual ao id digita para ser editado
        if (disciplinas[i].id == identificador)
        {

            // O indice vai receber o valor do id
            indice = i;
            break;
        }
    }

    // Se o id não tiver sido encontrado
    if (indice == -1)
    {
        printf("Disciplina não encontrada\n");
        return;
    }

    int opcao;
    do
    {
        // Pergunta o que deve ser alterado
        printf("O que deseja alterar?\n");
        printf("1)professor:\n");
        printf("2)Semestre:\n");
        printf("3)Curso:\n");
        scanf("%d", &opcao);
        getchar();

        // Caso escolha uma opção inválida
        if(opcao < 1 || opcao > 3){
            printf("Opcao invalida, escolha novamente: \n");
        }

    // Roda enquanto a escolha for inválida
    }while(opcao < 1 || opcao > 3);

    // Altera o professor
    if (opcao == 1)
    {
        printf("Novo professor:");
        scanf(" %99[^\n]", disciplinas[indice].professor);
    }
    // Altera o semestre
    else if (opcao == 2)
    {
        printf("Novo semestre:");
        scanf(" %49[^\n]", disciplinas[indice].semestre);
    }
    // Altera o curso
    else if (opcao == 3)
    {
        printf("Novo Curso:");
        scanf(" %99[^\n]", disciplinas[indice].curso);
    }

    // Salva as disciplinas
    salvar();

    printf("disciplina editada com sucesso. TMJ!\n");

}

// Mostra as notas existentes
void ConsultarNotas()
{

    // Abre o arquivo de notas
    FILE *arquivoNotas = fopen("notas.txt", "r");

    // Se o arquivo não existir
    if (arquivoNotas == NULL)
    {
        // Cria o arquivo
        FILE *f = fopen("notas.txt", "w+");
        fclose(f);
        arquivoNotas = fopen("notas.txt", "r");

        // Caso aconteça um erro
        if(arquivoNotas == NULL){
            printf("Houve um erro ao tentar abrir o arquivo\n");
            return;
        }

    }

    printf("\n--- LISTA DE NOTAS ---\n");

    // Pega as linhas no arquivo de notas e coloca os valores no struct de notas, e verifica se todos os dados da disciplinas estão sendo pegos
    while (fscanf(arquivoNotas,
                  "ID_ALUNO: %d; NOME_ALUNO: %[^;]; ID_DISCIPLINA: %d; NOME_DISCIPLINA: %[^;]; MEDIA: %f\n",
                  &n.idAluno,
                  n.nomeAluno,
                  &n.idDisciplina,
                  n.nomeDisciplina,
                  &n.media) == 5)
    {

        // Mostra os dados da nota atual do while
        printf("Aluno: %s (ID %d) | Disciplina: %s (ID %d) |  Media: %.2f\n",
               n.nomeAluno, n.idAluno, n.nomeDisciplina, n.idDisciplina, n.media);
    }

    // Fecha o arquivo de notas
    fclose(arquivoNotas);
    printf("\n--- Fim da lista ---\n");

}

// Cadastra uma nova nota
void CadastrarNotas()
{
    printf("\n--- CADASTRO DE NOTAS ---\n");

    int idAlunoSelecionado = -1;
    int idDisciplinaSelecionada = -1;
    float nota1, nota2;

    // Pede a primeira letra no nome do aluno que terá sua nota cadastrada
    char letraInicial;
    printf("Digite a letra inicial do aluno desejado: ");
    while (getchar() != '\n')
        ;
    scanf("%c", &letraInicial);

    // Garante sempre que a letra seja maiuscula
    if (letraInicial >= 'a' && letraInicial <= 'z')
    {
        // Faz uma subtração com base nos valores ASCII para pegar a versão maiúscula de uma letra minúscula
        letraInicial = letraInicial - ('a' - 'A');
    }

    // Cria o nome do arquivo da letra diminuido
    char nomeArquivo[7];
    nomeArquivo[0] = letraInicial;
    nomeArquivo[1] = 'D';
    nomeArquivo[2] = '.';
    nomeArquivo[3] = 't';
    nomeArquivo[4] = 'x';
    nomeArquivo[5] = 't';
    nomeArquivo[6] = '\0';

    // Abre o arquivo da letra do aluno
    FILE *arquivoAluno = fopen(nomeArquivo, "r");

    // Se o arquivo não existir
    if (arquivoAluno == NULL)
    {
        printf("Nenhum aluno encontrado com a letra %c.\n", letraInicial);
        return;
    }

    printf("\n=== Lista de alunos com a letra %c ===\n", letraInicial);
    char linha[200];

    // Roda por cada linha do arquivo da letra do aluno
    while (fgets(linha, sizeof(linha), arquivoAluno))
    {
        // Mostra a linha
        printf("%s", linha);
    }

    

    // Pede o id do aluno que tera sua nota cadastrada com base nas informações que foram mostradas na tela
    printf("Selecione o Aluno pelo numero de identificacao (ID): ");
    scanf("%d", &idAlunoSelecionado);

    // Salva o id do aluno no struct de notas
    n.idAluno = idAlunoSelecionado;

    int idAtual, achou = 0;
    int dentro = 0;
    char buffer[200];

    // Roda por cada linha do arquivo da letra do nome do aluno
    while (fgets(buffer, sizeof(buffer), arquivoAluno))
    {

        // Pega o id do aluno naquela linha
        if (sscanf(buffer, "ID: %d", &idAtual) == 1)
        {

            // Se o id que foi pego na linha for igual ao id do aluno que terá sua nota cadastrada
            dentro = (idAtual == idAlunoSelecionado);
            if (dentro)
            {
                achou = 1;

                // Salva os dados necessarios no struct de nota
                fgets(buffer, sizeof(buffer), arquivoAluno);
                sscanf(buffer, "Nome: %[^\n]", n.nomeAluno);

                // Roda até achar o simbolo de divisória de alunos '-'
                while (fgets(buffer, sizeof(buffer), arquivoAluno))
                {
                    if (buffer[0] == '-')
                        break;
                }
                continue;
            }
        }
    }

    // Fecha o arquivo da letra do aluno
    fclose(arquivoAluno);

    // Se não existir aluno com aquele id
    if (!achou)
    {
        printf("Aluno com ID %d não encontrado.\n", idAlunoSelecionado);
        return;
    }

    // Lista as disciplinas existentes
    listar();

    // Pede pra escolher a disciplina pelo id
    printf("Selecione a disciplina pelo numero de identificacao (ID): ");
    scanf("%d", &idDisciplinaSelecionada);
    
    // Salva o id da disciplina no struct de notas
    n.idDisciplina = idDisciplinaSelecionada;

    // Abre o arquivo das disciplinas
    FILE *origemDisc = fopen("disciplinas.txt", "r");
    if (origemDisc == NULL)
    {
        printf("Erro ao abrir o arquivo de disciplinas.\n");
        return;
    }

    achou = 0;
    dentro = 0;
    char bufferDisc[200];

    // Roda por cada linha do arquivo de disciplinas
    while (fgets(bufferDisc, sizeof(bufferDisc), origemDisc))
    {
        struct Disciplina disc;
        
        // Guarda os valores (id, professor, semestre e curso) no struct de disciplinas e guarda o nome da disciplina no struct de notas e ve se todos os valores estão sendo pegos
        if (sscanf(bufferDisc,
                   "ID: %d; NOME: %[^;]; PROFESSOR: %[^;]; SEMESTRE: %[^;]; CURSO: %[^\n]",
                   &disc.id,
                   n.nomeDisciplina,
                   disc.professor,
                   disc.semestre,
                   disc.curso) == 5)
        {
            // Se o id da disciplina que foi digitado for o mesmo que está sendo verificado pelo while
            if (disc.id == idDisciplinaSelecionada)
            {
                achou = 1;
                break;
            }
        }
    }

    // Fecha o arquivo de disciplinas
    fclose(origemDisc);

    // Caso não tenha achado o id da disciplina
    if (!achou)
    {
        printf("ID %d não encontrado.\n", idDisciplinaSelecionada);
        return;
    }

    // Verifica se o aluno já tem uma nota cadastrada pra essa disciplina
    if (NotaJaCadastrada(n.idAluno, n.idDisciplina))
    {
        printf("\nJa existe nota cadastrada para o aluno nesta disciplina.\n");
        printf("Nota cadastrada: N1=%.2f, N2=%.2f, Media=%.2f\n",
               nota1, nota2, n.media);
        return;
    }

    // Pede as notas do primeior e do segundo bimestre
    printf("Digite a Nota do 1o bimestre (n1): ");
    scanf("%f", &nota1);
    printf("Digite a Nota do 2o bimestre (n2): ");
    scanf("%f", &nota2);

    // Calcula a média
    n.media = (nota1 + nota2) / 2;

    // Abre o arquivo de notas
    FILE *arquivoNotas = fopen("notas.txt", "a");
    if (arquivoNotas == NULL)
    {
        printf("Erro ao abrir o arquivo para cadastro.\n");
        return;
    }

    // Salva a nota no arquivo
    fprintf(arquivoNotas, "ID_ALUNO: %d; NOME_ALUNO: %s; ID_DISCIPLINA: %d; NOME_DISCIPLINA: %s; MEDIA: %.2f\n",
            n.idAluno, n.nomeAluno, n.idDisciplina, n.nomeDisciplina, n.media);

    // Fecha o arquivo de notas
    fclose(arquivoNotas);

    printf("\nNota cadastrada com sucesso. Media final: %.2f\n", n.media);
    
}

// Verifica se já existe uma nota cadastrada para aquele aluno naquela disciplina
int NotaJaCadastrada(int idAl, int idDisc)
{

    // Abre o arquivo de notas
    FILE *arquivoNotas = fopen("notas.txt", "r");
    if (arquivoNotas == NULL)
    {
        return 0;
    }

    // Cria uma struct nota pra receber valores temporários
    struct Nota tempNota;
    int existe = 0;

    // Roda por cada linha do arquivo, pega os 5 valores e coloca no struct nota de valores temporarios
    while (fscanf(arquivoNotas, "ID_ALUNO: %d; NOME_ALUNO: %[^;]; ID_DISCIPLINA: %d; NOME_DISCIPLINA: %[^;]; MEDIA: %f\n",
                  &tempNota.idAluno,
                  &tempNota.nomeAluno,
                  &tempNota.idDisciplina,
                  &tempNota.nomeDisciplina,
                  &tempNota.media) == 5)
    {

        // Se já existir uma nota para o aluno sendo verificado na disciplina sendo verificada
        if (tempNota.idAluno == idAl && tempNota.idDisciplina == idDisc)
        {

            // Fala que já existe e sai
            existe = 1;
            break;
        }
    }

    // Fecha o arquivo de notas
    fclose(arquivoNotas);
    return existe;
}

// Excluir uma nota
void ExcluirNotas()
{
    printf("\n--- EXCLUSAO DE NOTAS ---\n");

    int idAlunoSelecionado = -1;
    int idDisciplinaSelecionada = -1;
    float nota1, nota2;

    // Pede pro usuário digitar a letra inicial
    char letraInicial;
    printf("Digite a letra inicial do aluno desejado: ");
    while (getchar() != '\n')
        ;
    scanf("%c", &letraInicial);

    // Garante sempre que a letra seja maiuscula
    if (letraInicial >= 'a' && letraInicial <= 'z')
    {
        // Faz uma subtração com base nos valores ASCII para pegar a versão maiúscula de uma letra minúscula
        letraInicial = letraInicial - ('a' - 'A');
    }

    // Cria o nome do arquivo diminuido
    char nomeArquivo[7];
    nomeArquivo[0] = letraInicial;
    nomeArquivo[1] = 'D';
    nomeArquivo[2] = '.';
    nomeArquivo[3] = 't';
    nomeArquivo[4] = 'x';
    nomeArquivo[5] = 't';
    nomeArquivo[6] = '\0';

    // Abre o arquivo da letra do aluno
    FILE *arquivoAluno = fopen(nomeArquivo, "r");
    if (arquivoAluno == NULL)
    {
        printf("Nenhum aluno encontrado com a letra %c.\n", letraInicial);
        return;
    }

    printf("\n=== Lista de alunos com a letra %c ===\n", letraInicial);
    char linha[200];

    // Roda por cada linha do arquivo da letro do usuário
    while (fgets(linha, sizeof(linha), arquivoAluno))
    {

        // Mostra a linha
        printf("%s", linha);
    }

    // Pede pra digitar o id do aluno a ter sua nota excluída
    printf("Selecione o Aluno pelo numero de identificacao (ID): ");
    scanf("%d", &idAlunoSelecionado);

    // Salva o id do aluno no struct de nota
    n.idAluno = idAlunoSelecionado;

    int idAtual, achou = 0;
    int dentro = 0;
    char buffer[200];

    // Roda por cada linha do arquivo da letra do aluno
    while (fgets(buffer, sizeof(buffer), arquivoAluno))
    {

        // Pega o id do aluno sendo verificado
        if (sscanf(buffer, "ID: %d", &idAtual) == 1)
        {

            // Se o id sendo verificado no while for igual ao id do aluno que terá sua nota excluída
            dentro = (idAtual == idAlunoSelecionado);
            if (dentro)
            {
                achou = 1;

                // Pega o nome do aluno e coloca no struct de nota
                fgets(buffer, sizeof(buffer), arquivoAluno);
                sscanf(buffer, "Nome: %[^\n]", n.nomeAluno);

                // Roda até chegar no simbolo de separação de alunos: '-'
                while (fgets(buffer, sizeof(buffer), arquivoAluno))
                {
                    if (buffer[0] == '-')
                        break;
                }
                continue;
            }
        }
    }

    // Fecha o arquivo
    fclose(arquivoAluno);

    // Se não achou um aluno, mostra uma mensagem de erro
    if (!achou)
    {
        printf("Aluno com ID %d não encontrado.\n", idAlunoSelecionado);
        return;
    }

    // Lista todas as disciplinas
    listar();

    // Pede o id da disciplinas que terá sua nota excluída
    printf("Selecione a disciplina pelo numero de identificacao (ID): ");
    scanf("%d", &idDisciplinaSelecionada);

    // Salva o id da disciplina
    n.idDisciplina = idDisciplinaSelecionada;

    // Abre o arquivo de disciplinas
    FILE *origemDisc = fopen("disciplinas.txt", "r");
    if (origemDisc == NULL)
    {
        printf("Erro ao abrir o arquivo completo.\n");
        return;
    }

    achou = 0;
    dentro = 0;
    char bufferDisc[200];

    // Roda por cada linha do arquivo de disciplinas
    while (fgets(bufferDisc, sizeof(bufferDisc), origemDisc))
    {

        // Cria um struct de disciplina
        struct Disciplina disc;

        // Guarda os valores (id, professor, semestre e curso) no struct de disciplinas e guarda o nome da disciplina no struct de notas e ve se todos os valores estão sendo pegos
        if (sscanf(bufferDisc,
                   "ID: %d; NOME: %[^;]; PROFESSOR: %[^;]; SEMESTRE: %[^;]; CURSO: %[^\n]",
                   &disc.id,
                   n.nomeDisciplina,
                   disc.professor,
                   disc.semestre,
                   disc.curso) == 5)
        {

            // Se o id da disciplina que terá sua notá excluida for igual ao id que está sendo verificado atualmente
            if (disc.id == idDisciplinaSelecionada)
            {

                // Diz que achou e sai do while
                achou = 1;
                break;
            }
        }
    }

    // Fecha o arquivo de disciplinas
    fclose(origemDisc);

    // Caso não tenha achado uma disciplina com aquele id, mostra uma mensagem de erro
    if (!achou)
    {
        printf("ID %d não encontrado.\n", idDisciplinaSelecionada);
        return;
    }

    // Verifica se existe uma nota para ser excluída
    if (!NotaJaCadastrada(n.idAluno, n.idDisciplina))
    {
        // Caso a nota não exista
        printf("\nNao existia nota cadastrada para excluir para o Aluno ID %d na Disciplina ID %d.\n",
               idAlunoSelecionado, idDisciplinaSelecionada);
        return;
    }

    // Abre o arquivo de notas
    FILE *arquivoOriginal = fopen("notas.txt", "r");

    // Cria um arquivo de notas temporárias
    FILE *arquivoTemporario = fopen("temp_notas.txt", "w");

    // Se não existir o arquivo de notas ou der erro ao criar o arquivo temporário
    if (arquivoOriginal == NULL || arquivoTemporario == NULL)
    {
        printf("Erro ao manipular o arquivo de notas. Exclusao falhou.\n");

        // Fecha o arquivo que foi aberto e encerra o processo de exclusão
        if (arquivoOriginal)
            fclose(arquivoOriginal);
        if (arquivoTemporario)
            fclose(arquivoTemporario);
        return;
    }

    // Cria um struct de nota temporaria
    struct Nota tempNota;
    int removido = 0;

    // Roda por cada linha do arquivo de notas enquanto salva os valores no struct de notas temporárias
    while (fscanf(arquivoOriginal, "ID_ALUNO: %d; NOME_ALUNO: %[^;]; ID_DISCIPLINA: %d; NOME_DISCIPLINA: %[^;]; MEDIA: %f\n",
                  &tempNota.idAluno,
                  tempNota.nomeAluno,
                  &tempNota.idDisciplina,
                  tempNota.nomeDisciplina,
                  &tempNota.media) == 5)
    {

        // Se a nota for diferente da que será excluída, ela será copiada para o arquivo temporário
        if (!(tempNota.idAluno == idAlunoSelecionado && tempNota.idDisciplina == idDisciplinaSelecionada))
        {
            fprintf(arquivoTemporario, "ID_ALUNO: %d; NOME_ALUNO: %s; ID_DISCIPLINA: %d; NOME_DISCIPLINA: %s; MEDIA: %.2f\n",
                    tempNota.idAluno, tempNota.nomeAluno, tempNota.idDisciplina, tempNota.nomeDisciplina, tempNota.media);
        }
        // Se for a nota que será excluída, ela não será copiada para o arquivo temporário
        else
        {
            // Fala que a nota foi encontrada
            removido = 1;
        }
    }

    // Fecha os arquivos
    fclose(arquivoOriginal);
    fclose(arquivoTemporario);

    // Caso tenha achado a nota que será excluida
    if (removido)
    {
        // Apaga o arquivo de notas
        remove("notas.txt");            

        // Renomeia o arquivo temporário de notas para "notas.txt"
        rename("temp_notas.txt", "notas.txt");

        printf("\n Nota do Aluno ID %d na Disciplina ID %d removida com sucesso.\n",
               idAlunoSelecionado, idDisciplinaSelecionada);
    }
    // Caso não tenha achado a nota que será excluída
    else
    {
        // Apaga o arquivo temporário e mostra uma mensagem de erro
        remove("temp_notas.txt");
        printf("\nNao foi possivel remover a nota (erro de arquivo).\n");
    }
}

int main()
{
    gerenciarContador();
    menuInicial();
    return 0;
}
