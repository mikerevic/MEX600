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
#include <string.h>
#include <pthread.h>
#include "Common.h"

void setStartPosition(car* array, raceTracks* rt) {
	int i;

	char line[1024];
	FILE *fp = fopen("Star_Postion_File.txt", "r");

	if (fp == NULL) {
		//
	}
	for (i = 0; i < 9; i++) { //dodjeljuje startnu poziciju i id autu citajuci iz fajla
		fgets(line, 25, fp);
		char a = line[4];
		array[i].IDCar = a - '0';

		char b = line[10];
		array[i].row = b - '0';
		char c = line[19];
		array[i].column = c - '0';
		rt->tracks[array[i].column][array[i].row] = array[i].IDCar; //dodavanje auta bna startnu poziciju

	}
}

//void sort(car* array) {
//	int i;
//	int j;
//	for (i = 0; i < 8; i++) {
//		for (j = i + 1; j < 9; j++) {
//			if (array[i].startPosition < array[j].startPosition) {
//				car tmp;
//				tmp = array[i];
//				array[i] = array[j];
//				array[j] = tmp;
//			}
//		}
//	}
//}

//void* print(void* param) {
//	car* current = (car*) param;
//	printf("%d\n", current->IDCar);
//}

void ispisMatrice(raceTracks* rt) {
	int i;
	int j;
	for (i = 0; i < 100; i++) {
		for (j = 0; j < 3; j++) {
			printf("%d\t", rt->tracks[j][i]);
		}
		printf("\n");
	}
}

pthread_mutex_t count_mutex;

void* move(void* param1) {
	parametar* rt = (parametar*) param1;
	car* car1 = rt->car1;
	raceTracks* racetrack = rt->raceTrack;
	pthread_mutex_lock(&count_mutex);
	int currentRow = car1->row;
	int currentColumn = car1->column;

	racetrack->tracks[currentRow-1][currentColumn] = 0;
	currentColumn  += rand() % 99;
	racetrack->tracks[currentRow][currentColumn] = car1->IDCar;
	ispisMatrice(racetrack->tracks);
	printf("------------------\n");
	printf("car1->IDCar %d-----\n",car1->IDCar);
	printf("------------------\n");

	pthread_mutex_unlock(&count_mutex);


}

