#include <stdarg.h>	//�������� �����ؼ� �������
#include <stdio.h>

void my_printf_char(char c)
{
	putchar(c);
}

void my_printf_str(char *str)
{
	int i;

	if (str)
		for (i = 0; str[i]; i++)
			my_printf_char(str[i]);
}

void my_printf_hexa(unsigned int n, char *hexa_arr)
{
	unsigned int cur;
	unsigned int res;

	cur = n % 16;		//cur�� 0���� 15����
	res = (n - cur) / 16;
	if (res)
		my_printf_hexa(res, hexa_arr);
	my_printf_char(hexa_arr[cur]);
}

void my_printf_int(int n)
{
	int cur;		//10������ ����� 1�� �ڸ� �κ�
	int res;		//cur�� ������ ����� ���� ������ �κ�
	char c;			//�ƽ�Ű�ڵ�� ����

	cur = n % 10;
	c = '0' + cur;
	res = (n - cur) / 10;
	if (res)		//����� �κ��� ���������� ��� ���(���� ��µ�)
		my_printf_int(res);
	my_printf_char(c);
}

void my_printf_octa(unsigned int n)
{
	int cur;		
	int res;		
	char c;			//�ƽ�Ű�ڵ�� ����

	cur = n % 8;
	c = '0' + cur;
	res = (n - cur) / 8;
	if (res)		//����� �κ��� ���������� ��� ���(���� ��µ�)
		my_printf_int(res);
	my_printf_char(c);
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
			else if (str[i + 1] == 'x')	//%x �ڸ��� ���� int�� ���� ����
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
