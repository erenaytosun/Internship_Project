


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <errno.h>
#include <ctype.h>



typedef struct list {
    int no;
    char *name;
    char *company;
    struct list *next;
} list_t;
list_t *head = NULL, *new, *temp, *temp1, *end;



void add_function_items (int no, char *name)
{
	new = malloc(sizeof(list_t));
	memset(new, 0, sizeof(list_t));
	// new = calloc(1, sizeof(list_t));
	new -> no = no;
	new -> name = strdup(name);
	new -> next == NULL;
	if (head == NULL) {
		head = new;
	} else {
		temp = head;
		while (temp -> next != NULL) {
			temp = temp -> next;
		}
		temp -> next = new;
	}
}



double time_difference (struct timeval before, struct timeval after)
{
	if (after.tv_sec == before.tv_sec) {
		return (after.tv_usec - before.tv_usec) / 1000000.0;
	} else {
		if (after.tv_usec > before.tv_usec) {
			return (after.tv_sec - before.tv_sec) + (after.tv_usec - before.tv_usec) / 1000000.0;
		} else {
			return (after.tv_sec - before.tv_sec - 1) +  (1000000 - (before.tv_usec - after.tv_usec)) / 1000000.0;
		}
	}
}



void add_new_student ()
{
	int number;
	char name[128];
	printf("Add Number: \n");
	scanf("%d", &number);
	printf("\nAdd Name : \n");
	scanf("%s", name);
	add_function_items(number, name);
}



float human_friendly_time (double time) {
	int minute = time / 60;
	int seconds = time ;
	seconds = seconds % 60 ;
	float result = (float)seconds / 60;
	result = result + minute;
	return result;
}


void add_sizeof_items (int sizeof_array, int percentof_function, char *file_nameof_function)
{
	int size = sizeof_array;
	char file_name[1024];
	strcpy(file_name, file_nameof_function);
	int percent = percentof_function;
	int control;
	int counterof_file = 0;
	int controlof_file = 0;
	int numberof_lamps = 0;
	int comparison = 0;
	double time_2;
	double time_3;
	double time_4;
	struct timeval t1, t2;


	FILE *textfiles;
	char string_array[1024];
	textfiles = fopen(file_name, "r");

	if (textfiles == NULL) {
		printf("File not found..\n");
		exit(0);
	}

	int c = fgetc(textfiles);
	if (c < 0) {
		printf("File is empty...\n");
		exit(0);
	}

	while (!feof(textfiles)) {
		fscanf(textfiles, "%s", string_array);
		counterof_file++;
	}
	int count = (size / 100) * percent;
	int computation = count;
	int multiple = 1;
	counterof_file = counterof_file - 1;
	int elementsize_infile = counterof_file;

	if (counterof_file < size) {
		numberof_lamps = (size / counterof_file) + 2 ;
	}
	gettimeofday(&t1, NULL);

	counterof_file = 1;
	if (numberof_lamps == 0) {

		if (size > 0) {

			int count_2 = (size / 100) * percent;
			int computation_2 = count_2;
			FILE *textfiles_3;
			textfiles_3 = fopen(file_name, "r");

			for (int m = 1; m < size + 1; m++) {

				fscanf(textfiles_3, "%s", string_array);
				char value[1024];
				snprintf(value, 1024, "%d-", 1);
				strcat(value, string_array);
				controlof_file = 1;

				if (counterof_file >= size+1) {
					break;
				}

				if (counterof_file == computation_2 && multiple * percent < 100) {
					comparison++;
					gettimeofday(&t2, NULL);
					double time = time_difference(t1, t2);
					system("clear");

					if (time >= 60) {
						printf("[%% %d compleded ...The passing time : %.2lf minute]\n",(percent*multiple), human_friendly_time(time));
					} else {
						printf("[%% %d compleded ...The passing time : %.1lf seconds]\n",(percent*multiple), time);
					}


					time_2 = ((time / ((percent * multiple)*0.90)) * ((multiple +1) * percent)) - time;

					if (time_2 >= 60) {
						printf("Estimated time for next step : %.2lf minute\n\n", human_friendly_time(time_2));
					} else {
						printf("Estimated time for next step : %.1lf seconds\n\n", time_2);
					}
					//printf("Estimated time for next step : %.2lf minute \n", human_friendly_time(time_2));

					if (comparison == 1) {
						time_3 = (( time / percent ) * 2.5 * 1400) ;
					}
					time_4 = (time_3) - (time);

					if (time_4 >= 60) {
						printf("Estimated time to complete Function : %.2lf minute\n\n", human_friendly_time(time_4));
					} else {
						printf("Estimated time to complete Function : %.1lf seconds\n\n", time_4);
					}
					//printf("Estimated time to complete Function : %.2lf minute\n\n", human_friendly_time(time_4));

					multiple++;
					computation = computation + count;
				}
				add_function_items(counterof_file, value);
				counterof_file++;
			}
			fclose(textfiles_3);
		}
	}
	for (int i = 1; i < numberof_lamps; i++) {

		FILE *textfiles_2;
		textfiles_2 = fopen(file_name, "r");

		for (int j = 0; j < elementsize_infile; j++) {

			fscanf(textfiles_2, "%s", string_array);
			char value[1024];
			snprintf(value, 1024, "%d-", i);
			strcat(value, string_array);
			controlof_file = 1;

			if (counterof_file >= size+1) {
				break;
			}

			if (counterof_file == computation && multiple * percent < 100) {

				comparison++;
				gettimeofday(&t2, NULL);
				double time = time_difference(t1, t2);
				system("clear");

				if (time >= 60) {
					printf("[%% %d compleded ...The passing time : %.2lf minute]\n\n",(percent*multiple), human_friendly_time(time));
				} else {
					printf("[%% %d compleded ...The passing time : %.1lf seconds]\n\n",(percent*multiple), time);
				}


				time_2 = ((time / ((percent * multiple) * 0.90)) * ((multiple +1) * percent)) - time;

				if (time_2 >= 60) {
					printf("Estimated time for next step : %.2lf minute\n\n", human_friendly_time(time_2));
				} else {
					printf("Estimated time for next step : %.1lf seconds\n\n", time_2);
				}
				//printf("Estimated time for next step : %.2lf minute\n", human_friendly_time(time_2));

				if (comparison == 1) {
					time_3 = (( time / percent ) * 2.9 * 1450) ;
				}
				time_4 = (time_3) - (time);

				if (time_4 >= 60) {
					printf("Estimated time to complete Function : %.2lf minute\n\n", human_friendly_time(time_4));
				} else {
					printf("Estimated time to complete Function : %.1lf seconds\n\n", time_4);
				}
				//printf("Estimated time to complete Function : %.2lf minute\n\n", human_friendly_time(time_4));

				multiple++;
				computation = computation + count;
			}
			add_function_items(counterof_file, value);
			counterof_file++;
		}

		fclose(textfiles_2);
	}
	gettimeofday(&t2, NULL);
	double time = time_difference(t1, t2);

	if(time >= 60) {
		printf("[%% %d compleded ...The passing time : %.2lf minute]\n", 100, human_friendly_time(time));
	} else {
		printf("[%% %d compleded ...The passing time : %.1lf seconds]\n", 100, time);
	}
	//printf("[%% %d compleded ...The passing time : %.2lf minute]\n", 100, human_friendly_time(time));
	fclose(textfiles);

}



