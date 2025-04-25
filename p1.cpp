#include <iostream>
#include <string>

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
        cout<<"enter id:";
        cin>>meal_id;
         }


    void set_name() {
        cout<<"enter name:";
        cin>>name;
         }


    void set_type() {
         int i;
         cout<<"enter type meal:";
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



int main(){

 M hj;

hj.input();
hj.print();

din k;

k.input();
k.print();

return 0;
}





