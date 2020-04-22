#ifndef DATE_H_
#define DATE_H_


#include <iostream>
#include <sstream>
#include <vector>

class Date {
public:
  Date(int new_year, int new_month, int new_day);

  int GetYear() const;
  int GetMonth() const;
  int GetDay() const;

  friend std::ostream& operator<< (std::ostream& out, const Date& date);
  friend bool operator== (const Date& lhs, const Date& rhs);
  friend bool operator< (const Date& lhs, const Date& rhs);

private:
  int year;
  int month;
  int day;
};

Date ParseDate(std::istringstream& date_stream);

#endif /* DATE_H_ */
