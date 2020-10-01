
#include <stdio.h>
#include <sys/file.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int in_file, out_file;  
	char array[100];
	int n, i, point; 
	
	
	if (argc < 3)
	{
		printf("Please give an input and output file\n");
		exit(1);
	}
	
	if (!strcmp(argv[1], argv[2]))
	{
		printf("\nBoth files must be different\n");
		exit(2);
	}
	
	in_file = open(argv[1], O_RDONLY);		
	if (in_file == -1)
	{
		printf("\nUnable to open the input file\n");
		exit(3);
	}
	
	
	out_file = open(argv[2], O_CREAT|O_RDWR|O_APPEND, 0644);		
	if (out_file == -1)
	{
		printf("\nUnable to open the output file\n");
		exit(4);
	}
	
	point = lseek(in_file, 0, SEEK_END);
	for (i = point - 1; i >= 0; i--) {
        lseek(in_file, i, SEEK_SET);
		n= read(in_file, array, n);
		n = write(out_file, array, n);
	}
	
	while (n != 0)	
	{
		for (i=0; i<n; i++)
			if (array[i] == 32)  
				array[i] += 63;
		n = write(out_file, array, n);
		n = read(in_file, array, 100);
	}
	
	printf("GUCCI!!!\n"); 

	close(in_file);
	close(out_file);	
		
	return 0;
}






