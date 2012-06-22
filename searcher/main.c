#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>

int main(int argc, char** argv){

	int length;
	FILE* fp;
	FILE* database;

	char* string;
	char* tempstring;
	char* deststr;
	char finalstr[100];

	fp= fopen("./../parser/result.txt", "rt");
	database= fopen("pastdata.txt", "wt");

	fscanf(fp, "%d\n", &length);

	string= (char*) malloc(sizeof(char)*length);

	fread(string, sizeof(char), length, fp);
	for(int i= 1; i< argc; i++)
	{
		fprintf(database, "dest string:%s\n", argv[i]);
		tempstring= string;

		while((deststr=strstr(tempstring, argv[i]))!= NULL){
			memcpy(finalstr, deststr, 99);
			finalstr[99]= 0;
			printf("%s\n", finalstr);
			fprintf(database, "%s\n", finalstr);
			tempstring= deststr+1;
		}
	}
}
