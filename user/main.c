#include "GPIO.h"
#include "stm32f0xx.h"
#include "systick.h"
#include "time.h"

void Go_Zero()  //���㣬��ת�������жϺ�ת�������ж�
{
  uint8_t fre = 2;
  Speed = 3500;                     //�����ٶȣ����Ƶ��
  Count = 10000;                    //���������ܲ���=Count+r2
  GPIO_SetBits(GPIOA, GPIO_Pin_6);  //����
  while (fre) {
    r1 = 0;
    r2 = 100;
    StepCount = 0;
    GPIO_WriteBit(
        GPIOA, GPIO_Pin_6,
        (BitAction)(1 - GPIO_ReadOutputDataBit(GPIOA, GPIO_Pin_6)));  // ��ת
    TIM_Config();
    do {
    } while (r2);
    fre--;
    TIM_Cmd(TIM3, DISABLE);
    Delay(500);
  }
}

int main(void) {
  SystemInit();
  IO_Init();
  Systick_Init();
  GPIO_SetBits(GPIOA, GPIO_Pin_7);  // ʹ�ܶ�
  Delay(100);

  Go_Zero();

  while (1)
    ;
}
