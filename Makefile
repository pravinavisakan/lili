OUTDIR = bin

PROG = game 

CC = g++

CXXFLAGS += `sdl2-config --cflags`
CXXFLAGS += -Wall -Wempty-body -Werror -Werror=maybe-uninitialized -Warray-bounds
CXXFLAGS += -g -lefence

BONUS_LD_FLAGS = -lSDL2_mixer -lSDL2_image -lSDL2_ttf
LDFLAGS += `sdl2-config --libs` -lGL -lGLEW -lm 

SEARCHPATH += src
SEARCHPATH += include
vpath %.cpp $(SEARCHPATH)
vpath %.h $(SEARCHPATH)

#DEPS += defs.h structs.h

_OBJS += main.o
OBJS = $(patsubst %,$(OUTDIR)/%,$(_OBJS))

# top-level rule to create the program.
all: $(PROG)

# linking the program.
$(PROG): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

# compiling other source files.
$(OUTDIR)/%.o: %.cpp %.h 
	@mkdir -p $(OUTDIR)
	$(CC) $(CFLAGS) $(CXXFLAGS) -c -o $@ $<

# cleaning everything that can be automatically recreated with "make".
clean:
	$(RM) -rf $(OUTDIR) $(PROG)
