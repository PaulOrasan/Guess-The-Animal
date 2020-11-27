#include "ui.h"
#include <iostream>
UI::UI(AnimalNode * base)
{
    this->root = base;
}
void UI::run()
{
    std::string input;
    std::cout << "Welcome to this Guess the Animal Game\nThroughout the game, enter y for YES and n for NO when prompted like this \"y/n\"\nAttention, if your input is invalid the game will restart\n";
    std::cout << "Do you want to play? y/n \n";
    std::getline(std::cin, input);
    while (true) {
        if (input == "n") {
            std::cout << "Ok, see you later!";
            return;
        }
        if (input == "y") {
            break;
        }
        std::cout <<"Oh no! You entered invalid input.\nDo you want to play? y/n\n";
        std::getline(std::cin, input);
    }
    while (true) {
        AnimalNode * current = this->root;
        AnimalNode * before = this->root;
        while (true) {
            if (current->getIsQuestion()) {
                std::cout << current->getValue() <<" y/n \n";
                std::getline(std::cin, input);
                if (input == "n") {
                    before = current;
                    current = current->getLeftChild();
                    continue;
                }
                if (input == "y") {
                    before = current;
                    current = current->getRightChild();
                    continue;
                }
                std::cout << "Oh no! The only valid input here is y for YES and n for NO. Restarting...\n";
                break;
            } else {
                std::cout << "My guess is that "<<current->getValue()<<" is your animal! Was I correct? y/n \n";
                std::getline(std::cin, input);
                if (input == "y") {
                    std::cout << "Great! I love this game!\n";
                    break;
                }
                if (input == "n") {
                    std::string newAnimal;
                    std::string newQuestion;
                    bool truthValue;
                    std::cout <<"Oh no! Please input the correct animal: ";
                    std::getline(std::cin, newAnimal);
                    std::cout <<"Please input a question I should ask next time to guess the animal: ";
                    std::getline(std::cin, newQuestion);
                    std::cout <<"And what answer will make me choose this animal? y/n: ";
                    std::getline(std::cin, input);
                    if (input == "y" || input == "n") {
                        AnimalNode * newQuestionNode = new AnimalNode(newQuestion, true);
                        AnimalNode * newAnimalNode = new AnimalNode(newAnimal, false);
                        if (input == "y") {
                            newQuestionNode->setRightChild(newAnimalNode);
                        } else {
                            newQuestionNode->setLeftChild(newAnimalNode);
                        }
                        if (before->getRightChild() == current){
                            before->insertNode(newQuestionNode, true);
                        } else {
                            before->insertNode(newQuestionNode, false);
                        }
                        break;
                    } else {
                        std::cout << "Oh no! The only valid input here is y for YES and n for NO. Restarting...\n";
                        break;
                    }
                }
            }
        }
        while (true) {
            std::cout << "Do you want to play again? y/n\n";
            std::getline(std::cin, input);
            if (input == "y") {
                break;
            }
            if (input == "n") {
                std:: cout << "Ok, see you later!";
                return;
            }
            std::cout << "Oh no! The only valid input is y for YES and n for NO. I cannot continue until your input is valid\n";
        }
    }
}
