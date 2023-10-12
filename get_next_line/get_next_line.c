/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizabethteo <elizabethteo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:27:42 by elizabethte       #+#    #+#             */
/*   Updated: 2023/10/12 15:20:47 by eteo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	checkstr(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_read(int fd)
{
	ssize_t	byteread;
	char	*buf;

	buf = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buf)
		return (NULL);
	byteread = read(fd, buf, BUFFER_SIZE);
	if (byteread <= 0)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

char	*ft_cases(int fd, char *str, char *buf)
{
	char	*output;
	char	*holding;

	output = ft_join(buf, str);
	ft_bzero(str, BUFFER_SIZE + 1);
	if (checkstr(output))
		ft_modsplit(output, str);
	else
	{
		holding = ft_read(fd);
		if (holding == NULL)
			return (NULL);
		if (!*holding)
			return (output);
		else
		{
			ft_strlcpy(str, holding, BUFFER_SIZE + 1);
			free(holding);
			output = ft_cases(fd, str, output);
		}
	}
	return (output);
}

char	*get_next_line(int fd)
{
	static char	str[BUFFER_SIZE + 1];
	char		*readstr;
	char		*holding;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (checkstr(str))
	{
		readstr = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
		if (readstr == NULL)
			return (NULL);
		ft_strlcpy(readstr, str, BUFFER_SIZE + 1);
		ft_bzero(str, BUFFER_SIZE + 1);
		ft_modsplit(readstr, str);
	}
	else
	{
		holding = ft_read(fd);
		if (!*holding)
		{
			free(holding);
			return (str);
		}
		else
			readstr = ft_cases(fd, str, holding);
	}
	return (readstr);
}

#include <stdio.h>

int main(void) {
    int fd;            // File descriptor for the text file
    char *line;        // Pointer to store the line read
    int line_count = 0;

    // Open the text file for reading (replace "your_file.txt" with the actual file path)
    fd = open("file.txt", O_RDONLY);

    if (fd < 0) {
        perror("Failed to open the file");
        return 1;
    }

    // Repeatedly call get_next_line until the end of the file is reached
    while (1) {
        line = get_next_line(fd);
        if (line) {
            printf("Line %d: %s\n", ++line_count, line);
            free(line); // Free the memory allocated by get_next_line
        } else {
            printf("End of file reached.\n");
            break;
        }
    }

    // Close the file descriptor
    close(fd);

    return 0;
}
