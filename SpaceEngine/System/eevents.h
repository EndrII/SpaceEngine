#ifndef EEVENTS_H
#define EEVENTS_H

#include <QWidget>
#include "EDefkey.h"
#include "EConfig.h"
#include <thread>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QTimer>
#include <QStyle>
class EEvents : public QWidget //dannii klass yavlayetsy interpritatoroom sobitii Qt
{
    Q_OBJECT
private:
    EConfig *setings;//nastoiki dvigka
    QTimer *timer,timer2;//taimer sinhroniizazii nastroek
    short convert(const int&);//konvertiruet signal qt v signal E
private slots:
    void _update();
    void _release();
protected:
    void mousePressEvent(QMouseEvent*);//nagatie mouse
    void mouseReleaseEvent(QMouseEvent*);//otgatie mishi
    void mouseMoveEvent(QMouseEvent*);// klavishi
    void mouseDoubleClickEvent(QMouseEvent*);// sobitie double clika
    void keyPressEvent(QKeyEvent*);//nagati
    void keyReleaseEvent(QKeyEvent *);//otgatie klavish
    void wheelEvent(QWheelEvent * event);
    void resizeEvent(QResizeEvent *event);
public:
    explicit EEvents(EConfig*,QWidget *parent = 0);
    void setSetings(EConfig* c);
    EConfig* Config();
    ~EEvents();
public slots:
    void focus();
signals:
    void EmousePressEvent(QMouseEvent*);//nagatie mouse
    void EmouseReleaseEvent(QMouseEvent*);//otgatie mishi
    void EmouseMoveEvent(QMouseEvent*);// klavishi
    void EmouseDoubleClickEvent(QMouseEvent*);// sobitie double clika
    void EkeyPressEvent(QKeyEvent*);//nagati
    void EkeyReleaseEvent(QKeyEvent *);//otgatie klavish
    void Press(short);//signal o nagatie klavishi
    void Release(short);//signal o nagatie klavishi
    void Mousemov(EKord); //signal o dvigenii mishi
    void Resize(QResizeEvent*);// signalit esli razmer izmenyon
};

#endif // EEVENTS_H
