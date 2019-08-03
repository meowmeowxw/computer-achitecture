/********************************************************************************
*                                                                              *
*                   Architetture dei sistemi di Elaborazione                   *
*                                                                              *
********************************************************************************

Elaborato 1
Descrizione: Sostituire tutte le occorrenze di una sottostringa all’interno di una stringa.
Ad esempio (“Questa stringa è una stringa”,“stringa”,”mela”)->“Questa mela è una mela”.

********************************************************************************/

#include <stdio.h>

void main()
{
	// Input
	// La stringa da modificare
	char stringa[1024] = "questa stringa e' una stringa";
	char str1[] = "stringa";	// la sottostringa da cercare
	char str2[] = "mela";	// la sottostringa con cui sostituirla

	// Output
	char risultato[1024] = ""; // La stringa modificata
	
	__asm
	{
		jmp inizio 
	lunghezza: xor ecx, ecx // ritorna lunghezza
			   xor al, al
			   not ecx
			   cld
			   repne scasb
			   not ecx
			   lea eax, [ecx - 1]
			   ret
				inizio : lea edi,stringa
				call lunghezza 
				push eax 
				lea edi,str1 
				call lunghezza
				push eax
				lea edi,str2
				call lunghezza
				push eax
				xor ebx,ebx
				xor edx,edx
	ciclo:		lea edi,str1 // [esp] = len(str2), [esp+4] = len(str1), [esp+8] = len(stringa)
				lea esi,[stringa+ebx]
				mov ecx,[esp+4]
				inc ecx
				repe cmpsb
				mov eax,ecx
				cmp eax,0
				je copia_stringa  
				mov al, stringa[ebx]
				mov risultato[edx],al
				inc edx
				inc ebx
				jmp controllo 
	copia_stringa : lea edi,risultato[edx]
					lea esi,str2 
					mov ecx,[esp]
					repe movsb
					add ebx,[esp+4]
					add edx,[esp]
		controllo :cmp ebx,[esp+8]
					jl ciclo
					add esp,12
					mov risultato[edx],0
	}

	// Stampa su video
	printf("Nuova stringa: %s\n", risultato);
	getchar();
}

 
