#include "mainwindow.h"
#include <QWidget>
#include <QApplication>
#include <QWebEngineView>
#include <QUrl>
#include <QGridLayout>
#include "Crime.h"
#include <QFileDialog>
#include <QMessageBox>
#include "crimeModel.h"
#include "HelpDialog.h"

MainWindow::MainWindow(QList<Crime*> crimes, QWidget *parent)
    : QMainWindow(parent), crimes(crimes)
{
    QWidget* widget = new QWidget(this);
    QGridLayout* layout = new QGridLayout(widget);

    crimemodel = new CrimeModel(crimes, this);
    listview = new QListView(widget);
    listview->setModel(crimemodel);

    connect(listview->selectionModel(), &QItemSelectionModel::selectionChanged,
            [this](const QItemSelection &selected, const QItemSelection &deselected){
                if (!selected.indexes().isEmpty())
                    updateDetails(selected.indexes().first());
            });

    detailLabel = new QLabel(widget);
    QWebEngineView *view = new QWebEngineView();
    view->load(QUrl("https://www.google.com/maps/@37.0902,-95.7129,4z?entry=ttu"));

    layout->addWidget(view,0,0,1,2);
    layout->addWidget(listview,1,0);
    layout->addWidget(detailLabel,1,1);

    caseButton = new QPushButton(tr("worst Case in this State"), this);
    layout->addWidget(caseButton, 2, 0);
    connect(caseButton, &QPushButton::clicked, this, &MainWindow::findWorstCase);

    helpButton = new QPushButton(tr("Help"), this);
    layout->addWidget(helpButton, 2, 1);
    connect(helpButton, &QPushButton::clicked, this, &MainWindow::showHelpDialog);

    widget->setLayout(layout);

    setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::updateDetails(const QModelIndex &index) {
    Crime *crime = crimemodel->getCrime(index);
    QString txt;
    int count=0;
    if (crime != nullptr) {

        detailLabel->setText(crime->getSummary());
        detailLabel->setWordWrap(true);
    }
}

void MainWindow::showHelpDialog() {
    HelpDialog dialog(this);
    dialog.exec();
}

void MainWindow::findWorstCase() {
    QModelIndex currentIdx = listview->currentIndex();
    Crime *crime = crimemodel->getCrime(currentIdx);
    QMessageBox msgBox;
    msgBox.setText("The worst crime in "+crime->getState()+" is\n" + crimemodel->getWorstCrime(crime->getState()));
    msgBox.exec();
}
//void saveas(){
//    QString s = QFileDialog::getSaveFileName(this, "Save data", ".", "CSV Files (*.csv)");
//    if (file.open(QIODevice::WriteOnly)) {
//        QTextStream out(&file);
//        out << "case,location,date,summary,fatalities,injured,total_victims,location,age_of_shooter,prior_signs_mental_health_issues,mental_health_details,weapons_obtained_legally,where_obtained,weapon_type,weapon_details,race,gender,latitude,longitude,type,year\n";

//        for(Crime* crime: crimes)
//        {
//            //here we need to add all getter's of our fields with commas in between
//        }

//        file.close();
//    }
//}



