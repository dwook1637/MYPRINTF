#include <stdarg.h>	//�������� �����ؼ� �������
#include <stdio.h>
#include <malloc.h>

int width=0;		//�ʵ� �ʺ�
int align=-1;		//���� ���

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
	int i;
	int size = size_hexa(n);
	char* blank = NULL;

	cur = n % 16;		//cur�� 0���� 15����
	res = (n - cur) / 16;

	if(align == 0){
		for(i=0 ; i < width-size ; i++){
			putchar(' ');
		}
	}
	if(align == 2){
		for(i=1 ; i < width-size ; i++){
			putchar(' ');
		} putchar('+'); 
	}
	if(align == 1){
		blank = (char*)malloc(sizeof(char)*(width-size));
		for(i=0 ; i < width-size; i++){
			blank[i] = ' ';
		}
	}
	align = -1;

	if (res)
		my_printf_hexa(res, hexa_arr);
	my_printf_char(hexa_arr[cur]);

	if(blank) {
		my_printf_str(blank);
		free(blank);
	}
}

void my_printf_int(int n)
{
	int cur;		//10������ ����� 1�� �ڸ� �κ�
	int res;		//cur�� ������ ����� ���� ������ �κ�
	char c;			//�ƽ�Ű�ڵ�� ����
	int i;
	int size = size_int(n);
	char* blank = NULL;

	cur = n % 10;
	c = '0' + cur;
	res = (n - cur) / 10;

	if(align == 0){
		for(i=0 ; i<width-size ; i++){
			putchar(' ');
		}
	}
	if(align == 2){
		for(i=1 ; i<width-size ; i++){
			putchar(' ');
		} putchar('+'); 
	}
	if(align == 1){
		blank = (char*)malloc(sizeof(char)*(width-size));
		for(i=0 ; i<width-size; i++){
			blank[i] = ' ';
		}
	}
	align = -1;

	if (res)		//����� �κ��� ���������� ��� ���(���� ��µ�)
		my_printf_int(res);
	my_printf_char(c);

	if(blank) {
		my_printf_str(blank);
		free(blank);
	}
}

void my_printf_octa(unsigned int n)
{
	int cur;		
	int res;		
	char c;			//�ƽ�Ű�ڵ�� ����
	int i;
	int size = size_octa(n);
	char* blank = NULL;

	if(align == 0){
		for(i=0 ; i < width-size ; i++){
			putchar(' ');
		}
	}
	if(align == 2){
		for(i=1 ; i < width-size ; i++){
			putchar(' ');
		} putchar('+'); 
	}
	if(align == 1){
		blank = (char*)malloc(sizeof(char)*(width-size));
		for(i=0 ; i < width-size; i++){
			blank[i] = ' ';
		}
	}
	align = -1;

	cur = n % 8;
	c = '0' + cur;
	res = (n - cur) / 8;
	if (res)		//����� �κ��� ���������� ��� ���(���� ��µ�)
		my_printf_int(res);
	my_printf_char(c);

	if(blank) {
		my_printf_str(blank);
		free(blank);
	}
}

int size_int(int n){
	int size=0;

	do{
		n /= 10;
		size++;
	}while(n);

	return size;
}

int size_hexa(int n){
	int size=0;

	do{
		n /= 16;
		size++;
	}while(n);

	return size;
}

int size_octa(int n){
	int size=0;

	do{
		n /= 8;
		size++;
	}while(n);

	return size;
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
	my_printf("test %d %c %o %x\n", 1, 'c', 16, 16);
	my_printf("test %-12d%-4d%4d%+4d\n", 2016, 12, 20, 18)
}



