#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <Lmcons.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

/*
	Caso apare�a o erro C99 no compilador, v� em Ferramentas(Tools) --> 
	Op��es de Compilador...(Compiler Options...) --> No primeiro campo marque a caixa e digite: -std=c99
	Obrigado!
*/

typedef struct {
	int  acertos, erros, pontuacao;
}verificaResposta, contadorFacil, contadorMedio, contadorDificil;

typedef struct {
	char nome[200];
}ModoJogo;

ModoJogo modo_de_jogo[10];
char nome[200];

verificaResposta contadores(verificaResposta todosNiveis, char resposta, char respCorreta, int pontuacao){	
					
	if(resposta == respCorreta){ // ALTERNATIVA CORRETA
	    printf("Resposta correta");
	    todosNiveis.acertos += 1;
	    todosNiveis.pontuacao += pontuacao;
	} else {
	    printf("Resposta errada\n");
	    printf("Resposta correta: Letra '%c'", respCorreta);              
		todosNiveis.erros += 1;
	}
	return todosNiveis;	
}

int main(){
	setlocale(LC_ALL, "portuguese");
	int hora[10], minuto[10], segundo[10], pontuacaoTotal[10], auxHorario = 1, pontuacao;
	char modoJogo[10];
    int opcao;
	do{
	
	    printf("    *------------------------------------------------------*\n");
	    printf("    |                     MENU DE OP��O                    |\n");
	    printf("    *------------------------------------------------------*\n");
	    printf("    |   0 - SAIR DO JOGO                                   |\n");  
	    printf("    |   1 - JOGAR TODOS OS N�VEIS                          |\n");
	    printf("    |   2 - JOGAR N�VEL F�CIL - SOMENTE O N�VEL F�CIL      |\n");
	    printf("    |   3 - JOGAR N�VEL M�DIO - SOMENTE O N�VEL M�DIO      |\n");
	    printf("    |   4 - JOGAR N�VEL DIF�CIL - SOMENTE O N�VEL DIF�CIL  |\n");
	    printf("    |   5 - HIST�RICO DE JOGADAS                           |\n");    
	    printf("    |   6 - VER INSTRU��ES DO JOGO E INFORMA��ES           |\n");
	    printf("    |   7 - VER OS DESENVOLVEDORES                         |\n");
	    printf("    *------------------------------------------------------*\n\n");
	
	    printf("    Digite uma op��o: ");  
	
	    scanf("%d", &opcao);   
	
	    switch(opcao){
	    	
	        case 0:{
				printf("\n	Obrigado por usar nosso programa! :-)\n");
	            break;
	        }
	
	        case 1:{
	            char respostaUsuario;
	            
	            contadorFacil todosNiveisFacil;
	            contadorMedio todosNiveisMedio;
	            contadorDificil todosNiveisDificil;
		
				todosNiveisFacil.acertos =0;
				todosNiveisFacil.erros =0;
				todosNiveisFacil.pontuacao =0;	
				
				todosNiveisMedio.acertos =0;
				todosNiveisMedio.erros =0;		
				todosNiveisMedio.pontuacao =0;		
					
				todosNiveisDificil.acertos =0;
				todosNiveisDificil.erros =0;
				todosNiveisDificil.pontuacao =0;
				
				//--------HORARIO-------//
	            struct tm tempo;
	            time_t tempoSeg;
	
	            time(&tempoSeg);
	            tempo = *localtime(&tempoSeg);
	
	            hora[auxHorario] = tempo.tm_hour;
	            minuto[auxHorario] = tempo.tm_min;
	            segundo[auxHorario] = tempo.tm_sec;
	            //--------HORARIO-------//
	            
	
	            printf("\n	VOC� SELECIONOU - JOGAR TODOS OS N�VEIS\n");
	            
	            //----------- Chamada do nome(usuario do win) -------------//
				char username[UNLEN + 1];
	            DWORD username_len = UNLEN + 1;
	            GetUserName(username, &username_len);
	
	            printf("\n	Ol� %s, seja bem vindo\n\n", username);
	            //----------- Chamada do nome(usuario do win) -------------//
	            
	            printf("    Este � um jogo de perguntas e respostas. O jogador(a) dever� escolher,\ndentre as 4 alternativas apenas uma e em seguida pressionar 'enter'\n\n");
	            printf("    Para mais informa��es, acesse a op��o INSTRU��ES de menu do jogo\n\n\n");
				    
				char tecla;
				    
				printf("PRESSIONE ENTER PARA COMECAR...");
				tecla = getch();
				printf("\n\n");       
				
				if(tecla != 13){
					break;
				}
         
	            printf("*--------------------------------*\n");
	            printf("|  PERGUNTA n. 01 - N�vel F�cil  |\n");
	            printf("*--------------------------------*\n\n");
	
	            printf("Laborat�rio de Automa��o: Qual � a �rea da f�sica que utiliza de gases pressurizados para executar um trabalho?\n\n");
	            printf("A) Hidr�ulica\n");
	            printf("B) Pneum�tica\n");
	            printf("C) El�trica\n");           
	            printf("D) Diodo Zener\n");
	            printf("---------------------------------\n");
	            printf("Resposta? ");
	            scanf(" %c", &respostaUsuario);
	            
				char respostaCorreta = 'B';
			
				todosNiveisFacil = contadores(todosNiveisFacil, respostaUsuario, respostaCorreta, 100);

	            printf("\n---------------------------------\n\n");
	        
	            printf("*--------------------------------*\n");
	            printf("|  PERGUNTA n. 02 - N�vel M�dio  |\n");
	            printf("*--------------------------------*\n\n");
	
	            printf("Redes e Protocolos Industriais: � o tipo de transmiss�o de dados bidirecional.A e B podem transmitir e receber dados ao mesmo tempo:\n");
				printf("Escolha uma op��o:?\n\n");
	
	            printf("A) Simplex\n");
	            printf("B) Half-duplex\n");
	            printf("C) Triplex\n");           
	            printf("D) Full-Duplex\n");
	            
	            printf("---------------------------------\n");
	            printf("Resposta? ");
	            scanf(" %c", &respostaUsuario);
	            
	            respostaCorreta = 'D';
	            
				todosNiveisMedio = contadores(todosNiveisMedio, respostaUsuario, respostaCorreta, 150);

	            printf("\n---------------------------------\n\n");
	
	            printf("*--------------------------------*\n");
	            printf("| PERGUNTA n. 03 - N�vel Dif�cil |\n");
	            printf("*--------------------------------*\n\n");
	
	            printf("Instrumenta��o Industrial: Qual � o sensor mais adequado para medir, por contato direto, temperatura na faixa de 200 �C,apresentando, como caracter�stica, alta linearidade?\n\n");
	
	            printf("A) Termopar\n");
	            printf("B) RTD\n");
	            printf("C) Termistor\n");           
	            printf("D) Semicondutores\n");
	            printf("---------------------------------\n");
	            printf("Resposta? ");
	            scanf(" %c", &respostaUsuario);
	            
	            respostaCorreta = 'B';
	            
				todosNiveisDificil = contadores(todosNiveisDificil, respostaUsuario, respostaCorreta, 200);
				
	            printf("\n---------------------------------\n\n");
	
	            printf("TODOS OS N�VEIS\n\n");
	            printf("Acertos: %d\n", todosNiveisFacil.acertos + todosNiveisMedio.acertos + todosNiveisDificil.acertos);
	            printf("Erros: %d\n", todosNiveisFacil.erros + todosNiveisMedio.erros + todosNiveisDificil.erros);
	            printf("Pontua��o: %d\n\n", todosNiveisFacil.pontuacao + todosNiveisMedio.pontuacao + todosNiveisDificil.pontuacao);
	            printf("_______PARTIDA FINALIZADA_______\n\n");
	            
	            pontuacaoTotal[auxHorario] = (todosNiveisFacil.pontuacao + todosNiveisMedio.pontuacao + todosNiveisDificil.pontuacao);
	            strcpy(modo_de_jogo[auxHorario].nome, "Todos os modos");
	            auxHorario += 1;
	            
	            break;
	        }
	
	        case 2:{
	           	char respostaUsuario;
	            contadorFacil contadorFacil;
		
				contadorFacil.acertos =0;
				contadorFacil.erros =0;
				contadorFacil.pontuacao =0;	
				
				//--------HORARIO-------//
	            struct tm tempo;
	            time_t tempoSeg;
	
	            time(&tempoSeg);
	            tempo = *localtime(&tempoSeg);
	
	            hora[auxHorario] = tempo.tm_hour;
	            minuto[auxHorario] = tempo.tm_min;
	            segundo[auxHorario] = tempo.tm_sec;
	            //--------HORARIO-------//
	            
	            printf("\n	VOC� SELECIONOU - JOGAR N�VEL F�CIL\n");
	            
	            //----------- Chamada do nome(usuario do win) -------------//
				char username[UNLEN + 1];
	            DWORD username_len = UNLEN + 1;
	            GetUserName(username, &username_len);
	
	            printf("\n	Ol� %s, seja bem vindo\n\n", username);
	            //----------- Chamada do nome(usuario do win) -------------//
	            
	            printf("    Este � um jogo de perguntas e respostas. O jogador(a) dever� escolher,\ndentre as 4 alternativas apenas uma e em seguida pressionar 'enter'\n\n");
	            printf("    Para mais informa��es, acesse a op��o INSTRU��ES de menu do jogo\n\n\n");
	
	            char tecla;
				    
				printf("PRESSIONE ENTER PARA COME�AR...");
				tecla = getch();
				printf("\n\n");       
				
				if(tecla != 13){
					break;
				}
				
	            printf("*--------------------------------*\n");
	            printf("|  PERGUNTA n. 01 - N�vel F�cil  |\n");
	            printf("*--------------------------------*\n\n");
	
	            printf("Comandos El�tricos: As siglas NA e NF representam respectivamente:\n\n");
	
	            printf("A) Normalmente Aberta e Normalmente fechada\n");
	            printf("B) Normalmente fechada e Normalmente aberta\n");
	            printf("C) Na botoeira e no fechamento\n");           
	            printf("D) Nota Aberta e Nota Fiscal\n");
	            printf("---------------------------------\n");
	            printf("Resposta? ");
	            scanf(" %c", &respostaUsuario);
	            
				char respostaCorreta = 'A';

				contadorFacil = contadores(contadorFacil, respostaUsuario, respostaCorreta, 100);

	            printf("\n---------------------------------\n\n");
	        
	            printf("*--------------------------------*\n");
	            printf("|  PERGUNTA n. 02 - N�vel F�cil  |\n");
	            printf("*--------------------------------*\n\n");
	
	            printf("Organiza��o Sa�de e Seguran�a: A revolu��o industrial favoreceu o desenvolvimento do __________.\n\n");
	
	            printf("A) Iluminismo\n");
	            printf("B) Capitalismo\n");
	            printf("C) Absolutismo\n");           
	            printf("D) Evolucionismo\n");
	            
	            printf("---------------------------------\n");
	            printf("Resposta? ");
	            scanf(" %c", &respostaUsuario);
	            
	            respostaCorreta = 'B';
	            
				contadorFacil = contadores(contadorFacil, respostaUsuario, respostaCorreta, 100);

	            printf("\n---------------------------------\n\n");
	
	            printf("*--------------------------------*\n");
	            printf("| PERGUNTA n. 03 - N�vel F�cil |\n");
	            printf("*--------------------------------*\n\n");
	
	            printf("Eletricidade: Qual � a f�rmula do c�lculo de Volts.\n\n");
	
	            printf("A) V = I . T\n");
	            printf("B) V = P . R\n");
	            printf("C) V = R . I\n");           
	            printf("D) V = F . N\n");
	            printf("---------------------------------\n");
	            printf("Resposta? ");
	            scanf(" %c", &respostaUsuario);
	            
	            respostaCorreta = 'C';
	            
				contadorFacil = contadores(contadorFacil, respostaUsuario, respostaCorreta, 100);
				
	            printf("\n---------------------------------\n\n");
	
	            printf("N�VEL F�CIL\n\n");
	            printf("Acertos: %d\n", contadorFacil.acertos);
	            printf("Erros: %d\n", contadorFacil.erros);
	            printf("Pontua��o: %d\n\n", contadorFacil.pontuacao);
	        	printf("_______PARTIDA FINALIZADA_______\n\n");
	            
	            pontuacaoTotal[auxHorario] = contadorFacil.pontuacao;
	            strcpy(modo_de_jogo[auxHorario].nome, "N�vel F�cil");
	            auxHorario += 1;
	            break;
	        }
	
	        case 3:{
	            char respostaUsuario;
	            contadorMedio contadorMedio;
		
				contadorMedio.acertos =0;
				contadorMedio.erros =0;
				contadorMedio.pontuacao =0;	
				
				//--------HORARIO-------//
	            struct tm tempo;
	            time_t tempoSeg;
	
	            time(&tempoSeg);
	            tempo = *localtime(&tempoSeg);
	
	            hora[auxHorario] = tempo.tm_hour;
	            minuto[auxHorario] = tempo.tm_min;
	            segundo[auxHorario] = tempo.tm_sec;
	            //--------HORARIO-------//
	            
	            printf("\n	VOC� SELECIONOU - JOGAR N�VEL M�DIO\n");
	            
	            //----------- Chamada do nome(usuario do win) -------------//
				char username[UNLEN + 1];
	            DWORD username_len = UNLEN + 1;
	            GetUserName(username, &username_len);
	
	            printf("\n	Ol� %s, seja bem vindo\n\n", username);
	            //----------- Chamada do nome(usuario do win) -------------//
	            
	            printf("    Este � um jogo de perguntas e respostas. O jogador(a) dever� escolher,\ndentre as 4 alternativas apenas uma e em seguida pressionar 'enter'\n\n");
	            printf("    Para mais informa��es, acesse a op��o INSTRU��ES de menu do jogo\n\n\n");
	
	           	char tecla;
				    
				printf("PRESSIONE ENTER PARA COME�AR...");
				tecla = getch();
				printf("\n\n");       
				
				if(tecla != 13){
					break;
				}        
				
	            printf("*--------------------------------*\n");
	            printf("|  PERGUNTA n. 01 - N�vel M�dio  |\n");
	            printf("*--------------------------------*\n\n");
	
	            printf("Instrumen��o Industrial: Marque a alternativa que n�o corresponde a uma vantagem do emprego de instrumentos no controle de processos.\n\n");
	            printf("A) Proporciona maior qualidade e uniformidade no produto final.\n");
	            printf("B) H� um aumento na necessidade de m�o de obra e, consequentemente, aumento de produ��o. \n");
	            printf("C) Redu��o de efeitos nocivos ao meio ambiente.\n");           
	            printf("D) Substitui oper�rios nos trabalhos realizados em ambientes agressivos.\n");
	            printf("---------------------------------\n");
	            printf("Resposta? ");
	            scanf(" %c", &respostaUsuario);
	            
				char respostaCorreta = 'B';

				contadorMedio = contadores(contadorMedio, respostaUsuario, respostaCorreta, 150);
				
	            printf("\n---------------------------------\n\n");
	        
	            printf("*--------------------------------*\n");
	            printf("|  PERGUNTA n. 02 - N�vel M�dio  |\n");
	            printf("*--------------------------------*\n\n");
	
	            printf("Programa��o: Qual � a principal diferen�a entre as estruturas de loop While e Do While.\n\n");
	
	            printf("A) While primeiro executa para depois verificar, enquanto o Do While primeiro verifica para depois executar\n");
	            printf("B) While precisa de um contador e o Do while n�o\n");
	            printf("C) Do While primeiro executa para depois verificar, enquanto o While primeiro verifica para depois executar\n");           
	            printf("D) Todas as alternativas est�o incorretas\n");
	            
	            printf("---------------------------------\n");
	            printf("Resposta? ");
	            scanf(" %c", &respostaUsuario);
	            
	            respostaCorreta = 'C';
	            
				contadorMedio = contadores(contadorMedio, respostaUsuario, respostaCorreta, 150);

	            printf("\n---------------------------------\n\n");
	
	            printf("*--------------------------------*\n");
	            printf("| PERGUNTA n. 03 - N�vel M�dio |\n");
	            printf("*--------------------------------*\n\n");
	
	            printf("Eletr�nica Anal�gica: O Dispositivo que emite um sinal de sa�da padronizado modificado, em rela��o � natureza do correspondente sinal de entrada, tamb�m padronizado, � conhecido como\n\n");
	            
	            printf("A) conversor.\n");
	            printf("B) transmissor.\n");
	            printf("C) v�lvula de controle.\n");           
	            printf("D) chave.\n");
	            printf("---------------------------------\n");
	            printf("Resposta? ");
	            scanf(" %c", &respostaUsuario);
	            
	            respostaCorreta = 'A';
	            
				contadorMedio = contadores(contadorMedio, respostaUsuario, respostaCorreta, 150);

	            printf("\n---------------------------------\n\n");
	
	            printf("N�VEL M�DIO\n\n");
	            printf("Acertos: %d\n", contadorMedio.acertos);
	            printf("Erros: %d\n", contadorMedio.erros);
	            printf("Pontua��o: %d\n\n", contadorMedio.pontuacao);
	        	printf("_______PARTIDA FINALIZADA_______\n\n");
	            
	            pontuacaoTotal[auxHorario] = contadorMedio.pontuacao;
	            
				strcpy(modo_de_jogo[auxHorario].nome, "N�vel M�dio");
	            auxHorario += 1;
	            break;
	        }
	
	        case 4:{
	            char respostaUsuario;
	            contadorDificil contadorDificil;
		
				contadorDificil.acertos =0;
				contadorDificil.erros =0;
				contadorDificil.pontuacao =0;	
				
				//--------HORARIO-------//
	            struct tm tempo;
	            time_t tempoSeg;
	
	            time(&tempoSeg);
	            tempo = *localtime(&tempoSeg);
	
	            hora[auxHorario] = tempo.tm_hour;
	            minuto[auxHorario] = tempo.tm_min;
	            segundo[auxHorario] = tempo.tm_sec;
	            //--------HORARIO-------//
	            
	            printf("\n	VOC� SELECIONOU - JOGAR N�VEL DIF�CIL\n");
	            
	            //----------- Chamada do nome(usuario do win) -------------//
				char username[UNLEN + 1];
	            DWORD username_len = UNLEN + 1;
	            GetUserName(username, &username_len);
	
	            printf("\n	Ol� %s, seja bem vindo\n\n", username);
	            //----------- Chamada do nome(usuario do win) -------------//
	            
	            printf("    Este � um jogo de perguntas e respostas. O jogador(a) dever� escolher,\ndentre as 4 alternativas apenas uma e em seguida pressionar 'enter'\n\n");
	            printf("    Para mais informa��es, acesse a op��o INSTRU��ES de menu do jogo\n\n\n");
	
				char tecla;
				    
				printf("PRESSIONE ENTER PARA COME�AR...");
				tecla = getch();
				printf("\n\n");       
				
				if(tecla != 13){
					break;
				}
				       
	            printf("*--------------------------------*\n");
	            printf("|  PERGUNTA n. 01 - N�vel Dif�cil  |\n");
	            printf("*--------------------------------*\n\n");
	
	            printf("Mec�nica dos Fluidos: Em rela��o aos combust�veis e lubrificantes, assinale a alternativa INCORRETA.\n\n");
	            printf("A) A viscosidade aumenta com o aumento da temperatura.\n");
	            printf("B) Quanto menores forem as folgas, menor dever� ser a viscosidade lubrificante para que o �leo possa penetrar nelas.\n");
	            printf("C) A maioria dos combust�veis cont�m hidrog�nio, que forma �gua quando queimado. O poder calor�fico � denominado inferior quando a �gua � liberada sob a forma de vapor.\n");           
	            printf("D) Quanto maior a velocidade, menor deve ser a viscosidade do lubrificante, pois a forma��o da pel�cula lubrificante � mais f�cil.\n");
	            printf("---------------------------------\n");
	            printf("Resposta? ");
	            scanf(" %c", &respostaUsuario);
	            
				char respostaCorreta = 'A';

				contadorDificil = contadores(contadorDificil, respostaUsuario, respostaCorreta, 200);

	            printf("\n---------------------------------\n\n");
	        
	            printf("*--------------------------------*\n");
	            printf("|  PERGUNTA n. 02 - N�vel Dif�cil  |\n");
	            printf("*--------------------------------*\n\n");
	
	            printf("M�quinas El�tricas: O transformador ideal abaixo piossui 300 espiras no prim�rio e 1200 espiras no secund�rio. Determine a tens�o do sencud�rio. Dados: v1 = 10v\n\n");
	
	            printf("A) 22v\n");
	            printf("B) 20v\n");
	            printf("C) 36v\n");           
	            printf("D) 40v\n");
	            
	            printf("---------------------------------\n");
	            printf("Resposta? ");
	            scanf(" %c", &respostaUsuario);
	            
	            respostaCorreta = 'D';

				contadorDificil = contadores(contadorDificil, respostaUsuario, respostaCorreta, 200);

	            printf("\n---------------------------------\n\n");
	
	            printf("*--------------------------------*\n");
	            printf("| PERGUNTA n. 03 - N�vel Dif�cil |\n");
	            printf("*--------------------------------*\n\n");
	
	            printf("Eletr�nica Digital: Circuitos que s�o utilizados nos casos em que necessitamos enviar um certo n�mero de informa��es, contidas em v�rios canais, a um s� canal, s�o chamados de:\n\n");
	
	            printf("A) Demultiplexadores (DEMUX)\n");
	            printf("B) Somadores\n");
	            printf("C) Multiplexadores (MUX)\n");           
	            printf("D) Nenhuma alternativa est� correta\n");
	            printf("---------------------------------\n");
	            printf("Resposta? ");
	            scanf(" %c", &respostaUsuario);
	            
	            respostaCorreta = 'C';
	            
				contadorDificil = contadores(contadorDificil, respostaUsuario, respostaCorreta, 200);

	            printf("\n---------------------------------\n\n");
	
	            printf("N�VEL DIF�CIL\n\n");
	            printf("Acertos: %d\n", contadorDificil.acertos);
	            printf("Erros: %d\n", contadorDificil.erros);
	            printf("Pontua��o: %d\n\n", contadorDificil.pontuacao);
	        	printf("_______PARTIDA FINALIZADA_______\n\n");
	            
	            pontuacaoTotal[auxHorario] = contadorDificil.pontuacao;
	            
				strcpy(modo_de_jogo[auxHorario].nome, "N�vel Dif�cil");
	            auxHorario += 1;
	                        
	            break;
	        }
	
	        case 5:{
	        	contadorFacil contadorFacil;
				
				printf("\n\n");
				
	            for(int i = 1; i < auxHorario; i++){
	            	printf("%d - Modo de jogo: %s", i, modo_de_jogo[i].nome);
	           		printf("\nHora da jogada ........: %d:",hora[i]);//hora   
	            	printf("%d:",minuto[i]);//minuto
	            	printf("%d\n",segundo[i]);//segundo 
	            	printf("Pontuacao: %d\n", pontuacaoTotal[i]);
	        	}
	        	
	        	if(auxHorario == 1){
	        		printf("	N�o H� jogadas para serem registradas.\n");
				}
	        	
	        	printf("\n\n");
	        	
	            break;
	        }
	
	        case 6:{
				printf("	1 - Use sempre letra mai�scula, exemplo: B.\n");
				printf("	2 - Preste aten��o no enunciado.\n");
				printf("	3 - Fa�a o quiz com calma.\n");
				printf("	4 - Se n�o souber a resposta de alguma pergunta, coloque qualquer letra do alfabeto que ser� mostrado a resposta correta.\n");
				printf("	5 - O nome da mat�ria est� no come�o do enunciado, caso precise revisa-l� posteriormente.\n\n");
	            break;
	        }
	
	        case 7:{
	            printf("\n	Bruno Magalh�es de Souza     - 17 anos - SZ3005291\n");
	            printf("	Caique Martins Da Silva      - 18 anos - SZ3006239\n");
				printf("	Kauan Linhares Pereira       - 19 anos - SZ3006506\n");
				printf("	Samuel Bandeira de Oliveira  - 18 anos - SZ3005704\n\n\n");
	            break;
	        }
	        
	        default:{
	            printf("\n    Op��o inv�lida, tente novamente\n\n");
	        }
	    }
	}while(opcao != 0);
    return 0;
}
