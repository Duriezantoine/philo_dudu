NAME	:= philo
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Ofast -g #
# CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -Og -g -pthread -fsanitize=thread

CC	:= cc


HEADERS	:= -I ./include

SRCS	:= ./src/main.c \
	./src/parsing.c \
	./src/init_philo.c \
	./src/while_philo.c \
	./src/ft_printf_monitoring.c \
	./src/time.c \
	./src/utils_libft.c \

OBJS	:= ${SRCS:.c=.o}

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(HEADERS) -o $(NAME) #-fsanitize=address

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: clean all

gdb: all
	gdb --tui ./$(NAME) $(MAP)

run: all
	./$(NAME) $(MAP)

.PHONY: all, clean, fclean, re, gdb, run
