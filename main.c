#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 170 //SUM of max field width + all the ';'
#define MAX_MEMBER_COUNTER 9
typedef struct
{
	char	caller_id[14];
	char	caller_name[50];
	char	client_id[14];
	char	client_name[50];
	char	start_date[10];
	char	start_time[11];
	char	end_time[11];
	char	caller_zone;
	char	client_zone;
}CDR;

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

void read_call_record(CDR *DB, char *line)
{
	short int	i;
	short int	member_counter;
	char		*member;

	i = 0;
	member_counter = 0;
	while (member_counter < MAX_MEMBER_COUNTER)
	{
		//call a function that gets the next member
		member = read_next_member(line);
		switch (member_counter)
		{
			case 0: 
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
		}
	}
}

void write_call_record(CDR *DB, FILE *output_stream)
{
	
}

void initialize_DB(CDR *DB)
{
	char	line[MAX_LINE_LENGTH];
	FILE	*f_stream;

	while ((line = fgets(f_stream,MAX_LINE_LENGTH, f_stream)) != EOF)
	{
		read_call_record(DB, line);

	}
}

main_loop(CDR *DB)
{
	
}


int main(int argc, char *argv)
{
	static CDR DB[1000000];

	main_loop(DB);
	return 0;
}