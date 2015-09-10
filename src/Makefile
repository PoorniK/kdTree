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

EXEDIR = ../bin
TESTSOURCES = $(shell echo ../test/*.cpp)
TESTOBJECTS = ../src/testkdTree.o
TESTTARGET = $(EXEDIR)/testkdTree

all:$(TESTTARGET)

clean:
	rm -f $(OBJECTS) $(TARGET) $(TESTOBJECTS) $(TESTTARGET)

$(TESTTARGET): $(TESTOBJECTS) $(TARGET)
	$(CC) -L$(TARGET) -o $@ $(TESTOBJECTS) $(OBJECTS)

$(TESTOBJECTS) : $(TESTSOURCES)
	$(CC) $(FLAGS) -I$(INCLUDEDIR) $(TESTSOURCES)
	
$(TARGET) : $(OBJECTS) 
	$(CC) $(LDFLAG) -Wl,-soname,$(TARGET) -o $(TARGET) $(OBJECTS)
	
$(OBJECTS) : $(SOURCES)
	$(CC) $(FLAGS) -I$(INCLUDEDIR) $(SOURCES)
