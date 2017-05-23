/*
 ============================================================================
 Name        : MEX600.c
 Author      : RT-RK
 Version     : 1.00.000
 Copyright   : Your copyright notice
 Description : CAR RACE in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "Common.h"

pthread_t ID_1,ID_2,ID_3,ID_4,ID_5,ID_6,ID_7,ID_8,ID_9;

car Car1, Car2, Car3, Car4, Car5, Car6, Car7, Car8, Car9;





int main(void) {
	pthread_create(&ID_1,NULL,NULL,NULL);
	pthread_create(&ID_2,NULL,NULL,NULL);
	pthread_create(&ID_3,NULL,NULL,NULL);
	pthread_create(&ID_4,NULL,NULL,NULL);
	pthread_create(&ID_5,NULL,NULL,NULL);
	pthread_create(&ID_6,NULL,NULL,NULL);
	pthread_create(&ID_7,NULL,NULL,NULL);
	pthread_create(&ID_8,NULL,NULL,NULL);
	pthread_create(&ID_9,NULL,NULL,NULL);

	pthread_join (ID_1, NULL);
	pthread_join (ID_2, NULL);
	pthread_join (ID_3, NULL);
	pthread_join (ID_4, NULL);
	pthread_join (ID_5, NULL);
	pthread_join (ID_6, NULL);
	pthread_join (ID_7, NULL);
	pthread_join (ID_8, NULL);
	pthread_join (ID_9, NULL);





	Set_Start_Position ();
	return EXIT_SUCCESS;
}
