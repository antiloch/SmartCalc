CC = gcc
FLAGS = -Wall -Wextra -Werror -std=c11
TEST_FLAGS = -lcheck

BUILD_DIR=build
BUILD_TEST_DIR=$(BUILD_DIR)/tests
SRCS=$(wildcard *.c)
OBJS=$(SRCS:%.c=$(BUILD_DIR)/%.o)
TEST_SRCS=$(wildcard tests/*.c)

all: clean test 

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

test:
	@echo "\033[1;34mCreating tests\033[0m"
	@$(CC) $(FLAGS) $(SRCS) $(TEST_SRCS) $(TEST_FLAGS) -o test
	@./test

clean:
	@echo "\033[1;34mCleaning\033[0m"
	@rm -rf build/ gcov_report/
	@rm -rf a.out test *.info *.a *.gcda
	@echo "\033[1;42m DONE \033[0m"

style: 
	@echo "\033[1;34mStyling\033[0m"
	@cp ../materials/linters/.clang-format ./
	@clang-format -i *.c
	@clang-format -i *.h
	@rm -rf .clang-format
	@echo "\033[1;42m DONE \033[0m" 
