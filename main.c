#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 173 //SUM of max field width + all the ';' + '\n'
#define MAX_MEMBER_COUNTER 8 + 1
#define MAX_MEMBER_LENGTH 50 + 1
#define CALLER_ID_LENGTH 14 + 1
#define NAME_LENGTH 50 + 1
#define DATE_LENGTH 10 +1
#define TIMESTAMP_LENGTH 11 + 1
#define REGION_CD_LENGTH 1 + 1
#define MAX_CDR_COUNT 25 //1000000
#define FILENAME "./db.txt"
#define HELP_TEXT_MODE 2
#define DEFAULT_MODE 0
#define CALLER_ID_SEARCH_MODE 1
#define INVALID_INPUT -1

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

void l_trim(const char *string, char *trimmed)
{
        int     i;
        int     j;

        j = 0;
        i = 0;
        while (string[i] <= ' ' && string[i] > 0)
        {
                i++;
        }
        while (string[i])
        {
                trimmed[j++] = string[i++];
        }
        trimmed[j] = '\0';
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
                        member[i] = '\0';
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
			case 0:strncpy(new_CDR->caller_id, member, CALLER_ID_LENGTH);break;
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

void initialize_DB(CDR *DB)
{
	char	line[MAX_LINE_LENGTH];
	FILE	*f_stream;
        int     i;
        CDR    *new_CDR;
        char    *result;

        i = 0;

        f_stream = fopen(FILENAME, "r");
        if (f_stream == NULL)
        {
                printf("falhei a abrir o Documento\n");
                return ;
        }
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

void search_exact_caller_id(CDR *DB, const char *arg_id)
{
        int     i;
        int     result;
        int     caller_counter;
        char    trimmed_arg[CALLER_ID_LENGTH];
        char    trimmed_caller_id[CALLER_ID_LENGTH];

        caller_counter = 0;
        i = 0;
        result = -1;
        while (i < MAX_CDR_COUNT)
        {
                l_trim(arg_id, trimmed_arg);
                l_trim(DB[i].caller_id, trimmed_caller_id);
                result = strncmp(trimmed_arg, trimmed_caller_id, CALLER_ID_LENGTH);
                if (result == 0)
                {
                        print_CDR(&(DB[i]));
                        printf("\n");
                        caller_counter++;
                }
                i++;
        }
        printf("Total number of registers with that ID: %d\n", caller_counter);
        return ;
}

char define_program_mode(char **argv)
{
        char    caller_id[CALLER_ID_LENGTH];

        if (!argv[1])
        {
                return DEFAULT_MODE;
        }
        if (strncmp(argv[1], "-h", 2) == 0)
        {
                return HELP_TEXT_MODE;
        }
        if (sscanf(argv[1], "%s", caller_id) == 0)
                return INVALID_INPUT;
        else
                return CALLER_ID_SEARCH_MODE;
}

void print_help_text()
{
        printf("\nIsto é o meu texto para te ajudar!\n");
        return ;
}

void print_menu()
{
        printf("\n\n\t\t\t\t****************Menu****************\n\n");
        printf("\t\t\t\t1 - Search Calls made from chosen number\n");
        printf("\t\t\t\t2 - Search Calls made to chosen number\n");
        printf("\t\t\t\t3 - Sum of call-time (caller)\n");
        printf("\t\t\t\te - exit\n\n");
        printf("\t\t\t\t************************************\n\n");
}

void main_loop(CDR *DB, char mode, char *arg_id)
{
        print_menu();
        return ;
}

int main(int argc, char **argv)
{
        static CDR      DB[MAX_CDR_COUNT];
        char            program_mode;

        program_mode = -1;
        program_mode = define_program_mode(argv);
        if (program_mode == INVALID_INPUT)
                return INVALID_INPUT;
        if (program_mode == HELP_TEXT_MODE)
        {
                print_help_text();
                return HELP_TEXT_MODE;
        }
        initialize_DB(DB);
        if (program_mode == CALLER_ID_SEARCH_MODE)
        {
                search_exact_caller_id(DB, argv[1]);
        }

        main_loop(DB, program_mode, argv[1]);
        return 0;
}




// int main(int argc, char *argv)
// {
// 	static CDR DB[MAX_CDR_COUNT];

// 	main_loop(DB);
// 	return 0;
// }