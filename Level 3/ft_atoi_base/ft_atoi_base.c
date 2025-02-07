int	ft_atoi_base(const char *str, int str_base)
{
	int	res = 0;
	int	sign = 1;
	int	i = 0;
	int c;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			c = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			c = str[i] - 'a' + 10;
		else if (str[i] >= 'A' && str[i] <= 'F')
			c = str[i] - 'A' + 10;
		else
			break;
		res = res * str_base + c;
		i++;
	}
	return (res * sign);
}
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <number> <base>\n", argv[0]);
        return 1;
    }
    
    const char *number = argv[1];
    int base = atoi(argv[2]);
    
    if (base < 2 || base > 16)
    {
        printf("Error: Base must be between 2 and 16.\n");
        return 1;
    }
    
    int result = ft_atoi_base(number, base);
    printf("Converted value: %d\n", result);
    
    return 0;
}