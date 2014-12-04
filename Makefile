##
## Makefile for my_ls in /home/barrau_h/Desktop/my_ls
## 
## Made by Hippolyte Barraud
## Login   <barrau_h@epitech.net>
## 
## Started on  Thu Nov 27 04:49:13 2014 Hippolyte Barraud
## Last update Sun Nov 30 17:38:06 2014 Hippolyte Barraud
##

CC = 		gcc

RM = 		rm -f

CFLAGS += 	-Wextra -Wall -Werror

CFLAGS += 	-pedantic

CFLAGS += 	-I.

NAME = 		my_ls

SRCS =		my_ls.c \
		query_parser/query_parser.c \
		query_parser/select_bool.c \
		fs_reader/fs_reader.c \
		fs_reader/link.c \
		fs_reader/dir.c \
		sorting/sorting.c \
		sorting/sorting_alpha.c \
		sorting/sorting_date.c \
		format/format.c \
		format/columns.c \
		format/format_types.c \
		utils/utils.c \
		utils/utils2.c \
		my_printf/helper_flag.c \
		my_printf/helper_format.c \
		my_printf/helper_num.c \
		my_printf/helper_string.c \
		my_printf/my_printf.c

OBJS = 		$(SRCS:.c=.o)

all: 		$(NAME)

$(NAME): 	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
