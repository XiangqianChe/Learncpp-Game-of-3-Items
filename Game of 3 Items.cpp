#include <iostream>
#include <vector>
#include <cassert>

namespace Items
{
    enum Type
    {
        health_potion,
        torch,
        arrow,
        max_items,
    };
}

int countItems(const std::vector<int>& items)
{
    int count{};
    for (auto item : items)
        count += item;
    return count;
}

int main()
{
    std::vector items{ 1, 5, 10 };
    assert(items.size() == Items::max_items);
    std::cout << "You have " << countItems(items) << " total items\n";

    return 0;
}