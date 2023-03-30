OUTPUT_FORMAT("elf32-bigmips", "elf32-bigmips",
              "elf32-littlemips")
OUTPUT_ARCH(mips)

ENTRY(_start)

SEARCH_DIR("/home/hyunw/local/compiler/mips/mips-elf/lib");

MEMORY
{
	UROM			(rx)	: ORIGIN = 0x00400000, 	LENGTH = 64k
	URAM			(!rx)	: ORIGIN = 0x10000000, 	LENGTH = 64k
    KRAM 			(!rx) 	: ORIGIN = 0x80000000, 	LENGTH = 8k
}

SECTIONS
{
 
 .text           :
  {
		_ftext = .;
    	*(.text)
		. = ALIGN(4); 
		*(.rodata)
		. = ALIGN(4); 
  } > UROM 
  PROVIDE (__etext = .);
  PROVIDE (_etext = .);
  PROVIDE (etext = .);

. = ALIGN(268435456);
HIDDEN (_gp = ALIGN (16) + 0x0000); 

/* .sdata : {	
			_fdata = .;
			*(.sdata)	
			. = ALIGN(4);
		  } > URAM AT > UROM */

 .data   : {
			_fdata = .;
			*(.sdata)	
			. = ALIGN(4);
   			*(.data)			
			. = ALIGN(4);
  		   } > URAM AT > UROM

	 _edata = .; PROVIDE (edata = .);

 .sbss  ADDR(.data) + SIZEOF(.data)	: AT (ADDR (.sbss)) 
		  {
			 __bss_start = .;
			 _fbss = .;
			*(.dynbss) 
			*(.sbss)
			*(.scommon)
			. = ALIGN(4);
	  	  } >URAM
 
 .bss  : {
			*(.dynbss)
		  	*(.bss)
			*(COMMON)
			. = ALIGN(4);
		 } >URAM
		__bss_end = .;

. = ALIGN(4);
_end = .; PROVIDE (end = .);
end = .;

.exchdlr :
    {
        *(.excdata)
        *(.excvec)
    } >KRAM
 
 .MIPS.abiflags   : { *(.MIPS.abiflags) } 
 
}


