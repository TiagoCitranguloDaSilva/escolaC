#include <stdio.h>
#include <stdlib.h>

void menuInicial();
void autores();
void menuAlunos();

int main(){
    menuInicial();
    return 0;
}

void menuInicial(){
    int opcaoMenu;

    printf("========== MENU INICIAL ============\n");
    printf("    [1] Gerenciar alunos            \n");
    printf("    [2] Gerenciar disciplinas       \n");
    printf("    [3] Gerenciar notas             \n");
    printf("    [4] Autores                     \n");
    printf("    [5] Sair                        \n");
    printf("====================================\n");
    printf("-Escolha uma opcao: ");
    scanf("%d", &opcaoMenu);

    switch(opcaoMenu){

        case 1:
        menuAlunos();
        break;

        case 2:
        //gerenciar disciplinas
        break;

        case 3:
        //gerenciar notas
        break;

        case 4:
        exit(0);
        break;
        
        case 5:
        menuInicial();
        break;
        
        default:
        printf("\n Opcao invalida, escolha entre uma das opcoes dadas.\n");
        printf(" Pressione ENTER para continuar...\n");
        while (getchar() != '\n');
        getchar();
        menuInicial();
        break;
        
    }
    
    
}

void menuAlunos(){
    int opcaoA;

    printf("\n============ GERENCIAR ALUNOS =============\n");
    printf("   [1] Consultar alunos                    \n");
    printf("   [2] Cadastrar alunos                    \n");
    printf("   [3] Editar aluno                        \n");
    printf("   [4] Sair                                \n");
    printf("===========================================\n");
    printf("-Escolha uma opcao: ");
    scanf("%d", &opcaoA);

    switch(opcaoA){

        case 1:
        //Consultar alunos
        break;

        case 2:
        //Cadastrar alunos
        break;

        case 3:
        //Editar aluno
        break;

        case 4:
        menuInicial();
        break;
        
        default:
        printf("\n Opcao invalida, escolha entre uma das opcoes dadas.\n");
        printf(" Pressione ENTER para continuar...\n");
        while (getchar() != '\n');
        getchar();
        menuAlunos();
        break;
        
    }

}

void menuDisciplinas(){
    int opcaoD;

    printf("\n============= MENU DISCIPLINAS ============\n");
    printf("   [1] Consultar disciplinas               \n");
    printf("   [2] Cadastrar disciplinas               \n");
    printf("   [3] Editar disciplinas                  \n");
    printf("   [4] Sair                                \n");
    printf("-Escolha uma opcao: ");
    scanf("%d", &opcaoD);

    switch (opcaoD){

        case 1:
        //
        break;

        case 2:
        //
        break;

        case 3:
        //
        break;

        case 4:
        menuInicial();
        break

        default:
        printf("\n Opcao invalida, escolha entre uma das opcoes dadas.\n");
        printf(" Pressione ENTER para continuar...\n");
        while (getchar() != '\n');
        getchar();
        menuDisciplinas();
        break;
    }
}

void menuNotas(){
    int opcaoN;

    printf("\n================= GERENCIAR NOTAS ==============\n")
}

void autores(){
    printf("\n\n-------------- AUTORES --------------\n");
    printf("   Camilli dos Santos \n");
    printf("   Gustavo Ferreira dos Santos \n");
    printf("   Jeanderson Silva \n");
    printf("   Luana Gallinari Ranzulla da Silva \n");
    printf("   Matheus de Mello Carvalhaes \n");
    printf("   Otavio Siqueira Goncalves \n");
    printf("   Pedro Henrique Baraldi da Silva \n");
    printf("   Tiago Citrangulo da Silva \n");
    printf("   Victor Wesley Oliveira dos Santos \n");
    printf("------------------------------------------");

    printf("\n Pressione ENTER para continuar...\n");
    while (getchar() != '\n');
    getchar();
    menuInicial();
    
}

