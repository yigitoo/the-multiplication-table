ifeq ($(OS), Windows_NT)
clear_console := cls
rmdir := rd /S
exe_format := .exe
pause_cmd := pause
else
clear_console := clear
rmdir := rm -rf
exe_format := ""
pause_cmd := ./scripts/pause.sh
endif

CC = g++
CFLAGS = -g

all: clean build run wait

build:
	mkdir build
	$(CC) -o build/main$(exe_format) src/main.cc
run:
	build/main$(exe_format)
wait:
	pause
clean:
	$(rmdir) build
chmod_scripts:
	chmod +x ./scripts/pause.sh

.PHONY: all build run wait clean