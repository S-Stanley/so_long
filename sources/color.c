#include "main.h"

int	get_color(char *value)
{
	if (atoi(value) == 0)
		return (0x00D8FF);
	if (atoi(value) == 1)
		return (0x50c836);
	return (0x00D8FF);
}