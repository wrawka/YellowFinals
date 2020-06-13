#ifndef DATABASE_H_
#define DATABASE_H_

#include "Date.h"
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Database {
public:
	/*
	 * Встретив команду Add date event, ваша программа
	 * должна добавить пару (date, event) в базу данных
	 */
	void Add(const Date& date, const string& event);

	/*
	 * Встретив команду Print, ваша программа должна вывести
	 * все пары (дата, событие), которые в данный момент
	 * содержатся в базе данных. Пары надо выводить по одной в строке.
	 * Они должны быть отсортированы по дате по возрастанию.
	 * События в рамках одной даты необходимо выводить в порядке добавления
	 * (за исключением уже удалённых и попыток добавления повторов).
	 */
	void Print(ostream& os) const;

	/*
	 * По команде Last date нужно вывести
	 * последнее из событий, случившихся к дате date.
	 */
	pair<Date, string> Last(Date date);

	/*
	 * Встретив команду Find condition, ваша программа
	 * должна вывести все пары (дата, событие),
	 * которые в данный момент содержатся в базе данных
	 * и удовлетворяют условию condition.
	 */

	// bool predicate(const Date &date, const std::string &event)
	// template <typename F>
	vector< pair<Date, string> > FindIf(function < bool(const Date &date, const std::__cxx11::string &event) > pred);

	/*
	 * Встретив команду Del condition, ваша программа должна удалить
	 * из базы данных все события, удовлетворяющие условию condition
	 */

	int RemoveIf(function < bool(const Date &date, const std::__cxx11::string &event) > pred);

private:
	map< Date, set<string> > storage;
	map< Date, vector<string> > ordered_storage;
};




#endif /* DATABASE_H_ */
