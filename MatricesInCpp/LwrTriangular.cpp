#include <iostream>

using namespace std;

class LowerTriangular{
    private:
        int *A;
        int dim;
    public:
        LowerTriangular(int dim){
            this->dim = dim;
            A = new int[dim];
        }
        ~LowerTriangular()
        {
            delete []A;
        }

        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
};

void LowerTriangular::set(int i, int j, int x){

    int index;

    if(i >= j){
        index = ((i * (i - 1)) / 2) + (j - 1);
        A[index] = x;
    }   
}

int LowerTriangular::get(int i, int j){
    int index;
    if(i >= j)
    {
        index = ((i * (i - 1)) / 2) + (j - 1);
        return A[index];
    }
    else
    {
        return 0;
    }
}

void LowerTriangular::display()
{
    int i, j, index;

    for(i = 1; i <= dim; i++)
    {
        for(j = 1; j <= dim; j++)
        {
            if(i >= j)
            {
                index = ((i * (i - 1)) / 2) + (j - 1);
                printf("%d ", A[index]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }

}

void initLower()
{
    
    int x;
    int dim;

    cout << ("Enter matrix dimension: ");
    cin >> dim;

    LowerTriangular m(dim);

    cout << "\nEnter all elements: \n";

    for(int i = 1; i <= dim; i++)
    {
        for(int j = 1; j <= dim; j++)
        {
            cin >> x;
            m.set(i, j, x);
        }
    }
    
    cout << endl;

    m.display();
}

int main(){

    initLower();
}




