#include<bits/stdc++.h>
using namespace std;
#define MX 5

class stackClass{

    int* arr = new int[MX];
    int count = 0;
    int front {0}, rear{0};

    public:

    void enqueue(int val){
        
        if(count == MX){
            cout<<"Queue overflow!\n";
            return;
        }
        //cout<<count<<endl;
        arr[rear % MX] = val;
        rear += 1;
        count += 1;
    }

    void dequeue(){

        if(count == 0){
            cout<<"Queue underflow!\n";
            return;
        }

        front += 1;
        count -= 1;
    }

    void getFront(){
        if(rear%MX == front%MX){
            cout<<"Queue Empty\n";
            return;
        }

        cout<<arr[front%MX]<<endl;
    }

    void getRear(){
        if(rear%MX == front%MX){
            cout<<"Queue Empty\n";
            return;
        }

        cout<<arr[rear%MX]<<endl;
    }

    void getSize(){
        cout<<count<<endl;
    }

    bool isEmpty(){
        if(count == 0)
            return true;
        
        return false;
    }

    void display(){
        if(count == 0){
            cout<<"Empty queue.\n";
            return;
        }

        for(int i = front; i<=rear-1; i++)
            cout<<arr[i%MX]<<endl;
        cout<<endl;
    }

};

int main(){

    stackClass st1;

    st1.enqueue(3);
    st1.enqueue(2); 
    st1.enqueue(1);
    st1.enqueue(8);
    //st1.display();
    st1.enqueue(6);
    st1.display();
    st1.enqueue(7);
    st1.dequeue();
    st1.dequeue();
    st1.getFront();
    st1.getRear();
    st1.display();
    

}