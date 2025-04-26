#ifndef TIMER_ANIMATION_H
#define TIMER_ANIMATION_H

#include <QObject>
#include <QTimer>
#include <QVariant>
#include <QMetaProperty>
#include <QDateTime>
#include <QColor>
#include <QPoint>
#include <QRect>

class Timer_animation : public QObject
{
    Q_OBJECT
public:
    enum State {
        Running,
        Paused,
        Stopped
    };
    Q_ENUM(State)

    enum Direction {
        Forward,
        Backward
    };
    Q_ENUM(Direction)

    explicit Timer_animation(QObject *target = nullptr,
                             const QByteArray &propertyName = QByteArray(),
                             QObject *parent = nullptr);

    void setStartValue(const QVariant &value);
    void setEndValue(const QVariant &value);
    void setDuration(int msecs);
    void setDirection(Direction dir);

    QObject* targetObject() const { return m_target; }
    QByteArray propertyName() const { return m_propertyName; }
    QVariant startValue() const { return m_startValue; }
    QVariant endValue() const { return m_endValue; }
    int duration() const { return m_duration; }
    State state() const { return m_state; }
    Direction direction() const { return m_direction; }

    void setState(State newState);

public slots:
    void start(bool autoDelete = false);
    void pause();
    void resume();
    void stop();

signals:
    void started();
    void valueChanged(const QVariant &currentValue);
    void incrementChanged(const QVariant &increment);
    void finished();
    void stateChanged(State newState);

private slots:
    void update();

private:
    QVariant m_previousValue;
    QVariant calculateIncrement(const QVariant &prev, const QVariant &curr) const;
    QVariant interpolate(qreal progress) const;
    void calculateInterval();

    QObject *m_target = nullptr;
    QByteArray m_propertyName;
    QVariant m_startValue;
    QVariant m_endValue;
    int m_duration = 1000;
    QTimer m_timer;
    qint64 m_startTime = 0;
    qint64 m_pausedTime = 0;
    State m_state = Stopped;
    Direction m_direction = Forward;
    bool m_autoDelete = false;
    qreal progress;
};

#endif // TIMER_ANIMATION_H
