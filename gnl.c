#include <unistd.h>
#include <stdarg.h>

char	*get_next_line(int fd)
{
	int		r, i = 0;
	char	*res = malloc(100000);
	char	c;

	if (fd < 0 || !(r = read(fd, &c, 1)))
	{
		free(res);
		return(NULL);
	}
	res[i++] = c;
	while ((r = read(fd, &c, 1) > 0) && c)
		res[i++] = c;
	return (res);
}

#include <stdio.h>

int main()
{
	char *str;

	str = get_next_line(0);
	while (str != NULL)
	{
		printf("%s", str);
		free (str);
		str = get_next_line(0);
	}
	return (0);
}
