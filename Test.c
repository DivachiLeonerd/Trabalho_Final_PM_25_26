#include <stdio.h>
#include <string.h>


char *read_next_member(char *line)
{
	char				member[50];
	short int			i;
	static short int	j = 0;

	i = 0;
	if (j >= MAX_LINE_LENGTH)
		return null;
	while (i < 50)
	{
		member[i++] = '0';
	}
	i = 0;
	while (1)
	{
		if (line[j] == '\n')
		{
			j++;
			return (member);
		}
		member[i] = line[j];
	}
}

int main()
{
	char	line = "Esta linha é\ndo caralho";
	char	*read_line;
	read_line = read_next_member(line);
	printf("***%s***\n", read_line);
	
	
	return 0;
}