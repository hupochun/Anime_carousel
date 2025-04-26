#ifndef ANIME_HOMEPAGE_H
#define ANIME_HOMEPAGE_H

#include <QWidget>
#include "Carousel_card/carousel_card.h"
#include "Carousel_card/Card_text.h"
#include "Carousel_card/Card_button.h"
#include "button_class/Diffusion_button.h"
#include "button_class/Wave_button.h"
#include "Login_interface/responsive_form.h"
#include "Login_interface/login_form.h"
#include "Login_interface/login_button.h"
#include "Login_interface/scroll_bar.h"
#include "Login_interface/registration_form.h"
#include "dial_class/temperature_dial.h"
#include "dial_class/Knob_page.h"

class Anime_Homepage : public QWidget
{
    Q_OBJECT

public:
    Anime_Homepage(QWidget *parent = nullptr);
    ~Anime_Homepage();
};

#endif // ANIME_HOMEPAGE_H
