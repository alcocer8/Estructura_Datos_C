#define F "Student.dat"
#define READ "rb+"
#define WRITE "wb+"
#define APPEND "ab+"

//Struct Student
typedef struct Student{
	int i;
	char name[20];
}Student;

Student make_student(){
	Student s;
	printf("Ingresa el ID: "); scanf("%i", &s.i);
	printf("Ingresa el nombre: "); scanf("%s", s.name);
	return s;
}

void show_student(Student s){
	printf("ID: %i\n", s.i);
	printf("Name: %s\n", s.name);
}

void read_file(FILE *file){
	Student s;
	while(!feof(file)){
		if(!fread(&s, sizeof(Student), 1, file))
			break;
		show_student(s);
	}
}

// Open File
FILE* open_file(char name_file[], char *open){
	FILE *file = fopen(name_file, open);
	if (!file)
	{
		printf("Error apertura de archivo\n");
		return NULL;
	}
	return file;
}

int add_student(){
	FILE *file = open_file(F, APPEND);
	Student s = make_student();
	fwrite(&s, sizeof(Student), 1, file);
	printf("Insert Value\n");
	fclose(file);
	return 0;
}

int delete_student(){
	FILE *file = open_file(F, READ);
	FILE *newfile = open_file("new.dat", "wb+rb");
	Student s;
	int n = 0;

	printf("Ingrese el ID buscado: "); scanf("%i", &n);

	while(!feof(file)){
		if(!fread(&s, sizeof(Student), 1, file) || n == s.i)
			continue;
		fwrite(&s, sizeof(Student), 1, newfile);
	}
	
	fclose(file);
	fclose(newfile);
	
	remove(F);
	rename("new.dat", F);
}

int print_students(){
	FILE *file = open_file(F, READ);
	read_file(file);
	fclose(file);
}

void search_student(){
	int n = 0;
	printf("Ingrese el ID: "); scanf("%i", &n);
	Student s;
	FILE *file = open_file(F, READ);

	while(!feof(file)){
		if(!fread(&s, sizeof(Student), 1, file) || n == s.i)
			break;
	}

	if (n != s.i)
	{
		printf("El estudiante no existe\n");
		return;
	}
	show_student(s);
	fclose(file);
}
