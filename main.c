#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 173 //SUM of max field width + all the ';' + '\n'
#define MAX_MEMBER_COUNTER 8 + 1
#define MAX_MEMBER_LENGTH 50 + 1
#define CALLER_ID_LENGTH 14 + 1
#define NAME_LENGTH 50 + 1
#define DATE_LENGTH 10 + 1
#define TIMESTAMP_LENGTH 11 + 1
#define REGION_CD_LENGTH 1 + 1
#define MAX_CDR_COUNT 1000000
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

void print_CDR(CDR *call_record)
{
        printf("%s-%s-%s-%s-%s-%s-%s-%c-%c", call_record->caller_id, call_record->caller_name,
                call_record->client_id, call_record->client_name, call_record->start_date,
                call_record->start_time, call_record->end_time, call_record->caller_zone,
                call_record->client_zone);
        printf("\n");
        return ;
}

void copy_CDR(const CDR *call_record, CDR *new_call_record)
{
        strncpy(new_call_record->caller_id, call_record->caller_id, CALLER_ID_LENGTH);
        strncpy( new_call_record->caller_name, call_record->caller_name, NAME_LENGTH);
        strncpy(new_call_record->client_id, call_record->client_id, CALLER_ID_LENGTH);
        strncpy(new_call_record->client_name, call_record->client_name, NAME_LENGTH);
        strncpy(new_call_record->start_date, call_record->start_date, DATE_LENGTH);
        strncpy(new_call_record->start_time, call_record->start_time, TIMESTAMP_LENGTH);
        strncpy(new_call_record->end_time, call_record->end_time, TIMESTAMP_LENGTH);
        strncpy(&(new_call_record->caller_zone), &(call_record->caller_zone), REGION_CD_LENGTH);
        strncpy(&(new_call_record->client_zone), &(call_record->client_zone), REGION_CD_LENGTH);
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

long int str_to_sec(const char *time_format)
{
        int             hours;
        int             minutes;
        int             seconds;
        long int        total_secs;

        hours = 0;
        minutes = 0;
        seconds = 0;
        sscanf(time_format, "%02dh %02dm %02ds", &hours, &minutes, &seconds); //XXh XXm XXs
        total_secs = hours * 3600 + minutes * 60 + seconds;
        return total_secs;
}

void secs_to_str(const long int arg_total_seconds, char *str)
{
        long int             hours;
        long int             minutes;
        long int             seconds;
        long int        total_seconds;

        total_seconds = arg_total_seconds;

        hours = total_seconds / (long)3600;
        total_seconds = total_seconds % (long)3600;
        
        minutes = total_seconds / (long)60;
        total_seconds = total_seconds % (long)60;
        seconds = total_seconds;
        sprintf(str, "%02ldh %02ldm %02lds\n", hours, minutes, seconds);
        return ;
}

void read_next_member(char *member,const char *line)
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

//reads and initializes a call_record, returns DB's address
CDR	*read_call_record(CDR *new_CDR, char *line)
{
	char			member[MAX_MEMBER_LENGTH];
	static short int	member_counter = 0;

	if (member_counter >= MAX_MEMBER_COUNTER)
	        member_counter = 0;
	while (member_counter < MAX_MEMBER_COUNTER)
	{
                read_next_member(member, line);
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

char initialize_DB(CDR *DB)
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
                printf("Failed to open Document. Need a db.txt on the same directory as executable\n");
                return 0;
        }
        do
        {
                result = fgets(line, MAX_LINE_LENGTH, f_stream);
                if (result == NULL)
                        break ;
                while (line[0] == '\n')
                {
                        result = fgets(line, 1, f_stream); 
                }
                new_CDR = read_call_record(&(DB[i]), line);
                i++;
        }
	while (line != NULL || new_CDR != NULL);
        fclose(f_stream);
        return 1;
}

void search_exact_caller_id(CDR *DB, const char *arg_id)
{
        int     i;
        int     result;
        int     caller_counter;
        char    trimmed_arg[CALLER_ID_LENGTH];
        char    trimmed_caller_id[CALLER_ID_LENGTH];
        char    temp[CALLER_ID_LENGTH];

        caller_counter = 0;
        i = 0;
        result = -1;
        if (arg_id == NULL)
        {
                printf("Choose the number to search:");
                scanf(" %s", temp);
                l_trim(temp, trimmed_arg);
                printf("\n");
        }
        else
        {
                l_trim(arg_id, trimmed_arg);
        }
        while (i < MAX_CDR_COUNT)
        {
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

//if MSISDN has no country code, fix it by putting the portuguese prefix. Otherwise, just do a left trim.
void put_country_cd(char *caller_id)
{
        char    trimmed_id[CALLER_ID_LENGTH];
        int     i;
        int     j;

        
        trimmed_id[CALLER_ID_LENGTH] = '\0';
        l_trim(caller_id, trimmed_id);
        j = strlen(trimmed_id);
        if (j == 9)
        {
                i = CALLER_ID_LENGTH - 1;
                while (i > 4)
                {
                        caller_id[i--] = trimmed_id[j--];
                }
                caller_id[0] = ' ';
                caller_id[1] = ' ';
                caller_id[2] = '3';
                caller_id[3] = '5';
                caller_id[4] = '1';
        }
        else
        {
                strncpy(caller_id, trimmed_id, CALLER_ID_LENGTH);
        }
        return ;
}

long int get_call_cost(CDR *call_record, long int conv_time)
{
        long int        bigger;
        long int        smaller;
        long int        price_per_sec;

        bigger = call_record->caller_zone;
        smaller = call_record->client_zone;
        if (call_record->caller_zone < call_record->client_zone)
        {
                bigger = call_record->client_zone;
                smaller = call_record->caller_zone;
        }
        price_per_sec = (bigger - smaller + 1);
        return (price_per_sec * conv_time);
}

//Handles the option 4 logic
void time_avg_cost(CDR *DB)
{
        int             i;
        int             caller_counter;
        int             result;
        char            search_id[CALLER_ID_LENGTH];
        char            temp[CALLER_ID_LENGTH];
        long int        conv_time;
        long int        total_conv_time;
        float           average_call_time;
        int             total_call_cost;
        CDR             matches_array[1000];
        
        total_conv_time = 0;
        i = 0;
        total_call_cost = 0;

        caller_counter = 0;
        printf("Choose the number:");
        scanf(" %s", search_id);
        printf("\n");
        put_country_cd(search_id);
        while (i < MAX_CDR_COUNT)
        {
                strncpy(temp, (&(DB[i]))->caller_id, CALLER_ID_LENGTH);
                put_country_cd(temp);
                result = strncmp(temp, search_id, CALLER_ID_LENGTH);
                if (result == 0)
                {
                        if (caller_counter > 999)
                        {
                                printf("Too many record calls (more than 1000). Exit.\n");
                                exit(1);
                        }
                        copy_CDR(&(DB[i]), &(matches_array[caller_counter]));
                        conv_time = str_to_sec((&(matches_array[caller_counter]))->end_time) - str_to_sec((&(matches_array[caller_counter]))->start_time);
                        total_conv_time += conv_time;
                        total_call_cost += get_call_cost(&(matches_array[caller_counter]), conv_time);
                        caller_counter++;
                }
                i++;
        }
        average_call_time = (float)(total_conv_time / (float)caller_counter);
        printf("Total number of records: %d\n", caller_counter);
        printf("\n\n");
        printf("Total number of calls = %d seconds.\n", caller_counter);
        printf("Total conversation time = %ld seconds.\n", total_conv_time);
        printf("Average Call Time = %.2f seconds.\n", average_call_time);
        printf("Total cost of calls = %d seconds.\n", total_call_cost);
        printf("Click Enter to Continue...\n");
        getc(stdin);
        while (getc(stdin) != 10);

        i = 0;
        while (i < caller_counter)
        {
                print_CDR(&(matches_array[i++]));
        }
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
        printf("\nVersion: 1.0\nSyntax: ./main.out\n");
        printf("or\nSyntax: ./main.out <telephone number>\n");
        printf("Example: ./main.out 34967692346\n");
        return ;
}

void print_menu()
{
        printf("\n\n\t\t\t\t****************Call Analysis****************\n\n");
        printf("\t\t\t\t0 - exit\n\n");
        printf("\t\t\t\t1 - Show calls performed by a number\n");
        printf("\t\t\t\t2 - Write the calls received by a number in a file\n");
        printf("\t\t\t\t3 - Total conversation time initiated by a number\n");
        printf("\n\n\n");
        printf("\t\t\t\t4 - Total time, average, and total cost performed by a number\n");
        printf("\t\t\t\t************************************\n\n");
}

void fwrite_received_calls(CDR *DB)
{
        FILE    *f_wstream;
        char    trimmed_client_id[CALLER_ID_LENGTH];
        char    trimmed_arg[CALLER_ID_LENGTH];
        char    temp[CALLER_ID_LENGTH];
        int     i;
        int     result;
        int     client_counter;

        i = 0;
        client_counter = 0;
        result = 0;

        printf("Name the new file:");
        scanf("%s", temp);
        f_wstream = fopen(temp, "w");
        printf("Choose the number to search:");
        scanf("%s", temp);
        l_trim(temp, trimmed_arg);
        printf("\n");
        while (i < MAX_CDR_COUNT)
        {
                l_trim(DB[i].client_id, trimmed_client_id);
                result = strncmp(trimmed_arg, trimmed_client_id, CALLER_ID_LENGTH);
                if (result == 0)
                {
                        print_CDR(&(DB[i]));
                        printf("\n");
                        client_counter++;
                        fprintf(f_wstream, "%s;%s;%s;%s;%s;%s;%s;%c;%c;\n",
                                DB[i].caller_id, DB[i].caller_name, DB[i].client_id,
                                DB[i].client_name, DB[i].start_date, DB[i].start_time,
                                DB[i].end_time, DB[i].caller_zone, DB[i].client_zone);
                }
                i++;
        }
        printf("Total number of records:%d\n", client_counter);
        fclose(f_wstream);
        return ;
}

void get_caller_total_time(CDR *DB)
{
        int             i;
        int             result;
        int             caller_counter;
        char            trimmed_arg[CALLER_ID_LENGTH];
        char            trimmed_caller_id[CALLER_ID_LENGTH];
        char            temp[CALLER_ID_LENGTH];
        long int        total_secs;
        char            formatted_time[TIMESTAMP_LENGTH];

        caller_counter = 0;
        i = 0;
        result = -1;
        total_secs = 0;
        printf("Choose the number to search:");
        scanf("%s", temp);
        l_trim(temp, trimmed_arg);
        printf("\n");
        while (i < MAX_CDR_COUNT)
        {
                l_trim(DB[i].caller_id, trimmed_caller_id);
                result = strncmp(trimmed_arg, trimmed_caller_id, CALLER_ID_LENGTH);
                if (result == 0)
                {
                        print_CDR(&(DB[i]));
                        printf("\n");
                        total_secs += str_to_sec(DB[i].end_time) - str_to_sec(DB[i].start_time);
                        caller_counter++;
                }
                i++;
        }
        secs_to_str(total_secs, formatted_time);
        printf("Total number of registers with that ID: %d\n", caller_counter);
        printf("Total number of seconds is %ld, which translates to %s\n", total_secs, formatted_time);
}

void main_loop(CDR *DB)
{
        int     bytes_read;
        char    usr_choice;

        while (1)
        {
                print_menu();
                printf("Choose:");
                bytes_read = scanf(" %c", &usr_choice);
                printf("\n");
                if (bytes_read == 0)
                {
                        printf("Error reading user input\n");
                        return ;
                }
                if (usr_choice == '0')
                        return ;
                if (usr_choice == '1')
                {
                        search_exact_caller_id(DB, NULL);
                        printf("\n");
                }
                if (usr_choice == '2')
                {
                        fwrite_received_calls(DB);
                        printf("\n");
                }
                if (usr_choice == '3')
                {
                        get_caller_total_time(DB);
                        printf("\n");
                }
                if (usr_choice == '4')
                {
                        time_avg_cost(DB);
                }
                printf("Click Enter to Continue...\n");
                getc(stdin);
                while (getc(stdin) != 10);
        }
}

int main(int argc, char **argv)
{
        static CDR      DB[MAX_CDR_COUNT];
        char            program_mode;
        char            is_initialized;

        (void)argc;
        program_mode = -1;
        program_mode = define_program_mode(argv);
        if (program_mode == INVALID_INPUT)
                return INVALID_INPUT;
        if (program_mode == HELP_TEXT_MODE)
        {
                print_help_text();
                return HELP_TEXT_MODE;
        }
        is_initialized = initialize_DB(DB);
        if (!is_initialized)
                return 1;
        if (program_mode == CALLER_ID_SEARCH_MODE)
        {
                search_exact_caller_id(DB, argv[1]);
        }
        main_loop(DB);
        return 0;
}
