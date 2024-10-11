/*
  Name: Devkarthik Suresh
  PRN: 23070123045
  Aim: Queue implementation
*/
#include <iostream>
using namespace std;

#define MAX 100

class Queue {
private:
    int arr[MAX];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return (rear + 1) % MAX == front;
    }

    bool isEmpty() {
        return front == -1;
    }

    void insert(int value) {
        if (isFull()) {
            cout << "Queue overflow! Cannot insert " << value << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX;
        }
        arr[rear] = value;
        cout << value << " inserted into queue." << endl;
    }

    void deleteElement() {
        if (isEmpty()) {
            cout << "Queue underflow! Cannot delete." << endl;
            return;
        }
        cout << arr[front] << " deleted from queue." << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i != rear; i = (i + 1) % MAX) {
            cout << arr[i] << " ";
        }
        cout << arr[rear] << endl;
    }
};

int main() {
    Queue queue;
    int choice, value;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                queue.insert(value);
                break;
            case 2:
                queue.deleteElement();
                break;
            case 3:
                queue.display();
                break;
            case 4:
                cout << "Exited out" << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

/*
Menu:
1. Insert
2. Delete
3. Display
4. Exit
Enter your choice: 1
Enter value to insert: 5
5 inserted into queue.
*/
