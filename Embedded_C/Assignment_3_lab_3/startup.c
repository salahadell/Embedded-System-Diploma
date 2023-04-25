#include "Platform_Types.h"

static uint32 stack_top[256] ;           //use an uninitialized static var to use it to reserve memory of stack on the ram using .bss section 

extern uint32 E_text ;
extern uint32 S_data ;
extern uint32 E_data ;
extern uint32 S_bss ;
extern uint32 E_bss ;
extern void main();

void reset_handler();

void default_handler()
{
  reset_handler();
}

void NMI_handler(void)__attribute__((weak,alias("default_handler")));
void HardF_handler(void)__attribute__((weak,alias("default_handler")));

void (* const arr_of_pointers_to_Hfunctions[])() __attribute__((section(".vectors"))) =     //using array of pointers to functions instead of array of int
{
 (void (*)()) ((uint32)stack_top+sizeof(stack_top)),
 &reset_handler,
 &NMI_handler,
 &HardF_handler 
};

void reset_handler()
{
  //copy .data
  uint32 data_size=(uint8*)&E_data-(uint8*)&S_data;
  uint8 *pointer_to_flash=(uint8*)&E_text;
  uint8 *pointer_to_ram=(uint8*)&S_data;
 for(int i=0;i<data_size;i++)
 {
  *((uint8*)pointer_to_ram++)=*((uint8*)pointer_to_flash++);
 }

  //init .bss
  uint32 bss_size=(uint8*)&E_bss-(uint8*)&S_bss;
  pointer_to_ram=(uint8*)&S_bss;
  for(int i=0;i<bss_size;i++)
 {
  *((uint8*)pointer_to_ram++)=(uint8)0;
 }

  main();
  
}