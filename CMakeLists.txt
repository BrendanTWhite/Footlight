# from https://github.com/AndreiCherniaev/CMake_variable_to_code/tree/main
add_compile_definitions(HF_ORG_NAME=${HF_ORG_NAME})
add_compile_definitions(HF_ORG_DOMAIN=${HF_ORG_DOMAIN})

add_compile_definitions(HF_APP_NAME=${HF_APP_NAME})
add_compile_definitions(HF_APP_DISPLAY_NAME=${HF_APP_DISPLAY_NAME})
add_compile_definitions(HF_APP_DESCRIPTION=${HF_APP_DESCRIPTION})
add_compile_definitions(HF_APP_VERSION=${HF_APP_VERSION})

add_compile_definitions(CMAKE_PROJECT_NAME=${CMAKE_PROJECT_NAME})
add_compile_definitions(CMAKE_PROJECT_DESCRIPTION=${CMAKE_PROJECT_DESCRIPTION})
add_compile_definitions(CMAKE_PROJECT_VERSION=${CMAKE_PROJECT_VERSION})

cmake_minimum_required(VERSION 3.19)
project(${HF_APP_NAME} LANGUAGES CXX DESCRIPTION "${HF_APP_DESCRIPTION}" VERSION ${HF_APP_VERSION})

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools)
find_package(Qt6 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(Footlight
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    models/fixture.h
    models/fixture.cpp
    models/fixturegroup.h models/fixturegroup.cpp
)

qt_add_translations(
    TARGETS Footlight
    TS_FILES Footlight_en_AU.ts
)

target_link_libraries(Footlight
    PRIVATE
        Qt::Core
        Qt::Widgets
)
target_link_libraries(Footlight PRIVATE Qt6::Core)

include(GNUInstallDirs)

install(TARGETS Footlight
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET Footlight
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
