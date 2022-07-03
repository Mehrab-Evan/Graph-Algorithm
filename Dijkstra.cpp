/*================================================
    Bismillahir Rahmaneer Rahim
    Nahmaduhu Wa Nusalli Ala Rasoolihii Kareem Amma 'Baad
    Astagfirullahi Rabbi Minkulli Zambiu Wa Atub hi ilayhi
    La haula wala ku ata illa billahi 'Alium 'Azim
    Rabbi zidni  'Ilmah
==================================================*/

#include<bits/stdc++.h>
#define ll long long
#define MX 10000000
using namespace std;

class node
{
	public :
		ll value, cost;
};

vector<node> Graph[MX];
bool visited[100];

ll distan[100];

bool comp(node A, node B)
{
    if(A.cost > B.cost) return true;
    else return false;
}

class comparator
{
    public :
        bool operator() (node &X, node &Y)
        {
            //will make the PQ as Minimum
            //at the front
            if(X.cost > Y.cost) return true;
            else return false;
        }
};
void dijkstra(ll source)
{
    //priority_queue<type, container, comparator(which order)> Name;
    priority_queue<node, vector<node>, comparator> PQ;
    PQ.push({source, 0}); //source and it's distance is 0

    while(!PQ.empty())
    {
        node Current = PQ.top();
        PQ.pop();

        int Current_val = Current.value;
        int Current_cost = Current.cost;

        if(visited[Current_val] == 1) continue; //visited node e kaaj nai

        distan[Current_val] = Current_cost; //Node wise min cost
        visited[Current_val] = 1; //visited hoi geche

        for(int i=0; i<Graph[Current_val].size(); i++)
        {
            ll Next_value = Graph[Current_val][i].value;
            ll Next_cost = Graph[Current_val][i].cost;

            if(visited[Next_value] == 0) {
                PQ.push({Next_value, (Current_cost + Next_cost)});
            }
        }

    }
}
int main()
{
    ll node, edge;
    cin >> node >> edge;

    for(int i=1; i<=edge; i++) {
    	ll u, v, w;
        cin >> u >> v >> w;
    	Graph[u].push_back({v, w});
    }

    cout << "Enter the Source : " << endl;
    ll source;
    cin >> source;
    dijkstra(source);

    for(int i=1; i<=node; i++) {
        cout << "Node : " << i << " Minimum Cost : " << distan[i] << endl;
    }
    return 0;

}

/*Inputs :
5 6
1 2
1 3
1 4
2 3
4 5*/
