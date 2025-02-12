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
#define SUBIR 0x7C0B                   //BOTAO SUBIR : B3
#define DESCER 0x7C09                  //BOT�O DESCER : B1

#include <18F4550.h>
#byte PORTD = 0xF83             //HABILITACAO DO PORT D, LIGANDO TODOS OS PINOS
#fuses HS, CPUDIV1,PLL5,USBDIV
#use delay(clock=20000000)
#use rs232(baud=9600,xmit=PIN_C6,rcv=PIN_C7)

signed long int CONTADOR_TEMPO_1 = 0;
signed long int CONTADOR_TEMPO_2 = 3183;
static unsigned int32 GIRA_DESCER = 4;
static unsigned int32 GIRA_SUBIR = 0;

//FUNCAO PRA GIRAR MOTOR (SUBIDA)
void MOTOR_SUBIR(){
GIRA_SUBIR+=1;                     
                 switch (GIRA_SUBIR){
                     
                     case '1':
                        OUTPUT_D(0x90);
                           if(CONTADOR_TEMPO_1<3183){
                              CONTADOR_TEMPO_1+=1;
                              }else{
                               OUTPUT_D(0x00);
                              }
                        printf("s\r\n");
                        printf("\r\n CONTADOR = %li\r\n",CONTADOR_TEMPO_1);
                        break;
                        
                     case '2':
                        OUTPUT_D(0x48);
                           if(CONTADOR_TEMPO_1<3183){
                              CONTADOR_TEMPO_1+=1;
                              }else{
                               OUTPUT_D(0x00);
                              }
                        printf("s\r\n");
                        printf("\r\n CONTADOR = %li\r\n",CONTADOR_TEMPO_1);
                        break;
                        
                     case '3':
                        OUTPUT_D(0x96);
                           if(CONTADOR_TEMPO_1<3183){
                              CONTADOR_TEMPO_1+=1;
                              }else{
                               OUTPUT_D(0x00);
                              }
                        printf("s\r\n");
                        printf("\r\n CONTADOR = %li\r\n",CONTADOR_TEMPO_1);
                        break;
                        
                     case '4':   
                        OUTPUT_D(0xC0);
                           if(CONTADOR_TEMPO_1<3183){
                              CONTADOR_TEMPO_1+=1;
                              }else{
                               OUTPUT_D(0x00);
                              }
                        printf("s\r\n");
                        printf("\r\n CONTADOR = %li\r\n",CONTADOR_TEMPO_1);
      
                        printf("\r\n");
                        break;
                        
                if((GIRA_SUBIR > 4)&&(CONTADOR_TEMPO_1<3183)){
                         GIRA_SUBIR = 0;
                         CONTADOR_TEMPO_1+=1;
                         printf("\r\n CONTADOR = %li\r\n",CONTADOR_TEMPO_1);           
                        }
                 

                 }
}

//FUNCAO GIRAR MOTOR (DESCIDA)
void MOTOR_DESCER(){

                     GIRA_DESCER-=1;
                     
                     switch (GIRA_DESCER){
                     
                     case '1':
                        OUTPUT_D(0xC0);
                        if(CONTADOR_TEMPO_2>0){
                              CONTADOR_TEMPO_2-=1;
                              }else{
                               OUTPUT_D(0x00);
                              }
                        
                        printf("\r\n CONTADOR = %li\r\n",CONTADOR_TEMPO_2);
                        printf("d\r\n");
                        break;
                        
                     case '2':
                        OUTPUT_D(0x60);
                        if(CONTADOR_TEMPO_2>0){
                              CONTADOR_TEMPO_2-=1;
                              }else{
                               OUTPUT_D(0x00);
                              }
                
                        printf("\r\n CONTADOR = %li\r\n",CONTADOR_TEMPO_2);
                        printf("d\r\n");
                        break;
                        
                     case '3':
                        OUTPUT_D(0x30);
                        if(CONTADOR_TEMPO_2>0){
                              CONTADOR_TEMPO_2-=1;
                              }else{
                               OUTPUT_D(0x00);
                              }
                        printf("s\r\n");
                        printf("\r\n CONTADOR = %li\r\n",CONTADOR_TEMPO_2);
                        printf("d\r\n");
                        break;
                        
                     case '4':   
                        OUTPUT_D(0x90);
                        if(CONTADOR_TEMPO_2>0){
                              CONTADOR_TEMPO_2-=1;
                              }else{
                               OUTPUT_D(0x00);
                              }
                        printf("\r\n CONTADOR = %li\r\n",CONTADOR_TEMPO_2);
                        printf("d\r\n");
                        printf("\r\n");
                        break;
                        
                        if((GIRA_DESCER <= 0)&&(CONTADOR_TEMPO_2>0)){
                              GIRA_DESCER = 4;
                              CONTADOR_TEMPO_2-=1;
                              printf("\r\n CONTADOR = %li\r\n",CONTADOR_TEMPO_2);
                           }
                       }

}

void main(){

//CONFIGURACAO PORTAS ENTRADA / SAIDA
port_b_pullups(TRUE);            //HABILITACAO DE PULLUPS PARA BOTOES
set_tris_b(0xFF);                //DEFINE PORTA B COMO 'INPUT' (0xFF = 0b11111111)
set_tris_d(0x00);                //DEFINE PORTA D COMO 'OUTPUT' (0x00 = 0b00000000)

          while(true){
                  
              if((INPUT(SUBIR)==0)&&(INPUT(DESCER)==1)){
                  MOTOR_SUBIR();
                  }
                                     
              if((INPUT(SUBIR)==1)&&(INPUT(DESCER)==0)){                     
                  MOTOR_DESCER();
                  }
                  
            }
}

