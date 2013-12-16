#include<iostream>
using namespace std;
 
int main(){
        int t;
        cin >> t;
        while(t!=0){
                float initial_rate,mins,initial_cost;
                int plans;
                cin >> initial_rate >> mins >> plans;
                initial_cost = initial_rate*mins;
                float final_cost[plans/1];
                int i=0,index;
                float min_cost=initial_cost;
                while(plans!=0){
                        float month,rate,act_cost;
                        cin >> month >> rate >> act_cost;
                        act_cost=act_cost/month;
                        final_cost[i]=rate*mins+act_cost;
                        if(final_cost[i] < min_cost){
                                min_cost=final_cost[i];
                                index=i;
                        }
                        i++;
                        plans--;
                }
                if(min_cost == initial_cost)
                        cout << 0 << endl;
                else
                        cout << index+1 << endl;
                t--;
        }
        return 0;
}
