# Nombre del ejecutable
TARGET = program

# Directorios
SRC_DIR = src
INC_DIR = inc
BUILD_DIR = build

# Compilador y banderas
CC = gcc
CFLAGS = -Wall -Wextra -I$(INC_DIR) -std=c11

# Archivos fuente y objetos
SRCS = $(wildcard $(SRC_DIR)/*.c) main.c
OBJS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(notdir $(SRCS)))

# Regla por defecto
all: $(BUILD_DIR)/$(TARGET)

# Enlazar el ejecutable
$(BUILD_DIR)/$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(addprefix $(BUILD_DIR)/, $(OBJS))

# Compilar cada .c en un .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Crear directorio build si no existe
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Limpiar archivos generados
clean:
	@echo "🧹 Limpiando build..."
	rm -rf $(BUILD_DIR)

.PHONY: all clean
