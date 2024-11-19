/*
 * EVM_PROJICT.c
 *
 * Created: 10/10/2024 8:07:14 AM
 *  Author: ghada_momen
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "LCD.h"
#include "BUTTUM.h"

unsigned char buttun1 = 0;
unsigned char buttun2 = 0;
unsigned char buttun3 = 0;
unsigned char buttun4 = 0;

void update_display() {
   
    LCD_Move_Cursor(1, 3);
    if (buttun1 < 10) {
        LCD_Send_data('0');
        LCD_Send_data(buttun1 + 48);
    } else {
        LCD_Send_data(buttun1 / 10 + 48);
        LCD_Send_data(buttun1 % 10 + 48);
    }

    LCD_Move_Cursor(1, 14);
    if (buttun2 < 10) {
        LCD_Send_data('0');
        LCD_Send_data(buttun2 + 48);
    } else {
        LCD_Send_data(buttun2 / 10 + 48);
        LCD_Send_data(buttun2 % 10 + 48);
    }

    LCD_Move_Cursor(2, 3);
    if (buttun3 < 10) {
        LCD_Send_data('0');
        LCD_Send_data(buttun3 + 48);
    } else {
        LCD_Send_data(buttun3 / 10 + 48);
        LCD_Send_data(buttun3 % 10 + 48);
    }

    LCD_Move_Cursor(2, 14);
    if (buttun4 < 10) {
        LCD_Send_data('0');
        LCD_Send_data(buttun4 + 48);
    } else {
        LCD_Send_data(buttun4 / 10 + 48);
        LCD_Send_data(buttun4 % 10 + 48);
    }
}

int main(void)
{
    LCD_Initial();
    BUSH_BUTT_Initil('B', 3);
    BUSH_BUTT_Initil('B', 4);
    BUSH_BUTT_Initil('B', 5);
    BUSH_BUTT_Initil('B', 6);
    BUSH_BUTT_Initil('B', 7);

    LCD_Send_String("A=00");
    LCD_Move_Cursor(1, 12);
    LCD_Send_String("B=00");
    LCD_Move_Cursor(2, 1);
    LCD_Send_String("C=00");
    LCD_Move_Cursor(2, 12);
    LCD_Send_String("D=00");

    while (1)
    {
        if (BUSH_BUTT_READ('B', 3) == 1)
        {
            buttun1++;
            if (buttun1 >= 100) buttun1 = 0; 
            update_display();
        }
        else if (BUSH_BUTT_READ('B', 4) == 1)
        {
            buttun2++;
            if (buttun2 >= 100) buttun2 = 0; 
            update_display();
        }
        else if (BUSH_BUTT_READ('B', 5) == 1)
        {
            buttun3++;
            if (buttun3 >= 100) buttun3 = 0; 
            update_display();
        }
        else if (BUSH_BUTT_READ('B', 6) == 1)
        {
            buttun4++;
            if (buttun4 >= 100) buttun4 = 0; 
            update_display();
        }
        else if (BUSH_BUTT_READ('B', 7) == 1)
        {
            buttun1 = buttun2 = buttun3 = buttun4 = 0;
            update_display();
        }
        _delay_ms(30); // delay 
    }
}
