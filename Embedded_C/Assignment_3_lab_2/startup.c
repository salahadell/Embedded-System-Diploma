#include "Platform_Types.h"
extern uint32 stack_top ;
extern uint32 E_text ;
extern uint32 S_data ;
extern uint32 E_data ;
extern uint32 S_bss ;
extern uint32 E_bss ;
extern void main();
void reset_handler(void);

void default_handler(void)
{
  reset_handler();
}
void NMI_handler(void)__attribute__((weak,alias("default_handler")));
void HardF_handler(void)__attribute__((weak,alias("default_handler")));
void bus_fault_handler(void)__attribute__((weak,alias("default_handler")));
void Memm_handler(void)__attribute__((weak,alias("default_handler")));

uint32 vectors[] __attribute__((section(".vectors")))={
(uint32) &stack_top,
(uint32) &reset_handler,
(uint32) &NMI_handler,
(uint32) &HardF_handler,
(uint32) &bus_fault_handler,
(uint32) &Memm_handler
};

void reset_handler(void)
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