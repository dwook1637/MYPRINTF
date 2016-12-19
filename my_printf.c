#include <stdarg.h>	//�������� �����ؼ� �������
#include <stdio.h>

void my_printf_char(char c)
{
	putchar(c);
}

void my_printf_str(char *str)
{
	//%s ���
}

void my_printf_hexa(unsigned int n, char *hexa_num)
{
	//%x ���
}

void my_printf_int(int n)
{
	//%d ���
}

void my_printf_octa(unsigned int n)
{
	//%o ���
}

void my_printf(char *str, ...)			//ù��° ���ڴ� ���ڿ�, �� ���� ���ڴ� ��������
{
	va_list va;								//�������� ����Ʈ
	int i=0;									//�ݺ�

	va_start(va, str);						//�������� �غ�
	while (str[i])							//���ڿ� ��ȸ
	{
		if (str[i] == '%')					//���ڿ� �� ���Ĺ���
		{
			if (str[i + 1] == 's')					//%s �ڸ��� ���� string ���ڿ� ����
				my_printf_str(va_arg(va, char *));		
			else if (str[i + 1] == 'd')				//%d �ڸ��� ���� int�� ���� ����
				my_printf_int(va_arg(va, int));			
			else if (str[i + 1] == 'c')				//%c �ڸ��� ���� char ������ ���
				my_printf_char((char)va_arg(va, int));		
			else if (str[i + 1] == 'x' || str[i + 1] == 'X')	//%x �ڸ��� ���� int�� ���� ����
				my_printf_hexa(va_arg(va, unsigned int), "0123456789abcdef");
			else if (str[i + 1] == 'o')				//%o �ڸ��� ���� int�� ���� ����				
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
	��������
	va_list	�������� ����Ʈ �ڷ���
	va_start(va_list, argLength) va_list���� ���ڸ� �޾ƿ�
	va_arg(va_list, type) �������� ����Ʈ���� �ش� Ÿ�� ������ ������� ������
	va_end(va_list)
*/