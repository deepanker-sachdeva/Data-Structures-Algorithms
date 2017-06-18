/*
Implementation of Graphs: 

Adjacency Matrix
*/

///	Author: Deepanker Sachdeva

//#include "stdafx.h"
#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<limits>
#include<stack>
using namespace std;
int pos_topo = -1;
int max_topo = 49;
struct stack_topo
{
	int S[50];
	stack_topo()
	{
		for (int i = 0; i < 50; i++)
		{
			S[i] = -1;
		}
	}
	void push(int item)
	{
		if (pos_topo < max_topo)
		{
			pos_topo++;
			S[pos_topo] = item;
			return;
		}
	}
	int pop()
	{
		if (pos_topo > -1)
		{
			int item = S[pos_topo];
			pos_topo--;
			return item;
		}
	}
}stt;
class topo
{
public:
	int a[50][50] = { 0 };
	int visit[50] = { 0 };
	int time = 0;
	int d[50] = { 0 }, f[50] = { 0 }, p[50] = { -1 };//parent
	int n, edges,j,k;
	void inputother()
	{
		cout << "Input no. of nodes, edges, then the 2 edges' index";//for the dijkstra
		cin >> n;
		cin >> edges;
		//for bfs and dfs
		for (int i = 0; i < edges; i++)
		{
		cin >> j >> k;
		a[j-1][k-1] =  1;
		}
	}
	void dfs()
	{
		for (int i = 0; i < n; i++)
		{
			visit[i] = 0;
			p[i] = -1;
		}
		for (int i = 0; i < n; i++)
		{
			if (visit[i] == 0)
				dfs_vis(i);
		}
	}
	void dfs_vis(int i)
	{
		visit[i] = 1;
		time = time + 1;
		d[i] = time;
		for (int j = 0; j < n; j++)
		{
			if (visit[j] == 0 && a[i][j] == 1)
			{
				p[j] = i;
				dfs_vis(j);
			}
		}
		f[i] = time = time + 1;
		stt.push(i);
	}
	void topological()
	{
		inputother();
		dfs();
		cout << "Topo: ";
		while (pos_topo != -1)
		{
			int y = stt.pop();
			cout << y+1 << "--"<<f[y]<<"\t\t";
		}
	}
}topo;
int maxi = 49;
int pos = -1;
struct mst_key
{
	int key;
	int i;
}X[50];
mst_key NUL = { -1,-1 };
struct mst_stak
{
public:
	mst_key *D[50];
	void push(mst_key *B)
	{
		if (pos < maxi)
		{
			pos++;
			D[pos] = B;
		}
	}
	mst_key smallest()
	{
		int small = X[0].key;
		mst_key smallX = X[0];
		int smallI = 0;
		while (smallX.i == -1)
		{
			smallI++;
			if (smallI > pos)
				return NUL;
			smallX = X[smallI];
			small = X[smallI].key;
		}
		for (int i = 0; i < pos; i++)
		{
			if (X[i].key < small&&X[i].i != -1)
			{
				small = X[i].key;
				smallI = i;
			}
		}
		mst_key dum = X[smallI];
		X[smallI].i = -1;
		return dum;
	}

}mst_st;
int character = 1;
struct disset
{
	char name;
	int a[50];
	int pos=0;
}set[50];
int WPos=0;
struct wts
{
	int wt;
	int i, j;
}W[50];
int dist[50];

struct dis
{
	int dist;
	int i;
};
dis A[50];
dis Z = {-1,-1};

struct stak
{
public:
	dis *D[50];
	void push(dis *B)
	{
		if (pos < maxi)
		{
			pos++;
			D[pos] = B;
			
		}
	}
	dis *pop()
	{
		if (pos > 0)
		{
			dis *B = D[pos];
			pos--;
			return B;
		}
	}
	dis smallest()
	{
		int small = A[0].dist;
		dis smallA = A[0];
		int smallI = 0;
		while (smallA.i == -1)
		{
			smallI++;
			if (smallI > pos)
				return Z;
			smallA = A[smallI];
			small = A[smallI].dist;
		}
		for (int i = 0; i < pos; i++)
		{
			if (A[i].dist < small&&A[i].i!=-1)
			{
				small = A[i].dist;
				smallI = i;
			}
		}
		dis dum = A[smallI];
		A[smallI].i = -1;
		return dum;
	}
}st;
class compare
{
public:

