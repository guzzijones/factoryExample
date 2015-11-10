###########
#add new depend files below 
#add new ones here object files relating to .cpp filesF
DEPS=driver.o config.o

EXE=driver

#######################
#DO NOT EDIT BELOW
#######################

###########
#variables
###########
CC=g++
CPPFLAGS= -Wall -c -I. 
CPPFLAGS+= -g -MD -MP -std=c++0x 
LFLAGS= -Wall  
VPATH=

all: $(EXE)

debug: CC+= -DDEBUG -g 
debug: $(EXE)
###########
#linker
###########
$(EXE): $(DEPS)
	$(CC)  $(DEPS) $(LFLAGS) -o $(EXE).exe

##########
#implicit calls for all object file builds
#########

###########
#include dependency files 
###########
-include $(DEPS:%.o=%.d)

