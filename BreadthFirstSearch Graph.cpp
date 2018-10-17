#include <iostream>
#include <queue>

using namespace std;

class DFS_graph
{
    int verts;
    int edges;
    int **AM;
public:
    DFS_graph()
    {
        cout << "Enter Number of vertices: ";
        cin >> verts;
        cout << "Enter number of Edges: ";
        cin >> edges;
        AM = new int *[verts];
        for(int i = 0; i < verts; i++)
        {
            AM[i] = new int [verts];
        }

        for(int i = 0; i < verts; i++)
        {
            for(int j = 0; j < verts; j++)
            {
                AM[i][j] = 0;
            }

        }
    }
    void CreateGraph()
    {
        line();
        for(int i = 1; i <= edges; i++)
        {
            int v1, v2;
            cout << "Edge " << i << endl;
            cout << "\tVertex 1: ";
            cin >> v1;
            cout << "\tVertex 2: ";
            cin >> v2;
            line();
            if(v1 >=  0 && v1 < verts && v2 >=  0 && v2 < verts )
            {
                AM[v1][v2] = 1;
            }
            else
            {
                cout << "Invalid Vertex Entered." << endl;
                break;
            }
        }
    }

    void line()
    {
        cout << " " << endl;
    }

    void BreadthFirst()
    {
        line();
        queue <int> q;
        int src, flag, store;
        int visit [verts] =  {0};

        cout  << "Enter source vertex: ";
        cin >> src;
        visit[src] = 1;
        q.push(src);

        while (!q.empty())
        {
            store = q.front();
            q.pop();
            cout << store << " ";
            for (int j = 1; j <= verts; j++)
            {
                if(visit[j] == 0)
                {
                    if (AM[store][j] == 1)
                    {
                        visit[j] = 1;
                        q.push(j);
                    }
                }
            }
        }

    }
};


int main()
{
    DFS_graph obj;
    obj.CreateGraph();
    obj.BreadthFirst);
    return 0;
}
