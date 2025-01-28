#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória 
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsÃ¡vel por cuidar das string

int registro() //Função resposável por cadastrar os usuários no sistema 
{
	//Inicio de criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informção do usuário
	scanf("%s", cpf); //%s refere-se ao save da string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e avisa que colocará uma nova info/atualização("a")
	fprintf(file,","); //a introdução da virgula seria a nova info/atualização do arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //usuário digita o nome
	scanf("%s",nome);//salva o nome na string
	
	file = fopen(arquivo, "a");//abre o arquivo e avisa que colocará uma nova info/atualização("a")
	fprintf(file,nome);//a introdução do nome seria a nova info/atualização do arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e avisa que colocará uma nova info/atualização("a")
	fprintf(file,","); //a introdução da virgula seria a nova info/atualização do arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//usuário digita o sobrenome
	scanf("%s",sobrenome);//salva o sobrenome na string
	
	file = fopen(arquivo, "a");//abre o arquivo e avisa que colocará uma nova info/atualização("a")
	fprintf(file,sobrenome);//a introdução do sobrenome seria a nova info/atualização do arquivo 
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e avisa que colocará uma nova info/atualização("a")
	fprintf(file,",");//a introdução da virgula seria a nova info/atualização do arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//usuário digita o cargo
	scanf("%s",cargo);//salva o cargo na string
	
	file = fopen(arquivo, "a");//abre o arquivo e avisa que colocará uma nova info/atualização("a")
	fprintf(file,cargo);//a introdução do cargo seria a nova info/atualização do arquivo 
	fclose(file);//fecha o arquivo	
	
    system("pause");//pausar a tela para ser possivel a leitura

}

int consulta()
{
   setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    char cpf[40];
    char conteudo[200];
	
    printf("Digite o CPF a ser consultado: ");
    scanf("%s",cpf);
  	
    FILE *file;
    file = fopen(cpf,"r");
  	
    if(file == NULL)
{
	printf("Não foi possivel abrir o arquivo, não localizado!.\n");
}
	
    while(fgets(conteudo, 200, file) != NULL)
{
	printf("\nEssas são as informações do usuário: ");
	printf("%s", conteudo);
	printf("\n\n");
}
  	
    system ("pause");	
}

int deletar()
{
   char cpf[40];
   
   printf("Digite o cpf do usuário a ser deletado: ");
   scanf("%s",cpf);
   
   remove(cpf);
   printf("O usuário foi deletado!.\n");
   system("pause");
   
   FILE *file;
   file = fopen(cpf,"r");
   
   if(file == NULL)
  {
       printf("O usuário não se encontra no sistema!.\n");
	   system("pause");
	 
  }
   
}

int main() 
   {
	int opcao=0; // Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls");
	
	    setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
	
	    printf("### Cartório da EBAC ###\n\n"); // Inicio do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
 	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n"); 
	    printf("Opção: "); // Fim do menu
	
	    scanf("%d", &opcao); // Armazenando a escolha do usuário
	
	system("cls"); //responsável por limpar a tela
	
	switch(opcao) //inicio da seleção de menu
	{
		case 1:
	    registro(); //chamada de funções
	    break;
	    
	    case 2:
	    consulta();
	    break;
	    
	    case 3:
	    deletar();
	    break;
	    
	    default:
	    printf("Essa opção não está disponivel!\n");
	    system("pause");
	    break;
	}//fim da seleção
    
	
    }
}
