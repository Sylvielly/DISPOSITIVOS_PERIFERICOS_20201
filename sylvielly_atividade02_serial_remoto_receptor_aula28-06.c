/*INSTITUTO FEDERAL DO CEARÁ (IFCE)*/
/*BACHARELADO EM ENGENHARIA DE CONTROLE E AUTOMAÇÃO*/
/*SYLVIELLY S SOUSA*/
/*DISPOSITIVOS PERIFERICOS*/
//PROGRAMAS PROF. FABIO
//SEMESTRE 2020.1

//ATIVIDADE 02: ELABORAR PROGRAMA PARA LIGAR E DESLIGAR LEDS NA FORMA SEQUENCIAL REMOTAMENTE SIMULANDO UM CONTROLE EM MALHA ABERTA

/* ---------------------------- ---------------- ----------------------------*/
/* ---------------------------- CIRCUITO RECEPTOR ---------------------------*/
/* ---------------------------- ---------------- ----------------------------*/

//INICIO CABECALHO PADRAO
#include <18F4550.h>
#fuses HS, CPUDIV1,PLL5,USBDIV
#use delay(clock=20000000)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)

//DECLARACAO DE VARIAVEIS
int32 B; 
//INICIO DE PROGRAMA
void main(){
   
               while(true){
                  B = getc()-'0';
                           
                           if(B == 1){
                              output_high(0x7C08);
                              output_low(0x7C09);
                              output_low(0x7C0A);
                              output_low(0x7C0B);
                              output_low(0x7C0C);
                              output_low(0x7C0D);
                              output_low(0x7C0E);
                              output_low(0x7C0F);
                              }
                             
                            if(B == 2){
                              output_high(0x7C09);
                              output_low(0x7C08);
                              output_low(0x7C0A);
                              output_low(0x7C0B);
                              output_low(0x7C0C);
                              output_low(0x7C0D);
                              output_low(0x7C0E);
                              output_low(0x7C0F);
                              
                              }
                              
                            if(B == 3){
                              output_high(0x7C0A);
                              output_low(0x7C08);
                              output_low(0x7C09);
                              output_low(0x7C0B);
                              output_low(0x7C0C);
                              output_low(0x7C0D);
                              output_low(0x7C0E);
                              output_low(0x7C0F);
                              
                              }
                             
                            if(B == 4){
                              output_high(0x7C0B);
                              output_low(0x7C08);
                              output_low(0x7C09);
                              output_low(0x7C0A);
                              output_low(0x7C0C);
                              output_low(0x7C0D);
                              output_low(0x7C0E);
                              output_low(0x7C0F);
                              
                              }
                              
                            if(B == 5){
                              output_high(0x7C0C);
                              output_low(0x7C08);
                              output_low(0x7C09);
                              output_low(0x7C0A);
                              output_low(0x7C0B);
                              output_low(0x7C0D);
                              output_low(0x7C0E);
                              output_low(0x7C0F);
                              
                              }
                              
                            if(B == 6){
                              output_high(0x7C0D);
                              output_low(0x7C08);
                              output_low(0x7C09);
                              output_low(0x7C0A);
                              output_low(0x7C0B);
                              output_low(0x7C0C);
                              output_low(0x7C0E);
                              output_low(0x7C0F);
                              
                              }
                           
                            if(B == 7){
                              output_high(0x7C0E);
                              output_low(0x7C08);
                              output_low(0x7C09);
                              output_low(0x7C0A);
                              output_low(0x7C0B);
                              output_low(0x7C0C);
                              output_low(0x7C0D);
                              output_low(0x7C0F);
                              
                              }
                 
                           if(B == 8){
                              output_high(0x7C0F);
                              output_low(0x7C08);
                              output_low(0x7C09);
                              output_low(0x7C0A);
                              output_low(0x7C0B);
                              output_low(0x7C0C);
                              output_low(0x7C0D);
                              output_low(0x7C0E); 
                              }        
                    }
                     
               }

  //FIM DE PROGRAMA

