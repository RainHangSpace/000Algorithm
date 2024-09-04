#include <iostream>
#include <set>
#include <map>
#include <string>
#include <unordered_set>
int main() {
    std::set<int> s;
    s.insert(2); // ����Ԫ�� 1
    s.insert(1); // ����Ԫ�� 2
    s.insert(1); // ��ͼ�ٴβ���Ԫ�� 1��������룬��Ϊ�Ѵ��ڣ�

    for (int num : s) {
        std::cout << num << " "; // ���: 1 2
    }
    std::cout << '\n';

    std::map<int, std::string> m;
    m.insert({ 1, "one" }); // �����Ϊ 1 ֵΪ "one" �ļ�ֵ��
    m.insert(std::make_pair(3, "three")); // Ҳ������������
    m.insert({ 2, "two" }); // �����Ϊ 2 ֵΪ "two" �ļ�ֵ��
    

    for (const auto& pair : m) {
        std::cout << pair.first << " => " << pair.second << '\n'; // ���: 1 => one, 2 => two, 3 => three
    }

    std::unordered_set<int> us;
    us.insert(10); // ����Ԫ�� 10
    us.insert(30); // ����Ԫ�� 30
    us.emplace(20); // ֱ���������й���Ԫ�� 20

    for (int num : us) {
        std::cout << num << " "; // �����˳����������˳��ͬ
    }
    std::cout << '\n';



    return 0;
}
