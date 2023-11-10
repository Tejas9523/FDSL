/*
        Queues are frequently used in computer programming, and a
    typical example is the creation of a job queue by an operating
    system. If the operating system does not use priorities, then the
    jobs are processed in the order they enter the system. Write C++
    program for simulating job queue. Write functions to add job and
    delete job from queue
*/

#include<iostream>
using namespace std;

#define MAX 100

class job
{
    public:
        int priority;
        int job_id;
        friend class Queue;
        job()
        {
            priority = 0;
            job_id = 0;
        }

        void get_data()
        {
            cout << "Enter Job I'd : ";
            cin >> job_id;
            cout << "Enter priority : ";
            cin >> priority;
            cout << endl;
        }
};

class Queue
{
    public:
        int size;
        int front;
        int rear;
        job queue[MAX];

        Queue(int n)
        {
            size = n;
            front = -1;
            rear = -1;
        }

        void insert()
        {
            if(isfull())
            {
                cout << "Queue Overflow" << endl;
                return;
            }
            job temp;
            temp.get_data();
            if(rear == -1)
            {
                front = 0;
                queue[++rear] = temp;
            }
            else
            {
                int iter = rear;
                while(iter >= front && queue[iter].priority > temp.priority)
                {
                    queue[iter+1] = queue[iter];
                    iter--;
                }
                queue[++iter] = temp;
                rear++;
            }
        }

        void pop()
        {
            if(isempty())
            {
                cout << "Queue Underflow" << endl;
                return;
            }

            if(front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
                front++;
        }

        bool isfull()
        {
            if(front == 0 && rear == size -1)
                return 1;
            return 0;
        }

        bool isempty()
        {
            if(front == -1)
                return 1;
            return 0;
        }

        void frontt()
        {
            if(isempty())
            {
                cout << "Queue Underflow" << endl;
                return;
            }

            cout << "Job I'd : " << queue[front].job_id << endl;
            cout << "Priority : " << queue[front].priority << endl;
        }
};


int main()
{
    cout << "\n\n***************** JOB QUEUE *****************\n\n";
    int n;
    cout << "Enter total number of jobs : ";
    cin >> n;
    Queue q(n);
    bool ans = true;
    int choice;
    while(ans)
    {
        cout << "\n-------------------- MENU --------------------";
        cout << "\n1. Insert Job";
        cout << "\n2. Delete Job";
        cout << "\n3. Display highest priroity job";
        cout << "\n4. Exit";
        
        cout << "\n\nEnter your choice : ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                q.insert();
                break;
            case 2:
                q.pop();
                cout << "\nJob Deleted Successfully";
                break;
            case 3:
                q.frontt();
                break;
            case 4:
                ans = false;
                break;
            default:
                cout << "Enter valid choice ...!\n";
                break;
        }
    }

    return 0;
}