include config.mk

APP_NAME = game
BUILD_DIR = ./bin
C_FILES = ./src/*.cpp

APP_INCLUDES:= -I$(SDL_INCLUDE_PATH) -I$(SDL_INCLUDE_PATH)/SDL2 -I$(SDL_IMAGE_INCLUDE_PATH)
APP_LINKERS:= -L$(SDL_LIB_PATH) -lSDL2 -L$(SDL_IMAGE_LIB_PATH) -lSDL2_image 

all: build run

build:
	mkdir -p $(BUILD_DIR)
	clang++ -std=c++11 -o $(BUILD_DIR)/$(APP_NAME) $(C_FILES) $(APP_INCLUDES) $(APP_LINKERS)

run:
	./$(BUILD_DIR)/$(APP_NAME)