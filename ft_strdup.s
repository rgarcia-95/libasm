extern _malloc						; Para poder utilizar la función
extern _ft_strlen					; Para poder utilizar la función
extern _ft_strcpy					; Para poder utilizar la función
section .text						; Sección donde van las instrucciones
	global _ft_strdup				; Para utilizarla en otras funciones
_ft_strdup:							; Función
	cmp rdi, 0						; Comprueba que la cadena a copiar no está vacía
	je end							; Si está vacía, llama a la instrucción
	push rdi						; Almacena la cadena en la pila
	call _ft_strlen					; Calcula el tamaño del String a copiar
	mov rdi, rax					; rdi = rax (Tamaño del String)
	inc rdi							; rdi++ (Para el valor nulo)
	call _malloc					; Reserva memoria para el String donde se va a copiar
	cmp rax, 0						; Comprueba si ha fallado el malloc
	je end							; En caso de que sí, llama a la instrucción
	mov rdi, rax					; rdi = rax
	pop rsi							; Recupera el valor de la pila y lo almacena en rsi
	call _ft_strcpy					; Copia la cadena
	ret								; return (rax)
end:								; Instrucción para devolver 0
	mov rax, 0						; rax = 0
	ret								; return (rax)