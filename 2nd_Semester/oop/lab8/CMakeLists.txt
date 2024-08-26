cmake_minimum_required(VERSION 3.27)
project(lab6)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.7.0\\mingw_64\\lib\\cmake")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

add_executable(lab6 main.cpp
        UI.cpp
        UI.h
        Repository.cpp
        Repository.h
        Service.cpp
        Service.h
        Domain.cpp
        Domain.h
        validator.h
        undo.h
        undo.h
        undo.h
        RepoLab.cpp
        RepoLab.h)
find_package(Qt6 COMPONENTS
        Core
        Widgets
        REQUIRED)
target_link_libraries(${PROJECT_NAME}         Qt::Core
        Qt6::Widgets
)