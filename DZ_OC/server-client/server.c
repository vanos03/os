#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>

typedef struct DataFile 
{
	int size;
	char name[5];
	FILE* file;
} FileInfo;


int main(int argc, char* argv[])
{
	int sd, cd, msglen;
	struct sockaddr_in addr;
	FileInfo ForSend;

	sd = socket(AF_INET, SOCK_STREAM, 0);
	if (sd < 0)
	{
		perror("Error calling socket");
		return __LINE__;
	}

	addr.sin_family = AF_INET;
	addr.sin_port = htons(2022);
	addr.sin_addr.s_addr = inet_addr("0.0.0.0");

	if (bind(sd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
	{
		perror("Bind");
		return __LINE__;
	}

	if (listen(sd, 5))
	{
		perror("Listen");
		return __LINE__;
	}

	if ((cd = accept(sd, NULL, NULL)) < 0)
	{
		perror("Accept");
		return __LINE__;
	}


		msglen = recv(cd, &ForSend, sizeof(ForSend), 0);
		printf("%d\n%s\n", ForSend.size, ForSend.name);

		char strok[ForSend.size];
		msglen = recv(cd, strok, ForSend.size, 0);

		FILE* fout = fopen(ForSend.name, "wb");
		fwrite(strok, sizeof(char), ForSend.size, fout);

	fclose(fout);
	close(cd);
	close(sd);
}
