xor ecx,ecx 
ciclo: mov eax,vet[ecx*4]
	popcnt ebx,eax
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
