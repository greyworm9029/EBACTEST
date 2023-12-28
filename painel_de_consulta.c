#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Função para limpar a tela
void clearScreen() {
    system("cls");
}

// Função para registrar nomes
void registro() {
	
	// Criando as variáveis 'cpf', 'nome', 'sobrenome' e 'cargo'
    char cpf[40], nome[40], sobrenome[40], cargo[40];
    
    // Solicita o cpf
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf); 
    
    // Tenta abrir o arquivo para a escrita
    FILE *file = fopen(cpf, "w"); 
    
    // Verificação de Validação 
    if (file == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return;
    }
    
    // Salva o cpf no arquivo e fecha
    fprintf(file, "%s,", cpf); 
    fclose(file); 
    
    // Solicita o nome
    printf("Digite o nome a ser cadastrado: "); 
    scanf("%s", nome);

	// Abre o arquivo no modo de adição/atualização
    file = fopen(cpf, "a");
    
    // Salva o nome e fecha
    fprintf(file, "%s,", nome);
    fclose(file);

	// Solicita o sobrenome
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

	// Abre o arquivo no modo de adição/atualização
    file = fopen(cpf, "a");
    
    // Salva o sobrenome e fecha
    fprintf(file, "%s,", sobrenome);
    fclose(file);

	// Solicita o cargo
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

	// Salva o cargo e fecha
    file = fopen(cpf, "a");
    fprintf(file, "%s", cargo);
    fclose(file);
}

// Função para consultar nomes
void consulta() {
    setlocale(LC_ALL, "Portuguese");
    
    // Criando as variáveis 'nome' e 'conteúdo'
    char cpf[40], conteudo[200];
    
	// Solicita o 'CPF' a ser consultado
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    // Tenta abrir o arquivo para leitura
    FILE *file = fopen(cpf, "r");

	// Se falhar, exibe mensagem de erro e retorna
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo, não localizado.\n");
        return;
    }

	// Lê o conteúdo do arquivo e exibe na tela 
    while (fgets(conteudo, 200, file) != NULL) {
        printf("\nEssas são as informações do usuário: %s\n\n", conteudo);
        system("pause");
    }

    fclose(file);
}

// Função para deletar nomes
void deletar() {
	// Criando a variável 'CPF'
	char cpf[40];
	
	// Solicita o 'CPF' a ser deletado
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf); 
	
	// Deleta o 'CPF'
	remove(cpf);
	
	// Abre o arquivo para leitura 
	FILE *file = fopen(cpf, "r");
	
	// Se falhar, exibe mensagem de erro e retorna
	if(file == NULL) {
		printf("O usuário não se encontra no sistema!\n");
		system("pause");
	}
	
}

// Função principal
int main() {
	
	// Criando as variáveis 'opção' e 'laço'
    int opcao = 0;
    int laco = 1;
    char senhadigitada[10]="a";
    int comparacao;
    
    printf("### Cartório da EBAC ###\n\n");
    printf("Login de administrador!\n\nDigite a sua senha: ");
    scanf("%s", senhadigitada);
    
    comparacao = strcmp(senhadigitada, "admin");
    
    if(comparacao == 0) {
    	
    	system("cls");
    	while (laco == 1) {
        	clearScreen();

        	setlocale(LC_ALL, "Portuguese");
        
        	// Cabeçalho do programa
        	printf("### Cartório da EBAC ###\n\n");
        
        	// Menu de opções
        	printf("Escolha a opção desejada no menu:\n\n");
        	printf("\t1 - Registrar nomes\n");
        	printf("\t2 - Consultar nomes\n");
        	printf("\t3 - Deletar nomes\n");
        	printf("\t4 - Sair do programa\n\n");
        	printf("Opção: ");
        	scanf("%d", &opcao);

        	clearScreen();

        	switch (opcao) {
            	
				case 1:
                registro();
                break;

            	case 2:
                consulta();
                break;

            	case 3:
                deletar();
                break;
                
                case 4: 
                printf("Obrigado por utilizar o nosso sistema!");
                return 0;
                break;

            	default:
                printf("Essa opção não está disponível!\n");
                system("pause");
                break;
       	 }
    	}
	} 
	
	else
	printf("Senha incorrreta!");
    return 0; // Indica que o programa está funcionando corretamente
}
