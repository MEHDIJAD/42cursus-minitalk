
SRCS_CLIENT = mand/client.c \
              mand/ft_atoi.c \

SRCS_SERVER = mand/server.c

SRCS_CLIENT_BONUS = bonus/client_bonus.c \
					bonus/ft_atoi_bonus.c \

SRCS_SERVER_BONUS = bonus/server_bonus.c \
					bonus/ft_handler_bonus.c \
					bonus/ft_get_utf8_byte_count_bonus.c \


OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

OBJS_CLIENT_BONUS = $(SRCS_CLIENT_BONUS:.c=.o)
OBJS_SERVER_BONUS = $(SRCS_SERVER_BONUS:.c=.o)


CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

CLIENT = client
SERVER = server

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

# FT_PRINTF PART

FT_PRINTF_SRC = ft_printf/ft_printf.c \
				ft_printf/ft_print_format.c \
				ft_printf/ft_printchar.c \
				ft_printf/ft_printstr.c \
				ft_printf/ft_printdigit.c \


FT_PRINTF_OB = $(FT_PRINTF_SRC:.c=.o)


FT_PRINTF_DIR = ft_printf

FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

# header file:

HEADERS_MAND = mand/minitalk.h ft_printf/ft_printf.h

HEADERS_BONUS = bonus/minitalk_bonus.h ft_printf/ft_printf.h


all: $(FT_PRINTF_LIB) $(CLIENT) $(SERVER)

bonus:  $(FT_PRINTF_LIB) $(CLIENT_BONUS) $(SERVER_BONUS)

$(FT_PRINTF_LIB):
	$(MAKE) -C $(FT_PRINTF_DIR) 

# client mand
$(CLIENT): $(OBJS_CLIENT) $(FT_PRINTF_OB)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(FT_PRINTF_LIB) -o $(CLIENT)

# server mand

$(SERVER): $(OBJS_SERVER) $(FT_PRINTF_OB)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(FT_PRINTF_LIB) -o $(SERVER)

#BONUS PART:

# client bonus

$(CLIENT_BONUS): $(OBJS_CLIENT_BONUS) $(FT_PRINTF_OB)
	$(CC) $(CFLAGS) $(OBJS_CLIENT_BONUS) $(FT_PRINTF_LIB) -o $(CLIENT_BONUS)

# sever bonus

$(SERVER_BONUS): $(OBJS_SERVER_BONUS) $(FT_PRINTF_OB)
	$(CC) $(CFLAGS) $(OBJS_SERVER_BONUS) $(FT_PRINTF_LIB) -o $(SERVER_BONUS)

# this is for communt file (ft_atoi.c)

$(OBJS_CLIENT) $(OBJS_SERVER): %.o: %.c $(HEADERS_MAND)
	$(CC) $(CFLAGS) -c $< -o $@

# bonus part

$(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS): %.o: %.c $(HEADERS_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(MAKE) clean -C $(FT_PRINTF_DIR)
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER) $(OBJS_CLIENT_BONUS) $(OBJS_SERVER_BONUS) $(COMMON_OBJS)

fclean: clean
	$(MAKE) fclean -C $(FT_PRINTF_DIR)
	$(RM) $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all


