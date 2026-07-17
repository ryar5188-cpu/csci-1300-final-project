# CSCI 1300 Final Project

## Theme

The player character lives in Washington D.C. and really wants to buy a house, but is very poor. You meet a character named Insider Bill who will let buy one if you play his game. Bill gives you four quarters, each with five turns, to gather the three items he needs. You can use your turns to make money from congresspeople or gather it yourself, spend your money on charisma, and use your charisma to buy Bill's items. Can you survive cutthroat environment and last through the turns to get yourself a house?

## Goal

Obtain Insider Bill's 3 items in 20 turns or less.

## How to compile and run

Copy, paste and enter "g++ main.cpp Character.cpp Item.cpp Location.cpp -Wall -Werror -Wpedantic" and "./a.out" into the FinalProject terminal

## How to play

After entering your username, you enter the letters a-f or A-F into the terminal when prompted to move to different locations or talk with characters.

## Classes

Item: stores the name, cost, and whether or not you have acquired the item.
Location: stores the name of the location and prints relevant information when the player goes to any location.
Character: stores the location, name, dialogue, and whether or not the player has interacted with the character before.

## Extra credit

None
