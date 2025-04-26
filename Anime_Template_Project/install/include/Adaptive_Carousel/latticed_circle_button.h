#ifndef LATTICED_CIRCLE_BUTTON_H
#define LATTICED_CIRCLE_BUTTON_H

#include <QPushButton>
#include <QPainter>
#include <QGraphicsDropShadowEffect>               
#include <QPropertyAnimation>
#include <QMouseEvent>        

class Latticed_Circle_Button : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(int Tomeido READ Tomeido WRITE setTomeido   FINAL)
    Q_PROPERTY(QColor Current_Color READ Current_Color WRITE setCurrent_Color   FINAL)
public:
    explicit Latticed_Circle_Button(QWidget* parent = nullptr);
    enum AnimationState {
        Execute,  
        Restore   
    };

    QPropertyAnimation *animation1;
    QPropertyAnimation* animation2;

    bool Shikisai_no_joutai = false;

    int Tomeido() const;
    void setTomeido(int newTomeido);

    QColor Current_Color() const;
    void setCurrent_Color(const QColor &newCurrent_Color);

signals:
    void Latticed_Circle_Click_Signal();

    void execute_animation_signal(Latticed_Circle_Button::AnimationState state);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    bool event(QEvent* e);                            

private:
    int m_Tomeido = 0;
    QColor m_Current_Color = QColor(0, 0, 0, 255);
};

#endif // LATTICED_CIRCLE_BUTTON_H
