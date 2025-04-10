#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria 
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Fun��o respos�vel por cadastrar os usu�rios no sistema 
{
	//Inicio de cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando inform��o do usu�rio
	scanf("%s", cpf); //%s refere-se ao save da string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e avisa que colocar� uma nova info/atualiza��o("a")
	fprintf(file,","); //a introdu��o da virgula seria a nova info/atualiza��o do arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //usu�rio digita o nome
	scanf("%s",nome);//salva o nome na string
	
	file = fopen(arquivo, "a");//abre o arquivo e avisa que colocar� uma nova info/atualiza��o("a")
	fprintf(file,nome);//a introdu��o do nome seria a nova info/atualiza��o do arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e avisa que colocar� uma nova info/atualiza��o("a")
	fprintf(file,","); //a introdu��o da virgula seria a nova info/atualiza��o do arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");//usu�rio digita o sobrenome
	scanf("%s",sobrenome);//salva o sobrenome na string
	
	file = fopen(arquivo, "a");//abre o arquivo e avisa que colocar� uma nova info/atualiza��o("a")
	fprintf(file,sobrenome);//a introdu��o do sobrenome seria a nova info/atualiza��o do arquivo 
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e avisa que colocar� uma nova info/atualiza��o("a")
	fprintf(file,",");//a introdu��o da virgula seria a nova info/atualiza��o do arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");//usu�rio digita o cargo
	scanf("%s",cargo);//salva o cargo na string
	
	file = fopen(arquivo, "a");//abre o arquivo e avisa que colocar� uma nova info/atualiza��o("a")
	fprintf(file,cargo);//a introdu��o do cargo seria a nova info/atualiza��o do arquivo 
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
	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
}
	
    while(fgets(conteudo, 200, file) != NULL)
{
	printf("\nEssas s�o as informa��es do usu�rio: ");
	printf("%s", conteudo);
	printf("\n\n");
}
  	
    system ("pause");	
}

int deletar()
{
   char cpf[40];
   
   printf("Digite o cpf do usu�rio a ser deletado: ");
   scanf("%s",cpf);
   
   remove(cpf);
   printf("O usu�rio foi deletado!.\n");
   system("pause");
   
   FILE *file;
   file = fopen(cpf,"r");
   
   if(file == NULL)
  {
       printf("O usu�rio n�o se encontra no sistema!.\n");
	   system("pause");
	 
  }
   
}

int main() 
   {
	int opcao=0; // Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls");
	
	    setlocale(LC_ALL,"Portuguese"); // Definindo a linguagem
	
	    printf("### Cart�rio da EBAC ###\n\n"); // Inicio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
 	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
		printf("\t4 - Sair do sistema\n\n"); 
	    printf("Op��o: "); // Fim do menu
	
	    scanf("%d", &opcao); // Armazenando a escolha do usu�rio
	
	system("cls"); //respons�vel por limpar a tela
	
	switch(opcao) //inicio da sele��o de menu
	{
		case 1:
	    registro(); //chamada de fun��es
	    break;
	    
	    case 2:
	    consulta();
	    break;
	    
	    case 3:
	    deletar();
	    break;
	    
	    case 4:
	    printf("Obrigado por ustilizar o sistema!\n");
	    return 0;
	    break;
	    
	    default:
	    printf("Essa op��o n�o est� disponivel!\n");
	    system("pause");
	    break;
	}//fim da sele��o
    
	
    }
}
