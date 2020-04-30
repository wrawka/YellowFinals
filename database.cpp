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

void Database::Last() {

}

vector< pair<Date, string> > Database::FindIf(bool (*lambda)(const Date& date, const string& event)) {
  cout << date;
}

// void Database::RemoveIf(bool (*lambda)(const Date& date, const string& event)) {

// }
