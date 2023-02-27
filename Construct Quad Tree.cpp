/*
// Definition for a QuadTree node.
class Node {
public:
    bool value;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        value = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _value, bool _isLeaf) {
        value = _value;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _value, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        value = _value;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* constructQuadTree(vector<vector<int>>& grid, int rowStart, int rowEnd, int colStart, int colEnd) {
        if (rowStart > rowEnd || colStart > colEnd) {
            return nullptr;
        }
        
        // Check if all elements in the quadrant are the same
        bool isLeaf = true;
        int value = grid[rowStart][colStart];
        for (int i = rowStart; i <= rowEnd; i++) {
            for (int j = colStart; j <= colEnd; j++) {
                if (grid[i][j] != value) {
                    isLeaf = false;
                    break;
                }
            }
            if (!isLeaf) {
                break;
            }
        }
        
        // If all elements in the quadrant are the same, create a new leaf node
        if (isLeaf) {
            return new Node(value, true);
        }
        
        // Otherwise, divide the quadrant into four sub-quadrants and recursively construct the quad-tree for each sub-quadrant
        int rowMid = (rowStart + rowEnd) / 2;
        int colMid = (colStart + colEnd) / 2;
        Node* topLeft = constructQuadTree(grid, rowStart, rowMid, colStart, colMid);
        Node* topRight = constructQuadTree(grid, rowStart, rowMid, colMid+1, colEnd);
        Node* bottomLeft = constructQuadTree(grid, rowMid+1, rowEnd, colStart, colMid);
        Node* bottomRight = constructQuadTree(grid, rowMid+1, rowEnd, colMid+1, colEnd);
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return constructQuadTree(grid, 0, n-1, 0, n-1);
    }
};