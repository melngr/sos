// #include <string>
// #include <vector>
// #include <iostream>
#include "Day.h"

const std::string Day::DAYS_OF_WEEK[WEEK_LENGTH] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };

/*  Standard toString operation.
 *  @param ostr, current outstream for program
 *  @param d, Day object to print
 *  @modifies ostr
 *  @effects Loads 'ostr' with all data available in 'd'.
 *  @return ostr
 */
std::ostream& operator<<(std::ostream& ostr, const Day& d){
	ostr << "PRINTING DAY OBJECT" << std::endl;
	ostr << "Hours Remaining: " << d._hoursOfDay << std::endl;
	ostr << "Index of current day: " << d._currDayInd << std::endl;
	ostr << "Current monster: " << *(d._currentMonster) << std::endl;
	ostr << "Current day of the week: " << d.DAYS_OF_WEEK[d._currDayInd] << std::endl;
	// for ( unsigned int i = 0; i < d.WEEK_LENGTH; ++i ) {
	//	ostr << (d.DAYS_OF_WEEK)[i] << std::endl;
	// }
	ostr << "END OF DAY OBJECT" << std::endl;
	return ostr;
};

