#include "Crime.h"

Crime::Crime(const QString& Case, const QString& location_1, const QString& date, const QString& summary, const int fatalities, const QString& injured, const QString total_victims, const QString location_2, const QString age_of_shooter, const QString prior_signs_mental_health_issues, const QString mental_health_details, const QString  weapons_obtained_legally, const QString where_obtained, const QString weapon_type, const QString weapon_details, const QString race, const QString gender, const double latitude, const double longitude, const QString type, const int year):
    Case(Case), location_1(location_1), date(date), summary(summary), fatalities(fatalities), injured(injured), total_victims(total_victims), location_2(location_2), age_of_shooter(age_of_shooter), prior_signs_mental_health_issues(prior_signs_mental_health_issues), mental_health_details(mental_health_details), weapons_obtained_legally(weapons_obtained_legally), where_obtained(where_obtained), weapon_type(weapon_type), weapon_details(weapon_details), race(race), gender(gender), latitude(latitude), longitude(longitude), type(type), year(year){
}

Crime::~Crime(){}

QString Crime::getCase() const {
    return Case;
}

QString Crime::getSummary() const {
    return summary;
}

QString Crime::getState() const {
    return location_1;
}

int Crime::getKilled() const {
    return fatalities;
}
