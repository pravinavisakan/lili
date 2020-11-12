# This makefile compiles the demo programs in the demos folder
# Setup -----------------------------------------------------------------------

#Compiler Setup
CC = g++

CXXFLAGS += `sdl2-config --cflags`
CXXFLAGS += -Wall -Wempty-body -Werror -Werror=maybe-uninitialized -Warray-bounds
CXXFLAGS += -g -lefence

BONUS_LD_FLAGS = -lSDL2_mixer -lSDL2_image -lSDL2_ttf
LDFLAGS += `sdl2-config --libs` -lGL -lGLEW -lm 

# setup output directories
COMPDIR = bin
OUTDIR = executeables

_PROG = cube
PROG = $(patsubst %,$(OUTDIR)/%,$(_PROG))

_OBJS += camera cube
OBJS = $(patsubst %,$(COMPDIR)/%.o,$(_OBJS))

# look for souces files in the following directories
SEARCHPATH += src
SEARCHPATH += include
SEARCHPATH += demos
vpath %.cpp $(SEARCHPATH)
vpath %.h $(SEARCHPATH)

# Rules -----------------------------------------------------------------------
# top-level rule to create the programs
all: $(PROG)

# linking the program. 
$(PROG): $(OBJS)
	@mkdir -p $(OUTDIR)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

# compiling other source files. (Uses contents of OBJS, restated for pattern sub)
$(COMPDIR)/%.o: %.cpp 
	@mkdir -p $(COMPDIR)
	$(CC) $(CXXFLAGS) -c -o $@ $<

# cleaning everything that can be automatically recreated with "make".
clean:
	$(RM) -rf $(COMPDIR) $(OUTDIR) 

