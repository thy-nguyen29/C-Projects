#pragma once

#ifndef COSEWIC_H
#define COSEWIC_H

#define MAX_NAME 20
#define MAX_SPECIES 10
#define STARTING_YEAR 2010
#define ENDING_YEAR 2019

/************************************/
/*          STRUCTURES             */
/**********************************/

typedef struct  
{
	int	 year;
	char taxOn[MAX_NAME + 1];
	char status[MAX_NAME + 1];
	int  countData;
	char province[MAX_NAME + 1];
}FileData;

typedef struct 
{
	int year;
	int extinct, extirpated, endangered, threatened, concern, total;
}DataByYear;

typedef struct 
{
	char province[MAX_NAME + 1];
	int extinct, extirpated, endangered, threatened, concern, total;
}DataByProvince;

typedef struct 
{
	char taxon[MAX_NAME + 1];
	int extinct, extirpated, endangered, threatened, concern, total;
}DataByTaxon;


/************************************/
/*       FUNCTION PROTOTYPES       */
/**********************************/

void clearInputBuffer(void);
int inputInt(void);
int inputIntRange(int lowerBound, int upperBound);
int loadData(char* DATA_FILE, FileData* data, int MAX_RECORDS);
void mainLogic(FileData* data, int records);
void displayDataByYear(FileData* data, int records);
void displayDataByProvince(FileData* data, int records);
void displayDataByTaxon(FileData* data, int records);
void displayByProvinceAndTaxon(FileData* data, int records);
#endif