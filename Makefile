################################################################################
# => TEXT
################################################################################

END		= \033[0m
BOLD	= \033[1m

RED		= \033[91m
GREEN	= \033[92m
YELLOW	= \033[93m
CYAN	= \033[96m

################################################################################
# => VARIABLES
################################################################################

NAME		= containers

PATHSRCS	= srcs/
PATHTEMP	= ${PATHSRCS}templates/
PATHHEADERS	= includes/
PATHNULL	= /dev/null

SRCS		= $(addprefix ${PATHSRCS}mains/, main.cpp vector.cpp stack.cpp map.cpp \
 											pair.cpp)

OBJS		= ${SRCS:.cpp=.o}

CC			= c++
INC			= -I${PATHHEADERS} \
			-I${PATHHEADERS}vector/ \
			-I${PATHHEADERS}stack/ \
			-I${PATHHEADERS}map/ \
			-I${PATHTEMP} \
			-I${PATHTEMP}vector/ \
			-I${PATHTEMP}stack/ \
			-I${PATHTEMP}map/

CFLAGS		= -Wall -Wextra -Werror -std=c++98

RM			= rm -rf
MAKE		= make -C

################################################################################
# => RULES
################################################################################

.cpp.o:
				@echo "${BOLD}${YELLOW}Compiling:${END}\t$<"
				@${CC} ${CFLAGS} ${INC} -c $< -o ${<:.cpp=.o} >${PATHNULL}

all:		${NAME}

${NAME}:	${OBJS}
				@echo "${BOLD}${GREEN}Building:${END}\t${NAME}"
				@${CC} ${OBJS} -o ${NAME} >${PATHNULL}

clean:
				@echo "${BOLD}${RED}Removing:${END}\tAll .o files"
				@${RM} ${OBJS} >${PATHNULL}

fclean:		clean
				@echo "${BOLD}${RED}Removing:${END}\t${NAME}"
				@${RM} ${NAME} >${PATHNULL}

re:			fclean all

.PHONY:		all clean fclean re

################################################################################
