#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>

int main(int argc, char* argv[]) {
	FILE* fd1, *fd2;
	uint32_t binary1, binary2;
	uint64_t sumbinary = 0;
	
	if(argc <3) {
		printf("Usage : ./add_nbo <4byteBinary file1> <4byteBinary file2>\n");
	}

	if((fd1 = fopen(argv[1], "rb")) == NULL ) return -1;
	if((fd2 = fopen(argv[2], "rb")) == NULL ) return -1;

	fread(&binary1, sizeof(uint32_t), 4, fd1);
	binary1 = htonl(binary1);

	fread(&binary2, sizeof(uint32_t), 4, fd2);
	binary2 = htonl(binary2);

	sumbinary = (uint64_t)binary1 + (uint64_t)binary2;

	printf("%u(0x%x) + %u(0x%x) = %lu(0x%lx)\n", binary1, binary1, binary2, binary2, sumbinary, sumbinary);

	printf("\t\t\t\t\t\tby.TagnameB\n");

	fclose(fd2);
	fclose(fd1);
	return 0;
}
