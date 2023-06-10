#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include <QDialog>
#include <QPainter>

class HelpDialog : public QDialog {
    Q_OBJECT

public:
    explicit HelpDialog(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // HELPDIALOG_H
