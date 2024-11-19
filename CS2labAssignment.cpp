
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

class patient
{
private:
    string patientId;
    char gender;
    string time;
    char type;
    int depTIME;
public:
    patient(string p, char g,string t,char ty, int d)
    {
        patientId = p;
        gender = g;
        time = t;
        type = ty;
        depTIME = d;
    }
    void isIDvalidated(string s) // validates the id length is 14 and the numbers are from 0 to 9
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] < '0' || s[i]>'9')
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
    int extractTime(string t)
    {

        int hours = (t[0] - '0') * 10 + (t[1] - '0');
        int minutes = (t[3] - '0') * 10 + (t[4] - '0');
        return (hours * 60) + minutes;


    }
    string getTime()
    {
        return time;
    }
    void setdepTIME(int s)
    {    
        depTIME = s;
    }
    int getdepTIME() 
    {
        return depTIME;
    }
    patient Random()
    {
      
        if (rand() % 2)
        {
           gender = 'M';
        }
        else {
            gender = 'F';
        }
        if (rand() % 2)
        {
            type = 'U';
        }
        else {
           type = 'N';
        }

        for (int i = 0; i < 14; i++)
        {
           patientId[i] = rand() % 10;
        }

        int hours = rand() % 24;
        int minutes = rand() % 60;
        if (hours < 10)
        {
           time = "0" + to_string(hours) + ":" + to_string(minutes);
        }
        else {
           time = to_string(hours) + ":" + to_string(minutes);
        }

        if (minutes < 10)
        {
           time = to_string(hours) + ":" + "0" + to_string(minutes);
        }
        else {
           time = to_string(hours) + ":" + to_string(minutes);
        }
        patient p(patientId,gender,time,type,depTIME=0);
        return p;
    }
};
class queueing_system {
private:
    queue<patient> urgentqueue;
    queue<patient> normalqueue;
    int max_time; // when i do it as a const i get an error, why?
   

public:
    queueing_system() {
        max_time = 10;
    }
    void add_to_list( patient& p) {
        if ( p.getType() == 'U') {
            urgentqueue.push(p);
        }
        else if (p.getType() == 'N') {
            normalqueue.push(p);
        }
        
    }
    vector<patient> Serving(int n)
    {
        cout<<"in serving"<<endl;
        vector <patient> healedPatients;
        while (!urgentqueue.empty() && n > 0)
        {
            patient healed = urgentqueue.front();
            healed.setdepTIME(2); // takes the current time
            healedPatients.push_back(healed);
            urgentqueue.pop();
            n--;
        }
        while (!normalqueue.empty() && n > 0)
        {
            patient healed = normalqueue.front();
            healed.setdepTIME(2); // takes the current time
            healedPatients.push_back(healed);
            normalqueue.pop();
            n--;

        }
        return healedPatients;

    }
    int getsizeUrgent()
    {
        return urgentqueue.size();
    }
    int getsizeNormal()
    {
        return normalqueue.size();

    }
    void printUrgentqueue()
    {
        queue<patient> temp=urgentqueue;

        
         while (!temp.empty())
        {
            cout << temp.front().getPatientId() << " " << endl;
            temp.pop();
        }
           
        
    }
    void printNormalqueue()
    {
        queue<patient> temp = normalqueue;


        while (!temp.empty())
        {
            cout << temp.front().getPatientId() << " " << endl;
            temp.pop();
        }


    }

};
class wholeProgram {
private:
    vector<patient> p;
    vector<patient> finalp;
    queueing_system system;
    vector<int> wait_time;
    int time_current;
    int total_wait_time;
    int n_served;
    double avg;

public:
    wholeProgram() {
        time_current = 0;
        total_wait_time = 0;
        n_served = 0;

    }
    static bool checktime(patient p1, patient p2) //we check to the arrival time of patients to see how arrived first
    {
        return (p1.extractTime(p1.getTime()) < p2.extractTime(p2.getTime()));

    }
    void generate_patients(int count) {
        for (int i = 0; i < count; ++i) 
        {
            patient p1("",'F',"",'U',0);// this is dummy data
            p1.Random();
            p.push_back(p1);
            cout<<"in for"<<endl;
            cout<<i;
        }
        cout<<"out for"<<endl;
        sort(p.begin(), p.end(), checktime);
    }
    

    void simulation(int n) {
        cout<<"in simulation"<<endl;
        for(int i=0;i<p.size();i++)
        { system.add_to_list(p[i]);}
        finalp= system.Serving(n);
        cout<<"finalp "<<finalp.size()<<endl;
        for (int i = 0; i < finalp.size(); i++)
        {
            total_wait_time+= finalp[i].getdepTIME() - finalp[i].extractTime(finalp[i].getTime());
            cout << "served patient id: " << finalp[i].getPatientId() << endl;
        }
        n_served = finalp.size();
        avg=total_wait_time / finalp.size();
        system.printUrgentqueue();
        system.printNormalqueue();
    }

    
    
    void display() 
    { // we need to print avg waiting time, total number of patients, number of urgent cases,and number of normal cases.
        cout << "average waiting time= " << avg << endl;
        cout << "total number of patients= " << n_served << endl;
        cout << "number of urgent cases= " << system.getsizeUrgent() << endl;
        cout << "number of normal cases= " << system.getsizeNormal() << endl;
       
    }


};


int main()
{
    cout << "which scenario do you want??" << endl;
    cout << "enter 1 for simple scenrio, 2 for moderate, and 3 for crowded" << endl;
    int value;
    cin >> value;
    wholeProgram p;
    if (value == 1)
    {
cout<<"hello"<<endl;
        p.generate_patients(100);
      


    }
    else if (value == 2)
    {

        p.generate_patients(300);
    }
    else if (value == 3)
    {
        p.generate_patients(700);
    }
    else {
        cout << "invalid input !!!" << endl;
    }
   
    while (1)
    {
        p.simulation(rand() % 6 + 5);
        cout << "press enter to advance time or enter 0 to stop the program" << endl;
        int c;
        cin >> c;
        if (c == 0)
        {
            p.display();
            break;
        }
       
    }
     
        

}
