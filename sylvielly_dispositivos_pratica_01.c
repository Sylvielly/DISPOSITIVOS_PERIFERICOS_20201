//=============================================================================
/*DISPOSITIVOS PERIFERICOS - S8 ENGENHARIA DE CONTROLE E AUTOMACAO*/
/*TRABALHO 01 - ENTREGA: 16/03/2020 - 
  CONTROLE PI DE VELOCIDADE DO MOTOR CC COM ACIONAMENTO VIA PWM*/
//ALUNA: SYLVIELLY S. SOUSA 

#include<18f4550.h>
#device  adc = 10                         //resolucao do adc 10 bits
#fuses HS, CPUDIV1,PLL5,USBDIV
#use delay(clock=20000000)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)        //configuracao serial
#define led0 pin_d0
#priority rda,timer0 

//variaveis para inserir valor de setpoint para PWM [MILHAR],[CENTENA],[DEZENA],[UNIDADE]
int32 m;
int32 c;       
int32 d;
int32 u;
signed long int porcentagem = 0;
signed long int PWM_CONFIG = 0;
signed long int digital_entrada=0;
signed long int proporcional=0;
signed long int erro=0;
signed long int saida_atual=0;
float KP = 0.1;
signed long int digital_velocidade = 0;
signed long int AD3=0;
static boolean led;
signed long int integral=0;
float KI=0.09;
signed long int fator;
signed long int setpoint_RPM=0;
signed long int INTEGRAL_SYS=0;
//float PWM_SET;

#int_rda                          //interrupcao para serial
void serial(){ 
   m=getc()-48;                  //48 corresponde ao valor do caractere 0 da tabela ASCII.
   c=getc()-48;                  //48 corresponde ao valor do caractere 0 da tabela ASCII.
   d=getc()-48;                  //48 corresponde ao valor do caractere 0 da tabela ASCII.
   u=getc()-48;                  //48 corresponde ao valor do caractere 0 da tabela ASCII.
                           
   setpoint_RPM=(1000*m)+(100*c)+(10*d)+(1*u);
   if (setpoint_RPM > 5000){
         setpoint_RPM = 5000;
      }
         digital_entrada = setpoint_RPM*0.2046;
   }

#int_timer0
void funcao_tempo(){
      static unsigned int32 n;
      set_timer0(131+get_timer0());
      n++;
      
      if (n==150){ 
            n=0;
            led=!led;
            output_bit(led0,led);
            
      //configuracao pi
     if(digital_velocidade>0){     
                  erro = digital_entrada - digital_velocidade;         
                  proporcional = KP*erro;
                  integral = (integral + erro);
                  INTEGRAL_SYS = (integral*KI);
            if (INTEGRAL_SYS>920.7){
                  INTEGRAL_SYS = 920.7;
               } 
            if((setpoint_RPM==0)&&(digital_velocidade==0)){
               saida_atual = 0;
           }
                     }
         
      }
      
      }
      
   
void main(){  
      
      //configuracao timer0 para execucao do controlador
         setup_timer_0 (RTCC_DIV_64|RTCC_INTERNAL | RTCC_8_BIT );
         set_timer0(131);
      
      //inicio configuracao portas analogicas
         setup_adc_ports(AN0_TO_AN3);
         setup_adc(adc_clock_internal);         //pino AN0 sera o pino onde o detectara velocidadeRPM 
         set_adc_channel(0);
      //fim configuracao portas analogicas
      
      //inicio habilitacao interrupcoes
         enable_interrupts(int_rda);            //interrupcao para serial
         enable_interrupts(global);
         enable_interrupts(INT_TIMER0);
      //fim habilitacao interrupcoes
  
      setup_timer_2(T2_DIV_BY_4, 249, 1);          //preparacao configuracao de PR2 para os pinos de PWM [CCP1]
   
   while(true){
   //inicio leitura entrada analogica de velocidade
            AD3 = read_adc();
            delay_us(100);
            digital_velocidade = AD3;                      //conversao da unidade de engenharia lida em AD3 para velocidade do motor
   //fim leitura entrada analogica de velocidade                   
                saida_atual = proporcional+INTEGRAL_SYS;                          
                PWM_CONFIG = (saida_atual*0.2443792766);               
            if(PWM_CONFIG>=250){
                  PWM_CONFIG = 250;
}
            if(PWM_CONFIG<0){
                  PWM_CONFIG = 0;
               }
               set_pwm1_duty(PWM_CONFIG);             //configura razao ciclica [duty cycle = ton / ton+toff]
               setup_ccp1(CCP_PWM);                   //envia valor pwm configurado para pino /ccp1
               
         printf("\r\n SETPOINT = %li \r\n ",setpoint_RPM);
         printf(" \r\n AD3 = %li \r\n ",AD3); 
         printf(" \r\n VELOCIDADE ATUAL = %li \r\n ",digital_velocidade*4.887585533)
         printf(" \r\n VALOR PWM = %li \r\n ",PWM_CONFIG);

         //fim configuracao pwm com condicao para 'pwm_config' para nao passar dos 250 (100% pwm)
         
   }        
} 
   
   
