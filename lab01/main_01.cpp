    #include <iostream>

    using namespace std;

    int countBits(int number){
        int count = 0;
        while(number != 0){
            count += number & 1;
            number >>= 1;
        }
        return count;
    }

    bool setBit(int& number, int order){
        number |= 1 << order;
        return true;
    }

    double mean(double array[], int numElements){
        double sum = 0;
        for (int i = 0; i < numElements; ++i) {
            sum += array[i];
        }
        return sum / numElements;
    }

    pair<double, double> max2(double array[], int numElements){
        double max1 = 0;
        double max2 = 0;
        for (int i = 0; i < numElements; ++i) {
            if(array[i] > max1){
                max2 = max1;
                max1 = array[i];
            }else if(array[i] > max2){
                max2 = array[i];
            }
        }
        return make_pair(max1, max2);
    }

    int main() {
      //  std::cout << "Hello, Lab_01" << std::endl;
    /*
        for (int i = 0; i < 127; ++i) {
            cout<< countBits(i)<< endl;
        }
        */
    /*
        for (int i = 0; i < 35; ++i) {
            int n = 0;
            if(setBit(n, i)){   
                cout<<i<<" ---> " << n <<endl;
            }else{
                cout<<"Impossible operation!" << endl;
            }
        }
        */

        double a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        double b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        double c[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        cout << mean(a, 10) << endl;
        cout << mean(b, 10) << endl;
        cout << mean(c, 10) << endl;

        cout << max2(a, 10).first << endl;
        cout << max2(b, 10).first << endl;
        cout << max2(c, 10).first << endl;





        return 0;
    }

