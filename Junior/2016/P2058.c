// The answer to P2058 
// Copyright (C) 2019 dumaosen

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include<stdio.h>

int data[300001], country[300001], ht[200002], count;
struct ship
{
	int ti, ki;
}allships[100001];

int main()
{
	int n = 0, i, j, k, m = 0, p = 0;
	scanf("%d", &n);
	
	for (i = 0; i < n; i ++)
	{
		scanf("%d%d", &allships[i].ti, &allships[i].ki);
		ht[i * 2] = m;
		for (j = 0; j < allships[i].ki; j ++)
		{
			scanf("%d", &data[m]);
			country[data[m]] ++;
			if (country[data[m]] == 1)
				count ++;
			m ++;
		}
		
		ht[i * 2 + 1] = m - 1;
		while(allships[i].ti - allships[p].ti >= 86400)
		{
			for (k = ht[p * 2] ; k <= ht[p * 2 + 1]; k ++)
			{
				country[data[k]] --;
				if (country[data[k]] == 0)
					count --;
			}
			p ++;
		}
		printf("%d\n", count);
	}
	return 0;
}
