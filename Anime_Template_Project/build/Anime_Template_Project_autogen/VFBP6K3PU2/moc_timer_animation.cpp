/****************************************************************************
** Meta object code from reading C++ file 'timer_animation.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../utility_class/timer_animation.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timer_animation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN15Timer_animationE_t {};
} // unnamed namespace

template <> constexpr inline auto Timer_animation::qt_create_metaobjectdata<qt_meta_tag_ZN15Timer_animationE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Timer_animation",
        "started",
        "",
        "valueChanged",
        "QVariant",
        "currentValue",
        "incrementChanged",
        "increment",
        "finished",
        "stateChanged",
        "State",
        "newState",
        "start",
        "autoDelete",
        "pause",
        "resume",
        "stop",
        "update",
        "Running",
        "Paused",
        "Stopped",
        "Direction",
        "Forward",
        "Backward"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'started'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'valueChanged'
        QtMocHelpers::SignalData<void(const QVariant &)>(3, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 5 },
        }}),
        // Signal 'incrementChanged'
        QtMocHelpers::SignalData<void(const QVariant &)>(6, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 4, 7 },
        }}),
        // Signal 'finished'
        QtMocHelpers::SignalData<void()>(8, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'stateChanged'
        QtMocHelpers::SignalData<void(State)>(9, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 10, 11 },
        }}),
        // Slot 'start'
        QtMocHelpers::SlotData<void(bool)>(12, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Bool, 13 },
        }}),
        // Slot 'start'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPublic | QMC::MethodCloned, QMetaType::Void),
        // Slot 'pause'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'resume'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'stop'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'update'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
        // enum 'State'
        QtMocHelpers::EnumData<State>(10, 10, QMC::EnumFlags{}).add({
            {   18, State::Running },
            {   19, State::Paused },
            {   20, State::Stopped },
        }),
        // enum 'Direction'
        QtMocHelpers::EnumData<Direction>(21, 21, QMC::EnumFlags{}).add({
            {   22, Direction::Forward },
            {   23, Direction::Backward },
        }),
    };
    return QtMocHelpers::metaObjectData<Timer_animation, qt_meta_tag_ZN15Timer_animationE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Timer_animation::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15Timer_animationE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15Timer_animationE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15Timer_animationE_t>.metaTypes,
    nullptr
} };

void Timer_animation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Timer_animation *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->started(); break;
        case 1: _t->valueChanged((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 2: _t->incrementChanged((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1]))); break;
        case 3: _t->finished(); break;
        case 4: _t->stateChanged((*reinterpret_cast< std::add_pointer_t<State>>(_a[1]))); break;
        case 5: _t->start((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->start(); break;
        case 7: _t->pause(); break;
        case 8: _t->resume(); break;
        case 9: _t->stop(); break;
        case 10: _t->update(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (Timer_animation::*)()>(_a, &Timer_animation::started, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (Timer_animation::*)(const QVariant & )>(_a, &Timer_animation::valueChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (Timer_animation::*)(const QVariant & )>(_a, &Timer_animation::incrementChanged, 2))
            return;
        if (QtMocHelpers::indexOfMethod<void (Timer_animation::*)()>(_a, &Timer_animation::finished, 3))
            return;
        if (QtMocHelpers::indexOfMethod<void (Timer_animation::*)(State )>(_a, &Timer_animation::stateChanged, 4))
            return;
    }
}

const QMetaObject *Timer_animation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Timer_animation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15Timer_animationE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Timer_animation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Timer_animation::started()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Timer_animation::valueChanged(const QVariant & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void Timer_animation::incrementChanged(const QVariant & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1);
}

// SIGNAL 3
void Timer_animation::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Timer_animation::stateChanged(State _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 4, nullptr, _t1);
}
QT_WARNING_POP
