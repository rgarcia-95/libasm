/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 20:05:10 by rgarcia-          #+#    #+#             */
/*   Updated: 2020/10/06 19:19:55 by rgarcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

int		main(void)
{
	int		ret;
	char	dstcpy[100];
	char	dstft_cpy[100];
	char	*aux = "Pruebas Libasm.";
	char	buffer[4096];

	printf("   strlen: <%zu>\n", strlen(aux));
	printf("ft_strlen: [%zu]\n", ft_strlen(aux));
	printf("\n");
	printf("   strcpy: <%s>\n", strcpy(dstcpy, aux));
	printf("ft_strcpy: [%s]\n", ft_strcpy(dstft_cpy, aux));
	printf("\n");
	printf("   strcmp: <%i>\n", strcmp("Pruebas", "Pruebas"));
	printf("ft_strcmp: [%i]\n", ft_strcmp("Pruebas", "Pruebas"));
	printf("\n");
	printf("   strdup: <%s>\n", strdup(aux));
	printf("ft_strdup: [%s]\n", ft_strdup(aux));
	printf("\n");
	printf("   write:\n");
	write(1, aux, ft_strlen(aux));
	printf("\n");
	printf("ft_write:\n");
	ft_write(1, aux, ft_strlen(aux));
	printf("\n");
	printf("\n");
	printf("   read:\n");
	ret = read(0, buffer, 4096);
	buffer[ret - 1] = 0;
	printf("<%s>\n", buffer);
	printf("ft_read:\n");
	ret = ft_read(0, buffer, 4096);
	buffer[ret - 1] = 0;
	printf("[%s]\n", buffer);
	return (0);
}

/*#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

void	check_ft_strlen()
{
	char *empty = "";
	char *hello_world = "Hello world !";
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";
	printf("\n\n===================================\n");
	printf("============== STRLEN =============\n");
	printf("===================================\n\n");	
	printf("%-20s: \"%s\"\n","Empty", empty);
	printf("%-20s: \"%zu\"\n", "libc", strlen(empty));
	printf("%-20s: \"%zu\"\n", "libasm", ft_strlen(empty));
	printf("\n");
	printf("%-20s: \"%s\"\n","hello_world", hello_world);
	printf("%-20s: \"%zu\"\n", "libc", strlen(hello_world));
	printf("%-20s: \"%zu\"\n", "libasm", ft_strlen(hello_world));
	printf("\n");	
	printf("%-20s: \"%s\"\n","Alphabet", alphabet);
	printf("%-20s: \"%zu\"\n", "libc", strlen(alphabet));
	printf("%-20s: \"%zu\"\n", "libasm", ft_strlen(alphabet));
}
void clear_buffer(char *buffer, int size)
{
	int i = 0;
	while (i < size)
		buffer[i++] = 0;
}
void	check_ft_strcpy()
{
	char buffer[30];
	
	char *empty = "";
	char *hello_world = "Hello world !";
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";
	
	printf("\n\n=============================\n");
	printf("========== STRCPY ===========\n");
	printf("=============================\n\n");
	printf("%-20s: \"%s\"\n", "str", empty);
	printf("%-20s: buffer[50]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, empty));	
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, empty));	
	clear_buffer(buffer, 30);
	printf("\n");
	printf("%-20s: \"%s\"\n", "str", hello_world);
	printf("%-20s: buffer[50]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, hello_world));	
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, hello_world));	
	clear_buffer(buffer, 30);
	printf("\n");
	printf("%-20s: \"%s\"\n", "str", alphabet);
	printf("%-20s: buffer[50]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, alphabet));	
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, alphabet));
	clear_buffer(buffer, 30);
	printf("\n");
}
void	check_ft_strcmp()
{
	char	*s1 = "Hi";
	char	*s2 = "Checkin";
	char	*empty = "";

	printf("\n\n===================================\n");
	printf("============== STRCMP =============\n");
	printf("===================================\n\n");
	printf("Dif str:\n");
	printf("%-20s: \"%i\"\n", "libc", strcmp(s1, s2));	
	printf("%-20s: \"%i\"\n", "libasm", ft_strcmp(s1, s2));
	printf("\n");
	printf("Same str:\n");
	printf("%-20s: \"%i\"\n", "libc", strcmp(s1, s1));	
	printf("%-20s: \"%i\"\n", "libasm", ft_strcmp(s1, s1));
	printf("\n");
	printf("Empty str:\n");
	printf("%-20s: \"%i\"\n", "libc", strcmp(empty, s1));	
	printf("%-20s: \"%i\"\n", "libasm", ft_strcmp(empty, s1));
}
void	check_ft_read()
{
	char	buffer[900];
	int 	fd;
	int 	rlibc;
	int		rlibasm;
	printf("\n\n====================================\n");
	printf("============== FT_READ =============\n");
	printf("====================================\n\n");
	printf("====Open field try ====>\n");
	printf("\n");
	fd = open("main.c", O_RDONLY);
	rlibc = read(fd, buffer, 50);
	rlibasm = ft_read(fd, buffer, 50);
	printf("%-20s: \"%d\"\n", "libc", rlibc);	
	printf("%-20s: \"%d\"\n", "libasm", rlibasm);
	close(fd);
	printf("\n");
	printf("====Text try ====>\n");
	printf("\n");
	fd = open("hola", O_RDONLY);
	rlibc = read(fd, buffer, 890);
	printf("%-20s: \"%d\"\n", "libc", rlibc);
	close(fd);
	
	fd = open("hola", O_RDONLY);
	rlibasm = ft_read(fd, buffer, 890);
	printf("%-20s: \"%d\"\n", "libasm", rlibasm);
	close(fd);	
	
	printf("====Crash try ====>\n");
	printf("\n");
	fd = open("wrong", O_RDONLY);
	rlibc = read(fd, buffer, 890);
	perror("read errno");
	printf("%-20s: \"%d\"\n", "libc", rlibc);	
	close(fd);
	printf("\n");	
	errno = 50;
	fd = open("wrong", O_RDONLY);
	rlibasm = ft_read(fd, buffer, 890);
	perror("ft_read errno");
	printf("%-20s: \"%d\"\n", "libasm", rlibasm);
	close(fd);
	printf("\n");
	
	printf("====Screen try ====>\n");
	printf("\n");
	rlibc = read(0, buffer, 890);
	printf("%-20s: \"%d\"\n", "libc", rlibc);	
	close(fd);
	printf("\n");	
	rlibasm = ft_read(0, buffer, 890);
	printf("%-20s: \"%d\"\n", "libasm", rlibasm);
	close(fd);
}
void	check_ft_write()
{
	char	buffer[900];
	int 	fd;
	int 	rlibc;
	int		rlibasm;
	printf("\n\n=====================================\n");
	printf("============== FT_WRITE =============\n");
	printf("=====================================\n\n");
	printf("====First try ====>\n");
	printf("\n");
	fd = open("hola", O_WRONLY);
	rlibc = write(fd, buffer, 890);
	printf("%-20s: \"%d\"\n", "libc", rlibc);		
	close(fd);
	
	fd = open("hola", O_WRONLY);
	rlibasm = ft_write(fd, buffer, 890);
	printf("%-20s: \"%d\"\n", "libasm", rlibasm);	
	close(fd);
	printf("\n");

	printf("====Crash try ====>\n");
	printf("\n");
	fd = open("wrong", O_WRONLY);
	rlibc = write(fd, buffer, 890);
	perror("write errno");
	printf("%-20s: \"%d\"\n", "libc", rlibc);	
	close(fd);
	printf("\n");
	
	errno = 50;
	fd = open("wrong", O_WRONLY);
	rlibasm = ft_write(fd, buffer, 890);
	perror("ft_write errno");
	printf("%-20s: \"%d\"\n", "libasm", rlibasm);	
	close(fd);
	printf("\n");
	
	printf("====Screen try ====>\n");
	printf("\n");
	rlibc = write(1, buffer, 890);
	printf("%-20s: \"%d\"\n", "libc", rlibc);
	close(fd);
	
	rlibasm = ft_write(1, buffer, 890);
	printf("%-20s: \"%d\"\n", "libasm", rlibasm);	
	close(fd);	
	printf("\n");
}
void	check_ft_strdup()
{
	char *hello_world = "Hello world !";
	char *empty = "";
	char *save;
	char *save2;
	
	printf("\n\n================================\n");
	printf("========== FT_STRDUP ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	save = strdup(hello_world);
	printf("%-20s: \"%s\"\n", "libc", save);
	free(save);
	save = NULL;
	save2 = ft_strdup(hello_world);
	printf("%-20s: \"%s\"\n", "libasm", save2);
	free(save2);
	save2 = NULL;
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", empty);
	save = strdup(empty);
	printf("%-20s: \"%s\"\n", "libc", save);
	free(save);
	save = NULL;
	save2 = ft_strdup(empty);
	printf("%-20s: \"%s\"\n", "libasm", save2);
	free(save2);
	save2 = NULL;
	printf("\n");
}
int		main(void)
{
	check_ft_strlen();
	check_ft_strcpy();
	check_ft_strcmp();
	check_ft_read();
	check_ft_write();
	check_ft_strdup();
	return (0);
}*/
