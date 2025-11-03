#include <stdio.h>
#include <stdlib.h>

void menuInicial();
void menuAlunos();
void menuDisciplinas();
void menuNotas();

                            // Menu inicial
void menuInicial(){
    int opcaoMenu;

    printf("\n=============== MENU INICIAL ===============\n\n");
    printf("          [1] Gerenciar alunos                \n");
    printf("          [2] Gerenciar disciplinas           \n");
    printf("          [3] Gerenciar notas                 \n");
    printf("          [4] Autores                         \n");
    printf("          [5] Sair                            \n\n");
    printf("==============================================\n");
    printf("-Escolha uma opcao: ");
    scanf("%d", &opcaoMenu);

    switch(opcaoMenu){

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
        while (getchar() != '\n');
        getchar();
        menuInicial();
        break;
        
        case 5:
        exit(0);
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

                        // Gerenciar alunos
void menuAlunos(){
    int opcaoA;

    printf("\n============= GERENCIAR ALUNOS =============\n\n");
    printf("        [1] Consultar alunos                  \n");
    printf("        [2] Cadastrar aluno                   \n");
    printf("        [3] Editar aluno                      \n");
    printf("        [4] Voltar para o menu inicial        \n\n");
    printf("==============================================\n");
    printf("-Escolha uma opcao: ");
    scanf("%d", &opcaoA);

    switch(opcaoA){

        case 1:
        system("cls");
        //Consultar alunos
        break;

        case 2:
        system("cls");
        //Cadastrar aluno
        break;

        case 3:
        system("cls");
        //Editar aluno
        break;

        case 4:
        system("cls");
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


                        // Gerenciar disciplinas
void menuDisciplinas(){
    int opcaoD;

    printf("\n============== MENU DISCIPLINAS ============\n\n");
    printf("         [1] Consultar disciplinas            \n");
    printf("         [2] Cadastrar disciplinas            \n");
    printf("         [3] Editar disciplinas               \n");
    printf("         [4] Voltar para o menu inicial       \n\n");
    printf("==============================================\n");
    printf("-Escolha uma opcao: ");
    scanf("%d", &opcaoD);

    switch (opcaoD){

        case 1:
        system("cls");
        //consultar disciplinas
        break;

        case 2:
        system("cls");
        //cadastrar disciplinas
        break;

        case 3:
        system("cls");
        //editar disciplinas
        break;

        case 4:
        system("cls");
        menuInicial();
        break;

        default:
        printf("\n Opcao invalida, escolha entre uma das opcoes dadas.\n");
        printf(" Pressione ENTER para continuar...\n");
        while (getchar() != '\n');
        getchar();
        menuDisciplinas();
        break;
    }
}


                         // Gerenciar notas
void menuNotas(){
    int opcaoN;

    printf("\n============== GERENCIAR NOTAS =============\n\n");
    printf("         [1] Consultar notas                  \n");
    printf("         [2] Cadastrar notas                  \n");
    printf("         [3] Excluir notas                    \n");
    printf("         [4] Voltar para o menu inicial       \n\n");
    printf("==============================================\n");
    printf("-Escolha uma opcao: ");
    scanf("%d", &opcaoN);
    
    switch(opcaoN){
        
        case 1:
        system("cls");
        //consultar notas
        break;
        
        case 2:
        system("cls");
        //cadastrar notas
        break;
        
        case 3:
        system("cls");
        //excluir notas
        break;
        
        case 4:
        system("cls");
        menuInicial();
        break;
        
        default:
        printf("\n Opcao invalida, escolha entre uma das opcoes dadas.\n");
        printf(" Pressione ENTER para continuar...\n");
        while (getchar() != '\n');
        getchar();
        menuNotas();
        break;
        
    }
    
}



int main(){
    menuInicial();
    return 0;
}
