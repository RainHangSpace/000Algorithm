#include <iostream>
#include <set>
#include <map>
#include <string>
#include <unordered_set>
int main() {
    std::set<int> s;
    s.insert(2); // 插入元素 1
    s.insert(1); // 插入元素 2
    s.insert(1); // 试图再次插入元素 1（不会插入，因为已存在）

    for (int num : s) {
        std::cout << num << " "; // 输出: 1 2
    }
    std::cout << '\n';

    std::map<int, std::string> m;
    m.insert({ 1, "one" }); // 插入键为 1 值为 "one" 的键值对
    m.insert(std::make_pair(3, "three")); // 也可以这样插入
    m.insert({ 2, "two" }); // 插入键为 2 值为 "two" 的键值对
    

    for (const auto& pair : m) {
        std::cout << pair.first << " => " << pair.second << '\n'; // 输出: 1 => one, 2 => two, 3 => three
    }

    std::unordered_set<int> us;
    us.insert(10); // 插入元素 10
    us.insert(30); // 插入元素 30
    us.emplace(20); // 直接在容器中构造元素 20

    for (int num : us) {
        std::cout << num << " "; // 输出的顺序可能与插入顺序不同
    }
    std::cout << '\n';



    return 0;
}
