#ifndef NECO_H
#define NECO_H

#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class NecoData;

class Neco
{
    Q_OBJECT
public:
    Neco();
    Neco(const Neco &);
    Neco &operator=(const Neco &);
    ~Neco();

private:
    QSharedDataPointer<NecoData> data;
};

#endif // NECO_H
