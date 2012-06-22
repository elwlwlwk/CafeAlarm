#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define false 0
#define true 1
#define bool int

int main(){

	FILE *fp;
	char *string;

	int length;
	bool inTag= false;
	
	fp= fopen("./../getchunkmodule/result.txt", "rt");
	if(fp== NULL){
		printf("cant find result.txt");
		exit(1);
	}

	fscanf(fp, "%d\n", &length);

	string= (char*)malloc(sizeof(char)*length);

	fread(string, sizeof(char), length, fp);

	fclose(fp);

	for(int i= 0; i<length; i++){
		if(string[i]== '<'&& inTag== false){
			inTag= true;
			string[i]= 20;
		}
		else if(string[i]== '>'&& inTag== true){
			inTag= false;
			string[i]= 20;
		}
		else if(inTag== true){
			string[i]= 20;
		}
	}
	
	fp= fopen("result.txt", "wt");
	fprintf(fp, "%d\n", length);
	fprintf(fp, "%s", string);
	fclose(fp);
	return 0;
}
