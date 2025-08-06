#ifndef SHOW_H
#define SHOW_H

#include <QObject>

class show : public QObject
{
    Q_OBJECT
public:
    explicit show(QObject *parent = nullptr);

signals:
};

#endif // SHOW_H
