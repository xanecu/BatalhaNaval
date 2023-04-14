#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <time.h>

#define tam 10
#define submarino 2
#define fragata 3
#define porta 5

//Submarino: 2 posições, Fragata: 3 posições, porta: 5 posições

int tabuleiro[tam][tam], tabuleirocpu[tam][tam];
int navio, pos, linha, coluna, pontojogador=0, pontocpu=0, linhaj=NULL, linhacp=NULL, colunaj=NULL, colunacp=NULL, dificuldade, IA, trava=46;

//JOGADA DE JOGADOR E CPU; INCREMENTO DE VALORES APÓS AÇÃO
void jogada(int linha, int coluna,int vez){		//vez==1 - jogador, vez==0 - CPU
	if(vez==1){	//vez do jogador
		if(tabuleirocpu[linha][coluna]==1){
			tabuleirocpu[linha][coluna]=2;
			pontojogador++;
			
		}else if(tabuleirocpu[linha][coluna]==-1 || tabuleirocpu[linha][coluna]==9){
			tabuleirocpu[linha][coluna]=0;
		}
	}
	if(vez==0){	//vez da cpu
		if(tabuleiro[linha][coluna]==1){
			tabuleiro[linha][coluna]=2;
			pontocpu++;
		}else if(tabuleiro[linha][coluna]==-1 || tabuleiro[linha][coluna]==9){
			tabuleiro[linha][coluna]=0;
		}
	}	
}

//void corrigetab(){
//	for(int i=0;i<tam;i++){
//		for(int j=0;j<tam;j++){
//			if(tabuleiro[i][j]== 9){
//				printf(" ~ ");
//				//tabuleiro[i][j]='~';
//			}
//		}
//	}
//}

