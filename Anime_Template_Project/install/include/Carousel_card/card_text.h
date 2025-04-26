#ifndef CARD_TEXT_H
#define CARD_TEXT_H

#include <QWidget>
#include <QPainter>
#include <QTextDocument>
#include <QPropertyAnimation>
#include <QMouseEvent>

class Card_text : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int shrink_width READ shrink_width WRITE setShrink_width FINAL)
    Q_PROPERTY(int enlarge_width READ enlarge_width WRITE setEnlarge_width FINAL)
    Q_PROPERTY(int font_size READ font_size WRITE setFont_size FINAL)
    Q_PROPERTY(int font_size2 READ font_size2 WRITE setFont_size2 FINAL)
    Q_PROPERTY(int top_margin READ top_margin WRITE setTop_margin FINAL)

public:
    explicit Card_text(QString text, QString text1, QWidget *parent = nullptr);
    QString text_main;
    QString text_sub;
    void start_animation(int animation_duration);
    void reset_animation(int animation_duration);
    int shrink_width() const;
    void setShrink_width(int newShrink_width);
    int enlarge_width() const;
    void setEnlarge_width(int newEnlarge_width);
    int font_size() const;
    void setFont_size(int newFont_size);
    int font_size2() const;
    void setFont_size2(int newFont_size2);
    int top_margin() const;
    void setTop_margin(int newTop_margin);

protected:
    void paintEvent(QPaintEvent *event);

private:
    int m_shrink_width = 200;
    int m_enlarge_width = 0;
    int m_font_size = 15;
    int m_font_size2 = 1;
    int m_top_margin = 210;
};

#endif // CARD_TEXT_H
