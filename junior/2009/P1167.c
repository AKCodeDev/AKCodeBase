// The answer to J2009P1
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

#include <stdbool.h>
#include <stdio.h>

bool first = true;

void out_neutral(int a, int b)
{
    if(a < 0)
        a = -a;
    
    if(first)
        first = false;
    
    if(b == 0)
        printf("%d", a);
    else if(b == 1)
        printf("%dx", a);
    else
        printf("%dx^%d", a, b);
}

void out_positive(int a, int b)
{
    if(!first)
        printf("+");
    
    out_neutral(a, b); 
}

void out_negative(int a, int b)
{
    printf("-");
    out_neutral(a, b); 
}

void out_nofactor_neutral(int b)
{
    if(first)
        first = false;
    
    if(b == 0)
        printf("1");
    else if(b == 1)
        printf("x");
    else
        printf("x^%d", b);
}

void out_nofactor_positive(int b)
{
    if(!first)
        printf("+");
    
    out_nofactor_neutral(b);
}

void out_nofactor_negative(int b)
{
    printf("-");
    out_nofactor_neutral(b);
}

void out(int a, int b)
{
    if(a == 0)
        return;
    
    if(a == 1)
        out_nofactor_positive(b);
    else if(a == -1)
        out_nofactor_negative(b);
    else if(a > 0)
        out_positive(a, b);
    else if(a < 0)
        out_negative(a, b);
}

int main()
{
    int n, a, i;
    scanf("%d", &n);
    
    for(i = n; i >= 0; i --)
    {
        scanf("%d", &a);
        out(a, i);
    }
    
    return 0;
}
