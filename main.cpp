#include "ui.h";
#include "animalNode.h"
#include <string>

AnimalNode * initialise()
{
    std::string initialQuestion = "is it a mammal? ";
    std::string yesAnswer = "dog";
    std::string noAnswer = "chicken";
    AnimalNode * root = new AnimalNode (initialQuestion, true);
    AnimalNode * rightChild = new AnimalNode (yesAnswer, false);
    AnimalNode * leftChild = new AnimalNode(noAnswer, false);
    root->setRightChild(rightChild);
    root->setLeftChild(leftChild);
    return root;
}

void clearData(AnimalNode * root)
{
    if (root->getLeftChild() == root->getRightChild() && root->getLeftChild() == NULL) {
        delete root;
        return;
    }
    if (root->getLeftChild() != NULL) {
        clearData(root->getLeftChild());
    }
    if (root->getRightChild() != NULL) {
        clearData(root->getRightChild());
    }
    delete root;
    return;
}
int main()
{
    AnimalNode * root = initialise();
    UI console = UI(root);
    console.run();
    clearData(root);
}
