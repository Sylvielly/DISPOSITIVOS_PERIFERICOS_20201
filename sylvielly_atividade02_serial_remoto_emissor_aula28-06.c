/*INSTITUTO FEDERAL DO CEARÁ (IFCE)*/
/*BACHARELADO EM ENGENHARIA DE CONTROLE E AUTOMAÇÃO*/
/*SYLVIELLY S SOUSA*/
/*DISPOSITIVOS PERIFERICOS*/
//PROGRAMAS PROF. FABIO
//SEMESTRE 2020.1

//ATIVIDADE 02: ELABORAR PROGRAMA PARA LIGAR E DESLIGAR LEDS NA FORMA SEQUENCIAL REMOTAMENTE SIMULANDO UM CONTROLE EM MALHA ABERTA

/* ---------------------------- ---------------- ----------------------------*/
/* ---------------------------- CIRCUITO EMISSOR ----------------------------*/
/* ---------------------------- ---------------- ----------------------------*/

//INICIO CABECALHO PADRAO
#include <18F4550.h>
#fuses HS, CPUDIV1,PLL5,USBDIV
#device ADC = 10
#use delay(clock=20000000)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)

//DECLARACAO DE VARIAVEIS
float valor_ad;               //VARIAVEL DO TIPO 'FLOAT'
float vad;

//INICIO DE PROGRAMA
void main(){
   
   //CONFIGURACAO PORTAS ANALOGICAS
   setup_adc_ports(AN0_TO_AN1|VSS_VDD);
   SETUP_ADC(ADC_CLOCK_INTERNAL);
   SET_ADC_CHANNEL(1);
  
               while(true){
                  //LEITURA DO POTENCIOMETRO
                  valor_ad = read_adc();
                  delay_ms(10);
                  vad = ((valor_ad*5)/1023);
                  
                   if((vad>0)&&(vad<=5)){
                           
                           if((vad>0.625)&&(vad<=1.25)){
                              printf("1");
                              }
                              
                            if((vad>1.25)&&(vad<=1.875)){
                              printf("2"); 
                              }
                              
                            if((vad>1.875)&&(vad<=2.5)){
                              printf("3");
                              }
                              
                            if((vad>2.5)&&(vad<=3.125)){
                              printf("4");
                              }
                              
                            if((vad>3.125)&&(vad<=3.75)){
                              printf("5");                              
                              }
                              
                            if((vad>3.75)&&(vad<=4.375)){
                              printf("6");
                              }
                           
                            if((vad>4.375)&&(vad<5)){
                              printf("7");
                              }
                 
                            if(vad==5){
                              printf("8");
                              }
                                      
                    }
                     
               }

}  //FIM DE PROGRAMA

