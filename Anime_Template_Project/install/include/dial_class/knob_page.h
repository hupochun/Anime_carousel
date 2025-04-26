#ifndef KNOB_PAGE_H
#define KNOB_PAGE_H

#include <QWidget>
#include "temperature_dial.h"
#include "../utility_class/timer_animation.h"

class Knob_page : public QWidget
{
    Q_OBJECT
public:
    explicit Knob_page(QWidget *parent = nullptr);
    Temperature_dial *temp_dial;
    void animations(); 
    int zoom_rate = 40;
    Timer_animation *animation;

public slots:
    void execute_animation(Temperature_dial::AnimationState State);

signals:
};

#endif // KNOB_PAGE_H
