# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgarcia- <rgarcia-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/29 20:04:41 by rgarcia-          #+#    #+#              #
#    Updated: 2020/10/01 20:08:24 by rgarcia-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libasm.a

SRCS	=	ft_strlen.s				\
			ft_strcpy.s				\
			ft_strcmp.s				\
			ft_write.s				\
			ft_read.s				\
			ft_strdup.s				\

OBJS	=	$(SRCS:.s=.o)

NASM	=	nasm -fmacho64

FLAGS	=	-Wall -Werror -Wextra

COMP	=	gcc

RUN		=	&& ./a.out

REMOVE	=	rm -rf

%.o : %.s
			@$(NASM) $<

all		:	$(NAME)

$(NAME)	:	$(OBJS)
		@ar rcs $(NAME) $(OBJS)

clean	:
			@$(REMOVE) $(OBJS)

fclean	:	clean
			@$(REMOVE) $(NAME) main.o

re		:	fclean $(NAME)

t		:	main.c $(NAME) clean
			@clear
			@$(COMP) $(FLAGS) $< $(NAME) $(RUN)
			@$(REMOVE) $(NAME) a.out

.PHONY	:	clean fclean re t