/*ENGENHARIA DE CONTROLE E AUTOMAÇÃO*/
/*SYLVIELLY S SOUSA*/
/*DISPOSITIVOS PERIFERICOS*/
//PROGRAMAS PROF. FABIO
//SEMESTRE 2020.1

//"Projete o acionamento de um elevador através de 2 botões (subir e descer) 
//de acordo
//com os dados abaixo associados ao seu número de matrícula:"

//=================================REQUISITOS==================================
//Nº DE ANDARES  : 2
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
signed long int a = 4;
signed long int FLAG_BOTAO_SUBIR = 0;
signed long int FLAG_BOTAO_DESCER = 0;
unsigned int32 LACO_REPETICAO_1 = 0;
unsigned int32 LACO_REPETICAO_2 = 795;

void MOTOR_SUBIR(){

   if((CONTADOR_TEMPO_1<3183)&&(FLAG_BOTAO_SUBIR==1)){
      while(LACO_REPETICAO_1<795){           
              OUTPUT_D(0x90);
              printf("s\r\n");
              delay_ms(a);
              
              OUTPUT_D(0x30);
              printf("s\r\n");
              delay_ms(a);
              
              OUTPUT_D(0x60);
              printf("s\r\n");
              delay_ms(a);
              
              OUTPUT_D(0xC0);
              printf("s\r\n");
              delay_ms(a);
              
              LACO_REPETICAO_1+=1;
              CONTADOR_TEMPO_1+=4;
              //printf("CONTADOR = %li\r\n",CONTADOR_TEMPO_1);
      }
      
              OUTPUT_D(0x90);
              printf("s\r\n");
              delay_ms(a);
              
              OUTPUT_D(0x30);
              printf("s\r\n");
              delay_ms(a);
              
              OUTPUT_D(0x60);
              printf("s\r\n");
              delay_ms(a);
              CONTADOR_TEMPO_1+=3;
              //printf("CONTADOR = %li\r\n",CONTADOR_TEMPO_1);
              printf("q\r\n");
      

   }else if((CONTADOR_TEMPO_1>3183)&&(input(SUBIR)==0)&&(FLAG_BOTAO_SUBIR==1)){
      FLAG_BOTAO_SUBIR = 0;         //zera as flags
      FLAG_BOTAO_DESCER = 0;
      OUTPUT_D(0x00);               //desliga motor
   }  
}  

void MOTOR_DESCER(){

   if((CONTADOR_TEMPO_2>0)&&(FLAG_BOTAO_DESCER==1)){
        while(LACO_REPETICAO_2>0){
              
              OUTPUT_D(0xC0);
              printf("d\r\n");
              delay_ms(a);
              
              OUTPUT_D(0x60);
              printf("d\r\n");
              delay_ms(a);
              
              OUTPUT_D(0x30);
              printf("d\r\n");
              delay_ms(a);
              
              OUTPUT_D(0x90);
              printf("d\r\n");
              delay_ms(a);
              
              LACO_REPETICAO_2-=1;
              CONTADOR_TEMPO_2-=4;
              //printf("CONTADOR = %li\r\n",CONTADOR_TEMPO_2);

              //printf("LACO = %li\r\n",LACO_REPETICAO_2);
        }        
              OUTPUT_D(0xC0);
              printf("d\r\n");
              delay_ms(a);
              
              OUTPUT_D(0x60);
              printf("d\r\n");
              delay_ms(a);
              
              OUTPUT_D(0x30);
              printf("d\r\n");
              delay_ms(a);
              CONTADOR_TEMPO_2-=3;
              //printf("CONTADOR = %li\r\n",CONTADOR_TEMPO_2);
              printf("q\r\n");
      
              
     }else if((CONTADOR_TEMPO_2==0)&&(input(DESCER)==0)&&(FLAG_BOTAO_DESCER==1)){
        FLAG_BOTAO_DESCER = 0;
        FLAG_BOTAO_SUBIR = 0;
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
                     MOTOR_SUBIR();
                     
                     }
                  
              if ((input(SUBIR)==1)&&(input(DESCER)==0)&&(FLAG_BOTAO_SUBIR==0)){
                     FLAG_BOTAO_DESCER = 1;
                  }
                  if(FLAG_BOTAO_DESCER==1){
                     MOTOR_DESCER();
                     
                     }

      }
                  
}
