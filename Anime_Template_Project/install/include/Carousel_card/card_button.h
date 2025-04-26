#ifndef CARD_BUTTON_H
#define CARD_BUTTON_H

#include <QPushButton>
#include <QPainter>
#include <QPainterPath>
#include <QMouseEvent>
#include <QPropertyAnimation>
#include <QDesktopServices>
#include <QUrl>

class Card_button : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(QColor button_color READ getbutton_color WRITE setButton_color FINAL)
    Q_PROPERTY(int color_opacity READ color_opacity WRITE setcolor_opacity FINAL)

public:
    explicit Card_button(QString text, QColor button_color, QWidget* parent = nullptr);
    QColor getbutton_color() const;
    void setButton_color(const QColor &newButton_color);

public:
    QString btntext;
    void color_control();
    QColor color1;
    QColor color2;
    int color_opacity() const;
    void setcolor_opacity(int newColor_opacity);
    void openWebsite();
    void setWebsite_url(QString url);

protected:
    void paintEvent(QPaintEvent* event);
    bool event(QEvent* e);

private:
    QPropertyAnimation* animation;
    QString website_url;
    QColor m_button_color;
    int m_color_opacity = 255;
};

#endif // CARD_BUTTON_H
