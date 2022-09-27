
#include <stdio.h>
#include <stdlib.h>

#define READ "rb"
#define WRITE "wb"
#define APPEND "ab"


typedef struct Persona
{
	int id;
	char name[20];
}Persona;


void printf_persona(Persona p){
	printf("ID: %i\n", p.id);
	printf("Name: %s\n", p.name);
}

FILE* open_file(char *file_name, char *type){
	FILE *new = fopen(file_name, type);

	if (!new)	
	{
		return NULL;
	}

	return new;
}

int write_file(char *file_name, Persona p){
	FILE *file = open_file(file_name, WRITE);

	if (!file)
	{
		return 0;
	}

	fwrite(&p, sizeof(Persona), 1, file);
	printf("Dato escrito. \n");
	fclose(file);
	return 1;
}

int append_file(char *file_name, Persona p){
	FILE *file = open_file(file_name, APPEND);

	if (!file)
	{
		return 0;
	}

	fwrite(&p, sizeof(Persona), 1, file);
	printf("Dato escrito. \n");
	fclose(file);
	return 1;
}


int read_file(char *file_name){
	FILE *file = open_file(file_name, READ);
	Persona p;
	if (!file)
	{
		return 0;
	}
	
	while(!feof(file)){
		if(!fread(&p, sizeof(Persona), 1, file))
			break;
		printf_persona(p);
	}

	fclose(file);
	return 1;	
}


int main(int argc, char const *argv[])
{
	return 0;
}