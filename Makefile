# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcharlsi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/20 15:59:41 by hcharlsi          #+#    #+#              #
#    Updated: 2021/08/20 15:59:45 by hcharlsi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = minishell.c

MY_ENV_SRCS = init_my_env.c new_var.c add_var_back.c last_var.c get_var_value_from_env.c\
				print_my_env.c cpy_my_env.c free_my_env.c my_env_to_str.c
MY_ENV_DIR = my_env
MY_ENV_PATH = $(addprefix $(MY_ENV_DIR)/, $(MY_ENV_SRCS))
SRCS += $(MY_ENV_PATH)
DIRS += $(MY_ENV_DIR)

PARSER_SRCS = parser.c get_var_name.c check_quotes.c split_params.c delete_double_quotes.c\
				question_mark.c init_buf.c start_proc_dollar.c proc_dollar.c
PARSER_DIR = parser
PARSER_PATH = $(addprefix $(PARSER_DIR)/, $(PARSER_SRCS))
SRCS += $(PARSER_PATH)
DIRS += $(PARSER_DIR)

PROGRAMS_SRCS = program_execution.c my_echo.c my_cd.c my_pwd.c my_export.c my_unset.c \
				my_env.c my_exit.c find_builtin_program.c builtin_program_exec.c\
				update_pwd_and_old_pwd.c sort_env.c
PROGRAMS_DIR = programs
PROGRAMS_PATH = $(addprefix $(PROGRAMS_DIR)/, $(PROGRAMS_SRCS))
SRCS += $(PROGRAMS_PATH)
DIRS += $(PROGRAMS_DIR)

REDIRECT_SRCS = is_redirect.c find_redirect.c redirect_exec.c recovery_std_fd.c here_doc_exec.c\
				choose_redirect.c dup_std.c fd_error.c redirect_error.c
REDIRECT_DIR = redirect
REDIRECT_PATH = $(addprefix $(REDIRECT_DIR)/, $(REDIRECT_SRCS))
SRCS += $(REDIRECT_PATH)
DIRS += $(REDIRECT_DIR)

PIPES_SRCS = is_pipe.c find_pipe.c pipe_exec.c close_pipes_fd.c
PIPES_DIR = pipes
PIPES_PATH = $(addprefix $(PIPES_DIR)/, $(PIPES_SRCS))
SRCS += $(PIPES_PATH)
DIRS += $(PIPES_DIR)

UTILS_SRCS = utils.c
UTILS_DIR = utils
UTILS_PATH = $(addprefix $(UTILS_DIR)/, $(UTILS_SRCS))
SRCS += $(UTILS_PATH)
DIRS += $(UTILS_DIR)

SRCS_DIR = srcs
SRCS_PATH = $(addprefix $(SRCS_DIR)/, $(SRCS))

OBJS = $(patsubst %.c, %.o, $(SRCS))
OBJS_DIR = objs
OBJS_PATH = $(addprefix $(OBJS_DIR)/, $(OBJS))
CREATED_DIRS = $(addprefix $(OBJS_DIR)/, $(DIRS))

HEADERS = minishell.h my_env.h utils.h redirect.h parser.h
HEADERS_DIR = includes
HEADERS_PATH = $(addprefix $(HEADERS_DIR)/, $(HEADERS))

LIBFT = libft.a
LIBFT_DIR = libft

CC = gcc

FLAGS = -Wall -Werror -Wextra -g

RM = rm -rf

GREEN = \033[0;32m
RESET = \033[0m

all: $(NAME)

$(NAME): write_logo $(OBJS_PATH)
	@echo "$(GREEN)\nObjects were created $(RESET)"
	@make -sC $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) .
	@echo "$(GREEN)\nLibft was compiled $(RESET)"
	@$(CC) $(FLAGS) -I $(HEADERS_DIR) $(LIBFT) $(OBJS_PATH) -lreadline -o $@
	@echo "$(GREEN)minishell was compiled $(RESET)"

write_logo:
	@echo "$(GREEN)\n\
	███╗░░░███╗██╗███╗░░██╗██╗░██████╗██╗░░██╗███████╗██╗░░░░░██╗░░░░░\n\
	████╗░████║██║████╗░██║██║██╔════╝██║░░██║██╔════╝██║░░░░░██║░░░░░\n\
	██╔████╔██║██║██╔██╗██║██║╚█████╗░███████║█████╗░░██║░░░░░██║░░░░░\n\
	██║╚██╔╝██║██║██║╚████║██║░╚═══██╗██╔══██║██╔══╝░░██║░░░░░██║░░░░░\n\
	██║░╚═╝░██║██║██║░╚███║██║██████╔╝██║░░██║███████╗███████╗███████╗\n\
	╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝╚═════╝░╚═╝░░╚═╝╚══════╝╚══════╝╚══════╝\n\
	$(RESET)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADERS_PATH)
	@mkdir -p $(OBJS_DIR) $(CREATED_DIRS)
	@$(CC) $(FLAGS) -I $(LIBFT_DIR) -I $(HEADERS_DIR) -c $< -o $@
	@echo "$(GREEN).$(RESET)\c"

clean:
	@$(RM) $(OBJS_DIR)
	@$(RM) $(LIBFT)
	@make fclean -sC $(LIBFT_DIR)
	@echo "$(GREEN) clean instruction was executed $(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN) fclean instruction was executed $(RESET)"

re: fclean all

.PHONY: all clean fclean re write_logo
