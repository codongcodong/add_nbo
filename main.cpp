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
	FILE* fp = fopen(filename, "r");
	fread(&temp,4,1,fp);
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
