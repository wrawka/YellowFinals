#include "Database.h"


void Database::Add(const Date& date, const string& event) {
  vector<string>& this_date = ordered_storage[date];
  // проверить, случался ли event в этот date
  // если нет, то добавить и упорядочить
  if (find(this_date.begin(), this_date.end(), event) == this_date.end()) {
    this_date.push_back(event);
  }
}

void Database::Print(ostream& os) const {
  for (const auto& date : ordered_storage) {
    for (const auto& event : date.second) {
    	os << date.first << " " << event << endl;
    }
  }
}

pair<Date, string> Database::Last(Date date) {
  Date last_date;
  if (ordered_storage.find(date) != ordered_storage.end()) {
    last_date = date;
  } else {
    last_date = (*(--ordered_storage.lower_bound(date))).first;
  }
  string last_event = ordered_storage.at(last_date).back();
  
  return make_pair(last_date, last_event);
}

// vector< pair<Date, string> > Database::FindIf(bool (*lambda)(const Date& date, const string& event)) {
//   cout << date;
// }

// void Database::RemoveIf(bool (*lambda)(const Date& date, const string& event)) {

// }
