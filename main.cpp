#include<iostream>

using namespace std;

/*

 i. Create a class that holds Money objects
 ii. What does the class do:

    it holds a value of money

    mutators and accessors
    setters and getters


    getters (accessors):
    get a balance (get info)

    setters:
    make a deposit
    make a withdrawal

 */

class Money{
private:
    double* all_cents; //maybe it's an pointer

public:

    Money();
    Money(const double& initial_deposit);
    Money(const Money& object_passed);

    ~Money();

    //getters (accesors)
    double const get_balance(); //return double all_cents

    //setters (mutators)
    void set_deposit(const double& deposit);
    void set_withdrawal(const double& withdrawal);

    //operator overloading
    double operator+(const double& passed_double);
    void operator-(const double& withdrawal_amount);

};



int main(){
    double balance, new_balance;

    Money old_account;

    old_account.set_deposit(50.00);

    balance = old_account.get_balance();

    cout << "Balance: " << balance << endl;

    old_account.set_deposit(100.00);

    cout << "Balance: " << balance << endl;

    Money new_account(old_account);

    new_balance = new_account.get_balance();

    cout << "New Account Balance: " << new_balance << endl;



    new_balance = (new_account + 100.00);

    cout << "New Account Balance: " << new_balance << endl;


    return 0;
}

Money::Money():all_cents(new double(0.0)){}
Money::Money(const double &initial_deposit):all_cents(new double(initial_deposit*100.00)){}
Money::Money(const Money& object_passed):all_cents(new double(*object_passed.all_cents)){}

//MEMBER FUNCTIONS

double const Money::get_balance(){
    return (*all_cents/100.00);
}

void Money::set_deposit(const double& deposit){
    *all_cents +=(deposit*100.00);
}

void Money::set_withdrawal(const double& withdrawal){
    double withdrawal_in_cents = withdrawal * 100.00;

    //what can go wrong? Answer: withdraw more money than you have

    if(withdrawal_in_cents > *all_cents){
        cout << "\t Careful! You are spending more than you have!" << endl;
        *all_cents-=withdrawal_in_cents;
    } else{
        *all_cents-=withdrawal_in_cents;
    }

}

Money::~Money(){
    delete all_cents;
    all_cents = NULL;
}

// OPERATOR OVERLOADING

double Money::operator+(const double& passed_double){
    set_deposit(passed_double);
    double temp = get_balance();
    return temp;
}

void Money::operator-(const double& withdrawal_amount){
    set_withdrawal(withdrawal_amount);

    return;
}
