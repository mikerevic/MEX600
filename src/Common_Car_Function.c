/*
 ============================================================================
 Name        : Common_Car_Function.c
 Author      : RT-RK
 Version     : 1.00.000
 Copyright   : Your copyright notice
 Description : RACE in C
 ============================================================================
 */
#include <stdio.h>
#include "Common.h"

int Set_Start_Position() {

	char line[1024];
	FILE *fp = fopen("Star_Postion_File.txt", "r");

	//Checks if file is empty
	if (fp == NULL) {
		return 1;
	}

	while (fgets(line, 25, fp)) {
		printf("%s\n", line);
	}

	return 0;
}

void* print(void* param) {
	car* current = (car*)param;

}

