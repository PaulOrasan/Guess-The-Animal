#include "animalNode.h"

AnimalNode::AnimalNode(std::string newValue, bool isThisQuestion)
{
    this->left = NULL;
    this->right = NULL;
    this->value.assign(newValue);
    this->isQuestion = isThisQuestion;
}

AnimalNode * AnimalNode::getLeftChild()
{
    return this->left;
}

AnimalNode * AnimalNode::getRightChild()
{
    return this->right;
}

void AnimalNode::setLeftChild(AnimalNode * newNode)
{
    this->left = newNode;
}

void AnimalNode::setRightChild(AnimalNode * newNode)
{
    this->right = newNode;
}

bool AnimalNode::getIsQuestion()
{
    return this->isQuestion;
}

std::string AnimalNode::getValue()
{
    return this->value;
}


void AnimalNode::insertNode(AnimalNode * newNode, bool right)
{
    if (right) {
        AnimalNode * container = this->right;
        this->right = newNode;
        if (newNode->getLeftChild() == NULL)
            newNode->setLeftChild(container);
        else
            newNode->setRightChild(container);
    } else {
        AnimalNode * container = this->left;
        this->left = newNode;
        if (newNode->getLeftChild() == NULL)
            newNode->setLeftChild(container);
        else
            newNode->setRightChild(container);
    }
}
