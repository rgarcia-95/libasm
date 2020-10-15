section .text							; Sección donde van las instrucciones
	global _ft_strlen					; Para utilizarla en otras funciones
_ft_strlen:								; Función
	mov rax, -1							; rax = -1
loop:									; Instrucción que va a simular un bucle
	inc rax								; rax++
	cmp BYTE [rdi + rax], 0				; Comprueba si está vacío/se ha llegado al final
	jne loop							; Si es distinto, vuelve a hacer el bucle
	ret									; return (rax)