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
        // temp = AS5048A_read_always();
        // temp = AS5048A_Read_Angle_once();

        temp = AS5048A_Read_Angle_once_16bit();


        printf("%d\n",temp-8192);
        // AS5048A_read_test(0x3FFF);
        // angle = AS5048A_read(0x3FFF);
        // angle = AS5048A_getRawRotation();
        // printf("%d\n", angle);
        // error = AS5048A_getErrors();

        // printf("%d\n", error);
        // AS5048A_clear_error();
        Delay(360000);
        // Delay(36000);
    }
}
