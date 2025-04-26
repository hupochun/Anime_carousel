#ifndef CAROUSEL_CARD_H
#define CAROUSEL_CARD_H

#include <QWidget>
#include "carrier_card.h"
#include <QList>
#include <QPropertyAnimation>
#include <QTimer>
#include <QGraphicsDropShadowEffect>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class Carousel_card : public QWidget
{
    Q_OBJECT
public:
    explicit Carousel_card(QWidget *parent = nullptr);

public:
    QList<Carrier_card*> Anime_seven_cards_list;
    QList<QPoint> Anime_seven_cards_zasyo_list;

    void Anime_basic_information();
    void Anime_cards_sorting(QList<Carrier_card*>& Anime_seven_cards_list,
                             int Anime_cards_startX,
                             int Anime_cards_cardWidth,
                             int Anime_cards_spacing);
    void Anime_Anima_set(Carrier_card* Anime_cards, QPoint Anime_zasyo, int Anime_time);

public slots:
    void Anime_card_position_update(int m_carrier_card_id);
    void onwheel_TimerTimeout();

signals:
    void wheel_signalChanged(int wheel_signal);

protected:
    void mousePressEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

private:
    QTimer clickTimer;
    int Yizi = 1;
    int San = 3;
    int Anime_cards_startX = -628;
    int Anime_cards_cardWidth = 320;
    int Anime_cards_spacing = 13;
    int animation_duration = 410;
};

#endif // CAROUSEL_CARD_H
