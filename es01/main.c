#include <stdio.h>

void main()
{
	unsigned short Num1 = 4;
	unsigned short Num2 = 0;
	unsigned int Prodotto;

	__asm
	{
		xor eax, eax
		mov cx,Num2 
		cmp cx,0
		je errore
ciclo : add ax,Num1 
		loop ciclo
		mov Prodotto,eax
errore : mov Prodotto,eax		
	}
	printf("%d\n", Prodotto);
	getchar();
}