void print_list ()
{
	if (head == NULL) {
		printf("List is empty...\n");
	}
    temp = head;
    while (temp != NULL) {
        printf("%d\t%s\n", temp -> no, temp -> name );
        temp = temp -> next;
    }
}



void destroy_item (list_t *item)
{
	if (item == NULL) {
		return;
	}
	free(item -> name);
	free(item -> company);
	free(item);
}



void delete (char arr[])
{
	char *str1 = head -> name;
	int control = 0;
	if (head == NULL) {
		control = 1;
	} else if (strcmp(str1, arr) == 0) {
		temp = head;
		head = head->next;
		destroy_item(temp);
		control = 10;
	}
	else {
		end = head;
		while (end->next != NULL) {
			end = end -> next;
		}
		temp = head;
		while (temp -> next != NULL) {
			char *str2 = temp -> next -> name;
			if (strcmp(str2, arr) == 0) {
				temp1 = temp -> next;
				control = 10;
				if (temp1 == end) {
					end = temp;
				}
				temp -> next = temp1 -> next;
				destroy_item(temp1);
				break;
			}
			temp = temp -> next;
		}
	}
	if (control == 0) {
		printf("This number is not in the list...\n");
	}
	if (control == 1) {
		printf("List is empty...\n");
	}
}



void search_by_no (int no)
{
	int control = 0;
	if (head == NULL) {
		control = 1 ;
	} else {
		temp = head;
		while (temp != NULL) {
			if (temp -> no == no) {
				printf("%d is in the list...Name : %s\n ", no, temp->name);
				control = 99;
				break;
			}
			temp = temp -> next;
		}
	}
	if (control == 0) {
		printf("This number is not in the list...\n");
	}
	if (control == 1) {
		printf("List is empty...\n");
	}
}



void search_by_name (char *name)
{
	int control = 0;
	int count = 0;
	if (head == NULL) {
		control = 1 ;
	} else {
		temp = head;
		while (temp != NULL) {
			char *str = temp -> name;
			if (strcmp(str, name) == 0) {
				printf("%s is in the list... At index : %d\n ", name, count);
				control = 99;
				break;
			}
			temp = temp -> next;
			count++;
		}
	}
	if (control == 0) {
		printf("This name is not in the list...\n");
	}
	if (control == 1) {
		printf("List is empty...\n");
	}
}


