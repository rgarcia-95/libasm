section .text						; Sección donde van las instrucciones
	global _ft_strcpy				; Para utilizarla en otras funciones
_ft_strcpy:							; Función
	push rdi						; Guarda en la pila la dirección de memoria de *dst (rdi)
loop:								; Instrucción que va a simular un bucle
	mov al, BYTE [rsi]				; al = *rsi
	mov BYTE [rdi], al				; *rdi = al
	inc rsi							; rsi++
	inc rdi							; rdi++
	cmp BYTE [rsi], 0				; Comprueba si ha llegado al final/está vacío
	jne loop						; Si no, vuelve a la instrucción loop
	mov BYTE [rdi], 0				; Copia el valor nulo
	pop rax							; Apunta rax hacia la dirección de memoria de rdi, ya modificado
	ret								; return (rax)