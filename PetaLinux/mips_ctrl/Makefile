#-------------------------------------------------------
# Copyright (c) 2022 SeoulTech All Rights Reserved
#-------------------------------------------------------
# Makefile
#-------------------------------------------------------
# Author		: Hyunwoo Oh (ohhyunwoo@seoultech.ac.kr)
# Organization	: SEOULTECH, SoC Platforms Lab.
# Created		: 2022.02.24.
# Version		: 1.0
#-------------------------------------------------------

SRCDIR		= src
OBJDIR      = lib
OBJFILES	= $(OBJDIR)/pma.o \
			  $(OBJDIR)/gpio.o \
			  $(OBJDIR)/mips_posit/mpjtag.o \
			  $(BUILDDIR)/main.o
BUILDDIR 	= build
BUILDOUT	= $(BUILDDIR)/mips_posit_ctrl

CC			= g++
CCFLAGS 	= -O2 -Iinclude -L$(OBJDIR) #-DDebug 

all: $(BUILDOUT)

$(BUILDOUT): Makefile $(OBJFILES)
	$(CC)	$(CCFLAGS)	$(OBJFILES) 	-o $(BUILDOUT)


$(BUILDDIR)/main.o:	main.c
	$(CC)	$(CCFLAGS) 	-c main.c 		-o $(BUILDDIR)/main.o

$(OBJDIR)/pma.o:	$(SRCDIR)/pma.c
	$(CC)	$(CCFLAGS)	-c src/pma.c	-o $(OBJDIR)/pma.o

$(OBJDIR)/gpio.o:	$(SRCDIR)/gpio.c
	$(CC)	$(CCFLAGS)	-c src/gpio.c	-o $(OBJDIR)/gpio.o

$(OBJDIR)/mips_posit/mpjtag.o:	$(SRCDIR)/mips_posit/mpjtag.c
	mkdir -p $(OBJDIR)/mips_posit
	$(CC)	$(CCFLAGS)	-c $(SRCDIR)/mips_posit/mpjtag.c	-o $(OBJDIR)/mips_posit/mpjtag.o

clean:
	rm -r $(OBJDIR); 	mkdir $(OBJDIR)
	rm -r $(BUILDDIR);	mkdir $(BUILDDIR)
