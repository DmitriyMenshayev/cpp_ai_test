#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Ai {
private:
    double lr;
    double bias;
    vector<double> weights;
public:
    Ai(){
        srand(time(0));

        weights = {
            1.0*rand()/RAND_MAX,
            1.0*rand()/RAND_MAX,
            1.0*rand()/RAND_MAX
        };
        lr = 1;
        bias = 1;
    }

    void learn(double input1, double input2, double output){
        cout << weights[0] << "  " << weights[1] << "  " << weights[2] << "\n";

        double outputP = input1*weights[0]+input2*weights[1]+bias*weights[2];
        if (outputP > 0){
            outputP = 1;
        } else {
            outputP = 0;
        }

        double error = output - outputP;
        weights[0] = weights[0] + error * input1 * lr;
        weights[1] = weights[1] + error * input2 * lr;
        weights[2] = weights[2] + error * bias * lr;
    }

    double solve(double input1, double input2){
        return input1*weights[0] + input2*weights[1] + bias*weights[2];
    }
};

int main(int argc, char* argv[]){

    Ai ai{};

    for (int i = 0; i < 50; i++){
        ai.learn(1.0, 1.0, 1.0);
        ai.learn(1.0, 0.0, 1.0);
        ai.learn(0.0, 1.0, 1.0);
        ai.learn(0.0, 0.0, 0.0);
    }

    int f = 0;

    while (f < 10){
        int x, y;

        cout << "Type x:\n";
        cin >> x;
        cout << "Type y:\n";
        cin >> y;

        double outputP = ai.solve(x, y);

        cout << "temp result is: " << outputP << "\n";

        if (outputP > 0){
            outputP = 1;
        } else {
            outputP = 0;
        }

        cout << "result is: " << outputP << "\n\n";

        f++;
    }
}