#include <unistd.h>
#include <stdarg.h>

char	*get_next_line(int fd)
{
	int		flrd;
	char	c;
	char	*str;
	char	*str2;

	str = malloc(1000000);
	str2 = str;
	if ((flrd = read(fd, &c, 1)) == 0)
		return (NULL);
	*str++ = c;
	while ((flrd = read(fd, &c, 1)) > 0 && c != '\n')
		*str++ = c;
	if (c == '\n')
		*str++ = '\n';
	*str = '\0';
	return (str2);
}


char *get_next_line(int fd)
{
    char *s = malloc(10000), *c = s;
    while (read(fd, c, 1) > 0 && *c++ != '\n');
    return c > s ? (*c = 0, s) : (free(s), NULL);
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
