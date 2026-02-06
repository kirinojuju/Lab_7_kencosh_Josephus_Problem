#include<iostream>
#include<list> //including <list> Lirary

using namespace std;

int main()
{   
    // Declaring the <int> lst of List
    list <int> lst;
        int N, M;
        // N is Number of People
        // M is Number of Turn's playing
    
    cout << "Hot Potato Game!" << endl;
    
    // Call Output & Input of N and M
    cout << "Enter the N (number of people): ";
    cin >> N;
    cout << "Enter the M (number of turn): ";
    cin >> M;

    // Creating or Adding the List of lst with N lists
    for(int i = 0; i < N; i++){
        lst.push_back(i+1);
    }

    cout << "So,.. There are " << N << " person in this Game" << endl;
    cout << endl;
    
    // Decalaring the Iterator of list (pointer of list) people is beginning of lst
    list<int>::iterator people = lst.begin();

    // Cout the Current Player
    for(int i = 0; i < N; i++){
        cout << "Person: " << *people << " ";
        people++;
        if(people == lst.end()){
            people = lst.begin();
        }
    }
    cout << endl;

    // Decalaring the Iterator of list (pointer of list) current_people is people
    list<int>::iterator current_people = people;
    
    // Looping Game Until the size of list is less than 1
    while(lst.size() > 1){
        // Looping the list of turn 
        for(int i = 1; i <= M; i++){
            current_people++;
            if(current_people == lst.end()){
                current_people = lst.begin(); // Make it to be Circular Linked list
            }
        }

        // Decalaring the Iterator of list (pointer of list) temporary(temp) is current_people
        list<int>::iterator temp = current_people;
        temp++;
        if(temp == lst.end()){
            temp = lst.begin();
        }

        cout << "Eliminated: " << *current_people << endl;

        lst.erase(current_people); // Delete the position of Turn to be
        current_people = temp; // return temp to current_people

    }
    
    cout << "The winner is " << lst.front() << endl; // Cout the Winner

    return 0;
}