#ifndef DEPRESSED_BUTTON_H
#define DEPRESSED_BUTTON_H

#include <QPushButton>
#include <QPropertyAnimation>
#include <QEvent>
#include <QPainter>
#include <QMouseEvent>
#include <QPainterPath>

class Depressed_Button : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(qreal JB READ JB WRITE setJB NOTIFY JBChanged FINAL)
    Q_PROPERTY(QColor clor READ clor WRITE setClor NOTIFY clorChanged FINAL)
    Q_PROPERTY(qreal SF READ SF WRITE setSF NOTIFY SFChanged FINAL)

public:
    explicit Depressed_Button(QString m_Function_Button_pixmap, QWidget* parent = nullptr);
    QPropertyAnimation* animation;
    QPropertyAnimation* animation1;

    qreal JB() const;
    void setJB(qreal newJB);

    QColor clor() const;
    void setClor(const QColor &newClor);

    qreal SF() const;
    void setSF(qreal newSF);

signals:
    void JBChanged();
    void clorChanged();
    void Animation_Trigger_State(bool x);
    void SFChanged();

protected:
    void paintEvent(QPaintEvent* event);
    bool event(QEvent* event);

private:
    QPixmap m_Function_Button_pixmap;
    QColor m_Bottom_Edge_Color = QColor(241, 245, 249, 255);
    qreal m_JB = 0.0;
    QColor m_clor = QColor(235, 235, 235, 235);
    qreal m_SF = 0.60;
};

#endif // DEPRESSED_BUTTON_H
