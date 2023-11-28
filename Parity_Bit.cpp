#include <bits/stdc++.h>
using namespace std;

class ParityCheck {
    public:
        vector<int> msg;
        int size, count;
        
    void getData();
    int parityChecker(vector<int> msg, int n);
    void displayData(vector<int> msg, int n, int pb);
};

void ParityCheck::getData()
{
    int m;
    
    cout<<"Enter the size of your message: ";
    cin>>size;
    
    cout<<"\nEnter your message (0 or 1 only) - "<<endl;
    for(int i=0; i<size; i++)
    {
        cin>>m;
        
        if(m==0 || m==1)
            msg.push_back(m);
            
        else
        {
            cout<<"INVLAID CHARACTER!";
            break;
        }
    }
}

int ParityCheck::parityChecker(vector<int> msg, int n)
{
    count = 0;
    
    for(int i=0; i<n; i++)
    {
        if(msg[i] == 1)
            count++;
    }
    
    return count;
}

void ParityCheck::displayData(vector<int> msg, int n, int pb)
{
    cout<<"\nFinal Message - "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<msg[i]<<" ";
    }
    cout<<" | ";
    cout<<pb;
}

int main()
{
    ParityCheck p;
    int choice;
    int result;
    int pb;
    
    p.getData();
    result = p.parityChecker(p.msg, p.size);
    
    cout<<endl;
    cout<<"\n--------------------------------";
    cout<<"\n           PARITY CHECKER  	  ";
    cout<<"\n--------------------------------"<<endl;
    cout<<"1. Even Parity\n2. Odd Parity\n\nEnter the choice - ";
    cin>>choice;
    
    switch(choice)
    {
		//Even Parity
        case 1:
            if(result%2 == 0)
            {
                pb = 0;
                cout<<"No Error"<<endl;
            }
                
            else
            {
                pb = 1;
                cout<<"Error"<<endl;
            }

            p.displayData(p.msg, p.size, pb);
        break;
        
		//Odd Parity
        case 2:
            if(result%2 != 0)
            {
                pb = 0;
                cout<<"No Error"<<endl;
            }
                
            else
            {
                pb = 1;
                cout<<"Error"<<endl;
            }

            p.displayData(p.msg, p.size, pb);
        break;
        
        default:
            cout<<"INVALID CHOICE!"<<endl;
    }
    
    return 0;
}

/*

OUTPUT:-

Enter the size of your message: 4

Enter your message (0 or 1 only) - 
1 0 1 0


--------------------------------
           PARITY CHECKER
--------------------------------
1. Even Parity
2. Odd Parity

Enter the choice - 1
No Error

Final Message -
1 0 1 0  | 0

*/
