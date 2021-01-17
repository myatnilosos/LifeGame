#include <iostream>
#include <cstdlib>
#define ALIVE '#'
#define DEAD ' '
#define ROWS 10
#define COLS 10

using namespace std;

void initArray(char life[ROWS][COLS]);
void showArray(char life[ROWS][COLS]);
void copyArray(char life[ROWS][COLS], char copy[ROWS][COLS]);
int countAliveCells(char life[ROWS][COLS], int i, int j);

int main()
{
	char life[ROWS][COLS] = {0}, copy[ROWS][COLS] = {0};
	bool flag = true;
		
	initArray(life);
	showArray(life);
	
	while(flag){
		flag = false;
		
		copyArray(life, copy);
	
		cout << endl;

		for(int i = 0; i < ROWS; i++){
			for(int j = 0; j < COLS; j++){
				if(copy[i][j] == DEAD and countAliveCells(copy, i, j) == 3){
					life[i][j] = ALIVE;
				}
				if((copy[i][j] == ALIVE and countAliveCells(copy, i, j) < 2) or (copy[i][j] == ALIVE and countAliveCells(copy, i, j) > 3)){
					life[i][j] = DEAD;
				}
			}
		}
		for(int i = 0; i < ROWS; i++){
			for(int j = 0; j < COLS; j++){
				if(copy[i][j] != life[i][j]){
					flag = true;
				}
			}
		}
		showArray(life);
	}
    return 0;
}

void initArray(char life[ROWS][COLS])
{
	int randomNumber = 0;
	
	for (int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
		   	randomNumber = rand() % 100;		
    		if(randomNumber < 50){
    			life[i][j] = ALIVE;
    		}
    		else {
    			life[i][j] = DEAD;
    		}
    	}
    }
}

void showArray(char life[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++){
    	for(int j = 0; j < COLS; j++){
	    	cout << life[i][j] << " "; 
	    }
	    cout << endl;
	}	
	cout << "-------------------" << endl;
}

void copyArray(char life[ROWS][COLS], char copy[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++){
    	for(int j = 0; j < COLS; j++)
			copy[i][j] = life[i][j];
	}
}