//1º TABULEIRO IMPRIMIDO PARA COLOCAÇÃO DE BARCOS
char imprimetab(int tab[tam][tam]){
    for(int i=0;i<tam;i++){
        printf("\t");
        for(int j=-1;j<tam;j++){
            if(i==0 && j==-1){
                printf("\t   0  1  2  3  4  5  6  7  8  9 \n\t");
            }
            if(j==-1){
                printf("\t%d ", i);
            }
            else{
            	if(tab[i][j] == -1){
            		printf(" ~ ");
				}
				if(tab[i][j] == 1){
					printf(" # ");
				}
				//if(tab[i][j] == 0){
				//	printf(" O ");
				//}
				//if(tab[i][j] == 2){
				//	printf(" X ");
				//}
				if(tab[i][j] == 9){
					printf(" - ");
				}
			}
        }
        printf("\n");
    }
    //system("pause");
}
void fimdejogo(int vencedor){		//vencedor==1 é o jogador, vencedor==0 é a cpu
	system("cls");
	if(vencedor==1){
		printf("\n\n\t __  __  _____   ____     ____      																\n");
		printf("\t/\\ \\/\\ \\/\\  __`\\/\\  _`\\  /\\  _`\\    														\n");
		printf("\t\\ \\ \\ \\ \\ \\ \\/\\ \\ \\ \\/\\_\\\\ \\ \\L\\_\\  												\n");
		printf("\t \\ \\ \\ \\ \\ \\ \\ \\ \\ \\ \\/_/_\\ \\  _\\L  													\n");
		printf("\t  \\ \\ \\_/ \\ \\ \\_\\ \\ \\ \\L\\ \\\\ \\ \\L\\ \\												\n");
		printf("\t   \\ `\\___/\\ \\_____\\ \\____/ \\ \\____/														\n");
		printf("\t    `\\/__/  \\/_____/\\/___/   \\/___/ 															\n");
		printf("\t                                    																\n");
		printf("\t                                    \n");
		printf("\t __  __  ____    __  __  ____     ____    __  __  __     											\n");
		printf("\t/\\ \\/\\ \\/\\  _`\\ /\\ \\/\\ \\/\\  _`\\  /\\  _`\\ /\\ \\/\\ \\/\\ \\    						\n");
		printf("\t\\ \\ \\ \\ \\ \\ \\L\\_\\ \\ `\\\\ \\ \\ \\/\\_\\\\ \\ \\L\\_\\ \\ \\ \\ \\ \\ \\   				\n");
		printf("\t \\ \\ \\ \\ \\ \\  _\\L\\ \\ , ` \\ \\ \\/_/_\\ \\  _\\L\\ \\ \\ \\ \\ \\ \\  						\n");	
		printf("\t  \\ \\ \\_/ \\ \\ \\L\\ \\ \\ \\`\\ \\ \\ \\L\\ \\\\ \\ \\L\\ \\ \\ \\_\\ \\ \\_\\ 				\n");
		printf("\t   \\ `\\___/\\ \\____/\\ \\_\\ \\_\\ \\____/ \\ \\____/\\ \\_____\\/\\_\\							\n");			
		printf("\t    `\\/__/  \\/___/  \\/_/\\/_/\\/___/   \\/___/  \\/_____/\\/_/									\n");
		
	}
	if(vencedor==0){
		printf("\n\n\t__      ______   _____ ______   _____  ______ _____  _____  ______ _    _ _ 		\n");
		printf("\t\\ \\    / / __ \\ / ____|  ____| |  __ \\|  ____|  __ \\|  __ \\|  ____| |  | | |		\n");
		printf("\t \\ \\  / / |  | | |    | |__    | |__) | |__  | |__) | |  | | |__  | |  | | |			\n");
		printf("\t  \\ \\/ /| |  | | |    |  __|   |  ___/|  __| |  _  /| |  | |  __| | |  | | |			\n");
		printf("\t   \\  / | |__| | |____| |____  | |    | |____| | \\ \\| |__| | |____| |__| |_|			\n");
		printf("\t    \\/   \\____/ \\_____|______| |_|    |______|_|  \\_\\_____/|______|\\____/(_)		\n");
		
	}
	system("pause");
}
void teladejogo(){
	system("cls");
	printf("\t\t_________________________________________  ________ 	\n");
	printf("\t\t___  __ )__    |__  __/__    |__  /___  / / /__    |	\n");
	printf("\t\t__  __  |_  /| |_  /  __  /| |_  / __  /_/ /__  /| |	\n");
	printf("\t\t_  /_/ /_  ___ |  /   _  ___ |  /___  __  / _  ___ |	\n");
	printf("\t\t/_____/ /_/  |_/_/    /_/  |_/_____/_/ /_/  /_/  |_|	\n");
	//printf("\n\t\tO = Tiro na agua   @ = Navio atingido   # - Seu navio\n\n");
	printf("\n\n\tJOGADOR\t\t\tPONTOS: %d\tCPU\t\t\tPONTOS: %d\n", pontojogador, pontocpu);
	printf("\t-------------------------------		-------------------------------\n");
	printf("\t   0  1  2  3  4  5  6  7  8  9 \t   0  1  2  3  4  5  6  7  8  9 \n");
	for(int i=0;i<tam;i++){						//laço para impressão dos tabuleiros lado a lado
        printf("\t");
		for(int j=-1;j<tam;j++){
            if(j==-1){
                printf("%d ", i);
            }
            else{
            	if(tabuleiro[i][j] == -1){
            		printf(" ~ ");
				}
				if(tabuleiro[i][j] == 1){
					printf(" # ");
				}
				if(tabuleiro[i][j] == 0){
					printf(" O ");
				}
				if(tabuleiro[i][j] == 2){
					printf(" X ");
				}
				if(tabuleiro[i][j] == 9){
					printf(" ~ ");
				}
			}      
        }
        printf("\t");
        for(int j=0;j<tam;j++){
            if(j==0){
                printf("%d ", i);
            }
            if(tabuleirocpu[i][j] == -1){
            	printf(" ~ ");
			}
			if(tabuleirocpu[i][j] == 1){
				printf(" ~ ");
			}
			if(tabuleirocpu[i][j] == 0){
				printf(" O ");
			}
			if(tabuleirocpu[i][j] == 2){
				printf(" X ");
			}
			if(tabuleirocpu[i][j] == 9){
				printf(" ~ ");
			}
            //printf(" %c ", tabuleirocpu[i][j]);     //pode alterar para tabuleiro cpu para efetuar testes rápidos
			if(i==1 && j==9){
				printf("   VENCE QUEM ALCANÇAR 27 PONTOS!");
			}
			if(i==3 && j==9){
				printf("     O = Tiro na agua");
			}
			if(i==4 && j==9){
				printf("     X = Navio atingido");
			}
			if(i==5 && j==9){
				printf("     # = Seu navio");
			}       
        }
        
        printf("\n");
    }
    printf("\n");
	printf("\túltimas jogadas\n\tJOGADOR: L-%d C-%d\tCPU: L-%d C-%d\n", linhaj, colunaj, linhacp, colunacp);	
	
}//
void gameplay(){
	int erro=0;
	do{	
		teladejogo();
		do{
			printf("\n\tFaça sua jogada\n\tLinha: ");
			scanf("%d", &linha);
			linhaj=linha;
			printf("\tColuna: ");
			scanf("%d", &coluna);
			colunaj=coluna;
			if(linha>9 || linha<0 || coluna>9 || coluna<0){
				printf("\tPosição não disponível!");
				erro=1;
			}else if(tabuleirocpu[linha][coluna]==0 || tabuleirocpu[linha][coluna]==2){
				printf("\tPosição já atacada!");
				erro=1;
			}else{
				erro=0;
			}
		}while(erro==1);
		jogada(linha, coluna, 1);
		printf("\n\tCPU está jogando...");
		sleep(1);
		//vez CPU
		dificuldade=0;
		do{
			linha=rand()%10;
			linhacp=linha;
			coluna=rand()%10;
			colunacp=coluna;
			if(tabuleiro[linha][coluna]== 1){		//cpu ganha chances extras de acordo com o nível de dificuldade
				break;
			}else if(tabuleiro[linha][coluna]==0 || tabuleiro[linha][coluna]==2){
				dificuldade--;
			}else{
				dificuldade++;
			}
		}while(dificuldade<IA);
		jogada(linha, coluna, 0);
		if(pontojogador==27){
			teladejogo();
			system("\npause");
			break;		
		}else if(pontocpu==27){
			teladejogo();
			system("\npause");
			break;
		}
	}while(1);
	if(pontojogador==27){
		fimdejogo(1);
		
	}else if(pontocpu==27){
		fimdejogo(0);
	}
}//CONTINUAR...
void atribuir(int linha, int coluna, int pos, int navio, int tab[tam][tam]){		//função para atribuir o navio na posição oferecida
	if(pos==0){	//vertical
		for(int i=0;i<navio;i++){
			tab[linha+i][coluna]= 1;
			tab[linha+i][coluna+1]= 9;
			tab[linha+i][coluna-1]= 9;
		}
		tab[linha-1][coluna]= 9;
		tab[linha+navio][coluna]= 9;	
	}
	if(pos==1){ //horizontal
		for(int i=0;i<navio;i++){
			tab[linha][coluna+i]= 1;
			tab[linha+1][coluna+i]= 9;
			tab[linha-1][coluna+i]= 9;
		}
		tab[linha][coluna-1]= 9;
		tab[linha][coluna+navio]= 9;
	}
}//
int liberacao(int linha, int coluna, int pos, int navio, int tab[tam][tam]){		//função para verificar a posição dada
	int liberar=0;
	if(pos==0){
		for(int i=0;i<navio;i++){
			if(tab[linha+i][coluna]== -1 && linha+i<tam){
				liberar=1;
			}
			else{
				liberar=0;
				return liberar;
			}
		}
	}else if(pos==1){
		for(int i=0;i<navio;i++){
			if(tab[linha][coluna+i]== -1 && coluna+i<tam){
				liberar=1;
			}
			else{
				liberar=0;
				return liberar;
			}
		}
	}
	return liberar;
}
void telaselecao(){
    system("cls");
    printf("\n\t\t|Atribuir navios ao tabuleiro|\n\n");
    printf("\t~ : área livre   - : área bloqueada   # : Navio\n");
    printf("Submarino: 2 posições  Fragata: 3 posições  Porta-aviões: 5 posições\n\n");
    imprimetab(tabuleiro);
}
void naviorand(int tab[tam][tam]){												
	srand(time(NULL));
	int submarin=4, fragat=3, port=2, encerrar=0, check=0;
    
    do{   
	    do{                     //rotina para escolha do navio
	        navio=rand()%3+1;
	            if(navio==1 && submarin!=0 || navio==2 && fragat!=0 || navio==3 && port!=0)
	                check=1;
	            else{
	                check=0;
	            }
	    }while(check==0);
        
		if(navio==1){
			do{
				linha=rand()%10;	//número para a linha				
				coluna=rand()%10;	//número para a coluna
		       	pos=rand()%2;		//vertical ou horizontal
			}while(liberacao(linha, coluna, pos, submarino, tab)==0);
			atribuir(linha, coluna, pos, submarino, tab);
			submarin--;		//controle da quantidade de barcos inseridos
			       	
	    }else if(navio==2){			
	       	do{
				linha=rand()%10;					
				coluna=rand()%10;	
		       	pos=rand()%2;		
			}while(liberacao(linha, coluna, pos, fragata, tab)==0);
			atribuir(linha, coluna, pos, fragata, tab);
			fragat--;
			
	    }else if(navio==3){				
	    	do{
				linha=rand()%10;					
				coluna=rand()%10;	
		       	pos=rand()%2;		
			}while(liberacao(linha, coluna, pos, porta, tab)==0);
			atribuir(linha, coluna, pos, porta, tab);
			port--;
        	}
		encerrar++;	
        	//printf("|Navio:%d\tLinha:%d\tColuna:%d\tPos:%d|\n", navio, linha, coluna, pos); //retorno para efetuar os testes após terminar as atribuições  
    }while(encerrar!=9);
}
int atribuirnavios(){
    int navio, submarin=4, fragat=3, port=2, encerrar=0, check=0, ok=0;
    char aleatorio;
    do{
       
        do{                     //rotina para escolha do navio e sua posição
            telaselecao();
            if(encerrar==0){
            	printf("\n\tAtribuir aleatóriamente?(s/n): ");
            	scanf("%c", &aleatorio);
            	if(aleatorio=='s'){
            		naviorand(tabuleiro);
            		return 0;
				}
			}
            printf("\n\n\t1 - Submarino(%d/4)\n\t2 - Fragata(%d/3)\n\t3 - Porta aviões(%d/2)\n", submarin, fragat, port);
            printf("\tNavio: ");
            scanf("%d", &navio);
            if(navio==1 && submarin!=0 || navio==2 && fragat!=0 || navio==3 && port!=0)
                check=1;
            else{
                printf("\n\n\tNavios Excedidos!\n");
                system("pause");
                system("cls");
                check=0;
            }
        }while(check==0);
	    do{ 
			   
			do{
	            printf("\n\tVertical (0) ou horizontal(1)? ");
	            scanf("%d", &pos);
	        }while(pos<0 || pos>1);
	        printf("\tLinha: ");
	        scanf("%d", &linha);
	        printf("\tColuna: ");
	        scanf("%d", &coluna);
	       
	        if(navio==1){
	            if(liberacao(linha, coluna, pos, submarino, tabuleiro)==1){
	            	atribuir(linha, coluna, pos, submarino, tabuleiro);
	            	ok=1;
	            	submarin--;
				}else{
					ok=0;
				}
	        }else if(navio==2){
	            if(liberacao(linha, coluna, pos, fragata, tabuleiro)==1){
	            	atribuir(linha, coluna, pos, fragata, tabuleiro);
	            	ok=1;
	            	fragat--;
				}else{
					ok=0;
				}
	        }else if(navio==3){
	            if(liberacao(linha, coluna, pos, porta, tabuleiro)==1){
	            	atribuir(linha, coluna, pos, porta, tabuleiro);
	            	ok=1;
	            	port--;
				}else{
					ok=0;
				}
	        }
	        if(ok==0){
	        	printf("\n\tPosição escolhida não disponível!\n\tPor favor insira outra posição!\n\n\t");
	        	system("pause");
	        	telaselecao();	        	
			}
		}while(ok==0);
        encerrar++;
    }while(encerrar!=9);
}
void game(){
	 char repete;
     pontojogador=0; pontocpu=0;
	 for(int i=0;i<tam;i++){
        for(int j=0;j<tam;j++){
            tabuleiro[i][j]= -1;
            tabuleirocpu[i][j]= -1;
            tabuleirocpu[i][j]= -1;
        }
    }
    do{	
		printf("\n\n\t\t\tDigite o nível de dificuldade(0 - Fácil à 10 - Dificil): ");
    	scanf("%d", &IA);
    	if(IA==30){
    		break;
		}
    }while(IA<0 || IA>10);
	setbuf(stdin, NULL);
	atribuirnavios();
	naviorand(tabuleirocpu);
	//corrigetab();  
   	gameplay();
   	system("cls");
   	setbuf(stdin, NULL);
   	printf("\n\n\n\t\t\t\tDeseja jogar novamente?(s/n):  ");
   	scanf("%c", &repete);
   	if(repete=='n'){
   		printf("\n\tObrigado por jogar!\n\nSaindo...");
		exit(1);
	}
   	
}
void instrucao(){
    system("cls");
    printf("\t\t     ____        __        ____             _   __                  __\n");
    printf("\t\t    / __ )____ _/ /_____ _/ / /_  ____ _   / | / /___ __   ______ _/ /\n");
    printf("\t\t   / __  / __ `/ __/ __ `/ / __ \\/ __ `/  /  |/ / __ `/ | / / __ `/ / \n");
    printf("\t\t  / /_/ / /_/ / /_/ /_/ / / / / / /_/ /  / /|  / /_/ /| |/ / /_/ / /  \n");
    printf("\t\t /_____/\\__,_/\\__/\\__,_/_/_/ /_/\\__,_/  /_/ |_/\\__,_/ |___/\\__,_/_/   \n\n");
	printf("\t\t\t\t|\tInstruções do jogo\t|\n\n");
    printf("\t  Batalha naval (BattleShip) é um jogo de tabuleiro para dois jogadores, no qual os mesmos \n\ttêm de adivinhar em que posições estão os navios do oponente.");
	printf("\n\n\t  Primeiramente você deve colocar os seus navios no tabuleiro à mostra apresentando as\n\t");
	printf("coordenadas de LINHA e COLUNA, sendo o mesmo preenchido automaticamente com a direção\n\tcorrespondente, HORIZONTAL ou VERTICAL.\n\t");
	printf("\n\tREGRAS PARA COLOCAR NAVIOS:\n\t");
	printf("1 - Não coloque navios em posições lado a lado");
	printf("\n\t2 - Não sobreponha os navios");
	printf("\n\t3 - Não utilize posições inexistentes no tabuleiro");
	printf("\n\n\t  Durante o jogo as legendas auxiliarão o entendimento das características do tabuleiro\n\n\t");
	printf("\n\n\tBÔNUS: digite 30 na dificuldade do jogo e tente vencer no modo impossível!\n\n\t");
}
int main(){
    setlocale(LC_ALL, "portuguese");
    int op;
    do{
    	printf("\t\t     ____        __        ____             _   __                  __\n");
        printf("\t\t    / __ )____ _/ /_____ _/ / /_  ____ _   / | / /___ __   ______ _/ /\n");
        printf("\t\t   / __  / __ `/ __/ __ `/ / __ \\/ __ `/  /  |/ / __ `/ | / / __ `/ / \n");
        printf("\t\t  / /_/ / /_/ / /_/ /_/ / / / / / /_/ /  / /|  / /_/ /| |/ / /_/ / /  \n");
        printf("\t\t /_____/\\__,_/\\__/\\__,_/_/_/ /_/\\__,_/  /_/ |_/\\__,_/ |___/\\__,_/_/   \n\n");
        printf("\t\t\t\t---------------------------------\n");
        printf("\t\t\t\t|\tMENU PRINCIPAL\t\t|\n");
        printf("\t\t\t\t---------------------------------");
        printf("\n\n\t\t\t\t\t1 - Iniciar\n\t\t\t\t\t2 - Instruções\n\t\t\t\t\t3 - Sair\n\n\t\tOpção desejada: ");
        scanf("%d", &op);
        setbuf(stdin, NULL);
        switch(op){
        case 1: game();break;
        case 2: instrucao();break;
        case 3: printf("Saindo...\n");sleep(1) ;exit(0);
        default: printf("\n\tEscolha uma opção válida!\n\n");break;
        }
        system("pause");
        system("cls");
    }while(1);
    return 0;
}
