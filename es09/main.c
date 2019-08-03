#include <stdio.h>

void main()
{
	unsigned int Num = 9;
	int Ris; 

	__asm
	{
		xor edx,edx
		mov eax,Num
		mov ecx,eax
		cmp eax,2
		je primo
		cmp eax,2
		jl no_primo 
		cdq
		mov ebx,2
		div ebx
		mov esi,eax
		mov edi,2
		ciclo : mov eax,Num
				cdq
				mov ebx,edi 
				div ebx
				cmp edx,0
				je no_primo 
				inc edi 
				cmp edi,esi 
				jl ciclo 
				primo: mov Ris,1
			   jmp fine 
			   no_primo: mov Ris,0
				  jmp fine 
		fine:xor ebx,ebx 
	}
	(Ris) ? puts("primo") : puts("no primo");
	getchar();
}