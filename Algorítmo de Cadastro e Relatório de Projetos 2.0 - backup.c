/*
	Algorítmo elaborado por:
	
	Nome:	Rafael Cossich Navarro dos Santos
	R.A:	2114.00.87-5

	
	Atividade Mapa - ALPII
	
////////////////////////////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\////////////////////////////////////////////////////////////

	Descrições do registro:
	
	Código	-	inteiro
	Titulo	-	string
	Descrição	- string
	Ano	-	inteiro
	Status	- 1=A fazer; 2=Fazendo; 3=Concluído
	Prazo	-	1=Com prazo: inteiro; 2=Sem prazo
	Financiamento	-	1=Aprovado; 2=Em análise; 3=Rejeitado
	Prioridade	-	1=Baixa; 2=Alta; 3=Urgente	
	Gerente de Projetos responsável	-	string

*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define	MAX	200

//variaveis globais
int	option, cont=0, temp, fechar=1;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Registro (descrição dos elementos no cabeçalho do algorítmo)
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
	printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
	printf("\t\t\t\tMenu Principal\n\n");
	printf("\t\t\t\t[1] - Cadastrar Novo Projeto\n\t\t\t\t[2] - Imprimir Relatório de Projetos\n\t\t\t\t[0] - Sair\n");
	printf("\n\n\t\t\t\t\t\t=> ");	
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Função de Cadastro de Projeto
int cadastro(){
	int exit=1, ex=0, i;
	system("cls");
	while(exit!=0 && cont<MAX){
		printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
		printf("\n\t\t\t\t\tCadastrando Novo Projeto.\n\n");
		projeto[cont].codigo = cont + 1;
		printf("\t\t\t\t\tPasso 1 de 8");
		printf("\n\n\n\t\t\t\tCódigo: %d", projeto[cont].codigo);
		printf("\n\n\t\t\t\tTítulo do Projeto: ");
		fflush(stdin);
		gets(projeto[cont].titulo);
		system("cls");
		printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
		printf("\n\t\t\t\t\tCadastrando Novo Projeto.\n\n");
		printf("\t\t\t\t\tPasso 2 de 8");
		printf("\n\n\n\t\t\t\tCódigo: %d", projeto[cont].codigo);
		printf("\n\n\t\t\t\tDescrição: ");
		fflush(stdin);
		gets(projeto[cont].descr);
		system("cls");
		printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
		printf("\n\t\t\t\t\tCadastrando Novo Projeto.\n\n");
		printf("\t\t\t\t\tPasso 3 de 8");
		printf("\n\n\n\t\t\t\tCódigo: %d", projeto[cont].codigo);
		printf("\n\n\t\t\t\tAno: ");
		fflush(stdin);
		scanf("%d", &projeto[cont].ano);
		do{
			system("cls");
			printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
			printf("\n\t\t\t\t\tCadastrando Novo Projeto.\n\n");
			printf("\t\t\t\t\tPasso 4 de 8");
			printf("\n\n\n\t\t\t\tCódigo: %d", projeto[cont].codigo);
			printf("\n\n\t\t\t\tStatus\n\n\t\t\t\t[1] - A Fazer\n\t\t\t\t[2] - Fazendo\n\t\t\t\t[3] - Concluído\n\n\t\t\t\t=>");
			fflush(stdin);
			scanf("%d", &temp);
			if(temp==1 || temp==2 || temp==3){
				projeto[cont].status = temp;
				ex = 1;
			}
			else{
				printf("\n\n\t\t\t\t**Valor inválido. Insira novamente.\n");
				getch();
			}
		}while(ex==0);
		do{
			ex = 0;
			system("cls");
			printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
			printf("\n\t\t\t\t\tCadastrando Novo Projeto.\n\n");
			printf("\t\t\t\t\tPasso 5 de 8");
			printf("\n\n\n\t\t\t\tCódigo: %d", projeto[cont].codigo);
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
				printf("\n\n\t\t\t\t**Valor inválido. Insira novamente.\n");
				getch();
			}
		}while(ex==0);
		do{
			ex = 0;
			system("cls");
			printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
			printf("\n\t\t\t\t\tCadastrando Novo Projeto.\n\n");
			printf("\t\t\t\t\tPasso 6 de 8");
			printf("\n\n\n\t\t\t\tCódigo: %d", projeto[cont].codigo);
			printf("\n\n\t\t\t\tFinanciamento\n\n\t\t\t\t[1] - APROVADO\n\t\t\t\t[2] - EM ANÁLISE\n\t\t\t\t[3] - REJEITADO\n\n\t\t\t\t=>");
			fflush(stdin);
			scanf("%d", &temp);
			if(temp==1 || temp==2 || temp==3){
				projeto[cont].financ = temp;
				ex = 1;
			}
			else{
				printf("\n\n\t\t\t\t**Valor inválido. Insira novamente.\n");
				getch();
			}
		}while(ex==0);
		do{
			ex = 0;
			system("cls");
			printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
			printf("\n\t\t\t\t\tCadastrando Novo Projeto.\n\n");
			printf("\t\t\t\t\tPasso 7 de 8");
			printf("\n\n\n\t\t\t\tCódigo: %d", projeto[cont].codigo);
			printf("\n\n\t\t\t\tPrioridade\n\n\t\t\t\t[1] - Baixa\n\t\t\t\t[2] - Alta\n\t\t\t\t[3] - URGENTE\n\n\t\t\t\t=>");
			fflush(stdin);
			scanf("%d", &temp);
			if(temp==1 || temp==2 || temp==3){
				projeto[cont].prior = temp;
				ex = 1;
			}
			else{
				printf("\n\n\t\t\t\t**Valor inválido. Insira novamente.\n");
				getch();
			}
		}while(ex==0);
		system("cls");
		printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
		printf("\n\t\t\t\t\tCadastrando Novo Projeto.\n\n");
		printf("\t\t\t\t\tPasso 8 de 8");
		printf("\n\n\n\t\t\t\tCódigo: %d", projeto[cont].codigo);
		printf("\n\n\t\t\t\tGerente de Projeto: ");
		fflush(stdin);
		gets(projeto[cont].gerproj);
		cont++;
		system("cls");
		printf("\n\n\n\t\t\t\t\tCadastro efetuado com sucesso!");
		printf("\n\n\t\t\t\t\tDeseja cadastrar novo projeto?\n\n\t\t\t\t\t[1] - Sim\n\t\t\t\t\t[2] - Não\n\n\t\t\t\t\t=>");
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
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Menu de Impressão Principal
void menuimprimir(){
	system("cls");
	printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
	printf("\t\t\t\tMenu de Relatórios\n\n");
	printf("\t\t\t\t[1] - Imprimir todos\n\t\t\t\t[2] - Menu Opções de Relatório: Status\n\t\t\t\t[3] - Menu Opções de Relatório: Financiamento\n");
	printf("\t\t\t\t[4] - Menu Opções de Relatório: Prioridade\n\t\t\t\t[0] - Voltar ao menu principal\n");
	printf("\n\n\t\t\t\t\t\t=> ");
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Menu de Impressão Status
void menuimpstatus(){
	system("cls");
	printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
	printf("\t\t\t\tMenu de Relatórios - Status\n\n");
	printf("\t\t\t\t[1] - Imprimir Projetos com Status: A Fazer\n\t\t\t\t[2] - Imprimir Projetos com Status: Fazendo\n\t\t\t\t[3] - Imprimir Projetos com Status: Concluído\n");
	printf("\t\t\t\t[0] - Voltar ao menu anterior\n");
	printf("\n\n\t\t\t\t\t\t=> ");
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Menu de Impressão Financiamento
void menuimpfinanc(){
	system("cls");
	printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
	printf("\t\t\t\tMenu de Relatórios - Financiamento\n\n");
	printf("\t\t\t\t[1] - Imprimir Projetos com Financiamento: APROVADO\n\t\t\t\t[2] - Imprimir Projetos com Financiamento: EM ANÁLISE\n");
	printf("\t\t\t\t[3] - Imprimir Projetos com Financiamento: REJEITADO\n\t\t\t\t[0] - Voltar ao menu anterior\n");
	printf("\n\n\t\t\t\t\t\t=> ");
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Menu de Impressão Prioridade
void menuimpprior(){
	system("cls");
	printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
	printf("\t\t\t\tMenu de Relatórios - Prioridade\n\n");
	printf("\t\t\t\t[1] - Imprimir Projetos com Prioridade: BAIXA\n\t\t\t\t[2] - Imprimir Projetos com Prioridade: ALTA\n");
	printf("\t\t\t\t[3] - Imprimir Projetos com Prioridade: URGENTE\n\t\t\t\t[0] - Voltar ao menu anterior\n");
	printf("\n\n\t\t\t\t\t\t=> ");
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Blueprint das impressões
void funcimprimir(int i){
		printf("\t\t\t\tCódigo: %d\n\t\t\t\tTítulo: %s\n\t\t\t\tDescrição: %s\n\t\t\t\tAno: %d\n", projeto[i].codigo, projeto[i].titulo, projeto[i].descr, projeto[i].ano);
		if(projeto[i].status==1){
			printf("\t\t\t\tStatus: A Fazer\n");
		}
		else if(projeto[i].status==2){
			printf("\t\t\t\tStatus: Fazendo\n");
		}
			else{
				printf("\t\t\t\tStatus: Concluído\n");
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
			printf("\t\t\t\tFinanciamento: EM ANÁLISE\n");
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
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Função de Impressão por 'Status'
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
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Função de Impressão por 'Finaciamento'
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
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Função de Impressão por 'Prioridade'
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
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Função de impressão
int imprimir(){
	int i=0;
	
	if(fechar==0){
		return 0;
	}
	do{
		menuimprimir();
		scanf("%d", &option);
		if(option!=1 && option!=2 && option!=3 && option!=4 && option!=0){
			printf("\n\t\t\t\tOpção inválida. Insira valor válido.");
			getch();
			system("cls");
		}
	}while(option!=1 && option!=2 && option!=3 && option!=4 && option!=0);
	system("cls");
	printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
	printf("\t\t\t\t\t\tRelatório\n\n");
	switch(option){
		case 1:{//imprimir todos
			for(i=0;i<cont;i++){
				funcimprimir(i);
			}
			printf("\n\n\n\n\t\t\t\tTodos os relatórios foram impressos com sucesso.\n\t\t\t\tPressione qualquer tecla para voltar.");
			getch();
			imprimir();
			return 0;
			break;
		}
		case 2:{//menu de impressão status
			do{
				menuimpstatus();
				scanf("%d", &option);
				if(option!=1 && option!=2 && option!=3 && option!=0){
					printf("\n\t\t\t\tOpção inválida. Insira valor válido.");
					getch();
					system("cls");
				}
			}while(option!=1 && option!=2 && option!=3 && option!=0);
			system("cls");
			printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
			printf("\t\t\t\t\t\tRelatório - Status\n\n");
			switch(option){
				case 1:{
					system("cls");
					printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
					printf("\t\t\t\tRelatório - Status 'A Fazer'\n\n");
					impstatus();
					printf("\n\n\n\n\t\t\t\tTodos os relatórios foram impressos com sucesso.\n\t\t\t\tPressione qualquer tecla para voltar.");
					getch();
					imprimir();
					return 0;
					break;
				}
				case 2:{
					system("cls");
					printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
					printf("\t\t\t\tRelatório - Status 'Fazendo'\n\n");
					impstatus();
					printf("\n\n\n\n\t\t\t\tTodos os relatórios foram impressos com sucesso.\n\t\t\t\tPressione qualquer tecla para voltar.");
					getch();
					imprimir();
					return 0;
					break;
				}
				case 3:{
					system("cls");
					printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
					printf("\t\t\t\tRelatório - Status 'Concluído'\n\n");
					impstatus();
					printf("\n\n\n\n\t\t\t\tTodos os relatórios foram impressos com sucesso.\n\t\t\t\tPressione qualquer tecla para voltar.");
					getch();
					imprimir();
					return 0;
					break;
				}
				default:{
					if(option!=0){
						printf("Opção inválida.");
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
					printf("\n\t\t\t\tOpção inválida. Insira valor válido.");
					getch();
					system("cls");
				}
			}while(option!=1 && option!=2 && option!=3 && option!=0);
			system("cls");
			printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
			printf("\t\t\t\t\t\tRelatório - Financiamento\n\n");
			switch(option){
				case 1:{
					system("cls");
					printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
					printf("\t\t\t\tRelatório - Financiamento 'APROVADO'\n\n");
					impfinanc();
					printf("\n\n\n\n\t\t\t\tTodos os relatórios foram impressos com sucesso.\n\t\t\t\tPressione qualquer tecla para voltar.");
					getch();
					imprimir();
					return 0;
					break;
				}
				case 2:{
					system("cls");
					printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
					printf("\t\t\t\tRelatório - Financiamento 'EM ANÁLISE'\n\n");
					impfinanc();
					printf("\n\n\n\n\t\t\t\tTodos os relatórios foram impressos com sucesso.\n\t\t\t\tPressione qualquer tecla para voltar.");
					getch();
					imprimir();
					return 0;
					break;
				}
				case 3:{
					system("cls");
					printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
					printf("\t\t\t\tRelatório - Financiamento 'REJEITADO'\n\n");
					impfinanc();
					printf("\n\n\n\n\t\t\t\tTodos os relatórios foram impressos com sucesso.\n\t\t\t\tPressione qualquer tecla para voltar.");
					getch();
					imprimir();
					return 0;
					break;
				}
				default:{
					if(option!=0){
						printf("Opção inválida.");
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
					printf("\n\t\t\t\tOpção inválida. Insira valor válido.");
					getch();
					system("cls");
				}
			}while(option!=1 && option!=2 && option!=3 && option!=0);
			system("cls");
			printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
			printf("\t\t\t\t\t\tRelatório - Prioridade\n\n");
			switch(option){
				case 1:{
					system("cls");
					printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
					printf("\t\t\t\tRelatório - Prioridade 'Baixa'\n\n");
					impprior();
					printf("\n\n\n\n\t\t\t\tTodos os relatórios foram impressos com sucesso.\n\t\t\t\tPressione qualquer tecla para voltar.");
					getch();
					imprimir();
					return 0;
					break;
				}
				case 2:{
					system("cls");
					printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
					printf("\t\t\t\tRelatório - Prioridade 'Alta'\n\n");
					impprior();
					printf("\n\n\n\n\t\t\t\tTodos os relatórios foram impressos com sucesso.\n\t\t\t\tPressione qualquer tecla para voltar.");
					getch();
					imprimir();
					return 0;
					break;
				}
				case 3:{
					system("cls");
					printf("\n\t\t\t\tAlgorítimo de Cadastro e Relatório de Projetos\n\n");
					printf("\t\t\t\tRelatório - Prioridade 'URGENTE'\n\n");
					impprior();
					printf("\n\n\n\n\t\t\t\tTodos os relatórios foram impressos com sucesso.\n\t\t\t\tPressione qualquer tecla para voltar.");
					getch();
					imprimir();
					return 0;
					break;
				}
				default:{
					if(option!=0){
						printf("Opção inválida.");
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
				printf("\n\n\t\t\t\tDeseja sair? - Todos os dados serão deletados.");
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
				printf("\n\n\t\t\t\tOpção inválida. Insira valor válido.");
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
