#include <iostream>
using namespace std;


//ok function from 1D8queens without goto
//modified
bool ok(int arr[], int c) {
    int mp[3][3] = {{0,2,1},
                    {0,2,1},
                    {1,2,0}};

    int wp[3][3] = {{2,1,0},
                    {0,1,2},
                    {2,0,1}};

    for (int i = 0; i < c; i++){
        if (arr[c]==arr[i]) return false; //The woman is already assigned to a man.
        else if ((mp[i][arr[c]]<mp[i][arr[i]]&&wp[arr[c]][i]<wp[arr[c]][c]) || (mp[c][arr[i]]<mp[c][arr[c]]&&wp[arr[i]][c]<wp[arr[i]][i])) return false;
        //current man's preference for new woman is more than his wife and new woman's preference for current man is more than her man.
        //new man's preference for current woman is more than his wife and current woman's preference for new man is more than her man.
    }
    return true;
};

void print(int arr[],int &x){
        cout << "Solution#" << ++x << " :" << endl;
        cout << "Man" << "   " << "Woman" << endl;
    for (int i =0; i<3; i++) {
        cout << i << "     " << arr[i] << endl;
    }
    cout<<endl;
}

int main() {
    int sm[3]= {-1,-1,-1}; //set all values to -1 to start pairing from woman 0.
    int nm = 0; //set next man to zero.(Starts paring from man0)
    int sol = 0; //Solution number.

    //Used a while loop instead of recursive function or gotos.
    while (nm >= 0) { // Once it is backtracked all the way to -1, the loop will stop
        sm[nm]++; //start pairing from woman 0;
        if (sm[nm] == 3) { //Base case, All women has been tried no suitable match found.
            sm[nm] = -1; //Reset the current man's pairing status;
            nm--; //backtrack to the previous man.
        } else if (ok(sm, nm)){ //Starts pairing with ok function
                if (nm == 2) {
                    print(sm,sol);//All men paired print the solution
                } else {
                    nm++;//if not all men are paired, move on to next man
                }
            }
        }
    return 0;
}