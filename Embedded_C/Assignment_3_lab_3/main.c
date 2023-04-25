#include "Platform_Types.h"

#define SYS_CTL 0x400FE000
#define PORTF_BASE 0x40025000

#define SYSCTL_RCGC2_R    *( vuint32_t *)(( vuint32_t *)(SYS_CTL + 0x108))
#define GPIO_PORTF_DIR_R  *( vuint32_t *)(( vuint32_t *)(PORTF_BASE + 0x400))
#define GPIO_PORTF_DEN_R  *( vuint32_t *)(( vuint32_t *)(PORTF_BASE + 0x51C))
#define GPIO_PORTF_DATA_R *( vuint32_t *)(( vuint32_t *)(PORTF_BASE + 0x3FC))

extern void NMI_handler()
{

}

int main(void)
{
	SYSCTL_RCGC2_R =0x20;
        for(vuint32_t  i=0;i<200;i++);
        GPIO_PORTF_DIR_R |=1<<3;
        GPIO_PORTF_DEN_R |=1<<3;

	while(1)
	{
		GPIO_PORTF_DATA_R |=1<<3;
		for(vuint32_t  i=0;i<1500;i++);
		GPIO_PORTF_DATA_R &=~(1<<3);
		for(vuint32_t i=0;i<1500;i++);

	}
}
