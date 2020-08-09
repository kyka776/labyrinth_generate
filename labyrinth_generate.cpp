#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int random_int(int max)
{
	return rand()%max;
} 
 
class labyrinth
{
private:
    vector<vector<bool> > pole;
 
public:
    labyrinth(int m, int n) 
	{
		cout << "m - " << m << " n - " << n << endl;
		vector<bool> line;	
		for(int i = 0; i < n*2 + 1; i++)
		{	
			line.push_back(0);
		}	
		for(int i = 0; i < m*2 + 1; i++)
		{	
			pole.push_back(line);
		}
		generate(m, n);
    }
    void generate(int m, int n)
    {
    	srand(time(NULL));
    	int x, y, nap, i;
		bool flag = 0;
    	for(int q = 0; q < m*n; q++)
    	{
    		if(flag == 0)
    		{
    			flag = 1;
    			x = random_int(m);
    			x = x*2 + 1;
    			y = random_int(n);
    			y = y*2 + 1;
    			if(pole[x][y] == 1)
    			{
    				flag = 0;
    				q--;
				}
				else
				{
					pole[x][y] = 1;
				}
			}
			else
			{
				nap = random_int(4);
				for(i = 0; i < 4; i++)
				{
					nap = nap + i;
					nap = nap % 4;
					if(nap == 0)	
					{
						x = x + 2;
						if (x < m*2 + 1)
						{
							if(pole[x][y] == 0)
							{
								pole[x][y] = 1;
								pole[x - 1][y] = 1;
								break;
							}
							else if(random_int(2) == 0)
							{
								pole[x - 1][y] = 1;
								flag = 0;
								q--;
								break;
							}
						}
						x = x - 2;
					}
					else if(nap == 1)
					{
						x = x - 2;
						if (x > 0)
						{
							if(pole[x][y] == 0)
							{
								pole[x][y] = 1;
								pole[x + 1][y] = 1;
								break;
							}
							else if(random_int(2) == 0)
							{
								pole[x+1][y] = 1;
								flag = 0;
								q--;
								break;
							}
						}
						x = x + 2;
					}
					else if(nap == 2)
					{
						y = y + 2;
						if (y < n*2 + 1)
						{
							if(pole[x][y] == 0)
							{
								pole[x][y] = 1;
								pole[x][y - 1] = 1;
								break;
							}
							else if(random_int(2) == 0)
							{
								pole[x][y - 1] = 1;
								flag = 0;
								q--;
								break;
							}
						}
						y = y - 2;
					}
					else
					{
						y = y - 2;
						if (y > 0)
						{
							if(pole[x][y] == 0)
							{
								pole[x][y] = 1;
								pole[x][y + 1] = 1;
								break;
							}
							else if(random_int(2) == 0)
							{
								pole[x][y + 1] = 1;
								flag = 0;
								q--;
								break;
							}
						}
						y = y + 2;
					}
				}
				if(i == 4)
				{
					flag = 0;
					q--;
				}
			}
    		
		}
    	
    	
	}
    void print()
    {
    	// system("cls");
    	for(int i = 0; i < pole.size(); i++)
    	{
    		for(int q = 0; q < pole[0].size(); q++)
    		{
    			if (pole[i][q] == 1)
    			{
    				cout << " "; 
				}
				else
				{
					cout << "0";
				}
			}
			cout << endl;
		}
	}
 
};
 
int main() 
{
	int m, n;
	cout << "Enter scale" << endl << "height:";
	cin >> m;
	cout << "length:";
	cin >> n;
	labyrinth lab(m, n);
	lab.print();
}
