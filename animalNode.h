#ifndef ANIMALTREE_H
#define ANIMALTREE_H
#include <string>

class AnimalNode
{
    public:
        AnimalNode(std::string, bool);
        AnimalNode * getLeftChild();
        AnimalNode * getRightChild();
        void setLeftChild(AnimalNode *);
        void setRightChild(AnimalNode *);
        bool getIsQuestion();
        std::string getValue();
        void insertNode(AnimalNode *, bool);
        void selfDelete();

    private:
        AnimalNode *left;
        AnimalNode *right;
        bool isQuestion;
        std::string value;
};

#endif // ANIMALTREE_H
