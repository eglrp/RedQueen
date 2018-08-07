int minPathSum2(vector<vector<int> > m)
{
    if(m.empty() || m[0].size() == 0)
        return 0;

    int more = max(m.size(), m[0].size());
    int less = min(m.size(), m[0].size());

    bool rowmore = more == m.size();
    vector<int> arr(less);

    arr[0] = m[0][0];

    for(int i = 1; i < less; i++)
    {
        arr[i] = arr[i-1] + (rowmore ? m[0][i] : m[i][0]);
    }

    for(int i = 1; i < more; i++)
    {
        arr[0] = arr[0] + (rowmore ? m[i][0] : m[0][i]);

        for(int j = 1; j < less; j++)
        {
            arr[j] = min(arr[j-1], arr[j]) + (rowmore? m[i][j] : m[j][i]);
        }

    }

    return arr[less-1];
}