cmake_minimum_required(VERSION 3.16)

project(encryptoDecrypto VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OPENSSL_ROOT_DIR "C:/Qt/Tools/OpenSSLv3/Win_x64")
set(OPENSSL_CRYPTO_LIBRARY "${OPENSSL_ROOT_DIR}/lib/libcrypto.lib")
set(OPENSSL_INCLUDE_DIR "${OPENSSL_ROOT_DIR}/include")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets SerialPort Core)
find_package(OpenSSL REQUIRED)

qt_add_resources(RESOURCES resources.qrc)

set(PROJECT_SOURCES
        main.cpp
        functiontest.cpp
        functiontest.h
        functiontest.ui
        ${RESOURCE_FILES}
)

set(RESOURCE_FILES
    app_icon.rc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(encryptoDecrypto
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        portScannerComboBox.h
        serialPort.h
        .gitignore
        serialPort.cpp
        resources.qrc
        MyTabWidget.h
        encrypto.h
        encrypto.cpp
        app_icon.rc
        delTreeWidget.h




    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET encryptoDecrypto APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(encryptoDecrypto SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(encryptoDecrypto
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(encryptoDecrypto PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::SerialPort
    Qt${QT_VERSION_MAJOR}::Core
    OpenSSL::SSL
    OpenSSL::Crypto
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.encryptoDecrypto)
endif()
set_target_properties(encryptoDecrypto PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS encryptoDecrypto
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(encryptoDecrypto)
endif()

target_sources(${PROJECT_NAME} PRIVATE ${RESOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${OPENSSL_INCLUDE_DIR})

set_target_properties(encryptoDecrypto PROPERTIES
    RC_COMPILE_DEFINITIONS "IDI_ICON1=1"
)
