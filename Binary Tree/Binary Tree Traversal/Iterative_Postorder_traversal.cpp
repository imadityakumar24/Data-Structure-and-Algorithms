/*


===============  Iterative Postorder Traversal of Binary Tree  =============== 


*/






#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};



// Postorder : left right root 
// now reverse it : root right left
// now store ans in a arrays
// last reverse the array 
// we get out postorder traversal


// tc = 0(n)
// sc = o(n)
class Solution {
public:
    vector<int> postOrder(Node* root) {
        vector <int> ans;
        stack <Node*> st;
        st.push(root);
        
        while (!st.empty()) {
            Node* temp = st.top();
            st.pop();
            
            ans.push_back(temp->data);
            
            if (temp->left != nullptr)
                st.push(temp->left);   
            if (temp->right != nullptr)
                st.push(temp->right);        
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};




int main() {
    cout << "\n\n";

    Solution obj;

    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(8);

    root->left->left = new Node(10);
    root->left->right = new Node(12);

    root->right->left = new Node(14);
    root->right->right = new Node(16);

    cout << "        2         " << endl;
    cout << "      /   \\      " << endl;
    cout << "     4     8      " << endl;
    cout << "   /  \\   /  \\  " << endl;
    cout << " 10   12 14   16  " << endl << endl;
     
    vector <int> ans = obj.postOrder(root); 

    cout << "\nPostOrder : ";
    for (auto i : ans) cout << i << " ";
    

    cout << "\n\n";
    return 0;
}
