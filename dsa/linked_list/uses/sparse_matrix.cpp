#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct Node {
    int col;
    int data;
    struct Node *next;
} NODE;

class SparseMatrix{
    private:
        int num;
        int columns;
        int rows;
        NODE **arr;

    public:
        SparseMatrix(){
            cout<<"Enter the number of rows in the matrix: ";
            cin>>rows;
            cout<<"Enter the number of columns in the matrix: ";
            cin>>columns;
            cout<<"Enter the number of elements: ";
            cin>>num;
            arr = new NODE*[rows];
            for(int i = 0; i < rows; i++)
                arr[i] = NULL;
            for(int i = 0; i < num; i++){
                int col, row, ele;
                cout<<"Enter the row for element number " << i+1 << ": ";
                cin>>row;
                if(row>rows){
                    cout<<"Row out of range!!\n";
                    i--;
                    continue;
                }
                cout<<"Enter the column for element number " << i+1 << ": ";
                cin>>col;
                if(col>columns){
                    cout<<"Column out of range!!\n";
                    i--;
                    continue;
                }
                cout<<"Enter the element number " << i+1 << ": ";
                cin>>ele;
                insertSorted(col,row,ele);
            }
        }

        void insertSorted(int col, int row, int ele){
            NODE *p = arr[row-1];
            NODE *t = new NODE{col, ele, nullptr};
            if(p==nullptr){
                arr[row-1] = t;
            }
            else if(p->col>col){
                t->next = p;
                arr[row-1] = t;
            }
            else{
                while(p->next && p->next->col<col){
                    p = p->next;
                }
                t->next = p->next;
                p->next = t;
            }
        }

        void display(){
            for(int i = 1; i <= rows; i++){
                NODE *p = arr[i-1];
                for(int j = 1; j <= columns; j++){
                    if(p && p->col==j){
                        cout<<p->data<<" ";
                        p = p->next;
                    }
                    else
                        cout<<"0 ";
                }
                cout<<endl;
            }
        }

        void add(SparseMatrix n){
            if(rows!=n.rows || columns!=n.columns){
                cout<<"The dimensions of the two matrices don't match, addition is not possible!\n";
                return;
            }

            for(int i = 0; i < rows; i++){
                NODE* p = arr[i], *q = n.arr[i];
                for(int j = 0; j < columns; j++){
                    
                }
            }
        }
};

int main(){
    SparseMatrix m = SparseMatrix();
    m.display();
}