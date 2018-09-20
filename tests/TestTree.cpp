#include "TestTree.h"
#include "common.h"

TestTree::TestTree()
{

}

void TestTree::postorderTest()
{
    vector<Node> nodes({Node(0),Node(1),Node(2),Node(3),Node(4)});
    vector<Node> nodes2({Node(10),Node(11),Node(12),Node(13),Node(14)});

    for(int i=0;i<nodes.size();++i){
        nodes[0].children.push_back(&nodes2[i]);
    }

    vector<int> res=Tree::postorder(&nodes[0]);
    print_arr(res,res.size());


}
