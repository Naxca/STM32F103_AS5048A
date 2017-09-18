#include "stm32f10x.h"
#include "AS5048A.h"

/************************************************
 ALIENTEK 战舰STM32F103开发板实验0
 工程模板
 注意，这是手册中的新建工程章节使用的main文件 
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/

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
