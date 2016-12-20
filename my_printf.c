#include <stdarg.h>
#include <stdio.h>
#include <malloc.h>

#define HEXA_ARR "0123456789abcdef"
int width=0;	
int align=-1;	

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

	cur = n % 16;	
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
	int cur;	
	int res;	
	char c;		
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

	if (res)	
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
	char c;		
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
	if (res)	
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

void my_printf(char *str, ...)	
{
	va_list va;		
	int i=0;	

	va_start(va, str);		
	while (str[i])		
	{
		if (str[i] == '%')			
		{
			if(str[i + 1] >= '0' && str[i+1] <= '9') { align = 0; }
			if(str[i + 1] == '-') { align = 1; i++; }
			else if(str[i + 1] == '+') { align = 2; i++; }

			while(str[i + 1] >= '0' && str[i+1] <= '9'){
				width *= 10;
				width += str[i + 1] - '0';
				i++;
			}

			if (str[i + 1] == 's')	
				my_printf_str(va_arg(va, char *));		
			else if (str[i + 1] == 'd')	
				my_printf_int(va_arg(va, int));			
			else if (str[i + 1] == 'c')	
				my_printf_char((char)va_arg(va, int));		
			else if (str[i + 1] == 'x')	
				my_printf_hexa(va_arg(va, unsigned int), HEXA_ARR);
			else if (str[i + 1] == 'o')					
				my_printf_octa(va_arg(va, unsigned int));				
			else
				my_printf_char(str[i + 1]);
			width = 0;
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
	my_printf("Output test\n");
	my_printf("%d %c %o %x\n\n", 1, 'c', 16, 16);
	my_printf("Minimum filed-width test\n");
	my_printf("%10d%5d%5d\n\n", 2016, 12, 20);
	my_printf("Alignment test\n");
	my_printf("%5d[%%5d]\n", 123);
	my_printf("%-5d[%%-5d]\n", 123);
	my_printf("%+5d[%%+5d]\n", 123);
}

