#ifndef SHOW_H
#define SHOW_H

#include <QString>
#include <QObject>

class Show : public QObject
{
    Q_OBJECT

public:
    explicit Show(QObject *parent, QString name);

    int id() const;

    QString name() const;
    void setName(const QString &newName);

private:
    int m_id;
    QString m_name;

signals:
};

#endif // SHOW_H
