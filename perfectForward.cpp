#include<iostream>
#include<utility>
void process(int& value) {
    std::cout << "L-value processed: " << value << std::endl;
}

void process(int&& value) {
    std::cout << "R-value processed: " << value << std::endl;
}

// 转发函数模板没有使用std::forward
template<typename T>
void forwarder(T&& arg) {
    process(arg); // 如果不用forwad 这里总是以左值的身份传递arg
    // process(std::forward<T>(arg));只有使用了forwad arg的类型才会被完美转发
}

//引用折叠
template<typename T>
void reference_collapse_example(T&& arg) {
    // 在这个上下文中，T&&是一个"万能引用"，它可以绑定到左值或右值
    process(std::forward<T>(arg)); // T的类型会决定arg是左值还是右值
    // 当arg绑定到左值时，T就是T&，这里会发生引用折叠，因此T& &变成了T&
    // 当arg绑定到右值时，T就是T，没有发生引用折叠
}


int main() {
    int x = 10;
    int& l_ref = x;      // 左值引用
    int&& r_ref = std::move(x);    // 右值引用
    int&& r_ref1 = 20;

    std::cout << "使用forward函数时：完美转发" << std::endl;
    reference_collapse_example(l_ref); // T会被推导为int&，所以T&& = int& &&将会折叠为int&
    reference_collapse_example(r_ref); // T会被推导为int&，arg这里是一个左值，所以同上，即便是右值引用，也是左值！
    reference_collapse_example(r_ref1);// 同上，这里展现是右值引用要想得到左值，必须用move函数
    reference_collapse_example(30);    // T会被推导为int，所以T&& = int&&，没有折叠发生


    std::cout << "\n不使用forward函数时：全是左值" << std::endl;
    forwarder(x);  // x是左值；调用process(int&)
    forwarder(10); // 10是右值，但它以左值的身份调用process(int&)
    return 0;

}

