Function of GET_NEXT_LINE :
	-read text file by FD one line at a time (need to identify "\n")
	-can be used repeatedly one after the other

Use of static variables: is to store leftover characters after the first line

ft_split will be modified to replace char with zero and also output the first string before \n

CASE SCENARIOS:
1. \n within buffer (ft_split at first \n store the rest - DONE)
2. no \n within buffer (store in static variable then run the next buffer, till there is a \n then activate case 1 - DONE (done it as recursion))
3. multiple \n within buffer (need to have a condition to check if \n is in storage before running read - DONE)
4. At the end of the file where there is no (\n) ***********

FUNCTIONS IN UTILS:
1. ft_modsplit (modified -> will output the first part of the string, then calloc and static char the rest)
2. ft_join
3. ft_strzero (convert all to zeros)
4. ft_strlcpy

char *get_next_line(int fd)
{
	static char str[buffer + 1];
	char *readstr;

	check if fd >= 0 and buffer size > 1, else return NULL

	if (checkstr(str))
		readstr = ft_split(str) (at first \n)
	else
		readstr = ft_read(fd)
		ft_cases(fd, str,readstr)
}

int checkstr(char *str)
{
	while (*str)
	{
		if (*str = '\n')
			return 1
		str++
	}
	return (0)
}

char *ft_read(int fd)
{
	ssize_t byteread
	char *buf

	buf  = calloc (buffer size * (sizeof(char) + 1))
	byteread = read(fd, buf, buffer size)
	if (byteread <= 0) // shows there is nothing else to read
	{
		return (NULL)
	}
	return (buf);
}

char *ft_cases(int fd, static char *str, char *buf)
{
	char *temp
	char *output
	char *holding

	temp = ft_join(buf, str);
	ft_zero(str);
	if (checkstr(temp))
	{
		output = ft_split(temp, str) (allocates the leftover to str)
	}
	else
	{
		str = ft_read(int fd);
		ft_cases(fd, str, temp);
	}
}
