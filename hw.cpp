#include <iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

class myArray{
    public:
    int* arr;
    size_t elNum;
    size_t arSize;
    myArray(){
        elNum=0;
        arSize=2;
        arr=new int[arSize];
    }
    public:
    void printMenu()
    {
        cout<<endl<<endl<<"(p): Print elements"<<endl;
        cout<<"(a): Add element"<<endl;
        cout<<"(d): Delete element"<<endl;
        cout<<"(r): Return size"<<endl;
        cout<<"(e): Exit"<<endl<<endl;
    }

    void printElements()
    {
        for(size_t i=0;i<elNum;i++)
        {
            cout<<arr[i]<<", ";
        }
    }

    void addElement()
    {
        if(elNum >= arSize)
        {
            expandMemory();
        }
        cout<<"Enter element: ";
        cin>>arr[elNum];
        elNum++;
    }
    
    void expandMemory()
    { 
        int* temp = new int[arSize*2];
        arSize*=2;
        for (size_t i = 0; i < elNum; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        cout << "Memory Expanded!" << endl;
    }

    void removeElement()
    {
        int idx, ele; 
        bool isThere=0;
        cout<<"Enter element: ";
        cin>>ele;
        for(size_t i=0;i<elNum;i++)
        {
            if(arr[i]==ele)
            {
                idx=i;
                isThere=1;
            }
        }
        if(!isThere)
        {
            cout<<"Not there";
        }
        else
        {
            for (size_t i=idx;i<arSize-1;i++)
            {
                arr[i]=arr[i+1];
            }
            elNum--;
            if(arSize/elNum==2){
                if(arSize>2)
                {
                    shrinkMemory();
                    arSize/=2;
                }
            }
        }
    }

    void printSizeInfo()
    {
        cout<<"S: "<<arSize<<", "<<"E: "<<elNum;
    }

    void shrinkMemory()
    {
        int* temp = new int[arSize/2];
        for(size_t i=0;i<elNum;i++){
            *(temp+i)=*(arr+i);
        }
        delete[] arr;
        arr=temp;
        cout<<"Memory Shrunk!"<<endl;
    }
};

int main()
{
    myArray *m= new myArray; 
    char choice;
    bool isTrue=1;
    while(isTrue){
        m->printMenu();
        cout<<"Enter option: ";
        cin>>choice;

        switch(choice)
        {
            case 'a':
                m->addElement();
            break;

            case 'p': 
                m->printElements();
            break;

            case 'd':  
                m->removeElement();
            break;

            case 'e': 
                delete [] m->arr;
                delete m;
                isTrue=0;
            break;

            case 'r': 
                m->printSizeInfo();
            break;
        }
    }
    return 0;
}