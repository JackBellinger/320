#include "BST.h"
#include "Student.h"
#include <iostream>
using namespace std;

int menu()
{
    int response = 0;
    
    cout << endl << "Menu:" << endl;
    cout << "1. insert" << endl;
    cout << "2. delete" << endl;
    cout << "3. print bst" << endl;
    cout << "4. quit" << endl;
    cout << "Please input the option you would like: ";
    cin >> response;
    cout << "---------------------------------------" << endl;
    return response;
}
template <class T>
bool validateInput(int response, BST<T>* bst, bool clearScreen)
/* returns a bool determining if the program should quit or not, 
 * true if the program should quit
*/
{
    bool quit = false;
    if(response >= 1 && response <= 5)
    {
        switch(response)
        {
            case 1:
            {
				bst->bstInsert();
                cout << (clearScreen?string(100, '\n'):"");
                break;
            }
            case 2:
            {
                cout << (clearScreen?string(100, '\n'):"");
				cout << "what would you like to delete?" << endl;
				int key = 0;
				cin >> key;
				T del = T(key);
                bst->bstDelete(bst->bstSearch(del));
                break;
            }
            case 3:
            {
                cout << (clearScreen?string(100, '\n'):"");
				cout << "How would you like to print it?" << endl;
				cout << "1. Inorder" << endl << "2. Preorder" << endl << "3. Postorder" << endl;
				int printChoice = 0;
				cin >> printChoice;
               	
				switch(printChoice)
				{
					case 1:
						bst->inOrder();
						break;
					case 2:
						bst->preOrder();
						break;
					case 3:
						bst->postOrder();
						break;
				}
                break;
            }
            case 4:
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
    BST<int>* iBST = new BST<int>();
    BST<Student>* sBST = new BST<Student>();
    
    cout << "Choose a BST type" << endl << "0. Student" << endl << "1. Integer" << endl;
    bool isIBST = 0;
    cin >> isIBST;
    cout << "Clear screen?" << endl;
	bool clear = true;
	cin >> clear;
    cout << (clear?string(100, '\n'):"");
    bool quit = false;
    while(!quit)//menu asks for which option, which returns the choice into validateInput, which returns if the program should quit
    {
        if(isIBST)
            quit = validateInput<int>(menu(), iBST, clear);
        else
            quit = validateInput<Student>(menu(), sBST, clear);
        //BST->printBST();
    }
    return 0;
}
