#ifndef TEMPERATURE_DIAL_H
#define TEMPERATURE_DIAL_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QPainterPath>
#include <QGraphicsDropShadowEffect>
#include "../utility_class/timer_animation.h"

class Temperature_dial : public QWidget {
    Q_OBJECT
    Q_PROPERTY(int shadow_scale READ shadow_scale WRITE setShadow_scale NOTIFY shadow_scaleChanged FINAL)

public:
    explicit Temperature_dial(QWidget *parent = nullptr);
    
    enum AnimationState {
        Execute,
        Restore
    };

    void startAnimation();
    void draw_text();
    void draw_text_template(const QString& text, float fontScale, QPointF positionRatio, const int& alignment);
    void draw_circle();
    void draw_empty_circle();
    void draw_full_circle();
    void draw_crosshair();
    void draw_circular_gradient_shadow();
    QColor interpolateColor(const QColor& start, const QColor& end, double t);
    QColor getColorForAngle(int angle);
    void set_size(QRect size);

public:
    double getAngleInDegrees() const;
    int shadow_scale() const;
    void setShadow_scale(int newShadow_scale);

private slots:

signals:
    void shadow_scaleChanged();
    void execute_animation_signal(Temperature_dial::AnimationState state);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void resizeEvent(QResizeEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    bool event(QEvent* e);

private:
    QPointF center;
    QPointF circleCenter;
    double radius;
    double m_previousAngle = M_PI_2;
    bool isDragging = false;
    Timer_animation * timer_animation;
    bool is_animation_running = true;
    double angle;
    QString integerPart;
    QString decimalPart;
    QRectF window_width;
    QGraphicsDropShadowEffect* shadow;
    int m_shadow_scale;
    int zoom_rate = 40;
    int fontSize;
};

#endif // TEMPERATURE_DIAL_H

