#include <iostream>
#include <iomanip>

using namespace std;

const int INF = 999;
const int MAX = 20;

int main()
{
    int n, i, j, k;
    int c[MAX][MAX], d[MAX][MAX], nt[MAX][MAX];

    cout << "Enter the number of routers: ";
    cin >> n;

    cout << "\nEnter the cost matrix:\n";
    cout << "(Enter 999 for infinity/no direct connection)\n\n";

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> c[i][j];

            d[i][j] = c[i][j];

            if (c[i][j] != INF && i != j)
                nt[i][j] = j;
            else
                nt[i][j] = -1;
        }
    }

    // Algorithm
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (d[i][k] != INF && d[k][j] != INF)
                {
                    if (d[i][j] > d[i][k] + d[k][j])
                    {
                        d[i][j] = d[i][k] + d[k][j];
                        nt[i][j] = nt[i][k];
                    }
                }
            }
        }
    }

    cout << "\nFinal Distance Matrix:\n\n";

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << setw(5) << d[i][j];
        }
        cout << "\n";
    }

    cout << "\nRouting Table:\n";

    for (i = 0; i < n; i++)
    {
        cout << "\nRouter " << (i + 1) << ":\n";
        cout << "Destination\tCost\tNext Hop\n";

        for (j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            if (d[i][j] == INF)
                cout << (j + 1) << "\t\t999\t-\n";
            else
                cout << (j + 1) << "\t\t" << d[i][j] << "\t" << (nt[i][j] + 1) << "\n";
        }
    }

    return 0;
}
