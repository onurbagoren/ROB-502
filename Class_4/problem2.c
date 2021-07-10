#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_READ_LINES 80

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

	printf("%s, %s, %d\n", file_name, key, lines_before);

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
		lines[++line_count] = line;
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
				line[substring_pos + strlen(key)] = '\0';
				printf("%s\n", line); 		
			}else{
				//
				// Using the current index from line_count, get index value difference
				// print lines until current
				// is there a more elegent way than from backtracking?
				//
			}
		} else {
			printf("\n");
		}
		
		printf("Line #%d is: %s\n", line_count, lines[line_count]);
	}
	return 0;
}
