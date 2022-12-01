ECHO = @echo
PRINT = @printf
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
INVERT = \033[7m
RESETTXT = \033[0m
BOLD = \033[1m

SRC_PATH = src/
SRC = philo_main.c routine.c data_manager.c arg_checker.c thread_handler.c str_1.c \
ft_atoi.c philo_init.c utils.c data_free.c time_handler.c
SRCS = $(addprefix $(SRC_PATH),$(SRC))

OBJ_PATH = obj/
OBJ = $(SRC:%.c=%.o)
OBJS = $(addprefix $(OBJ_PATH),$(OBJ))

NAME	= philo
AR 		= ar rcs
CC		= gcc
RM		= rm -f

INCLUDES = -I includes/

OPTIONS = -pthread
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		$(ECHO) "$(YELLOW)Compilation de philo...$(RESETTXT)"
		@gcc $(CFLAGS) $(INCLUDES) $(OPTIONS) $(OBJS) -o $@
		$(ECHO) "$(GREEN)$(BOLD)Compilation Terminée !!!$(RESETTXT)"

%.o:$(SRC_PATH)%.c
		$(PRINT) "$(YELLOW)Generation des objets...$(RESETTXT)\r"
		@mkdir -p $(OBJ_PATH)
		@$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $(OBJ_PATH)$@

clean:
		$(ECHO) "$(RED)Suppression des objets...$(RESETTXT)"
		@$(RM) $(OBJS)
		$(ECHO) "$(GREEN)$(BOLD)Terminé !$(RESETTXT)"

fclean:	clean
		$(ECHO) "$(RED)Suppression de philo...$(RESETTXT)"
		@$(RM) $(NAME)
		$(ECHO) "$(GREEN)$(BOLD)Terminé !$(RESETTXT)"

re:		fclean all

.PHONY: all clean fclean re