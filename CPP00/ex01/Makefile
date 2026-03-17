CC = c++
CFLAGS =  -Wall -Wextra -Werror -MMD -MP -g
NAME = phone.out
LIBS =

SRC = ./main.cpp \
	  ./Contact.cpp \
	  ./PhoneBook.cpp

OBJ = $(addprefix .obj/,$(SRC:.cpp=.o))
DEP = $(addprefix .obj/,$(SRC:.cpp=.d))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $+ $(LIBS)

.obj/%.o: %.cpp
	@mkdir -p .obj
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEP)

clean:
	rm -rf .obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
