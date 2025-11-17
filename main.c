#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 170 //SUM of max field width + all the ';'
#define MAX_MEMBER_COUNTER 9
#define MAX_MEMBER_LENGTH 50
#define CALLER_ID_LENGTH 14
#define NAME_LENGTH 50
#define DATE_LENGTH 10
#define TIMESTAMP_LENGTH 11
#define REGION_CD_LENGTH 1




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

void read_next_member(char *member, char *line)
{
        short int               i;
        static short int        j = 0;

        i = 0;
        if (j >= MAX_LINE_LENGTH)
        {
            j = 0;
        }
        while (i < MAX_MEMBER_LENGTH)
        {            
            member[i++] = '\0';
        }
        i = 0;
        while (1)
        {
			if (line[j] == '\n' || line[j] == EOF || line[j] == '\0' || line[j] == ';')
			{
				j++;
				return ;
			}
			member[i++] = line[j++];
        }
	return ;
}

CDR	*read_call_record(CDR *new_CDR, char *line)//reads and initializes a call_record, returns DB's address or null whether it was successful or not
{
	char				member[50];
	short int			i;
	static short int	member_counter = 0;

	i = 0;
	if (member_counter >= MAX_MEMBER_COUNTER)
		member_counter = 0;
	while (member_counter < MAX_MEMBER_COUNTER)
	{
		//call a function that gets the next member
		read_next_member(member, line);
		switch (member_counter)
		{
			case 0:strncpy(new_CDR->caller_id, member, CALLER_ID_LENGTH); break; 
			case 1:strncpy(new_CDR->caller_name, member, NAME_LENGTH); break;
			case 2:strncpy(new_CDR->caller_id, member, CALLER_ID_LENGTH); break;
			case 3:strncpy(new_CDR->client_name, member, NAME_LENGTH); break;
			case 4:strncpy(new_CDR->start_date, member, DATE_LENGTH); break;
			case 5:strncpy(new_CDR->start_time, member, TIMESTAMP_LENGTH); break;
			case 6:strncpy(new_CDR->end_time, member, TIMESTAMP_LENGTH); break;
			case 7:strncpy(new_CDR->caller_zone, member, REGION_CD_LENGTH); break;
			case 8:strncpy(new_CDR->client_zone, member, REGION_CD_LENGTH); break;
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