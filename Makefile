# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: gpirro <gpirro@student.42.fr>                +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/08 15:30:05 by gpirro        #+#    #+#                  #
#    Updated: 2022/04/19 17:55:38 by gpirro        ########   odam.nl          #
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
OBJS	= 	${SRCS:.c=.o}
CC		= 	gcc
CFLAGS	= 	-Wall -Wextra -Werror -g

all: ${LIBFT} ${PRINTF} ${NAME}

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

${LIBFT}:
	make -C libft

clean:
	make clean -C libft
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME} ${LIBFT}

re: fclean all

.PHONY: all clean fclean re .c.o