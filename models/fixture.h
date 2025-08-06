#ifndef FIXTURE_H
#define FIXTURE_H

#include <QString>
#include <QObject>

class Fixture : public QObject
{
    Q_OBJECT

public:
    Fixture(int universe, int channel, QString name);

    int id() const;

    QString name() const;
    void setName(const QString &newName);

    int universe() const;
    void setUniverse(int newUniverse);

    int channel() const;
    void setChannel(int newChannel);


private:
    int m_id;
    QString m_name;
    int m_universe;
    int m_channel;

};

#endif // FIXTURE_H
