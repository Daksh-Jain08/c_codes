#include<iostream>
#include"stack_cpp.h"

using namespace std;


int main(){
    Stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);

    st.display();

    cout<<st.pop()<<endl;

    st.display();
    return 0;
}
