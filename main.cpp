#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <stdlib.h>

void print_usage(void)
{
	puts("syntax : add-nbo <file1> <file2>");
	exit(0);
}

uint32_t read_nbo(char* filename)
{
	uint32_t temp;
	int res;
	FILE* fp = fopen(filename, "r");

	if(!fp)
	{
		printf("Invalid file: %s\n",filename);
		exit(0);
	}

	res = fread(&temp,1,4,fp);
	if(res!=4)
	{
		printf("invalid data in %s\n",filename);
		exit(0);
	}

	fclose(fp);
	
	return ntohl(temp);
}

int main(int argc, char** argv)
{
	uint32_t n1, n2;

	if(argc!=3)
		print_usage();
	
	n1 = read_nbo(argv[1]);
	n2 = read_nbo(argv[2]);

	printf("%d(%#x) + %d(%#x) = %d(%#x)\n",n1,n1,n2,n2,n1+n2,n1+n2);

}
