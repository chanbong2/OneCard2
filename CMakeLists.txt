#cmake_minimum_required(VERSION 3.30)
#project(OneCard)
#
#set(CMAKE_CXX_STANDARD 14)
#
#add_executable(OneCard main.cpp
#        rule/include/Game.hpp
#        include/main.hpp
#        rule/include/Card.hpp
#        rule/include/Deck.hpp
#        rule/include/Enum.hpp
#        rule/include/Player.hpp
#        rule/src/Card.cpp
#        rule/src/Deck.cpp
#        rule/src/Game.cpp
#        rule/src/Player.cpp
#        src/main.cpp)

cmake_minimum_required(VERSION 3.30)
project(GAME)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(rule)


add_executable(GAME
        src/main.cpp)

target_include_directories(GAME
        PUBLIC
        include
)

target_link_libraries(GAME
        PUBLIC
        RULE
)