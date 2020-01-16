/*
*输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/

    bool HasSubTree1(TreeNode *p1, TreeNode *p2){
        if(p2 == NULL){
            return true;
        }
        if(p1 == NULL){
            return false;
        }
        if(p1->val != p2->val){
            return false;
        }

        return HasSubTree1(p1->left, p2->left) &&
               HasSubTree1(p1->right, p2->right);

    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        TreeNode *p1 = pRoot1;
        TreeNode *p2 = pRoot2;
        bool result = false;

        if(p1 != NULL && p2 != NULL){

            if(p1->val == p2->val){
                result = HasSubTree1(p1, p2);
            }
            if(result == false){
                result = HasSubtree(p1->left, p2);
            }
            if(result == false){
                result = HasSubtree(p1->right, p2);
            }
        }

        return result;
    }
