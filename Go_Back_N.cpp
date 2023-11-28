
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main()
{
    int nf, window_size;
    int no_tr=0;

    cout<<"Enter the number of frames: ";
    cin>>nf;

    cout<<"Enter the Window Size: ";
    cin>>window_size;
    
    int i=1;
    while(i<=nf)
    {
        int x=0;
        for(int j=i; j<i+window_size && j<=nf; j++)
        {
            cout<<"Sent Frame "<<j<<endl;
            no_tr++;
        }

        for(int j=i; j<i+window_size && j<=nf; j++)
        {
            int flag = rand()%2;
            if(!flag)
                {
                    cout<<"Acknowledgment for Frame "<<j<<endl;
                    x++;
                }
            else
                {   cout<<"Frame "<<j<<" Not Received"<<endl;
                    cout<<"Retransmitting Window"<<endl;
                    break;
                }
        }
        cout<<endl;
        i+=x;
    }

    cout<<"Total number of transmissions: "<<no_tr<<endl;
    return 0;
}

