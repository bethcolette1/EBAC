#include <stdio.h> //biblioteca de comunicacao com o usuario
#include <stdlib.h> //biblioteca de alocar espacos na memoria
#include <locale.h> //biblioteca de alocacao de textos por regiao
#include <string.h> //bibilioteca responsável por cuidar das string

int registro() //função responsável por cadastrar os usuários nos sistema
{
	//inicio criação de viriáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string

	FILE *file; // cria o arquivo no banco de dados
	file = fopen(arquivo, "w"); // salva na pasta //w write, cria uma nova, escreve
	fprintf(file, cpf); // salva o valor da variavel 
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //a atualizar
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
} //fim da função

int consulta () //função responsável por consultar os usuários nos sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	
	printf("Digite o CPF a ser consultado");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //r read ler o arquivo
	
	if(file == NULL)
	{
		printf("Nao foi possivel abrir o arquivo, nao foi localizado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário");
		printf("%s", conteudo);
		printf("\n\n");
		
	}

system("pause");	
} // fim da função consultar

int deletar () //função responsável por deletar os usuários nos sistema
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("o usuário não se encontra no sistema! . \n");
		system("pause");
	}
	
	else //senão
	{
		remove(cpf); //remover usuário
		printf("o usuário foi deletado!");
		system("pause");
		
	}
	
} //fim da função

int main ()
{
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;) // entrada;saída
	{
	
		system("cls");
		
	    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
		
		printf("### Cartório da EBAC ###\n\n"); //inicio do menu
		printf("Escolha a opção desejado do menu:\n\n"); //printf escrita na tela
		printf("\t1 - Registrar nome\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t4 - sair do sistema\n\n");
		printf("opção: ");//fim do menu
	
		scanf("%d", &opcao); //inicio da seleção
	//scanf lê o imput do usuário/ %d digito na variavel opção
	
		system("cls"); //roda o comando no prompt de comando
		
		switch(opcao)
		{
			case 1:
			registro(); // chamada de funções
			break; //encerrar opção
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause");
			break;
				
		} //fim da seleção
	
	
	
}
}

