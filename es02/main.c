#include <stdio.h>

void main()
{
	unsigned int Num = 1089;
	unsigned int Radice;

	__asm
	{
		xor eax,eax
		xor ecx,ecx
		xor ebx,ebx
		mov ebx,0h 
		mov eax,Num
		mov ecx,1h
	ciclo : sub eax,ecx
			inc ebx
			inc ecx
			inc ecx 
			cmp eax,0
			jge ciclo 
			dec ebx
			mov Radice,ebx 		
	}
	printf("%d\n", Radice);
	getchar();
}

/*
__asm
{
	mov eax, Num1
	xor ebx, ebx
	mov ecx, 1
	ciclo : sub eax, ecx
			cmp eax, 0
			jge l2
			jmp l3
			l2 : inc ebx
				 add ecx, 2
				 jmp ciclo
				 l3 : mov radice, ebx

}
*/