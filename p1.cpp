#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <ctime>

using namespace std;

enum MealType { BREAKFAST, LUNCH, DINNER };

class M
 {
private:
    int meal_id;
    string name;
    MealType type;
    float price;

public:


    void print() const {
        cout << "Meal: " << name << ", Type: " << type << ", Price: " << price << endl;
    }


    void input(){
        set_meal_id();
        set_name();
        set_type();
        set_price();
        }

    // Setters with validation
    void set_meal_id() {
        cout<<"enter meal_id:";
        cin>>meal_id;
         }


    void set_name() {
        cout<<"enter meal_name:";
        cin>>name;
         }


    void set_type() {
         int i;
         cout<<"enter type meal:(1,2,3)";
         cin>>i;
          if(i==1) type=BREAKFAST;
          if(i==2) type=LUNCH;
          if(i==3) type=DINNER;
          }




    void set_price() {

        for(int i=0;i<1;)
            {
                cout<<"enter price:";
                cin>>price;
                if (price > 0) { i++;}


                 else cout<<endl<<"enter agin";
            }
    }

    // Getters
    int get_meal_id() const { return meal_id; }
    string get_name() const { return name; }
    MealType get_type() const { return type; }
    float get_price() const { return price; }
};


class din {
private:
    int hall_id;
    string address;
    int capacity;

public:

    void print() const {
        cout << "Dining Hall: " << address << ", Capacity: " << capacity << endl;
    }

    void input(){
        set_hall_id();
        set_address();
        set_capacity();
                }

    // Setters with validation
    void set_hall_id() { cout<<"enter id:";cin>>hall_id; }
    void set_address() { cout<<"enter address:";cin>>address; }
    void set_capacity() {
         for(int i=0;i<1;)
            {
                cout<<"enter capacity:";
                cin>>capacity;
                if (capacity > 0) { i++;}


                 else cout<<endl<<"enter again";
            }
    }

    // Getters
    int get_hall_id() const { return hall_id; }
    string get_address() const { return address; }
    int get_capacity() const { return capacity; }
};





class Student {
private:
    int student_id;
    string name, email;
    float balance;
    vector<int> reservations;

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
        std::cerr << "رزرو یافت نشد!\n";
        return false;
    }

    // Setters with validation
    void set_student_id() { cout<<"enter student_id:";cin>>student_id;  }
    void set_name() { cout<<"enter student_name:"; cin>>name; }
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
    int get_student_id() const { return student_id; }
    string get_name() const { return name; }
    string get_email() const { return email; }
    float get_balance() const { return balance; }
};



enum ReservationStatus { SUCCESS, CANCELLED, FAILED };

class Reservation {
private:
    int reservation_id;
    Student studentt;
    M meall;
    din halll;
    ReservationStatus status;
    time_t created_at;

public:


    void print() const {
        cout << "Reservation ID: " << reservation_id << ", Student: " << studentt.get_name()
                  << ", Meal: " << meall.get_name() << ", Status: " << status << endl;
    }

    void input(Student b2,M h1,din h2){
        set_reservation_id();
        set_student(b2);
        set_meal(h1);
        set_hall(h2);
        set_status();
                }

    void cancel() {
        if (status == SUCCESS) status=CANCELLED;
        else cout<<"cansel bod";

                  }

    // Setters with validation
    void set_reservation_id() {cout<<"enter re_id:"; cin>>reservation_id; }
    void set_student(Student b1) {studentt=b1;}
    void set_meal(M h1) {meall=h1; }
    void set_hall(din h2) { halll=h2;}
    void set_status() {
        int i;
        cout<<"enter re_status:(1,2,3)";
        cin>>i;
        if(i==1)status=SUCCESS;
        if(i==2)status=CANCELLED;
        if(i==3)status=FAILED;

      }

    // Getters
    int get_reservation_id() const { return reservation_id; }
    Student get_student() const { return studentt; }
    M get_meall() const { return meall; }
    din get_halll() const { return halll; }
    ReservationStatus get_status() const { return status; }
    time_t get_created_at() const { return created_at; }
};




int main(){

 M hj;

hj.input();
//hj.print();

din k;

k.input();
//k.print();

Student b;

b.input();
//b.print();

Reservation l;

l.input(b,hj,k);
l.print();

return 0;
}





