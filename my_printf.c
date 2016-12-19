#include <stdarg.h>	//가변인자 관련해서 들어있음
#include <stdio.h>

void my_printf_char(char c)
{
	putchar(c);
}

void my_printf_str(char *str)
{
	//%s 출력
}

void my_printf_hexa(unsigned int n, char *hexa_num)
{
	//%x 출력
}

void my_printf_int(int n)
{
	//%d 출력
}

void my_printf_octa(unsigned int n)
{
	//%o 출력
}

void my_printf(char *str, ...)			//첫번째 인자는 문자열, 그 이후 인자는 가변인자
{
	va_list va;								//가변인자 리스트
	int i=0;									//반복

	va_start(va, str);						//가변인자 준비
	while (str[i])							//문자열 순회
	{
		if (str[i] == '%')					//문자열 내 서식문자
		{
			if (str[i + 1] == 's')					//%s 자리에 오는 string 문자열 전달
				my_printf_str(va_arg(va, char *));		
			else if (str[i + 1] == 'd')				//%d 자리에 오는 int형 정수 전달
				my_printf_int(va_arg(va, int));			
			else if (str[i + 1] == 'c')				//%c 자리에 오는 char 문자형 출력
				my_printf_char((char)va_arg(va, int));		
			else if (str[i + 1] == 'x' || str[i + 1] == 'X')	//%x 자리에 오는 int형 정수 전달
				my_printf_hexa(va_arg(va, unsigned int), "0123456789abcdef");
			else if (str[i + 1] == 'o')				//%o 자리에 오는 int형 정수 전달				
				my_printf_octa(va_arg(va, unsigned int));				
			else
				my_printf_char(str[i + 1]);			
			i++;
		}
		else
			my_printf_char(str[i]);
		i++;
  	}
  	va_end(va);
}

int main(void)
{
	my_printf("test %c", 'c');
	//my_printf("test %d %c %o %x", 1, 'c', 16, 16);
}




/*
	가변인자
	va_list	가변인자 리스트 자료형
	va_start(va_list, argLength) va_list에서 인자를 받아옴
	va_arg(va_list, type) 가변인자 리스트에서 해당 타입 변수를 순서대로 가져옴
	va_end(va_list)
*/