extern ___error						; Para poder utilizar la función
section .text						; Sección donde van las instrucciones
	global _ft_read					; Para utilizarla en otras funciones
_ft_read:							; Función
	mov rax, 0x2000003				; rax = 0x2000003
	syscall							; Hace una llamada al sistema para leer (versión de 64 bits de int 80h)
	jc _error						; Si hay algún error al leer, llama a la instrucción
	jmp return						; Si no hay ningún error, salta a la instrucción
_error:								; Instrucción que gestiona el error
	mov r15, rax					; r15 = rax (Valor devuelto al leer)
	call ___error					; Llama a la función para identificar el error
	mov [rax], r15					; &rax = r15 (Identificador del tipo de error)
	mov rax, -1						; rax = -1
	ret								; return (rax)
return:								; Instrucción que devuelve el valor leído si la lectura ha ido bien
	ret								; return (rax)