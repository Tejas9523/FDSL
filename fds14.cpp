/*
        Pizza parlor accepting maximum M orders. Orders are served in
        first come first served
        basis. Order once placed cannot be cancelled. 
        Write C++ program to simulate the system using circular queue using array.
*/

#include<iostream>
using namespace std;

class circular_queue
{
    public:
        //data members
        int *arr;
        int front;
        int rear;   
        int size;

        circular_queue(int n)
        {
            size = n;
            arr = new int[size];
            front = rear = -1;
        }

        void push(int data)
        {
            //check isfull
            if(is_full())
            {
                cout << "Maximum Orders Reached ...!" << endl;
                return;
            }
            else if(is_empty())
            {
                front = rear = 0;
                arr[rear] = data;
            }
            else if(rear == size - 1 && front != 0)
            {
                rear = 0;
                arr[rear] = data;
            }
            else
            {
                rear++;
                arr[rear] = data;
            }
            cout << "Order Placed Successfully." << endl;
        }

        void pop()
        {
            //check empty
            if(is_empty())
            {
                cout << "No Orders Placed to Cancel ...!" << endl;
                return;
            }
            int ans = arr[front];
            if(front == rear)
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
            cout << "Order No. " << ans <<  " Cancelled Successfully." << endl;
        }

        bool is_empty()
        {
            if(front == -1)
                return true;
            else 
                return false;
        }

        bool is_full()
        {
            if((front == 0 && rear == size - 1) || (rear == ((front-1)%(size - 1))))
                return true;
            else 
                return false;

        }

        int forward()
        {
            if(is_empty())
                return -1;
            else
                return arr[front];

        }
};

int main()
{
    cout << "********************* PIZZA PARLOUR *********************\n\n";
    bool ans = true;
    int choice;
    int data;
    int m;
    cout << "Enter Total Number of Orders : ";
    cin >> m;
    circular_queue cq(m);

    while(ans)
    {
        cout << "\n--------------------- MENU ---------------------";
        cout << "\n1. To Place Order";
        cout << "\n2. To Cancel Order";
        cout << "\n3. To Check whether all Orders are full";
        cout << "\n4. To Check whether Order Queue is Empty";
        cout << "\n5. Display Front Order Number";
        cout << "\n6. Exit";

        cout << "\n\nEnter your choice : ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter Order Number : ";
                cin >> data;
                cq.push(data);
                break;
            case 2:
                cq.pop();
                break;
            case 3:
                if(cq.is_full())
                    cout << "Yes , All Orders are full." << endl;
                else 
                    cout << "No , All Orders aren't full." << endl;
                break;
            case 4:
                if(cq.is_empty())
                    cout << "Yes , Order Queue is Empty.";
                else
                    cout << "No , Order Queue is not Empty.";
                break;
            case 5:
                data = cq.forward();
                if(data == -1)
                    cout << "Order Queue is Empty." << endl;
                else 
                    cout << "Front Order Number : " << data;
                break;
            case 6:
                ans = false;
                break;
        
            default:
                cout << "Enter valid choice ...!" << endl;
                break;
        }
    }
    return 0;
}