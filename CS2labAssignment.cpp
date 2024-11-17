// CS2labAssignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

class patient
{
private:
    string patientId;
    char gender;
    int time;
    char type;
public:
    patient(string p, char g, int t, char ty) 
    {
        patientId = p;
        gender = g;
        time = t;
        type = ty;
    }
    void isIDvalidated(string s) // validates the id length is 14 and the numbers are from 0 to 9
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i]<'0' || s[i]>'9')
            {
                cout << "Error: ID is invalid" << endl;
            }
        }
        if (s.length() != 14)
        {
            cout << "Error: ID is not validated. Another Id will be generated" << endl;

        }

    }
    string getPatientId()
    {
        return patientId;
    }
    char getGender()
    {
        return gender;
    }
    char getType()
    {
        return type;

    }
    
};



int main()
{
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
