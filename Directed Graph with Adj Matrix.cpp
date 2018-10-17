#include<iostream>

using namespace std;


class AdjMatrix_Graph
{
    int verts;
    int edges;
    int **AM;
public:
    AdjMatrix_Graph()
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

    void line()
    {
        cout << " " << endl;
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

    void Display()
    {
        cout << "Adjacecy Matrix of the Graph:-  " << endl;
        for(int i = 0; i < verts; i++)
        { cout << "\t";
            for (int j = 0; j < verts; j++)
            {
                cout << AM[i][j] << " ";
            }
            cout << " " << endl;

        }
    }


};




int main()
{
    AdjMatrix_Graph obj;

    obj.CreateGraph();
    obj.Display();


}
