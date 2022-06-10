/*
	Algor�tmo elaborado por:
	
	Nome:	Rafael Cossich Navarro dos Santos
	R.A:	2114.00.87-5

	
	Atividade Mapa - ALPII
	
////////////////////////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\////////////////////////////////////////////////////////////

	Descri��es do registro:
	
	C�digo	-	inteiro
	Titulo	-	string
	Descri��o	- string
	Ano	-	inteiro
	Status	- 1=A fazer; 2=Fazendo; 3=Conclu�do
	Prazo	-	1=Com prazo: inteiro; 2=Sem prazo
	Financiamento	-	1=Aprovado; 2=Em an�lise; 3=Rejeitado
	Prioridade	-	1=Baixa; 2=Alta; 3=Urgente	
	Gerente de Projetos respons�vel	-	string

*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define	MAX	200

//variaveis globais
int	option, cont=0, temp, fechar=1;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Registro (descri��o dos elementos no cabe�alho do algor�tmo)
struct	reg_projeto
{
	int		codigo;
	char	titulo[50];
	char	descr[150];
	int		ano;
	int		status;
	int		prazo;
	int		financ;
	int		prior;
	char	gerproj[30];
};
struct	reg_projeto	projeto[MAX];
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Menu Principal
void menu(){
	printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
	printf("\t\t\t\tMenu Principal\n\n");
	printf("\t\t\t\t[1] - Cadastrar Novo Projeto\n\t\t\t\t[2] - Imprimir Relat�rio de Projetos\n\t\t\t\t[0] - Sair\n");
	printf("\n\n\t\t\t\t\t\t=> ");	
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Fun��o de Cadastro de Projeto
int cadastro(){
	int exit=1, ex=0, i;
	system("cls");
	while(exit!=0 && cont<MAX){
		printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
		printf("\n\t\t\t\t\tCadastrando Novo Projeto.\n\n");
		projeto[cont].codigo = cont + 1;
		printf("\t\t\t\t\tPasso 1 de 8");
		printf("\n\n\n\t\t\t\tC�digo: %d", projeto[cont].codigo);
		printf("\n\n\t\t\t\tT�tulo do Projeto: ");
		fflush(stdin);
		gets(projeto[cont].titulo);
		system("cls");
		printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
		printf("\n\t\t\t\t\tCadastrando Novo Projeto.\n\n");
		printf("\t\t\t\t\tPasso 2 de 8");
		printf("\n\n\n\t\t\t\tC�digo: %d", projeto[cont].codigo);
		printf("\n\n\t\t\t\tDescri��o: ");
		fflush(stdin);
		gets(projeto[cont].descr);
		system("cls");
		printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
		printf("\n\t\t\t\t\tCadastrando Novo Projeto.\n\n");
		printf("\t\t\t\t\tPasso 3 de 8");
		printf("\n\n\n\t\t\t\tC�digo: %d", projeto[cont].codigo);
		printf("\n\n\t\t\t\tAno: ");
		fflush(stdin);
		scanf("%d", &projeto[cont].ano);
		do{
			system("cls");
			printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
			printf("\n\t\t\t\t\tCadastrando Novo Projeto.\n\n");
			printf("\t\t\t\t\tPasso 4 de 8");
			printf("\n\n\n\t\t\t\tC�digo: %d", projeto[cont].codigo);
			printf("\n\n\t\t\t\tStatus\n\n\t\t\t\t[1] - A Fazer\n\t\t\t\t[2] - Fazendo\n\t\t\t\t[3] - Conclu�do\n\n\t\t\t\t=>");
			fflush(stdin);
			scanf("%d", &temp);
			if(temp==1 || temp==2 || temp==3){
				projeto[cont].status = temp;
				ex = 1;
			}
			else{
				printf("\n\n\t\t\t\t**Valor inv�lido. Insira novamente.\n");
				getch();
			}
		}while(ex==0);
		do{
			ex = 0;
			system("cls");
			printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
			printf("\n\t\t\t\t\tCadastrando Novo Projeto.\n\n");
			printf("\t\t\t\t\tPasso 5 de 8");
			printf("\n\n\n\t\t\t\tC�digo: %d", projeto[cont].codigo);
			printf("\n\n\t\t\t\tPrazo\n\n\t\t\t\t[1] - Com Prazo\n\t\t\t\t[2] - Sem Prazo\n\n\t\t\t\t=>");
			fflush(stdin);
			scanf("%d", &temp);
			if(temp==1 || temp==2){
				if(temp==1){
					printf("\n\t\t\t\tInsira o prazo do projeto[semanas]: ");
					scanf("%d", &projeto[cont].prazo);
					ex = 1;
				}
				else{
					projeto[cont].prazo=0;
					ex = 1;
				}	
			}
			else{
				printf("\n\n\t\t\t\t**Valor inv�lido. Insira novamente.\n");
				getch();
			}
		}while(ex==0);
		do{
			ex = 0;
			system("cls");
			printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
			printf("\n\t\t\t\t\tCadastrando Novo Projeto.\n\n");
			printf("\t\t\t\t\tPasso 6 de 8");
			printf("\n\n\n\t\t\t\tC�digo: %d", projeto[cont].codigo);
			printf("\n\n\t\t\t\tFinanciamento\n\n\t\t\t\t[1] - APROVADO\n\t\t\t\t[2] - EM AN�LISE\n\t\t\t\t[3] - REJEITADO\n\n\t\t\t\t=>");
			fflush(stdin);
			scanf("%d", &temp);
			if(temp==1 || temp==2 || temp==3){
				projeto[cont].financ = temp;
				ex = 1;
			}
			else{
				printf("\n\n\t\t\t\t**Valor inv�lido. Insira novamente.\n");
				getch();
			}
		}while(ex==0);
		do{
			ex = 0;
			system("cls");
			printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
			printf("\n\t\t\t\t\tCadastrando Novo Projeto.\n\n");
			printf("\t\t\t\t\tPasso 7 de 8");
			printf("\n\n\n\t\t\t\tC�digo: %d", projeto[cont].codigo);
			printf("\n\n\t\t\t\tPrioridade\n\n\t\t\t\t[1] - Baixa\n\t\t\t\t[2] - Alta\n\t\t\t\t[3] - URGENTE\n\n\t\t\t\t=>");
			fflush(stdin);
			scanf("%d", &temp);
			if(temp==1 || temp==2 || temp==3){
				projeto[cont].prior = temp;
				ex = 1;
			}
			else{
				printf("\n\n\t\t\t\t**Valor inv�lido. Insira novamente.\n");
				getch();
			}
		}while(ex==0);
		system("cls");
		printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
		printf("\n\t\t\t\t\tCadastrando Novo Projeto.\n\n");
		printf("\t\t\t\t\tPasso 8 de 8");
		printf("\n\n\n\t\t\t\tC�digo: %d", projeto[cont].codigo);
		printf("\n\n\t\t\t\tGerente de Projeto: ");
		fflush(stdin);
		gets(projeto[cont].gerproj);
		cont++;
		system("cls");
		printf("\n\n\n\t\t\t\t\tCadastro efetuado com sucesso!");
		printf("\n\n\t\t\t\t\tDeseja cadastrar novo projeto?\n\n\t\t\t\t\t[1] - Sim\n\t\t\t\t\t[2] - N�o\n\n\t\t\t\t\t=>");
		fflush(stdin);
		scanf("%d", &option);
		if(option==1){
			cadastro();
			return 0;
		}
		else{
			exit=0;
		}		
	}
	system("cls");
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Menu de Impress�o Principal
void menuimprimir(){
	system("cls");
	printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
	printf("\t\t\t\tMenu de Relat�rios\n\n");
	printf("\t\t\t\t[1] - Imprimir todos\n\t\t\t\t[2] - Menu Op��es de Relat�rio: Status\n\t\t\t\t[3] - Menu Op��es de Relat�rio: Financiamento\n");
	printf("\t\t\t\t[4] - Menu Op��es de Relat�rio: Prioridade\n\t\t\t\t[0] - Voltar ao menu principal\n");
	printf("\n\n\t\t\t\t\t\t=> ");
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Menu de Impress�o Status
void menuimpstatus(){
	system("cls");
	printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
	printf("\t\t\t\tMenu de Relat�rios - Status\n\n");
	printf("\t\t\t\t[1] - Imprimir Projetos com Status: A Fazer\n\t\t\t\t[2] - Imprimir Projetos com Status: Fazendo\n\t\t\t\t[3] - Imprimir Projetos com Status: Conclu�do\n");
	printf("\t\t\t\t[0] - Voltar ao menu anterior\n");
	printf("\n\n\t\t\t\t\t\t=> ");
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Menu de Impress�o Financiamento
void menuimpfinanc(){
	system("cls");
	printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
	printf("\t\t\t\tMenu de Relat�rios - Financiamento\n\n");
	printf("\t\t\t\t[1] - Imprimir Projetos com Financiamento: APROVADO\n\t\t\t\t[2] - Imprimir Projetos com Financiamento: EM AN�LISE\n");
	printf("\t\t\t\t[3] - Imprimir Projetos com Financiamento: REJEITADO\n\t\t\t\t[0] - Voltar ao menu anterior\n");
	printf("\n\n\t\t\t\t\t\t=> ");
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Menu de Impress�o Prioridade
void menuimpprior(){
	system("cls");
	printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
	printf("\t\t\t\tMenu de Relat�rios - Prioridade\n\n");
	printf("\t\t\t\t[1] - Imprimir Projetos com Prioridade: BAIXA\n\t\t\t\t[2] - Imprimir Projetos com Prioridade: ALTA\n");
	printf("\t\t\t\t[3] - Imprimir Projetos com Prioridade: URGENTE\n\t\t\t\t[0] - Voltar ao menu anterior\n");
	printf("\n\n\t\t\t\t\t\t=> ");
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Blueprint das impress�es
void funcimprimir(int i){
		printf("\t\t\t\tC�digo: %d\n\t\t\t\tT�tulo: %s\n\t\t\t\tDescri��o: %s\n\t\t\t\tAno: %d\n", projeto[i].codigo, projeto[i].titulo, projeto[i].descr, projeto[i].ano);
		if(projeto[i].status==1){
			printf("\t\t\t\tStatus: A Fazer\n");
		}
		else if(projeto[i].status==2){
			printf("\t\t\t\tStatus: Fazendo\n");
		}
			else{
				printf("\t\t\t\tStatus: Conclu�do\n");
			}
		if(projeto[i].prazo==0){
			printf("\t\t\t\tPrazo: Sem Prazo\n");
		}
		else{
			printf("\t\t\t\tPrazo: %d semana(s)\n", projeto[i].prazo);
		}
		if(projeto[i].financ==1){
			printf("\t\t\t\tFinanciamento: APROVADO\n");
		}
		else if(projeto[i].financ==2){
			printf("\t\t\t\tFinanciamento: EM AN�LISE\n");
		}
			else{
				printf("\t\t\t\tFinanciamento: REJEITADO\n");
			}
		if(projeto[i].prior==1){
			printf("\t\t\t\tPrioridade: Baixa\n");
		}
		else if(projeto[i].prior==2){
			printf("\t\t\t\tPrioridade: Alta\n");
		}
			else{
				printf("\t\t\t\tPrioridade: URGENTE\n");
			}
		printf("\t\t\t\tGerente de Projeto: %s", projeto[i].gerproj);
		printf("\n\n\n");
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Fun��o de Impress�o por 'Status'
void impstatus(){
	int i;
	switch(option){
		case 1:{//a fazer
			for(i=0;i<cont;i++){
				if(projeto[i].status == 1){
					funcimprimir(i);
				}
			}
			break;
		}
		case 2:{//fazendo
			for(i=0;i<cont;i++){
				if(projeto[i].status == 2){
					funcimprimir(i);
				}
			}
			break;
		}
		case 3:{
			for(i=0;i<cont;i++){
				if(projeto[i].status == 3){
					funcimprimir(i);
				}
			}
			break;
		}
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Fun��o de Impress�o por 'Finaciamento'
void impfinanc(){
	int i;
	switch(option){
		case 1:{//a fazer
			for(i=0;i<cont;i++){
				if(projeto[i].financ == 1){
					funcimprimir(i);
				}
			}
			break;
		}
		case 2:{//fazendo
			for(i=0;i<cont;i++){
				if(projeto[i].financ == 2){
					funcimprimir(i);
				}
			}
			break;
		}
		case 3:{
			for(i=0;i<cont;i++){
				if(projeto[i].financ == 3){
					funcimprimir(i);
				}
			}
			break;
		}
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Fun��o de Impress�o por 'Prioridade'
void impprior(){
	int i;
	switch(option){
		case 1:{//a fazer
			for(i=0;i<cont;i++){
				if(projeto[i].prior == 1){
					funcimprimir(i);
				}
			}
			break;
		}
		case 2:{//fazendo
			for(i=0;i<cont;i++){
				if(projeto[i].prior == 2){
					funcimprimir(i);
				}
			}
			break;
		}
		case 3:{
			for(i=0;i<cont;i++){
				if(projeto[i].prior == 3){
					funcimprimir(i);
				}
			}
			break;
		}
	}
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Fun��o de impress�o
int imprimir(){
	int i=0;
	
	if(fechar==0){
		return 0;
	}
	do{
		menuimprimir();
		scanf("%d", &option);
		if(option!=1 && option!=2 && option!=3 && option!=4 && option!=0){
			printf("\n\t\t\t\tOp��o inv�lida. Insira valor v�lido.");
			getch();
			system("cls");
		}
	}while(option!=1 && option!=2 && option!=3 && option!=4 && option!=0);
	system("cls");
	printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
	printf("\t\t\t\t\t\tRelat�rio\n\n");
	switch(option){
		case 1:{//imprimir todos
			for(i=0;i<cont;i++){
				funcimprimir(i);
			}
			printf("\n\n\n\n\t\t\t\tTodos os relat�rios foram impressos com sucesso.\n\t\t\t\tPressione qualquer tecla para voltar.");
			getch();
			imprimir();
			return 0;
			break;
		}
		case 2:{//menu de impress�o status
			do{
				menuimpstatus();
				scanf("%d", &option);
				if(option!=1 && option!=2 && option!=3 && option!=0){
					printf("\n\t\t\t\tOp��o inv�lida. Insira valor v�lido.");
					getch();
					system("cls");
				}
			}while(option!=1 && option!=2 && option!=3 && option!=0);
			system("cls");
			printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
			printf("\t\t\t\t\t\tRelat�rio - Status\n\n");
			switch(option){
				case 1:{
					system("cls");
					printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
					printf("\t\t\t\tRelat�rio - Status 'A Fazer'\n\n");
					impstatus();
					printf("\n\n\n\n\t\t\t\tTodos os relat�rios foram impressos com sucesso.\n\t\t\t\tPressione qualquer tecla para voltar.");
					getch();
					imprimir();
					return 0;
					break;
				}
				case 2:{
					system("cls");
					printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
					printf("\t\t\t\tRelat�rio - Status 'Fazendo'\n\n");
					impstatus();
					printf("\n\n\n\n\t\t\t\tTodos os relat�rios foram impressos com sucesso.\n\t\t\t\tPressione qualquer tecla para voltar.");
					getch();
					imprimir();
					return 0;
					break;
				}
				case 3:{
					system("cls");
					printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
					printf("\t\t\t\tRelat�rio - Status 'Conclu�do'\n\n");
					impstatus();
					printf("\n\n\n\n\t\t\t\tTodos os relat�rios foram impressos com sucesso.\n\t\t\t\tPressione qualquer tecla para voltar.");
					getch();
					imprimir();
					return 0;
					break;
				}
				default:{
					if(option!=0){
						printf("Op��o inv�lida.");
						system("cls");
						imprimir();
					}
					else{
						imprimir();
					}
					break;
				}
			}
			break;
		}
		imprimir();
		return 0;
		case 3:{//menu de impressao financiamento
			do{
				menuimpfinanc();
				scanf("%d", &option);
				if(option!=1 && option!=2 && option!=3 && option!=0){
					printf("\n\t\t\t\tOp��o inv�lida. Insira valor v�lido.");
					getch();
					system("cls");
				}
			}while(option!=1 && option!=2 && option!=3 && option!=0);
			system("cls");
			printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
			printf("\t\t\t\t\t\tRelat�rio - Financiamento\n\n");
			switch(option){
				case 1:{
					system("cls");
					printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
					printf("\t\t\t\tRelat�rio - Financiamento 'APROVADO'\n\n");
					impfinanc();
					printf("\n\n\n\n\t\t\t\tTodos os relat�rios foram impressos com sucesso.\n\t\t\t\tPressione qualquer tecla para voltar.");
					getch();
					imprimir();
					return 0;
					break;
				}
				case 2:{
					system("cls");
					printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
					printf("\t\t\t\tRelat�rio - Financiamento 'EM AN�LISE'\n\n");
					impfinanc();
					printf("\n\n\n\n\t\t\t\tTodos os relat�rios foram impressos com sucesso.\n\t\t\t\tPressione qualquer tecla para voltar.");
					getch();
					imprimir();
					return 0;
					break;
				}
				case 3:{
					system("cls");
					printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
					printf("\t\t\t\tRelat�rio - Financiamento 'REJEITADO'\n\n");
					impfinanc();
					printf("\n\n\n\n\t\t\t\tTodos os relat�rios foram impressos com sucesso.\n\t\t\t\tPressione qualquer tecla para voltar.");
					getch();
					imprimir();
					return 0;
					break;
				}
				default:{
					if(option!=0){
						printf("Op��o inv�lida.");
						system("cls");
						imprimir();
					}
					else{
						imprimir();
					}
					break;
				}
			}
			break;
		}
		imprimir();
		return 0;
		case 4:{//menu de impressao prioridade
			do{
				menuimpprior();
				scanf("%d", &option);
				if(option!=1 && option!=2 && option!=3 && option!=0){
					printf("\n\t\t\t\tOp��o inv�lida. Insira valor v�lido.");
					getch();
					system("cls");
				}
			}while(option!=1 && option!=2 && option!=3 && option!=0);
			system("cls");
			printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
			printf("\t\t\t\t\t\tRelat�rio - Prioridade\n\n");
			switch(option){
				case 1:{
					system("cls");
					printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
					printf("\t\t\t\tRelat�rio - Prioridade 'Baixa'\n\n");
					impprior();
					printf("\n\n\n\n\t\t\t\tTodos os relat�rios foram impressos com sucesso.\n\t\t\t\tPressione qualquer tecla para voltar.");
					getch();
					imprimir();
					return 0;
					break;
				}
				case 2:{
					system("cls");
					printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
					printf("\t\t\t\tRelat�rio - Prioridade 'Alta'\n\n");
					impprior();
					printf("\n\n\n\n\t\t\t\tTodos os relat�rios foram impressos com sucesso.\n\t\t\t\tPressione qualquer tecla para voltar.");
					getch();
					imprimir();
					return 0;
					break;
				}
				case 3:{
					system("cls");
					printf("\n\t\t\t\tAlgor�timo de Cadastro e Relat�rio de Projetos\n\n");
					printf("\t\t\t\tRelat�rio - Prioridade 'URGENTE'\n\n");
					impprior();
					printf("\n\n\n\n\t\t\t\tTodos os relat�rios foram impressos com sucesso.\n\t\t\t\tPressione qualquer tecla para voltar.");
					getch();
					imprimir();
					return 0;
					break;
				}
				default:{
					if(option!=0){
						printf("Op��o inv�lida.");
						system("cls");
						imprimir();
					}
					else{
						imprimir();
					}
					break;
				}
			}
			break;
		}
		imprimir();
		return 0;
		default:{
			main();
			break;
		}
	}
	system("cls");
	return 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Main
int	main(){
	int	exit=1;
	setlocale(LC_ALL,"Portuguese_Brazil");
	system("cls");
	if(fechar==0){
		return 0;
	}
	menu();
	do{
		do{
		scanf("%d", &option);
		switch(option){
			case 1:{
				cadastro();
				system("cls");
				menu();
				break;
			}
			case 2:{
				imprimir();
				system("cls");
				menu();
				break;
			}
			case 0:{
				printf("\n\n\t\t\t\tDeseja sair? - Todos os dados ser�o deletados.");
				printf("\n\t\t\t\t[1] - Sair\n\t\t\t\t[0] - Cancelar\n\n\t\t\t\t\t\t=>");
				scanf("%d", &option);
				if(option==1){
					fechar=0;
					return 0;
				}
				else{
					main();
				}
				break;
			}
			default:{
				printf("\n\n\t\t\t\tOp��o inv�lida. Insira valor v�lido.");
				getch();
				system("cls");
				menu();
				break;
				}
			}
		}while((option!=1 && option!=2 && option!=0) || exit!=0);
	}while(fechar!=0);
	return 0;	
}
