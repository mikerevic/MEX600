/*
 ============================================================================
 Name        : Common_Car_Function.c
 Author      : RT-RK
 Version     : 1.00.000
 Copyright   : Bojan Mikerevic
 Description : RACE in C
 ============================================================================
 */
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include "Common.h"
#define DEBUG 1

void setStartPosition(car* array, raceTracks* rt) {
	int i;

	char line[1024];
	FILE *fp = fopen("Start_Position_File.txt", "r");

	for (i = 0; i < 9; i++) {
		fgets(line, 30, fp);
		char a = line[4];
		array[i].IDCar = a - '0';

		char b = line[10];
		array[i].row = b - '0';
		char c = line[19];
		array[i].column = c - '0';
		rt->tracks[array[i].column][array[i].row] = array[i].IDCar;
		char d = line[27];
		array[i].tires = d - '0';

	}
}
/*
 ============================================================================
 Name        : Common_Car_Function.c
 Author      : RT-RK
 Version     : 1.00.000
 Copyright   : Vanja Prpos
 Description : RACE in C
 ============================================================================
 */
int setWeatherCondition() {
	srand(time(NULL));
	int weatherCondition = rand() % 2;
	return weatherCondition;
}

void setGenerator(raceTracks* raceTrack1, car* array) {
	int generator;
	double step;
	int i;
	for (i = 0; i < 9; i++) {
		if (raceTrack1->weatherCondition == 0) {
			srand(time(NULL));
			generator = 7 + rand() % 3;
			if (array[i].tires == 0) {
				step = generator;
				array[i].step = step;
			} else {
				step = generator * 0.8;
				array[i].step = step;
			}
		} else {
			srand(time(NULL));
			generator = 3 + rand() % 3;

			if (array[i].tires == 0) {
				step = generator * 0.7;
				array[i].step = step;
			} else {
				step = generator;
				array[i].step = step;
			}
		}
	}
}
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
/*
 ============================================================================
 Name        : Common_Car_Function.c
 Author      : RT-RK
 Version     : 1.00.000
 Copyright   : Vesna Malic
 Description : RACE in C
 ============================================================================
 */
int v;
int noOfLaps = 0;
pthread_mutex_t count_mutex0;
pthread_mutex_t count_mutex1;
pthread_mutex_t count_mutex2;
pthread_mutex_t count_mutex4;
int pom = 0;
void* move(void* param1) {
	parametar* rt = (parametar*) param1;
	car* car1 = rt->car1;
	raceTracks* racetrack = rt->raceTrack;

	while (1) {

		int y = car1->row;
		int x = car1->column;

		int currentStep = car1->step;

		while (currentStep > 0) {

			pthread_mutex_lock(&count_mutex0);
			if ((racetrack->tracks[x][y + 1] != 0)) {
				if (currentStep > 1) {
					y += 2;
//					if (y < 100) {
						racetrack->tracks[x][y + 2] = car1->IDCar;
						racetrack->tracks[x][y] = 0;
						car1->row += 2;
						currentStep -= 2;
//					}
//					else {
//						noOfLaps++;
//						//ako je noOfLaps-1=numberOfLaps onda ga unesi u fajl
//					}


				} else {
					break;
				}
			} else {
				racetrack->tracks[x][y + 1] = car1->IDCar;
				racetrack->tracks[x][y] = 0;
				car1->row++;
				y++;
				currentStep--;
			}
			pthread_mutex_unlock(&count_mutex0);

		}

		pthread_mutex_lock(&count_mutex4);
		ispisMatrice(racetrack->tracks);
		if (DEBUG) {
			printf("*%d  korak %d\n", car1->IDCar, car1->step);
			printf("----------------------");
			printf("pom je: %d\n", pom);
		}
		pom++;
		if (pom ==0) {
			printf("usao u if");
			break;

		}
		pthread_mutex_unlock(&count_mutex4);
		v += car1->step;
		sleep(1);
	}
}
