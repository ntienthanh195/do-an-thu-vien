# Dev-C++ 5.11 runs make from the project directory.
SHELL := cmd.exe
CXXDIR := C:/msys64/ucrt64/bin
TARGET := demo.exe
SOURCES := $(wildcard demo/*.cpp)

.PHONY: all clean
all: $(TARGET)

$(TARGET): $(SOURCES) demo/00_KhaiBaoChung.h demo.mk
	echo Dang bien dich demo Thu vien...
	set "PATH=$(CXXDIR);%PATH%" && "$(CXXDIR)/g++.exe" -std=c++11 -O2 -Wall -Wextra -Wpedantic -static $(SOURCES) -o "$@"

clean:
	if exist "$(TARGET)" del /q "$(TARGET)"
