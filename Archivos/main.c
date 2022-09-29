#include <stdio.h>
#include <stdlib.h>
#include "students.h"

void show_options(int *opc){
	printf("---------- Base de datos Student ----------\n");
	printf("1. Add Student\n");
	printf("2. Delete Student\n");
	printf("3. Modify Student\n");
	printf("4. Search Student\n");
	printf("5. Sort Students\n");
	printf("6. Print Students\n");
	printf("7. Clear List\n");
	printf("8. Exit\n");
	scanf("%i", opc);
}

void menu_switch_case(int opc){
	switch(opc){
		case 1: add_student(); break;
		case 2: delete_student(); break;
		case 3: printf("modify_student\n"); break;
		case 4: search_student(); break;
		case 5: printf("Sort_list\n"); break;
		case 6: print_students(); break;
		case 7: printf("Clear_list.\n"); break;
		case 8: printf("Bye.\n"); break;
		default: printf("Try Again\n"); break;
	}
}

void menu_student(){
	int opc = 0;
	while(opc != 8){
		show_options(&opc);
		menu_switch_case(opc);
	}
}

int main(int argc, char const *argv[])
{
	menu_student();
	return 0;
}