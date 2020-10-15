section .text						; Sección donde van las instrucciones
	global _ft_strcmp				; Para utilizarla en otras funciones
_ft_strcmp:							; Función
	mov rax, 0						; rax = 0
loop:								; Instrucción que va a simular un bucle
	mov al, BYTE [rdi]				; al = *rdi
	mov bl, BYTE [rsi]				; bl = *rsi
	cmp al, 0						; Comprueba si se ha llegado al final/está vacío
	je operation					; Si sí, llama a la instrucción
	cmp bl, 0						; Comprueba si se ha llegado al final/está vacío
	je operation					; Si sí, llama a la instrucción
	cmp al, bl						; Compara los dos caracteres
	jne operation					; Si son distintos, llama a la instrucción
	inc rdi							; rdi++
	inc rsi							; rsi++
	jmp loop						; Llama de nuevo al bucle para seguir comparando
operation:							; Instrucción que calcula la diferencia
	cmp al, bl						; Comprueba la diferencia
	ja positive						; Si es mayor al, llama a la instrucción
	jb negative						; Si es mayor bl, llama a la instrucción
	ret								; return (rax)
positive:							; Instrucción si s1 > s2
	mov rax, 1						; rax = 1
	ret								; return (rax)
negative:							; Instrucción si s1 < s2
	mov rax, -1						; rax = -1
	ret								; return (rax)