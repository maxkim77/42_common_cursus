# Program for compiling C programs
CC      := cc
CFLAGS  := -Wall -Wextra -Werror
INCLUDES:= -I. -Ilibft

RM      := /bin/rm -f

NAME_SERVER := server
NAME_CLIENT := client

# =============================================================================
# Sources / Objects
# =============================================================================
SRC_SERVER       := server.c minitalk.c
SRC_CLIENT       := client.c minitalk.c
SRC_SERVER_BONUS := server_bonus.c minitalk_bonus.c
SRC_CLIENT_BONUS := client_bonus.c minitalk_bonus.c

OBJ_SERVER       := $(SRC_SERVER:.c=.o)
OBJ_CLIENT       := $(SRC_CLIENT:.c=.o)
OBJ_SERVER_BONUS := $(SRC_SERVER_BONUS:.c=.o)
OBJ_CLIENT_BONUS := $(SRC_CLIENT_BONUS:.c=.o)

DEPS := minitalk.h

LIBFT      := ./libft/libft.a
LIBFT_PATH := ./libft

# =============================================================================
# Rules
# =============================================================================
all: $(NAME_SERVER) $(NAME_CLIENT)

# 링크 단계 – 오브젝트가 바뀌지 않으면 재링크 안 함
$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o $@

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o $@

# 공통 .c -> .o 규칙 (헤더 경로 포함)
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# libft가 없거나 구버전이면 갱신
$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

# Clean object files (*.o)
clean:
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)
	$(MAKE) -C $(LIBFT_PATH) clean

# Clean binaries
fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	$(MAKE) -C $(LIBFT_PATH) fclean

# Rebuild
re: fclean all

# Bonus (동일한 실행파일 이름에 보너스 소스로 교체 빌드)
bonus: $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) $(LIBFT) -o $(NAME_SERVER)
	$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) $(LIBFT) -o $(NAME_CLIENT)

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonu
