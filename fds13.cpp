/*
        A double-ended queue (deque) is a linear list in which additions
        and deletions may be made at either end. Obtain a data
        representation mapping a deque into a one- dimensional array.
            Write C++ program to simulate deque with functions to add and
            delete elements from either end of the deque.
*/

#include<iostream>
using namespace std;

class Deque
{
    public:
        //data members
        int *arr;
        int front;
        int rear;
        int size;

        //initialize data members
        Deque(int n)
        {
            size = n;
            arr = new int[size];
            rear = front = -1;
        }

        void push_front(int data)
        {
            //chack full
            if(isfull())
            {
                cout << "Queue Overflow" << endl;
                return;
            }
            else if(is_empty())
            {
                front = rear = 0;
                arr[front] = data;
            }
            else if(front == 0 && rear != size - 1)
            {
                front = size - 1;
                arr[front] = data;
            }
            else
            {
                front--;
                arr[front] = data;
            }
            cout << "Element Pushed Successfully." << endl;
        }

        void push_rear(int data)
        {
            //chack full
            if(isfull())
            {
                cout << "Queue Overflow" << endl;
                return;
            }
            else if(is_empty())
            {
                front = rear = 0;
                arr[rear] = data;
            }
            else if(rear == size-1 && front != 0)
            {
                rear = 0;
                arr[rear] = data;
            }
            else
            {
                rear++;
                arr[rear] = data;
            }
            cout << "Element Pushed Successfully." << endl;
        }

        void pop_front()
        {
            //check empty
            if(is_empty())
            {
                cout << "Queue Underflow" << endl;
                return;
            }
            else if(front == rear)
            {
                front = rear = -1;
            }
            else if(front == size - 1)
            {
                front = 0;
            }
            else 
            {
                front++;
            }
            cout << "Element Poped Successfully." << endl;
        }

        void pop_rear()
        {
            //check empty
            if(is_empty())
            {
                cout << "Queue Underflow" << endl;
                return;
            }
            else if(front == rear)
            {
                front = rear = -1;
            }
            else if(rear == 0)
            {
                rear = size - 1;
            }
            else 
            {
                rear--;
            }
            cout << "Element Poped Successfully." << endl;
        }

        bool isfull()
        {
            if((front == 0 && rear == size - 1) || (rear == ((front - 1) % (size - 1))))
                return true;
            else 
                return false;
        }

        bool is_empty()
        {
            if(front == -1)
                return true;
            else
                return false;
        }

        int forward()
        {
            //check empty
            if(is_empty())
                return -1;
            else 
                return arr[front]; 
        }

        int backward()
        {
            //check empty
            if(is_empty())
                return -1;
            else
                return arr[rear];
        }

};

int main()
{
    cout << "****************** DEQUE ******************\n\n";
    cout << "Enter Total number of Entries : ";
    int n;
    cin >> n;
    Deque dq(n);
    int choice;
    int data;
    
    bool ans = true;
    while(ans)
    {
        cout << "\n---------------------- MENU ----------------------";
        cout << "\n1. Push Front";
        cout << "\n2. Push Back";
        cout << "\n3. Pop Front";
        cout << "\n4. Pop Back";
        cout << "\n5. Check Isfull";
        cout << "\n6. Check IsEmpty";
        cout << "\n7. Front element";
        cout << "\n8. Rear Element";
        cout << "\n9. Exit";
        cout << "\n\nEnter your choice : ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter Element : ";
                cin >> data;
                dq.push_front(data);
                break;
            case 2:
                cout << "Enter Element : ";
                cin >> data;
                dq.push_rear(data);
                break;
            case 3:
                dq.pop_front();
                break;
            case 4:
                dq.pop_rear();
                break;
            case 5:
                if(dq.isfull()) cout << "Deque is Full\n";
                else cout << "Deque is not full\n";
                break;
            case 6:
                if(dq.is_empty()) cout << "Deque is empty\n";
                else cout << "Deque is not empty\n";
                break;
            case 7:
                cout << "Front : " << dq.forward() << endl; 
                break;
            case 8:
                cout << "Rear : " << dq.backward() << endl;
                break;
            case 9:
                ans = false;
                break;

            default:
                cout << "Enter valid choice ...!\n";
                break;
        }
    }
    return 0;
}