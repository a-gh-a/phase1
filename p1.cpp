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
    Meal(int id, string n, MealType t, float p) {
        set_meal_id();
        set_name();
        set_type();
        set_price();
    }

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


int main(){

 M hj;

hj.input();

return 0;
}





