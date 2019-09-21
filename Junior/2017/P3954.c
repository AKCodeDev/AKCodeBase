// The answer to J2018P1
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

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	
	const int ans = a / 5 + b / 10 * 3 + c / 2;
	
	printf("%d", ans);
	return 0;
}
