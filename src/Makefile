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
	@rm -rf build/ gcov_report/ a.out test *.info *.a *.gcda app
	@rm -rf gcov_report/ *.info
	@echo "\033[1;42m DONE \033[0m"

style: 
	@echo "\033[1;34mStyling\033[0m"
	@cp ../materials/linters/.clang-format ./
	@clang-format -i *.c
	@clang-format -i *.h
	@rm -rf .clang-format
	@echo "\033[1;42m DONE \033[0m" 

install:
	@echo "\033[1;34mInstalling\033[0m"
	@mkdir app
	@cp *.c *.h untitled/* app
	@cd app && qmake untitled.pro && make
	@cd app && rm *.o *.c *.cpp *.h
	@cp -r app/untitled.app ~/Desktop
	@echo "\033[1;42m DONE \033[0m" 

uninstall:
	@echo "\033[1;34mUnistalling\033[0m"
	@rm -rf app
	@rm -rf ~/Desktop/untitled.app ~/Desktop/untitled.tar.gz
	@echo "\033[1;42m DONE \033[0m" 

dist: uninstall install
	@echo "\033[1;34mArchivating\033[0m"
	@tar -cvzf ~/Desktop/untitled.tar.gz ~/Desktop/untitled.app
	@echo "\033[1;42m DONE \033[0m" 

dvi:
	@open ../README_RUS.md

add_coverage_flag:
	$(eval FLAGS += --coverage)	

gcov_report: clean add_coverage_flag test
	@gcov -l -p *.gcno
	@lcov -q --c --directory . --output-file coverage.info
	@genhtml -q coverage.info --output-directory gcov_report
	@rm -rf *.gcno *gcda *.gcov
	@open gcov_report/index.html
