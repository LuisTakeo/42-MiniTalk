CC = cc
FLAGS = -Wextra -Wall -Werror

LIBS_FOLDER = ./libs
LIBFT = $(LIBS_FOLDER)/libft
LIBS = $(LIBFT)/libft.a

NAME = client
NAME_B = client_bonus
NAME_SERVER = server
NAME_SERVER_B = server_bonus


INCLUDES = -I ./
HEADER_CLIENT = client.h
HEADER_SERVER = server.h
HEADER_CLIENT_B = client_bonus.h
HEADER_SERVER_B = server_bonus.h

SRC_CLIENT = client.c
SRC_SERVER = server.c
SRC_CLIENT_B = client_bonus.c
SRC_SERVER_B = server_bonus.c

OBJS_CLIENT = ${SRC_CLIENT:%.c=%.o}
OBJS_SERVER = ${SRC_SERVER:%.c=%.o}
OBJS_CLIENT_B = ${SRC_CLIENT_B:%.c=%.o}
OBJS_SERVER_B = ${SRC_SERVER_B:%.c=%.o}

all: libft $(NAME) $(NAME_SERVER)
	@echo "Pronto!"
	@echo "Utilize './$(NAME_SERVER)' para obter o PID do server."
	@echo "Utilize './$(NAME) <PID> <text_message>' para enviar uma mensagem ao server."

bonus: libft $(NAME_B) $(NAME_SERVER_B)
	@echo "Pronto!"
	@echo "Utilize './$(NAME_SERVER_B)' para obter o PID do server."
	@echo "Utilize './$(NAME_B) <PID> <text_message>' para enviar uma mensagem ao server."

libft:
	@echo "Compilando Libft..."
	@make all bonus new_fun -C $(LIBFT) $(FLAGS) --no-print-directory

%.o: %.c %.h
	@$(CC) $(FLAGS) -o $@ -c $< && echo "Compilando: $(notdir $<)"

$(NAME): $(OBJS_CLIENT)
	@echo "Criando ./$(NAME)"
	@$(CC) $(OBJS_CLIENT) $(LIBS) $(INCLUDES) -o $(NAME)
	@echo "Concluido!"

$(NAME_SERVER): $(OBJS_SERVER)
	@echo "Criando ./$(NAME_SERVER)"
	@$(CC) $(OBJS_SERVER) $(LIBS) $(INCLUDES) -o $(NAME_SERVER)
	@echo "Concluido!"

$(NAME_B): $(OBJS_CLIENT_B)
	@echo "Criando arquivo $(NAME_B)"
	@$(CC) $(OBJS_CLIENT_B) $(LIBS) $(INCLUDES) -o $(NAME_B)
	@echo "Concluido!"

$(NAME_SERVER_B): $(OBJS_SERVER_B)
	@echo "Criando ./$(NAME_SERVER_B)"
	@$(CC) $(OBJS_SERVER_B) $(LIBS) $(INCLUDES) -o $(NAME_SERVER_B)
	@echo "Concluido!"

clean:
	@echo "Limpando objects..."
	@rm -rf $(OBJS_CLIENT) $(OBJS_CLIENT_B) $(OBJS_SERVER) $(OBJS_SERVER_B)
	@make clean -C $(LIBFT) --no-print-directory
	@echo "Feito!"


fclean: clean
	@echo "Removendo libft.a..."
	@make fclean -C $(LIBFT) --no-print-directory
	@echo "Removendo executáveis..."
	@rm -rf $(NAME) $(NAME_B) $(NAME_SERVER) $(NAME_SERVER_B)
	@echo "Feito!"

re: fclean all

.PHONY: all, clean, fclean, re, libmlx
