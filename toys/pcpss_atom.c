// The main code of PCPSS atom
// Copyright (C) 2019 dumaosen

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
    #include <windows.h>
#elif __unix__
    #include <unistd.h>
#endif

void sleep_func(int a)
{
    #ifdef _WIN32
        Sleep(1000 * a);
    #elif __unix__
        sleep(a);
    #endif
}
    
void clear_func()
{
    #ifdef _WIN32
        system("CLS");
    #elif __unix__
        system("clear");
    #endif
}

// List 3 pss, the same reason
enum pss{stone, scissors, paper};

// Convert numbers to human language
const char* language_converter(enum pss a)
{
    switch(a)
    {
        case stone:
            return "stone     ";
        case scissors:
            return "scissors  ";
        case paper:
            return "paper     ";
        default:
            return "error     ";
    }
}

// Print error file
void print_error()
{
    printf("\a");
    printf(" Wrong command ('h' help)\n");
}

// Print hpboard file
void print_hpboard(int a, int b)
{
    printf("\n    +--------------+\n"
           "    | PC:%-10d|\n"
           "    | MK:%-10d|\n"
           "    +--------------+\n"
           , a, b);
}

// Print player state
void print_state(bool state)
{
    if(state)
        printf("\n      Passive state\n\n");
    else
        printf("\n      Active state\n\n");
}

// Print the pss of each player
void print_pss(int a, int b)
{
    printf("\n    +--------------+\n"
           "    | PC:%s|\n"
           "    | MK:%s|\n"
           "    +--------------+\n"
           , language_converter(a), language_converter(b));
}

// Print the end message
void summary(int a, int b)
{
    if(a < b)
        printf("\n      Mankind win!\n");
    else if(a == b)
        printf("\n      Tie!\n");
    else
        printf("\n      PC win!\n");
}

// Determine if player a wins player b in a round
bool compare(int a, int b)
{
    if((a - b == 1 || a - b == -2))
        return false;
    return true;
}

// Malloc spaces and read command
// NOTE: Free the spaces after using it
char* enter_command(int len)
{
    char* command;
    command = malloc(len);
    printf(" Enter your command: ");
    scanf("%s", command);
    return command;
}

// Calculate the hp of each player
void calc_hp(bool win, int *player, const char* name)
{
    if(win)
    {
        *player += 1;
        printf("\n      %s +1\n", name);
    }
    else
    {
        *player -= 2;
        printf("\n      Ouch! %s -2\n", name);
    }
    if(*player > 99)
        *player = 99;
    if(*player < 0)
        *player = 0;
}

// Main loop
void game()
{
    clear_func();
    int pchand, mkhand, pc = 10, mk = 10;
    bool state = false;
    print_hpboard(pc, mk);
    print_state(state);
    for(;;)
    {
        // Read command
        char* command = enter_command(1);
        switch(*command)
        {
            case '1':
                mkhand = stone;
                break;
            case '2':
                mkhand = scissors;
                break;
            case '3':
                mkhand = paper;
                break;
            case 'q':
                clear_func();
                print_hpboard(pc, mk);
                summary(pc, mk);
                sleep_func(2);
                return;
            case 'h':
                printf(" '1' stone\n"
                       " '2' scissors\n"
                       " '3' paper\n"
                       " 'q' quit\n");
                continue;;
            default:
                print_error();
                continue;
        }
        free(command);
        srand((unsigned)time(NULL));
        pchand = rand() % 3;
        // Print AI command
        printf(" AI command: ");
        printf("%d\n", pchand + 1);
        sleep_func(1);
        print_pss(pchand, mkhand);
        bool win = compare(mkhand, pchand);
        // Change state if the same command
        if(pchand == mkhand)
        {
            state = !state;
            printf("\n      Change state\n");
        }
        // Calculate players' hp
        else if(state)
            calc_hp(win, &mk, "Mankind");
        else
            calc_hp(!win, &pc, "PC");
        sleep_func(2);
        clear_func();
        print_hpboard(pc, mk);
        if(!pc || !mk)
        {
            summary(pc, mk);
            sleep_func(2);
            clear_func();
            return;
        }
        print_state(state);
    }
}

// Start menu
int main()
{
    clear_func();
    game();
    exit(0);
}
