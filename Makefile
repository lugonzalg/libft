# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lugonzal <lugonzal@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/29 17:18:21 by lugonzal          #+#    #+#              #
# Updated: 2021/05/29 17:18:27 by lugonzal               ###   ########.fr     #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
AR = ar rcs
RM = rm -f
INC = -I .

FILES = mem/ft_memset \
		mem/ft_bzero \
		mem/ft_memcpy \
		mem/ft_memccpy \
		mem/ft_memmove \
		mem/ft_memchr \
		mem/ft_memcmp \
		mem/ft_calloc \
		num/ft_atoi \
		num/ft_atoi_double \
		num/ft_itoa \
		num/ft_abs \
		str/ft_strmapi \
		str/ft_strlen \
		str/ft_strlcpy \
		str/ft_strlcat \
		str/ft_strchr \
		str/ft_strrchr \
		str/ft_strnstr \
		str/ft_strncmp \
		str/ft_strdup \
		str/ft_substr \
		str/ft_strjoin \
		str/ft_strtrim \
		str/ft_split_2 \
		is_checker/ft_isalpha \
		is_checker/ft_isdigit \
		is_checker/ft_isdigit_double \
		is_checker/ft_isalnum \
		is_checker/ft_isascii \
		is_checker/ft_isprint \
		to_some/ft_toupper \
		to_some/ft_tolower \
		fd/ft_putchar_fd \
		fd/ft_putstr_fd \
		fd/ft_putendl_fd \
		fd/ft_putnbr_fd \
		ft_printf/ft_printf \
		ft_printf/extra_printf \
		ft_printf/handle_types \
		ft_printf/writf \
		tools/scl_range \
		list/ft_lstnew \
		list/ft_lstadd_front \
		list/ft_lstsize \
		list/ft_lstlast \
		list/ft_lstadd_back \
		list/ft_lstdelone \
		list/ft_lstclear \
		list/ft_lstiter \
		list/ft_lstmap \
		tree/ft_tree_node_new \
		tree/ft_tree_node_insert \

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))

OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))


.c.o: $(SRCS)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
