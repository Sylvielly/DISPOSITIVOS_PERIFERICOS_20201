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
#int_timer1                                  //HABILITACAO TIMER1

//DEFINICAO DE VARIAVEIS
signed long int CONTADOR_TEMPO_1 = 0;
signed long int CONTADOR_TEMPO_2 = 3183;
signed long int FLAG_BOTAO_SUBIR = 0;
signed long int FLAG_BOTAO_DESCER = 0;

//===================== FUNCAO PARA GIRAR MOTOR DE PASSO ======================
//FUNCAO PRA GIRAR MOTOR (SUBIDA)
//void MOTOR_SUBIR(){
//}

//FUNCAO GIRAR MOTOR (DESCIDA)
//void MOTOR_DESCER(){
     
//}

//INICIO FUNCAO TEMPO
void TEMPO(){

   static unsigned int32 N;
   static unsigned int32 SET_TIMER = 55536;
   set_timer1(SET_TIMER+get_timer1());
   N++;

   //if((N == 250)&&(FLAG_BOTAO_SUBIR == 1)){
   //      N = 0;
         
         CONTADOR_TEMPO_1+=1;
               
   if(CONTADOR_TEMPO_1<3183){
            
         switch((CONTADOR_TEMPO_1)%4){
      
            case '0': 
            if(N==250){
            OUTPUT_D(0x90);
            printf("s\r\n");}
            printf("\r\nCONTADOR %li \r\n",CONTADOR_TEMPO_1);
            break;  
            
            case '1': 
            if(N==500){
            OUTPUT_D(0x48);
            printf("s\r\n");}
            printf("\r\nCONTADOR %li \r\n",CONTADOR_TEMPO_1);
            break; 
            
            case '2': 
            if(N==750){
            OUTPUT_D(0x96);
            printf("s\r\n");}
            printf("\r\nCONTADOR %li \r\n",CONTADOR_TEMPO_1);
            break;
            
            case '3': 
            if(N==1000){
            OUTPUT_D(0xC0);
            printf("s\r\n");}
            printf("\r\nCONTADOR %li \r\n",CONTADOR_TEMPO_1);
            break;
            
            

         }
   }
   
   if(CONTADOR_TEMPO_2>0){
            
         switch((CONTADOR_TEMPO_2)%4){
      
            case '0': 
            if(N==250){
            OUTPUT_D(0xC0);
            printf("d\r\n");}
            printf("\r\nCONTADOR %li \r\n",CONTADOR_TEMPO_2);
            break;
            
            case '1': 
            if(N==500){
            OUTPUT_D(0x60);
            printf("d\r\n");}
            printf("\r\nCONTADOR %li \r\n",CONTADOR_TEMPO_2);
            break; 
            
            case '2': 
            if(N==750){
            OUTPUT_D(0x30);
            printf("d\r\n");}
            printf("\r\nCONTADOR %li \r\n",CONTADOR_TEMPO_2);
            break;
            
            case '3': 
            if(N==1000){
            OUTPUT_D(0x90);
            printf("d\r\n");}
            printf("\r\nCONTADOR %li \r\n",CONTADOR_TEMPO_2);
            break;
                      
         }
   }
   
   N=0;
   
   

}
   
   //}else if((N == 250)&&(FLAG_BOTAO_DESCER == 1)){
   //      N = 0;
   //      CONTADOR_TEMPO_2-=1;
   ///      MOTOR_DESCER();
      //}

//}
//FIM FUNCAO TEMPO

void main(){

//CONFIGURACAO PORTAS ENTRADA / SAIDA
port_b_pullups(TRUE);            //HABILITACAO DE PULLUPS PARA BOTOES
set_tris_b(0xFF);                //DEFINE PORTA B COMO 'INPUT' (0xFF = 0b11111111)
set_tris_d(0x00);                //DEFINE PORTA D COMO 'OUTPUT' (0x00 = 0b00000000)

//CONFIGURACOES DO TIMER1
setup_timer_1(T1_INTERNAL|T1_DIV_BY_2);
set_timer1(55536);
enable_interrupts(GLOBAL);
enable_interrupts(INT_TIMER1);

                  while(true){
                  
                        if((INPUT(SUBIR)==0)&&(INPUT(DESCER)==1)){
                              FLAG_BOTAO_SUBIR = !FLAG_BOTAO_SUBIR;
                           }
                                     
                        if((INPUT(SUBIR)==1)&&(INPUT(DESCER)==0)){                     
                              FLAG_BOTAO_DESCER = !FLAG_BOTAO_DESCER;
                           }
                     
                  
                  }
}
