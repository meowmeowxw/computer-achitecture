#include <stdio.h>

void main()
{
	unsigned char stringa[] = "Questa è una stringa";
	int lunghezza = sizeof(stringa) - 1;
	unsigned char carattere = 'è';
	int i;

	__asm
	{
		xor edx,edx 
		mov ah,carattere
		ciclo: cmp edx,lunghezza 
				jge errore 
				mov bh,stringa[edx]
				cmp ah,bh
				je trovato 
				inc edx
				jmp ciclo
		errore: mov edx,-1
		trovato: mov i,edx  
	}
	printf("posizione : %d\n", i);
	getchar();
}