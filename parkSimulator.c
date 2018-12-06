
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "random437.h"

 int totalSimulationTime = 360000; //in ms, equivalent to 10hrs in 1s = 10ms environment
 int maxPerCar = 10;
 double timeToLoad = 7.0; //in s
 double timeForRide = 53.0; //in s
 int maxWaitPeople = 800;


 
bool isFordFull(int numOfPeople){
    if (numOfPeople < maxPerCar){
       return false;
    }
    else { return true;}
}

bool isWaitAreaFull(int numOfPeople){
    if (numOfPeople < maxWaitPeople){
       return false;
    }
    else { return true;}
}

bool isTimeForRideOver(int currentTime){
    int cTime = currentTime/ 10; //in s
    if (cTime < timeForRide){return false;}
    else{return true;}
}

bool isTimeToLoadOver(int currentTime){
    int cTime = currentTime/ 10; //in s
    if (cTime < timeToLoad){return false;}
    else{return true;}
}


int getMeanArrival(int currentTime){
    int oneSec = 10; //in ms
    int currentTimeInS = currentTime/oneSec;
    int cTime = (currentTimeInS / 3600) + 9;
    
    if (cTime >= 9 && cTime < 11)  {
       return 25;
    }
    
    else if (cTime >= 11 && cTime < 14) {
       return 45;
    }
    
    else if (cTime >= 14 && cTime < 16) {
       return 35;
    }

    else {
        return 25;
    }
}

int getNumOfPeople(int currentTime){
    int meanArrival = getMeanArrival(currentTime);
    return poissonRandom(meanArrival);
}

int main(){

 //design the waiting area

   
    int tempVal = 0, tempVal1 = 0, tempVal2 = 0, tempVal3 = 0;
    int msec = 0, trigger = 360000; /* 10ms */
    clock_t before = clock();
    int iterations = 0;

    do {
  
       clock_t difference = clock() - before;
       msec = difference * 1000 / CLOCKS_PER_SEC;
       iterations++;
       } while ( msec < trigger );

       printf("Time taken %d seconds %d milliseconds (%d iterations)\n",msec/10, msec%10, iterations);
      
        
       return 0;
}
