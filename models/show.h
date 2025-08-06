#ifndef SHOW_H
#define SHOW_H

#include <QtDebug>
#include <QString>
#include <QObject>
#include <atomic>

class Show : public QObject
{
    Q_OBJECT

public:
    explicit Show(QObject *parent, QString name, long override_id = NULL);
    ~Show();

    long id() const;

    QString name() const;
    void setName(const QString &newName);

private:
    long m_id;
    QString m_name;

signals:
};

#endif // SHOW_H
