#include "BST.h"
    /*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	NodeInterface * BST::getRootNode() const
	{
      return root;
	}

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool BST::add(int data)
	{
	    return insert(this->root, data);
	}

  bool BST::insert( Node*& local_root, int data) {
    if (local_root == NULL) { 
      local_root = new Node(data); 
      return true; 
    } else {
      if (data < local_root->data) 
        return insert(local_root->leftChild, data); 
      else if (local_root->data < data) 
        return insert(local_root->rightChild, data); 
      else { return false; }
    }
  }

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool BST::remove(int data)
	{
      return erase(this->root, data);
	}

  bool BST::erase( Node*& local_root, int data) {
    if (local_root == NULL) { 
      return false; 
    } else { 
      if (data < local_root->data) 
        return erase(local_root->leftChild, data);
      else if (local_root->data < data) 
        return erase(local_root->rightChild, data); 
      else { // Found item } 
        Node* old_root = local_root; 
        if (local_root->leftChild == NULL) { 
          local_root = local_root->rightChild; 
        } else if (local_root->rightChild == NULL) { 
          local_root = local_root->leftChild; 
        } else { 
          replace_parent(old_root, old_root->leftChild); 
        } delete old_root; return true;
      }
    }
  }

  void BST::replace_parent( Node*& old_root, Node*& local_root) {
    if (local_root->rightChild != NULL) { 
      replace_parent(old_root, local_root->rightChild);
    } else { 
      old_root->data = local_root->data; 
      old_root = local_root; 
      local_root = local_root->leftChild;
    }
  }

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void BST::clear()
	{
      deleteBST(root);
	}


  void BST::deleteBST(Node*& local_root) {
    if(local_root == NULL) {
      return;
    }
    deleteBST(local_root->leftChild);
    deleteBST(local_root->rightChild);
    local_root = NULL;
}


