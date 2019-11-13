#include <iostream>
#define N 5

using namespace std;

class graph
{
	int g[N][N];
	int i,j;

public:
	graph()
	{
		for (i==0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				g[i][j]=0;
			}
		}
	}
	graph (int edge)
	{
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			{
				g[i][j]=0;
			}
		}
	
	i=0;

	while (i<edge)

	{
		addedge();
		i++;
	}
	}
	void show();
	void addedge();
};
void graph:: show()
{
	for(i=0;i<N;i++)
	{
		cout<<"Edge from v"<<i+1<<" to";
		for(j=0;j<N;j++)
		{
			cout<<"\t v"<<j+1;
			cout<<"="<<g[i][j];
		}
		cout<<endl;
	}
}

void graph::addedge()
{
	int v1, v2;
	cout<<"Enter two vertex you want to connect: \n";
	cin>>v1;
	cin>>v2;
	g[v1-1][v2-1]=1;
	g[v2-1][v1-1]=1;
}

int main()
{
	int e;
	cout<<"Enter number of edges you want to graph of 3 vertices: \n";
	cin>>e;
	graph gh(e);
	gh.show();
	return 0;
}

