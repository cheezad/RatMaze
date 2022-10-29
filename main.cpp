#include <iostream>
#include <stack>
#include <fstream>
#include <string>
using namespace std;

ofstream myfileout;
struct pos{
    int x,y;
};
static int matrix[17][17];
static int mark[17][17];
struct offsets{
    int a, b;
};
struct Items{
    int x, y, dir;
};

enum directions { E, SE, S, SW, W, NW,  N, NE};

static void Path(const int m, const int p){
    int now = 0;
    mark[1][0] = 1;
    stack<Items> st;
    struct offsets move[8] = {
        {0, 1},
        {1, 1},
        {1, 0},
        {1, -1},
        {0, -1},
        {-1, -1},
        {-1, 0},
        {-1, 1}
    };
    Items temp = {1, 0, E};
    st.push(temp);
    pos first = {1,0};
    
    while (!st.empty()){
        temp = st.top();
        myfileout << now++ << ":"<< temp.x << "," << temp.y << endl; // print
        st.pop(); // unstack
        int i = temp.x; int j = temp.y; int d = temp.dir;
        while (d < 8) // move forward
        {
            int g = i + move[d].a, h = j + move[d].b;
            if(g < 0 || g > 17 || h < 0 || h > 17) {
                d++;
                continue;
            }
            if(g == m && h == p){ // reached end
                pos last = {m,p};
                myfileout << now++ << ":"<< last.x << "," << last.y << endl; // print
                myfileout <<  "successfully escaped!!" << endl;
                return;
            }
            if((!matrix[g][h]) && (!mark[g][h])){ // new pos
                mark[g][h] = 1;
                temp.x=i; temp.y=j; temp.dir=d+1;
                myfileout << now++ << ":"<< g << "," << h << endl; // print
                st.push(temp); // stack it
                i = g; j = h; d = E; // move to (g,h)
            }else d++; // try next direction
        }
    }
    
    myfileout << "Failed to escape" << endl;
}

int main(){
    string nameOfFile;
    cout << "enter file name : ";
    cin >> nameOfFile;
    string line;
    ifstream myfile (nameOfFile);
    myfileout.open ("output.txt");
    if (myfile.is_open())
    {
        int i = 0;
        while ( getline (myfile,line) )
        {
            for(int j = 0 ; j < 17 ; j++){
                int num = line[j] - 48;
                matrix[i][j] = num;
                mark[i][j] = num;
            }
            i++;
        }
        myfile.close();
    }else cout << "Unable to open file"; 
    Path(15,16);
    myfileout.close();
    return 0;
}
