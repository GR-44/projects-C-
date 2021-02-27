/* Modeling supermarket working day(720 minuts). We need to calculate how many people(max quantity for one time, not for all day)
   will be in a queue. 
*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    const int working_day = 720;       // working day = 720 minutes
    int current_time = 0;
    queue<int> que;
    int custom_time;                   // random customer appearance time(from 1 to 4)
    int service_time;                  // random customer service time(from 1 to 4)
    int current_customer = 0;
    int served_customer = 0;
    int next_customer = 1;              
    int max_customers_que = 0;         // max customers in the queue
    bool new_customer = false;
    bool vacant_cashier = false;
    bool first_service = true;
    int end_service = 0;
    int total_customers = 0;
    srand(time(0));

    custom_time = current_time + (rand() % 4 + 1);                     // custom appearance time
    for (; current_time <= working_day; ++current_time)
    {
        if(custom_time == current_time)    // total customers quantity from store opening
            ++total_customers;
        if (first_service == true && (custom_time == current_time))   // the first customerer service 
        {
            ++current_customer;
            service_time = rand() % 4 + 1;
            end_service = current_time + service_time;
            vacant_cashier = false;
            first_service = false;
        }

        if (end_service == current_time && current_time != 0)
        {
            if(current_time != 0)
                ++served_customer; // total served customers from store opening

            if (!que.empty())
            {
                que.pop();
                vacant_cashier = true;
            }
            else
            {
                vacant_cashier = true;
            }
        }

        if (vacant_cashier == true && served_customer < total_customers)  // service of customer if cashier is vacant
        {
            ++current_customer;
            service_time = rand() % 4 + 1;
            end_service = current_time + service_time;
            vacant_cashier = false;
            new_customer = false;
        }

        if (custom_time == current_time)               // random appearance time of new customer
        {
            custom_time = current_time + (rand() % 4 + 1);
            new_customer = true;
            ++next_customer;
        }

        if (vacant_cashier == false && new_customer == true && total_customers > current_customer)  // push new customer in the queue
        {                                                                                           // if cashier is busy
            que.push(1);
            new_customer = false;
        }

        if (que.size() > max_customers_que)              
            max_customers_que = que.size();
    }

    cout << "max customers in queue: " << max_customers_que << endl;    // total customers in the queue
    cout << "total customers:        " << total_customers << endl;

    return 0;
}














