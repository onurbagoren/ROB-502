#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_READ_LINES 80


void copy_char_arr( char *original, char *copy )
{
    for( int i = 0; i < MAX_READ_LINES; i++ )
    {
        copy[i] = original[i];
    }
}

int main( int argc, char **argv )
{
	if( argc != 4 )
	{
		printf("Please enter the commands as ./problem2 <file> <key> <lines before>\n");
		return 1;
	}
	
	char *file_name = argv[1];
	char *key = argv[2];
	int lines_before = atoi(argv[3]);

	FILE *fp = fopen(file_name, "r");

	if (fp == NULL)
	{
		printf("error opening the file %s\n", file_name);
		return 1;
	}

	int line_count = -1;
	char line[MAX_READ_LINES] = {0};
	char *lines[MAX_READ_LINES] = {0};
	while(fgets(line, MAX_READ_LINES, fp)){
		char *substr; 
		substr = strstr(line, key);
        lines[++line_count] = malloc(strlen(line) + 1);
        strcpy(lines[line_count], line);
		// printf("lines[%d]: %s\n", line_count, lines[line_count]);
		if ( substr != NULL )
		{
			int substring_pos = substr - line;
			if( lines_before == 0 )
			{
				line[substring_pos + strlen(key)] = '\0';
				printf("%s\n", line + substring_pos);
			}
			else if( lines_before == 1 )
			{
                char tmp[MAX_READ_LINES]; 
                copy_char_arr(*(lines + line_count),tmp);
                tmp[substring_pos + strlen(key)] = '\0';
				printf("%s\n", tmp); 	
			}
            else{
                for( int i = lines_before; i > 1; i-- )
                {
                    int line_value = line_count - ( i - 1 );
                    printf("%s", lines[line_value]);
                }
                char tmp[MAX_READ_LINES]; 
                copy_char_arr(*(lines + line_count),tmp);
                tmp[substring_pos + strlen(key)] = '\0';
				printf("%s\n", tmp); 	
            }
		} else {
		}
	}
	return 0;
}
