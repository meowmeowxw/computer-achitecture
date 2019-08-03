#include <stdio.h>

void main()
{
	unsigned int num = 1024;
	unsigned int ris;

	__asm
	{
		mov eax,num 
		mov ecx,0
		cmp eax,0
		je fine
		controllo : test eax,1
				jnz finecontrollo  
		errore : shr eax,1
				 jmp controllo 
		finecontrollo : cmp eax,1b 
				 jnz fine 
				 inc ecx 
		fine : mov ris,ecx  
	}
	printf("ris : %d\n", ris);
	getchar();
}