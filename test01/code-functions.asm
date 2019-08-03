jmp inizio 
	lunghezza: xor ecx, ecx // ritorna lunghezza
			   xor al, al
			   not ecx
			   cld
			   repne scasb
			   not ecx
			   lea eax, [ecx - 1]
			   ret
	copia : repe movsb
			ret
	compara :  repe cmpsb
			   mov eax,ecx
			fine: ret

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
				xor ecx,ecx
				xor edx,edx
	ciclo:		lea edi,str1 // [esp] = len(str2), [esp+4] = len(str1), [esp+8] = len(stringa)
				lea esi,[stringa+ebx]
				mov ecx,[esp+4]
				inc ecx
				call compara 
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
					call copia 
					add ebx,[esp+4]
					add edx,[esp]
		controllo :cmp ebx,[esp+8]
					jl ciclo
					add esp,12
					mov risultato[edx],0
