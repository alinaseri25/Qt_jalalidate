#include "qdatejalali.h"

QDATEJALALI::QDATEJALALI(QObject *parent) : QObject(parent)
{
    this->setParent(parent);
    shmdate.day = shmdate.month = 0; shmdate.year = 0 - 1300;
    mildate.day = mildate.month = 0;mildate.year = 0 - 2000;
}

bool QDATEJALALI::SetMiladiDate(int _year, int _month, int _day, int _dayOfWeek)
{
    mildate.day = _day;
    mildate.month = _month;
    mildate.year = _year - 2000;
    dayOfWeek = _dayOfWeek;
    miltoshmcv(mildate.year,mildate.month,mildate.day);
    return true;
}

bool QDATEJALALI::SetMiladiDate(QString Date)
{
    QStringList DatePart = Date.split("/");
    if(DatePart.count() == 3)
    {
        mildate.year =  QString(DatePart[0]).toInt() - 2000;
        mildate.month =  QString(DatePart[1]).toInt();
        mildate.day =  QString(DatePart[2]).toInt();
        miltoshmcv(mildate.year,mildate.month,mildate.day);
        return true;
    }
    else
    {
        mildate.day = mildate.month = 0;mildate.year = 0 - 2000;
        miltoshmcv(mildate.year,mildate.month,mildate.day);
        return false;
    }
}

bool QDATEJALALI::SetShamsiDate(int _year, int _month, int _day, int _dayOfWeek)
{
    shmdate.day = _day;
    shmdate.month = _month;
    shmdate.year = _year - 1300;
    dayOfWeek = _dayOfWeek;
    shmtomilcv(shmdate.year,shmdate.month,shmdate.day);
    return true;
}

bool QDATEJALALI::SetShamsiDate(QString Date)
{
    QStringList DatePart = Date.split("/");
    if(DatePart.count() == 3)
    {
        shmdate.year = QString(DatePart[0].toInt() - 1300).toInt();
        shmdate.month = QString(DatePart[1]).toInt();
        shmdate.day = QString(DatePart[2]).toInt();
        shmtomilcv(shmdate.year,shmdate.month,shmdate.day);
        return true;
    }
    else
    {
        shmdate.day = shmdate.month = 0; shmdate.year = 0 - 1300;
        shmtomilcv(shmdate.year,shmdate.month,shmdate.day);
        return false;
    }
}

bool QDATEJALALI::ProcNow()
{
    QDateTime Now = QDateTime::currentDateTime();
    SetMiladiDate(Now.date().year(),Now.date().month(),Now.date().day(),Now.date().dayOfWeek());
    return true;
}

int QDATEJALALI::getdaymi()
{
    return mildate.day;
}

int QDATEJALALI::getmonthmi()
{
    return mildate.month;
}

QString QDATEJALALI::getmonthmistring()
{
    switch (mildate.month) {
    case 1:
        return QString("January");
        break;
    case 2:
        return QString("February");
        break;
    case 3:
        return QString("March");
        break;
    case 4:
        return QString("April");
        break;
    case 5:
        return QString("May");
        break;
    case 6:
        return QString("June");
        break;
    case 7:
        return QString("July");
        break;
    case 8:
        return QString("August");
        break;
    case 9:
        return QString("September");
        break;
    case 10:
        return QString("October");
        break;
    case 11:
        return QString("November");
        break;
    case 12:
        return QString("December");
        break;
    default:
        return QString("Not in month range");
        break;
    }
}

int QDATEJALALI::getyearmi()
{
    return mildate.year + 2000;
}

QString QDATEJALALI::getdayofweekmi()
{
    switch (dayOfWeek) {
    case 0:
        return QString("sunday");
        break;
    case 1:
        return QString("monday");
        break;
    case 2:
        return QString("tuesday");
        break;
    case 3:
        return QString("wednesday");
        break;
    case 4:
        return QString("thursday");
        break;
    case 5:
        return QString("friday");
        break;
    case 6:
        return QString("saturday");
        break;
    default:
        return QString("Error");
        break;
    }
}

int QDATEJALALI::getdaysh()
{
    return shmdate.day;
}

int QDATEJALALI::getmonthsh()
{
    return shmdate.month;
}

QString QDATEJALALI::getmonthshstring()
{
    switch (shmdate.month) {
    case 1:
        return QString("فروردین");
        break;
    case 2:
        return QString("اردیبهشت");
        break;
    case 3:
        return QString("خرداد");
        break;
    case 4:
        return QString("تیر");
        break;
    case 5:
        return QString("مرداد");
        break;
    case 6:
        return QString("شهریور");
        break;
    case 7:
        return QString("مهر");
        break;
    case 8:
        return QString("آبان");
        break;
    case 9:
        return QString("آذر");
        break;
    case 10:
        return QString("دی");
        break;
    case 11:
        return QString("بهمن");
        break;
    case 12:
        return QString("اسفند");
        break;
    default:
        return QString("خارج از بازه ی ماه ها");
        break;
    }
}

int QDATEJALALI::getyearsh()
{
    return shmdate.year + 1300;
}

QString QDATEJALALI::getdayofweeksh()
{
    switch (dayOfWeek) {
    case 0:
        return QString("یکشنبه");
        break;
    case 1:
        return QString("دوشنبه");
        break;
    case 2:
        return QString("سشنبه");
        break;
    case 3:
        return QString("چهارشنبه");
        break;
    case 4:
        return QString("پنجشنبه");
        break;
    case 5:
        return QString("جمعه");
        break;
    case 6:
        return QString("شنبه");
        break;
    default:
        return QString("Error");
        break;
    }
}

/*************************************************************************/
void QDATEJALALI::miltoshmcv(unsigned char ym,unsigned char mm,unsigned char dm)
{
    //ym -= 2000;
    unsigned char k,t1,t2;
    k=ym%4;
    if(k==3)
       k=2;
    k*=2;
    t1=miltable[k][mm-1];
    t2=miltable[k+1][mm-1];
    if(mm<3 || (mm==3 && dm<=miltable[k][mm-1]))
       shmdate.year = ym + 78;
    else
       shmdate.year = ym + 79;


    if(dm<=t1)
    {
       shmdate.day=dm+t2;
       shmdate.month=(mm+8)%12+1;
    }
    else
    {
       shmdate.day=dm-t1;
       shmdate.month=(mm+9)%12+1;
    }
}
/**********************************************************************/
void QDATEJALALI::shmtomilcv(unsigned char ys ,unsigned char ms,unsigned char ds)
{
    //ys -= 1300;
    unsigned char k,t1,t2;
    k = ys%4;
    if( k == 0)
       k = 2;
    else
       k = k + k;
    t1 =shmtable[k - 2][ms-1];
    t2 = shmtable[k-1][ms-1];
    if(ms<10 || (ms==10 && ds <= shmtable[k-2][ms-1]))
       mildate.year = ys - 79;
    else
       mildate.year = ys - 78;

    //mildate.year += 2000;

    if(ds <= t1)
    {
       mildate.day = ds + t2;
       mildate.month = (ms + 1)%12 + 1;
    }
    else
    {
       mildate.day= ds - t1;
       mildate.month= (ms + 2)%12 + 1;
    }
}
