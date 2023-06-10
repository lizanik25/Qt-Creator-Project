#include "mainwindow.h"
#include "Crime.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

QList<Crime*> loadCrimesFromCSV(const QString &filename) {
    QFile file(filename);
    QList<Crime*> crimes;
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);

        if (!in.atEnd()) {
            in.readLine();
        }

        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(';');
            if (fields.size() == 21) {
                Crime* crime = new Crime(fields[0], fields[1], fields[2], fields[3], fields[4].toInt(), fields[5], fields[6], fields[7], fields[8], fields[9], fields[10], fields[11], fields[12], fields[13], fields[14], fields[15], fields[16], fields[17].toDouble(), fields[18].toDouble(), fields[19], fields[20].toInt());
                crimes.append(crime);
            }
        }
        file.close();
    }
    return crimes;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString str = ":/shooting-1982-2023-semicolon.csv";
    QList<Crime*> list = loadCrimesFromCSV(str);

    MainWindow w(list);
    w.show();
    return a.exec();
}

