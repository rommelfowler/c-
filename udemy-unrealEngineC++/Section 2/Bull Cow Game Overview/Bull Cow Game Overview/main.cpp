//
//  main.cpp
//  Bull Cow Game Overview
//
//  Created by rommel santiago on 11/8/17.
//  Copyright © 2017 Rommel Fowler. All rights reserved.
//  @package - Bull Cow Game. Guess the correct number out of 5
//
/*
 This is the console executable that makes use of the BullCow class.
 This acts as the view in the MVC pattern, and is responsible for all user
 interaction. For game logic see the FBullCowGame class.
 */
#include <iostream>
#include <string>
#include "FBullCowGame.hpp"


using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // instantiate a new game

// the entry point for our application
int main()
{
    bool bPlayAgain = false;
    do {
        PrintIntro();
        PlayGame();
        bPlayAgain = AskToPlayAgain();
    }
    while (bPlayAgain);
    
    return 0; // exit the application
}


// introduce the game
void PrintIntro()
{
    constexpr int32 WORD_LENGTH = 9;
    std::cout << "Welcome to Bulls and Cows, a fun word game.\n";
    std::cout << "Can you guess the " << WORD_LENGTH;
    std::cout << " letter isogram I'm thinking of?\n";
    std::cout << std::endl;
    return;
}


void PlayGame()
{
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    
    // loop for the number of turns asking for guesses
    // TODO change from FOR to WHILE loop once we are validating tries
    
    for (int32 count = 1; count <= MaxTries; count++) {
        FText Guess = GetGuess();                             //TODO make loop check for validity
        
        // submit valid guess to the game
        BullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
        // print number of balls and cows
        std::cout << "Bulls + " << BullCowCount.Bulls;
        std::cout << ". Cows + " << BullCowCount.Cows << std::endl;

        
        std::cout << "Your guess was: " << Guess << std::endl;
        std::cout << std::endl;
    }
    // TODO add a game summary
    
}


FText GetGuess()
{
    int32 CurrentTry = BCGame.GetCurrentTry();
    
    // get a guess from the player
    std::cout << "Try " << CurrentTry << ". Enter your guess: ";
    FText Guess = "";
    std::getline(std::cin, Guess);
    return Guess;
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again (y/n)? ";
    FText Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 'y') || (Response[0] == 'Y');

    
}
