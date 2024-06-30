class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        // Union find
        vector<int> root_A(n + 1);
        vector<int> root_B(n + 1);
        for (int i = 1; i <= n; i++) {
            root_A[i] = i;
            root_B[i] = i;
        }

        int res = 0;
        int aliceEdges = 0;
        int bobEdges = 0;

        // Alice and Bob
        for (auto& edge : edges) {
            if (edge[0] == 3) {
                if (uni(edge[1], edge[2], root_A)) {
                    aliceEdges++;
                    if (uni(edge[1], edge[2], root_B)) {
                        bobEdges++;
                    }
                } else {
                    res++;
                }
            }
        }

        vector<int> root_A_copy = root_A;

        // only Alice
        for (auto& edge : edges) {
            if (edge[0] == 1) {
                if (uni(edge[1], edge[2], root_A)) {
                    aliceEdges++;
                } else {
                    res++;
                }
            }
        }

        // only Bob
        root_A = root_A_copy;
        for (auto& edge : edges) {
            if (edge[0] == 2) {
                if (uni(edge[1], edge[2], root_B)) {
                    bobEdges++;
                } else {
                    res++;
                }
            }
        }

        return (aliceEdges == bobEdges && aliceEdges == n - 1) ? res : -1;
    }

    bool uni(int a, int b, vector<int>& root) {
        int root_A = find(a, root);
        int root_B = find(b, root);
        if (root_A == root_B) {
            return false;
        }
        root[root_A] = root_B;
        return true;
    }

    int find(int a, vector<int>& root) {
        if (root[a] != a) {
            root[a] = find(root[a], root);
        }
        return root[a];
    }
};
