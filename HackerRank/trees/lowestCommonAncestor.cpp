public static Node lca(Node root, int v1, int v2) {
    // Write your code here.        
    if (v1 > root.data && v2 > root.data) {
        // Move to the right subtree
        return lca(root.right, v1, v2);
    }

    if (v1 < root.data && v2 < root.data) {
        // Move to the left subtree
        return lca(root.left, v1, v2);    
    }

    // Found the LCA
    return root;
}