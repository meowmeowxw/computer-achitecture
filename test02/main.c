/********************************************************************************
*                                                                              *
*                   Architetture dei sistemi di Elaborazione                   *
*                                                                              *
********************************************************************************

Elaborato 2
Descrizione: Dato un array di interi senza segno, calcolare il loro M.C.D. (Massimo Comune Divisore).

********************************************************************************/

#include <stdio.h>

void main()
{
	// Input
	//Array di interi
	unsigned int intArray[] = {2,4,6,8,10,12,0};
	//Il numero di interi nell'array
	int num = sizeof(intArray) / sizeof(intArray[0]);

	// Output
	unsigned int MCD;

	__asm
	{
		mov ecx, num
		dec ecx
		mov eax, intArray[ecx * 4]
		mov ebx, intArray[ecx * 4 - 4]
		call mcde
		dec ecx
		cmp ecx,0
		jle fine
		ciclo : 
		mov ebx, intArray[ecx * 4 - 4]
				call mcde
				dec ecx
				cmp ecx, 0
				jne ciclo
				jmp fine
				mcde : cmp     ebx, eax //; ebx = smaller number
					   jb      gcd0
					   xchg    eax, ebx
			gcd0 : xor     edx, edx //; divide: larger / smaller
			cmp ebx,0
			je ritorno 
						div     ebx
						mov     eax, ebx // eax = new larger(was smaller)
						mov     ebx, edx // ebx = new smaller(new remainder)
						or ebx, ebx // loop if new smaller != 0
						jnz     gcd0
				ritorno:		mov MCD, eax
						ret
			fine : xor eax,eax
	}
	
	// Stampa su video
	printf("M.C.D.: %d \n", MCD);
	getchar();
}


 
