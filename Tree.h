#ifndef TREE_H
#define TREE_H

#include "common.h"
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}
    Node(int i) :val(i){}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Tree
{
public:
    Tree();

    static vector<int> postorder(Node *root);

private:
//    static vector<int>

};

#endif // TREE_H
