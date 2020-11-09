// Жертва dll-инъекции
#include <iostream>
#include <windows.h>
#include <cstring>

#define STRING_SIZE 1024

int main()
{
    const char* trumpId = "Trump";
    const char* bidenId = "Biden";
    int number_of_voters = 0;;
    int bidenVotes = 0;
    int trumpVotes = 0;
    char* trump = (char*)calloc(STRING_SIZE, sizeof(char));
    char* biden = (char*)calloc(STRING_SIZE, sizeof(char));
    strcpy_s(trump, STRING_SIZE, trumpId);
    strcpy_s(biden, STRING_SIZE, bidenId);
   
    std::wcout << "Welcome to the US presidential election!" << std::endl;

    while (true)
    {
        int choice = 0;
        bool isVoted = false;
        std::wcout << "It's time to vote:\n";
        std::wcout << "1." << trumpId << std::endl;
        std::wcout << "2." << bidenId << std::endl;
        std::wcout << "0." << "Finish election" << std::endl;
        std::wcin >> choice;
        if (choice == 1)
        {
            trumpVotes++;
            isVoted = true;
        }
        if (choice == 2)
        {
            bidenVotes++;
            isVoted = true;
        }
        if (choice == 0)
        {
            std::wcout << "It's to announce results\n";
            break;
        }
        if (isVoted)
            std::wcout << "Thanks for voting!\n";
    }

    std::wcout << "And the winner is...";
    Sleep(2000);
    if (bidenVotes > trumpVotes)
        std::wcout << biden;
    else if (bidenVotes < trumpVotes)
        std::wcout << trump;
    else
        std::wcout << "Noone! It's draw";
    std::wcout << "!!!" << std::endl;
    Sleep(500);
    std::wcout << trumpId << " - " << trumpVotes << " votes\n";
    Sleep(500);
    std::wcout << bidenId << " - " << bidenVotes << " votes\n";

    int i;
    std::wcin >> i;
}
