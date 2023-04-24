MEMORY
{
	flash(rx) : o = 0x08000000,   l = 128K
	sram(rwx) : o = 0x20000000,    l = 20K
}

SECTIONS
{
	.text :{

		*(.vectors*)
		*(.text*)	
		*(.rodata)
		E_text = . ;
	}> flash

    .data :{

    	S_data = . ;
        *(.data)
        . = ALIGN(4) ;
   		E_data = . ;

    }> sram AT> flash

    .bss :{

       	S_bss = . ;
		*(.bss*)
		. = ALIGN(4) ;
    	E_bss = . ;
    	. = ALIGN(4) ;
    	. = . + 1000 ;
    	stack_top = . ;

    }> sram
    
}