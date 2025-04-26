#ifndef DIFFUSION_BUTTON_H
#define DIFFUSION_BUTTON_H

#include <QPushButton>
#include <QPainter>
#include <QMouseEvent>
#include <QPainterPath>
#include <QGraphicsDropShadowEffect>
#include <QPropertyAnimation>

class Diffusion_button : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(int radius READ radius WRITE setRadius NOTIFY radiusChanged FINAL)
    Q_PROPERTY(int opacity READ opacity WRITE setOpacity NOTIFY opacityChanged FINAL)

public:
    explicit Diffusion_button(QWidget* parent = nullptr);
    void draw_disappearing_circle();
    void execute_animation();
    QPoint mouse_coordinates;
    QPropertyAnimation* animation1;
    QPropertyAnimation* animation3;
    void reset_animation();

public:
    int radius() const;
    void setRadius(int newRadius);
    int opacity() const;
    void setOpacity(int newOpacity);

signals:
    void radiusChanged();
    void opacityChanged();

protected:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* event);

private:
    int m_radius = 0;
    int m_opacity = 255;
};

#endif // DIFFUSION_BUTTON_H
