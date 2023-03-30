#------------------------------------------------------------
#  copyright (c) 2023 SeoulTech All Rights Reserved
#------------------------------------------------------------
# Makefile
#------------------------------------------------------------
# Author		: Hyun Woo Oh (ohhyunwoo@seoultech.ac.kr)
# Oranization	: SEOULTECH.
# Created 		: 2022.12.10
# Version		: 1.0
#-----------------------------------------------------------

include make.env

OBJFILES = $(OBJDIR)/startup.o $(OBJDIR)/exchdlr.o $(OBJDIR)/main.o $(OBJDIR)/uart.o $(OBJDIR)/counter.o  $(OBJDIR)/calc.o $(OBJDIR)/intellino.o

all: $(BUILDDIR)/Instdata 

$(BUILDDIR)/Instdata: startup.lds makefile $(OBJFILES)
	$(LD) $(LDFLAGS) $(OBJFILES) -o $(BUILDDIR)/Instdata $(LKFLAGS)
	cd $(BUILDDIR); $(OBJDUMP) $(DPFLAGS) Instdata > Instdata.dump
	cd $(BUILDDIR); $(OBJCOPY) -j .text -O binary Instdata useg0.bin
	cd $(BUILDDIR); $(OBJCOPY) -j .sdata -j .data -O binary Instdata useg1.bin
	cd $(BUILDDIR); $(OBJCOPY) -j .exchdlr -O binary Instdata kseg.bin
	cd $(BUILDDIR); ./binmerge.pl useg0 useg1 kseg compiled
	cd $(BUILDDIR); ./bin2bytehex.pl compiled.bin compiled.hex
	cd $(BUILDDIR); ./bin2hex.pl useg
	cd $(BUILDDIR); ./bin2hex.pl kseg
$(OBJDIR)/startup.o: startup.s
	$(CPP) $(CCFLAGS)	startup.s > startup.i
	$(AS) $(ASFLAGS)	startup.i -o $(OBJDIR)/startup.o
	rm startup.i

$(OBJDIR)/exchdlr.o: exchdlr.s
	$(CPP)	$(CCFLAGS)	exchdlr.s  > exchdlr.i
	$(AS)	$(ASFLAGS)	exchdlr.i -o $(OBJDIR)/exchdlr.o
	rm exchdlr.i

$(OBJDIR)/main.o: main.c include/intellino_as.h
	$(CPP) $(CCFLAGS) main.c > main.i
	$(CC) $(CCFLAGS)  --specs=nosys.specs -Wall -S main.i
	echo "#define __asmdef__" > main_temp
	echo "#include \"asmdefs.h\"" >> main_temp
	echo "#undef __asmdef__" >> main_temp
	cat main_temp main.s | tee main_new.s
	rm main.i
	$(CPP)	$(CCFLAGS)	main_new.s  > main.i
	$(AS) $(ASFLAGS) main.i -o $(OBJDIR)/main.o
	rm main.s
	rm main_new.s
	rm main.i
	rm main_temp

$(OBJDIR)/uart.o: include/uart.h uart.c
	$(CPP) $(CCFLAGS) uart.c > uart.i
	$(CC) $(CCFLAGS)  --specs=nosys.specs -Wall -S uart.i
	$(AS) $(ASFLAGS) uart.s -o $(OBJDIR)/uart.o
	rm uart.s uart.i

$(OBJDIR)/counter.o: include/counter.h counter.c
	$(CPP) $(CCFLAGS) counter.c > counter.i
	$(CC) $(CCFLAGS)  --specs=nosys.specs -Wall -S counter.i
	$(AS) $(ASFLAGS) counter.s -o $(OBJDIR)/counter.o
	rm counter.s counter.i

$(OBJDIR)/calc.o: include/calc.h calc.c
	$(CPP) $(CCFLAGS) calc.c > calc.i
	$(CC) $(CCFLAGS)  --specs=nosys.specs -Wall -S calc.i
	$(AS) $(ASFLAGS) calc.s -o $(OBJDIR)/calc.o
	rm calc.s calc.i

$(OBJDIR)/intellino.o: include/intellino.h intellino.c
	$(CPP) $(CCFLAGS) intellino.c > intellino.i
	$(CC) $(CCFLAGS)  --specs=nosys.specs -Wall -S intellino.i
	echo "#define __asmdef__" > intellino_temp
	echo "#include \"asmdefs.h\"" >> intellino_temp
	echo "#undef __asmdef__" >> intellino_temp
	cat intellino_temp intellino.s | tee intellino_new.s
	rm intellino.i
	$(CPP)	$(CCFLAGS)	intellino_new.s  > intellino.i
	$(AS) $(ASFLAGS) intellino.i -o $(OBJDIR)/intellino.o
	rm intellino.s
	rm intellino_new.s
	rm intellino.i
	rm intellino_temp

clean:
	rm -rf *.o *.a *.mif *.dump *.hex *.bin *.mif Instdata
	cd $(BUILDDIR); rm -rf *.hex *.dump *.bin Instdata
	cd $(OBJDIR); rm -rf *.o
