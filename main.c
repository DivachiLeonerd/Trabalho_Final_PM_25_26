#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 173 //SUM of max field width + all the ';' + '\n'
#define MAX_MEMBER_COUNTER 9
#define MAX_MEMBER_LENGTH 50
#define CALLER_ID_LENGTH 14
#define NAME_LENGTH 50
#define DATE_LENGTH 10
#define TIMESTAMP_LENGTH 11
#define REGION_CD_LENGTH 1
#define MAX_CDR_COUNT 1000000
#define FILENAME "./db.txt"


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
        putchar('-');
        print_chr_array(call_record->caller_name, NAME_LENGTH);
        putchar('-');
        print_chr_array(call_record->client_id, CALLER_ID_LENGTH);
        putchar('-');
        print_chr_array(call_record->client_name, NAME_LENGTH);
        putchar('-');
        print_chr_array(call_record->start_date, DATE_LENGTH);
        putchar('-');
        print_chr_array(call_record->start_time, TIMESTAMP_LENGTH);
        putchar('-');
        print_chr_array(call_record->end_time, TIMESTAMP_LENGTH);
        putchar('-');
        print_chr_array(&(call_record->caller_zone), REGION_CD_LENGTH);
        putchar('-');
        print_chr_array(&(call_record->client_zone), REGION_CD_LENGTH);
        putchar('\n');
        return ;
}

void read_next_member(char *member, char *line)
{
        short int               i;
        static short int        j = 0;

        i = 0;
        if (j >= MAX_LINE_LENGTH - 2)
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
        // printf("read_call_record():line:%s\n", line);
	while (member_counter < MAX_MEMBER_COUNTER)
	{
		//call a function that gets the next member
                read_next_member(member, line);
                // printf("read_call_record(): %s\nmember counter:%d\n", member, member_counter);
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

void write_call_record(CDR *DB, FILE *output_stream)
{
	
}

void initialize_DB(CDR *DB)
{
	char	line[MAX_LINE_LENGTH];
	FILE	*f_stream;
        int     i;
        CDR    *new_CDR;
        char    *result;

        i = 0;

        f_stream = fopen(FILENAME, "r");
        do
        {
                result = fgets(line, MAX_LINE_LENGTH, f_stream);
                //printf("Initialize_DB(): line:*%d* || result:%p\n", line[0], result);
                if (result == NULL)
                        break ;
                while (line[0] == '\n')
                {
                        result = fgets(line, 1, f_stream); 
                }
                //printf("After Initialize_DB(): line:*%s* || result:%p\n", line, result);
                new_CDR = read_call_record(&(DB[i]), line);
                print_CDR(new_CDR);
                i++;
        }
	while (line != NULL || new_CDR != NULL);
        fclose(f_stream);
        return ;
}

main_loop(CDR *DB)
{
	
}

int main(int argc, char **argv)
{
        static CDR      DB[MAX_CDR_COUNT];
        FILE            *file_stream;
        char            buff[MAX_LINE_LENGTH];
        int             i;

        i = 0;
        file_stream = fopen(FILENAME, "r");
        if (file_stream == NULL)
                return 1;
        printf("hello World\n");
        initialize_DB(DB);
        // for (int i = 0; i < 25; i++)
        // {
        //         read_call_record(&(DB[i]), buff);
        //         print_CDR(&(DB[i]));
        // }
        // while (i < 5)
        // {
        //         print_CDR(&(DB[i++]));
        // }
        return 0;
}




// int main(int argc, char *argv)
// {
// 	static CDR DB[MAX_CDR_COUNT];

// 	main_loop(DB);
// 	return 0;
// }