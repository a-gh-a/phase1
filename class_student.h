#ifndef CLASS_STUDENT_H_INCLUDED
#define CLASS_STUDENT_H_INCLUDED
#include "class_user.h"

using namespace std;

class Student : public User {
private:
    int student_id;
    string name, email;
    float balance;
    vector<int> reservations;
    bool active;
    int phone;

public:



    void print() const {
        cout << "Student: " << name << ", Email: " << email << ", Balance: " << balance << endl;
    }

    void input()
    {
     set_student_id();
     set_name();
     set_email();
     set_balance();
     set_active();
     set_phone();
    }

    bool reserve_meal(int meal_id, float price) {
        if (balance >= price) {
            reservations.push_back(meal_id);
            balance -= price;
            return true;
        }
        cout<<"erorr ";
        return false;
    }

    bool cancel_reservation(int meal_id) {
        for (auto it = reservations.begin(); it != reservations.end(); ++it) {
            if (*it == meal_id) {
                reservations.erase(it);
                return true;
            }
        }
        std::cerr << "error\n";
        return false;
    }

    // Setters with validation
    void set_phone (){cout<<"enter phone:";cin>>phone;}
    void set_student_id() { cout<<"enter student_id:";cin>>student_id;  }
    void set_name() { cout<<"enter student_name:"; cin>>name; }
    void set_active() {
          int i;
          cout<< " activated ?(yes=1,no=0)"<<endl;
          cin>>i;
          if(i==0) active=true;
          else active=false;
    }
    void set_email() {

        for(int i=0;i<1;)
            {
        cout<<"enter email:";
        cin>>email;
        regex email_pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

        if (regex_match(email, email_pattern)) i++;
        else cout<<"email is not correct";
            }
                     }


    void set_balance() {
        for(int i=0;i<1;)
            {
                cout<<"enter balance:";
                cin>>balance;
                if (balance > 0) { i++;}


                 else cout<<endl<<"enter again";
            }

    }

    // Getters
    int get_phone() const {return phone;}
    int get_student_id() const { return student_id; }
    string get_name() const { return name; }
    string get_email() const { return email; }
    float get_balance() const { return balance; }
    bool get_active() const {return active;}
};


#endif // CLASS_STUDENT_H_INCLUDED
