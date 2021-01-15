#include <iostream>
#include <cstdlib>
#define ROWS 10
#define COLS 10

using namespace std;

void initArray(char life[ROWS][COLS]);
void showArray(char life[ROWS][COLS]);

int main()
{
	char life[ROWS][COLS] = {0};
	
	initArray(life);
	showArray(life);

    return 0;
}

void initArray(char life[ROWS][COLS])
{
	int randomNumber = 0;
	
	for (int i = 0; i < ROWS; i++){
		for(int j = 0; j < COLS; j++){
		   	randomNumber = rand() % 100;		
    		if(randomNumber < 50){
    			life[i][j] = '#';
    		}
    		else {
    			life[i][j] = ' ';
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
}
