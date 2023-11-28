#include <iostream>
using namespace std;

int main()
{
	int count, src_router, i, j, k, w, v, min;
	int cost_matrix[100][100], dist[100], last[100];
	int flag[100];
	char user_input;
	cout << "\nEnter the number of routers: ";
	cin >> count;
	cout << "\nEnter the cost matrix values:\n";
	for (i = 0; i < count; i++)
	{
		for (j = i; j < count; j++)
		{
			if (i == j)
			{
				cost_matrix[i][j] = 0;
			}
			else
			{
				cout << i << "->" << j << ": ";
				cin >> cost_matrix[i][j];
				cost_matrix[j][i] = cost_matrix[i][j];
				if (cost_matrix[i][j] < 0)
					cost_matrix[i][j] = 1000;
			}
		}
	}
	cout << "\nEnter the source router: ";
	cin >> src_router;
	for (v = 0; v < count; v++)
	{
		flag[v] = 0;
		last[v] = src_router;
		// cout<<last[v];
		dist[v] = cost_matrix[src_router][v];
		// cout<<dist[v];
	}
	flag[src_router] = 1;

	for (i = 0; i < count; i++)
	{
		min = 1000;
		for (w = 0; w < count; w++)
		{
			if (!flag[w] && dist[w] < min)
			{
				v = w;
				min = dist[w];
				cout<<"min"<<endl;
				cout<<min<<endl;
			}
		}
		flag[v] = 1;
		for (w = 0; w < count; w++)
		{
			if (!flag[w] && (min + cost_matrix[v][w] < dist[w]))
			{
				dist[w] = min + cost_matrix[v][w];
				cout<<"cost"<<endl;
				cout<<dist[w]<<endl;
				last[w] = v;
			}
		}
	}

	for (i = 0; i < count; i++)
	{
		cout << "\n"
			 << src_router << "=>" << i << ": Path taken: " << i;
		w = i;
		while (w != src_router)
		{
			cout << "<--" << last[w];
			w = last[w];
		}
		cout << "\nShortest path cost: " << dist[i];
	}

	return 0;
}
