class DSU {
private:
    vector<int> parent;
    vector<int> size;
public:
    DSU(int n) : parent(n), size(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_parent(int node) {
        if (parent[node] == node) return node;

        return parent[node] = find_parent(parent[node]);
    }
    
    void union_by_size(int node1, int node2) {
        int p_node1 = find_parent(node1), p_node2 = find_parent(node2);
        // same component
        if (p_node1 == p_node2) return;

        if (size[p_node1] < size[p_node2]) {
            parent[p_node1] = parent[p_node2];
            size[p_node2] += size[p_node1];
        }
        else {
            parent[p_node2] = parent[p_node1];
            size[p_node1] += size[p_node2];
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size() + 1);

        for (auto& edge: edges) {
            if (dsu.find_parent(edge[0]) == dsu.find_parent(edge[1])) return edge;
            dsu.union_by_size(edge[0], edge[1]);
        }

        return {}; 
    }
};