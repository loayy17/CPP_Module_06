CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
SRCS = main.cpp ScalarConverter.cpp TypeConverter.cpp
OBJS = ${SRCS:.cpp=.o}
NAME = convert

${NAME}: ${OBJS}
		${CXX} ${CXXFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean: 
	rm -rf ${NAME}

fclean: clean
	rm -rf ${OBJS}

re: fclean all

.PHONY: re fclean clean all