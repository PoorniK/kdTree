.PHONY : clean

CC = g++
FLAGS = -std=c++11 -fPIC -g -c #-Wall
LDFLAG = -shared
SHELL = /bin/sh

LIBDIR = ../lib
INCLUDEDIR = ../include
TARGET = $(LIBDIR)/kdTree.so
SOURCES = $(shell echo ./*.cpp)
HEADERS = $(shell echo ../include/*.hpp)
OBJECTS = $(SOURCES:.cpp=.o)

all:$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)

$(TARGET) : $(OBJECTS) 
	$(CC) $(LDFLAG) -Wl,-soname,$(TARGET) -o $(TARGET) $(OBJECTS)
	
$(OBJECTS) : $(SOURCES)
	$(CC) $(FLAGS) -I$(INCLUDEDIR) $(SOURCES)
