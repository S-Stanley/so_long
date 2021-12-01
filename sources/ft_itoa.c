#include "main.h"

unsigned int	size_malloc_itoa(int nb)
{
	unsigned int	count;

	count = 1;
	if (nb < 0)
	{
		nb = nb * -1;
		count++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nb)
{
	unsigned int	i;
	char			*to_return;
	unsigned int	size;

	i = 0;
	size = size_malloc_itoa(nb);
	to_return = malloc(sizeof(char) * (size + 1));
	if (nb < 0)
	{
		nb = nb * -1;
		to_return[0] = '-';
		i++;
	}
	to_return[size] = 0;
	while (nb > 9)
	{
		to_return[--size] = (nb % 10) + '0';
		i++;
		nb = nb / 10;
	}
	to_return[--size] = nb + '0';
	return (to_return);
}
