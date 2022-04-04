# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: gpirro <gpirro@student.42.fr>                +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/08 15:30:05 by gpirro        #+#    #+#                  #
#    Updated: 2022/04/04 16:33:18 by gpirro        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= 	fdf
VPATH	=	./drawing/ ./gnl/ ./list/ ./movement/ ./objs/
SRCS	=	fdf.c\
			input.c\
			drawing.c\
			drawline.c\
			movements.c\
			keypress.c\
			get_next_line_utils.c\
			get_next_line.c\
			list.c
LIBFT	= 	libft/libft.a
PRINTF	=	printf/libftprintf.a
OBJS	= 	${SRCS:.c=.o}
CC		= 	gcc
CFLAGS	= 	-g #-Wall -Wextra -Werror -g
OBJ_DIR	=	./objs/

all: ${LIBFT} ${PRINTF} ${NAME}

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT) $(PRINTF)
	mkdir -p ${OBJ_DIR}
	mv *.o ${OBJ_DIR}

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

${LIBFT}:
	make -C libft

${PRINTF}:
	make -C printf

clean:
	make clean -C libft
	make clean -C printf
	rm -rf ${OBJ_DIR}
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME} ${LIBFT} ${PRINTF}

re: fclean all

.PHONY: all clean fclean re .c.o