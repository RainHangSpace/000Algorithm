#include<iostream>
#include<utility>
void process(int& value) {
    std::cout << "L-value processed: " << value << std::endl;
}

void process(int&& value) {
    std::cout << "R-value processed: " << value << std::endl;
}

// ת������ģ��û��ʹ��std::forward
template<typename T>
void forwarder(T&& arg) {
    process(arg); // �������forwad ������������ֵ����ݴ���arg
    // process(std::forward<T>(arg));ֻ��ʹ����forwad arg�����ͲŻᱻ����ת��
}

//�����۵�
template<typename T>
void reference_collapse_example(T&& arg) {
    // ������������У�T&&��һ��"��������"�������԰󶨵���ֵ����ֵ
    process(std::forward<T>(arg)); // T�����ͻ����arg����ֵ������ֵ
    // ��arg�󶨵���ֵʱ��T����T&������ᷢ�������۵������T& &�����T&
    // ��arg�󶨵���ֵʱ��T����T��û�з��������۵�
}


int main() {
    int x = 10;
    int& l_ref = x;      // ��ֵ����
    int&& r_ref = std::move(x);    // ��ֵ����
    int&& r_ref1 = 20;

    std::cout << "ʹ��forward����ʱ������ת��" << std::endl;
    reference_collapse_example(l_ref); // T�ᱻ�Ƶ�Ϊint&������T&& = int& &&�����۵�Ϊint&
    reference_collapse_example(r_ref); // T�ᱻ�Ƶ�Ϊint&��arg������һ����ֵ������ͬ�ϣ���������ֵ���ã�Ҳ����ֵ��
    reference_collapse_example(r_ref1);// ͬ�ϣ�����չ������ֵ����Ҫ��õ���ֵ��������move����
    reference_collapse_example(30);    // T�ᱻ�Ƶ�Ϊint������T&& = int&&��û���۵�����


    std::cout << "\n��ʹ��forward����ʱ��ȫ����ֵ" << std::endl;
    forwarder(x);  // x����ֵ������process(int&)
    forwarder(10); // 10����ֵ����������ֵ����ݵ���process(int&)
    return 0;

}

