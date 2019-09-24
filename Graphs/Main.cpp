#include <iostream>
#include "Graph.h"
//#include "Graph.cpp"

using namespace std;

int menu()
{
    int response = 0;
    
    cout << "Menu:" << endl;
    cout << "1. Add Node" << endl;
    cout << "2. Add Edge" << endl;
    cout << "3. Breadth First Search" << endl;
    cout << "4. Depth First Search" << endl;
    cout << "5. Topological Sort" << endl;
    cout << "6. Connected Components" << endl;
    cout << "7. Quit" << endl;
    cout << "Please input the option you would like: ";
    cin >> response;
    cout << "---------------------------------------" << endl;
    return response;
}
bool validateInput(int response, Graph<int>& g, bool clearScreen)
/* returns a bool determining if the program should quit or not, 
 * true if the program should quit
*/
{
    bool quit = false;
    if(response >= 1 && response <= 7)
    {
        switch(response)
        {
            case 1:
            {
				cout << (clearScreen?string(100, '\n'):"");
                cout<< "what int would you like to add?";
				int add = 0;
				cin >> add;
				g.addVertex(add);
                break;
            }
            case 2:
            {
                cout << (clearScreen?string(100, '\n'):"");
                int v = 0, u = 0;
				cout << "Vertex 1: ";
				cin >> v;
				cout << "Vertex 2: ";
				cin >> u;

				g.addEdge(v, u);
				break;
            }
            case 3:
            {
                cout << (clearScreen?string(100, '\n'):"");
				cout << "What vertex would you like to start at? ";
				int start = 0;
				cin >> start;
				g.printBfs(start);
                break;
            }
			case 4:
			{
                cout << (clearScreen?string(100, '\n'):"");
				cout << "What vertex would you like to start at? ";
				int start = 0;
				cin >> start;
				g.Dfs(start);
                break;
			}
			case 5:
			{
                cout << (clearScreen?string(100, '\n'):"");
				vector<int> x = g.topoSort();
				cout << endl;
				for(int a : x)
					cout << a << " ";
				cout << endl;
				break;
			}
			case 6:
			{
                cout << (clearScreen?string(100, '\n'):"");
				vector<vector<int>> x = g.connectedComps();
				cout << endl;
				for(vector<int> a : x)
				{
					for(int b : a)
					{	cout << b; }
					cout << endl;
				}
				break;
			}
            case 7:
            {
                //cout << "back";
                quit = true;
                break;
            }
            
        }//end switch
    }
    else
	{
        cout << (clearScreen?string(100, '\n'):"");
		cout << "Please enter a valid integer" << endl << endl;
	}
      return quit;          
}


int main()
{
    Graph<int> g = Graph<int>(true);
    cout << "Clear screen?\nyes:1 no:0 " << endl;
	bool clear = true;
	cin >> clear;
    cout << (clear?string(100, '\n'):"");
    bool quit = false;
    while(!quit)//menu asks for which option, which returns the choice into validateInput, which returns if the program should quit
    {
            quit = validateInput(menu(), g, clear);
    }
    return 0;
}

