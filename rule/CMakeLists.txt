cmake_minimum_required(VERSION 3.30)
project(RULE)


include_directories(
        include
)

add_library(RULE STATIC
        src/Card.cpp
        src/Deck.cpp
        src/Game.cpp
        src/Player.cpp
        include/Player1.hpp
        include/Player2.hpp
        src/Player1.cpp
)
target_include_directories(RULE
        PUBLIC
        include
)

