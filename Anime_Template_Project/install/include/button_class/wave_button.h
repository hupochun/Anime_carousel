#ifndef WAVE_BUTTON_H
#define WAVE_BUTTON_H

#include <QPushButton>
#include <QPainter>
#include <QMouseEvent>
#include <QPainterPath>
#include <QGraphicsDropShadowEffect>
#include <QPropertyAnimation>

class Wave_button : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(int angle READ angle WRITE setAngle NOTIFY angleChanged FINAL)
    Q_PROPERTY(int wave_position READ wave_position WRITE setWave_position NOTIFY wave_positionChanged FINAL)
    Q_PROPERTY(int wave_transparency READ wave_transparency WRITE setWave_transparency NOTIFY wave_transparencyChanged FINAL)
    Q_PROPERTY(int right_angle READ right_angle WRITE setRight_angle NOTIFY right_angleChanged FINAL)

public:
    explicit Wave_button(QWidget* parent = nullptr);
    void rotating_rounded_rectangle();
    void rotating_rounded_rectangle1();
    QColor color;
    void draw_border();
    void execute_animation();
    void restore_animation();
    double triangle_position();
    bool click_status = true;
    int execution_time = 4000;
    void draw_text();

public:
    int angle() const;
    void setAngle(int newAngle);
    int wave_position() const;
    void setWave_position(int newWave_position);
    int wave_transparency() const;
    void setWave_transparency(int newWave_transparency);
    int right_angle() const;
    void setRight_angle(int newRight_angle);

signals:
    void angleChanged();
    void wave_positionChanged();
    void wave_transparencyChanged();
    void right_angleChanged();

protected:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* event);

private:
    int m_angle = 25;
    int m_right_angle = 1080;
    int m_wave_position = 0;
    int m_wave_transparency = 100;
};

#endif // WAVE_BUTTON_H
