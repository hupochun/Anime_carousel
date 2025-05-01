#include "depressed_button.h"

Depressed_Button::Depressed_Button(QString m_Function_Button_pixmap, QWidget* parent)
    : QPushButton{ parent }
{
    this->setCursor(Qt::PointingHandCursor);
    this->resize(150, 150);
    this->m_Function_Button_pixmap = QPixmap(m_Function_Button_pixmap);
    
    animation = new QPropertyAnimation(this, "clor");
    animation->setDuration(200);
    animation->setStartValue(m_clor);
    animation->setEndValue(QColor(135, 135, 135, 115));

    animation1 = new QPropertyAnimation(this, "SF");
    animation1->setDuration(200);
    animation1->setStartValue(m_SF);
    animation1->setEndValue(0.55);
}

void Depressed_Button::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    QPainterPath path;
    path.addRoundedRect(this->rect(), 35, 35);
    painter.setClipPath(path);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QColor(255, 255, 255, 255));
    painter.drawRect(this->rect());

    QLinearGradient gradient(QPointF(-width() * 0.1, -height() * 0.1), QPointF(width() * 1.0, height() * 1.0));
    gradient.setColorAt(0, m_clor);
    gradient.setColorAt(0.86, QColor(255, 255, 255, 255));
    gradient.setColorAt(1.0, QColor(255, 255, 255, 255));

    QPen pen;
    pen.setWidth(74);
    pen.setBrush(gradient);

    QImage blur_image(this->size(), QImage::Format_ARGB32);
    blur_image.fill(QColor(0, 0, 0, 0));
    QPainter image_painter(&blur_image);
    image_painter.setRenderHint(QPainter::Antialiasing);
    image_painter.setBrush(gradient);
    image_painter.setPen(Qt::NoPen);
    image_painter.drawRoundedRect(this->rect(), 10, 10);
    image_painter.end();
    painter.drawImage(this->rect(), blur_image);

    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::NoBrush);
    QRect rect;
    rect.setHeight(this->height() * m_SF);
    rect.setWidth(this->height() * m_SF);
    rect.moveCenter(QPoint(this->rect().center().x(), this->rect().center().y()));
    painter.drawPixmap(rect, m_Function_Button_pixmap);
}

bool Depressed_Button::event(QEvent *event)
{
    if (event->type() == QEvent::Enter)
    {
        emit Animation_Trigger_State(true);
        animation->setDirection(QAbstractAnimation::Forward);
        animation->start();
        animation1->setDirection(QAbstractAnimation::Forward);
        animation1->start();
    }
    else if (event->type() == QEvent::Leave)
    {
        emit Animation_Trigger_State(false);
        animation->setDirection(QAbstractAnimation::Backward);
        animation->start();
        animation1->setDirection(QAbstractAnimation::Backward);
        animation1->start();
    }

    return QPushButton::event(event);
}

qreal Depressed_Button::JB() const
{
    return m_JB;
}

void Depressed_Button::setJB(qreal newJB)
{
    if (qFuzzyCompare(m_JB, newJB))
        return;
    m_JB = newJB;
    emit JBChanged();
    update();
}

QColor Depressed_Button::clor() const
{
    return m_clor;
}

void Depressed_Button::setClor(const QColor &newClor)
{
    if (m_clor == newClor)
        return;
    m_clor = newClor;
    emit clorChanged();
    update();
}

qreal Depressed_Button::SF() const
{
    return m_SF;
}

void Depressed_Button::setSF(qreal newSF)
{
    if (qFuzzyCompare(m_SF, newSF))
        return;
    m_SF = newSF;
    emit SFChanged();
    update();
}
