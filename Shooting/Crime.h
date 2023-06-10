#ifndef CRIME_H
#define CRIME_H
#include <QString>

class Crime{
private:
    QString Case;
    QString location_1;
    QString date;
    QString summary;
    int fatalities;
    QString injured;
    QString total_victims;
    QString location_2;
    QString age_of_shooter;
    QString prior_signs_mental_health_issues;
    QString mental_health_details;
    QString  weapons_obtained_legally;
    QString where_obtained;
    QString weapon_type;
    QString weapon_details;
    QString race;
    QString gender;
    double latitude;
    double longitude;
    QString type;
    int year;



public:
    Crime(const QString& Case, const QString& location_1, const QString& date, const QString& summary, const int fatalities, const QString& injured, const QString total_victims, const QString location_2, const QString age_of_shooter, const QString prior_signs_mental_health_issues, const QString mental_health_details, const QString  weapons_obtained_legally, const QString where_obtained, const QString weapon_type, const QString weapon_details, const QString race, const QString gender, const double latitude, const double longitude, const QString type, const int year);
    ~Crime();

    QString getCase() const;
    QString getSummary() const;
    QString getState() const;
    int getKilled() const;

};

#endif // CRIME_H
