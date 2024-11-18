// CS2labAssignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <queue>

using namespace std;

class patient
{
private:
    string patientId;
    char gender;
    int time;
    char type;
public:
   patient() 
    {
        patientId = "";
        gender = 'M';
        time = "";
        type = 'U';
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
     int  extractTime(string t)
    {
       
       int hours= (t[0] - '0') * 10 + (t[1] - '0');
       int minutes = (t[3] - '0') * 10 + (t[4] - '0');
       return (hours * 60) + minutes;


    }
 void Random()
        {
        patient p;
        if (rand() % 2)
        {
            p.gender = 'M';
        }
        else {
            p.gender = 'F';
        }
        if (rand() % 2)
        {
            p.gender = 'U';
        }
        else {
             p.gender = 'N';
        }
      
        for (int i = 0; i < 14; i++)
        {
            p.patientId[i] = rand()%10;
        }
         
        int hours = rand() % 24;
        int minutes = rand() % 60;
        if (hours < 10)
        {
            p.time = "0" + to_string(hours) + ":" + to_string(minutes);
        }
        else {
            p.time = to_string(hours) + ":" + to_string(minutes);
        }
        
        if (minutes < 10)
        {
            p.time = to_string(hours) + ":" + "0" + to_string(minutes);
        }
        else {
            p.time = to_string(hours) + ":" + to_string(minutes);
        }

    }
};
class queueing_system{
    private:
    queue<patient> urgentqueue; 
    queue<patient> normalqueue;
    int max_time; // when i do it as a const i get an error, why?
   char patient_status;

    public:
    queueing_system(){
        max_time = 10;
    }
    void add_to_list(const patient& p){
        if (patient_status == 'u'|| patient_status == 'U'){
            urgentqueue.push(p);
        }else if (patient_status=='N' || patient_status =='n'){
             normalqueue.push(p);
        }
    }
    // void next (){ // ask if we need this if not delete
    //     if (urgentqueue.empty()== false){
    //         patient next_p = urgentqueue.front();
    //         uregentqueue.pop();
    //         cout<<"current patient of type urgent"<<next.patientId<< "at: "<<next.time<<endl;
    //     }else if (normalqueue.empty()== false){
    //         patient next_p = normalqueue.front();
    //         normalqueue.pop();
    //         cout<<"current patient of type normal"<<next.patientId<< "at: "<<next.time<<endl;

    //     }else{
    //         cout<<"no patients waiting"<<endl;
    //     }
    // }
    // void print(){ // ask if we need this
    //     cout<<"current waiting queue in clinic for urgent patients: "<<endl;
    //     cout<<" urgent patients waiting queue: ";
    //     if (urgentqueue.empty()== true){
    //         cout<<"0"<<endl;
    //     }else{
    //         queue<patient> temp = urgentqueue;
    //         while (temp.empty()== false){
    //             cout<<temp.front().patientId<<" "<<endl;
    //             temp.pop();
    //         }

    //     cout<<"current waiting queue in clinic for normal patients: "<<endl;
    //     if (normalqueue.empty()== true){
    //         cout<<"0"<<endl;
    //     }else{
    //         queue<patient> temp1 = urgentqueue;
    //         while (temp1.empty()== false){
    //             cout<<temp1.front().patientId<<" "<<endl;
    //             temp1.pop();
    //         }


    //     }

    // }


void time_constraints (int current_time ){
    while (current_time>0){
        if (urgentqueue.empty()== false){
            patient new_p = urgentqueue.front();
             urgentqueue.pop();

             int time;
             if (current_time<max_time){
                time = current_time;
             }else{
                time = max_time;
             }
             current_time-=time;
        }else if (normalqueue.empty()== false){
            patient new_p = normalqueue.front();
             normalqueue.pop();

             int time;
             if (current_time<max_time){
                time = current_time;
             }else{
                time = max_time;
             }
             current_time-=time;
        }else{
            break;
        }
    }

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
