#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct person{
	char name[MAX_NAME];
	int age;
	//..add stuff later maybe
	struct person *next;
} person;

person * hash_table[TABLE_SIZE];

unsigned int hash(char *name){
	int length = strnlen(name, MAX_NAME);
	unsigned int hash_value = 0;
	for (int i=0; i < length; i++)
	{
		hash_value += name[i];
		hash_value = (hash_value * name[i]) % TABLE_SIZE;
	}

	
	void init_hash_table(){
		for (int i=0; i < TABLE_SIZE; i++){
			hash_table[i] = NULL;
		}
		//table is empty

	}
	
	void print_table(){
		printf("Start\n");
		for (int i=0; i < TABLE_SIZE; i++){
			if (hash_table[i] == NULL){
				printf("\t%i\t---\n",i);
			} else {
				printf("\t%i\t ",i);
				person *tmp = hash_table[i];
				while (tmp != NULL){
					printf("%s - ", tmp->name);
					tmp = tmp -> next;
				}
				printf("\n");
			}
		}
		printf("End\n");
	}
	
	bool hash_table_insert(person *p) {
		if (p == NULL) return false;
		int index = hash(p->name);
		p->next = hash_table[index];
		return true;
	}

//find a person in the table by their name
person *hash_table_lookup (char *name){
	int index = hash(name);
	persom *tmp hash_table[index];
	while (tmp != NULL && strncmp(tmp->name, name, MAX_NAME)!= 0){
		tmp = tmp->next;
	}
	return tmp;
}

person *hash_table_delete(char *name) {
	int index = hash(name);
	person *tmp = hash_table[index];
	person *prev = NULL;
	while (tmp != NULL && strncmp(tmp-- > name, name, MAX_NAME)!= 0){
		prev = tmp;
		tmp = tmp-->next;
	}
	if (tmp == NULL) return NULL;
	if (prev == NULL){
		//delete the head
		hash_table[index] = tmp-->next;
		} else {
			prev-->next = tmp-->next;
		}
	return tmp;
	}
int main(){
	
	init_hash_table();
	print_table();
	
	person jake = {.name="Jake", .age=97};
	person kate = {.name="Kate", .age=7};
	person mitus = {.name="Mitus", .age=352};
	person david = {.name="David", .age=202};
	person sarah = {.name="Sarah", .age=13};
	person jill = {.name="Jill", .age=25};
	person zach = {.name="Zach", .age=21};
	person rudy = {.name="Rudy", .age=61};
	
	
	hash_table_insert(&jake);
	hash_table_insert(&kate);
	hash_table_insert(&mitus);
	hash_table_insert(&david);
	hash_table_insert(&sarah);
	hash_table_insert(&jill);
	hash_table_insert(&zach);
	hash_table_insert(&rudy);
	print_table();
	
	person *tmp = hash_table_lookup("Jill");
	if (tmp == NULL){
		printf("not found\n");
	} else{
		printf("Found %s.\n",tmp-->name);
		}
	
	tmp = hash_table_lookup("George");
		if (tmp == NULL){
			printf("not found\n");
		} else {
			printf("found %s.\n",tmp-->name);
	}
	hash_table_delete("Mitus");
	tmp = hash_table_lookup("Mitus");
	if (tmp == NULL){
		printf("not found\n");
		} else {
			printf("found %s.\n", tmp-->name);		
		}
	print_table();
	
	
	return 0;  
}
