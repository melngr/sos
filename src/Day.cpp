#include <string>
#include <vector>
#include <iostream>
#include "Day.h"


const std::string Day::daysOfWeek_[WEEK_LENGTH] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

std::ostream& operator<<(std::ostream& ostr, const Day& d){
	ostr << "PRINTING DAY OBJECT" << std::endl;
	ostr << "Hours Remaining: " << d.hoursOfDay_ << std::endl;
	ostr << "Index of current day: " << d.currDayInd_ << std::endl;
	ostr << "Current day of the week: " << d.daysOfWeek_[d.currDayInd_] << std::endl;
	for(int i = 0; i < d.WEEK_LENGTH; i++){
		ostr << (d.daysOfWeek_)[i] << std::endl;
	}
	ostr<<"END OF DAY OBJECT" << std::endl;
};
