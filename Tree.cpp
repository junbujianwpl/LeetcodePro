#include "Tree.h"

Tree::Tree()
{

}

vector<int> Tree::postorder(Node *root)
{
    vector<int> result;
    if(root == NULL) return result;

    for(auto i:root->children){
        auto res=postorder(i);
        result.insert(result.end(),res.begin(),res.end());
    }
    result.push_back(root->val);
    return result;
}
