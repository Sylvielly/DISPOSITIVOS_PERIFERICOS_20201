//=============================================================================

#include <18F4550.h>
#fuses HS, CPUDIV1,PLL5,USBDIV
#use delay(clock=20000000)
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)
#use standard_io(B) //comentar linha caso a biblioteca do LCD seja diferente
#define use_portB_lcd TRUE //comentar linha caso a biblioteca do LCD seja diferente
#define LCD_TYPE 2
#include <LCD.c>
int32 c;       //variaveis
int32 d;
int32 u;
unsigned int32 porcentagem = 0;
int32 null;
unsigned int32 value = 0;

#int_rda
void serial(){ 
   c=getc()-48; //48 corresponde ao valor do caractere 0 da tabela ASCII.
   d=getc()-48;//48 corresponde ao valor do caractere 0 da tabela ASCII.
   u=getc()-48;//48 corresponde ao valor do caractere 0 da tabela ASCII.
   //null=getc()-48;//descarta caractere nulo/indevido caso seja enviado pela serial
   porcentagem=(100*c)+(10*d)+u;
   
   if (porcentagem > 100)
      {
         porcentagem = 100;
      }
}
void main(){  
   enable_interrupts(int_rda);
   enable_interrupts(global);
   lcd_init();
   printf("\r\nDigite a velocidade:\r\n");
   setup_timer_2(T2_DIV_BY_4, 249, 1);          //preparacao 
   
   while(true){
      value = (porcentagem*250)/100;
      set_pwm1_duty(value);
      setup_ccp1(CCP_PWM);
   
   
    lcd_gotoxy(1,1);
    printf(lcd_putc,"\f Vel = %lu", porcentagem);
    lcd_gotoxy(1,2);
    printf(lcd_putc," Rot = %lu ",value);
   } 
}
