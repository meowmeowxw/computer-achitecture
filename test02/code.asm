mov ecx, num
dec ecx
mov eax, intArray[ecx * 4]
mov ebx, intArray[ecx * 4 - 4]
call mcde
dec ecx
ciclo : mov ebx, intArray[ecx * 4 - 4]
		call mcde
		dec ecx
		cmp ecx, 0
		jne ciclo
		jmp fine

mcde :	cmp     ebx, eax; ebx = smaller number
		jb      gcd0
		xchg    eax, ebx
		gcd0 :  xor     edx, edx; divide: larger / smaller
				div     ebx
				mov     eax, ebx; eax = new larger(was smaller)
				mov     ebx, edx; ebx = new smaller(new remainder)
				or ebx, ebx; loop if new smaller != 0
				jnz     gcd0
				; ; eax = gcd
				mov MCD, eax
				ret
fine: xor ecx,ecx
