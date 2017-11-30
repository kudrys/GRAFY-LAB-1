// GRAFYLAB1.cpp : Defines the entry point for the console application.
//

//dane: V(G), E(g) //zbiór wierzcho³ków, zbiór krawêdzi grafu G
//	d[1..n] //tablica odleg³oœci
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
	for (int testCount = 0; testCount < liczbaTestow; testCount++) {

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
		for (int odlCount = 1; odlCount < wierzcholki; odlCount++)
			tabOdleglosci[odlCount] = nieskonczonosc;

		for (int lineCount = 1; lineCount < wierzcholki; lineCount++)
		{
			for (int j = 0; j < wierzcholki; j++)
				for (int i = 0; i < wierzcholki; i++)
				{
					if (tabOdleglosci[j] + tabWierzcholki[j][i] < tabOdleglosci[i])
						tabOdleglosci[i] = tabOdleglosci[j] + tabWierzcholki[j][i];
				}

			//wypisz
			for (int wypiszCount = 0; wypiszCount < wierzcholki; wypiszCount++)
				if (tabOdleglosci[wypiszCount] < nieskonczonosc)
					cout << tabOdleglosci[wypiszCount] << " ";
				else
					cout << 0 << " ";
			//next loop run
			cout << endl;
		}
		cout << endl;
	}

    return 0;
}

//dane: V(G), E(g) //zbiór wierzcho³ków, zbiór krawêdzi grafu G
//	d[1..n] //tablica odleg³oœci
//	d[0] = 0;
//	  foreach(v in V(G) / v0)
//		  d[v] = +inf;
//	  for (i = 1; i< n; i++) // I
//		  foreach((u, v) in E(G)) // II
//		  if (d[u] + waga((u, v)) < d[v])
//			  d[v] = d[u] + waga((u, v));
//