	bool operator()(dis& t1, dis& t2)
	{
		if (t1.dist>t2.dist)
			return true;
		return false;
	}
};

class circularQueue
{
public:
	int q[20], n=20, f, r;																			//a is the queue array, f and r are index ptrs, n is total size of the queue
	void display()
	{
		cout << "Showing the Queue & F,R\n";
		for (int i = 0; i < n; i++)
			cout << q[i] << "\t";
		cout << "F=" << f << " & R=" << r << endl;
	}
	void qinsert(int item)																		//insertion function
	{
		if ((r == n&&f == 1) || (f == r + 1))
		{
			cout << "Overflow\nQueue is already full\n";
			return;
		}
		if (f == 0 || r == 0)
		{
			f = 1;
			r = 1;
		}
		else if (r == n)
		{
			r = 1;
		}
		else
			r = r + 1;
		//rather than else if else , these at the last 
		//r=(r+1)%n;
		q[r - 1] = item;
	}

	int qout()													//it pops the item out
	{
		int item;
		if (f == 0)
		{
			cout << "Queue is already empty\n";
			return 100000;
		}
		else
		{
			item = q[f - 1];
			if (f == r)
			{
				f = 0;
				r = 0;
			}
			else
			{
				f = f + 1;
				if (f > n)
					f = 1;
			}
			//f=(f+1)%n;    in place of above else
		}
		return item;
	}
}q;
class Graph_Matrix//:public circularQueue
{
public:
	queue<int> Q;
	//for other input method;   these should be commented
/*
	int **a = 0, n, vis[10][10], done[50] = {0};
	void input()
	{
		cout << "Enter the no. of nodes!\n";
		cin >> n;
		a = new int *[n];
		for (int i = 0; i < n; i++)
			a[i] = new int[n];
			
		cout << "Now enter the adjacency matrix!\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> a[i][j];
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				vis[i][j] = 0;
	}
	void connected_edges()
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				vis[i][j] = 0;
		cout << "Connected Nodes are: \n";
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (a[i][j] != 0&&vis[i][j]==0)
					cout << i+1 << " " << j+1 << "\n";
				vis[i][j] =vis[j][i]= 1;
			}
	}
	*/
	int a[50][50];
	int n, edges, j, k,temp;
	
