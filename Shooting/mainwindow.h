#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QStringListModel>
#include <QMainWindow>
#include <QListView>
#include "Crime.h"
#include "crimeModel.h"
#include <QLabel>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QList<Crime*> crimes, QWidget *parent = nullptr);
    ~MainWindow();

    void saveas();
    void updateDetails(const QModelIndex &index);
    void showHelpDialog();
    void findWorstCase();

private:
    Ui::MainWindow *ui;
    QList<Crime*> crimes;
    QListView* listview;
    QStringListModel* model;
    CrimeModel *crimemodel;
    QLabel *detailLabel;
    QPushButton *caseButton;
    QPushButton *helpButton;

};
#endif // MAINWINDOW_H
