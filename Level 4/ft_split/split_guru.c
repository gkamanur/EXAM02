#include <stdio.h>
#include <stdlib.h>

// Declaration of the ft_split function
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while ((i < (size - 1)) && (src[i] != '\0'))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

int	ft_word(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s != c)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

int	ft_len(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
	{
		len++;
	}
	return (len);
}

void	free_all(char **result, size_t i)
{
	while (i > 0)
		free(result[--i]);
	free(result);
	return ;
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**result;

	result = (char **)malloc((ft_word(s, c) + 1) * sizeof(char *));
	if (!s || !c || !result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c)
		{
			result[i] = (char *)malloc((ft_len(s, c) + 1) * sizeof(char));
			if (!result[i])
				free_all(result, i);
			ft_strlcpy(result[i++], s, ft_len(s, c) + 1);
			s += ft_len(s, c);
		}
	}
	result[i] = NULL;
	return (result);
}

// Helper function to print the result of ft_split
void print_split_result(char **result)
{
    if (!result)
    {
        printf("Result is NULL\n");
        return;
    }

    for (int i = 0; result[i] != NULL; i++)
    {
        printf("Word %d: %s\n", i, result[i]);
        free(result[i]); // Free each string
    }
    free(result); // Free the array itself
}

int main(void)
{
    // Test Case 1: Normal string with delimiters
    printf("Test Case 1:\n");
    char **result1 = ft_split("Hello,world,this,is,a,test", ',');
    print_split_result(result1);

    // Test Case 2: String with consecutive delimiters
    printf("\nTest Case 2:\n");
    char **result2 = ft_split("Hello,,,world,,split", ',');
    print_split_result(result2);

    // Test Case 3: String with no delimiters
    printf("\nTest Case 3:\n");
    char **result3 = ft_split("HelloWorld", ',');
    print_split_result(result3);

    // Test Case 4: Empty string
    printf("\nTest Case 4:\n");
    char **result4 = ft_split("", ',');
    print_split_result(result4);

    // Test Case 5: Only delimiters
    printf("\nTest Case 5:\n");
    char **result5 = ft_split(",,,,", ',');
    print_split_result(result5);

    // Test Case 6: String with leading and trailing delimiters
    printf("\nTest Case 6:\n");
    char **result6 = ft_split(",Hello,world,", ',');
    print_split_result(result6);

    // Test Case 7: NULL input
    printf("\nTest Case 7:\n");
    char **result7 = ft_split(NULL, ',');
    print_split_result(result7);

    return 0;
}