	void inputother()
	{
		cout << "Input no. of nodes, edges, then the 2 edges' index and their weights";//for the dijkstra
		cin >> n;
		cin >> edges;
		//for bfs and dfs
		for (int i = 0; i < edges; i++)
		{
			cin >> j >> k;
			a[j-1][k-1] = a[k-1][j-1] = 1;
		}
		/*
		//for dijkstra
		for (int i = 0; i < edges; i++)
		{
			cin >> j >> k>>temp;
			a[j - 1][k - 1] = a[k - 1][j - 1] = temp;
		}*/
	}
	int visit[50] = { 0 };
	void bfs(int s)
	{
		cout << "Nodes approachable from " << s+1 << " are:\n";
		
		for (int i = 0; i < n; i++)
		{
			visit[i] = 0;//for colors
		}
		visit[s] = 1;
		q.qinsert(s);
		//Q.push(s);
		while (q.f != 0)
		//while(!Q.empty())
		{
			int u = q.qout();
			//int u = Q.front();
			//Q.pop();
			cout << u + 1<<"\t";
			for (int j = 0; j < n; j++)
			{
				if(a[u][j]==1&& visit[j] == 0)
				{
					visit[j] = 1;
					q.qinsert(j);
					//Q.push(j);
				}
				/*example run
				5
				6
				1 2
				2 3
				3 5
				1 4
				4 5
				2 5
				*/
			}
		}
	}
	void bfs_shortestPath_bet_2vertices(int s)
	{
		cout << "Enter the other vertex\n";
		
		for (int i = 0; i < n; i++)
		{
			visit[i] = 0;//for colors
			d[i] = imax;
			p[i] = -1;
		}
		visit[s] = 1;
		d[s] = 0;
		p[s] = -1;
		q.qinsert(s);
		while (q.f != 0)
		{
			int u = q.qout();
			cout << u + 1 << "\t";
			for (int j = 0; j < n; j++)
			{
				if (a[u][j] == 1 && visit[j] == 0)
				{
					visit[j] = 1;
					d[j] = d[u] + 1;
					p[j] = u;
					q.qinsert(j);
				}
				/*example run
				5
				6
				1 2
				2 3
				3 5
				1 4
				4 5
				2 5
				*/
			}
		}
	}
	int time = 0;
	int d[50] = { 0 }, f[50] = { 0 }, p[50] = {-1};//parent
	void dfs()
	{
		cout << "\nDfs: ";
		for (int i = 0; i < n; i++)
		{
			visit[i] = 0;
			p[i] = -1;
		}
		for (int i = 0; i < n; i++)
		{
			if (visit[i] == 0)
				dfs_vis(i);
		}
	}
	void dfs_vis(int i)
	{
		cout << i + 1 << "\t";
		visit[i] = 1;
		time = time + 1;
		d[i] = time;
		for (int j = 0; j < n; j++)
		{
			if (visit[j] == 0&& a[i][j] == 1)
			{
				p[j] = i;
				dfs_vis(j);
			}
		}
		f[i] = time = time + 1;

	}
	//priority_queue<int, std::vector<int>, greater<int> > PQ;
	priority_queue<int, std::vector<int>, greater<int>> PQ;
	int imax=numeric_limits<int>::max();
	int b[50][50];
	stack<int> stk;
	//dijkstra using PQ not working properly due to insertion of dist in PQ bu t after it is relaxed, PQ cant change its value
	/*
	void dijkstra()
	{
		int s;
		cout << "From which node to find the shortest path!\n";
		cin >> s;
		init_sngl_src(s);
		init_other_matrix(b);
		for (int i = 0; i < n; i++)
			PQ.push(dist[i]);
		
		while (!PQ.empty())
		{

			int dista = PQ.top();
			cout << "distance:" << dista << endl;
			int u;
			PQ.pop();
			for (int i = 0; i < n; i++)
				if (dist[i] == dista)
					u = i;
			for (int v = 0; v < n; v++)
				if (a[u][v]>0)
					relax(u, v);
		}
		show_paths();
	}
	*/
	void dijkstra()
	{
		int s;
		cout << "From which node to find the shortest path!\n";
		cin >> s;
		init_sngl_src(s);
		init_other_matrix(b);
		for (int i = 0; i < n; i++)
			st.push(&A[i]);

		while (1)
		{
			dis DistI = st.smallest();
			if (DistI.i == -1)
				break;
			cout << "distance:" << DistI.dist << endl;
			int u;
			u = DistI.i;
			for (int v = 0; v < n; v++)
				if (a[u][v]>0)
					relax(u, v);
		}

		//show_paths();

		for (int i = 0; i < n; i++)
		{
			if (p[i] != -1)
			{
				cout << p[i] + 1 << "\t" << i+1 <<"\n";
			}
		}
	}
	void init_other_matrix(int b[][50])
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				b[i][j] = 0;
	}
	void init_sngl_src(int s)
	{
		for (int i = 0; i < n; i++)
		{
			A[i].dist = imax;
			A[i].i = i;
			p[i] = -1;
		}
		A[s-1].dist = 0;
	}
	void relax(int u, int v)
	{
		if (A[v].dist > A[u].dist + a[u][v])
		{
			A[v].dist = A[u].dist + a[u][v];
			p[v] = u;
		}
	}
	/*
	void show_paths()
	{
		for (int i = 0; i < n; i++)
		{
			if (p[i] != -1)
			{
				stk.push(i);
				call(i);
			}
		}
	}
	void call(int i)
	{
		if (p[i] != -1)
		{
			stk.push(p[i]);
			call(p[i]);
		}
		if (stk.empty())
			return;
		cout << i + 1 << "\t";
		while (!stk.empty())
		{
			cout << stk.top() << "\t";
			stk.pop();
		}
		cout << "\n";
	}*/
	void kruskal()
	{
		int otherA[50][50] = {0};
		for (int i = 0; i < n; i++)
		{
			set[i].name = character;
			character++;
			set[i].a[set[i].pos] = i;
			set[i].pos++;
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= i; j++)//for no j,i when i,j already there
			{
				if (a[i][j] != 0)
				{
					W[WPos].wt = a[i][j];
					W[WPos].i = i;
					W[WPos].j = j;
					WPos++;
				}
			}
		insertionSort();
		for (int i = 0; i < WPos; i++)
		{
			int u = W[i].i, v = W[i].j;
			int h = find_set(u), j = find_set(v);
			if ( set[h].name!=set[j].name )
			{
				otherA[u][v] =otherA[v][u] =W[i].wt;
				unionSet(h, j);
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < i; j++)
				if (otherA[i][j] != 0)
					cout << j + 1 << "----" << otherA[i][j] << "----" << i + 1 << endl;
	}     
	/*Test run as given example in slides
9
14
1 2 4
1 8 8
2 8 11
2 3 8
3 4 7
3 6 4
3 9 2
4 5 9
4 6 14
5 6 10
6 7 2
7 8 1
7 9 6
8 9 7
	*/
	int find_set(int index)//returns the set[] index
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < set[i].pos; j++)
				if (set[i].a[j] == index)
					return i;
		}
	}
	void unionSet(int h,int j)
	{
		int big, small;
		if (set[h].pos > set[j].pos)
		{
			big = h;
			small = j;
		}
		else
		{
			big = j;
			small = h;
		}
		for (int i = 0; i < set[small].pos; i++)
		{
			set[big].a[set[big].pos] = set[small].a[i];
			set[big].pos++;
		}
		set[small].pos = -1;
	}
	void insertionSort()									//function to insertion sort
	{
		int temp, j, i;
		wts Wtemp;
		for (j = 1; j < edges; j++)
		{
			Wtemp = W[j];
			temp = W[j].wt;
			i = j - 1;
			for (; W[i].wt > temp&&i >= 0; i--)
				W[i + 1] = W[i];						//entering and displacing other elements
			W[i + 1] = Wtemp;
		}
	}
	int inMST_Stak[50] = { 0 };
	void mst_prim()
	{
		int s;
		cout << "From which node to find the MST!\n";
		cin >> s;
		init_sngl_src_mst(s);
		for (int i = 0; i < n; i++)
		{
			mst_st.push(&X[i]);
			inMST_Stak[i] = 1;
		}

		while (1)
		{
			mst_key DistI = mst_st.smallest();
			if (DistI.i == -1)
				break;
			cout << "distance:" << DistI.key << endl;
			int u;
			u = DistI.i;
			inMST_Stak[u] = -1;
			for (int v = 0; v < n; v++)
				if (a[u][v]>0 && inMST_Stak[v] == 1 && a[u][v] < X[v].key)
				{
					p[v] = u;
					X[v].key = a[u][v];
				}
		}

		for (int i = 0; i < n; i++)
		{
			if (p[i] != -1)
			{
				cout << p[i] + 1 << "\t" << i + 1 << "\n";
			}
		}
	}
	void init_sngl_src_mst(int s)
	{
		for (int i = 0; i < n; i++)
		{
			X[i].key = imax;
			X[i].i = i;
			p[i] = -1;
		}
		X[s - 1].key = 0;
	}
	void warshall()
	{
		cout << "Input for warshall\t";
		cout << "Enter the no. of nodes and then start entering the matrix\n";
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				cin >> a[i][j];
				//if (a[i][j] == 100)
					//a[i][j] = imax;//dont use imax as imax+1=imin then min of every will be imin
			}
		int D[10][10][10] = {0};
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				D[0][i][j] = a[i][j];
		for (int k = 1; k <= n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					D[k][i][j] = min(D[k - 1][i][j], D[k - 1][i][k] + D[k - 1][k][j]);
		for (int k = 0; k < n; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
					cout << D[k][i][j] << "\t ";
				cout << endl;
			}
			cout << endl << endl << endl << "\n";
		}
	}
	int min(int i, int j)
	{
		if (i < j)
			return i;
		return j;
	}
}g;

int main()
{
	g.inputother();
	//g.connected_edges();
	cout << "For bfs, enter the source node!\n";
	int s;
	cin >> s;
	g.bfs(s-1);
	//g.dfs();
	//g.dijkstra();
	//g.kruskal();
	//g.mst_prim();
	//g.warshall();
	//topo.topological();
	return 0;
}

/*
0 1 0 1 0
1 0 0 0 1
0 0 0 1 0
1 0 1 0 0
0 1 0 0 0
*/