#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <Lmcons.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

/*
	Caso apareça o erro C99 no compilador, vá em Ferramentas(Tools) --> 
	Opções de Compilador...(Compiler Options...) --> No primeiro campo marque a caixa e digite: -std=c99
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
	int hora[10], minuto[10], segundo[10], pontuacaoTotal[10], auxHorario = 1;
	char modoJogo[10];
    int opcao;
	do{
	
	    printf("    *------------------------------------------------------*\n");
	    printf("    |                     MENU DE OPÇÃO                    |\n");
	    printf("    *------------------------------------------------------*\n");
	    printf("    |   0 - SAIR DO JOGO                                   |\n");  
	    printf("    |   1 - JOGAR TODOS OS NÍVEIS                          |\n");
	    printf("    |   2 - JOGAR NÍVEL FÁCIL - SOMENTE O NÍVEL FÁCIL      |\n");
	    printf("    |   3 - JOGAR NÍVEL MÉDIO - SOMENTE O NÍVEL MÉDIO      |\n");
	    printf("    |   4 - JOGAR NÍVEL DIFÍCIL - SOMENTE O NÍVEL DIFÍCIL  |\n");
	    printf("    |   5 - HISTÓRICO DE JOGADAS                           |\n");    
	    printf("    |   6 - VER INSTRUÇÕES DO JOGO E INFORMAÇÕES           |\n");
	    printf("    |   7 - VER OS DESENVOLVEDORES                         |\n");
	    printf("    *------------------------------------------------------*\n\n");
	
	    printf("    Digite uma opção: ");  
	
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
	            
	
	            printf("\n	VOCÊ SELECIONOU - JOGAR TODOS OS NÍVEIS\n");
	            
	            //----------- Chamada do nome(usuario do win) -------------//
				char username[UNLEN + 1];
	            DWORD username_len = UNLEN + 1;
	            GetUserName(username, &username_len);
	
	            printf("\n	Olá %s, seja bem vindo\n\n", username);
	            //----------- Chamada do nome(usuario do win) -------------//
	            
	            printf("    Este é um jogo de perguntas e respostas. O jogador(a) deverá escolher,\ndentre as 4 alternativas apenas uma e em seguida pressionar 'enter'\n\n");
	            printf("    Para mais informações, acesse a opção INSTRUÇÕES de menu do jogo\n\n\n");
				    
				char tecla;
				    
				printf("PRESSIONE ENTER PARA COMECAR...");
				tecla = getch();
				printf("\n\n");       
				
				if(tecla != 13){
					break;
				}
         
	            printf("*--------------------------------*\n");
	            printf("|  PERGUNTA n. 01 - Nível Fácil  |\n");
	            printf("*--------------------------------*\n\n");
	
	            printf("Laboratório de Automação: Qual é a área da física que utiliza de gases pressurizados para executar um trabalho?\n");
	            printf("A) Hidráulica\n");
	            printf("B) Pneumática\n");
	            printf("C) Elétrica\n");           
	            printf("D) Diodo Zener\n");
	            printf("---------------------------------\n");
	            printf("Resposta? ");
	            scanf(" %c", &respostaUsuario);
	            
				char respostaCorreta = 'B';
			
				todosNiveisFacil = contadores(todosNiveisFacil, respostaUsuario, respostaCorreta, 100);

	            printf("\n---------------------------------\n\n");
	        
	            printf("*--------------------------------*\n");
	            printf("|  PERGUNTA n. 02 - Nível Médio  |\n");
	            printf("*--------------------------------*\n\n");
	
	            printf("Redes e Protocolos Industriais: É o tipo de transmissão de dados bidirecional.A e B podem transmitir e receber dados ao mesmo tempo:\n");
				printf("Escolha uma opção:?\n\n");
	
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
	            printf("| PERGUNTA n. 03 - Nível Difícil |\n");
	            printf("*--------------------------------*\n\n");
	
	            printf("Instrumentação Industrial: Qual é o sensor mais adequado para medir, por contato direto, temperatura na faixa de 200 °C,apresentando, como característica, alta linearidade?\n\n");
	
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
	
	            printf("TODOS OS NÍVEIS\n\n");
	            printf("Acertos: %d\n", todosNiveisFacil.acertos + todosNiveisMedio.acertos + todosNiveisDificil.acertos);
	            printf("Erros: %d\n", todosNiveisFacil.erros + todosNiveisMedio.erros + todosNiveisDificil.erros);
	            printf("Pontuação: %d\n\n", todosNiveisFacil.pontuacao + todosNiveisMedio.pontuacao + todosNiveisDificil.pontuacao);
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
	            
	            printf("\n	VOCÊ SELECIONOU - JOGAR NÍVEL FÁCIL\n");
	            
	            //----------- Chamada do nome(usuario do win) -------------//
				char username[UNLEN + 1];
	            DWORD username_len = UNLEN + 1;
	            GetUserName(username, &username_len);
	
	            printf("\n	Olá %s, seja bem vindo\n\n", username);
	            //----------- Chamada do nome(usuario do win) -------------//
	            
	            printf("    Este é um jogo de perguntas e respostas. O jogador(a) deverá escolher,\ndentre as 4 alternativas apenas uma e em seguida pressionar 'enter'\n\n");
	            printf("    Para mais informações, acesse a opção INSTRUÇÕES de menu do jogo\n\n\n");
	
	            char tecla;
				    
				printf("PRESSIONE ENTER PARA COMEÇAR...");
				tecla = getch();
				printf("\n\n");       
				
				if(tecla != 13){
					break;
				}
				
	            printf("*--------------------------------*\n");
	            printf("|  PERGUNTA n. 01 - Nível Fácil  |\n");
	            printf("*--------------------------------*\n\n");
	
	            printf("Comandos Elétricos: As siglas NA e NF representam respectivamente:\n\n");
	
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
	            printf("|  PERGUNTA n. 02 - Nível Fácil  |\n");
	            printf("*--------------------------------*\n\n");
	
	            printf("Organização Saúde e Segurança: A revolução industrial favoreceu o desenvolvimento do __________.\n\n");
	
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
	            printf("| PERGUNTA n. 03 - Nível Fácil |\n");
	            printf("*--------------------------------*\n\n");
	
	            printf("Eletricidade: Qual é a fórmula do cálculo de Volts.\n\n");
	
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
	
	            printf("NÍVEL FÁCIL\n\n");
	            printf("Acertos: %d\n", contadorFacil.acertos);
	            printf("Erros: %d\n", contadorFacil.erros);
	            printf("Pontuação: %d\n\n", contadorFacil.pontuacao);
	        	printf("_______PARTIDA FINALIZADA_______\n\n");
	            
	            pontuacaoTotal[auxHorario] = contadorFacil.pontuacao;
	            strcpy(modo_de_jogo[auxHorario].nome, "Nível Fácil");
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
	            
	            printf("\n	VOCÊ SELECIONOU - JOGAR NÍVEL MÉDIO\n");
	            
	            //----------- Chamada do nome(usuario do win) -------------//
				char username[UNLEN + 1];
	            DWORD username_len = UNLEN + 1;
	            GetUserName(username, &username_len);
	
	            printf("\n	Olá %s, seja bem vindo\n\n", username);
	            //----------- Chamada do nome(usuario do win) -------------//
	            
	            printf("    Este é um jogo de perguntas e respostas. O jogador(a) deverá escolher,\ndentre as 4 alternativas apenas uma e em seguida pressionar 'enter'\n\n");
	            printf("    Para mais informações, acesse a opção INSTRUÇÕES de menu do jogo\n\n\n");
	
	           	char tecla;
				    
				printf("PRESSIONE ENTER PARA COMEÇAR...");
				tecla = getch();
				printf("\n\n");       
				
				if(tecla != 13){
					break;
				}        
				
	            printf("*--------------------------------*\n");
	            printf("|  PERGUNTA n. 01 - Nível Médio  |\n");
	            printf("*--------------------------------*\n\n");
	
	            printf("Instrumenção Industrial: Marque a alternativa que não corresponde a uma vantagem do emprego de instrumentos no controle de processos.\n\n");
	            printf("A) Proporciona maior qualidade e uniformidade no produto final.\n");
	            printf("B) Há um aumento na necessidade de mão de obra e, consequentemente, aumento de produção. \n");
	            printf("C) Redução de efeitos nocivos ao meio ambiente.\n");           
	            printf("D) Substitui operários nos trabalhos realizados em ambientes agressivos.\n");
	            printf("---------------------------------\n");
	            printf("Resposta? ");
	            scanf(" %c", &respostaUsuario);
	            
				char respostaCorreta = 'B';

				contadorMedio = contadores(contadorMedio, respostaUsuario, respostaCorreta, 150);
				
	            printf("\n---------------------------------\n\n");
	        
	            printf("*--------------------------------*\n");
	            printf("|  PERGUNTA n. 02 - Nível Médio  |\n");
	            printf("*--------------------------------*\n\n");
	
	            printf("Programação: Qual é a principal diferença entre as estruturas de loop While e Do While.\n\n");
	
	            printf("A) While primeiro executa para depois verificar, enquanto o Do While primeiro verifica para depois executar\n");
	            printf("B) While precisa de um contador e o Do while não\n");
	            printf("C) Do While primeiro executa para depois verificar, enquanto o While primeiro verifica para depois executar\n");           
	            printf("D) Todas as alternativas estão incorretas\n");
	            
	            printf("---------------------------------\n");
	            printf("Resposta? ");
	            scanf(" %c", &respostaUsuario);
	            
	            respostaCorreta = 'C';
	            
				contadorMedio = contadores(contadorMedio, respostaUsuario, respostaCorreta, 150);

	            printf("\n---------------------------------\n\n");
	
	            printf("*--------------------------------*\n");
	            printf("| PERGUNTA n. 03 - Nível Médio |\n");
	            printf("*--------------------------------*\n\n");
	
	            printf("Eletrônica Analógica: O Dispositivo que emite um sinal de saída padronizado modificado, em relação à natureza do correspondente sinal de entrada, também padronizado, é conhecido como\n\n");
	            
	            printf("A) conversor.\n");
	            printf("B) transmissor.\n");
	            printf("C) válvula de controle.\n");           
	            printf("D) chave.\n");
	            printf("---------------------------------\n");
	            printf("Resposta? ");
	            scanf(" %c", &respostaUsuario);
	            
	            respostaCorreta = 'A';
	            
				contadorMedio = contadores(contadorMedio, respostaUsuario, respostaCorreta, 150);

	            printf("\n---------------------------------\n\n");
	
	            printf("NÍVEL MÉDIO\n\n");
	            printf("Acertos: %d\n", contadorMedio.acertos);
	            printf("Erros: %d\n", contadorMedio.erros);
	            printf("Pontuação: %d\n\n", contadorMedio.pontuacao);
	        	printf("_______PARTIDA FINALIZADA_______\n\n");
	            
	            pontuacaoTotal[auxHorario] = contadorMedio.pontuacao;
	            
				strcpy(modo_de_jogo[auxHorario].nome, "Nível Médio");
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
	            
	            printf("\n	VOCÊ SELECIONOU - JOGAR NÍVEL DIFÍCIL\n");
	            
	            //----------- Chamada do nome(usuario do win) -------------//
				char username[UNLEN + 1];
	            DWORD username_len = UNLEN + 1;
	            GetUserName(username, &username_len);
	
	            printf("\n	Olá %s, seja bem vindo\n\n", username);
	            //----------- Chamada do nome(usuario do win) -------------//
	            
	            printf("    Este é um jogo de perguntas e respostas. O jogador(a) deverá escolher,\ndentre as 4 alternativas apenas uma e em seguida pressionar 'enter'\n\n");
	            printf("    Para mais informações, acesse a opção INSTRUÇÕES de menu do jogo\n\n\n");
	
				char tecla;
				    
				printf("PRESSIONE ENTER PARA COMEÇAR...");
				tecla = getch();
				printf("\n\n");       
				
				if(tecla != 13){
					break;
				}
				       
	            printf("*--------------------------------*\n");
	            printf("|  PERGUNTA n. 01 - Nível Difícil  |\n");
	            printf("*--------------------------------*\n\n");
	
	            printf("Mecânica dos Fluidos: Em relação aos combustíveis e lubrificantes, assinale a alternativa INCORRETA.\n\n");
	            printf("A) A viscosidade aumenta com o aumento da temperatura.\n");
	            printf("B) Quanto menores forem as folgas, menor deverá ser a viscosidade lubrificante para que o óleo possa penetrar nelas.\n");
	            printf("C) A maioria dos combustíveis contém hidrogênio, que forma água quando queimado. O poder calorífico é denominado inferior quando a água é liberada sob a forma de vapor.\n");           
	            printf("D) Quanto maior a velocidade, menor deve ser a viscosidade do lubrificante, pois a formação da película lubrificante é mais fácil.\n");
	            printf("---------------------------------\n");
	            printf("Resposta? ");
	            scanf(" %c", &respostaUsuario);
	            
				char respostaCorreta = 'A';

				contadorDificil = contadores(contadorDificil, respostaUsuario, respostaCorreta, 200);

	            printf("\n---------------------------------\n\n");
	        
	            printf("*--------------------------------*\n");
	            printf("|  PERGUNTA n. 02 - Nível Difícil  |\n");
	            printf("*--------------------------------*\n\n");
	
	            printf("Máquinas Elétricas: O transformador ideal abaixo piossui 300 espiras no primário e 1200 espiras no secundário. Determine a tensão do sencudário. Dados: v1 = 10v\n\n");
	
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
	            printf("| PERGUNTA n. 03 - Nível Difícil |\n");
	            printf("*--------------------------------*\n\n");
	
	            printf("Eletrônica Digital: Circuitos que são utilizados nos casos em que necessitamos enviar um certo número de informações, contidas em vários canais, a um só canal, são chamados de:\n\n");
	
	            printf("A) Demultiplexadores (DEMUX)\n");
	            printf("B) Somadores\n");
	            printf("C) Multiplexadores (MUX)\n");           
	            printf("D) Nenhuma alternativa está correta\n");
	            printf("---------------------------------\n");
	            printf("Resposta? ");
	            scanf(" %c", &respostaUsuario);
	            
	            respostaCorreta = 'C';
	            
				contadorDificil = contadores(contadorDificil, respostaUsuario, respostaCorreta, 200);

	            printf("\n---------------------------------\n\n");
	
	            printf("NÍVEL DIFÍCIL\n\n");
	            printf("Acertos: %d\n", contadorDificil.acertos);
	            printf("Erros: %d\n", contadorDificil.erros);
	            printf("Pontuação: %d\n\n", contadorDificil.pontuacao);
	        	printf("_______PARTIDA FINALIZADA_______\n\n");
	            
	            pontuacaoTotal[auxHorario] = contadorDificil.pontuacao;
	            
				strcpy(modo_de_jogo[auxHorario].nome, "Nível Difícil");
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
	        		printf("	Não Há jogadas para serem registradas.\n");
				}
	        	
	        	printf("\n\n");
	        	
	            break;
	        }
	
	        case 6:{
			printf("	1 - Use sempre letra maiúscula, exemplo: B.\n");
			printf("	2 - Preste atenção no enunciado.\n");
			printf("	3 - Faça o quiz com calma.\n");
			printf("	4 - Se não souber a resposta de alguma pergunta, coloque qualquer letra do alfabeto que será mostrado a resposta correta.\n");
			printf("	5 - O nome da matéria está no começo do enunciado, caso precise revisa-lá posteriormente.\n\n");
	            	break;
	        }
	
	        case 7:{
			printf("	Kauan Linhares Pereira       - 19 anos - SZ3006506\n");
	            	break;
	        }
	        
	        default:{
	            	printf("\n    Opção inválida, tente novamente\n\n");
	        }
	    }
	}while(opcao != 0);
    return 0;
}
