#include <stdio.h>
#include <string.h>
#define MAX_LINE_LENGTH 171 //SUM of max field width + all the ';'
#define MAX_MEMBER_COUNTER 9
#define MAX_MEMBER_LENGTH 50
#define CALLER_ID_LENGTH 14
#define NAME_LENGTH 50
#define DATE_LENGTH 10
#define TIMESTAMP_LENGTH 11
#define REGION_CD_LENGTH 1

typedef struct
{
	char	caller_id[CALLER_ID_LENGTH];
	char	caller_name[NAME_LENGTH];
	char	client_id[CALLER_ID_LENGTH];
	char	client_name[NAME_LENGTH];
	char	start_date[DATE_LENGTH];
	char	start_time[TIMESTAMP_LENGTH];
	char	end_time[TIMESTAMP_LENGTH];
	char	caller_zone;
	char	client_zone;
}CDR;

void print_chr_array(char *array, int array_size)
{
        int     i;

        i = 0;
        while (i < array_size)
        {
                putchar(array[i++]);
        }
        return ;
}

void print_CDR(CDR *call_record)
{
        print_chr_array(call_record->caller_id, CALLER_ID_LENGTH);
        print_chr_array(call_record->caller_name, NAME_LENGTH);
        print_chr_array(call_record->client_id, CALLER_ID_LENGTH);
        print_chr_array(call_record->client_name, NAME_LENGTH);
        print_chr_array(call_record->start_date, DATE_LENGTH);
        print_chr_array(call_record->start_time, TIMESTAMP_LENGTH);
        print_chr_array(call_record->end_time, TIMESTAMP_LENGTH);
        print_chr_array(&(call_record->caller_zone), REGION_CD_LENGTH);
        print_chr_array(&(call_record->client_zone), REGION_CD_LENGTH);

        return ;
}

void read_next_member(char *member, char *line)
{
        short int               i;
        static short int        j = 0;

        i = 0;
        if (j >= MAX_LINE_LENGTH)
        {
                j = 0;
        }
        while (i < 50)
        {            
                member[i++] = '\0';
        }
        i = 0;
        while (1)
        {
                if (line[j] == '\n' || line[j] == '\0' || line[j] == ';')
                {
                        j++;
                        return ;
                }
                member[i++] = line[j++];
        }
}

CDR	*read_call_record(CDR *new_CDR, char *line)//reads and initializes a call_record, returns DB's address or null whether it was successful or not
{
	char			member[MAX_MEMBER_LENGTH];
	static short int	member_counter = 0;

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
			case 2:strncpy(new_CDR->client_id, member, CALLER_ID_LENGTH); break;
			case 3:strncpy(new_CDR->client_name, member, NAME_LENGTH); break;
			case 4:strncpy(new_CDR->start_date, member, DATE_LENGTH); break;
			case 5:strncpy(new_CDR->start_time, member, TIMESTAMP_LENGTH); break;
			case 6:strncpy(new_CDR->end_time, member, TIMESTAMP_LENGTH); break;
			case 7:strncpy(&(new_CDR->caller_zone), member, REGION_CD_LENGTH); break;
			case 8:strncpy(&(new_CDR->client_zone), member, REGION_CD_LENGTH); break;
                        default: break;
		}
		member_counter++;
	}
	return new_CDR;
}

int main()
{
        FILE    *db_text;
        char    line[MAX_LINE_LENGTH + 1];

        CDR     call_record;

        line[MAX_LINE_LENGTH - 1] = '\0';

        db_text = fopen("./db.txt", "r");
        printf("hello World\n");

        fgets(line, MAX_LINE_LENGTH, db_text);
        print_chr_array(line, MAX_LINE_LENGTH);
        printf("\nmain- depois do print_chr_array\n*");
        read_call_record(&call_record, line);
        print_CDR(&call_record);
        printf("*\n");
        fclose(db_text);
        return 0;
}