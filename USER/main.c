#include "stm32f10x.h"
#include "AS5048A.h"

uint16_t angle;
uint8_t error;

void Delay(u32 count)
{
    u32 i=0;
    for(;i<count;i++);
}
int main(void)
{
	uart_init(115200);
    AS5048A_Init();
    while(1)
    {
        uint16_t temp;

        temp = AS5048A_Read_Angle_once_16bit();

        printf("%d\n",temp-8192);

        Delay(360000);
        // Delay(36000);
    }
}
