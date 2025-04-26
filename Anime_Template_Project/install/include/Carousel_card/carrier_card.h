#ifndef CARRIER_CARD_H
#define CARRIER_CARD_H

#include <QWidget>
#include <QPainter>
#include <QPropertyAnimation>
#include <QMouseEvent>
#include <QPainterPath>
#include <QTimer>
#include <QFile>
#include <QGraphicsDropShadowEffect>
#include <QLabel>
#include "card_text.h"
#include "Card_button.h"

class Carrier_card : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int carrier_card_id READ carrier_card_id WRITE setcarrier_card_id NOTIFY carrier_card_idChanged FINAL)
    Q_PROPERTY(int opacity READ opacity WRITE setOpacity FINAL)
    Q_PROPERTY(int circle_degrees READ circle_degrees WRITE setCircle_degrees FINAL)

public:
    explicit Carrier_card(QPixmap m_carrier_card, QString main_title, QString sub_title, QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    bool event(QEvent* e);

public:
    QTimer m_clickTimer;
    QTimer timer4s;
    int TimerTimeout = 0;
    bool display_circle = false;
    void restore_disc();
    void onClickTimerTimeout();
    void circle_reset();
    QPoint mousePos;
    bool isClicked = false;
    void draw_radial_gradient_circle();

public:
    Card_text* Anime_small_text;
    int position_small_after_enlargement = 267;
    int basic_small_position = 245;
    void font_related_construction(QString main_title, QString sub_title);
    Card_button* Anime_button;

public:
    int carrier_card_id() const;
    QColor m_color1;
    QColor m_color2;
    QColor m_color3;
    int opacity() const;
    void setOpacity(int newOpacity);
    int circle_degrees() const;
    void setCircle_degrees(int newCircle_degrees);
    void Anime_card_1();
    void setcarrier_card_id(int newCarrier_card_id);
    QColor getMostFrequentColor(const QPixmap& pixmap);
    void set_gradient_color();
    void draw_sector_circle();

public slots:
    void Anime_card_transformation(int animation_duration);

signals:
    void carrier_card_idChanged(int m_carrier_card_id);

private:
    QGraphicsDropShadowEffect* shadow;
    QPixmap m_carrier_card;
    int m_carrier_card_id = 0;
    int m_opacity = 90;
    int m_circle_degrees = 360;
};

#endif // CARRIER_CARD_H
