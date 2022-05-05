#include "assign2.hpp"


assign2_exception::exception maintain(tree_node *node);


assign2_exception::exception zig(tree_node *node);


assign2_exception::exception zag(tree_node *node);


assign2_exception::exception add_node(tree_node *father, tree_node *child, int child_direction) {
    assign2_exception::exception e = 0;
    if (!father || !child)
        e |= NULL_POINTER_EXCEPTION;
    if (child_direction != CHILD_DIRECTION_LEFT && child_direction != CHILD_DIRECTION_RIGHT)
        e |= INVALID_CHILD_DIRECTION_EXCEPTION;
    if (child && child->father)
        e |= DUPLICATED_FATHER_EXCEPTION;
    if (father && child_direction == CHILD_DIRECTION_LEFT && father->l_child)
        e |= DUPLICATED_LEFT_CHILD_EXCEPTION;
    if (father && child_direction == CHILD_DIRECTION_RIGHT && father->r_child)
        e |= DUPLICATED_RIGHT_CHILD_EXCEPTION;
    if (e != 0)
        return e;
    if (child_direction == CHILD_DIRECTION_LEFT)
        father->l_child = child;
    if (child_direction == CHILD_DIRECTION_RIGHT)
        father->r_child = child;
    child->father = father;
    tree_node *temp = father;
    while (temp) {
        (temp->tree_count)++;
        temp = temp->father;
    }
    return e;
}


assign2_exception::exception judge_child_direction(tree_node *node, int *child_direction) {
    if (!node || !child_direction)
        return NULL_POINTER_EXCEPTION;
    if (!node->father)
        return ROOTS_FATHER_EXCEPTION;
    tree_node *father = node->father;
    if (node == father->l_child)
        (*child_direction) = CHILD_DIRECTION_LEFT;
    if (node == father->r_child)
        (*child_direction) = CHILD_DIRECTION_RIGHT;
    return 0;
}


assign2_exception::exception insert_into_BST(BST *bst, uint64_t data, tree_node **inserted_node) {
    if (!bst)
        return NULL_POINTER_EXCEPTION;
    if (!bst->comp)
        return NULL_COMP_FUNCTION_EXCEPTION;
    if (!bst->root) {
        auto *node = new tree_node{nullptr, nullptr, nullptr, 1, 1, data};
        bst->root = node;
        *inserted_node = node;
        return 0;
    }
    tree_node *pre = nullptr;
    tree_node *temp = bst->root;
    auto comp_func = bst->comp;
    int direction = 0;
    while (temp) {
        pre = temp;
        int comp = comp_func(data, temp->data);
        if (comp < 0) {
            temp = temp->l_child;
            direction = CHILD_DIRECTION_LEFT;
        } else if (comp > 0) {
            temp = temp->r_child;
            direction = CHILD_DIRECTION_RIGHT;
        } else {
            assign2_exception::exception e = 0;
            (temp->node_count)++;
            (*inserted_node) = temp;
            while (temp) {
                e |= maintain(temp);
                temp = temp->father;
            }
            return e;
        }
    }
    temp = new tree_node{nullptr, nullptr, nullptr, 1, 1, data};
    if (direction == CHILD_DIRECTION_LEFT)
        pre->l_child = temp;
    if (direction == CHILD_DIRECTION_RIGHT)
        pre->r_child = temp;
    temp->father = pre;
    while (pre) {
        maintain(pre);
        pre = pre->father;
    }
    (*inserted_node) = temp;
    return 0;
}


assign2_exception::exception find_in_BST(BST *bst, uint64_t data, tree_node **target_node) {
    if (!bst)
        return NULL_POINTER_EXCEPTION;
    if (!(bst->comp))
        return NULL_COMP_FUNCTION_EXCEPTION;
    tree_node *temp = bst->root;
    auto comp_func = (bst->comp);
    while (true) {
        if (!temp) {
            (*target_node) = nullptr;
            break;
        }
        int comp = comp_func(data, temp->data);
        if (comp == 0) {
            (*target_node) = temp;
            break;
        } else if (comp > 0)
            temp = temp->r_child;
        else
            temp = temp->l_child;
    }
    return 0;
}


