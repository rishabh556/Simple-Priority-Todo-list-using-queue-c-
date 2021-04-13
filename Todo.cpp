#include <iostream>
using namespace std;
class node
{
public:
    string data;
    node* next;
    node(string task)
    {
        data = task;
        next = NULL;
    }
};

class queue
{
    node* front;
    node* back;

public:
    queue()
    {
        front = NULL;
        back = NULL;
    }
    void push(string x)
    {
        node* n = new node(x);
        if (front == NULL)
        {
            back = n;
            front = n;
            return;
        }
        back->next = n;
        back = n;
    }

    void pop()
    {
        if (front == NULL)
        {
            cout << endl;
            cout << "No Task is Remaining!!" << endl;
            return;
        }
        node* todelete = front;
        front = front->next;
        delete todelete;
    }

    string peek()
    {
        if (front == NULL)
        {
            cout << "no task in the list!!" << endl;
            return " ";
        }
        return front->data;
    }

    bool empty()
    {
        if (front == NULL)
        {

            return true;
        }
        return false;
    }

    void display(){
        int i=1;
        if (front == NULL)
        {
            cout << "no task in the list!!" << endl;
        }
        while(front !=NULL ){
            cout<<i<<". ";
            cout<<front->data<<endl;
            front = front->next;
            i++;

        }

    }
};

int main()
{
    queue q;
    string Task;
    while (true)
    {

        int choice;
        cout << endl;
        cout << "****************Select Your Choice Below****************" << endl;
        cout << "Press 1: For adding a task " << endl;
        cout << "Press 2: For deleting the first task " << endl;
        cout << "Press 3: For displaying the current task in the list " << endl;
        cout << "Press 4: For displaying all the task" << endl;
        cout << "Press 5: End" << endl;
        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "Enter your task: ";
            cin.ignore();
            getline(cin, Task);
            q.push(Task);
            cout << "Task inserted successfully" << endl;
            break;
        case 2:
            q.pop();
            cout << "Congrats,your first task completed!!" << endl;
            break;
        case 3:
            cout << "Your current task is:- " << endl;
            cout << q.peek() << endl;
            break;

        case 4:
            cout <<"Your todays todo list is:-"<<endl;
            q.display();

            break;

        case 5:
            cout << "Hey, you just ended the list!!" << endl;
            exit(1);
            break;

        default:
            cout << "Invalid choice!!";
            break;
        }
    }
    return 0;
}