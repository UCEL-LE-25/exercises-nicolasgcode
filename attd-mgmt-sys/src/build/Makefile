# Compiler and flags
CC = gcc
CFLAGS = -Wall -I../include

# Source directory relative to build/
SRC_DIR = ..
SRC = $(SRC_DIR)/menus.c $(SRC_DIR)/main.c $(SRC_DIR)/user.c $(SRC_DIR)/validators.c \
      $(SRC_DIR)/helpers.c $(SRC_DIR)/table.c $(SRC_DIR)/file.c $(SRC_DIR)/date.c \
      $(SRC_DIR)/student.c $(SRC_DIR)/report.c

# Object files will be built in build dir
OBJ = $(patsubst $(SRC_DIR)/%.c, %.o, $(SRC))

# Output binary (placed one directory up, or change as needed)
TARGET = ../../attd

# Default rule
all: $(TARGET)

# Link object files to create binary
$(TARGET): $(OBJ)
	$(CC) $(addprefix ./, $(OBJ)) -o $(TARGET)

# Compile each source file to object file
%.o: ../%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	@if exist *.o del /q *.o
	@if exist ..\..\attd.exe del /q ..\..\attd.exe
