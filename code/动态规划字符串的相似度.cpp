int calculateStringDistance(string strA, string strB)
{
    int lenA = strA.length();
    int lenB = strB.length();
    int** c=new int*[lenA+1];
    for (int i = 0; i < lenA; ++i)
        c[i] = new int[lenB+1];
    for(int i = 0; i < lenA; i++)
        c[i][lenB] = lenB - i;
    for(int j = 0; j < lenB; j++)
        c[lenA][j] = lenB - j;

    c[lenA][lenB] = 0;
    for (int i = lenA - 1; i >= 0; i--)
    {
        for(int j = lenB - 1; j >= 0; j--)
        {
            if(strB[j] == strA[i])
                c[i][j]=c[i+1][j+1];
            else
                c[i][j]=minValue(c[i][j+1], c[i+1][j], c[i+1][j+1])+1;
        }
    }
    int dis=c[0][0];
    for (int i = 0; i < lenA+1; ++i)
    {
        delete[] c;
    }

    delete[] c;
    return dis;
}