#include <iostream>
#include <stack>

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

    void dfs()
    {
        line();
        stack <int> stk;
        int src, flag, pick;
        int visit [verts] =  {0};

        cout  << "Enter source vertex: ";
        cin >> src;

        stk.push(src);
        cout << "Depth First Search Traversal: ";
        cout << stk.top() << " ";
        while (!stk.empty())
        {
            flag = 0;
            pick = stk.top();
            for (int j = 0; j < verts; j++)
            {
                if(visit[j] == 0 && AM[pick][j] == 1)
                {
                    flag = 1;
                    stk.push(j);
                    visit[pick] = 1;
                    cout << j << " ";
                    break;
                }
            }
            if (flag == 1)
            {
                stk.pop();
            }
        }
        line();
    }



};

int main()
{
    DFS_graph obj;
    obj.CreateGraph();
    obj.dfs();
    return 0;
}
