// The answer to S2016P1
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

#include <stdio.h>

int point;
struct toy
{
	int posit;
	char name[11];
}alltoys[100001];
struct command
{
	int posit, point;
}allcommands[100001];

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	
	for(i = 0; i < n; i ++)
		scanf("%d%s", &alltoys[i].posit, &alltoys[i].name);
	
	for(i = 0; i < m; i ++)
		scanf("%d%d", &allcommands[i].posit, &allcommands[i].point);
	
	for(i = 0; i < m; i ++)
	{
		if(alltoys[point].posit == allcommands[i].posit)
			point = point - allcommands[i].point;
		else	
			point = point + allcommands[i].point;
		if(point < 0)
			point = point + n;
		if(point >= n)
			point = point - n;
	}
	
	printf("%s", alltoys[point].name);
	return 0;
}
