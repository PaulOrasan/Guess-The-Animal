#ifndef UI_H
#define UI_H
#include "animalNode.h"

class UI
{
    public:
        UI(AnimalNode *);
        void run();
        void askQuestion();
    private:
        AnimalNode * root;
};

#endif // UI_H
