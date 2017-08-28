/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int maxDepth(TreeNode* root) {

    std::vector<TreeNode *> n_depth_nodes;
    n_depth_nodes.push_back(root);

    int max_depth = 0;
    if(root == NULL){
        return 0;
    }

    while(n_depth_nodes.size() > 0){
        max_depth++;
        std::vector<TreeNode *> n_plus_depth_nodes;
        n_plus_depth_nodes.clear();

        for(int i = 0; i < n_depth_nodes.size(); i++){
            if(n_depth_nodes[i]->left != NULL) n_plus_depth_nodes.push_back(n_depth_nodes[i]->left);
            if(n_depth_nodes[i]->right != NULL) n_plus_depth_nodes.push_back(n_depth_nodes[i]->right);
        }

        n_depth_nodes = n_plus_depth_nodes;
    }
    return max_depth;
}


bool isSameTree(TreeNode *p, TreeNode *q) {
    if (p == NULL || q == NULL) return (p == q);
    return (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}
/*
    bool isSameTree(TreeNode* p, TreeNode* q) {

        std::vector<TreeNode *> p_node_layer;
        std::vector<TreeNode *> q_node_layer;

        if(p == NULL && q == NULL){
            return true;
        }else if((p == NULL && q != NULL) ||(p != NULL && q == NULL)){
            return false;
        }

        p_node_layer.push_back(p);
        q_node_layer.push_back(q);

        while(p_node_layer.size() == q_node_layer.size() && q_node_layer.size() > 0){

            std::vector<TreeNode *> new_p_layer;
            std::vector<TreeNode *> new_q_layer;
            new_p_layer.clear();
            new_q_layer.clear();

            for(int i = 0; i < p_node_layer.size(); i++){

                if(p_node_layer[i]->val == q_node_layer[i]->val){

                    if(p_node_layer[i]->right != NULL && q_node_layer[i]->right != NULL){
                        //add
                        new_p_layer.push_back(p_node_layer[i]->right);
                        new_q_layer.push_back(q_node_layer[i]->right);

                    }else if(p_node_layer[i]->right == NULL && q_node_layer[i]->right != NULL){
                        return false;
                    }else if(p_node_layer[i]->right != NULL && q_node_layer[i]->right == NULL){
                        return false;
                    }

                    if(p_node_layer[i]->left != NULL && q_node_layer[i]->left != NULL){
                        new_p_layer.push_back(p_node_layer[i]->left);
                        new_q_layer.push_back(q_node_layer[i]->left);
                    }else if(p_node_layer[i]->left == NULL && q_node_layer[i]->left != NULL){
                        return false;
                    }else if(p_node_layer[i]->left != NULL && q_node_layer[i]->left == NULL){
                        return false;
                    }

                }else{
                    return false;
                }
            }

            p_node_layer = new_p_layer;
            q_node_layer = new_q_layer;
        }

        return true;

    }
    */
