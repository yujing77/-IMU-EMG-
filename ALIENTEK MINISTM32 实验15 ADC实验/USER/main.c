#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "lcd.h"
#include "adc.h"

//ALIENTEK Mini STM32开发板范例代码15
//ADC实验  
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司
   	
 int main(void)
 { 
	u16 adc0;
	u16 adc1;
	u16 adc2;
	u16 adc3;
	u16 adc4;
	u16 adc5;
	float temp0;
	float temp1;
	float temp2;
	float temp3;
	float temp4;
	float temp5;
	delay_init();	    	 //延时函数初始化	  
	uart_init(9600);	 	//串口初始化为9600
	LED_Init();		  		//初始化与LED连接的硬件接口
 	LCD_Init();
 	Adc_Init();		  		//ADC初始化	    
	POINT_COLOR=RED;//设置字体为红色 
	LCD_ShowString(60,50,200,16,16,"Mini STM32");	
	LCD_ShowString(60,70,200,16,16,"ADC TEST");	
	LCD_ShowString(60,90,200,16,16,"ATOM@ALIENTEK");
	LCD_ShowString(60,110,200,16,16,"2014/3/9");	
	//显示提示信息
	POINT_COLOR=BLUE;//设置字体为蓝色
	LCD_ShowString(60,130,200,16,16,"ADC_CH1_VAL:");	      
	LCD_ShowString(60,150,200,16,16,"ADC_CH1_VOL:0.000V");	    
	while(1)
	{
		adc0=Get_Adc_Average(ADC_Channel_0,10);
	  temp0=(float)adc0*(3.3/4096);
		adc1=Get_Adc_Average(ADC_Channel_1,10);
	  temp1=(float)adc1*(3.3/4096);
		adc2=Get_Adc_Average(ADC_Channel_2,10);
	  temp2=(float)adc2*(3.3/4096);
		adc3=Get_Adc_Average(ADC_Channel_3,10);
	  temp3=(float)adc3*(3.3/4096);
		adc4=Get_Adc_Average(ADC_Channel_4,10);
	  temp4=(float)adc4*(3.3/4096);
		adc5=Get_Adc_Average(ADC_Channel_5,10);
	  temp5=(float)adc5*(3.3/4096);
//		LCD_ShowxNum(156,130,adcx,4,16,0);//显示ADC的值
		 //temp=(float)adcx*(3.3/4096);
		 //adcx=temp;
		printf("data1:%f\n",(temp0));		
		printf("data2:%f\n",(temp1));
		printf("data3:%f\n",(temp2));
		printf("data4:%f\n",(temp3));
		printf("data5:%f\n",(temp4));
		printf("data6:%f\n",(temp5));
//		LCD_ShowxNum(156,150,adcx,1,16,0);//显示电压值
//		temp-=adcx;
//		temp*=1000;
//		LCD_ShowxNum(172,150,temp,3,16,0X80);
//		LED0=!LED0;
		delay_ms(1000);	
	}											    
}	
