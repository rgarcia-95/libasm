extern ___error						; Para poder utilizar la función
section .text						; Sección donde van las instrucciones
	global _ft_write				; Para utilizarla en otras funciones
_ft_write:							; Función
	mov rax, 0x2000004				; rax = 0x2000004
	syscall							; Hace una llamada al sistema para escribir (versión de 64 bits de int 80h)
	jc _error						; Si hay algún error al escribir, llama a la instrucción
	jmp return						; Si no hay ningún error, salta a la instrucción
_error:								; Instrucción que gestiona el error
	mov r15, rax					; r15 = rax (Valor devuelto al escribir)
	call ___error					; Llama a la función para identificar el error
	mov [rax], r15					; &rax = r15 (Identificador del tipo de error)
	mov rax, -1						; rax = -1
	ret								; return (rax)
return:								; Instrucción que devuelve el valor escrito si la escritura ha ido bien
	ret								; return (rax)