void search_by_name_2 (char *name)
{
	int control = 0;
	int count = 0;
	if (head == NULL) {
		control = 1 ;
	} else {
		temp = head;
		while (temp != NULL) {
			char *str = temp -> name;
			if (strcmp(str, name) == 0) {
				//printf("%s is in the list... At index : %d\n ", name, count);
				control = 99;
				break;
			}
			temp = temp -> next;
			count++;
		}
	}
	if (control == 0) {
		printf("This name is not in the list...\n");
	}
	if (control == 1) {
		printf("List is empty...\n");
	}
}



void delete_function()
{
	temp = head;
	while (temp != NULL) {
		delete(temp -> name);
		temp = head;
	}
}



void message ()
{
	printf("Wrong Number...Please try again...\n");
}



void message_string ()
{
	printf("Please enter numbers...Please try again...\n");
}



void delete_all_items ()
{
	struct timeval t1, t2;
	gettimeofday(&t1, NULL);
	delete_function();
	gettimeofday(&t2, NULL);
	double result = time_difference(t1, t2);
	if (result >= 60) {
		printf("result : %.2lf minute\n\n", human_friendly_time(result));
	} else {
		printf("result : %.1lf seconds\n\n", result);
	}
}



void short_add_function(int sizeof_array, int percentof_function, char *file_nameof_function)
{
	int size = sizeof_array;
	int percent = percentof_function;
	char file_name[1024];
	strcpy(file_name, file_nameof_function);

	struct timeval t1, t2;
	gettimeofday(&t1, NULL);
	add_sizeof_items(size ,percent, file_name);
	gettimeofday(&t2, NULL);
	double result = time_difference(t1, t2);
	if (result >= 60) {
		printf("result : %.2lf minute\n\n", human_friendly_time(result));
	} else {
		printf("result : %.1lf seconds\n\n", result);
	}
	//printf("result : %.2lf minute\n\n", human_friendly_time(result));
}



void short_search_no ()
{
	int search_no;
	struct timeval t1, t2;
	printf("Which number should be found : \n");
	scanf("%d", &search_no);
	gettimeofday(&t1, NULL);
	search_by_no(search_no);
    gettimeofday(&t2, NULL);
	double result = time_difference(t1, t2);
	printf("result : %.2lf seconds\n\n", result);
}



void short_search_name ()
{
	char search_name[1024];
	struct timeval t1, t2;
	printf("Which name should be found : \n");
	scanf("%s", search_name);
	gettimeofday(&t1, NULL);
    search_by_name(search_name);
	gettimeofday(&t2, NULL);
	double result = time_difference(t1, t2);
	printf("result : %.2lf seconds\n\n", result);
}



void search_all_name ()
{
	temp = head;
	while (temp != NULL) {
		search_by_name_2(temp -> name);
		temp = temp -> next;
	}
}



void short_search_all_name ()
{
	struct timeval t1, t2;
	gettimeofday(&t1, NULL);
	search_all_name();
	gettimeofday(&t2, NULL);
	double result = time_difference(t1, t2);
	if (result >= 60) {
		printf("result : %.2lf minute\n\n", human_friendly_time(result));
	} else {
		printf("result : %.1lf seconds\n\n", result);
	}
}



int menu ()
{
	char choice[128];
	printf("\n[1]: Add\n[2]: List\n[3]: Delete All\n[4]: Add İtems\n[5]: Search_by_no \n[6]: Search_by_name \n[7]: Search_all_Name\n[8]: Quit\n");
	scanf("%s", choice);
	int size = strlen(choice);
	for (int i = 0; i < size; i++) {
		if (isdigit(choice[i]) == 0) {
			strcpy(choice, "9");
			break;
		}
	}
	int result = atoi(choice);
	return result;
}



int main (int argc, char *argv[])
{
	int size = atoi(argv[1]);
	char file_name[1024];
	strcpy(file_name, argv[2]);
	int percent;
	if (argv[3] != NULL) {
		percent = atoi(argv[3]);
	} else {
		percent = 10;
	}
	printf("array size : %d\t txt_name : %s\t percent : %d\n", size, file_name, percent);
	int choice;

	while (choice != 8) {

		choice = menu();
		switch (choice) {
			case 1:
				add_new_student();
				break;
			case 2:
				print_list();
				break;
			case 3:
				delete_all_items();
				break;
			case 4:
				short_add_function(size ,percent, file_name);
				break;
			case 5:
				short_search_no();
				break;
			case 6:
				short_search_name();
				break;
			case 7:
				short_search_all_name();
				break;
			case 8:
				break;
			case 9:
				message_string();
				break;
			default:
				message();
				break;
			}
		}
	return 0;

}

