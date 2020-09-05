/*ENGENHARIA DE CONTROLE E AUTOMA��O*/
/*SYLVIELLY S SOUSA*/
/*DISPOSITIVOS PERIFERICOS*/
//PROGRAMAS PROF. FABIO
//SEMESTRE 2020.1

//"Projete o acionamento de um elevador atrav�s de 2 bot�es (subir e descer) 
//de acordo
//com os dados abaixo associados ao seu n�mero de matr�cula:"

//=================================REQUISITOS==================================
//N� DE ANDARES  : 2
//DIAMETRO POLIA : 60 CM
//ANDAR DE INICIO DE SIMULACAO : TERREO
//SUBIR : PINO B3
//DESCER : PINO B1
//TIPO DE MOTOR : UNIPOLAR (MAIOR TORQUE)
//PPR : 500
//MODO : FULL STEP
//SAIDA PARA AS BOBINAS DO MOTOR: D7, D6, D5 E D4

//DEFINICAO DE PINOS
#define SUBIR 0x7C0B
#define DESCER 0x7C09

//CABECALHO PADRAO
#include <18F4550.h>
#byte PORTD = 0xF83                          //HABILITACAO PORTA 'D'
#fuses HS, CPUDIV1,PLL5,USBDIV
#use delay(clock=20000000)
#use rs232(baud=9600,xmit=PIN_C6,rcv=PIN_C7) //HABILITACAO SERIAL

//DEFINICAO DE VARIAVEIS
signed long int CONTADOR_TEMPO_1 = 0;
signed long int CONTADOR_TEMPO_2 = 3183;
signed long int a = 2;
signed long int FLAG_BOTAO_SUBIR = 0;
signed long int FLAG_BOTAO_DESCER = 0;
unsigned int32 LACO_REPETICAO = 0;
void MOTOR_SUBIR(){
   
   if((CONTADOR_TEMPO_1<=3182)&&(FLAG_BOTAO_SUBIR==1)){
      if(LACO_REPETICAO<397){
      
              OUTPUT_D(0x90);
              printf("s\r\n");
              CONTADOR_TEMPO_1+=1;
              printf("CONTADOR = %li\r\n",CONTADOR_TEMPO_1);
              delay_ms(a);
              
              OUTPUT_D(0x30);
              printf("s\r\n");
              CONTADOR_TEMPO_1+=1;
              printf("CONTADOR = %li\r\n",CONTADOR_TEMPO_1);
              delay_ms(a);
              
              OUTPUT_D(0x60);
              printf("s\r\n");
              CONTADOR_TEMPO_1+=1;
              printf("CONTADOR = %li\r\n",CONTADOR_TEMPO_1);
              delay_ms(a);
              
              OUTPUT_D(0xC0);
              printf("s\r\n");
              CONTADOR_TEMPO_1+=1;
              printf("CONTADOR = %li\r\n",CONTADOR_TEMPO_1);
              delay_ms(a);
              
              LACO_REPETICAO+=1;
              printf("CONTADOR = %li\r\n",LACO_REPETICAO);
      }
      
              OUTPUT_D(0x90);
              printf("s\r\n");
              CONTADOR_TEMPO_1+=1;
              printf("CONTADOR = %li\r\n",CONTADOR_TEMPO_1);
              delay_ms(a);
              
              OUTPUT_D(0x30);
              printf("s\r\n");
              CONTADOR_TEMPO_1+=1;
              printf("CONTADOR = %li\r\n",CONTADOR_TEMPO_1);
              delay_ms(a);
              
              OUTPUT_D(0x60);
              printf("s\r\n");
              CONTADOR_TEMPO_1+=1;
              printf("CONTADOR = %li\r\n",CONTADOR_TEMPO_1);
              delay_ms(a);
              
              OUTPUT_D(0xC0);
              printf("s\r\n");
              CONTADOR_TEMPO_1+=1;
              printf("CONTADOR = %li\r\n",CONTADOR_TEMPO_1);
              delay_ms(a);

              OUTPUT_D(0x90);
              printf("s\r\n");
              CONTADOR_TEMPO_1+=1;
              printf("CONTADOR = %li\r\n",CONTADOR_TEMPO_1);
              delay_ms(a);
              
              OUTPUT_D(0x30);
              printf("s\r\n");
              CONTADOR_TEMPO_1+=1;
              printf("CONTADOR = %li\r\n",CONTADOR_TEMPO_1);
              delay_ms(a);
              
              OUTPUT_D(0x60);
              printf("s\r\n");
              CONTADOR_TEMPO_1+=1;
              printf("CONTADOR = %li\r\n",CONTADOR_TEMPO_1);
              delay_ms(a);

              
   }else if((CONTADOR_TEMPO_1>3183)&&(input(SUBIR)==0)&&(FLAG_BOTAO_SUBIR==1)){
      FLAG_BOTAO_SUBIR = 0;
      FLAG_BOTAO_DESCER = 0;
      printf("q\r\n");
      OUTPUT_D(0x00);
   }
}

void MOTOR_DESCER(){

   if((CONTADOR_TEMPO_2>0)&&(FLAG_BOTAO_DESCER==1)){
              
              OUTPUT_D(0xC0);
              printf("d\r\n");
              CONTADOR_TEMPO_2-=1;
              printf("CONTADOR = %li\r\n",CONTADOR_TEMPO_2);
              delay_ms(a);
              
              OUTPUT_D(0x60);
              printf("d\r\n");
              CONTADOR_TEMPO_2-=1;
              printf("CONTADOR = %li\r\n",CONTADOR_TEMPO_2);
              delay_ms(a);
              
              OUTPUT_D(0x30);
              printf("d\r\n");
              CONTADOR_TEMPO_2-=1;
              printf("CONTADOR = %li\r\n",CONTADOR_TEMPO_2);
              delay_ms(a);
              
              OUTPUT_D(0x90);
              printf("d\r\n");
              CONTADOR_TEMPO_2-=1;
              printf("CONTADOR = %li\r\n",CONTADOR_TEMPO_2);
              delay_ms(a);
              
     }else if((CONTADOR_TEMPO_2==0)&&(input(DESCER)==0)&&(FLAG_BOTAO_DESCER==1)){
        FLAG_BOTAO_DESCER = 0;
        FLAG_BOTAO_SUBIR = 0;
        printf("q\r\n");
        OUTPUT_D(0x00);
           }
}
void main(){

//CONFIGURACAO PORTAS ENTRADA / SAIDA
port_b_pullups(TRUE);            //HABILITACAO DE PULLUPS PARA BOTOES
set_tris_b(0xFF);                //DEFINE PORTA B COMO 'INPUT' (0xFF = 0b11111111)
set_tris_d(0x00);                //DEFINE PORTA D COMO 'OUTPUT' (0x00 = 0b00000000)

      while(true){
         
              if ((input(SUBIR)==0)&&(input(DESCER)==1)&&(FLAG_BOTAO_DESCER==0)){
                     FLAG_BOTAO_SUBIR = 1;                     
                  }
                  if(FLAG_BOTAO_SUBIR==1){
                     MOTOR_SUBIR();}
                  
              if ((input(SUBIR)==1)&&(input(DESCER)==0)&&(FLAG_BOTAO_SUBIR==0)){
                     FLAG_BOTAO_DESCER = 1;
                  }
                  if(FLAG_BOTAO_DESCER==1){
                     MOTOR_DESCER();}

   
      }
                  
}



