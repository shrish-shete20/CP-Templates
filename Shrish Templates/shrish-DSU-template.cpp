struct DSU
{
    int n;
    vector<int>leader,sizes;
    // pair<int,int> max_size={0,1};
    DSU(int _n)
    {
        n=_n;
        // max_size.first=n;
        leader.resize(n+1);
        sizes.resize(n+1);
        for(int i = 0; i <= n; i++)
        {
            leader[i]=i;
            sizes[i]=1;
        }
    }
    int get_leader(int node)
    {
        if(node==leader[node])
        {
            return node;
        }
        return leader[node]=get_leader(leader[node]);
    }
    void connect(int x,int y)
    {
        int leader_x=get_leader(x);
        int leader_y=get_leader(y);
        if(leader_x!=leader_y)
        {
            // max_size.first--;
            if(sizes[leader_x]<sizes[leader_y])
            {
                swap(leader_x,leader_y);
            }
            leader[leader_y]=leader_x;
            sizes[leader_x]+=sizes[leader_y];
            // max_size.second=max(max_size.second,sizes[leader_x]);
        }
        // max_size.second=leader_x;
    }
};
