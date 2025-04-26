cmake_minimum_required(VERSION 3.16)

project(Anime_Template_Project VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets OpenGLWidgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets OpenGLWidgets)

# 定义组件库源文件（不含 main.cpp）
set(LIB_SOURCES
    anime_homepage.cpp anime_homepage.h
    Carousel_card/carousel_card.cpp Carousel_card/carousel_card.h
    Carousel_card/carrier_card.cpp Carousel_card/carrier_card.h
    Carousel_card/card_text.cpp Carousel_card/card_text.h
    Carousel_card/card_button.cpp Carousel_card/card_button.h
    button_class/diffusion_button.cpp button_class/diffusion_button.h
    button_class/wave_button.cpp button_class/wave_button.h
    Login_interface/responsive_form.cpp Login_interface/responsive_form.h
    Login_interface/scroll_bar.cpp Login_interface/scroll_bar.h
    Login_interface/login_form.cpp Login_interface/login_form.h
    Login_interface/registration_form.cpp Login_interface/registration_form.h
    Login_interface/input_box.cpp Login_interface/input_box.h
    Login_interface/login_button.cpp Login_interface/login_button.h
    Login_interface/other_login_buttons.cpp Login_interface/other_login_buttons.h
    Login_interface/transparent_transition_interface.cpp Login_interface/transparent_transition_interface.h
    Login_interface/hollow_button.cpp Login_interface/hollow_button.h
    utility_class/timer_animation.cpp utility_class/timer_animation.h
    utility_class/timer_animationgroup.cpp utility_class/timer_animationgroup.h
    dial_class/temperature_dial.cpp dial_class/temperature_dial.h
    dial_class/knob_page.cpp dial_class/knob_page.h
    Adaptive_Carousel/daen_no_kado.cpp Adaptive_Carousel/daen_no_kado.h
    Adaptive_Carousel/latticed_circle_button.cpp Adaptive_Carousel/latticed_circle_button.h
    Zipper_Slider/pathwidget.cpp Zipper_Slider/pathwidget.h
    src.qrc
)

# 构建共享库组件
add_library(AnimeComponents SHARED ${LIB_SOURCES})

# 暴露头文件路径并链接 Qt 库
target_include_directories(AnimeComponents PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)
target_link_libraries(AnimeComponents PUBLIC
    Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::OpenGLWidgets
)

include(GNUInstallDirs)
# 安装库和头文件
install(TARGETS AnimeComponents
    EXPORT AnimeComponentsTargets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# 删除旧的递归安装头文件指令
# install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
#    FILES_MATCHING PATTERN "*.h"
# )
# 按目录安装头文件
install(FILES anime_homepage.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(DIRECTORY Carousel_card/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/Carousel_card FILES_MATCHING PATTERN "*.h")
install(DIRECTORY button_class/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/button_class FILES_MATCHING PATTERN "*.h")
install(DIRECTORY Login_interface/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/Login_interface FILES_MATCHING PATTERN "*.h")
install(DIRECTORY utility_class/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/utility_class FILES_MATCHING PATTERN "*.h")
install(DIRECTORY dial_class/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/dial_class FILES_MATCHING PATTERN "*.h")
install(DIRECTORY Adaptive_Carousel/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/Adaptive_Carousel FILES_MATCHING PATTERN "*.h")
install(DIRECTORY Zipper_Slider/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/Zipper_Slider FILES_MATCHING PATTERN "*.h")

# 导出组件库的 CMake 配置
install(EXPORT AnimeComponentsTargets
    FILE AnimeComponentsConfig.cmake
    FILE AnimeComponentsTargets.cmake
     NAMESPACE AnimeComponents::
     DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/AnimeComponents
)

# 生成并安装对应的 Config.cmake 与版本文件
include(CMakePackageConfigHelpers)
set(CONFIG_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/AnimeComponents")

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/AnimeComponentsConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/AnimeComponentsConfig.cmake"
    INSTALL_DESTINATION "${CONFIG_INSTALL_DIR}"
)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/AnimeComponentsConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

install(
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/AnimeComponentsConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/AnimeComponentsConfigVersion.cmake"
    DESTINATION "${CONFIG_INSTALL_DIR}"
)
