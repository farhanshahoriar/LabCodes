#include <bits/stdc++.h>
int main(){
std::vector<int> v{ 10,20, 20, 30, 40, 50 };
//ub(51)->6  //ub(50)->6  //ub(49)->4  //ub(10)->1 /ub(9) ->0
//std::upper_bound() returns an iterator to the upper bound of the value passed to it.
 //iterator to 1st number larger than it.

 //lb(51)->5 //lb(50)->4 //lb(49)->4 //lb(15)->1 //lb(10)->0 //lb(9)->0
 int x=20;
 auto upper1 = std::lower_bound(v.begin(), v.end(), x);
 auto upper2 = std::upper_bound(v.begin(), v.end(), x);

 std::cout << "\nupper_bound for element 35 is at position : "<< (upper1 - v.begin());

    std::cout << "\nupper_bound for element 45 is at position : "<< (upper2 - v.begin());
    return 0;
}
