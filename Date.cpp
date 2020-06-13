#include "Date.h"
#include <iomanip>
#include <stdexcept>

using namespace std;

// конструктор по-умолчанию
Date::Date() : year(1970), month(1), day(1) {};

// конструктор выбрасывает исключение, если его аргументы некорректны
Date::Date(int new_year, int new_month, int new_day) {
  
  //год может быть любым
  year = new_year;	

  //проверка значения месяца
  if (new_month > 12 || new_month < 1) {
    throw logic_error("Month value is invalid: " + to_string(new_month));
  }
  month = new_month;

  //проверка значения дня
  if (new_day > 31 || new_day < 1) {
    throw logic_error("Day value is invalid: " + to_string(new_day));
  }
  day = new_day;
}

// TODO: зачем теперь эти методы
int Date::GetYear() const 	{ return year; }
int Date::GetMonth() const 	{ return month; }
int Date::GetDay() const 	  { return day; }


ostream& operator<< (ostream& out, const Date& date) {
	  out << setw(4) << setfill('0') << date.year << "-"
			  << setw(2) << setfill('0') << date.month << "-"
        << setw(2) << setfill('0') << date.day;
	  return out;
}

bool operator== (const Date& lhs, const Date& rhs) {
  return (lhs.year == rhs.year && lhs.month == rhs.month && lhs.day == rhs.day);
}

bool operator< (const Date& lhs, const Date& rhs) {
  // воспользуемся тем фактом, что векторы уже можно сравнивать на <:
  // создадим вектор из года, месяца и дня для каждой даты и сравним их
  return vector<int>{lhs.year, lhs.month, lhs.day} < vector<int>{rhs.year, rhs.month, rhs.day};
}

Date ParseDate(istringstream& date_stream) {
  bool ok = true;

  int year;
  ok = ok && (date_stream >> year);			// забираем год
  ok = ok && (date_stream.peek() == '-');	// проверяем разделитель
  date_stream.ignore(1);

  int month;
  ok = ok && (date_stream >> month);		// забираем месяц
  ok = ok && (date_stream.peek() == '-');	// проверяем разделитель
  date_stream.ignore(1);

  int day;
  ok = ok && (date_stream >> day);			// забираем день
  ok = ok && (date_stream.peek() == ' ');	// проверяем пробел в конце Даты

  if (!ok) {
    throw logic_error("Wrong date format: " + date_stream.str());
  }
  return Date(year, month, day);
}
