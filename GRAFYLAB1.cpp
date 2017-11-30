// GRAFYLAB1.cpp : Defines the entry point for the console application.
//

//dane: V(G), E(g) //zbi�r wierzcho�k�w, zbi�r kraw�dzi grafu G
//	d[1..n] //tablica odleg�o�ci
//	d[0] = 0;
//	  foreach(v in V(G) / v0)
//		  d[v] = +inf;
//	  for (i = 1; i< n; i++) // I
//		  foreach((u, v) in E(G)) // II
//		  if (d[u] + waga((u, v)) < d[v])
//			  d[v] = d[u] + waga((u, v));
//

#pragma warning (disable : 4996)
#include <iostream>
#include <vector>
#define nieskonczonosc 100000

using namespace std;

int main()
{
	freopen("ConsoleOutput.txt", "w", stdout);
	int liczbaTestow;
	int wierzcholki;
	int krawedzie;
	int testy;

	int tabWierzcholki[100][100];
	int tabOdleglosci[100];
	tabOdleglosci[0] = 0;
	
	cin >> liczbaTestow;
	for (int i = 0; i < liczbaTestow; i++) {

		cin >> wierzcholki;
		for (int j = 0; j < wierzcholki; j++)
		{
			for (int i = 0; i < wierzcholki; i++)
			{
				int value;
				cin >> value;
				if (value != 0)
					tabWierzcholki[j][i] = value;
				else
					tabWierzcholki[j][i] = nieskonczonosc;
			}
		}

		//fill with infinity
		for (int i = 1; i < wierzcholki; i++)
			tabOdleglosci[i] = nieskonczonosc;

		for (int i = 1; i < wierzcholki; i++)
		{
			for (int j = 0; j < wierzcholki; j++)
				for (int i = 0; i < wierzcholki; i++)
				{
					if (tabOdleglosci[j] + tabWierzcholki[j][i] < tabOdleglosci[i])
						tabOdleglosci[i] = tabOdleglosci[j] + tabWierzcholki[j][i];
				}

			//wypisz
			for (int i = 0; i < wierzcholki; i++)
				if (tabOdleglosci[i] < nieskonczonosc)
					cout << tabOdleglosci[i] << " ";
				else
					cout << 0 << " ";
			//next loop run
			cout << endl;
		}
		cout << endl;
	}

    return 0;
}

//dane: V(G), E(g) //zbi�r wierzcho�k�w, zbi�r kraw�dzi grafu G
//	d[1..n] //tablica odleg�o�ci
//	d[0] = 0;
//	  foreach(v in V(G) / v0)
//		  d[v] = +inf;
//	  for (i = 1; i< n; i++) // I
//		  foreach((u, v) in E(G)) // II
//		  if (d[u] + waga((u, v)) < d[v])
//			  d[v] = d[u] + waga((u, v));
//