#ifndef QDATEJALALI_H
#define QDATEJALALI_H

#include <QObject>
#include <QDate>
#include <QStringList>

class QDATEJALALI : public QObject
{
    Q_OBJECT
public:
    explicit QDATEJALALI(QObject *parent = 0);
    bool SetMiladiDate(int _year, int _month, int _day, int _dayOfWeek = 0);
    bool SetMiladiDate(QString Date = "0000/00/00");// QString Date = "YYYY/MM/DD"
    bool SetShamsiDate(int _year,int _month,int _day, int _dayOfWeek = 0);
    bool SetShamsiDate(QString Date = "0000/00/00");// QString Date = "YYYY/MM/DD"
    bool ProcNow();
    int getdaysh(void);
    int getmonthsh(void);
    QString getmonthshstring(void);
    int getyearsh(void);
    QString getdayofweeksh(void);

    int getdaymi(void);
    int getmonthmi(void);
    QString getmonthmistring(void);
    int getyearmi(void);
    QString getdayofweekmi(void);

private:
    unsigned char shmtable[6][12]={
        {11,10,10,9,9,9,8,9,9,10,11,9},
        {20,20,21,21,22,22,22,22,21,21,20,19},
        {11,10,10,9,9,9,8,9,9,10,11,10},
        {20,20,21,21,22,22,22,22,21,21,20,19},
        {12,11,11,10,10,10,9,10,10,11,12,10},
        {19,19,20,20,21,21,21,21,20,20,19,18}};

    unsigned char miltable[6][12]={
        {20,19,19,19,20,20,21,21,21,21,20,20},
        {10,11,10,12,11,11,10,10,10,9,10,10},
        {19,18,20,20,21,21,22,22,22,22,21,21},
        {11,12,10,11,10,10,9,9,9,8,9,9},
        {20,19,20,20,21,21,22,22,22,22,21,21},
        {10,11,9,11,10,10,9,9,9,8,9,9}};

     struct date{
     unsigned int day;
     unsigned int month;
     unsigned int year;
    };
     struct date shmdate,mildate ;
     unsigned int dayOfWeek;

     void miltoshmcv(unsigned char ym, unsigned char mm, unsigned char dm);
     void shmtomilcv(unsigned char ys, unsigned char ms, unsigned char ds);
signals:

public slots:
};

#endif // QDATEJALALI_H
