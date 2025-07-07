# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blax <blax@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 11:22:00 by                   #+#    #+#              #
#    Updated: 2025/07/07 11:23:14 by blax             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = sudoku_solver

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
DEBUG_FLAGS = -g -fsanitize=address
OPTIMIZE_FLAGS = -O2

# Source files
SRCDIR = .
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

# Colors for output
GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
YELLOW = \033[0;33m
NC = \033[0m # No Color

# Default target
all: $(NAME)

# Build the main program
$(NAME): $(OBJECTS)
	@echo "$(BLUE)Linking $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(NC)"

# Compile source files to object files
%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@

# Debug build with sanitizer
debug: CFLAGS += $(DEBUG_FLAGS)
debug: fclean $(NAME)
	@echo "$(GREEN)✓ Debug build completed with AddressSanitizer$(NC)"

# Optimized build
optimized: CFLAGS += $(OPTIMIZE_FLAGS)
optimized: fclean $(NAME)
	@echo "$(GREEN)✓ Optimized build completed$(NC)"

# Run the program
run: $(NAME)
	@echo "$(BLUE)Running $(NAME)...$(NC)"
	@./$(NAME)

# Run with valgrind for memory leak detection
valgrind: $(NAME)
	@echo "$(BLUE)Running $(NAME) with Valgrind...$(NC)"
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

# Clean object files
clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -f $(OBJECTS)
	@echo "$(GREEN)✓ Object files cleaned$(NC)"

# Clean everything
fclean: clean
	@echo "$(RED)Cleaning executable...$(NC)"
	@rm -f $(NAME)
	@echo "$(GREEN)✓ Everything cleaned$(NC)"

# Rebuild everything
re: fclean all

# Install (copy to /usr/local/bin)
install: $(NAME)
	@echo "$(BLUE)Installing $(NAME) to /usr/local/bin...$(NC)"
	@sudo cp $(NAME) /usr/local/bin/
	@echo "$(GREEN)✓ $(NAME) installed successfully$(NC)"

# Uninstall
uninstall:
	@echo "$(RED)Uninstalling $(NAME)...$(NC)"
	@sudo rm -f /usr/local/bin/$(NAME)
	@echo "$(GREEN)✓ $(NAME) uninstalled$(NC)"

# Show help
help:
	@echo "$(BLUE)Available targets:$(NC)"
	@echo "  $(YELLOW)all$(NC)        - Build the program (default)"
	@echo "  $(YELLOW)debug$(NC)      - Build with debug flags and AddressSanitizer"
	@echo "  $(YELLOW)optimized$(NC)  - Build with optimization flags"
	@echo "  $(YELLOW)run$(NC)        - Build and run the program"
	@echo "  $(YELLOW)valgrind$(NC)   - Run the program with Valgrind"
	@echo "  $(YELLOW)clean$(NC)      - Remove object files"
	@echo "  $(YELLOW)fclean$(NC)     - Remove object files and executable"
	@echo "  $(YELLOW)re$(NC)         - Rebuild everything"
	@echo "  $(YELLOW)install$(NC)    - Install the program to /usr/local/bin"
	@echo "  $(YELLOW)uninstall$(NC)  - Remove the program from /usr/local/bin"
	@echo "  $(YELLOW)help$(NC)       - Show this help message"

# Declare phony targets
.PHONY: all clean fclean re debug optimized run valgrind install uninstall help
