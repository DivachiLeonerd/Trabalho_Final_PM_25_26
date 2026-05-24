#include "coordinator.h"

#define	WRONG_COMMAND -1
#define NOT_FOPEN -1


/*
static int read_usr_command()
{
	int	n;
	char usr_input[100];
	n = 0;

	while (!n)
	{
		n = scanf("> %s", &usr_input);
	}
	if (usr_input[1] != ' ' || usr_input[1] != '\0')
		return 0;
	switch (usr_input[0])
	{
	case 'C': cache_command();
		break;
	case 'D': abbr_cache_command();
		break;
	case 'E': statistics_command();
		break;
	case 'F':
		break;
	case 'G':
		break;
	case 'L':
		break;
	case 'M':
		break;
	case 'O':
		break;
	case 'T':
		break;
	case 'X':
		break;
	case 'Z':
		break;
	default:
		break;
	}
}
*/

int main()
{
	int	is_db_open;
	int	return_val;
	//Coordinator	coordinator;

	printf("FICHEIRO: ");
	FILE *fd = NULL;
	fd = open_dbfile("./Others/Tests/resources/db_file");
	//printf("fd: %p\n", fd);
	//if (!fd)
		//fclose(fd);
	//coordinator = create_coordinator();
	//return_val = interpreter(coordinator);

	//destroy_coordinator(coordinator);

	return 0;

}
