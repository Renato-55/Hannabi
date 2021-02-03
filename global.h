#ifndef _GLOBALH_		//protectes from multiple including...
#define _GLOBALH_		//... needs an #endif at bottom

#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <locale.h>


#define NUMERODECORES	5
#define CARTASPORCOR 	10
#define TOTALCARTAS		50
#define HANDSIZE 		5	


// STRUCT
typedef struct carta_{
	int cor;
	int num;
	int vis;
	int jogavel_num;
	int jogavel_cor;
}carta;


// funcoes

void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds) 
        ; 
} 

void FullScreen()
{
	keybd_event ( VK_MENU, 0x36, 0, 0 ); 
 	keybd_event ( VK_RETURN, 0x1C, 0, 0 ); 
	keybd_event ( VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0 ); 
	keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 );

}






#endif
