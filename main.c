//Posto beta v10.cpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <dos.h>

struct registro_agenda
	{
		char nome[20];
		char sobrenome[30];
		char telefone[14];
	};

int Registro()
{
	struct registro_agenda agenda;
	int i;
	char url[]="clientes.txt";
	FILE *arq;
	
	arq =fopen(url, "a");
	if(arq == NULL)
		printf("Erro, não foi possível abrir o arquivo\n");
	else
	{
	system("cls");
	printf(" ------------------------------------------ \n");
	printf("|                 Cadastro                 |\n");
	printf(" ------------------------------------------ \n");
	printf("\n");
	
	printf("Nome.............: ");
	fflush(stdin);
	fgets(agenda.nome,20, stdin);
	for (i=0;i<20;i++)
	agenda.nome[i] = toupper(agenda.nome[i]);
	
	
	printf("Sobrenome........: ");
	fflush(stdin);
	fgets(agenda.sobrenome,30, stdin);
	for (i=0;i<30;i++)
	agenda.sobrenome[i] = toupper(agenda.sobrenome[i]);
	
	printf("Telefone.........: ");
	fflush(stdin);
	fgets(agenda.telefone, 14, stdin);
	
	
	fprintf(arq,"Nome.............: %s\n", agenda.nome);
	fprintf(arq,"Sobrenome........: %s\n", agenda.sobrenome);
	fprintf(arq,"Telefone.........: %s\n\n", agenda.telefone);
	
	
	system("cls");
	printf("Cadastrado com sucesso");
	fclose(arq);
	}
}

int Consulta()
{
	
	char url[]="clientes.txt",
		 contatos[300];
	struct registro_agenda agenda;
	FILE *arq;
	
	printf(" ------------------------------------------ \n");
	printf("|                 Consulta                 |\n");
	printf(" ------------------------------------------ \n");
	printf("\n");
	
	arq= fopen(url, "r");
	if (arq == NULL)
	{
		printf("\n Erro na consulta. Procure o suporte!");
	}else
	{
		while((fgets(contatos, sizeof(contatos), arq)) != NULL)	
			printf("%s", contatos);
	}
	fclose(arq);
}

int SelecionarCliente()
{
	char url[] = "clientes.txt",
		 cliente[20],
		 comprador[20],
		 descart[20],
		 cad[2],
		 limite[500];
	char *testecad;	 
	int i;
	FILE *arq;
	
	testecad = "S";
	inicio:
	printf("\nDigite o nome do cliente: ");
	fflush(stdin);
	gets(comprador);
	for(i=0;i<sizeof(comprador);i++)
	{
		comprador[i] = toupper(comprador[i]);
	}
	
	arq = fopen(url,"r");
	if (arq == NULL)
		printf("Erro ao ler o registro dos clientes\n");
	else
	{
		while(!feof(arq))
		{
			fscanf(arq, "%s %s\n", descart, cliente);
			
			if((strcmp(cliente,comprador)) == 0)
			break;		
		}	
		
		if(strcmp(cliente,comprador) == 0)
		{
			system("cls");
			printf("Bem vindo, %s!\n\n", cliente);
		}
		else
		{
			printf("Nome não encontrado!\n\n");
			printf("Por favor, cadastrar antes de usar o programa.\n\n");
			printf("Deseja cadastrar? <S ou N>\n");
			scanf(" %c", &cad);
			printf("\n");
			for(i=0;i<2;i++){
				cad[i] = toupper(cad[i]);
			}
			if(strcmp(cad,testecad) == 0)
			{
				Registro();
			} else
			{
				printf("Cadastro obrigatório para se fazer uma compra!\n");
				goto inicio;
			}	
		}
	}
	fclose(arq);
}

main ()
{
	float result, litros,preco,totalgasto,totalgastoflex;
	char op[2],cod,comb;
	char* teste;
	char flex[2];
	char dif[2];
	char* testeflex;
	char* testedif;
	int i,diferente;
	char data
	
	setlocale(LC_ALL, "Portuguese");
	
	result = 0;
	teste = "S";
	testeflex = "S";
	testedif = "S";
	totalgasto = 0;
	totalgastoflex = 0;
	while (result == 0)
	{
		inicio:
		totalgasto = 0;
		totalgastoflex = 0;
		printf("\n");
		printf(" ------------------------- \n");
		printf("|   O que deseja fazer?   |\n");
		printf("|-------------------------|\n");
		printf("|#########################|\n");
		printf("|-------------------------|\n");
		printf("|  A - Adicionar Cliente  |\n");
		printf("|  C - Consultar Clientes |\n");
		printf("|  V - Fazer uma Venda    |\n");
		printf("|  X - Fechar o Programa  |\n");
		printf(" ------------------------- \n");
		printf("\n");
		printf("Código: \n");
		scanf(" %s", &cod);
		cod = toupper(cod);
		switch (cod)
		{
		
			case 'A':
				
				system("cls");
				Registro();
				printf("\n");
				goto inicio;
			
			case 'C':
				system("cls");
				printf("\n");
				Consulta();
				goto inicio;
			
			case 'V':
				SelecionarCliente();
				combustivel:
				//system("cls");
				printf(" ---------------------- \n");
				printf("|   Tabela de preços   |\n");
				printf("|----------------------|\n");
				printf("|######################|\n");
				printf("|----------------------|\n");
				printf("| G - Gasolina  | 3.30 |\n");
				printf("| A - Álcool    | 2.90 |\n");
				printf("| D - Diesel    | 1.90 |\n");
				printf("| N - GNV       | 1.20 |\n");
				printf(" ---------------------- \n");
				printf("\n");
				printf("Código: \n");
				scanf(" %s", &comb);
				comb = toupper(comb);
				switch(comb)
				{
					case 'G':
						printf("\n");
						printf("Quantos litros de gasolina deseja colocar?\n");	
						preco = 3.3;
						break;
					case 'A':
						printf("\n");
						printf("Quantos litros de Álcool deseja colocar?\n");
						preco = 2.9;
						break;
					case 'D':
						printf("\n");
						printf("Quantos litros de Diesel deseja colocar?\n");
						preco = 1.9;
						break;
					case 'N':
						printf("\n");
						printf("Quantos litros de GNV deseja colocar?\n");
						preco = 1.2;
						break;
					default:
						system("cls");
						printf("\n");
						printf("Código inválido. Tente outra vez.\n");						
						goto combustivel;
				}
				scanf(" %f", &litros);
				printf("\n");
				totalgasto = litros * preco;
				totalgastoflex = totalgastoflex + totalgasto;
				printf("R$ %.2f\n", totalgastoflex);
				printf("É carro flex? <S ou N> \n");
				scanf(" %s", &flex);
				for (i = 0;i<2;i++)
				{
					flex[i] = toupper(flex[i]);
				}
				result = strcmp(flex,testeflex);
				if (result == 0)
				{
					printf("\n");
					printf("Deseja por um combustível diferente? <S ou N>\n");
					scanf(" %s",dif);
					for (i = 0;i<2;i++)
					{
					dif[i] = toupper(dif[i]);
					}
					diferente = strcmp(dif,testedif);
					if (diferente == 0)
					{
						system("cls");
						goto combustivel;
					}
					system("cls");
				}
				else
				{
					goto inicio;
				}
				break;
			case 'X':
				system("cls");
				printf("\n");
				printf("Obrigado por usar o programa!");
				result = 1;
				break;
			default:
				system("cls");
				printf("Código inválido, tente outra vez\n");
				goto inicio;
		}
	}	
}