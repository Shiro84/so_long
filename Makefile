# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matomas <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 16:53:51 by matomas           #+#    #+#              #
#    Updated: 2024/12/29 16:17:20 by matomas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Directorios
SRCDIR = srcs
OBJDIR = objects
HEADERDIR = include
LIBDIR = lib

# Librerías (Submódulos)
LIBFT = $(LIBDIR)/libft/libft.a
GNL = $(LIBDIR)/gnl/get_next_line.a
MLX = $(LIBDIR)/mlx/libmlx.a

# Headers
HEADERS = $(HEADERDIR)/so_long.h \
          $(LIBDIR)/gnl/get_next_line.h \
          $(LIBDIR)/libft/libft.h \
          $(LIBDIR)/mlx/mlx.h

# Archivos fuente
SOURCES = $(SRCDIR)/main.c \
	$(SRCDIR)/map/map_load.c \
	$(SRCDIR)/map/map_parse.c \
	$(SRCDIR)/map/map_draw.c \
	$(SRCDIR)/player/player_init.c \
	$(SRCDIR)/player/player_move.c \
	$(SRCDIR)/enemies/enemies_init.c \
	$(SRCDIR)/enemies/enemies_move.c \
	$(SRCDIR)/game/game_loop.c \
	$(SRCDIR)/game/game_exit.c

OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SOURCES))

# Compilación
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -I$(HEADERDIR) -I$(LIBDIR)/libft -I$(LIBDIR)/gnl -I$(LIBDIR)/mlx
LIB_FLAGS = -L$(LIBDIR)/libft -lft -L$(LIBDIR)/gnl -lgnl
MLX_FLAGS = -L$(LIBDIR)/mlx -lmlx -framework OpenGL -framework Appkit

# Colores mágicos
DEF_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
CYAN = \033[0;96m
PURPLE = \033[0;95m

# Reglas
all: dir sublibs libs $(NAME)

libs: mlx

sublibs: subgnl sublib

subgnl:
	@if [ ! -d "./lib/gnl/.git" ]; then \
        git clone git@github.com:Shiro84/gnl.git ./lib/gnl; \
        git submodule update --init --recursive; \
    elif [ -d "./lib/gnl/.git" ]; then \
        echo "[ Warnig ] libft: already exists and is a valid git repository."; \
    else \
        echo "[ Warnig ] libft: already exists and is not an empty directory."; \
    fi

sublib: 
	@if [ ! -d "./lib/libft/.git" ]; then \
        git clone git@github.com:Shiro84/libft.git ./lib/libft; \
        git submodule update --init --recursive; \
    elif [ -d "./lib/libft/.git" ]; then \
        echo "[ Warnig ] libft: already exists and is a valid git repository."; \
    else \
        echo "[ Warnig ] libft: already exists and is not an empty directory."; \
    fi


libft:
	@echo "$(YELLOW)Reuniendo sabiduría ancestral (libft)...$(DEF_COLOR)"
	@make -C $(LIBDIR)/libft

gnl:
	@echo "$(YELLOW)Descifrando pergaminos olvidados (get_next_line)...$(DEF_COLOR)"
	@make -C $(LIBDIR)/gnl

mlx:
	@echo "$(YELLOW)Forjando herramientas mágicas (MiniLibX)...$(DEF_COLOR)"
	@make -C $(LIBDIR)/mlx

dir:
	@mkdir -p $(OBJDIR) $(OBJDIR)/map $(OBJDIR)/player $(OBJDIR)/enemies $(OBJDIR)/game

print:
	@echo $(OBJECTS)
	@echo $(OBJDIR)
	@echo "------>$(SRCDIR)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	@echo "$(PURPLE)Cargando mundo...$(DEF_COLOR) $(BLUE)$<$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	@echo "$(CYAN)Preparando aventura...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIB_FLAGS) $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)El mundo está listo para la exploración: $(NAME)$(DEF_COLOR)"

clean:
	@echo "$(RED)Eliminando escombros del mundo...$(DEF_COLOR)"
	@make clean -C $(LIBDIR)/libft
	@make clean -C $(LIBDIR)/gnl
	@make clean -C $(LIBDIR)/mlx
	@rm -rf $(OBJDIR)
	@echo "$(GREEN)El mundo está limpio.$(DEF_COLOR)"

fclean: clean
	@echo "$(RED)Destruyendo reliquias antiguas (ejecutable)...$(DEF_COLOR)"
	@make fclean -C $(LIBDIR)/libft
	@make fclean -C $(LIBDIR)/gnl
	@rm -f $(NAME)
	@echo "$(GREEN)El ejecutable ha sido eliminado.$(DEF_COLOR)"

re: fclean all

.PHONY: all libs sublibs clean fclean re