int countAliveCells(char life[ROWS][COLS], int i, int j)
{
	int counter = 0;
	
	if((i > 0 and j > 0) and (i < (ROWS - 1) and j < (COLS - 1))){
		counter = 0;
   		if(life[i-1][j] == ALIVE)
			counter++;
		if(life[i-1][j+1] == ALIVE)
			counter++;
   		if(life[i][j+1] == ALIVE)
			counter++;
		if(life[i+1][j+1] == ALIVE)
			counter++;
   		if(life[i+1][j] == ALIVE)
			counter++;
		if(life[i+1][j-1] == ALIVE)
			counter++;
   		if(life[i][j-1] == ALIVE)
			counter++;
		if(life[i-1][j-1] == ALIVE)
			counter++;
	}
	else if(i == 0 and (j > 0 and j < (COLS - 1))){
		counter = 0;
   		if(life[ROWS-1][j] == ALIVE)
			counter++;
    	if(life[ROWS-1][j+1] == ALIVE)
    		counter++;
	    if(life[i][j+1] == ALIVE)
    		counter++;
    	if(life[i+1][j+1] == ALIVE)
    		counter++;
	    if(life[i+1][j] == ALIVE)
    		counter++;
    	if(life[i+1][j-1] == ALIVE)
    		counter++;
	    if(life[i][j-1] == ALIVE)
    		counter++;
    	if(life[ROWS-1][j-1] == ALIVE)
    		counter++;
   	}
    else if(i == (ROWS - 1) and (j > 0 and j < (COLS - 1))){
    	counter = 0;
		if(life[i-1][j] == ALIVE)
    		counter++;
    	if(life[i-1][j+1] == ALIVE)
    		counter++;
		if(life[i][j+1] == ALIVE)
    		counter++;
    	if(life[0][j+1] == ALIVE)
    		counter++;
		if(life[0][j] == ALIVE)
    		counter++;
    	if(life[0][j-1] == ALIVE)
    		counter++;
		if(life[i][j-1] == ALIVE)
    		counter++;
    	if(life[i-1][j-1] == ALIVE)
    		counter++;
    }
    else if((i > 0 and i < (ROWS - 1)) and j == 0){
    	counter = 0;
		if(life[i-1][j] == ALIVE)
    		counter++;
    	if(life[i-1][j+1] == ALIVE)
    		counter++;
		if(life[i][j+1] == ALIVE)
    		counter++;
    	if(life[i+1][j+1] == ALIVE)
    		counter++;
		if(life[i+1][j] == ALIVE)
    		counter++;
    	if(life[i+1][COLS - 1] == ALIVE)
    		counter++;
		if(life[i][COLS - 1] == ALIVE)
    		counter++;
    	if(life[i-1][COLS - 1] == ALIVE)
    		counter++;
    }
    else if((i > 0 and i < (ROWS - 1)) and j == (COLS - 1)){
    	counter = 0;
    	if(life[i-1][j] == ALIVE)
    		counter++;
    	if(life[i-1][0] == ALIVE)
    		counter++;
		if(life[i][0] == ALIVE)
    		counter++;
    	if(life[i+1][0] == ALIVE)
    		counter++;
		if(life[i+1][j] == ALIVE)
    		counter++;
    	if(life[i+1][j-1] == ALIVE)
    		counter++;
		if(life[i][j-1] == ALIVE)
    		counter++;
    	if(life[i-1][j-1] == ALIVE)
    		counter++;
    }
    else if(i == 0 and j == 0){
    	counter = 0;
    	if(life[ROWS-1][j] == ALIVE)
    		counter++;
    	if(life[ROWS-1][j+1] == ALIVE)
    		counter++;
		if(life[i][j+1] == ALIVE)
    		counter++;
    	if(life[i+1][j+1] == ALIVE)
    		counter++;
		if(life[i+1][j] == ALIVE)
    		counter++;
    	if(life[i+1][COLS-1] == ALIVE)
    		counter++;
		if(life[i][COLS-1] == ALIVE)
    		counter++;
    	if(life[ROWS-1][COLS-1] == ALIVE)
    		counter++;
    }
    else if(i == 0 and j == (COLS - 1)){
    	counter = 0;
    	if(life[ROWS-1][j] == ALIVE)
    		counter++;
    	if(life[ROWS-1][0] == ALIVE)
    		counter++;
		if(life[i][0] == ALIVE)
    		counter++;
    	if(life[i+1][0] == ALIVE)
    		counter++;
		if(life[i+1][j] == ALIVE)
    		counter++;
    	if(life[i+1][COLS-1] == ALIVE)
    		counter++;
		if(life[i][COLS-1] == ALIVE)
    		counter++;
    	if(life[ROWS-1][j-1] == ALIVE)
    		counter++;
    }
    else if(i == (ROWS - 1) and j == (COLS - 1)){
    	counter = 0;
		if(life[i-1][j] == ALIVE)
    		counter++;
    	if(life[i-1][0] == ALIVE)
    		counter++;
		if(life[i][0] == ALIVE)
    		counter++;
    	if(life[0][0] == ALIVE)
    		counter++;
		if(life[0][j] == ALIVE)
    		counter++;
    	if(life[0][j-1] == ALIVE)
    		counter++;
		if(life[i][j-1] == ALIVE)
    		counter++;
    	if(life[i-1][j-1] == ALIVE)
    		counter++;
    }
    else if(i == (ROWS - 1) and j == 0){
    	counter = 0;
		if(life[i-1][j] == ALIVE)
    		counter++;
    	if(life[i-1][j+1] == ALIVE)
    		counter++;
		if(life[i][j+1] == ALIVE)
    		counter++;
    	if(life[0][j+1] == ALIVE)
    		counter++;
		if(life[0][j] == ALIVE)
    		counter++;
    	if(life[i+1][COLS-1] == ALIVE)
    		counter++;
		if(life[i][COLS-1] == ALIVE)
    		counter++;
    	if(life[i-1][COLS-1] == ALIVE)
    		counter++;
    }
    return counter;
}
