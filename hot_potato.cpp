#include<iostream>
#include<list>

using namespace std;

int main()
{
    list <int> lst;
        int N, M;
    
    cout << "Hot Potato Game!" << endl;
    
    cout << "Enter the N (number of people): ";
    cin >> N;
    cout << "Enter the M (number of turn): ";
    cin >> M;

    for(int i = 0; i < N; i++){
        lst.push_back(i+1);
    }

    cout << "So,.. There are " << N << " person in this Game" << endl;
    cout << endl;

    list<int>::iterator people = lst.begin();

    for(int i = 0; i < N; i++){
        cout << "Person: " << *people << " ";
        people++;
        if(people == lst.end()){
            people = lst.begin();
        }
    }
    cout << endl;

    list<int>::iterator current_people = people;

    while(lst.size() > 1){
        for(int i = 1; i <= M; i++){
            current_people++;
            if(current_people == lst.end()){
                current_people = lst.begin();
            }
        }

        list<int>::iterator temp = current_people;
        temp++;
        if(temp == lst.end()){
            temp = lst.begin();
        }
        
        cout << "Eliminated: " << *current_people << endl;

        lst.erase(current_people);
        current_people = temp;

    }
    
    cout << "The winner is " << lst.front() << endl;

    return 0;
}