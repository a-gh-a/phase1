#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <ctime>

using namespace std;

enum MealType { BREAKFAST, LUNCH, DINNER };
enum day {MONDAY,TUESDAY,WEDNESDAY,THURSDAY,FRIDAY};

class M
 {
private:
    int meal_id;
    string name;
    MealType type;
    float price;
    day day_Re;

public:


    void print() const {
        cout << "Meal: " << name << ", Type: " << type << ", Price: " << price <<",day:"<<day_Re<< endl;
    }


    void input(){
        set_meal_id();
        set_name();
        set_type();
        set_price();
        set_day();
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

    void set_day(){
    int i;
    cout<<"enter day(1,2,3,4,5):";
    cin>>i;
    if(i==1)day_Re=MONDAY;
    if(i==2)day_Re=TUESDAY;
    if(i==3)day_Re=WEDNESDAY;
    if(i==4)day_Re=THURSDAY;
    else day_Re=FRIDAY;


    }

    // Getters
    int get_meal_id() const { return meal_id; }
    string get_name() const { return name; }
    MealType get_type() const { return type; }
    float get_price() const { return price; }
    day get_day() const {return day_Re;}
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

class User {
protected:
    int userID;
    string name, lastName;
    string hashedPassword;

public:

    //User(int id, string n, string ln, string pwd) : userID(id), name(n), lastName(ln), hashedPassword(pwd) {}

    // Getters
    int getUserID() const { return userID; }
    string getName() const { return name; }
    string getLastName() const { return lastName; }
    string getHashedPassword() const { return hashedPassword; }

    // Setters
    void setName(string n) { name = n; }
    void setLastName(string ln) { lastName = ln; }
    void setHashedPassword(string pwd) { hashedPassword = pwd; }


    virtual void print() const {
        cout << "User ID: " << userID << ", Name: " << name << " " << lastName << endl;
    }
};





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
        else cout<<"error";
      }

    // Getters
    int get_reservation_id() const { return reservation_id; }
    Student get_student() const { return studentt; }
    M get_meall() const { return meall; }
    din get_halll() const { return halll; }
    ReservationStatus get_status() const { return status; }
    time_t get_created_at() const { return created_at; }
};






class Admin : public Student{
public:



    // مدیریت وضعیت فعال بودن
    void activateUser(User& user) {
        cout << "User: " << user.getName()<<endl;
        set_active();

    }


    // چاپ اطلاعات Admin
    void print() const {
        cout << "Admin ID: " << getUserID() << ", Name: " << getName() << " " << getLastName() << endl;
    }
};



class Panel {
public:
    // نمایش منو
    void showMenu() {
        cout << "1. display student information\n";
        cout << "2. show credit\n";
        cout << "3. view reservations\n";
        cout << "4. add reservation\n";
        cout << "5. add to cart\n";
        cout << "6. purchase confirmation\n";
        cout << "7. cancel the reservation\n";
        cout << "8. EXIT";
    }

    // توابع مربوط به تعاملات کاربری
    void showStudentInfo();
    void checkBalance();
    void viewReservations();
    void addReservation(Reservation);
    void addToShoppingCart();
    void confirmShoppingCart();
    void removeShoppingCartItem();
    void increaseBalance();
    void cancelReservation(int);
    void exit();
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


