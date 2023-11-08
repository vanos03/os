#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

struct FileInfo{
	int size;
	char name[5];
} data;

int main (int argc, char* argv[])
{
	int cd;
	int size;
	int len_name = strlen(argv[1]) + 1;
	struct sockaddr_in addr;
	if ((cd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		perror("Error calling socket");
		return __LINE__;
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(2022);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if ((-1) == connect(cd, (struct sockaddr *)&addr, sizeof(addr)))
	{
		perror("connect");
		return __LINE__;
	}

	FILE *fp;
	fp = fopen(argv[1], "rb");

	fseek(fp, 0L, SEEK_END);
	size = ftell(fp); 
	rewind(fp);

	char *data_file = malloc(size * sizeof(char));
	fread(data_file, sizeof(char), size, fp);


	data.size = size;
	sprintf(data.name, argv[2]);
	send(cd, &data, sizeof(data),  0);

	send(cd, data_file, size, 0);
	
	free(data_file);
	fclose(fp);
	close(cd);
	return 0;
}
