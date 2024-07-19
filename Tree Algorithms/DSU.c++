class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findUltimateParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }
    void UnionByRank(int u, int v)
    {
        int x = findUltimateParent(u);
        int y = findUltimateParent(v);
        if (x != y)
        {
            if (rank[x] < rank[y])
            {
                parent[x] = y;
            }
            else if (rank[x] > rank[y])
            {
                parent[y] = x;
            }
            else
            {
                parent[x] = y;
                rank[y]++;
            }
        }
    }
    void UnionBySize(int u, int v)
    {
        int x = findUltimateParent(u);
        int y = findUltimateParent(v);
        if (x != y)
        {
            if (size[x] < size[y])
            {
                parent[x] = y;
                size[y] += size[x];
            }
            else
            {
                parent[y] = x;
                size[x] += size[y];
            }
        }
    }
};