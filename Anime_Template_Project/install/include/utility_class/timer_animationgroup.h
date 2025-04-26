#ifndef ANIMATION_GROUP_H
#define ANIMATION_GROUP_H

#include <QObject>
#include <QMap>
#include <QList>
#include "timer_animation.h"

class Timer_AnimationGroup : public QObject
{
    Q_OBJECT
public:
    explicit Timer_AnimationGroup(QObject *parent = nullptr);
    void addAnimation(int x, Timer_animation* animation);
    void clearAnimations();
    void start();
    void pause();
    void resume();
    void stop();
    void setGroupDirection(Timer_animation::Direction dir);
    Timer_animation::Direction groupDirection() const { return m_currentDirection; }

signals:
    void started();
    void groupStarted(int x);
    void groupFinished(int x);
    void finished();

private slots:
    void handleAnimationFinished();

private:
    void processNextGroup();
    void rebuildExecutionQueue();
    void restartFromCurrent();

    QMap<int, QList<Timer_animation*>> m_animationGroups;
    QList<int> m_executionQueue;
    Timer_animation::Direction m_currentDirection = Timer_animation::Forward;
    int m_currentIndex = -1;
    int m_activeCount = 0;
    bool m_isRunning = false;
    int m_lastProcessedX = -1;
};

#endif // ANIMATION_GROUP_H
