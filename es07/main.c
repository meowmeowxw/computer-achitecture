#include <stdio.h>

void main()
{
	int Vettore[] = { 3,7,3,7,5,1,4,-3,-7,-9,2,6 };
	unsigned int Lung = sizeof(Vettore) / sizeof(Vettore[0]);

	__asm
	{
		mov edx, Lung
		dec edx; edx = pos
		ciclo1: mov ebx, Vettore[edx*4]; ebx = max
				mov edi, edx; edi = pos
				mov ecx, edx
		ciclo: dec ecx 
			   cmp ecx,-1
			   jle copia 
			   cmp ebx,Vettore[ecx*4]
			   jge ciclo
			   mov ebx,Vettore[ecx*4]
			   mov edi,ecx 
			   jmp ciclo 
		copia: mov esi,Vettore[edx*4]
			   mov Vettore[edx*4],ebx 
			   mov Vettore[edi*4],esi
			   dec edx 
			   cmp edx,0
			   jnz ciclo1
		fine: xor eax,eax 
	}
	for (int i = 0; i < Lung; ++i)
	{
		printf("Vettore[%d] is : %d\n", i, Vettore[i]);
	}
	getchar();
	
}