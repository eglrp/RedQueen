int c[100][100];
int LCS_LENGTH(const char* X, const char* Y)
{
    if(X == NULL || Y == NULL)
        return 0;
    int m=strlen(X);
    int n=strlen(Y);
    for(int i=1; i<m; ++i)
        c[i][0]=0;
    for(int i=1; i<n; ++i)
        c[0][i]=0;
    c[0][0]=0;
    for(int i=1; i <= m; ++i)
        for(int j=1; j <= n; ++j)
        {
            if(X[i] == Y[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i][j-1], c[i-1][j]);
        }
    return c[m][n];
}