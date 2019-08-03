/********************************************************************************
*                                                                              *
*                   Architetture dei sistemi di Elaborazione                   *
*                                                                              *
********************************************************************************

Elaborato 3
Descrizione: Dato un array di DWORD, invertire l’ordine dei byte delle DWORD che
hanno un numero dispari di bit a uno (l’inversione consiste nel passaggio da
little-endian a big-endian).

********************************************************************************/

#include <stdio.h>

void main()
{
	// Vettore di DWORD da modificare
	unsigned int vet[] = { 11,0,1,2,3,4,5,6,7,8,9,10,-1,-2,-3,254 };
	// Numero di elementi del vettore
	unsigned int num = sizeof(vet) / sizeof(vet[0]);

	// Blocco assembler
    // Popcnt non può essere usata
	__asm
	{
		jmp inizio
	bitcount : mov eax,[esp+4]
			   sar eax,1 
			   and eax,0x55555555
			   sub [esp+4],eax 
			   mov eax,[esp+4]
			   and eax,0x33333333
			   mov edi,eax
			   mov eax,[esp+4]
			   sar eax,0x2 
			   and eax,0x33333333
			   add eax,edi 
			   mov [esp+4],eax 
			   mov eax,[esp+4]
			   sar eax,0x4
			   mov edi,eax
			   mov eax,[esp+4]
			   add eax,edi
			   and eax,0xf0f0f0f
			   imul eax,eax,0x1010101
			   sar eax,0x18
			   ret 
	inizio:	xor ecx,ecx 
				   ciclo: mov eax,vet[ecx*4]
				   push eax
			   call bitcount
			   mov ebx,eax
			   pop eax
			   mov eax,vet[ecx*4]
			   test ebx,1
			   jnz scambio 
			   inc ecx 
		controllo : cmp ecx,num
			   jng ciclo 
		jmp fine 
		scambio: bswap eax
			 mov vet[ecx*4],eax
			 inc ecx 
			 jmp controllo
		fine : xor eax,eax
	}
	printf("il primo numero : %d\n", vet[0]);
	// Stampa su video
	{
		unsigned int i;
		for (i = 0; i < num; i++)
			printf("0x%08X\n", vet[i]);
	}
	getchar();
}

