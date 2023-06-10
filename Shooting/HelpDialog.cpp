#include "HelpDialog.h"
#include <QPainter>
#include <QPainterPath>
#include <QtMath>

HelpDialog::HelpDialog(QWidget *parent) : QDialog(parent) {
    resize(600, 600);  // Set the window size
}

void HelpDialog::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int numberOfRings = 5;
    int ringWidth = width() / (2 * numberOfRings);
    for (int i = 0; i < numberOfRings; ++i) {
        if (i % 2 == 0) {
            painter.setBrush(Qt::red);
        } else {
            painter.setBrush(Qt::white);
        }
        painter.drawEllipse(width() / 2 - ringWidth * (i + 1),
                            height() / 2 - ringWidth * (i + 1),
                            2 * ringWidth * (i + 1),
                            2 * ringWidth * (i + 1));
    }
}
