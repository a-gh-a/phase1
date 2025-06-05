#ifndef CLASS_RESERVATION_H_INCLUDED
#define CLASS_RESERVATION_H_INCLUDED


using namespace std;


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


#endif // CLASS_RESERVATION_H_INCLUDED
