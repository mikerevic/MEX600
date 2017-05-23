/*
 ============================================================================
 Name        : Common.h
 Author      : RT-RK
 Version     : 1.00.000
 Copyright   : Your copyright notice
 Description : RACE in C
 ============================================================================
 */

void* move(void* param1);
typedef struct raceTracks {
	int tracks[3][100];
//	int* end_position;
//	int* end_position;
//	int* end_position;

} raceTracks;

typedef struct car {
	int IDCar;
	int row;
	int column;
} car;


typedef struct parametar {
	car* car1;
	raceTracks* raceTrack;
}parametar;

typedef struct race { //trka
	char* date;
	int numberOfLaps;

} race;


