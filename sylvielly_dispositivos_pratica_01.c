#include <18F4550.h>
#define led pin_d0 
#fuses HS, CPUDIV1,PLL5,USBDIV
#use delay(clock=20000000)
#use standard_io(B) //comentar linha caso a biblioteca do LCD seja diferente
#define use_portB_lcd TRUE //comentar linha caso a biblioteca do LCD seja diferente
#define LCD_TYPE 2
#include <LCD.c>
#use rs232(baud=9600, xmit=PIN_C6, rcv=PIN_C7)


void main()
   {  
      lcd_init();
         while(true)
            {
               char selection;
               printf("\r\nSelecione:\r\n");
               printf(" 1) L - ligar led \r\n");
               printf(" 2) D - desligar led \r\n");
               
               do {
                     selection=getc();
                  } 
                  while (!((selection=='L')||(selection=='D')));
                        if (selection=='L')
                        {
                           output_high(led);
                           lcd_gotoxy(1,1);
                           printf(lcd_putc,"\rLED LIGADO\r  ", );
                           
                        }
                        else
                        {
                           output_low(led);
                           lcd_gotoxy(1,1);
                           printf(lcd_putc,"\rLED DESLIGADO\r  ", );

                        }     
   
            }
}
   

