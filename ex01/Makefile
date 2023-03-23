NAME = AwesomePhoneBook

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:%.cpp=%.o)

$(NAME) : $(OBJS)
	$(CXX) $(OBJS) -o $(NAME)

clean:
	$(RM) *.o
	$(RM) $(NAME)

run: $(NAME)
	./$(NAME)

test: $(NAME)
	cat <<EOF
