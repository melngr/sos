#include <string>
#include <vector>
#include "Dungeon.h"




void Dungeon::progressToNextDay(){
	currDay->moveForwardOneDay();
}

void Dungeon::subtractHrs(float numHrs){
	float& currHrs = currDay->hoursOfDay_;
	if(numHrs >= currHrs){
		float remainder = numHrs - currHrs;
		progressToNextDay(); //make day move to the next day
		subtractHrs(remainder);
	}else{
		currHrs -= numHrs;
	}
}
