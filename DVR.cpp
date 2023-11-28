#include<bits/stdc++.h>
using namespace std;


void dvr() {

    cout << "Enter number of nodes" << endl;
    int no ;
    cin >> no ;

    vector<vector<int> > edges ;

    cout << " enter links " ;
    int links ; 
    cin >> links ;

    for (int i = 0 ; i < links ; i++) {
        vector<int> temp(3) ;
        vector<int> temp2(3) ;
        cin >> temp[0] ; // u
        cin >> temp[1] ; // v
        cin >> temp[2] ; // wt
        temp2[0] = temp[1]; // v
        temp2[1] = temp[0]; // u
        temp2[2] = temp[2]; // wt
        edges.push_back(temp) ;
        edges.push_back(temp2) ;
    }

    int dist[no + 1][no + 1] ;
    int via[no + 1][no + 1] = {0};

    for (int i = 1 ; i <= no ; i++) {
        for (int j = 1 ; j <= no ; j++) {
            if (i == j) dist[i][j] = 0 ;
            else dist[i][j] = 1e8 ;
        }
    }

    for (int node = 1 ; node <= no ; node++) {
        for (int i = 1 ; i < no ; i++) {
            for (int it = 0 ; it < 2 * links ; it++) {
                int u = edges[it][0] ;
                int v = edges[it][1] ;
                int wt = edges[it][2] ;

                if (dist[node][u] != 1e8 and dist[node][u] + wt < dist[node][v]) {
                    dist[node][v] = dist[node][u] + wt ;
                    via[node][v] = u ;
                }
            }
        }
    }

    for (int i = 1 ; i <= no ; i++) {
        cout << "\nFor router " << i << " :\n" ;
        for (int j = 1 ; j < no + 1 ; j++) {
            cout << "From " << j << " : distance ";
            cout << dist[i][j] << " ";
            cout << "via " << via[i][j] << endl;
        }
        cout << "\n\n" ;
    }
}

int main() {

    dvr() ;
}

/*
input : 
5
6
1 2 5
1 4 3
1 3 2
2 3 4
3 5 4
2 5 3

*/
