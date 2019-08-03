#include <stdio.h>

void main()
{
	unsigned int Num = 11259375;
	char Ris[8];

	__asm
	{
		xor edx,edx 
		xor ebx,ebx
		mov dl,7
		ciclo : mov eax,Num
		and eax,15 
		cmp eax,9
		jg valore 
		mov bl,48
		jmp shifta 
		valore:mov bl,55
		shifta: mov Ris[edx],bl
		add Ris[edx],al
		shr Num,4
		dec dl
		cmp dl,0
		jge ciclo
		fine : xor eax,eax 
	}
	unsigned int i;
	for (i = 0; i < 8; ++i)
	{
		printf("%c", Ris[i]);
	}
	puts("");
	getchar();
}