assign2_exception::exception maintain(tree_node *node) {
    if (!node)
        return NULL_POINTER_EXCEPTION;
    uint32_t count = node->node_count;
    if (node->l_child)
        count = count + node->l_child->tree_count;
    if (node->r_child)
        count = count + node->r_child->tree_count;
    node->tree_count = count;
    return 0;
}


assign2_exception::exception zig(tree_node *node) {//Right Rotation
    if (!node || !(node->father))
        return NULL_POINTER_EXCEPTION;
    tree_node *temp = node->father;
    int *direction = new int;
    assign2_exception::exception e = 0;
    e |= judge_child_direction(temp, direction);
    temp->l_child = node->r_child;
    if (node->r_child)
        node->r_child->father = temp;
    node->r_child = temp;
    tree_node *grand = temp->father;
    temp->father = node;
    maintain(temp);
    maintain(node);
    if (e == ROOTS_FATHER_EXCEPTION) {
        node->father = nullptr;
        delete direction;
        return e;
    }
    if ((*direction) == CHILD_DIRECTION_LEFT)
        grand->l_child = node;
    if ((*direction) == CHILD_DIRECTION_RIGHT)
        grand->r_child = node;
    node->father = grand;
    delete direction;
    return 0;
}


assign2_exception::exception zag(tree_node *node) {//Left Rotation
    if (!node || !(node->father))
        return NULL_POINTER_EXCEPTION;
    tree_node *temp = node->father;
    int *direction = new int;
    assign2_exception::exception e = 0;
    e |= judge_child_direction(temp, direction);
    temp->r_child = node->l_child;
    if (node->l_child)
        node->l_child->father = temp;
    node->l_child = temp;
    tree_node *grand = temp->father;
    temp->father = node;
    maintain(temp);
    maintain(node);
    if (e == ROOTS_FATHER_EXCEPTION) {
        node->father = nullptr;
        delete direction;
        return e;
    }
    if ((*direction) == CHILD_DIRECTION_LEFT)
        grand->l_child = node;
    if ((*direction) == CHILD_DIRECTION_RIGHT)
        grand->r_child = node;
    node->father = grand;
    delete direction;
    return 0;
}


assign2_exception::exception splay(BST *bst, tree_node *node) {
    if (!bst)
        return NULL_POINTER_EXCEPTION;
    assign2_exception::exception e = 0;
    if (!node)
        e |= NULL_POINTER_EXCEPTION;
    if (!(bst->comp))
        e |= NULL_COMP_FUNCTION_EXCEPTION;
    if (node == (bst->root))//exclude the node is the toot itself
        return e;
    tree_node *temp = node;
    while (temp->father)
        temp = temp->father;
    if (temp != (bst->root))
        e |= SPLAY_NODE_NOT_IN_TREE_EXCEPTION;
    if (e != 0)
        return e;
    temp = node;
    while (true) {
        if (temp->father == bst->root) {
            int *direction = new int;
            e |= judge_child_direction(temp, direction);
            if (e != 0) {
                delete direction;
                return e;
            }
            if ((*direction) == CHILD_DIRECTION_LEFT)
                e |= zig(temp);//Not an exception to handle
            if ((*direction) == CHILD_DIRECTION_RIGHT)
                e |= zag(temp);//Not an exception to handle
            bst->root = temp;
            delete direction;
            return 0;
        } else {
            int *up_dir = new int;
            int *down_dir = new int;
            e |= judge_child_direction(temp, down_dir);
            e |= judge_child_direction(temp->father, up_dir);
            if (e != 0) {//Not an exception to occur
                delete up_dir;
                delete down_dir;
                return e;
            }
            if ((*up_dir) == CHILD_DIRECTION_LEFT && (*down_dir) == CHILD_DIRECTION_LEFT) {
                e = zig(temp->father);
                e = zig(temp);
            } else if ((*up_dir) == CHILD_DIRECTION_LEFT && (*down_dir) == CHILD_DIRECTION_RIGHT) {
                e = zag(temp);
                e = zig(temp);
            } else if ((*up_dir) == CHILD_DIRECTION_RIGHT && (*down_dir) == CHILD_DIRECTION_LEFT) {
                e = zig(temp);
                e = zag(temp);
            } else {
                e = zag(temp->father);
                e = zag(temp);
            }
            delete up_dir;
            delete down_dir;
            if (e == ROOTS_FATHER_EXCEPTION) {
                bst->root = temp;
                return 0;
            }
        }
    }
}