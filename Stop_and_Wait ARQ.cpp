#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

class data 
{
    public:
        int sn, rn, size;
        vector<int> sv;
        vector<int> rv;

    data() 
    {
        sn = 1; 
        rn = 1; 
        size = 0;
    }

    void sender();
    void receiver(int i);
    void result();
    void waitforevent();
    void getdata();
    void makeframe();
    void sendframe();
};

void data::sender() 
{
    waitforevent();
    getdata();
    makeframe();
    sendframe();
}

void data::waitforevent() 
{
    cout<<"Waiting for event...";
    sleep(1);
    cout<<".";
    sleep(1);
    cout<<".";
    sleep(1);
    cout<<"."<<endl;
}

void data::getdata() 
{
    cout<<"Enter the number of bits you want to send: "<<endl;
    cin>>size;

    cout<<"Enter the bits - "<<endl;
    for(int i=0; i<size; i++) 
    {
        int num;
        cin>>num;
        sv.push_back(num);
    }
}

void data::makeframe() 
{
    cout<<"Making Frames...";
    cout<<".";
    sleep(1);
    cout<<".";
    sleep(1);
    cout<<"."<<endl;
}

void data::sendframe() 
{
    int ack1;
    cout<<"Sending Frames - "<<endl;
    for(int i=0; i<sv.size(); i++) 
    {
        cout<<"Sending "<<sn<<" Frame...";
        sleep(1);
        cout<<".";
        sleep(1);
        cout<<"."<<endl;
        cout<<"Timer Starts...";
        sleep(1);
        cout<<".";
        sleep(1);
        cout<<"."<<endl;
        receiver(sv[i]);
        
        //If ack fails
        if (sn != (rn - 1)) 
        {
            cout << "************** ON SENDER SIDE ***************" << endl;
            cout << "Sender Timed Out " << endl;
            cout << "Acknowlegdement NOT received " << endl;
            cout << "Retrasmitting the " << sn << " Frame again. ";
            cout << ". ";
            sleep(2);
            cout << "." << endl;
            cout << "Timer Starts again. ";
            sleep(2);
            cout << ". ";
            sleep(2);
            cout << "." << endl;
            receiver(sv[i]);
            sn++;
        } 
        
        //If ack is received successfully
        else 
        {
            cout<<"************** ON SENDER SIDE ***************"<<endl;
            cout<<"Acknowledgement Received for "<<rn<<" frame."<<endl;
            sn++;
        }
    }

    cout<<"All frames sent Successfully..."<<endl;
}

void data::receiver(int i) 
{
    cout<<"\n************ON RECEIVER SIDE*****************"<<endl;
    cout<<"Waiting for an event...";
    sleep(2);
    cout<<".";
    sleep(2);
    cout<<"."<<endl;

    // int ack_loss = 0;

    if (sn == rn) 
    {
        cout<<"Received "<<sn<<" Frame"<<endl;
        cout<<"Timer stops"<<endl;
        cout<<"Extracting data...";
        sleep(1);
        cout<<".";
        sleep(1);
        cout<<".";
        sleep(1);
        cout<<"."<<endl;
        sleep(2);

        rv.push_back(i);
        rn++;

        cout<<"Sending Acknowledgement...";
        sleep(2);
        cout<<".";
        sleep(2);
        cout<<"."<<endl;

        //Trying Acknowledgement Loss
        // if(ack_loss == 0)
        // {
        //     rv.pop_back();
        //     rn--;
        //     ack_loss++;
        // }
    }
}

void data::result() 
{
    cout<<"The data sent at sender side is: ";
    for(int i=0; i<sv.size(); i++) 
    {
        cout<<sv[i]<<" ";
    }
    cout<<endl;

    cout<<"The data received at receiver side is: ";
    for(int i=0; i<rv.size(); i++) 
    {
        cout<<rv[i]<<" ";
    }
    cout << endl;
}

int main() 
{
    data d;

    d.sender();
    d.result();

    return 0;
}

